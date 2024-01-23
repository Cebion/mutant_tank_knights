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

enum MAP_VIRTUAL_PAD
{
    PAD_A,
    PAD_X,
    PAD_B,
    PAD_Y,
    PAD_L1,
    PAD_R1,
    PAD_L2,
    PAD_R2,
    PAD_SELECT,
    PAD_START,
    PAD_Z
};

extern SDL_Surface *screen;
extern SDL_Joystick *joy;
extern int audio_rate;
extern zzUint16 audio_format;
extern int audio_channels;
extern int audio_buffers;
extern zzUint8 volume;
extern zzSint8 trackname_delay,volume_delay;
extern zzSint8 SoundMode;
extern Mix_Chunk *d_sound[32];

extern zzUint8 CradleMode;
extern zzUint8 d_sound_count;

extern zzSint8 controlpadangle;
extern zzUint8 controlpadbutton[11];

extern SDL_Joystick *USBjoy;

extern zzUint8 GameLoopEnabled;
extern zzUint8 scrbuf[76800];
extern zzUint8 mmapii[64][64];

extern zzUint32 count;
extern char s_textstring[128];
extern int l_textstring;

extern zzUint32 ltickcount,tickcount,tickcount2;
extern zzUint8 fps,fps_done;
extern zzSint32 f_sin[4096],f_cos[4096],f_tan[1024];
extern zzUint16 rnd_seed;
extern zzUint8 map[256][256],tile[262144];
extern zzSint32 camerax,cameray,camerazoom;
extern zzSint32 icamerax,icameray,icamerazoom,score,highscore;
extern zzUint8 level;
extern zzSint8 player_angle,player_realangle;

extern zzSint32 mobx[32],moby[32],mobix[32],mobiy[32],mobwx[32],mobwy[32],mobcount[32];
extern zzSint16 mobsprite[32],mobspritex[32],mobspritey[32];
extern zzSint8  mobenabled[32],mobtype[32],mobside[32],mobdir[32],mobfromstack[32];
extern zzSint8 mobhp[32];
extern zzUint8 leveltheme,leveltype,leveltank;
extern zzUint8 tileanim[256],tilesplateffect[256];
extern zzUint8 table_rnd[1024];
extern zzUint8 gameovercount,zoneclearcount,gamemode,LCDmode,hurtcount,flashcount;
extern zzSint32 monstersleft;
extern zzUint8 splat_color[96],splat_alive[96];
extern zzSint32 splat_x[96],splat_y[96],splat_ix[96],splat_iy[96],splat_ix2[96],splat_iy2[96];

extern zzUint8 bullet_alive[64],bullet_type[64],bullet_side[64],bullet_angle[64];
extern zzSint32 bullet_x[64],bullet_y[64],bullet_ix[64],bullet_iy[64];

extern zzSint32 sprite_x[64],sprite_y[64],sprite_ix[64],sprite_iy[64],sprite_index[64],sprite_count[64];
extern zzUint8 sprite_life[64],sprite_animated[64];

extern zzUint16 powerup_count[32],powerup_index[32];
extern zzSint32 powerup_x[32],powerup_y[32];


extern zzUint16 player_gundelay,player_missledelay;
extern zzUint8 mapmonsters,monsters;
extern zzSint32 angle_tox[8],angle_toy[8];

extern zzUint16 mobstack[4],mobstacktype[4];

extern zzUint8 ipal[256][3];
extern zzUint8 DialogOn;
