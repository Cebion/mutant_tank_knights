/*
 This file is part of Mutant Tank Knights.

    Mutant Tank Knights is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Mutant Tank Knights is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Mutant Tank Knights.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "globalvar.h"
#include "monsters.h"
#include "particle.h"
#include "genmap.h"
#include "sound.h"
#include "zmath.h"
#include "sprites.h"

const zzUint8 bulletspeed[4]= {32,20,15,20},bulletsound[4]= {5,4,4,5};
void SpawnBullet(signed long int x,signed long int y,unsigned short int angle,unsigned short int type,unsigned short int side)
{
    sPlaySound(bulletsound[type],127,127);

    zzUint8 i=0;
    while ((bullet_alive[i]>0) & (i<64)) i++;
    if (i==64) i=random64();
    bullet_alive[i]=50;
    bullet_x[i]=x+32*(random256()-127);
    bullet_y[i]=y+32*(random256()-128);
    bullet_angle[i]=angle;
    bullet_type[i]=type;
    bullet_side[i]=side;

    bullet_ix[i]=angle_tox[angle]*bulletspeed[type]+4*(random256()-127);
    bullet_iy[i]=angle_toy[angle]*bulletspeed[type]+4*(random256()-127);
}
zzUint8 bulletdamage[4]= {1,10,2,2};
void ProcBullets(void)
{
    zzUint8 i;
    zzSint32 x,y,cx,cy;
    zzSint8 blocked,blockedbymob;
    for (i=0; i<64; i++)
        if (bullet_alive[i])
        {
            bullet_alive[i]--;
            blocked=0;
            blockedbymob=-1;
            x=bullet_x[i];
            y=bullet_y[i];
            cx=x>>16;
            cy=y>>16;
            if (map[cx][cy]>127) blocked=1;

            if ((x<65536)|(y<65536)|(x>16646144)|(y>16646144)) bullet_alive[i]=0;
            bullet_x[i]+=bullet_ix[i];
            bullet_y[i]+=bullet_iy[i];

            zzUint8 k;
            for (k=0; k<32; k++)
                if (mobenabled[k])
                    if (mobhp[k]>0)
                        if (mobside[k]!=bullet_side[i])
                            if (bullet_x[i]>mobx[k]-mobwx[k])
                                if (bullet_x[i]<mobx[k]+mobwx[k])
                                    if (bullet_y[i]>moby[k]-mobwy[k])
                                        if (bullet_y[i]<moby[k]+mobwy[k])
                                            blockedbymob=k;

            if (blockedbymob>=0)
            {
                HurtMob(blockedbymob,bulletdamage[bullet_type[i]]);
                if (blockedbymob>0)
                {
                    mobix[blockedbymob]+=bullet_ix[i]/2;
                    mobiy[blockedbymob]+=bullet_iy[i]/2;
                }
            }
            if ((blocked)| (blockedbymob>=0)) bullet_alive[i]=0;
            switch (bullet_type[i])
            {
            case 0://bullet
                if (bullet_alive[i]==0)
                {
                    EmitParticle(x-bullet_ix[i]*2,y-bullet_iy[i]*2,1+2*random2());
                    GroundEffect(x,y);

                    SpawnSprite(x-20480+random256()*160,y-20480+random256()*160,512-32);

                    SpawnSpritei(x-20480+random256()*160-bullet_ix[i],y-20480+random256()*160-bullet_iy[i],512-16,-bullet_ix[i]*1,-bullet_iy[i]*1);

                    if (random8()==0)
                    {
                        DestroyTile(cx,cy);
                    }

                }
                break;
            case 1://missle
                bullet_ix[i]=bullet_ix[i]*33;
                bullet_ix[i]=bullet_ix[i]>>5;
                bullet_iy[i]=bullet_iy[i]*33;
                bullet_iy[i]=bullet_iy[i]>>5;
                if (count%2==1) EmitSmokeSplat(x,y,1);

                if (count%4==1) SpawnSprite(x-10240+random256()*80,y-10240+random256()*80,512-16);

                if (bullet_alive[i]==0)
                {
                    flashcount=1;
                    SpawnSpritei(x+17384,y+17384,512-16, 19000+8*random256(), 19000+8*random256());
                    SpawnSpritei(x-17384,y+17384,512-16,-19000-8*random256(), 19000+8*random256());
                    SpawnSpritei(x-17384,y-17384,512-16,-19000-8*random256(),-19000-8*random256());
                    SpawnSpritei(x+17384,y-17384,512-16, 19000+8*random256(),-19000-8*random256());

                    SpawnSpritei(x+17384,y,512-16,22000+9*random256(),0);
                    SpawnSpritei(x-17384,y,512-16,-22000-9*random256(),0);
                    SpawnSpritei(x,y+17384,512-16,0,22000+9*random256());
                    SpawnSpritei(x,y-17384,512-16,0,-22000-9*random256());


                    SpawnSpritei(x+17384,y+17384,512-8, 9000+8*random256(), 9000+8*random256());
                    SpawnSpritei(x-17384,y+17384,512-8,-9000-8*random256(), 9000+8*random256());
                    SpawnSpritei(x-17384,y-17384,512-8,-9000-8*random256(),-9000-8*random256());
                    SpawnSpritei(x+17384,y-17384,512-8, 9000+8*random256(),-9000-8*random256());

                    SpawnSpritei(x+17384,y,512-8,12000+9*random256(),0);
                    SpawnSpritei(x-17384,y,512-8,-12000-9*random256(),0);
                    SpawnSpritei(x,y+17384,512-8,0,12000+9*random256());
                    SpawnSpritei(x,y-17384,512-8,0,-12000-9*random256());


                    DestroyTile(cx,cy);

                    icamerax+=1024*(-128+random256());
                    icameray+=1024*(-128+random256());
                    icamerazoom+=32*(-128+random256());

                }
                break;
            case 2://wave
                if (bullet_alive[i]==0)
                {
                    SpawnSpritei(x-20480+random256()*160-bullet_ix[i],y-20480+random256()*160-bullet_iy[i],512-16,-bullet_ix[i]*3,-bullet_iy[i]*3);

                    if (random2())
                    {

                        DestroyTile(cx,cy);
                    }
                    SpawnSprite(x-20480+random256()*160,y-20480+random256()*160,512-8);
                }
                break;
            case 3://force bolt
                bullet_angle[i]=(bullet_angle[i]+1)& 7;

                if (bullet_alive[i]==0)
                {
                    if (random2()) DestroyTile(cx,cy);
                    SpawnSprite(x-20480+random256()*160,y-20480+random256()*160,512-24);

                    EmitParticle(x-bullet_ix[i]*2,y-bullet_iy[i]*2,1+2*random2());
                    EmitParticle(x-bullet_ix[i]*2,y-bullet_iy[i]*2,1+2*random2());

                    SpawnSpritei(x,y-17384,512-16,400*(-4+random8()),-6000-9*random256());

                }

                break;
            }//end of case

        }

}
void ClearBullets(void)
{
    zzUint8 i;
    for (i=0; i<64; i++) bullet_alive[i]=0;
}
