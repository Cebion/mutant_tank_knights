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
#include <string.h>
#include <stdio.h>
void s_drawtext(signed int x,signed int y,unsigned short int c)//draws the char *s_textstring
{
//     for (int ix=0;ix<80;ix++)
//     for (int iy=0;iy<192;iy++)
//     scrbuf[ix+iy*320]=fontdata[ix+iy*80];
    int x1,y1,cx,cy,x2,y2,i;

    if (l_textstring!=0)
        for (i=0; i<l_textstring; i++)
        {
            x1=x+i*8;
            y1=y;
            x2=s_textstring[i]%32*8;
            y2=s_textstring[i]/32*16;
            zzUint8 ix,iy;

            for (ix=0; ix<8; ix++)
                for (iy=0; iy<16; iy++)
                {
                    cx=x1+ix;
                    cy=y1+iy;
                    if ((cx>=0)&&(cy>=0)&&(cx<320)&&(cy<240))
                    {
                        if (tile[196608+x2+ix+(iy+y2)*512])
                            scrbuf[cx+cy*320]=c;
                    }
                }

        }
}
void s_drawtext2(signed int x,signed int y,unsigned short int c)//draws the char *s_textstring
{
    zzUint32 n;

    zzSint32 x1,y1,cx,cy,x2,y2,i,ix,iy;
    zzUint8 ci;
    if (l_textstring!=0)
        for (i=0; i<l_textstring; i++)
        {
            ci=s_textstring[i];
            x1=x+i*16;
            y1=y;
            x2=ci%32*8;
            y2=ci/32*16;
            for (ix=0; ix<8; ix++)
                for (iy=0; iy<16; iy++)
                {
                    cx=x1+ix*2;
                    cy=y1+iy*2;
                    if ((cx>=0)&&(cy>=0)&&(cx<319)&&(cy<239))
                    {
                        if (tile[196608+x2+ix+(iy+y2)*512])
                        {
                            n=cx+cy*320;
                            scrbuf[n]=c;
                            scrbuf[n+1]=c;
                            scrbuf[n+321]=c;
                            scrbuf[n+320]=c;
                        }
                    }
                }

        }
}
