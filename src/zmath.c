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
#include "math.h"

#include "zmath.h"
#include "stdlib.h"
#include "globalvar.h"
#define FPDIV(x,y)	((((x)<<12)/((y)))>>4)

zzUint16 arctan(zzSint32 argx,zzSint32 argy)
{
    zzSint16 val;
    zzUint16 d,res;
    if (argx==0)
    {
        res=1024;
    }
    else
    {
        d=1024;
        res=512;
        val=FPDIV(argy,argx);
        if (val<0) val=-val;
        while (d>1)
        {
            d=d>>1;
            if (f_tan[res]>val) res=res-d;
            else if (f_tan[res]<val) res=res+d;
            else d=0;
        }

    }
    if ((argx<=0)&(argy>0)) res=2048-res;
    else if ((argx<=0)&(argy<0)) res=2048+res;
    else if ((argx>=0)&(argy<0)) res=4096-res;

    return res;
}

zzUint32 fastrange(zzSint32 argx,zzSint32 argy)
{
    zzSint32 rs0,rs1;
    rs0=argx;
    rs1=argy;
    if (rs0<0) rs0= - rs0;
    if (rs1<0) rs1= - rs1;
    if (rs0>rs1) return rs0;
    else return rs1;
}


zzSint32 calcturn(zzSint32 angle0,zzSint32 angle1)
{
    zzSint32 de=(angle1-angle0);
    if (de>2048) de=-4096+de;
    else if (de<-2048) de=4096+de;

    return de;
}
zzSint32 zabs(zzSint32 val)
{
    if (val>=0) return val;
    else return -val;
}


zzSint16 SuperAngle(zzSint32 value)
{
    zzSint16 val=value;
    while (val<0) val+=4096;

    while (val>=4096) val-=4096;
    return val;
}

zzUint8 random2(void)
{
    zzUint8 ret=table_rnd[rnd_seed] & 1;
    rnd_seed=rnd_seed+1;
    rnd_seed=rnd_seed & 1023;
    return ret;
}
zzUint8 random4(void)
{
    zzUint8 ret=table_rnd[rnd_seed] & 3;
    rnd_seed=rnd_seed+1;
    rnd_seed=rnd_seed & 1023;
    return ret;
}
zzUint8 random8(void)
{
    zzUint8 ret=table_rnd[rnd_seed] & 7;
    rnd_seed=rnd_seed+1;
    rnd_seed=rnd_seed & 1023;
    return ret;
}
zzUint8 random16(void)
{
    zzUint8 ret=table_rnd[rnd_seed] & 15;
    rnd_seed=rnd_seed+1;
    rnd_seed=rnd_seed & 1023;
    return ret;
}
zzUint8 random32(void)
{
    zzUint8 ret=table_rnd[rnd_seed] & 31;
    rnd_seed=rnd_seed+1;
    rnd_seed=rnd_seed & 1023;
    return ret;
}
zzUint8 random64(void)
{
    zzUint8 ret=table_rnd[rnd_seed] & 63;
    rnd_seed=rnd_seed+1;
    rnd_seed=rnd_seed & 1023;
    return ret;
}
zzUint8 random128(void)
{
    zzUint8 ret=table_rnd[rnd_seed] & 127;
    rnd_seed=rnd_seed+1;
    rnd_seed=rnd_seed & 1023;
    return ret;
}
zzUint8 random256(void)
{
    zzUint8 ret=table_rnd[rnd_seed];
    rnd_seed=rnd_seed+1;
    rnd_seed=rnd_seed & 1023;
    return ret;
}
