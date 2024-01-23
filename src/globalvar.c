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
SDL_Surface *screen;
zzUint8 d_sound_count = 0;

int audio_channels = 2;
int audio_rate = 22050;
#ifdef GP2X
zzUint16 audio_format = AUDIO_U16;
int audio_buffers = 256;
#else
zzUint16 audio_format = AUDIO_S16;
int audio_buffers = 1024;
#endif

Mix_Chunk *d_sound[32];

zzSint8 controlpadangle;
zzUint8 controlpadbutton[11];

zzUint8 CradleMode=0;
zzUint8 volume;
zzSint8 trackname_delay,volume_delay=0;
zzSint8 SoundMode=0;

SDL_Joystick *joy;
SDL_Joystick *USBjoy;

zzUint8 GameLoopEnabled=1;

zzUint8 scrbuf[76800];
zzUint32 count;
zzUint8 mmapii[64][64];

char s_textstring[128];
int l_textstring;
zzUint32 tickcount,tickcount2,ltickcount;
zzUint8 fps,fps_done;

zzSint32 f_sin[4096],f_cos[4096],f_tan[1024];



zzUint8 map[256][256],tile[262144];
zzSint32 camerax,cameray,camerazoom;
zzSint32 icamerax,icameray,icamerazoom;
zzUint8 level;
zzSint32 mobx[32],moby[32],mobix[32],mobiy[32],mobwx[32],mobwy[32],mobcount[32];
zzSint16 mobsprite[32],mobspritex[32],mobspritey[32];
zzSint8  mobenabled[32],mobtype[32],mobside[32],mobdir[32],mobfromstack[32];
zzSint8 mobhp[32];
zzSint8 player_angle,player_realangle;
zzUint8 leveltheme,leveltype,leveltank;
zzUint8 tileanim[256],tilesplateffect[256];
zzSint32 score,highscore;
zzUint8 gameovercount,zoneclearcount,gamemode,LCDmode,hurtcount,flashcount;
zzSint32 monstersleft;

zzUint8 splat_color[96],splat_alive[96];
zzSint32 splat_x[96],splat_y[96],splat_ix[96],splat_iy[96],splat_ix2[96],splat_iy2[96];

zzUint8 bullet_alive[64],bullet_type[64],bullet_side[64],bullet_angle[64];
zzSint32 bullet_x[64],bullet_y[64],bullet_ix[64],bullet_iy[64];
zzSint32 sprite_x[64],sprite_y[64],sprite_ix[64],sprite_iy[64],sprite_index[64],sprite_count[64];
zzUint8 sprite_life[64],sprite_animated[64];

zzUint16 powerup_count[32],powerup_index[32];
zzSint32 powerup_x[32],powerup_y[32];


zzUint16 player_gundelay,player_missledelay;
zzSint32 angle_tox[8]= {0,256,256,256,0,-256,-256,-256},angle_toy[8]= {-256,-256,0,256,256,256,0,-256};
zzUint8 mapmonsters,monsters;
zzUint16 mobstack[4],mobstacktype[4];

zzUint8 table_rnd[1024]= {30,193,252,152,70,237,135,54,35,249,126,200,86,176,108,172,
                          218,181,240,108,218,165,105,134,82,227,126,46,197,251,103,157,
                          192,165,243,101,79,13,69,134,250,247,94,26,68,156,38,36,
                          59,217,31,131,233,23,253,52,182,100,39,74,219,118,124,144,
                          37,137,225,94,55,114,9,20,66,148,45,112,187,47,45,43,
                          108,0,4,38,90,44,98,24,110,118,78,235,71,23,226,172,
                          252,153,44,226,27,190,184,228,186,51,149,175,156,3,6,4,
                          146,56,238,208,116,135,68,78,176,113,154,95,147,50,10,174,
                          57,197,203,34,209,62,137,245,252,209,97,14,15,149,122,120,
                          190,130,77,205,255,153,37,245,49,191,19,127,41,7,32,82,
                          11,188,64,96,203,88,62,95,4,203,160,224,212,171,28,109,
                          22,41,219,179,18,38,15,167,1,151,51,98,0,119,7,36,
                          43,93,243,69,224,87,27,72,85,21,31,74,216,126,200,15,
                          242,92,48,104,214,159,244,143,227,172,199,11,124,210,180,59,
                          110,78,91,9,241,103,247,189,166,147,150,234,99,87,56,183,
                          10,112,118,158,3,236,155,63,182,123,154,29,1,220,165,53,
                          70,80,177,2,157,142,63,188,52,47,32,21,77,73,61,99,
                          11,239,170,109,32,181,195,84,193,162,71,163,107,215,56,248,
                          175,35,246,203,185,50,180,187,107,72,253,117,50,105,128,94,
                          164,199,12,182,223,114,132,115,15,157,178,18,48,251,30,141,
                          123,186,115,25,60,55,171,16,250,140,85,136,20,2,95,134,
                          41,241,25,182,65,244,86,145,38,89,79,112,89,192,190,28,
                          235,229,93,78,122,58,24,22,17,26,114,167,48,207,125,70,
                          200,160,13,14,102,75,27,168,47,57,198,183,14,61,164,215,
                          93,96,139,242,160,195,237,12,252,103,34,121,129,72,245,222,
                          169,57,138,233,83,230,5,218,24,134,236,96,75,21,106,73,
                          173,124,201,212,44,92,95,96,161,115,112,117,144,40,33,159,
                          130,229,179,147,206,153,152,150,189,141,210,76,120,101,198,139,
                          224,113,111,240,221,66,232,137,91,217,42,242,34,111,191,125,
                          209,42,202,242,247,155,54,5,81,109,51,216,16,227,17,148,
                          71,65,102,170,74,52,139,185,97,201,122,45,68,97,204,84,
                          35,121,16,116,230,152,168,174,146,104,148,5,210,131,98,157,
                          113,85,19,246,254,87,81,29,244,33,33,219,67,210,196,79,
                          31,58,194,173,138,211,86,164,91,117,4,248,226,110,244,19,
                          7,81,139,220,82,119,111,46,56,104,208,5,66,249,131,64,
                          11,142,79,133,133,98,29,53,187,177,217,231,90,65,47,186,
                          151,43,129,235,20,214,212,225,10,175,231,18,106,196,207,13,
                          130,168,243,184,76,2,12,66,0,100,69,161,158,240,130,142,
                          248,193,48,115,67,57,74,141,198,99,140,237,8,153,178,0,
                          228,108,87,220,217,168,194,176,7,238,209,202,230,89,83,220,
                          246,163,185,60,154,18,136,105,171,107,6,50,149,159,201,129,
                          214,19,174,144,54,234,76,204,164,107,221,233,121,237,255,208,
                          133,234,88,32,187,138,213,143,161,49,140,145,151,159,1,25,
                          211,63,148,208,251,166,8,104,132,26,180,221,199,14,189,67,
                          17,120,10,8,216,17,146,239,132,39,175,39,114,179,202,46,
                          46,254,229,251,158,125,37,86,249,200,71,230,88,185,231,23,
                          6,177,169,26,155,161,136,135,54,193,2,202,123,163,28,123,
                          142,116,84,176,41,119,162,145,255,58,60,35,21,156,170,33,
                          24,215,81,80,128,36,246,222,236,119,215,167,122,238,93,77,
                          207,29,250,69,60,219,192,151,36,70,232,253,103,146,68,194,
                          61,236,55,39,228,245,243,204,170,59,163,28,64,149,82,238,
                          184,190,3,241,254,143,34,67,43,211,55,166,127,189,101,40,
                          184,100,250,128,225,212,162,136,63,183,232,62,173,196,205,113,
                          131,30,216,156,129,226,144,181,106,72,232,120,30,51,205,180,
                          150,222,9,23,22,73,253,73,207,186,213,172,194,45,109,147,
                          121,65,166,188,235,241,53,152,213,27,44,229,88,102,169,97,
                          91,125,145,160,150,201,128,83,183,117,92,126,58,105,206,133,
                          1,100,37,191,135,233,223,49,80,154,213,162,247,106,124,6,
                          223,199,198,59,64,224,177,254,141,178,118,12,8,225,188,211,
                          248,49,138,228,90,101,195,197,52,192,196,102,9,255,22,75,
                          178,239,205,42,75,191,249,181,206,218,197,62,111,171,84,155,
                          222,80,167,61,77,127,137,240,92,179,94,53,85,42,165,13,
                          127,132,140,40,83,16,20,89,40,204,169,214,227,239,195,143,
                          173,116,223,206,110,158,90,234,174,76,25,221,31,231,3,99
                         };

zzUint16 rnd_seed=0;

zzUint8 ipal[256][3];

zzUint8 DialogOn;
