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

void EmitStaticSplat(signed long int x,signed long int y,unsigned short color)
{
    zzUint8 i=0;
    while ((splat_alive[i]>0) & (i<32)) i++;
    if (i==32) i=random32();

    splat_alive[i]=128+random128();
    splat_color[i]=color;
    splat_x[i]=x;
    splat_y[i]=y;
    splat_ix[i]=0;
    splat_iy[i]=0;
    splat_ix2[i]=0;
    splat_iy2[i]=0;
}
void EmitWaterSplat(signed long int x,signed long int y,unsigned short color)
{
    zzUint8 i=0;
    while ((splat_alive[i]>0) & (i<32)) i++;
    if (i==32) i=random32();

    splat_alive[i]=64+random64();
    splat_color[i]=color;
    splat_x[i]=x;
    splat_y[i]=y;
    splat_ix[i]=64*(-64+random128());
    splat_iy[i]=-1000-128*random32();
    splat_ix2[i]=0;
    splat_iy2[i]=50;

}
void EmitSmokeSplat(signed long int x,signed long int y,unsigned short color)
{
    zzUint8 i=0;
    while ((splat_alive[i]>0) & (i<32)) i++;
    if (i==32) i=random32();
    splat_alive[i]=16+random32();
    splat_color[i]=color;
    splat_x[i]=x;
    splat_y[i]=y;
    splat_ix[i]=64*(-64+random128());
    splat_iy[i]=-1000;
    splat_ix2[i]=0;
    splat_iy2[i]=-350;
}

void EmitParticle(signed long int x,signed long int y,unsigned short color)
{
    zzUint8 i=32;
    while ((splat_alive[i]>0) & (i<96)) i++;
    if (i==96) i=32+random64();
    splat_alive[i]=16+random32();
    splat_color[i]=color;
    splat_x[i]=x;
    splat_y[i]=y;
    splat_ix[i]=128*(-64+random128());
    splat_iy[i]=-2000-random128()*25;
    splat_ix2[i]=0;
    splat_iy2[i]=250;
}

void GroundEffect(signed long x,signed long y)
{
    switch (tilesplateffect[map[x>>16][y>>16]])
    {
    case 1:
        EmitStaticSplat(x,y,2);
        break;
    case 2:
        EmitWaterSplat(x,y,3);
        break;

    }
}



void ProcParticles(void)
{
    zzUint8 i;
    for (i=0; i<32; i++)
        if (splat_alive[i])
        {
            splat_alive[i]--;
            splat_x[i]+=splat_ix[i];
            splat_ix[i]+=splat_ix2[i];
            splat_y[i]+=splat_iy[i];
            splat_iy[i]+=splat_iy2[i];
        }


    for (i=32; i<96; i++)
        if (splat_alive[i])
        {
            splat_alive[i]--;
            splat_x[i]+=splat_ix[i];
            splat_ix[i]+=splat_ix2[i];
            splat_y[i]+=splat_iy[i];
            splat_iy[i]+=splat_iy2[i];
            zzUint8 blocked=0;
            zzSint32 x,y;
            x=splat_x[i]+splat_ix[i];
            y=splat_y[i];

            if (x<0) blocked=1;
            else if (x>16646144) blocked=1;
            else
            {
                if (map[x>>16][y>>16]>127) blocked=1;
            }
            if (blocked) splat_ix[i]=-splat_ix[i];

            x=splat_x[i];
            y=splat_y[i]+splat_iy[i];

            if (y<0) blocked=1;
            else if (y>16646144) blocked=1;
            else
            {
                if (map[x>>16][y>>16]>127) blocked=1;
            }
            if (blocked) splat_iy[i]=-splat_iy[i];
            else if (splat_iy[i]>2000)
            {
                splat_iy[i]=-splat_iy[i];
                if (random4()==0) splat_ix[i]=-splat_ix[i];
            }

        }

}

void ClearParticles(void)
{
    zzUint8 i;
    for (i=0; i<96; i++) splat_alive[i]=0;
}
