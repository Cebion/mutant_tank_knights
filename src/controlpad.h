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
#include "globalvar.h"


#ifdef GP2X// GP2X button mapping

enum MAP_KEY
{
    VK_UP         , // 0
    VK_UP_LEFT    , // 1
    VK_LEFT       , // 2
    VK_DOWN_LEFT  , // 3
    VK_DOWN       , // 4
    VK_DOWN_RIGHT , // 5
    VK_RIGHT      , // 6
    VK_UP_RIGHT   , // 7
    VK_START      , // 8
    VK_SELECT     , // 9
    VK_FL         , // 10
    VK_FR         , // 11
    VK_FA         , // 12
    VK_FB         , // 13
    VK_FX         , // 14
    VK_FY         , // 15
    VK_VOL_UP     , // 16
    VK_VOL_DOWN   , // 17
    VK_FZ           // 18 :)
};
enum USBMAP_KEY
{
    USBVK_FA         , // 0
    USBVK_FX         , // 1
    USBVK_FB         , // 2
    USBVK_FY         , // 3
    USBVK_VOL_DOWN   , // 4
    USBVK_VOL_UP     , // 5
    USBVK_FL         , // 6
    USBVK_FR         , // 7
    USBVK_SELECT     , // 8
    USBVK_START      , // 9
    USBVK_FZ          // 10
};
#else
enum MAP_KEY
{
    VK_FA         , // 0
    VK_FX         , // 1
    VK_FB         , // 2
    VK_FY         , // 3
    VK_VOL_DOWN   , // 4
    VK_VOL_UP     , // 5
    VK_FL         , // 6
    VK_FR         , // 7
    VK_SELECT     , // 8
    VK_START      , // 9
    VK_FZ          // 10
};
#endif


void ControlPadUpdate(void);
