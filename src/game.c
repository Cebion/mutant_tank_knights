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
#include "genmap.h"
#include "sprites.h"
#include "particle.h"
#include "bullets.h"
#include "sound.h"
#include "monsters.h"
#include <SDL/SDL.h>
#include "gamemenu.h"
#include "render.h"
#include "powerups.h"
#include "sfont.h"
#include "intro.h"

#include <SDL/SDL_mixer.h>

void ShowLogo()
{
    sPlaySound(10,127,127);
//SetPalette(0);
    zzUint16 i,x,y;
    for (i=4; i>=1; i--)
    {
        for (x=0; x<320; x++)
            for (y=0; y<240; y++)
                scrbuf[x+y*320]=tile[432+x/4+(512-60*i+y/4)*512];

        if (score>highscore) highscore=score;

//l_textstring=sprintf(s_textstring,"CURRENT LEVEL %i",level);
//s_drawtext2(12,125,0);
//s_drawtext2(8,125,0);
//s_drawtext2(10,127,0);
//s_drawtext2(10,123,0);

//s_drawtext2(10,125,3);
        l_textstring=sprintf(s_textstring,"YOUR SCORE: %i",score);
        s_drawtext2(8,160,0);
        s_drawtext2(12,160,0);
        s_drawtext2(10,162,0);
        s_drawtext2(10,158,0);

        s_drawtext2(10,160,1);

        l_textstring=sprintf(s_textstring,"HIGH SCORE: %i",highscore);
        s_drawtext2(12,200,0);
        s_drawtext2(8,200,0);
        s_drawtext2(10,202,0);
        s_drawtext2(10,198,0);

        s_drawtext2(10,200,1);


        scrbuf_draw();
        SDL_Delay(100);
        Mix_HaltChannel(0);
        SDL_Delay(600);
    }
    ClrScr();
    scrbuf_draw();
    SDL_Delay(500);

}
void ShowGameOver(void)
{
    sPlaySound(11,127,127);
    if (score>highscore) highscore=score;
    zzUint16 x,y,i,l;
    SetPalette(0);
    for (x=0; x<319; x++)
        for (y=0; y<239; y++)
            scrbuf[x+y*320]=tile[256+x/2+(512-240+y/2)*512];
    for (i=0; i<240; i++)
        scrbuf[319+i*320]=0;
    for (l=0; l<320; l++)
        scrbuf[239*320+l]=0;

    scrbuf_draw();
    SDL_Delay(100);
    Mix_HaltChannel(0);
    SDL_Delay(1200);
    ClrScr();
    scrbuf_draw();
    SDL_Delay(500);
    score=0;
    Introduction();
    MainGameMenu();
}


zzSint32 walkcount=0;
void SetNewLevel(unsigned short level)
{
    ClearBullets();
    ClearParticles();
    ClearMonsters();
    ClearSprites();


//if ((controlpadbutton[PAD_SELECT]==0))
//{
    ShowLogo();
//}

    GenerateMap(level);
    monsters=1;
    switch (leveltank)
    {
    case 0:
        mobhp[0]=32;
        break;
    case 1:
        mobhp[0]=20;
        break;
    case 2:
        mobhp[0]=25;
        break;
    case 3:
        mobhp[0]=10;
        break;
    }

    zoneclearcount=0;
    gameovercount=0;
    gamemode=0;
}

void TankEffect()
{
    if (count%2==0)
        switch (player_angle)
        {
        case 0:
            GroundEffect(mobx[0]-20000+256*(random32()-16),moby[0]+20000);
            GroundEffect(mobx[0]+20000+256*(random32()-16),moby[0]+20000);
            break;
        case 1:
            GroundEffect(mobx[0]-20000,moby[0]+20000);
            GroundEffect(mobx[0]+10000,moby[0]+20000);
            break;
        case 2:
            GroundEffect(mobx[0]-20000,moby[0]+14000);
            GroundEffect(mobx[0]-20000,moby[0]+28000);
            break;
        case 3:
            GroundEffect(mobx[0]-20000,moby[0]+20000);
            GroundEffect(mobx[0]+10000,moby[0]+20000);
            break;
        case 4:
            GroundEffect(mobx[0]-20000+256*(random32()-16),moby[0]+20000);
            GroundEffect(mobx[0]+20000+256*(random32()-16),moby[0]+20000);
            break;
        case 5:
            GroundEffect(mobx[0]-10000,moby[0]+20000);
            GroundEffect(mobx[0]+20000,moby[0]+20000);
            break;
        case 6:
            GroundEffect(mobx[0]+20000,moby[0]+14000);
            GroundEffect(mobx[0]+20000,moby[0]+28000);
            break;
        case 7:
            GroundEffect(mobx[0]-10000,moby[0]+20000);
            GroundEffect(mobx[0]+20000,moby[0]+20000);
            break;

        }
}
void ProcPlayer()
{
    if (player_gundelay) player_gundelay--;
    if (player_missledelay) player_missledelay--;
    camerax=mobx[0]*16+mobix[0]*(200+(65536-camerazoom)/160);
    cameray=moby[0]*16+mobiy[0]*(200+(65536-camerazoom)/160);

    if ((controlpadbutton[PAD_A])|(controlpadbutton[PAD_B])|(controlpadbutton[PAD_X])|(controlpadbutton[PAD_Y]))
        if ((player_angle %2) !=1)
        {
            camerax+=3500*angle_tox[player_angle];
            cameray+=3500*angle_toy[player_angle];

        }

    camerazoom=45000-5*walkcount-zabs(mobix[0])/2-zabs(mobiy[0])/2-monsters*1200+zoneclearcount*500;


    if ((zabs(mobix[0])>1200)|(zabs(mobiy[0])>1200))
    {

        if (leveltank<3)
            TankEffect();

        if ((mobiy[0])<-1200)
        {
            if (zabs(mobix[0])<1200)
                player_angle=0;
            else if ((mobix[0])<-1200)
                player_angle=7;
            else
                player_angle=1;
        }
        else if ((mobiy[0])>1200)
        {
            if (zabs(mobix[0])<1200)
                player_angle=4;
            else if ((mobix[0])<-1200)
                player_angle=5;
            else
                player_angle=3;
        }
        else if ((mobix[0])<-1200)
            player_angle=6;
        else if ((mobix[0])>1200)
            player_angle=2;


        if (walkcount<0) walkcount=1;
        else if (walkcount<1000) walkcount++;
    }
    else
    {
        if (walkcount>0) walkcount=-1;
        else if (walkcount>-1000) walkcount--;
    }

    if (count%4==0)
        if (player_realangle!=player_angle)
        {
            zzSint8 c=player_angle-player_realangle;
            if (c>4)
            {
                c=c-4;
                player_realangle--;
            }
            else if (c<-4)
            {
                c=c+4;
                player_realangle++;
            }
            else
            {
                if (c<0) player_realangle--;
                else player_realangle++;
            }
        }
    if (player_realangle<0) player_realangle=7;
    else if (player_realangle>7) player_realangle=0;

    if (leveltank==3) mobsprite[0]=248+(count/10 %2)*32;

    else
        mobsprite[0]=256+leveltank*8;
    mobsprite[0]=mobsprite[0]+player_realangle;

}
zzSint8 zsign(zzSint32 vl)
{
    if (vl>=0) return 1;
    else return -1;
}
zzUint8 phitcount=0;
void ProcMobs()
{
    zzSint32 x,x2,y,y2,i;

    for (i=0; i<32; i++)
        if (mobenabled[i])
        {
            zzUint8 k;
            for (k=i+1; k<32; k++)
                if (mobenabled[k])
                    if (mobhp[k]>0)
                        if ((mobx[i]+mobwx[i]>mobx[k]-mobwx[k])&(mobx[i]-mobwx[i]<mobx[k]+mobwx[k]))
                            if ((moby[i]+mobwy[i]>moby[k]-mobwy[k])&(moby[i]-mobwy[i]<moby[k]+mobwy[k]))
                            {   //collide
                                if (zabs(mobx[i]-mobx[k])<4000)
                                    if (zabs(moby[i]-moby[k])<4000)
                                    {
                                        mobix[i]+=16*(-128+random256());
                                        mobiy[i]+=16*(-128+random256());
                                    }


                                if (i==0)
                                    if (mobdata[mobtype[k]][11]>0)
                                    {
                                        if ((phitcount)==0) {
                                            phitcount=16;
                                            HurtMob(0,mobdata[mobtype[k]][11]);
                                        }
                                        else phitcount--;
                                    }
                                    else if (mobdata[mobtype[k]][11]==-1)HurtMob(k,mobhp[k]);


                                zzSint32 dx,dy;
                                dx=mobx[i]-mobx[k];
                                dy=moby[i]-moby[k];


                                zzSint32 pushpower=600;
                                if (dx>dy)
                                {
                                    mobix[i]+=pushpower*zsign(dx);
                                    mobix[k]-=pushpower*zsign(dx);
                                }
                                else if (dy>dx)
                                {
                                    mobiy[i]+=pushpower*zsign(dy);
                                    mobiy[k]-=pushpower*zsign(dy);
                                }


                            }//collide

//XXX
            zzUint8 freex=1;
            if (mobix[i]>0)
                x=mobx[i]+mobix[i]+mobwx[i];
            else
                x=mobx[i]+mobix[i]-mobwx[i];
            if ((x<65536)|(x>16646144)) freex=0;

            y=moby[i]-mobwy[i];
            y2=moby[i]+mobwy[i];

            zzSint32 dy;
            if (map[x>>16][y>>16]>127) freex=0;
            if (map[x>>16][y2>>16]>127) freex=0;
            if (mobwy[i]>32000)
                for (dy=y+50000; dy<y2; dy+=50000)
                    if (map[x>>16][dy>>16]>127) freex=0;

            if (freex)mobx[i]+=mobix[i];

//YYY
            zzUint8 freey=1;
            if (mobiy[i]>0)
                y=moby[i]+mobiy[i]+mobwy[i];
            else
                y=moby[i]+mobiy[i]-mobwy[i];
            if ((y<65536)|(y>16646144)) freey=0;
            x=mobx[i]-mobwx[i];
            x2=mobx[i]+mobwx[i];

            if (map[x>>16][y>>16]>127) freey=0;
            if (map[x2>>16][y>>16]>127) freey=0;

            zzSint32 dx;
            if (mobwx[i]>32000)
                for (dx=x+30000; dx<x2; dx+=30000)
                    if (map[dx>>16][y>>16]>127) freex=0;

            if (freey)moby[i]+=mobiy[i];




            mobix[i]=mobix[i]*8/10;
            mobiy[i]=mobiy[i]*8/10;

            zzSint32 mixy=10000;
            if (mobix[i]>mixy) mobix[i]=mixy;
            else if (mobix[i]<-mixy) mobix[i]=-mixy;
            if (mobiy[i]>mixy) mobiy[i]=mixy;
            else if (mobiy[i]<-mixy) mobiy[i]=-mixy;

        }

}

zzSint32 mobrocket[8]= {-15000,-15000,0,+15000,+15000,+15000,0,-15000};
zzUint8 bulletcount;

void PlayerShootGun(void)
{
    switch (leveltank)
    {
    case 0:
        player_gundelay=10;
        mobix[0]-=angle_tox[player_angle]*4;
        mobiy[0]-=angle_toy[player_angle]*4;
        SpawnBullet(mobx[0]+angle_tox[player_angle]*40-mobrocket[player_angle]*3/4,moby[0]+angle_toy[player_angle]*40,player_angle,0,0);
        break;
    case 1:
        player_gundelay=8;
        if ((bulletcount++)& 1)
            SpawnBullet(mobx[0]+angle_tox[player_angle]*40-mobrocket[player_angle]*3/4,moby[0]+angle_toy[player_angle]*40,player_angle,0,0);
        else
            SpawnBullet(mobx[0]+angle_tox[player_angle]*40+mobrocket[player_angle]*3/4,moby[0]+angle_toy[player_angle]*40,player_angle,0,0);

        break;
    case 2:
        player_gundelay=21;
        bulletcount++;
        if ((bulletcount)&1)
            SpawnBullet(mobx[0]+mobrocket[player_angle],moby[0]-17000,player_angle,1,0);
        else
            SpawnBullet(mobx[0]-mobrocket[player_angle],moby[0]-17000,player_angle,1,0);
        break;
    case 3:
        player_gundelay=15;
        SpawnBullet(mobx[0]+angle_tox[player_angle]*40-mobrocket[player_angle]*3/4,moby[0]+angle_toy[player_angle]*40-5000,player_angle,0,0);
        break;

    }
}
void PlayerShootMissle(void)
{
    switch (leveltank)
    {
    case 0:
        player_missledelay=70;
        SpawnBullet(mobx[0]+mobrocket[player_angle],moby[0]-17000,player_angle,1,0);
        break;
    case 1:
        player_missledelay=21;
        player_gundelay=21;
        SpawnBullet(mobx[0]+angle_tox[player_angle]*80,moby[0]+angle_toy[player_angle]*80,player_angle,3,0);

        break;
    case 2:
        player_missledelay=21;
        player_gundelay=20;
        SpawnBullet(mobx[0]+angle_tox[player_angle]*80,moby[0]+angle_toy[player_angle]*80,player_angle,2,0);

        break;
    case 3:
        player_missledelay=100;
        SpawnBullet(mobx[0]+mobrocket[player_angle],moby[0]-17000,player_angle,2,0);
        break;
    }
}

zzSint32 tankspeed[4]= {1000,1250,750,550};

void GameStep(void)
{
    if ((controlpadangle==7)||(controlpadangle==0)||(controlpadangle==1)) mobiy[0]-=tankspeed[leveltank];
    if ((controlpadangle==1)||(controlpadangle==2)||(controlpadangle==3)) mobix[0]+=tankspeed[leveltank];
    if ((controlpadangle==3)||(controlpadangle==4)||(controlpadangle==5)) mobiy[0]+=tankspeed[leveltank];
    if ((controlpadangle==5)||(controlpadangle==6)||(controlpadangle==7)) mobix[0]-=tankspeed[leveltank];

    if ((controlpadbutton[PAD_A])|(controlpadbutton[PAD_B])|(controlpadbutton[PAD_X])|(controlpadbutton[PAD_Y]))
    {
        if (player_gundelay==0)
            PlayerShootGun();


    }
    if ((controlpadbutton[PAD_L1])|(controlpadbutton[PAD_R1]))
        if (player_missledelay==0)
            PlayerShootMissle();

    if (controlpadbutton[PAD_START]) MainGameMenu();
    if (controlpadbutton[PAD_SELECT])
        SetNewLevel(level+1);
//else
//if (count>12)
//{
//SetNewLevel(level);
//LCDmode=(LCDmode+1)%2;
//SetPalette(leveltheme);
//}

    ProcSprites();
    ProcFlood();
    ProcPlayer();
    ProcParticles();
    MonsterAi();
    ProcMobs();
    ProcBullets();
    ProcPowerUps();

}
