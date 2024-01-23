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
extern void EmitParticle(signed long int x,signed long int y,unsigned short color);
extern void EmitStaticSplat(signed long int x,signed long int y,unsigned short color);
extern void EmitWaterSplat(signed long int x,signed long int y,unsigned short color);
extern void EmitSmokeSplat(signed long int x,signed long int y,unsigned short color);
extern void ProcParticles(void);
extern void ClearParticles(void);
extern void GroundEffect(signed long x,signed long y);
