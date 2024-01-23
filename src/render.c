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
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "types.h"
#include "zmath.h"
#include "sound.h"
#include "sfont.h"
#include "string.h"
#include "globalvar.h"
#include "gamerender.h"
#define FPMUL(x,y)	((((x)>>6)*((y)>>6))>>4)
#define FPDIV(x,y)	((((x)<<6)/((y)>>6))>>4)


void scrbuf_draw(void)
{
    SDL_LockSurface(screen);

#ifdef GP2X
    memcpy(screen->pixels,scrbuf,76800);


#else
//zzUint8 scrtemp[1228800];
    zzUint8 scrtemp[800*480*4*4];
    /*
    zzUint16 x1,y1;zzUint32 ii=0,i=0;

    for (int y=0;y<480;y+=2)
    {
    for (int x=0;x<640;x+=2)
    {
    zzUint8 c=scrbuf[i];

    scrtemp[ii]=ipal[c][2];
    scrtemp[ii+1]=ipal[c][1];
    scrtemp[ii+2]=ipal[c][0];

    scrtemp[ii+4]=ipal[c][2];
    scrtemp[ii+5]=ipal[c][1];
    scrtemp[ii+6]=ipal[c][0];

    ii+=8;i++;
    }

    for (int x=0;x<640;x++)
    {
    scrtemp[ii]=scrtemp[ii-2560];
    scrtemp[ii+1]=scrtemp[ii-2559];
    scrtemp[ii+2]=scrtemp[ii-2558];

    ii+=4;
    }
    }
    memcpy(screen->pixels,scrtemp,1228800);
    */
    zzUint16 x1,y1;
    zzUint32 ii=0,i=0;
    int y,x;
    for (y=0; y<240; y++)
    {
        for (x=0; x<320; x++)
        {
            zzUint8 c=scrbuf[i];

            scrtemp[ii]=ipal[c][2];
            scrtemp[ii+1]=ipal[c][1];
            scrtemp[ii+2]=ipal[c][0];
            scrtemp[ii+4]=ipal[c][2];
            scrtemp[ii+5]=ipal[c][1];
            scrtemp[ii+6]=ipal[c][0];
            scrtemp[ii+3200]=ipal[c][2];
            scrtemp[ii+3201]=ipal[c][1];
            scrtemp[ii+3202]=ipal[c][0];
            scrtemp[ii+3204]=ipal[c][2];
            scrtemp[ii+3205]=ipal[c][1];
            scrtemp[ii+3206]=ipal[c][0];

            if(x&1==1) {
                scrtemp[ii+8]=ipal[c][2];
                scrtemp[ii+9]=ipal[c][1];
                scrtemp[ii+10]=ipal[c][0];
                scrtemp[ii+3208]=ipal[c][2];
                scrtemp[ii+3209]=ipal[c][1];
                scrtemp[ii+3210]=ipal[c][0];
                ii+=4;
            }
            ii+=8;
            i++;
        }
        ii+=800*4;

    }
    memcpy(screen->pixels,scrtemp,800*480*4);

#endif

    SDL_UnlockSurface(screen);
    SDL_Flip(screen);

}


void ClrScr(void)
{
    zzUint32 i;

    for (i=0; i<76800; i++)
        scrbuf[i]=0;
}
void Render(void)
{
    zzUint32 i;


    GameRender();

    if ((controlpadbutton[PAD_L2])|(controlpadbutton[PAD_R2]))
    {
        i=0;
        zzUint16 y,x;

        for (y=0; y<239; y+=2)
        {
            for (x=0; x<320; x++)
                scrbuf[i+x]=0;
            i+=640;
        }


        if (controlpadbutton[PAD_L2]) if (volume>0) volume--;
        if (controlpadbutton[PAD_R2]) if (volume<75) volume++;

        l_textstring=sprintf(s_textstring,"VOLUME=%i",volume);
        s_drawtext2(160-l_textstring*8,200,1);
        s_drawtext2(160-l_textstring*8-2+random4(),200-2+random4(),2);

        Mix_Volume(-1,volume);
//Mix_VolumeMusic(volume);
    }

    /*if (count<1024)
    {
    l_textstring=sprintf(s_textstring,"Stage%i thm%i type%i mnstr%i fps:%i",level,leveltheme,leveltype,mapmonsters,fps);
    s_drawtext(6,220,1);
    }
    */
    /*
    for (zzUint8 y=0;y<4;y++)
    {
    l_textstring=sprintf(s_textstring,"%i-%i",mobstack[y],mobstacktype[y]);
    s_drawtext(6+y*64,220,1);

    }
    l_textstring=sprintf(s_textstring,"%i",monsters);
    s_drawtext(6,200,1);
    */
    scrbuf_draw();
}


