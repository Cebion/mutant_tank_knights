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
#include "zmath.h"
#include "bullets.h"
#include "sound.h"
#include "sprites.h"
#include "powerups.h"
#include "game.h"

zzSint32 mobdata[16][16]=
{   //size,hp,widthx,widthy //anim0-4 //speed aspeed shoottype meleedamage //explosion nil nil score
    {  0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0},//player NULL
    {  1,1,30000,30000, 320,321,320,322, 355,2,0,1, 0,0,0,5},//bird
    {  1,3,30000,30000, 323,324,323,325, 100,4,0,1, 0,0,0,10},//zombie
    {  1,4,30000,30000, 326,327,326,328, 130,3,0,2, 0,0,0,15},//worm

    {  1,2,30000,30000, 329,330,329,331, 90 ,4,1,1, 0,0,0,20},//zombie gunner
    {  1,2,30000,30000, 332,333,332,333, 110,3,0,-1, 0,0,0,15},//bitter bomb
    {  2,7,59000,59000, 352,354,356,354, 60,5,3,0, 0,0,0,50},//destroyer eye
    {  2,8,59000,59000, 358,360,362,364, 70,0,4,0, 1,0,0,100},//mutant tank

    { 3,20,90000,90000, 366,369,366,369, 60,1,2,0, 1,0,0,250},//missle launcher
    { 2,15,59000,59000, 416,418,420,418, 120,4,0,8, 0,0,0,400},//Tentacle
    { 2,17,59000,59000, 422,424,426,424, 80,3,5,0, 1,0,0,350},//Walker
    { 1,100,30000,30000, 334,335,336,335, 320,4,0,1, 0,0,0,10000},//Lord Irish

    { 2,120,59000,59000, 374,376,372,376, 250,4,0,8, 0,0,0,15000},//Lord Irish
    {  0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0},
    {  0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0},
    {  0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0}
};

void KillMob(unsigned short int i)
{
    if (mobenabled[i])
    {
        mobenabled[i]=0;
        monsters--;
    }
}

void HurtMob(unsigned short int i,unsigned short damage)
{
    if (mobhp[i]>=0)
    {
        mobhp[i]-=damage;
        if (i==0) hurtcount=5;
        sPlaySound(6,127,127);
        if (mobhp[i]<=0)
        {
            if (i>0)
            {
                zzSint32 iscore=mobdata[mobtype[i]][15];
                monstersleft=monstersleft-1;
                if ((iscore>0)&(iscore<=1001)) score+=iscore;
            }
            if (i==0) ShowGameOver();
        }
    }
}

void SpawnMonster(unsigned short int x,unsigned short int y,unsigned short int stacki)
{
    zzUint8 i=1;
    zzUint8 index=mobstacktype[stacki];
    while ((mobenabled[i]) & (i<32)) i++;
    if (i==32)
        {}
    else
    {
        mobfromstack[i]=stacki;
        mobenabled[i]=1;
        mobx[i]=x*65536+32768*mobdata[index][0];
        moby[i]=y*65536+32768*mobdata[index][0];
        mobix[i]=0;
        mobiy[i]=0;

        mobwx[i]=mobdata[index][2];
        mobwy[i]=mobdata[index][3];

        mobspritex[i]=16*mobdata[index][0];
        mobspritey[i]=16*mobdata[index][0];
        mobsprite[i]=mobdata[index][4];
        mobcount[i]=random256();
        mobtype[i]=index;
        mobside[i]=1;
        mobdir[i]=-1;
        mobhp[i]=mobdata[index][1];
        monsters++;
    }
}
void MonsterAi(void)
{
    zzUint8 t,i;
    for (i=1; i<32; i++)
        if (mobenabled[i])
        {
            mobcount[i]++;
            t=mobtype[i];
            if (mobdata[t][9])
            {
                mobsprite[i]=mobdata[t][4+(mobcount[i]>>(mobdata[t][9]))%4];
            }
            else if (count%10==0)
            {
                if (mobiy[i]-100<-zabs(mobix[i]))mobsprite[i]=mobdata[t][4+0];
                else if (mobix[i]+100>zabs(mobiy[i]))mobsprite[i]=mobdata[t][4+1];
                else if (mobiy[i]+100>zabs(mobix[i]))mobsprite[i]=mobdata[t][4+2];
                else mobsprite[i]=mobdata[t][4+3];
            }
            if (mobhp[i]>0)
            {
                if  (mobdata[t][10])
                {
                    zzUint8 angle;



                    switch (mobdata[t][10])
                    {
                    case 1:
                        if ((mobcount[i]&63)==0)
                        {
                            if (mobx[i]-mobx[0]>zabs(moby[i]-moby[0])) angle=6;
                            else if (mobx[i]-mobx[0]<-zabs(moby[i]-moby[0])) angle=2;
                            else if (moby[i]-moby[0]>zabs(mobx[i]-mobx[0])) angle=0;
                            else angle=4;
                            SpawnBullet(mobx[i],moby[i],angle,0,1);
                        }
                        break;
                    case 2:
                        if ((mobcount[i]&63)==0)
                        {
                            if (mobx[i]-mobx[0]>zabs(moby[i]-moby[0])) angle=6;
                            else if (mobx[i]-mobx[0]<-zabs(moby[i]-moby[0])) angle=2;
                            else if (moby[i]-moby[0]>zabs(mobx[i]-mobx[0])) angle=0;
                            else angle=4;
                            SpawnBullet(mobx[i],moby[i],angle,1,1);
                        }
                        break;
                    case 3:
                        if ((mobcount[i]&63)==0)
                        {
                            SpawnBullet(mobx[i],moby[i],(mobcount[i]>>6)& 7,2,1);
                            SpawnBullet(mobx[i],moby[i],(((mobcount[i])>>6)+4)& 7,2,1);
                        }
                        break;
                    case 4:
                        if ((mobcount[i]&63)==0)
                        {
                            if (mobx[i]-mobx[0]>zabs(moby[i]-moby[0])) angle=6;
                            else if (mobx[i]-mobx[0]<-zabs(moby[i]-moby[0])) angle=2;
                            else if (moby[i]-moby[0]>zabs(mobx[i]-mobx[0])) angle=0;
                            else angle=4;

                            SpawnBullet(mobx[i],moby[i],(7+angle)&7,3,1);
                            SpawnBullet(mobx[i],moby[i],(8+angle)&7,3,1);
                            SpawnBullet(mobx[i],moby[i],(9+angle)&7,3,1);
                        }
                        break;
                    case 5:
                        if ((mobcount[i]&31)==0)
                        {
                            if (mobx[i]-mobx[0]>zabs(moby[i]-moby[0])) angle=6;
                            else if (mobx[i]-mobx[0]<-zabs(moby[i]-moby[0])) angle=2;
                            else if (moby[i]-moby[0]>zabs(mobx[i]-mobx[0])) angle=0;
                            else angle=4;

                            SpawnBullet(mobx[i],moby[i],(7+angle+(mobcount[i]>>5)%3)&7,0,1);
                        }
                        break;


                    }
                }
                if (mobdir[i]==-1)
                {
                    if (mobx[i]+mobwx[i]>mobx[0]+mobwx[0]) mobix[i]-=mobdata[t][8];
                    else if (mobx[i]-mobwx[i]<mobx[0]-mobwx[0]) mobix[i]+=mobdata[t][8];

                    if (moby[i]+mobwy[i]>moby[0]+mobwy[0]) mobiy[i]-=mobdata[t][8];
                    else if (moby[i]-mobwy[i]<moby[0]-mobwy[0]) mobiy[i]+=mobdata[t][8];
                }
                else
                {
                    switch (mobdir[i])
                    {
                    case 0:
                        mobiy[i]-=mobdata[t][8];
                        break;
                    case 1:
                        mobiy[i]-=mobdata[t][8];
                        mobix[i]+=mobdata[t][8];
                        break;
                    case 2:
                        mobix[i]+=mobdata[t][8];
                        break;
                    case 3:
                        mobiy[i]+=mobdata[t][8];
                        mobix[i]+=mobdata[t][8];
                        break;
                    case 4:
                        mobiy[i]+=mobdata[t][8];
                        break;
                    case 5:
                        mobiy[i]+=mobdata[t][8];
                        mobix[i]+=mobdata[t][8];
                        break;
                    case 6:
                        mobix[i]-=mobdata[t][8];
                        break;
                    case 7:
                        mobiy[i]-=mobdata[t][8];
                        mobix[i]-=mobdata[t][8];
                        break;

                    }
                }
                if ((mobcount[i]&63)==0)
                    if (random8()==0) mobdir[i]=random8();
                    else mobdir[i]=-1;
            }
            else
            {
                mobhp[i]--;
                if (mobhp[i]<-25)
                {
                    if (random8()==0 ) SpawnPowerUp(mobx[i],moby[i],random4());
                    if (mobdata[t][12]==1)
                    {   //explosion
                        zzSint32 x=mobx[i];
                        zzSint32 y=moby[i];

                        SpawnSpritei(x+17384,y+17384,512-8, 9000+8*random256(), 9000+8*random256());
                        SpawnSpritei(x-17384,y+17384,512-8,-9000-8*random256(), 9000+8*random256());
                        SpawnSpritei(x-17384,y-17384,512-8,-9000-8*random256(),-9000-8*random256());
                        SpawnSpritei(x+17384,y-17384,512-8, 9000+8*random256(),-9000-8*random256());

                        SpawnSpritei(x+17384,y,512-8,12000+9*random256(),0);
                        SpawnSpritei(x-17384,y,512-8,-12000-9*random256(),0);
                        SpawnSpritei(x,y+17384,512-8,0,12000+9*random256());
                        SpawnSpritei(x,y-17384,512-8,0,-12000-9*random256());

                        sPlaySound(6,127,127);

                    }//explosion

                    if (mobdata[t][11]==-1)
                    {
                        SpawnBullet(mobx[i],moby[i],0,2,2);
                        SpawnBullet(mobx[i],moby[i],1,2,2);
                        SpawnBullet(mobx[i],moby[i],2,2,2);
                        SpawnBullet(mobx[i],moby[i],3,2,2);
                        SpawnBullet(mobx[i],moby[i],4,2,2);
                        SpawnBullet(mobx[i],moby[i],5,2,2);
                        SpawnBullet(mobx[i],moby[i],6,2,2);
                        SpawnBullet(mobx[i],moby[i],7,2,2);

                    }
//predeath

                    SpawnSpriteil(mobx[i],moby[i],512+4,0,-10000,120);

                    KillMob(i);
                }
            }

        }
}


zzUint8 TestCageFree(zzSint16 x,zzSint16 y,zzUint8 size)
{
    zzUint8 ret=1;
    if (size==1)
    {
        if ((x<1)|(y<1)|(x>254)|(y>254))
            ret=0;
        else if (map[x][y]>127) ret=0;
    }
    else
    {
        zzSint16 ix,iy;

        for (ix=x; ix<x+size; ix++)
            for (iy=y; iy<y+size; iy++)
                if ((ix<1)|(iy<1)|(ix>254)|(iy>254))
                    ret=0;
                else if (map[ix][iy]>127) ret=0;
    }
    return ret;
}
zzUint8 Floodangle;

void FloodIntegrate(void)
{
    zzSint32 x0,y0,x1,y1,wx,wy;
    zzSint16 cx0,cx1,cy0,cy1,sx,sy;
    zzUint8 gn=0;

    zzUint8 NewMonster,size,stacki;

    NewMonster=0;
    zzUint8 i=0;
    while ((mobstack[i]==0)&(i<4)) i++;

    if (i<4)
    {
        NewMonster=mobstacktype[i];
        stacki=i;
    }

    if (i==4)
        if (monsters==1)
            if (zoneclearcount==0)
//if (mobstack[0]==0)
//if (mobstack[1]==0)
//if (mobstack[2]==0)
//if (mobstack[3]==0)
                if (monstersleft<1)
                    zoneclearcount=1;


    if ((NewMonster>0)&(NewMonster<16))
    {
        Floodangle=(Floodangle+1)%4;
        wx=200*(65536-icamerazoom);
        wy=180*(65536-icamerazoom);
        x0=(icamerax-wx)>>4;
        x1=(icamerax+wx)>>4;
        y0=(icameray-wy)>>4;
        y1=(icameray+wy)>>4;
        size=mobdata[NewMonster][0];
        cx0=x0>>16;
        cx0=cx0-size;
        cx1=x1>>16;
        cy0=y0>>16;
        cy0=cy0-size;
        cy1=y1>>16;
        zzSint32 freeplaces=0;

        sx=cx0;
        sy=cy0;
        zzUint8 correct=0;
        zzSint32 lx,ly;

        switch (Floodangle)
        {
        case 0://north
            ly=cy0;
            for (lx=cx0; lx<cx1; lx++)
                if (TestCageFree(lx,ly,size)==1)
                {   correct=1;
                    if (freeplaces==0) {
                        sx=lx;
                        sy=ly;
                    }
                    if (random8()==0) {
                        sx=lx;
                        sy=ly;
                    }
                    freeplaces++;
                }
            break;
        case 1://south
            ly=cy1;
            for (lx=cx0; lx<cx1; lx++)
                if (TestCageFree(lx,ly,size)==1)
                {   correct=1;
                    if (freeplaces==0) {
                        sx=lx;
                        sy=ly;
                    }
                    if (random8()==0) {
                        sx=lx;
                        sy=ly;
                    }
                    freeplaces++;
                }
            break;

        case 2://west
            lx=cx0;
            for (ly=cy0; ly<cy1; ly++)
                if (TestCageFree(lx,ly,size)==1)
                {   correct=1;
                    if (freeplaces==0) {
                        sx=lx;
                        sy=ly;
                    }
                    if (random8()==0) {
                        sx=lx;
                        sy=ly;
                    }
                    freeplaces++;
                }
            break;

        case 3://
            lx=cx1;
            for (ly=cy0; ly<cy1; ly++)
                if (TestCageFree(lx,ly,size)==1)
                {   correct=1;
                    if (freeplaces==0) {
                        sx=lx;
                        sy=ly;
                    }
                    if (random8()==0) {
                        sx=lx;
                        sy=ly;
                    }
                    freeplaces++;
                }
            break;
        }

        if (correct)
            if (stacki<4)
                if (mobstack[stacki]>0)
                {
                    SpawnMonster(sx,sy,stacki);
                    mobstack[stacki]--;
                }
    }
}

void FloodCleanse(void)
{

    zzSint32 x0,y0,x1,y1,wx,wy;
    wx=240*(65536-icamerazoom);
    wy=200*(65536-icamerazoom);
    x0=(icamerax-wx)>>4;
    x1=(icamerax+wx)>>4;
    y0=(icameray-wy)>>4;
    y1=(icameray+wy)>>4;

    zzUint8 i;

    for (i=1; i<32; i++)
        if (mobenabled[i])
            if ((mobx[i]+mobwx[i]<x0)|(mobx[i]-mobwx[i]>x1)|(moby[i]+mobwy[i]<y0)|(moby[i]+mobwy[i]>y1))
            {
                mobstack[mobfromstack[i]]++;
                KillMob(i);
            }
}

void ProcFlood(void)
{
    if (count>128)
        if (monsters<mapmonsters)
            if (count%20==0) FloodIntegrate();

    if (count%80==33) FloodCleanse();
}

void ClearMonsters(void)
{
    zzUint8 i;

    for (i=1; i<32; i++) KillMob(i);
}
