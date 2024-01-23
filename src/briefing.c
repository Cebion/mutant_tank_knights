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
#include "sfont.h"
#include "zmath.h"


char briefing[1024][48]=
//                                             |
{
    "This is HQ! Abort Mission!",
    "You forgot to read the game manual!1",

    "No problem! I will read it",
    "just after I return to base...0",

    "There are bunch of wierd buttons",
    "on my Gp2x. Why they for?0",

    "A,B,X,Y - shoot primary weapon,",
    "L and R - shoot secondaty weapon1",

//
    "Hey, Briefing Girl!",
    "What drops from dead enemies?0",

    "That is a random bonuses.",
    "You can pick it up.1",

    "Awesome! My tank has the",
    "automatic scavanging system!0",

    "But beware of skull-shaped ones!",
    "These can harm your tank.1",
//
    "Damn! Our base under attack!",
    "And all I got is this carriot?0",

    "Do not underistimate it",
    "It has two machine guns.1",

    "You driving a prototype that",
    "also has experimentary blaster.1",

    "Now finish remaining enemies",
    "Use minimap to detect them.1",

//
    "Earthquakes had formed giant",
    "cave systems all around planet.1",

    "Damn! More mutants!",
    "There is no end to them!0",

    "In order to complete mission",
    "you need to destroy them.1",

    "Show no mercy,",
    "brave tank driver!1",
//
    "That place looks abandoned",
    "There is no data that we seek.0",

    "Eliminate mutants, so second",
    "team could perform search.1",

    "Affirmative! No problem as long",
    "as there bullets in the chamber.0",

    "Our engineers made these",
    "unlimited ammo just for that.1",

//
    "STOP! You using the wrong tank!",
    "That one is not ready yet.1",

    "That tank surely has devastating",
    "missle attack. I like it.0",

    "For a sake of god! Do not shoot",
    "in the fuel containers!1",

    "Why?.. ... ...",
    "Ah! They explode! Got It.0",

//
    "Wipe out these worms out",
    "from these tunnels.1",

    "There will be place for",
    "our new labaratory.1",

    "... another cave mission...",
    "I want to see some trees outside.0",

    "I miss the green landscapes too.",
    "That mutant invasion is bad :(1",
//
    "Something big just crawled",
    "through this military base.1",

    "Careful about these living",
    "bombs.1",

    "I can touch them and drive away",
    "There is plenty on time.0",

    "Do not risk the vehicle",
    "The repairs is a big trouble1",

//
    "WHAT ARE HELL YOU DOING?!!",
    "GET BACK IN TANK!!!1",

    "Only coward fights enemy",
    "using strange looking tanks.0",

    "I can tear them with my bare",
    "hands.0",

    "Do not eat their corpses then...",
    "We need you alive!1",

//
    "Base, do you read me?..",
    "I kinda lost...0",

    "So lonely...",
    "I have no tank radio...0",

    "I'm hungry. I have only",
    "last food ration...0",

    "Damn! Nobody reads.",
    "I really miss the Briefing Girl.0",

//
    "Does somebody reads this",
    "frequency? I'm sending SOS!0",

    "I got your signal",
    "Head north. We will find you.2",

    "Name yourself! Are you from",
    "federal army or resistanse?0",

    "My name is Lord Irish.",
    "I need you to destroy mutants.2",
//
    "The source of these mutants",
    "lies in military experiments.2",

    "I want to return peace to",
    "my country.2",

    "That is why my kindrom needs",
    "such tank driver as yourself.2",

    "Your platoon is just a bit eastern.",
    "We will meet at swamps later.2",

//
    "Finaly we contacted you!",
    "Still we cannot locate you.1",

    "Destroy nearby monsters! They are",
    "causing big noise in radiowaves.1",

    "So that is why your face flickers",
    "on my display...0",

    "You better listen to her.",
    "Mutants are very radioactive.2",

//
    "Check this city for survivors",
    "SOS sygnal was recieved hour ago.1",

    "I doubt that here anyone that",
    "breathes. So much poisoned gas.0",

    "That must be stopped",
    "Soon whole Earth will be dead.2",

    "This is a dead town anyway",
    "No one here now.0",

//
    "Scout these region so our",
    "convoy could pass it undamaged.1",

    "I got recently contacted by",
    "some Lord Irish. Know him?0",

    "... not in our database.",
    "Whad did he mentioned?1",

    "That his land was attacked too.",
    "Also want meet at swamps.0",

//
    "HA HA HA! You fell to my trap!",
    "You, stypid tank driver!2",

    "Do not let him get away!",
    "Otherwise he will be healed!1",

    "Do not worry!",
    "I got ROCKET TANK!0",

    "Dig your grave.",
    "You gonna die, tank driver.2",
// 16

    "Search the ruined labaratory",
    "for survivors!1",

    "Shall I search for a shiny",
    "things too?0",

    "You got tank! You got order!",
    "Do you understand?1",

    "...",
    "Not at all...0",

//
    "Thanks for saving me!",
    "Now drive to exit!2",

    "DO NOT TOUCH MY CONTROL",
    "PANEL, YOU FREAK!0",

    "OH! NO! More mutants!",
    "You must anihilate them!2",

    "We need that survivor alive!",
    "Do not let mutants get him.1",

//

    "I have wierd feeling about",
    "that passenger...0",

    "Damn! Is the Lord Irish!",
    "He is alive!!!1",

    "Bwa-ha-ha-ha! I will tear",
    "your tank down to plates!2",

    "Hands off my tank, you,",
    "two-legged idiot.0",

//

    "You cannot run away",
    "from your death!2",

    "Oh, NOOO!!!",
    "He is followed you!1",

    "Your tiny tank will rot",
    "forever in this swamp!..2",

    "Is he after me or my",
    "tank instead?0",

//

    "I will take shelter in",
    "these tunnels...0",

    "There some giant monster",
    "just have entered the tunnels!!!1",

    "Guess who it is?",
    "HA-HA-HA!2",

    "Look! He has mutated to the next",
    "stage!1",
//
    "Was it the Nuclear Explosion?",
    "What is going on at the base?0",

    "Our perimeter have just been",
    "breached. Mutants evrywhere!1",

    "How they have found our",
    "secret base???0",

    "I think we got a traitor",
    "in our ranks.1",
//

    "These caves are the fastest",
    "way I can reach the base.0",

    "KDIF!fffwwwiiuuuv...fvs....",
    "laauuiiffevr...bfs..ihttee.1",

    "Looks likes something is",
    "jamming radio signal.0",

    "gjero...ssssttttk....",
    "......LORD...IRISH...1",
//

    "Damn! Too many mechs ahead.",
    "I should be strong.0",

    "My missles are the heavenly",
    "blades that reap the darkness!0",

    "My tanks controls is supreme",
    "techical interface!0",

    "Now die stypid biomechanical",
    "twolegged abodimations!0",
//
    "Oh NOOOO! The whole base",
    "personell is now zombies!0",

    "igj..roivmkf...djslsm?",
    "dfjgo..epph...obkb..d.1",

    "Signal jammer should be",
    "somwhere in this base.0",

    "ohkh..wwfpg...nmnkwwww...",
    "...........gsdkgeobksgw..1",

//
    "These foul dungeons",
    "are full of mutants!0",

    "There should be their",
    "source somewhere0",

    "I would like to know",
    "what happened to our base0",

    "I guess I will find",
    "it soon enogh!0",

};
//                              |

zzUint32 DialogTime[4];

void DrawDialog(void)
{
    zzUint32 i;
    DialogTime[0]=50+table_rnd[level*2];
    DialogTime[1]=DialogTime[0]+256+table_rnd[1+level*2];
    DialogTime[2]=DialogTime[1]+256+table_rnd[3+level*2];
    DialogTime[3]=DialogTime[2]+256+table_rnd[level*4];




    DialogOn=0;

    for (i=0; i<4; i++)
        if (count>DialogTime[i])
            if (count<DialogTime[i]+228)
                DialogOn=i+1;

    if (DialogOn)
    {
        zzSint32 textcount=0;
        textcount=count-DialogTime[DialogOn-1];
        textcount=textcount/2;
// FRAME
        for (i=64000; i<76800; i++)
            scrbuf[i]=0;
        for (i=0; i<320; i++)
        {
            scrbuf[64000+i]=1;
            scrbuf[76480+i]=1;
        }

//TEXT
        textcount=textcount-8;
        if (textcount<0) textcount=0;
        l_textstring=sprintf(s_textstring,"%s",briefing[(level-1)*8+ 2*(DialogOn-1)]);

        if (l_textstring>textcount) l_textstring=textcount;
        s_drawtext(48,204,1);
        textcount=textcount-l_textstring;
        if (textcount<0) textcount=0;
        l_textstring=sprintf(s_textstring,"%s",briefing[(level-1)*8+ 2*(DialogOn-1)+1]);

        zzUint8 portraitID=(zzUint8)(s_textstring[l_textstring-1])-'0';
        zzUint8 allissaid=0;

        if (l_textstring>textcount) l_textstring=textcount;
        else allissaid=1;
        if (l_textstring>0) l_textstring--;
        s_drawtext(48,220,1);
        if (count/10%2==0)
        {
            l_textstring=sprintf(s_textstring,"<-TRANSMISSION->");
            s_drawtext(99,190,0);
            s_drawtext(101,190,0);
            s_drawtext(100,189,0);
            s_drawtext(100,191,0);
            s_drawtext(100,190,1);
        }

//Transmission


//PORTRAIT
        zzSint32 x,y;
        zzUint8 color=1;
        i=4+204*320;

//l_textstring=sprintf(s_textstring,"ms:%i",portraitID);
//s_drawtext(150,10,1);

        if ((textcount<2) | (random32()==0))
        {
            for (y=0; y<32; y++)
            {

                for (x=0; x<32; x++)
                {
                    scrbuf[i++]=1+color;
                    if (random2()==0) color=(color+1)%2;
                }
                i+=288;
            }

        }
        else
        {
            zzUint32 ii;
            portraitID=portraitID*3;
            if (allissaid) portraitID+=2;
            else portraitID+=(count/5) %2;

            ii=416+(272+16*portraitID)*512;
            for (y=0; y<16; y++)
            {
                for (x=0; x<16; x++)
                {
                    scrbuf[i+320]=tile[ii];
                    scrbuf[i++]=tile[ii];

                    scrbuf[i+320]=tile[ii];
                    scrbuf[i++]=tile[ii++];
                }
                i+=288+320;
                ii+=496;
            }


        }


    }
}
