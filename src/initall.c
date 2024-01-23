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
#include "render.h"
#include "sfont.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include "tiledata.h"
#include "sound.h"
#include "genmap.h"
#include "tables.h"
#include "globalvar.h"
#include "zmath.h"
#include "game.h"
#include "gamemenu.h"
#include "intro.h"

#define FPMUL(x,y)	((((x)>>6)*((y)>>6))>>4)


void InitAll(void)
{
    volume=64;
    Mix_AllocateChannels(2);
    Mix_Volume(-1,64);
    SoundMode=0;

    SetPalette(0);
    LoadTiles();

    SetPalette(0);
    zzUint16 x,y;

    for (x=0; x<320; x++)
        for (y=0; y<240; y++)
            scrbuf[x+y*320]=tile[256+x/2+(512-120+y/2)*512];
    scrbuf_draw();
//
    LoadSound();
    LoadTables();

    tileanim[64]=1;
    tileanim[138]=1;

    tilesplateffect[0]=1;
    tilesplateffect[2]=1;

    tilesplateffect[64]=2;



    mobsprite[0]=256;
    mobspritex[0]=16;
    mobspritey[0]=16;
    mobenabled[0]=1;

    mobx[0]=65536*8+32666;
    moby[0]=65536*8+32666;
    mobwx[0]=27000;
    mobwy[0]=25000;
    icamerazoom=10000;
    camerazoom=10000;
    camerax=mobx[0]*16;
    cameray=moby[0]*16;
    icamerax=mobx[0]*16;
    icameray=moby[0]*16;

//level=1;
    Introduction();
    MainGameMenu();

//SetNewLevel(1);
}
