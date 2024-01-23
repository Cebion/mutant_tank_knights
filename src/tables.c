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
#define FPDIV(x,y)	((((x)<<10)/((y)>>2))>>4)

void LoadTables(void)
{
    f_sin[0]=0;
    f_sin[1]=101;
    f_sin[2]=201;
    f_sin[3]=302;
    f_sin[4]=402;
    f_sin[5]=503;
    f_sin[6]=603;
    f_sin[7]=704;
    f_sin[8]=804;
    f_sin[9]=905;
    f_sin[10]=1005;
    f_sin[11]=1106;
    f_sin[12]=1206;
    f_sin[13]=1307;
    f_sin[14]=1407;
    f_sin[15]=1508;
    f_sin[16]=1608;
    f_sin[17]=1709;
    f_sin[18]=1809;
    f_sin[19]=1910;
    f_sin[20]=2010;
    f_sin[21]=2111;
    f_sin[22]=2211;
    f_sin[23]=2312;
    f_sin[24]=2412;
    f_sin[25]=2513;
    f_sin[26]=2613;
    f_sin[27]=2714;
    f_sin[28]=2814;
    f_sin[29]=2914;
    f_sin[30]=3015;
    f_sin[31]=3115;
    f_sin[32]=3216;
    f_sin[33]=3316;
    f_sin[34]=3417;
    f_sin[35]=3517;
    f_sin[36]=3617;
    f_sin[37]=3718;
    f_sin[38]=3818;
    f_sin[39]=3918;
    f_sin[40]=4019;
    f_sin[41]=4119;
    f_sin[42]=4219;
    f_sin[43]=4320;
    f_sin[44]=4420;
    f_sin[45]=4520;
    f_sin[46]=4621;
    f_sin[47]=4721;
    f_sin[48]=4821;
    f_sin[49]=4921;
    f_sin[50]=5022;
    f_sin[51]=5122;
    f_sin[52]=5222;
    f_sin[53]=5322;
    f_sin[54]=5422;
    f_sin[55]=5523;
    f_sin[56]=5623;
    f_sin[57]=5723;
    f_sin[58]=5823;
    f_sin[59]=5923;
    f_sin[60]=6023;
    f_sin[61]=6123;
    f_sin[62]=6224;
    f_sin[63]=6324;
    f_sin[64]=6424;
    f_sin[65]=6524;
    f_sin[66]=6624;
    f_sin[67]=6724;
    f_sin[68]=6824;
    f_sin[69]=6924;
    f_sin[70]=7024;
    f_sin[71]=7124;
    f_sin[72]=7224;
    f_sin[73]=7323;
    f_sin[74]=7423;
    f_sin[75]=7523;
    f_sin[76]=7623;
    f_sin[77]=7723;
    f_sin[78]=7823;
    f_sin[79]=7923;
    f_sin[80]=8022;
    f_sin[81]=8122;
    f_sin[82]=8222;
    f_sin[83]=8322;
    f_sin[84]=8421;
    f_sin[85]=8521;
    f_sin[86]=8621;
    f_sin[87]=8720;
    f_sin[88]=8820;
    f_sin[89]=8919;
    f_sin[90]=9019;
    f_sin[91]=9119;
    f_sin[92]=9218;
    f_sin[93]=9318;
    f_sin[94]=9417;
    f_sin[95]=9517;
    f_sin[96]=9616;
    f_sin[97]=9716;
    f_sin[98]=9815;
    f_sin[99]=9914;
    f_sin[100]=10014;
    f_sin[101]=10113;
    f_sin[102]=10212;
    f_sin[103]=10312;
    f_sin[104]=10411;
    f_sin[105]=10510;
    f_sin[106]=10609;
    f_sin[107]=10709;
    f_sin[108]=10808;
    f_sin[109]=10907;
    f_sin[110]=11006;
    f_sin[111]=11105;
    f_sin[112]=11204;
    f_sin[113]=11303;
    f_sin[114]=11402;
    f_sin[115]=11501;
    f_sin[116]=11600;
    f_sin[117]=11699;
    f_sin[118]=11798;
    f_sin[119]=11897;
    f_sin[120]=11996;
    f_sin[121]=12095;
    f_sin[122]=12193;
    f_sin[123]=12292;
    f_sin[124]=12391;
    f_sin[125]=12490;
    f_sin[126]=12588;
    f_sin[127]=12687;
    f_sin[128]=12785;
    f_sin[129]=12884;
    f_sin[130]=12983;
    f_sin[131]=13081;
    f_sin[132]=13180;
    f_sin[133]=13278;
    f_sin[134]=13376;
    f_sin[135]=13475;
    f_sin[136]=13573;
    f_sin[137]=13672;
    f_sin[138]=13770;
    f_sin[139]=13868;
    f_sin[140]=13966;
    f_sin[141]=14065;
    f_sin[142]=14163;
    f_sin[143]=14261;
    f_sin[144]=14359;
    f_sin[145]=14457;
    f_sin[146]=14555;
    f_sin[147]=14653;
    f_sin[148]=14751;
    f_sin[149]=14849;
    f_sin[150]=14947;
    f_sin[151]=15045;
    f_sin[152]=15143;
    f_sin[153]=15240;
    f_sin[154]=15338;
    f_sin[155]=15436;
    f_sin[156]=15534;
    f_sin[157]=15631;
    f_sin[158]=15729;
    f_sin[159]=15826;
    f_sin[160]=15924;
    f_sin[161]=16021;
    f_sin[162]=16119;
    f_sin[163]=16216;
    f_sin[164]=16314;
    f_sin[165]=16411;
    f_sin[166]=16508;
    f_sin[167]=16606;
    f_sin[168]=16703;
    f_sin[169]=16800;
    f_sin[170]=16897;
    f_sin[171]=16994;
    f_sin[172]=17091;
    f_sin[173]=17188;
    f_sin[174]=17285;
    f_sin[175]=17382;
    f_sin[176]=17479;
    f_sin[177]=17576;
    f_sin[178]=17673;
    f_sin[179]=17770;
    f_sin[180]=17867;
    f_sin[181]=17963;
    f_sin[182]=18060;
    f_sin[183]=18156;
    f_sin[184]=18253;
    f_sin[185]=18350;
    f_sin[186]=18446;
    f_sin[187]=18543;
    f_sin[188]=18639;
    f_sin[189]=18735;
    f_sin[190]=18832;
    f_sin[191]=18928;
    f_sin[192]=19024;
    f_sin[193]=19120;
    f_sin[194]=19216;
    f_sin[195]=19313;
    f_sin[196]=19409;
    f_sin[197]=19505;
    f_sin[198]=19600;
    f_sin[199]=19696;
    f_sin[200]=19792;
    f_sin[201]=19888;
    f_sin[202]=19984;
    f_sin[203]=20080;
    f_sin[204]=20175;
    f_sin[205]=20271;
    f_sin[206]=20366;
    f_sin[207]=20462;
    f_sin[208]=20557;
    f_sin[209]=20653;
    f_sin[210]=20748;
    f_sin[211]=20844;
    f_sin[212]=20939;
    f_sin[213]=21034;
    f_sin[214]=21129;
    f_sin[215]=21224;
    f_sin[216]=21320;
    f_sin[217]=21415;
    f_sin[218]=21510;
    f_sin[219]=21604;
    f_sin[220]=21699;
    f_sin[221]=21794;
    f_sin[222]=21889;
    f_sin[223]=21984;
    f_sin[224]=22078;
    f_sin[225]=22173;
    f_sin[226]=22268;
    f_sin[227]=22362;
    f_sin[228]=22457;
    f_sin[229]=22551;
    f_sin[230]=22645;
    f_sin[231]=22740;
    f_sin[232]=22834;
    f_sin[233]=22928;
    f_sin[234]=23022;
    f_sin[235]=23116;
    f_sin[236]=23210;
    f_sin[237]=23304;
    f_sin[238]=23398;
    f_sin[239]=23492;
    f_sin[240]=23586;
    f_sin[241]=23680;
    f_sin[242]=23774;
    f_sin[243]=23867;
    f_sin[244]=23961;
    f_sin[245]=24054;
    f_sin[246]=24148;
    f_sin[247]=24241;
    f_sin[248]=24335;
    f_sin[249]=24428;
    f_sin[250]=24521;
    f_sin[251]=24614;
    f_sin[252]=24708;
    f_sin[253]=24801;
    f_sin[254]=24894;
    f_sin[255]=24987;
    f_sin[256]=25080;
    f_sin[257]=25172;
    f_sin[258]=25265;
    f_sin[259]=25358;
    f_sin[260]=25451;
    f_sin[261]=25543;
    f_sin[262]=25636;
    f_sin[263]=25728;
    f_sin[264]=25821;
    f_sin[265]=25913;
    f_sin[266]=26005;
    f_sin[267]=26098;
    f_sin[268]=26190;
    f_sin[269]=26282;
    f_sin[270]=26374;
    f_sin[271]=26466;
    f_sin[272]=26558;
    f_sin[273]=26650;
    f_sin[274]=26742;
    f_sin[275]=26833;
    f_sin[276]=26925;
    f_sin[277]=27017;
    f_sin[278]=27108;
    f_sin[279]=27200;
    f_sin[280]=27291;
    f_sin[281]=27382;
    f_sin[282]=27474;
    f_sin[283]=27565;
    f_sin[284]=27656;
    f_sin[285]=27747;
    f_sin[286]=27838;
    f_sin[287]=27929;
    f_sin[288]=28020;
    f_sin[289]=28111;
    f_sin[290]=28202;
    f_sin[291]=28293;
    f_sin[292]=28383;
    f_sin[293]=28474;
    f_sin[294]=28564;
    f_sin[295]=28655;
    f_sin[296]=28745;
    f_sin[297]=28835;
    f_sin[298]=28926;
    f_sin[299]=29016;
    f_sin[300]=29106;
    f_sin[301]=29196;
    f_sin[302]=29286;
    f_sin[303]=29376;
    f_sin[304]=29466;
    f_sin[305]=29555;
    f_sin[306]=29645;
    f_sin[307]=29735;
    f_sin[308]=29824;
    f_sin[309]=29914;
    f_sin[310]=30003;
    f_sin[311]=30093;
    f_sin[312]=30182;
    f_sin[313]=30271;
    f_sin[314]=30360;
    f_sin[315]=30449;
    f_sin[316]=30538;
    f_sin[317]=30627;
    f_sin[318]=30716;
    f_sin[319]=30805;
    f_sin[320]=30893;
    f_sin[321]=30982;
    f_sin[322]=31071;
    f_sin[323]=31159;
    f_sin[324]=31248;
    f_sin[325]=31336;
    f_sin[326]=31424;
    f_sin[327]=31512;
    f_sin[328]=31600;
    f_sin[329]=31688;
    f_sin[330]=31776;
    f_sin[331]=31864;
    f_sin[332]=31952;
    f_sin[333]=32040;
    f_sin[334]=32127;
    f_sin[335]=32215;
    f_sin[336]=32303;
    f_sin[337]=32390;
    f_sin[338]=32477;
    f_sin[339]=32565;
    f_sin[340]=32652;
    f_sin[341]=32739;
    f_sin[342]=32826;
    f_sin[343]=32913;
    f_sin[344]=33000;
    f_sin[345]=33087;
    f_sin[346]=33173;
    f_sin[347]=33260;
    f_sin[348]=33347;
    f_sin[349]=33433;
    f_sin[350]=33520;
    f_sin[351]=33606;
    f_sin[352]=33692;
    f_sin[353]=33778;
    f_sin[354]=33865;
    f_sin[355]=33951;
    f_sin[356]=34037;
    f_sin[357]=34122;
    f_sin[358]=34208;
    f_sin[359]=34294;
    f_sin[360]=34380;
    f_sin[361]=34465;
    f_sin[362]=34551;
    f_sin[363]=34636;
    f_sin[364]=34721;
    f_sin[365]=34806;
    f_sin[366]=34892;
    f_sin[367]=34977;
    f_sin[368]=35062;
    f_sin[369]=35146;
    f_sin[370]=35231;
    f_sin[371]=35316;
    f_sin[372]=35401;
    f_sin[373]=35485;
    f_sin[374]=35570;
    f_sin[375]=35654;
    f_sin[376]=35738;
    f_sin[377]=35823;
    f_sin[378]=35907;
    f_sin[379]=35991;
    f_sin[380]=36075;
    f_sin[381]=36159;
    f_sin[382]=36243;
    f_sin[383]=36326;
    f_sin[384]=36410;
    f_sin[385]=36493;
    f_sin[386]=36577;
    f_sin[387]=36660;
    f_sin[388]=36744;
    f_sin[389]=36827;
    f_sin[390]=36910;
    f_sin[391]=36993;
    f_sin[392]=37076;
    f_sin[393]=37159;
    f_sin[394]=37241;
    f_sin[395]=37324;
    f_sin[396]=37407;
    f_sin[397]=37489;
    f_sin[398]=37572;
    f_sin[399]=37654;
    f_sin[400]=37736;
    f_sin[401]=37818;
    f_sin[402]=37900;
    f_sin[403]=37982;
    f_sin[404]=38064;
    f_sin[405]=38146;
    f_sin[406]=38228;
    f_sin[407]=38309;
    f_sin[408]=38391;
    f_sin[409]=38472;
    f_sin[410]=38554;
    f_sin[411]=38635;
    f_sin[412]=38716;
    f_sin[413]=38797;
    f_sin[414]=38878;
    f_sin[415]=38959;
    f_sin[416]=39040;
    f_sin[417]=39120;
    f_sin[418]=39201;
    f_sin[419]=39282;
    f_sin[420]=39362;
    f_sin[421]=39442;
    f_sin[422]=39523;
    f_sin[423]=39603;
    f_sin[424]=39683;
    f_sin[425]=39763;
    f_sin[426]=39843;
    f_sin[427]=39922;
    f_sin[428]=40002;
    f_sin[429]=40082;
    f_sin[430]=40161;
    f_sin[431]=40241;
    f_sin[432]=40320;
    f_sin[433]=40399;
    f_sin[434]=40478;
    f_sin[435]=40557;
    f_sin[436]=40636;
    f_sin[437]=40715;
    f_sin[438]=40794;
    f_sin[439]=40872;
    f_sin[440]=40951;
    f_sin[441]=41029;
    f_sin[442]=41108;
    f_sin[443]=41186;
    f_sin[444]=41264;
    f_sin[445]=41342;
    f_sin[446]=41420;
    f_sin[447]=41498;
    f_sin[448]=41576;
    f_sin[449]=41653;
    f_sin[450]=41731;
    f_sin[451]=41808;
    f_sin[452]=41886;
    f_sin[453]=41963;
    f_sin[454]=42040;
    f_sin[455]=42117;
    f_sin[456]=42194;
    f_sin[457]=42271;
    f_sin[458]=42348;
    f_sin[459]=42424;
    f_sin[460]=42501;
    f_sin[461]=42578;
    f_sin[462]=42654;
    f_sin[463]=42730;
    f_sin[464]=42806;
    f_sin[465]=42882;
    f_sin[466]=42958;
    f_sin[467]=43034;
    f_sin[468]=43110;
    f_sin[469]=43186;
    f_sin[470]=43261;
    f_sin[471]=43337;
    f_sin[472]=43412;
    f_sin[473]=43487;
    f_sin[474]=43562;
    f_sin[475]=43638;
    f_sin[476]=43713;
    f_sin[477]=43787;
    f_sin[478]=43862;
    f_sin[479]=43937;
    f_sin[480]=44011;
    f_sin[481]=44086;
    f_sin[482]=44160;
    f_sin[483]=44234;
    f_sin[484]=44308;
    f_sin[485]=44382;
    f_sin[486]=44456;
    f_sin[487]=44530;
    f_sin[488]=44604;
    f_sin[489]=44677;
    f_sin[490]=44751;
    f_sin[491]=44824;
    f_sin[492]=44898;
    f_sin[493]=44971;
    f_sin[494]=45044;
    f_sin[495]=45117;
    f_sin[496]=45190;
    f_sin[497]=45262;
    f_sin[498]=45335;
    f_sin[499]=45408;
    f_sin[500]=45480;
    f_sin[501]=45552;
    f_sin[502]=45625;
    f_sin[503]=45697;
    f_sin[504]=45769;
    f_sin[505]=45841;
    f_sin[506]=45912;
    f_sin[507]=45984;
    f_sin[508]=46056;
    f_sin[509]=46127;
    f_sin[510]=46199;
    f_sin[511]=46270;
    f_sin[512]=46341;
    f_sin[513]=46412;
    f_sin[514]=46483;
    f_sin[515]=46554;
    f_sin[516]=46624;
    f_sin[517]=46695;
    f_sin[518]=46765;
    f_sin[519]=46836;
    f_sin[520]=46906;
    f_sin[521]=46976;
    f_sin[522]=47046;
    f_sin[523]=47116;
    f_sin[524]=47186;
    f_sin[525]=47256;
    f_sin[526]=47325;
    f_sin[527]=47395;
    f_sin[528]=47464;
    f_sin[529]=47534;
    f_sin[530]=47603;
    f_sin[531]=47672;
    f_sin[532]=47741;
    f_sin[533]=47809;
    f_sin[534]=47878;
    f_sin[535]=47947;
    f_sin[536]=48015;
    f_sin[537]=48084;
    f_sin[538]=48152;
    f_sin[539]=48220;
    f_sin[540]=48288;
    f_sin[541]=48356;
    f_sin[542]=48424;
    f_sin[543]=48491;
    f_sin[544]=48559;
    f_sin[545]=48626;
    f_sin[546]=48694;
    f_sin[547]=48761;
    f_sin[548]=48828;
    f_sin[549]=48895;
    f_sin[550]=48962;
    f_sin[551]=49029;
    f_sin[552]=49095;
    f_sin[553]=49162;
    f_sin[554]=49228;
    f_sin[555]=49295;
    f_sin[556]=49361;
    f_sin[557]=49427;
    f_sin[558]=49493;
    f_sin[559]=49559;
    f_sin[560]=49624;
    f_sin[561]=49690;
    f_sin[562]=49756;
    f_sin[563]=49821;
    f_sin[564]=49886;
    f_sin[565]=49951;
    f_sin[566]=50016;
    f_sin[567]=50081;
    f_sin[568]=50146;
    f_sin[569]=50211;
    f_sin[570]=50275;
    f_sin[571]=50340;
    f_sin[572]=50404;
    f_sin[573]=50468;
    f_sin[574]=50532;
    f_sin[575]=50596;
    f_sin[576]=50660;
    f_sin[577]=50724;
    f_sin[578]=50787;
    f_sin[579]=50851;
    f_sin[580]=50914;
    f_sin[581]=50977;
    f_sin[582]=51041;
    f_sin[583]=51104;
    f_sin[584]=51166;
    f_sin[585]=51229;
    f_sin[586]=51292;
    f_sin[587]=51354;
    f_sin[588]=51417;
    f_sin[589]=51479;
    f_sin[590]=51541;
    f_sin[591]=51603;
    f_sin[592]=51665;
    f_sin[593]=51727;
    f_sin[594]=51789;
    f_sin[595]=51850;
    f_sin[596]=51911;
    f_sin[597]=51973;
    f_sin[598]=52034;
    f_sin[599]=52095;
    f_sin[600]=52156;
    f_sin[601]=52217;
    f_sin[602]=52277;
    f_sin[603]=52338;
    f_sin[604]=52398;
    f_sin[605]=52459;
    f_sin[606]=52519;
    f_sin[607]=52579;
    f_sin[608]=52639;
    f_sin[609]=52699;
    f_sin[610]=52759;
    f_sin[611]=52818;
    f_sin[612]=52878;
    f_sin[613]=52937;
    f_sin[614]=52996;
    f_sin[615]=53055;
    f_sin[616]=53114;
    f_sin[617]=53173;
    f_sin[618]=53232;
    f_sin[619]=53290;
    f_sin[620]=53349;
    f_sin[621]=53407;
    f_sin[622]=53465;
    f_sin[623]=53523;
    f_sin[624]=53581;
    f_sin[625]=53639;
    f_sin[626]=53697;
    f_sin[627]=53754;
    f_sin[628]=53812;
    f_sin[629]=53869;
    f_sin[630]=53926;
    f_sin[631]=53983;
    f_sin[632]=54040;
    f_sin[633]=54097;
    f_sin[634]=54154;
    f_sin[635]=54210;
    f_sin[636]=54267;
    f_sin[637]=54323;
    f_sin[638]=54379;
    f_sin[639]=54435;
    f_sin[640]=54491;
    f_sin[641]=54547;
    f_sin[642]=54603;
    f_sin[643]=54658;
    f_sin[644]=54714;
    f_sin[645]=54769;
    f_sin[646]=54824;
    f_sin[647]=54879;
    f_sin[648]=54934;
    f_sin[649]=54989;
    f_sin[650]=55043;
    f_sin[651]=55098;
    f_sin[652]=55152;
    f_sin[653]=55206;
    f_sin[654]=55260;
    f_sin[655]=55314;
    f_sin[656]=55368;
    f_sin[657]=55422;
    f_sin[658]=55476;
    f_sin[659]=55529;
    f_sin[660]=55582;
    f_sin[661]=55636;
    f_sin[662]=55689;
    f_sin[663]=55742;
    f_sin[664]=55794;
    f_sin[665]=55847;
    f_sin[666]=55900;
    f_sin[667]=55952;
    f_sin[668]=56004;
    f_sin[669]=56056;
    f_sin[670]=56108;
    f_sin[671]=56160;
    f_sin[672]=56212;
    f_sin[673]=56264;
    f_sin[674]=56315;
    f_sin[675]=56367;
    f_sin[676]=56418;
    f_sin[677]=56469;
    f_sin[678]=56520;
    f_sin[679]=56571;
    f_sin[680]=56621;
    f_sin[681]=56672;
    f_sin[682]=56722;
    f_sin[683]=56773;
    f_sin[684]=56823;
    f_sin[685]=56873;
    f_sin[686]=56923;
    f_sin[687]=56972;
    f_sin[688]=57022;
    f_sin[689]=57072;
    f_sin[690]=57121;
    f_sin[691]=57170;
    f_sin[692]=57219;
    f_sin[693]=57268;
    f_sin[694]=57317;
    f_sin[695]=57366;
    f_sin[696]=57414;
    f_sin[697]=57463;
    f_sin[698]=57511;
    f_sin[699]=57559;
    f_sin[700]=57607;
    f_sin[701]=57655;
    f_sin[702]=57703;
    f_sin[703]=57750;
    f_sin[704]=57798;
    f_sin[705]=57845;
    f_sin[706]=57892;
    f_sin[707]=57939;
    f_sin[708]=57986;
    f_sin[709]=58033;
    f_sin[710]=58079;
    f_sin[711]=58126;
    f_sin[712]=58172;
    f_sin[713]=58219;
    f_sin[714]=58265;
    f_sin[715]=58311;
    f_sin[716]=58356;
    f_sin[717]=58402;
    f_sin[718]=58448;
    f_sin[719]=58493;
    f_sin[720]=58538;
    f_sin[721]=58583;
    f_sin[722]=58628;
    f_sin[723]=58673;
    f_sin[724]=58718;
    f_sin[725]=58763;
    f_sin[726]=58807;
    f_sin[727]=58851;
    f_sin[728]=58896;
    f_sin[729]=58940;
    f_sin[730]=58983;
    f_sin[731]=59027;
    f_sin[732]=59071;
    f_sin[733]=59114;
    f_sin[734]=59158;
    f_sin[735]=59201;
    f_sin[736]=59244;
    f_sin[737]=59287;
    f_sin[738]=59330;
    f_sin[739]=59372;
    f_sin[740]=59415;
    f_sin[741]=59457;
    f_sin[742]=59499;
    f_sin[743]=59541;
    f_sin[744]=59583;
    f_sin[745]=59625;
    f_sin[746]=59667;
    f_sin[747]=59708;
    f_sin[748]=59750;
    f_sin[749]=59791;
    f_sin[750]=59832;
    f_sin[751]=59873;
    f_sin[752]=59914;
    f_sin[753]=59954;
    f_sin[754]=59995;
    f_sin[755]=60035;
    f_sin[756]=60075;
    f_sin[757]=60116;
    f_sin[758]=60156;
    f_sin[759]=60195;
    f_sin[760]=60235;
    f_sin[761]=60275;
    f_sin[762]=60314;
    f_sin[763]=60353;
    f_sin[764]=60392;
    f_sin[765]=60431;
    f_sin[766]=60470;
    f_sin[767]=60509;
    f_sin[768]=60547;
    f_sin[769]=60586;
    f_sin[770]=60624;
    f_sin[771]=60662;
    f_sin[772]=60700;
    f_sin[773]=60738;
    f_sin[774]=60776;
    f_sin[775]=60813;
    f_sin[776]=60851;
    f_sin[777]=60888;
    f_sin[778]=60925;
    f_sin[779]=60962;
    f_sin[780]=60999;
    f_sin[781]=61035;
    f_sin[782]=61072;
    f_sin[783]=61108;
    f_sin[784]=61145;
    f_sin[785]=61181;
    f_sin[786]=61217;
    f_sin[787]=61253;
    f_sin[788]=61288;
    f_sin[789]=61324;
    f_sin[790]=61359;
    f_sin[791]=61394;
    f_sin[792]=61429;
    f_sin[793]=61464;
    f_sin[794]=61499;
    f_sin[795]=61534;
    f_sin[796]=61568;
    f_sin[797]=61603;
    f_sin[798]=61637;
    f_sin[799]=61671;
    f_sin[800]=61705;
    f_sin[801]=61739;
    f_sin[802]=61772;
    f_sin[803]=61806;
    f_sin[804]=61839;
    f_sin[805]=61873;
    f_sin[806]=61906;
    f_sin[807]=61939;
    f_sin[808]=61971;
    f_sin[809]=62004;
    f_sin[810]=62036;
    f_sin[811]=62069;
    f_sin[812]=62101;
    f_sin[813]=62133;
    f_sin[814]=62165;
    f_sin[815]=62197;
    f_sin[816]=62228;
    f_sin[817]=62260;
    f_sin[818]=62291;
    f_sin[819]=62322;
    f_sin[820]=62353;
    f_sin[821]=62384;
    f_sin[822]=62415;
    f_sin[823]=62445;
    f_sin[824]=62476;
    f_sin[825]=62506;
    f_sin[826]=62536;
    f_sin[827]=62566;
    f_sin[828]=62596;
    f_sin[829]=62626;
    f_sin[830]=62655;
    f_sin[831]=62685;
    f_sin[832]=62714;
    f_sin[833]=62743;
    f_sin[834]=62772;
    f_sin[835]=62801;
    f_sin[836]=62830;
    f_sin[837]=62858;
    f_sin[838]=62886;
    f_sin[839]=62915;
    f_sin[840]=62943;
    f_sin[841]=62971;
    f_sin[842]=62998;
    f_sin[843]=63026;
    f_sin[844]=63054;
    f_sin[845]=63081;
    f_sin[846]=63108;
    f_sin[847]=63135;
    f_sin[848]=63162;
    f_sin[849]=63189;
    f_sin[850]=63215;
    f_sin[851]=63242;
    f_sin[852]=63268;
    f_sin[853]=63294;
    f_sin[854]=63320;
    f_sin[855]=63346;
    f_sin[856]=63372;
    f_sin[857]=63397;
    f_sin[858]=63423;
    f_sin[859]=63448;
    f_sin[860]=63473;
    f_sin[861]=63498;
    f_sin[862]=63523;
    f_sin[863]=63547;
    f_sin[864]=63572;
    f_sin[865]=63596;
    f_sin[866]=63621;
    f_sin[867]=63645;
    f_sin[868]=63668;
    f_sin[869]=63692;
    f_sin[870]=63716;
    f_sin[871]=63739;
    f_sin[872]=63763;
    f_sin[873]=63786;
    f_sin[874]=63809;
    f_sin[875]=63832;
    f_sin[876]=63854;
    f_sin[877]=63877;
    f_sin[878]=63899;
    f_sin[879]=63922;
    f_sin[880]=63944;
    f_sin[881]=63966;
    f_sin[882]=63987;
    f_sin[883]=64009;
    f_sin[884]=64031;
    f_sin[885]=64052;
    f_sin[886]=64073;
    f_sin[887]=64094;
    f_sin[888]=64115;
    f_sin[889]=64136;
    f_sin[890]=64156;
    f_sin[891]=64177;
    f_sin[892]=64197;
    f_sin[893]=64217;
    f_sin[894]=64237;
    f_sin[895]=64257;
    f_sin[896]=64277;
    f_sin[897]=64296;
    f_sin[898]=64316;
    f_sin[899]=64335;
    f_sin[900]=64354;
    f_sin[901]=64373;
    f_sin[902]=64392;
    f_sin[903]=64410;
    f_sin[904]=64429;
    f_sin[905]=64447;
    f_sin[906]=64465;
    f_sin[907]=64483;
    f_sin[908]=64501;
    f_sin[909]=64519;
    f_sin[910]=64536;
    f_sin[911]=64554;
    f_sin[912]=64571;
    f_sin[913]=64588;
    f_sin[914]=64605;
    f_sin[915]=64622;
    f_sin[916]=64639;
    f_sin[917]=64655;
    f_sin[918]=64672;
    f_sin[919]=64688;
    f_sin[920]=64704;
    f_sin[921]=64720;
    f_sin[922]=64735;
    f_sin[923]=64751;
    f_sin[924]=64766;
    f_sin[925]=64782;
    f_sin[926]=64797;
    f_sin[927]=64812;
    f_sin[928]=64827;
    f_sin[929]=64841;
    f_sin[930]=64856;
    f_sin[931]=64870;
    f_sin[932]=64884;
    f_sin[933]=64899;
    f_sin[934]=64912;
    f_sin[935]=64926;
    f_sin[936]=64940;
    f_sin[937]=64953;
    f_sin[938]=64967;
    f_sin[939]=64980;
    f_sin[940]=64993;
    f_sin[941]=65006;
    f_sin[942]=65018;
    f_sin[943]=65031;
    f_sin[944]=65043;
    f_sin[945]=65055;
    f_sin[946]=65067;
    f_sin[947]=65079;
    f_sin[948]=65091;
    f_sin[949]=65103;
    f_sin[950]=65114;
    f_sin[951]=65126;
    f_sin[952]=65137;
    f_sin[953]=65148;
    f_sin[954]=65159;
    f_sin[955]=65169;
    f_sin[956]=65180;
    f_sin[957]=65190;
    f_sin[958]=65200;
    f_sin[959]=65210;
    f_sin[960]=65220;
    f_sin[961]=65230;
    f_sin[962]=65240;
    f_sin[963]=65249;
    f_sin[964]=65259;
    f_sin[965]=65268;
    f_sin[966]=65277;
    f_sin[967]=65286;
    f_sin[968]=65294;
    f_sin[969]=65303;
    f_sin[970]=65311;
    f_sin[971]=65320;
    f_sin[972]=65328;
    f_sin[973]=65336;
    f_sin[974]=65343;
    f_sin[975]=65351;
    f_sin[976]=65358;
    f_sin[977]=65366;
    f_sin[978]=65373;
    f_sin[979]=65380;
    f_sin[980]=65387;
    f_sin[981]=65393;
    f_sin[982]=65400;
    f_sin[983]=65406;
    f_sin[984]=65413;
    f_sin[985]=65419;
    f_sin[986]=65425;
    f_sin[987]=65430;
    f_sin[988]=65436;
    f_sin[989]=65442;
    f_sin[990]=65447;
    f_sin[991]=65452;
    f_sin[992]=65457;
    f_sin[993]=65462;
    f_sin[994]=65467;
    f_sin[995]=65471;
    f_sin[996]=65476;
    f_sin[997]=65480;
    f_sin[998]=65484;
    f_sin[999]=65488;
    f_sin[1000]=65492;
    f_sin[1001]=65495;
    f_sin[1002]=65499;
    f_sin[1003]=65502;
    f_sin[1004]=65505;
    f_sin[1005]=65508;
    f_sin[1006]=65511;
    f_sin[1007]=65514;
    f_sin[1008]=65516;
    f_sin[1009]=65519;
    f_sin[1010]=65521;
    f_sin[1011]=65523;
    f_sin[1012]=65525;
    f_sin[1013]=65527;
    f_sin[1014]=65528;
    f_sin[1015]=65530;
    f_sin[1016]=65531;
    f_sin[1017]=65532;
    f_sin[1018]=65533;
    f_sin[1019]=65534;
    f_sin[1020]=65535;
    f_sin[1021]=65535;
    f_sin[1022]=65536;
    f_sin[1023]=65536;

    zzUint32 i;

    for (i=0; i<1024; i++)
    {
        f_sin[1024+i]=f_sin[1023-i];
        f_sin[2048+i]=-f_sin[i];
        f_sin[3072+i]=-f_sin[1023-i];

    }


    for (i=0; i<4096; i++)
        f_cos[i]=f_sin[(i+1024)%4096];
    for (i=0; i<=1024; i++)
        if (f_cos[i]>5)
            f_tan[i]=FPDIV(f_sin[i],f_cos[i]);
        else
            f_tan[i]=0xFFFFFFF;

}
