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
#include "particle.h"
#include "zmath.h"
#include "sprites.h"
#include "bullets.h"
#include "sound.h"

zzUint8 playerx,playery;
zzUint8 maptypemobs[8][4]=
{
    {2,4,7,10},{1,3,6,9},{1,2,6,10},{5,2,4,7},
    {2,4,7,8},{2,4,5,7},{3,1,5,9},{2,5,4,10}
};

zzUint8 colors[36][3]=
{
    {0,0,0},{255,255,0},{127,0,0},{0,255,0},
    {0,0,0},{0,255,0},{0,0,128},{127,127,127},
    {0,0,0},{0,255,255},{128,0,128},{255,0,255},
    {0,0,0},{255,0,255},{0,128,128},{255,0,0},

    {0,0,255},{255,255,0},{0,255,255},{0,0,0},
    {64,64,64},{255,0,0},{127,127,127},{0,0,0},

    {32,32,32},{255,0,128},{0,0,128},{128,64,0},
    {0,0,0},{128,255,0},{0,64,64},{0,127,127},

    {0,200,190},{0,10,0},{0,100,80},{0,150,120}
};

zzUint8 leveltypezero[8]= {5,0,0,5,0,5,2,5};
void DestroyTile(unsigned short x,unsigned short y)
{

    if (map[x][y]>=128)
        SpawnSpriteil(32768+x*65536,32768+y*65536,512-96+map[x][y],128*(-32+random64()),-6096-random256()*32,32);

    sPlaySound(7,127,127);
    zzSint32 xx=32666+x*65536;
    zzSint32 yy=32666+y*65536;
    zzUint8 l;

    for (l=0; l<8; l++)
        EmitParticle(xx,yy,1+2*random2());


    zzUint8 tile=map[x][y],rs;
    rs=leveltypezero[leveltype];
    if (random2()==0) rs=2;

    if (leveltype==4)
    {
        if ((tile>=134)&(tile<138))
        {
            zzUint8 x0=(x/4)*4;
            zzUint8 y0=(y/4)*4;

            zzUint16 i,k;

            for (i=x0; i<x0+4; i++)
                for (k=y0; k<y0+4; k++)
                {
                    SpawnSpriteil(32768+i*65536,32768+k*65536,512-96+map[i][k],128*(-32+random64()),-2096-random256()*10,32);

                    if (random2()) map[i][k]=2;
                    else map[i][k]=5;

                    EmitParticle(32666+65536*i,32666+65536*k,1+2*random2());
                }
        }
    }
    else if (leveltype==6)
    {
        if (random4()==0) rs=64;
    }

    if (tile==64) rs=64;
    else if (tile==129) rs=5;
    else if (tile==130)
    {
        SpawnBullet(xx,yy,0,2,2);
        SpawnBullet(xx,yy,1,2,2);
        SpawnBullet(xx,yy,2,2,2);
        SpawnBullet(xx,yy,3,2,2);
        SpawnBullet(xx,yy,4,2,2);
        SpawnBullet(xx,yy,5,2,2);
        SpawnBullet(xx,yy,6,2,2);
        SpawnBullet(xx,yy,7,2,2);

    }

    map[x][y]=rs;
}
void SetPalette(unsigned int num)
{
    if (LCDmode>0) num=8;
    zzUint8 ii=num*4;


#ifdef GP2X
    zzUint8 i;

    for (i=0; i<=3; i++)
    {
        screen->format->palette->colors[i].r=colors[i+ii][0];
        screen->format->palette->colors[i].g=colors[i+ii][1];
        screen->format->palette->colors[i].b=colors[i+ii][2];
    }
    SDL_SetColors(screen,screen->format->palette->colors,0,256);
#else
    zzUint8 i;
    for (i=0; i<=3; i++)
    {
        ipal[i][0]=colors[i+ii][0];
        ipal[i][1]=colors[i+ii][1];
        ipal[i][2]=colors[i+ii][2];
    }
#endif
}

void GenLake()
{
    zzUint8 brush,k,l,n;
    zzSint16 x,y,cx,cy,i;
    for (x=0; x<256; x++) for (y=0; y<256; y++) map[x][y]=2;


    for (y=0; y<256; y++)
    {
        x=random8();
        while (x<255)
        {
            map[x][y]=128;
            x+=1+random8();
        }
    }

    for (i=0; i<200; i++)
    {
//if (random4()==0) brush=128;
//else
        brush=64;
        if (i==0)
        {
            cx=playerx;
            cy=playery;
        }
        else
        {
            cx=64+2*random64();
            cy=64+2*random64();
        }
        n=7+random16();
        for (k=0; k<n; k++)
        {
            x=cx;
            y=cy;
            l=random16();
            while ((l>0)&(x>0))
            {
                map[x][y]=brush;
                l--;
                x--;
            }
            l=random16();
            while ((l>0)&(y>0))
            {
                map[x][y]=brush;
                l--;
                y--;
            }
            l=random16();
            while ((l>0)&(x<255))
            {
                map[x][y]=brush;
                l--;
                x++;
            }
            l=random16();
            while ((l>0)&(y<255))
            {
                map[x][y]=brush;
                l--;
                y++;
            }


        }

    }

}
void GenBase2()
{
    zzSint16 x,y,cx,cy,i;

    for (x=0; x<256; x++) for (y=0; y<256; y++) map[x][y]=1;
    for (x=0; x<64; x++) for (y=0; y<64; y++) mmapii[x][y]=1;

    x=playerx/4;
    y=playery/4;
    zzUint8 l;

    for (i=0; i<3; i++)
    {
        l=2+2*random4();
        while ((l>0)&(x>0))
        {
            mmapii[x][y]=0;
            l--;
            x--;
        }
        l=2+2*random4();
        while ((l>0)&(y>0))
        {
            mmapii[x][y]=0;
            l--;
            y--;
        }
        l=2+2*random4();
        while ((l>0)&(x<63))
        {
            mmapii[x][y]=0;
            l--;
            x++;
        }
        l=2+2*random4();
        while ((l>0)&(y<63))
        {
            mmapii[x][y]=0;
            l--;
            y++;
        }


    }


    for (x=0; x<64; x++)
        for (y=0; y<64; y++)
            if (mmapii[x][y])
            {
                cx=x*4;
                cy=y*4;
                map[cx+0][cy+0]=132;
                map[cx+1][cy+0]=132;
                map[cx+2][cy+0]=132;
                map[cx+3][cy+0]=132;

                map[cx+0][cy+1]=132;
                map[cx+1][cy+1]=132;
                map[cx+2][cy+1]=132;
                map[cx+3][cy+1]=132;

                map[cx+0][cy+2]=132;
                map[cx+1][cy+2]=132;
                map[cx+2][cy+2]=132;
                map[cx+3][cy+2]=132;

                map[cx+0][cy+3]=132;
                map[cx+1][cy+3]=132;
                map[cx+2][cy+3]=132;
                map[cx+3][cy+3]=132;
            }
            else
            {
                cx=x*4;
                cy=y*4;
                map[cx+0][cy+0]=1;
                map[cx+1][cy+0]=1;
                map[cx+2][cy+0]=1;
                map[cx+3][cy+0]=1;

                map[cx+0][cy+1]=1;
                map[cx+3][cy+1]=1;

                map[cx+0][cy+2]=1;
                map[cx+3][cy+2]=1;

                map[cx+0][cy+3]=1;
                map[cx+1][cy+3]=1;
                map[cx+2][cy+3]=1;
                map[cx+3][cy+3]=1;

                if (random4()==0)
                {
                    map[cx+1][cy+1]=64;
                    map[cx+2][cy+1]=64;
                    map[cx+1][cy+2]=64;
                    map[cx+2][cy+2]=64;
                }
                else
                {
                    map[cx+1][cy+1]=4;
                    map[cx+2][cy+1]=4;
                    map[cx+1][cy+2]=4;
                    map[cx+2][cy+2]=4;
                }
            }


    for (x=1; x<255; x++) for (y=1; y<255; y++)
            if (map[x][y]>127)
                if ((map[x+1][y+1]<127) | (map[x+1][y-1]<127) | (map[x-1][y+1]<127) | (map[x-1][y-1]<127) | (map[x-1][y]<127) | (map[x+1][y]<127)|(map[x][y+1]<127)|(map[x][y-1]<127))
                {
                    map[x][y]=131;
                }

    for (x=1; x<255; x++) for (y=1; y<255; y++)
            if (map[x][y]<64)
                if (random16()==0)
                    map[x][y]=130;


    zzUint8 brush=5,n,k;
    cx=playerx;
    cy=playery;
    n=7;
    for (k=0; k<n; k++)
    {
        x=cx;
        y=cy;
        l=random8();
        while ((l>0)&(x>0))
        {
            map[x][y]=brush;
            l--;
            x--;
        }
        l=random8();
        while ((l>0)&(y>0))
        {
            map[x][y]=brush;
            l--;
            y--;
        }
        l=random8();
        while ((l>0)&(x<255))
        {
            map[x][y]=brush;
            l--;
            x++;
        }
        l=random8();
        while ((l>0)&(y<255))
        {
            map[x][y]=brush;
            l--;
            y++;
        }

    }
}

void GenBase()
{
    zzSint16 x,y,cx,cy,i;

    for (x=0; x<256; x++) for (y=0; y<256; y++) map[x][y]=1;
    for (x=0; x<64; x++) for (y=0; y<64; y++) mmapii[x][y]=1;

    x=playerx/4;
    y=playery/4;
    zzUint8 l;

    for (i=0; i<3; i++)
    {
        l=2+2*random4();
        while ((l>0)&(x>0))
        {
            mmapii[x][y]=0;
            l--;
            x--;
        }
        l=2+2*random4();
        while ((l>0)&(y>0))
        {
            mmapii[x][y]=0;
            l--;
            y--;
        }
        l=2+2*random4();
        while ((l>0)&(x<63))
        {
            mmapii[x][y]=0;
            l--;
            x++;
        }
        l=2+2*random4();
        while ((l>0)&(y<63))
        {
            mmapii[x][y]=0;
            l--;
            y++;
        }


    }


    for (x=0; x<64; x++)
        for (y=0; y<64; y++)
            if (mmapii[x][y])
            {
                cx=x*4;
                cy=y*4;
                map[cx+0][cy+0]=132;
                map[cx+1][cy+0]=132;
                map[cx+2][cy+0]=132;
                map[cx+3][cy+0]=132;

                map[cx+0][cy+1]=132;
                map[cx+1][cy+1]=132;
                map[cx+2][cy+1]=132;
                map[cx+3][cy+1]=132;

                map[cx+0][cy+2]=132;
                map[cx+1][cy+2]=132;
                map[cx+2][cy+2]=132;
                map[cx+3][cy+2]=132;

                map[cx+0][cy+3]=132;
                map[cx+1][cy+3]=132;
                map[cx+2][cy+3]=132;
                map[cx+3][cy+3]=132;
            }
            else
            {
                cx=x*4;
                cy=y*4;
                map[cx+0][cy+0]=1;
                map[cx+1][cy+0]=1;
                map[cx+2][cy+0]=1;
                map[cx+3][cy+0]=1;

                map[cx+0][cy+1]=1;
                map[cx+1][cy+1]=4;
                map[cx+2][cy+1]=4;
                map[cx+3][cy+1]=1;

                map[cx+0][cy+2]=1;
                map[cx+1][cy+2]=4;
                map[cx+2][cy+2]=4;
                map[cx+3][cy+2]=1;

                map[cx+0][cy+3]=1;
                map[cx+1][cy+3]=1;
                map[cx+2][cy+3]=1;
                map[cx+3][cy+3]=1;
            }


    for (x=1; x<255; x++) for (y=1; y<255; y++)
            if (map[x][y]>127)
                if ((map[x+1][y+1]<127) | (map[x+1][y-1]<127) | (map[x-1][y+1]<127) | (map[x-1][y-1]<127) | (map[x-1][y]<127) | (map[x+1][y]<127)|(map[x][y+1]<127)|(map[x][y-1]<127))
                {
                    map[x][y]=131;
                }

    for (x=1; x<255; x++) for (y=1; y<255; y++)
            if (map[x][y]<128)
                if (random16()==0)
                    map[x][y]=130;

    cx=playerx/4*4;
    cy=playery/4*4;
    map[cx+0][cy+0]=4;
    map[cx+1][cy+0]=4;
    map[cx+2][cy+0]=4;
    map[cx+3][cy+0]=4;

    map[cx+0][cy+1]=4;
    map[cx+1][cy+1]=3;
    map[cx+2][cy+1]=3;
    map[cx+3][cy+1]=4;

    map[cx+0][cy+2]=4;
    map[cx+1][cy+2]=3;
    map[cx+2][cy+2]=3;
    map[cx+3][cy+2]=4;

    map[cx+0][cy+3]=4;
    map[cx+1][cy+3]=4;
    map[cx+2][cy+3]=4;
    map[cx+3][cy+3]=4;

}
void GenBunker()
{
    zzSint16 x,y,cx,cy,i;

    for (x=0; x<256; x++) for (y=0; y<256; y++) map[x][y]=1;
    for (x=0; x<64; x++) for (y=0; y<64; y++) mmapii[x][y]=1;

    x=playerx/4;
    y=playery/4;
    zzUint8 l;

    for (i=0; i<3; i++)
    {
        l=2+2*random4();
        while ((l>0)&(x>0))
        {
            mmapii[x][y]=0;
            l--;
            x--;
        }
        l=2+2*random4();
        while ((l>0)&(y>0))
        {
            mmapii[x][y]=0;
            l--;
            y--;
        }
        l=2+2*random4();
        while ((l>0)&(x<63))
        {
            mmapii[x][y]=0;
            l--;
            x++;
        }
        l=2+2*random4();
        while ((l>0)&(y<63))
        {
            mmapii[x][y]=0;
            l--;
            y++;
        }


    }


    for (x=0; x<64; x++)
        for (y=0; y<64; y++)
            if (mmapii[x][y])
            {
                cx=x*4;
                cy=y*4;
                map[cx+0][cy+0]=132;
                map[cx+1][cy+0]=132;
                map[cx+2][cy+0]=132;
                map[cx+3][cy+0]=132;

                map[cx+0][cy+1]=132;
                map[cx+1][cy+1]=132;
                map[cx+2][cy+1]=132;
                map[cx+3][cy+1]=132;

                map[cx+0][cy+2]=132;
                map[cx+1][cy+2]=132;
                map[cx+2][cy+2]=132;
                map[cx+3][cy+2]=132;

                map[cx+0][cy+3]=132;
                map[cx+1][cy+3]=132;
                map[cx+2][cy+3]=132;
                map[cx+3][cy+3]=132;


            }
    for (x=1; x<255; x++) for (y=1; y<255; y++)
            if (map[x][y]<128)
                if ((map[x+1][y+1]>127) | (map[x+1][y-1]>127) | (map[x-1][y+1]>127) | (map[x-1][y-1]>127) | (map[x-1][y]>127) | (map[x+1][y]>127)|(map[x][y+1]>127)|(map[x][y-1]>127))
                {
                    map[x][y]=3;
                }
    for (x=1; x<255; x++) for (y=1; y<255; y++)
            if (map[x][y]>127)
                if ((map[x+1][y+1]<127) | (map[x+1][y-1]<127) | (map[x-1][y+1]<127) | (map[x-1][y-1]<127) | (map[x-1][y]<127) | (map[x+1][y]<127)|(map[x][y+1]<127)|(map[x][y-1]<127))
                {
                    map[x][y]=134;
                }
    for (x=1; x<255; x++) for (y=1; y<255; y++)
            if (map[x][y]==134)
                if (random32()==0)
                    map[x][y]=138;


    cx=playerx/4*4;
    cy=playery/4*4;
    map[cx+0][cy+0]=4;
    map[cx+1][cy+0]=4;
    map[cx+2][cy+0]=4;
    map[cx+3][cy+0]=4;

    map[cx+0][cy+1]=4;
    map[cx+1][cy+1]=3;
    map[cx+2][cy+1]=3;
    map[cx+3][cy+1]=4;

    map[cx+0][cy+2]=4;
    map[cx+1][cy+2]=3;
    map[cx+2][cy+2]=3;
    map[cx+3][cy+2]=4;

    map[cx+0][cy+3]=4;
    map[cx+1][cy+3]=4;
    map[cx+2][cy+3]=4;
    map[cx+3][cy+3]=4;

}

void GenBunker2()
{
    zzSint16 x,y,cx,cy,i;

    for (x=0; x<256; x++) for (y=0; y<256; y++) map[x][y]=1;
    for (x=0; x<64; x++) for (y=0; y<64; y++) mmapii[x][y]=1;

    x=playerx/4;
    y=playery/4;
    zzUint8 l;

    for (i=0; i<3; i++)
    {
        l=2+2*random4();
        while ((l>0)&(x>0))
        {
            mmapii[x][y]=0;
            l--;
            x--;
        }
        l=2+2*random4();
        while ((l>0)&(y>0))
        {
            mmapii[x][y]=0;
            l--;
            y--;
        }
        l=2+2*random4();
        while ((l>0)&(x<63))
        {
            mmapii[x][y]=0;
            l--;
            x++;
        }
        l=2+2*random4();
        while ((l>0)&(y<63))
        {
            mmapii[x][y]=0;
            l--;
            y++;
        }


    }


    for (x=0; x<64; x++)
        for (y=0; y<64; y++)
            if (mmapii[x][y])
            {
                cx=x*4;
                cy=y*4;
                map[cx+0][cy+0]=132;
                map[cx+1][cy+0]=132;
                map[cx+2][cy+0]=132;
                map[cx+3][cy+0]=132;

                map[cx+0][cy+1]=132;
                map[cx+1][cy+1]=132;
                map[cx+2][cy+1]=132;
                map[cx+3][cy+1]=132;

                map[cx+0][cy+2]=132;
                map[cx+1][cy+2]=132;
                map[cx+2][cy+2]=132;
                map[cx+3][cy+2]=132;

                map[cx+0][cy+3]=132;
                map[cx+1][cy+3]=132;
                map[cx+2][cy+3]=132;
                map[cx+3][cy+3]=132;


            }

    for (x=1; x<255; x++) for (y=1; y<255; y++)
            if (map[x][y]<128)
                if ((map[x+1][y+1]>127) | (map[x+1][y-1]>127) | (map[x-1][y+1]>127) | (map[x-1][y-1]>127) | (map[x-1][y]>127) | (map[x+1][y]>127)|(map[x][y+1]>127)|(map[x][y-1]>127))
                {
                    map[x][y]=3;
                }

    for (x=1; x<255; x++) for (y=1; y<255; y++)
            if (map[x][y]>127)
                if ((map[x+1][y+1]<127) | (map[x+1][y-1]<127) | (map[x-1][y+1]<127) | (map[x-1][y-1]<127) | (map[x-1][y]<127) | (map[x+1][y]<127)|(map[x][y+1]<127)|(map[x][y-1]<127))
                {
                    map[x][y]=134;
                }

    for (x=1; x<255; x++) for (y=1; y<255; y++)
            if (map[x][y]==134)
                if (random16()==0)
                    map[x][y]=5;

    for (x=1; x<255; x++) for (y=1; y<255; y++)
            if (map[x][y]==1)
                if (random8()==0)
                    map[x][y]=2;


    cx=playerx/4*4;
    cy=playery/4*4;
    map[cx+0][cy+0]=4;
    map[cx+1][cy+0]=4;
    map[cx+2][cy+0]=4;
    map[cx+3][cy+0]=4;

    map[cx+0][cy+1]=4;
    map[cx+1][cy+1]=3;
    map[cx+2][cy+1]=3;
    map[cx+3][cy+1]=4;

    map[cx+0][cy+2]=4;
    map[cx+1][cy+2]=3;
    map[cx+2][cy+2]=3;
    map[cx+3][cy+2]=4;

    map[cx+0][cy+3]=4;
    map[cx+1][cy+3]=4;
    map[cx+2][cy+3]=4;
    map[cx+3][cy+3]=4;


}

void GenCity()
{
    zzSint16 x,y,cx,cy,i;

    for (x=0; x<256; x++) for (y=0; y<256; y++) map[x][y]=0;
    for (x=0; x<64; x++) for (y=0; y<64; y++) mmapii[x][y]=1;

    cx=playerx/4;
    cy=playery/4;

    for (x=0; x<64; x++)
    {
        mmapii[x][cy]=0;
        mmapii[cx][x]=0;
    }

    for (i=0; i<16; i++)
    {
        x=2*random16();
        y=2*random16();
        cx=32+2*random16();
        cy=32+2*random16();

        zzUint8 ix,iy;

        for (ix=x; ix<=cx; ix++)
        {
            mmapii[ix][y]=0;
            mmapii[ix][cy]=0;
        }
        for (iy=y; iy<=cy; iy++)
        {
            mmapii[x][iy]=0;
            mmapii[cx][iy]=0;
        }

    }


    for (x=0; x<64; x++)
        for (y=0; y<64; y++)
            if (mmapii[x][y])
            {
                cx=x*4;
                cy=y*4;
                map[cx+0][cy+0]=136;
                map[cx+1][cy+0]=136;
                map[cx+2][cy+0]=136;
                map[cx+3][cy+0]=136;

                map[cx+0][cy+1]=136;
                map[cx+1][cy+1]=136;
                map[cx+2][cy+1]=136;
                map[cx+3][cy+1]=136;

                map[cx+0][cy+2]=135;
                map[cx+1][cy+2]=135;
                map[cx+2][cy+2]=135;
                map[cx+3][cy+2]=135;

                map[cx+0][cy+3]=134;
                map[cx+1][cy+3]=134;
                map[cx+2][cy+3]=134;
                map[cx+3][cy+3]=134;


            }
    for (x=1; x<255; x++) for (y=1; y<255; y++)
            if (map[x][y]<127)
                if ((map[x+1][y+1]>127) | (map[x+1][y-1]>127) | (map[x-1][y+1]>127) | (map[x-1][y-1]>127) | (map[x-1][y]>127) | (map[x+1][y]>127)|(map[x][y+1]>127)|(map[x][y-1]>127))
                {
                    map[x][y]=1;
                }

    for (x=0; x<256; x++) for (y=0; y<256; y++)
            if (map[x][y]==0)
                if (random16()==1) map[x][y]=2;

    for (x=0; x<256; x++) for (y=0; y<256; y++)
            if (map[x][y]==0)
                if (random16()==1) map[x][y]=129;

}
void GenForest()
{
    zzUint8 brush,k,l,n;
    zzSint16 x,y,cx,cy,i;
    for (x=0; x<256; x++) for (y=0; y<256; y++) map[x][y]=2;


    for (y=0; y<256; y++)
    {
        x=random8();
        while (x<255)
        {
            map[x][y]=128;
            x+=1+random8();
        }
    }

    for (i=0; i<200; i++)
    {
        brush=128;
        cx=4*random64();
        cy=4*random64();

        n=7+random16();
        for (k=0; k<n; k++)
        {
            x=cx;
            y=cy;
            l=random16();
            while ((l>0)&(x>0))
            {
                map[x][y]=brush;
                l--;
                x--;
            }
            l=random16();
            while ((l>0)&(y>0))
            {
                map[x][y]=brush;
                l--;
                y--;
            }
            l=random16();
            while ((l>0)&(x<254))
            {
                map[x][y]=brush;
                l--;
                x++;
            }
            l=random16();
            while ((l>0)&(y<254))
            {
                map[x][y]=brush;
                l--;
                y++;
            }


        }

    }

}
void GenCavern()
{
    zzUint8 brush,k,l,n;
    zzSint16 x,y,cx,cy,i;
    for (x=0; x<256; x++) for (y=0; y<256; y++) map[x][y]=132;


    for (i=0; i<200; i++)
    {
        brush=5;
        if (i<6)
        {
            cx=playerx;
            cy=playery;
        }
        else
        {
            cx=4*random64();
            cy=4*random64();
        }
        n=7+random16();
        for (k=0; k<n; k++)
        {
            x=cx;
            y=cy;
            l=random16();
            while ((l>0)&(x>0))
            {
                map[x][y]=brush;
                l--;
                x--;
            }
            l=random16();
            while ((l>0)&(y>0))
            {
                map[x][y]=brush;
                l--;
                y--;
            }
            l=random16();
            while ((l>0)&(x<255))
            {
                map[x][y]=brush;
                l--;
                x++;
            }
            l=random16();
            while ((l>0)&(y<255))
            {
                map[x][y]=brush;
                l--;
                y++;
            }


        }

    }
    for (y=0; y<256; y++)
    {
        x=random8();
        while (x<255)
        {
            if (map[x][y]<128)
                map[x][y]=2;
            x+=1+random16();
        }
    }

    for (y=0; y<256; y++)
    {
        x=random8();
        while (x<255)
        {
            if (map[x][y]<128)
                map[x][y]=133;
            x+=1+random16();
        }
    }

}
void GenDropShip()
{
    map[playerx][playery]=3;
    map[playerx-1][playery]=4;
    map[playerx+1][playery]=4;
    map[playerx][playery+1]=4;
    map[playerx][playery-1]=4;
    map[playerx-1][playery-1]=160;
    map[playerx+1][playery-1]=161;
    map[playerx-1][playery+1]=162;
    map[playerx+1][playery+1]=163;
}
void GenerateMap(unsigned int index)
{


    level=index;
//level=26;// custom level ejection

    if (level<16)
        leveltheme=table_rnd[level+20] & 3;// :)
    else
        leveltheme=table_rnd[level+20] & 7;

    leveltype=table_rnd[level] & 7;

    leveltank=(table_rnd[((level+45)*3)%1024]+3) % 4;

    playerx=64+zabs(table_rnd[level] & 127);
    playery=64+zabs(table_rnd[level+2] & 127);
    rnd_seed=index*3;
    camerazoom=5;
    icamerazoom=50000;

    switch (leveltype)
    {
    case 0:
        GenBunker();
        break;
    case 1:
        GenForest();
        GenDropShip();
        break;
    case 2:
        GenLake();
        GenDropShip();
        break;
    case 3:
        GenBase2();
        GenDropShip();
        break;
    case 4:
        GenCity();
        GenDropShip();
        break;
    case 5:
        GenBunker2();
        break;
    case 6:
        GenCavern();
        GenDropShip();
        break;
    case 7:
        GenBase();
        break;
    }

    mobenabled[0]=1;
    mobx[0]=65536*playerx+32666;
    moby[0]=65536*playery+32666;
    mobwx[0]=27000;
    mobwy[0]=25000;

    camerax=mobx[0]*16;
    cameray=moby[0]*16;
    icamerax=mobx[0]*16;
    icameray=moby[0]*16;
    player_angle=4;
    player_realangle=0;

    PlayMusic(leveltheme);
    SetPalette(leveltheme);

    count=0;
    player_gundelay=10;
    player_missledelay=50;
    mapmonsters=2+random8()+level/4;
    if (mapmonsters>31) mapmonsters=32;
    zzUint8 i;

    for (i=0; i<4; i++)
    {
        mobstack[i]=0;
        mobstacktype[i]=maptypemobs[leveltype][i];
    }
    mobstack[0]=5+random8()+level/4;
    mobstack[1]=1+level/6;
    mobstack[2]=level/8;
    mobstack[3]=level/12;


    switch (level)
    {
    case 16:
        mobstack[3]=1;
        mobstacktype[0]=1;
        mobstacktype[1]=1;
        mobstacktype[2]=1;
        mobstacktype[3]=11;
        break;
    case 19:
        leveltank=0;
        mobstack[3]=1;
        mobstacktype[0]=1;
        mobstacktype[1]=1;
        mobstacktype[2]=1;
        mobstacktype[3]=11;
        break;
    case 20:
        leveltank=0;
        mobstack[3]=1;
        mobstacktype[3]=11;
        break;
    case 21:
        leveltank=3;
        mobstack[1]=1;
        mobstacktype[1]=12;
        break;
    case 24:
        mobstack[3]=20;
        break;
    case 25:
        mapmonsters=32;
        mobstack[1]=100;
        break;

    }

    monstersleft=mobstack[0]+mobstack[1]+mobstack[2]+mobstack[3];
}



