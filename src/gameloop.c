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
//#include <stdlib.h>
#include "globalvar.h"
#include "gameloop.h"
#include "render.h"
#include "gameproc.h"

void calcfps(void)
{
    if (tickcount-tickcount2>1000)
    {
        fps=fps_done;
        fps_done=0;
        tickcount2=tickcount;
    }
}
void gameloop(void)
{
    while (GameLoopEnabled)
    {
        Gameprocess();
        Render();
        fps_done++;
//#ifdef WIN32
        SDL_Delay(20);
//#endif
        tickcount=SDL_GetTicks();
        count++;
        calcfps();
    }
}
