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
#include "sprites.h"
#include "bullets.h"
#include "sound.h"
#include "monsters.h"

void SpawnPowerUp(signed long int x,signed long int y,unsigned int index)
{
    zzUint8 i=0;
    while ((powerup_count[i]>0) & (i<64)) i++;
    if (i==32) i=random32();

    powerup_x[i]=x;
    powerup_y[i]=y;

    powerup_index[i]=index;
    powerup_count[i]=255;

}

void ProcPowerUps(void)
{
    zzUint8 i;

    for (i=0; i<32; i++)
        if (powerup_count[i]>0)
        {

            powerup_count[i]--;



            if ((zabs(mobx[0]-powerup_x[i])<45536)&(zabs(moby[0]-powerup_y[i])<45536))
            {
                powerup_count[i]=0;
                SpawnSpriteil(mobx[0],moby[0],512+powerup_index[i],0,-10000,16);
                zzUint8 k;

                switch (powerup_index[i])
                {
                case 0:
                    mobhp[0]++;
                    break;
                case 1:
                    score+=100;
                    break;
                case 2:

                    for (k=0; k<8; k++)
                        SpawnBullet(mobx[0]+angle_tox[k]*40,moby[0]+angle_toy[k]*40,k,0,0);

                    break;

                case 3:
                    HurtMob(0,4);
                    break;

                }//switch
                sPlaySound(9,127,127);
            }
            else if (powerup_count[i]==0)
                SpawnSpriteil(powerup_x[i],powerup_y[i],512+powerup_index[i],0,-10000,16);

        }
}

extern void ClearPowerUps(void)
{

}
