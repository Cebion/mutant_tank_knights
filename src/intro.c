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
#include <SDL/SDL.h>
#include "render.h"
#include "genmap.h"
#include "game.h"
#include "sfont.h"
#include "sound.h"
#include "zmath.h"
#include "gameproc.h"

#include <SDL/SDL_mixer.h>

char songtext[13][50]=
{
    "As I drive my little tank",
    "Between all worlds of madness",
    "As I use my cannon",
    "To defeat evil mutants",

    "So far lies my sacred goal",
    "So hard the time hurts me",
    "Very thin armours rusts",
    "That shelters my heart",

    "Why the bullets fly around",
    "Why these wars still shaking Earth",
    "The stars offensive staring down",
    "There's no place without light",

    "The fear clouds my decision"
};

zzUint32 songtime[13][2]=
{
    1000,2000,
    3000,4000,
    5000,6000,
    7000,8000,

    9000,10000,
    11000,12000,
    13000,14000,
    15000,16000,

    17000,18000,
    19000,20000,
    21000,22000,
    23000,24000,

    25000,26000
};
zzUint32 anim,StartTick;


zzSint32 particle_x[16],particle_y[16],particle_ix[16],particle_iy[16];


void DrawSong(void)
{
    zzUint32 songtick;
    songtick=SDL_GetTicks()-StartTick;

    l_textstring=sprintf(s_textstring,"ms:%i",songtick);
    s_drawtext(150,10,1);
    zzUint8 i;

    for (i=0; i<13; i++)
        if ((songtick>=songtime[i][0])&(songtick<=songtime[i][1]))
        {

            l_textstring=sprintf(s_textstring,"%s",songtext[i]);
            zzSint32 x,y;
            x=160-l_textstring*4;
            y=200;
            s_drawtext(x+1,y,0);
            s_drawtext(x-1,y,0);
            s_drawtext(x,y+1,0);
            s_drawtext(x,y-1,0);

            s_drawtext(x,200,2);

            zzUint32 l2=l_textstring*(songtick-songtime[i][0])/(songtime[i][1]-songtime[i][0]);
            l_textstring=l2;
            s_drawtext(x,200,1);

        }
}

zzUint8 DitherFilter[5][5]=
{
    0,0,1,1,1,
    0,0,1,1,1,
    0,0,0,3,3,
    2,2,2,3,3,
    2,2,2,2,3
};

void DrawScreen(zzUint16 x,zzUint32 y,zzUint8 deltax,zzUint8 deltay)
{
    zzUint16 ix,iy;
    zzUint8 c[4],dx,dy;
    zzUint32 ii,i;

    for (iy=1; iy<46; iy++)
        for (ix=1; ix<62; ix++)
        {
            ii=(x+ix)+(y+iy)*512;
            c[0]=tile[ii];
            c[1]=tile[ii+1];
            c[2]=tile[ii+512];
            c[3]=tile[ii+513];
            i=642+iy*320*5+ix*5-deltax-320*deltay;
            for (dy=0; dy<5; dy++)
            {
                for (dx=0; dx<5; dx++)
                {

                    zzUint8 color=c[DitherFilter[dy][dx]];
                    if (color) scrbuf[i]=color;
                    i++;
                }
                i+=315;
            }

        }

}

void DrawBorder(void)
{
    zzSint32 x,y,ii;
    zzUint8 color=0;
    ii=0;
    for (y=0; y<240; y++)
    {
        for (x=0; x<15; x++)
        {
            scrbuf[ii+305]=color;
            scrbuf[ii++]=color;
        }
        ii+=305;
    }

    ii=0;
    for (y=0; y<15; y++)
    {
        for (x=0; x<320; x++)
        {
            scrbuf[ii+72000]=color;
            scrbuf[ii++]=color;
        }
//ii+=305;
    }


}

void DrawParticles(void)
{
    zzUint8 i;

    for (i=0; i<16; i++)
    {
        particle_x[i]+=particle_ix[i];
        particle_y[i]+=particle_iy[i];

        if (particle_x[i]>15)
            if (particle_y[i]>15)
                if (particle_x[i]<305)
                    if (particle_y[i]<225)
                    {
                        zzUint32 ii=particle_x[i]+particle_y[i]*320;
                        scrbuf[ii]=1;
                        scrbuf[ii+1]=1;
                        scrbuf[ii+320]=1;
                        scrbuf[ii+321]=1;

                    }

        if (anim<800)
        {
            if (particle_x[i]<15)
            {
                particle_x[i]=320+random256();
                particle_y[i]=20+random128();
                particle_ix[i]=-2-random4();
                particle_iy[i]=-2+random4();

            }
        }
        else if (anim<1400)
        {
            if (particle_y[i]<15)
            {
                particle_x[i]=32+random256();
                particle_y[i]=240+random64();
                particle_ix[i]=-2+random4();
                particle_iy[i]=-2-random4();

            }
        }
        else if (anim<2000)
        {
            if (particle_x[i]>305)
            {
                particle_x[i]=-random256();
                particle_y[i]=20+random128();
                particle_ix[i]=+2+random4();
                particle_iy[i]=-2+random4();

            }
        }
        else if (anim<3400)
        {
            if (particle_y[i]>225)
            {
                particle_x[i]=32+random256();
                particle_y[i]=-random64();
                particle_ix[i]=-2+random4();
                particle_iy[i]=+1+random4();
            }
        }
//else



    }


}

void DrawMTK()
{
    zzUint16 y,x;

    for (y=0; y<48; y++)
    {
        zzUint32 ii=6+320*(30+y*2);
        zzUint32 ii2=368+y*512;
        for (x=0; x<144; x++)
        {
            if (tile[ii2])
            {
                scrbuf[ii+320]=tile[ii2];
                scrbuf[ii+321]=tile[ii2];
                scrbuf[ii]=tile[ii2];
                scrbuf[ii+1]=tile[ii2];
            }
            ii+=2;
            ii2++;
        }
    }
}
void Introduction(void)
{
    anim=0;
    PlayMusic(9);
    SetPalette(0);


    zzUint8 mmloop=1,cursor=1,c;
    zzSint8 langle;

    StartTick=SDL_GetTicks();


    while (mmloop)
    {
        proccontrol();
        if ((controlpadbutton[PAD_START])|(controlpadbutton[PAD_A])|(controlpadbutton[PAD_B])|(controlpadbutton[PAD_Y])|(controlpadbutton[PAD_X])) mmloop=0;
        SDL_Delay(5);

        zzUint32 i;

        for (i=0; i<76800; i++) scrbuf[i]=0;

        if (anim<800)
        {
            if (anim==1)
                for (i=0; i<16; i++)
                {
                    particle_x[i]=320+random256();
                    particle_y[i]=20+random128();
                    particle_ix[i]=-2-random4();
                    particle_iy[i]=-2+random4();
                }
            DrawScreen(224+anim/10,0,(anim/2)%5,0);
            DrawParticles();
            DrawScreen(224+anim/5,48,anim%5,0);
        }
        else if (anim<1400)
        {
            zzUint16 anim2=anim-800;
            if (anim2==1)
            {
                SetPalette(1);
                for (i=0; i<16; i++)
                {
                    particle_x[i]=32+random256();
                    particle_y[i]=240+random64();
                    particle_ix[i]=-2+random4();
                    particle_iy[i]=-2-random4();
                }
            }
            DrawScreen(0,304+anim2/20,0,(anim2/4)%5);
            DrawParticles();
//DrawScreen(224+anim2/5,48,anim2%5,0);
        }
        else if (anim<2000)
        {
            zzUint16 anim3=600-(anim-1400);
            if (anim==1401)
            {
                SetPalette(2);
                for (i=0; i<16; i++)
                {
                    particle_x[i]=-random256();
                    particle_y[i]=20+random128();
                    particle_ix[i]=+2+random4();
                    particle_iy[i]=-2+random4();
                }
            }
            DrawScreen(64,304+anim3/20,0,(anim3/4)%5);
            DrawParticles();
//DrawScreen(224+anim2/5,48,anim2%5,0);
        }
        else if (anim<3350)
        {
            zzUint16 anim4=(anim-2000);
            if (anim==2001)
            {
                SetPalette(1);
                for (i=0; i<16; i++)
                {
                    particle_x[i]=32+random256();
                    particle_y[i]=-random64();
                    particle_ix[i]=-2+random4();
                    particle_iy[i]=+1+random4();
                }
            }
            DrawScreen(128+anim4/20,288,(anim4/4)%5,0);
            DrawParticles();
//DrawScreen(224+anim2/5,48,anim2%5,0);
        }
        else anim=0;
//else mmloop=0;

//l_textstring=sprintf(s_textstring,"Frame:%i",anim);
//s_drawtext(150,10,1);

        DrawBorder();
//DrawSong();
        DrawMTK();
        scrbuf_draw();


        if ((controlpadbutton[PAD_L2])|(controlpadbutton[PAD_R2]))
        {
            if (controlpadbutton[PAD_L2]) if (volume>0) volume--;
            if (controlpadbutton[PAD_R2]) if (volume<75) volume++;
            Mix_Volume(-1,volume);
//Mix_VolumeMusic(volume);
        }


        anim++;
    }

}
