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
#include "zmath.h"
#include "sfont.h"
#include "sound.h"
#include "gameproc.h"

#include <SDL/SDL_mixer.h>
zzUint8 tmpbuf[76800];
void MainGameMenu(void)
{
    if (score>highscore) highscore=score;
    PlayMusic(8);
    SetPalette(0);

    zzUint16 x,y;
    for (x=0; x<320; x++)
        for (y=0; y<240; y++)
            tmpbuf[x+y*320]=tile[256+x/2+(512-120+y/2)*512];
    zzUint32 ii;
    zzUint32 mcount=0;
    zzUint8 mmloop=1,cursor=1,c;
    if (score) cursor=0;

    zzSint8 langle;
    scrbuf_draw();
    SDL_Delay(500);
    while (mmloop)
    {
        for (ii=0; ii<76800; ii++) scrbuf[ii]=tmpbuf[ii];
        if (random32()==0)
        {
            for (y=0; y<48; y++)
            {
                zzUint32 ii=6+320*(30+y*2);
                zzUint32 ii2=368+y*512;
                for (x=0; x<144; x++)
                {
                    if (tile[ii2])
                    {
                        zzUint8 cc=random4();
                        scrbuf[ii+320]=cc;
                        scrbuf[ii+321]=cc;
                        scrbuf[ii]=cc;
                        scrbuf[ii+1]=cc;
                    }
                    ii+=2;
                    ii2++;
                }
            }

        }
        l_textstring=sprintf(s_textstring,"HIGH SCORE: %i",highscore);
        s_drawtext(300-8*l_textstring,10,1);

        proccontrol();
        if ((controlpadbutton[PAD_START])|(controlpadbutton[PAD_A])|(controlpadbutton[PAD_B])|(controlpadbutton[PAD_Y])|(controlpadbutton[PAD_X]))
        {
            sPlaySound(9,127,127);
            SDL_Delay(100);
            switch (cursor)
            {
            case 0:
                mmloop=0;
                PlayMusic(leveltheme);
                SetPalette(leveltheme);
                break;
            case 1:
                mmloop=0;
                score=0;
                SetNewLevel(level);

                break;
            case 2:
                mmloop=0;
                score=0;
                level=1;
                SetNewLevel(level);
                break;
            case 3:
//mmloop=0;
                LCDmode=(LCDmode+1)%2;
                SetPalette(0);
                zzUint16 x,y;

                for (x=0; x<319; x++)
                    for (y=0; y<239; y++)
                        scrbuf[x+y*320]=tile[256+x/2+(512-120+y/2)*512];
                SDL_Delay(250);

//l_textstring=sprintf(s_textstring,"LEVEL: %i",level);
//s_drawtext(20,10,3);

                l_textstring=sprintf(s_textstring,"HIGH SCORE: %i",highscore);
                s_drawtext(300-8*l_textstring,10,1);
                break;
            case 4:
                mmloop=0;
                SDL_Delay(2000);
                GameLoopEnabled=0;
                break;



            }//switch
        }
        if (langle!=controlpadangle)
        {
            if (score) {
                if (controlpadangle==0) {
                    if (cursor>0) {
                        cursor--;
                        sPlaySound(8,127,127);
                    }
                }
            }
            else
            {
                if (controlpadangle==0) {
                    if (cursor>1) {
                        cursor--;
                        sPlaySound(8,127,127);
                    }
                }
            }

            if (controlpadangle==4) {
                if (cursor<4) {
                    cursor++;
                    sPlaySound(8,127,127);
                }
            }

            langle=controlpadangle;
        }

//
        zzUint16 dx,dy;
        mcount++;
        dy=320*(127+15*cursor+4+(f_sin[(mcount*128)%4096])/16384);
        for (dx=0; dx<102; dx++)
        {
            scrbuf[dx+dy]=1;
        }


        if (score)
        {
            c=2;
            if (cursor==0) c=1;
            l_textstring=sprintf(s_textstring,"RESUME GAME");
            s_drawtext(100,125,c);
            if (c==1)
            {
                s_drawtext2(random8()+160-8*l_textstring,210,0);
                dy=320*(136+15*cursor-4-(f_sin[(mcount*128)%4096])/16384);
                for (dx=98+8*l_textstring; dx<320; dx++)
                    scrbuf[dx+dy]=1;
            }
        }
        c=2;
        if (cursor==1) c=1;
        l_textstring=sprintf(s_textstring,"PLAY GAME");
        s_drawtext(100,140,c);
        if (c==1)
        {
            s_drawtext2(random8()+160-8*l_textstring,210,0);
            dy=320*(136+15*cursor-4-(f_sin[(mcount*128)%4096])/16384);
            for (dx=98+8*l_textstring; dx<320; dx++)
                scrbuf[dx+dy]=1;
        }

        c=2;
        if (cursor==2) c=1;
        l_textstring=sprintf(s_textstring,"RESET PROGRESS");
        s_drawtext(100,155,c);
        if (c==1) {
            s_drawtext2(random8()+160-8*l_textstring,210,0);
            dy=320*(136+15*cursor-4-(f_sin[(mcount*128)%4096])/16384);
            for (dx=98+8*l_textstring; dx<320; dx++)
                scrbuf[dx+dy]=1;
        }

        c=2;
        if (cursor==3) c=1;
        if (LCDmode) l_textstring=sprintf(s_textstring,"B/W LCD");
        else
            l_textstring=sprintf(s_textstring,"CGA ADAPTER");

        s_drawtext(100,170,c);
        if (c==1) {
            s_drawtext2(random8()+160-8*l_textstring,210,0);
            dy=320*(136+15*cursor-4-(f_sin[(mcount*128)%4096])/16384);
            for (dx=98+8*l_textstring; dx<320; dx++)
                scrbuf[dx+dy]=1;
        }

        c=2;
        if (cursor==4) c=1;
        l_textstring=sprintf(s_textstring,"EXIT GAME");
        s_drawtext(100,185,c);
        if (c==1) {
            s_drawtext2(random8()+160-8*l_textstring,210,0);
            dy=320*(136+15*cursor-4-(f_sin[(mcount*128)%4096])/16384);
            for (dx=98+8*l_textstring; dx<320; dx++)
                scrbuf[dx+dy]=1;
        }


//
        if ((controlpadbutton[PAD_L2])|(controlpadbutton[PAD_R2]))
        {

            if (controlpadbutton[PAD_L2]) if (volume>0) volume--;
            if (controlpadbutton[PAD_R2]) if (volume<75) volume++;


            Mix_Volume(-1,volume);
//Mix_VolumeMusic(volume);
        }
        scrbuf_draw();
        SDL_Delay(50);

    }

    SetPalette(leveltheme);
}
wtext2(random8()+160-8*l_textstring,210,0);
dy=320*(136+15*cursor-4-(f_sin[(mcount*128)%4096])/16384
