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
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "globalvar.h"
#include "gameloop.h"
#include "sound.h"
#include "render.h"
#include "sfont.h"
#include "initall.h"
#include "zmath.h"

#ifdef GP2X
#include "sys/mman.h"
#include "fcntl.h"

volatile unsigned short *MEM_REG;
unsigned long   gp2x_dev=0;

void RamHack(void)//I't me! RamHack!
{
    gp2x_dev = open("/dev/mem", O_RDWR);

    MEM_REG=(unsigned short *)mmap(0, 0x10000, PROT_READ|PROT_WRITE, MAP_SHARED, gp2x_dev, 0xc0000000);
    unsigned short v,timing;

//tRC
    timing=5;
    v = (unsigned short)(MEM_REG[0x3804>>1] & (~(0xF << 8)));
    MEM_REG[0x3804>>1] = ((timing & 0xF) << 8) | v;

//tRAS
    timing=3;
    v = (unsigned short)(MEM_REG[0x3804>>1] & (~(0xF << 4)));
    MEM_REG[0x3804>>1] = ((timing & 0xF) << 4) | v;

//tWR
    timing=0;
    v = (unsigned short)(MEM_REG[0x3804>>1] & (~(0xF)));
    MEM_REG[0x3804>>1] = (timing & 0xF) | v;

//tMRD
    timing=0;

    v = (unsigned short)(MEM_REG[0x3802>>1] & (~(0xF << 12)));
    MEM_REG[0x3802>>1] = ((timing & 0xF) << 12) | v;

//tRFC
    timing=0;

    v = (unsigned short)(MEM_REG[0x3802>>1] & (~(0xF << 8)));
    MEM_REG[0x3802>>1] = ((timing & 0xF) << 8) | v;

//tRP
    timing=1;

    v = (unsigned short)(MEM_REG[0x3802>>1] & (~(0xF << 4)));
    MEM_REG[0x3802>>1] = ((timing & 0xF) << 4) | v;
//tRCD
    timing=1;

    v = (unsigned short)(MEM_REG[0x3802>>1] & (~(0xF)));
    MEM_REG[0x3802>>1] = (timing & 0xF) | v;

    close(gp2x_dev);
}

#endif
////


int main (int argc, char *argv[])
{

#ifdef GP2X
    RamHack();
//system("/sbin/insmod mmuhack.o");
#endif

    level=1;
    highscore=0;
    FILE *fp;
    zzUint8 c;
    fp=fopen("config.cfg","rb");
    if (fp)
    {
        level=fgetc(fp);
        c=fgetc(fp);
        highscore+=c;
        c=fgetc(fp);
        highscore+=256*c;
        c=fgetc(fp);
        highscore+=256*256*c;
        c=fgetc(fp);
        highscore+=256*256*256*c;
        fclose(fp);
    }


    if (SDL_Init (SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK) < 0)
    {
        exit (1);
    }
    if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers)) {
        exit(1);
    }
    Mix_QuerySpec(&audio_rate, &audio_format, &audio_channels);


#ifndef GP2X

    SDL_WM_SetCaption("Mutant Tank Knights Ex","Mutant Tank Knights Ex");
    SDL_ShowCursor(SDL_DISABLE);

#ifdef PANDORA
    screen = SDL_SetVideoMode (800, 480, 32, SDL_HWSURFACE|SDL_FULLSCREEN);
#else
    screen = SDL_SetVideoMode (800, 480, 32, SDL_HWSURFACE);
#endif
    //screen = SDL_SetVideoMode (320, 240, 32, SDL_HWSURFACE);
    if (screen == NULL) {
        exit (2);
    }
#else
    SDL_ShowCursor(SDL_DISABLE);
    screen = SDL_SetVideoMode (320, 240, 8, SDL_HWSURFACE);
    if (screen == NULL) {
        exit (2);
    }
#endif
//load all
    if (SDL_NumJoysticks() > 0)
    {
        joy = SDL_JoystickOpen(0);

        if (SDL_NumJoysticks() > 1)
        {
            USBjoy = SDL_JoystickOpen(1);
            CradleMode=1;
        }

    }
    SDL_ShowCursor(SDL_DISABLE);
    InitAll();
    gameloop();

    ClrScr();
    Mix_CloseAudio();


    SDL_Quit();



    fp=fopen("config.cfg","wb");
    if (fp)
    {
        fputc(level,fp);
        c=highscore%256;
        highscore=highscore/256;
        fputc(c,fp);
        c=highscore%256;
        highscore=highscore/256;
        fputc(c,fp);
        c=highscore%256;
        highscore=highscore/256;
        fputc(c,fp);
        c=highscore%256;
        highscore=highscore/256;
        fputc(c,fp);
    }
    fclose(fp);

#ifdef GP2X
    chdir("/usr/gp2x");
    execl("/usr/gp2x/gp2xmenu", "/usr/gp2x/gp2xmenu", NULL);
#endif

    return 0;
}
