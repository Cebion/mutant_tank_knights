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


void SpawnSprite(signed long int x,signed long int y,unsigned int index)
{
    zzUint8 i=0;
    while ((sprite_count[i]>0) & (i<64)) i++;
    if (i==64) i=random64();

    sprite_x[i]=x;
    sprite_y[i]=y;
    sprite_ix[i]=0;
    sprite_iy[i]=0;

    sprite_index[i]=index;
    sprite_count[i]=1;
    sprite_life[i]=9;
    sprite_animated[i]=1;

}

void SpawnSpriteil(signed long int x,signed long int y,unsigned int index,signed long int ix,signed long int iy,unsigned short int life)
{
    zzUint8 i=0;
    while ((sprite_count[i]>0) & (i<64)) i++;
    if (i==64) i=random64();

    sprite_x[i]=x;
    sprite_y[i]=y;
    sprite_ix[i]=ix;
    sprite_iy[i]=iy;

    sprite_index[i]=index;
    sprite_count[i]=1;
    sprite_life[i]=life;
    sprite_animated[i]=0;

}
void SpawnSpritei(signed long int x,signed long int y,unsigned int index,signed long int ix,signed long int iy)
{
    zzUint8 i=0;
    while ((sprite_count[i]>0) & (i<64)) i++;
    if (i==64) i=random64();

    sprite_x[i]=x;
    sprite_y[i]=y;
    sprite_ix[i]=ix;
    sprite_iy[i]=iy;

    sprite_index[i]=index;
    sprite_count[i]=1;
    sprite_life[i]=9;
    sprite_animated[i]=1;

}


void ProcSprites(void)
{
    zzUint8 i;

    for (i=0; i<64; i++)
        if (sprite_count[i]>0)
        {
            if (sprite_animated[i]) if (sprite_count[i]>1) sprite_index[i]++;

            sprite_count[i]++;

            sprite_x[i]+=sprite_ix[i];
            sprite_y[i]+=sprite_iy[i];

            if (sprite_count[i]==sprite_life[i]) sprite_count[i]=0;
        }
}

extern void ClearSprites(void)
{

}
