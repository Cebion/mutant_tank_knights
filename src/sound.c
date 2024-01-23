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
#include "sound.h"
#include <SDL/SDL_mixer.h>
#include "globalvar.h"
#include "zmath.h"

void LoadSound(void)
{
    zzUint32 i;
    zzUint16 s;
//d_sound[0]=Mix_LoadWAV("sfx0.wav");
    d_sound[4]=Mix_LoadWAV("sfx4.wav");
    d_sound[5]=Mix_LoadWAV("sfx5.wav");
    d_sound[6]=Mix_LoadWAV("sfx6.wav");
    d_sound[7]=Mix_LoadWAV("sfx7.wav");
    d_sound[8]=Mix_LoadWAV("sfx8.wav");
    d_sound[9]=Mix_LoadWAV("sfx9.wav");
    d_sound[10]=Mix_LoadWAV("sfx10.wav");
    d_sound[11]=Mix_LoadWAV("sfx11.wav");
}

char musictrk[10][32]= {
    "sfx0.ogg",
    "sfx1.ogg",
    "sfx2.ogg",
    "sfx3.ogg",

    "sfx13.ogg",
    "sfx14.ogg",
    "sfx15.ogg",
    "sfx16.ogg",

    "sfx12.ogg",
    "sfx17.ogg"
};
Mix_Music *dd_music = NULL;

void PlayMusic(unsigned short int track)
{

    dd_music=Mix_LoadMUS(musictrk[track]);
//Mix_PlayChannel(0,d_sound[0],-1);
    Mix_PlayMusic(dd_music,-1);
}
void sPlaySound(unsigned int index,unsigned short int left,unsigned short int right)
{
    zzUint8 t=right;
    switch (SoundMode)
    {
    case 0://NORMAL
        break;
    case 1://REVERSED
        right=left;
        left=t;
        break;
    case 2://MONO
        if (left>right) right=left;
        else left=right;
        break;
    }

    Mix_PlayChannel(1,d_sound[index],0);
#ifdef GP2X
    Mix_SetPanning(1,right,left);
#else
    Mix_SetPanning(1,left,right);
#endif
}
