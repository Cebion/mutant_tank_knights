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

#include <SDL/SDL_image.h>

void LoadTiles(void)
{


    SDL_Surface *Image_Surf;
    Image_Surf=IMG_Load("gfxset0.png");

    SDL_LockSurface(Image_Surf);
    zzUint8 readbyte,*p;
    zzUint8 cl[4];
    p = (zzUint8*)Image_Surf->pixels;

    cl[0]=*p++;
    cl[1]=*p++;
    cl[2]=*p++;
    cl[3]=*p++;
    zzUint32 i;

    for (i=4; i<262144; i++)
    {
        readbyte=*p++;
        tile[i]=0;
        if (readbyte>0)
            if (readbyte==cl[1]) tile[i]=1;
            else if (readbyte==cl[2]) tile[i]=2;
            else if (readbyte==cl[3]) tile[i]=3;
    }
    SDL_UnlockSurface(Image_Surf);


}
