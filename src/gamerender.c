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
#include "gamerender.h"
#include "globalvar.h"
#include "sfont.h"
#include "game.h"
#include "briefing.h"

#include "zmath.h"
zzUint8 buf[76800];
zzSint32 rx,ry;
zzSint32 width,height;
zzUint8 countanim;

zzSint32 interface_z=20;

zzUint8 getmap(zzSint32 px,zzSint32 py)
{
    zzUint8 c;
    c=0;
    if (px>=0)
        if (py>=0)
            if (px<256)
                if (py<256)
                    c=map[px][py];
    if (tileanim[c])
        c=c+countanim;
    return c;
}

void RenderMap(void)
{
    countanim=count/4%4;
    zzSint32 i,x,y,x0,y0;
    zzSint32 im,im0,imy,c,cx,cx0,cy,tex,temp;
    x0=rx;
    y0=ry;
    i=0;
    im0=x0 % 16;
    imy=y0 % 16;
    cx0=x0/16;
    cy=y0/16;

    for (y=0; y<height; y++)
    {
        im=im0;
        x=0;
        cx=cx0;

        c=getmap(cx,cy);

        //texel
        tex=(c & 31);
        tex=tex<<4;
        temp=c>>5;
        temp=temp<<4;
        temp=temp+imy;
        temp=temp<<9;
        tex+=temp+im;
        //texel

        while (x<width)
        {   //xxx

            buf[i+x]=tile[tex];
            tex++;
            im++;
            if (im==16)
            {
                im=0;
                cx++;
                c=getmap(cx,cy);
                //texel
                tex=(c & 31);
                tex=tex<<4;
                temp=c>>5;
                temp=temp<<4;
                temp=temp+imy;
                temp=temp<<9;
                tex+=temp;
                //texel
            }
            x++;
        }//xxx
        i+=320;
        imy++;

        if (imy==16)
        {
            imy=0;
            cy++;
        }
    }
}

void RenderSplats()
{
    zzSint32 x,y,i;
    for (i=0; i<32; i++)
        if (splat_alive[i])
        {
            x=splat_x[i]>>12;
            x-=rx;
            y=splat_y[i]>>12;
            y-=ry;
            if ((x<0)|(y<0)|(x>width)|(y>height))
                splat_alive[i]=0;
            else buf[x+y*320]=splat_color[i];
        }

}
void RenderParticles()
{
    zzSint32 x,y,i;
    for (i=32; i<96; i++)
        if (splat_alive[i])
        {
            x=splat_x[i]>>12;
            x-=rx;
            y=splat_y[i]>>12;
            y-=ry;
            if ((x<0)|(y<0)|(x>width)|(y>height))
                splat_alive[i]=0;
            else buf[x+y*320]=splat_color[i];
        }

}

void RenderSprite16(zzSint32 x,zzSint32 y,zzUint16 index)
{
    zzSint32 x0,y0,x1,y1;
    zzSint32 tex,temp,c,imy,im,ii;

    x0=x>>12;
    x0-=8;
    y0=y>>12;
    y0-=8;
    x0=x0-rx;
    y0=y0-ry;
    x1=x0+16;
    y1=y0+16;
    if (x0<width)
        if (x1>=0)
            if (y0<height)
                if (y1>=0)
                {
                    c=index;
                    imy=0;
                    im=0;
                    if (x0<0)
                    {
                        im=-x0;
                        x0=0;
                    }
                    if (y0<0)
                    {
                        imy=-y0;
                        y0=0;
                    }
                    if (x1>width) x1=width;
                    if (y1>height) y1=height;
                    //texel
                    tex=(c & 31);
                    tex=tex<<4;
                    temp=c>>5;
                    temp=temp<<4;
                    temp=temp+imy;
                    temp=temp<<9;
                    tex+=temp+im;
                    //texel
                    zzUint16 c0=tile[tex-im-512*imy];

                    zzUint16 x,y;

                    for (y=y0; y<y1; y++)
                    {
                        ii=tex+512*(y-y0);
                        for (x=x0; x<x1; x++)
                        {
                            zzUint8 color=tile[ii];
                            if (color!=c0)
                                buf[x+y*320]=color;
// else buf[x+y*320]=0;

                            ii++;
                        }
                    }
                }

}
void RenderMobs()
{
    zzSint32 x0,y0,x1,y1,i;
    zzSint32 tex,temp,c,imy,im,ii;
    for (i=31; i>=0; i--)
        if (mobenabled[i])
            if ((mobhp[i]>0) | (mobcount[i]& 1))
            {
                x0=mobx[i]>>12;
                x0-=mobspritex[i]/2;
                y0=moby[i]>>12;
                y0-=mobspritey[i]/2;
                x0=x0-rx;
                y0=y0-ry;
                x1=x0+mobspritex[i];
                y1=y0+mobspritey[i];
                if (x0<width)
                    if (x1>=0)
                        if (y0<height)
                            if (y1>=0)
                            {
                                c=mobsprite[i];
                                imy=0;
                                im=0;
                                if (x0<0)
                                {
                                    im=-x0;
                                    x0=0;
                                }
                                if (y0<0)
                                {
                                    imy=-y0;
                                    y0=0;
                                }
                                if (x1>width) x1=width;
                                if (y1>height) y1=height;
                                //texel
                                tex=(c & 31);
                                tex=tex<<4;
                                temp=c>>5;
                                temp=temp<<4;
                                temp=temp+imy;
                                temp=temp<<9;
                                tex+=temp+im;
                                //texel
                                zzUint16 c0=tile[tex-im-512*imy];
                                zzUint16 x,y;

                                for (y=y0; y<y1; y++)
                                {
                                    ii=tex+512*(y-y0);
                                    for (x=x0; x<x1; x++)
                                    {
                                        zzUint8 color=tile[ii];
                                        if (color!=c0)
                                            buf[x+y*320]=color;
// else buf[x+y*320]=0;

                                        ii++;
                                    }
                                }
                            }
            }
}

void RenderInterface()
{
//gebug
//l_textstring=sprintf(s_textstring,"%i/%i",monsters,mapmonsters);
//s_drawtext(21,100,0);
//s_drawtext(20,99,1);
//debug
    if (count<100)
    {
        l_textstring=sprintf(s_textstring,"ZONE %i-%i",1+(level-1)/8,1+(level-1)%8);
        s_drawtext2(100,162,0);
        s_drawtext2(100,158,0);
        s_drawtext2(98,160,0);
        s_drawtext2(102,160,0);
        s_drawtext2(100,160,1);

    }
    if (zoneclearcount)
    {
        zzSint32 i=0;
        zzUint16 x,y;

        for (y=0; y<239; y+=2)
        {
            for (x=0; x<320; x++)
                scrbuf[i+x]=0;
            i+=640;
        }
        if (zoneclearcount/4%2==0)
        {
            l_textstring=sprintf(s_textstring,"ZONE %i-%i CLEAR",1+(level-1)/8,1+(level-1)%8);
            s_drawtext2(50,152,0);
            s_drawtext2(50,148,0);
            s_drawtext2(48,150,0);
            s_drawtext2(52,150,0);
            s_drawtext2(50,150,1);
        }
        zoneclearcount++;
        if (zoneclearcount>64)
        {
            SetNewLevel(level+1);
        }
    }
    else if (count>16)
    {
        l_textstring=sprintf(s_textstring,"ARMOR RATING");
        s_drawtext(interface_z+1,interface_z+1,0);
        s_drawtext(interface_z,interface_z,1);

        if (count>32)
        {
            l_textstring=sprintf(s_textstring,"%i",mobhp[0]);
            s_drawtext2(interface_z+1,37,0);
            s_drawtext2(interface_z,36,1);
            if (count>48)
            {
                l_textstring=sprintf(s_textstring,"GAME SCORE");
                s_drawtext(241-interface_z,interface_z+1,0);
                s_drawtext(240-interface_z,interface_z,1);
                if (count>64)
                {
                    l_textstring=sprintf(s_textstring,"%i",score);
                    s_drawtext2(321-interface_z-l_textstring*16,37,0);
                    s_drawtext2(320-interface_z-l_textstring*16,36,1);
                    /*
                    if (count>72)
                    {
                    l_textstring=sprintf(s_textstring,"ZONE");
                    s_drawtext(267,219,0);
                    s_drawtext(266,217,1);
                    if (count>84)
                    {
                    l_textstring=sprintf(s_textstring,"%i-%i",1+(level-1)/8,1+(level-1)%8);
                    s_drawtext2(301-l_textstring*16,191,0);
                    s_drawtext2(300-l_textstring*16,190,1);
                    */
                    /*
                    if (count>94)
                    {
                    l_textstring=sprintf(s_textstring,"ENEMY");
                    s_drawtext(21,219,0);
                    s_drawtext(20,217,1);
                    if (count>108)
                    {
                    l_textstring=sprintf(s_textstring,"%i",monstersleft);
                    s_drawtext2(21,191,0);
                    s_drawtext2(20,190,1);
                    }
                    }
                    }
                    }
                    */
                }
            }
        }
    }

}

void RenderBullets(void)
{
    zzUint16 i;

    for (i=0; i<64; i++)
        if (bullet_alive[i])
        {
            zzUint16 index=288+bullet_angle[i]+8*bullet_type[i];
            RenderSprite16(bullet_x[i],bullet_y[i],index);
        }

}

void RenderPowerUps(void)
{
    zzUint8 i;

    for (i=0; i<32; i++)
        if (powerup_count[i])
        {
            zzUint16 index=512+powerup_index[i];
            RenderSprite16(powerup_x[i],powerup_y[i],index);
        }

}

void RenderSprites(void)
{
    zzUint8 i;
    for (i=0; i<64; i++)
        if (sprite_count[i])
        {
            zzUint16 index=sprite_index[i];
            RenderSprite16(sprite_x[i],sprite_y[i],index);
        }

}


void RenderMiniMap(void)
{
    zzSint32 x,y,ii;
    zzUint8 c;
    zzSint16 x0=120,y0=1+interface_z/2,x1=x0+90,y1=y0+40;
    zzSint16 cx,cy,ix,iy,px,py;
    cx=(x1+x0)/2;
    cy=(y1+y0)/2;

    px=mobx[0]/16384;
    py=moby[0]/16384;

    for (y=y0; y<y1; y++)
    {
        ii=y*320+x0;
        scrbuf[ii++]=1;

        for (x=x0; x<x1; x++)
        {
            c=0;
            ix=x-cx+px;
            iy=y-cy+py;
            ix=ix/4;
            iy=iy/4;
            if ((ix>0)&(iy>0)&(ix<255)&(iy<255))
            {
                if (map[ix][iy]>>7) c=2;
            }
            else if ((ix==0)|(iy==0)|(ix==255)|(iy==255)) c=1;

            scrbuf[ii++]=c;
        }
        scrbuf[ii]=1;
    }

    ii=y1*320+x0+1;
    for (x=x0; x<x1; x++)
        scrbuf[ii++]=1;
    ii=y0*320+x0-319;
    for (x=x0; x<x1; x++)
        scrbuf[ii++]=1;

    ii=cx+cy*320;
    zzUint8 i;

    for (i=1; i<32; i++)
        if (mobenabled[i])
        {
            ix=mobx[i]>>14;
            iy=moby[i]>>14;
            ix=cx+ix-px+1;
            iy=cy+iy-py+1;
            if ((ix>x0)&(iy>y0)&(ix<x1)&(iy<y1))
            {
                ii=ix+iy*320;
                scrbuf[ii]=3;
                scrbuf[ii-321]=3;
                scrbuf[ii-319]=3;
                scrbuf[ii+319]=3;
                scrbuf[ii+321]=3;
            }
        }

    for (i=0; i<64; i++)
        if (bullet_alive[i])
        {
            ix=bullet_x[i]>>14;
            iy=bullet_y[i]>>14;
            ix=cx+ix-px;
            iy=cy+iy-py;
            if ((ix>x0)&(iy>y0)&(ix<x1)&(iy<y1))
            {
                ii=ix+iy*320;
                scrbuf[ii]=1;
            }
        }


    ii=cx+cy*320;
    scrbuf[ii-320]=1;
    scrbuf[ii-1]=1;
    scrbuf[ii+1]=1;
    scrbuf[ii+320]=1;

}

void GameRender(void)
{
    zzSint32 x,y,i,ii;
    icamerax=icamerax+(camerax-icamerax)/9;
    icameray=icameray+(cameray-icameray)/9;

    if (camerazoom<0) camerazoom=0;
    else if (camerazoom>58000) camerazoom=58000;
    icamerazoom=icamerazoom+(camerazoom-icamerazoom)/8;




    if (camerax-160*(65536-icamerazoom)<0) {
        camerax=160*(65536-icamerazoom);
    }
    else if (icamerax+160*(65536-icamerazoom)>268435456) {
        icamerax=268435456-160*(65536-icamerazoom);
    }


    if (cameray-120*(65536-icamerazoom)<0) {
        cameray=120*(65536-icamerazoom);
    }
    else if (icameray+120*(65536-icamerazoom)>268435456) {
        icameray=268435456-120*(65536-icamerazoom);
    }



    rx=(icamerax-160*(65536-icamerazoom))>>16;
    ry=(icameray-120*(65536-icamerazoom))>>16;
//rx=icamerax>>16;
//ry=icameray>>16;
    if (icamerazoom<0) icamerazoom=0;
    else if (icamerazoom>65000) icamerazoom=65000;

    width=320*(65536-icamerazoom)/65536;
    height=240*(65536-icamerazoom)/65536;
    if (width>320) width=320;
    else if (width<32) width=32;
    if (height>240) height=240;
    else if (height<24) height=24;


    if (rx<0) rx=0;

    if (ry<0) ry=0;

///////

    RenderMap();
    RenderSplats();
    RenderPowerUps();
    RenderMobs();
    RenderParticles();
    RenderBullets();
    RenderSprites();

////////////////

    i=0;
    ii=0;
    zzSint32 step,stepy,istepx,istepy;
    step=width*65536/320;
    istepx=0;
    istepy=0;
    y=0;
    stepy=height*65536/240;

    zzUint8 newrow=1,y2=0;

    while(y<240)
    {
        istepx=0;
        if (newrow)
        {
            ii=y2*320;
            for (x=0; x<320; x++)
            {
                scrbuf[x+i]=buf[ii];
                istepx+=step;
                if (istepx>65536)
                {
                    istepx=istepx & 65535;
                    ii++;
                }
            }
        }
        else
            for (x=0; x<320; x++) scrbuf[x+i]=scrbuf[x+i-320];

        istepy+=stepy;
        if (istepy>65536)
        {
            istepy=istepy & 65535;
            y2++;
            newrow=1;
        }
        else newrow=0;
        i+=320;
        y++;
    }

    if (hurtcount)
    {
        for (i=0; i<76800; i++)
            scrbuf[i]=3-scrbuf[i];
        hurtcount--;
    }
    else if (flashcount)
    {
        for (i=0; i<76800; i++)
            if (scrbuf[i]==2) scrbuf[i]=1;
        flashcount--;
    }


    interface_z=20-(40000-icamerazoom)/1250;

    if (interface_z>20) interface_z=20;
    else if (interface_z<0) interface_z=0;

    if (zoneclearcount==0) if (count>110) RenderMiniMap();

    RenderInterface();
    DrawDialog();
}
