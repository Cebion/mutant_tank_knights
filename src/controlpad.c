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
#include "controlpad.h"

#define AXIS_DEADZONE 7000

static const zzSint8 angle_detection[9]=
{   7, 0, 1,
    6,-1, 2,
    5, 4, 3
};
int i_keyb[23];
#ifdef PANDORA
static const SDLKey sd_keyb[23]= {SDLK_KP8,SDLK_KP9,SDLK_KP6,SDLK_KP3,SDLK_KP2,SDLK_KP1,SDLK_KP4,SDLK_KP7,
                                  SDLK_HOME,SDLK_PAGEDOWN,SDLK_END,SDLK_PAGEUP,SDLK_RSHIFT,SDLK_RCTRL,SDLK_MINUS,SDLK_EQUALS,SDLK_ESCAPE,SDLK_TAB,SDLK_t,SDLK_UP,SDLK_RIGHT,SDLK_DOWN,SDLK_LEFT
                                 };
#else

static const SDLKey sd_keyb[23]= {SDLK_KP8,SDLK_KP9,SDLK_KP6,SDLK_KP3,SDLK_KP2,SDLK_KP1,SDLK_KP4,SDLK_KP7,
                                  SDLK_SPACE,SDLK_RETURN,SDLK_z,SDLK_LSHIFT,SDLK_LCTRL,SDLK_RCTRL,SDLK_MINUS,SDLK_EQUALS,SDLK_TAB,SDLK_ESCAPE,SDLK_z,SDLK_UP,SDLK_RIGHT,SDLK_DOWN,SDLK_LEFT
                                 };
#endif

static const int sd_key_ref[11]=
{
    PAD_A,PAD_B,PAD_X,PAD_Y,PAD_L1,PAD_R1,PAD_L2,PAD_R2,PAD_SELECT,PAD_START,PAD_Z

};
void ControlPadUpdate(void)
{
    int i;
    SDL_JoystickUpdate();
    controlpadbutton[PAD_A]=SDL_JoystickGetButton(joy,0);
    controlpadbutton[PAD_X]=SDL_JoystickGetButton(joy,1);
    controlpadbutton[PAD_B]=SDL_JoystickGetButton(joy,2);
    controlpadbutton[PAD_Y]=SDL_JoystickGetButton(joy,3);
// controlpadbutton[PAD_Z]=SDL_JoystickGetButton(joy,VK_FZ);

    controlpadbutton[PAD_L1]=SDL_JoystickGetButton(joy,4);
    controlpadbutton[PAD_R1]=SDL_JoystickGetButton(joy,5);
// controlpadbutton[PAD_L2]=SDL_JoystickGetButton(joy,VK_VOL_DOWN);
// controlpadbutton[PAD_R2]=SDL_JoystickGetButton(joy,VK_VOL_UP);

    controlpadbutton[PAD_START]=SDL_JoystickGetButton(joy,6);
// controlpadbutton[PAD_SELECT]=SDL_JoystickGetButton(joy,VK_SELECT);

    controlpadangle=-1;
    zzSint16 axis=SDL_JoystickGetAxis(joy,0);
    zzUint8 x=1;
    if (axis<-AXIS_DEADZONE) x=0;
    else if (axis>AXIS_DEADZONE) x=2;
    axis=SDL_JoystickGetAxis(joy,1);
    zzUint8 y=1;
    if (axis<-AXIS_DEADZONE) y=0;
    else if (axis>AXIS_DEADZONE) y=2;

    controlpadangle=angle_detection[x+y*3];
#ifndef GP2X

//Keyboard
    SDL_Event event;

    while (SDL_PollEvent (&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            GameLoopEnabled=0;
            break;
        case SDL_KEYDOWN:
            for (i=0; i<23; i++)
                if (event.key.keysym.sym==sd_keyb[i])
                    i_keyb[i]=1;
            if (event.key.keysym.sym==SDLK_ESCAPE)
                GameLoopEnabled=0;
            break;
        case SDL_KEYUP:
            for (i=0; i<23; i++)
                if (event.key.keysym.sym==sd_keyb[i])
                    i_keyb[i]=0;
            break;

        }
    }
    for (i=0; i<8; i++)
        if (i_keyb[i]) controlpadangle=i;

    if ((i_keyb[0]) & (i_keyb[2])) controlpadangle=1;
    if ((i_keyb[2]) & (i_keyb[4])) controlpadangle=3;
    if ((i_keyb[4]) & (i_keyb[6])) controlpadangle=5;
    if ((i_keyb[6]) & (i_keyb[0])) controlpadangle=7;
    if (i_keyb[19] | i_keyb[20] | i_keyb[21] | i_keyb[22])
    {
        if ((i_keyb[19])&(i_keyb[21]==0)&(i_keyb[20]==0)&(i_keyb[22]==0)) controlpadangle=0;
        else if ((i_keyb[20])&(i_keyb[21]==0)&(i_keyb[22]==0)&(i_keyb[19]==0)) controlpadangle=2;
        else if ((i_keyb[21])&(i_keyb[22]==0)&(i_keyb[20]==0)&(i_keyb[19]==0)) controlpadangle=4;
        else if ((i_keyb[22])&(i_keyb[21]==0)&(i_keyb[20]==0)&(i_keyb[19]==0)) controlpadangle=6;
        else if (i_keyb[19] & i_keyb[20]) controlpadangle=1;
        else if (i_keyb[20] & i_keyb[21]) controlpadangle=3;
        else if (i_keyb[21] & i_keyb[22]) controlpadangle=5;
        else if (i_keyb[22] & i_keyb[19]) controlpadangle=7;


    }



    for (i=8; i<19; i++)
        if (i_keyb[i]) controlpadbutton[i-8]=1;


#else
    /*
    if (SDL_JoystickGetButton(joy,VK_UP)) controlpadangle=0;
    else
    if (SDL_JoystickGetButton(joy,VK_UP_RIGHT)) controlpadangle=1;
    else
    if (SDL_JoystickGetButton(joy,VK_RIGHT)) controlpadangle=2;
    else
    if (SDL_JoystickGetButton(joy,VK_DOWN_RIGHT)) controlpadangle=3;
    else
    if (SDL_JoystickGetButton(joy,VK_DOWN)) controlpadangle=4;
    else
    if (SDL_JoystickGetButton(joy,VK_DOWN_LEFT)) controlpadangle=5;
    else
    if (SDL_JoystickGetButton(joy,VK_LEFT)) controlpadangle=6;
    else
    if (SDL_JoystickGetButton(joy,VK_UP_LEFT)) controlpadangle=7;


    if ((SDL_JoystickGetButton(joy,VK_UP))&(SDL_JoystickGetButton(joy,VK_RIGHT))) controlpadangle=1;
    else
    if ((SDL_JoystickGetButton(joy,VK_DOWN))&(SDL_JoystickGetButton(joy,VK_RIGHT))) controlpadangle=3;
    else
    if ((SDL_JoystickGetButton(joy,VK_DOWN))&(SDL_JoystickGetButton(joy,VK_LEFT))) controlpadangle=5;
    else
    if ((SDL_JoystickGetButton(joy,VK_UP))&(SDL_JoystickGetButton(joy,VK_LEFT))) controlpadangle=7;



    if (CradleMode)
    {
    zzSint16 axis=SDL_JoystickGetAxis(USBjoy,0);
    zzUint8 x=1;
    if (axis<-AXIS_DEADZONE) x=0;
    else
    if (axis>AXIS_DEADZONE) x=2;
    axis=SDL_JoystickGetAxis(USBjoy,1);
    zzUint8 y=1;
    if (axis<-AXIS_DEADZONE) y=0;
    else
    if (axis>AXIS_DEADZONE) y=2;

     controlpadangle=angle_detection[x+y*3];


     controlpadbutton[PAD_A]=SDL_JoystickGetButton(USBjoy,USBVK_FA);
     controlpadbutton[PAD_X]=SDL_JoystickGetButton(USBjoy,USBVK_FX);
     controlpadbutton[PAD_B]=SDL_JoystickGetButton(USBjoy,USBVK_FB);
     controlpadbutton[PAD_Y]=SDL_JoystickGetButton(USBjoy,USBVK_FY);


     controlpadbutton[PAD_L1]=SDL_JoystickGetButton(USBjoy,USBVK_VOL_DOWN);
     controlpadbutton[PAD_R1]=SDL_JoystickGetButton(USBjoy,USBVK_VOL_UP);
     controlpadbutton[PAD_Z]=0;
     if (controlpadbutton[PAD_L1]) if (controlpadbutton[PAD_R1])  controlpadbutton[PAD_Z]=1;

     controlpadbutton[PAD_START]=SDL_JoystickGetButton(USBjoy,USBVK_START);
     controlpadbutton[PAD_SELECT]=SDL_JoystickGetButton(USBjoy,USBVK_SELECT);

    }
    */


#endif
}
