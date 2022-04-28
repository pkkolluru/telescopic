/*********************************************************************************************
 * Copyright (c) <2020>, <Santosh Ansumali@JNCASR>                                           *
 *  All rights reserved.                                                                     *
 *   Redistribution and use in source and binary forms, with or without modification, are    *
 *   permitted provided that the following conditions are met:                               *
 *                                                                                           *
 *    1. Redistributions of source code must retain the above copyright notice, this list of *
 *       conditions and the following disclaimer.                                            *
 *    2. Redistributions in binary form must reproduce the above copyright notice, this list *
 *       of conditions and the following disclaimer in the documentation and/or other        *
 *       materials provided with the distribution.                                           *
 *    3. Neither the name of the <JNCASR> nor the names of its contributors may be used to   *
 *       endorse or promote products derived from this software without specific prior       *
 *       written permission.                                                                 *
 *                                                                                           *
 *       THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND     *
 *       ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED       *
 *       WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  *
 *       IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,    *
 *       INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,      *
 *       BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,       *
 *       DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF     *
 *       LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE     *
 *       OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED   *
 *       OF THE POSSIBILITY OF SUCH DAMAGE.                                                  *
 *       Contributors:         Praveen Kumar Kolluru and   Santosh Ansumali                  *
 *                                                                                           *
 *       Suggestions:          ansumali@jncasr.ac.in                                         *
 *       Bugs:                 ansumali@jncasr.ac.in                                         *
 *                                                                                           *
 *********************************************************************************************/

#ifndef _PROJORDER2_H_
#define _PROJORDER2_H_

#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>

#include"functions.hpp"

void secondOrderIntegrator(myReal *yOld, myReal *yFinal, funct odeFUN,
                           myReal &t);
void thirdOrderIntegrator(myReal *yOld, myReal *yFinal, funct odeFUN,
                           myReal &t);
void fourthOrderIntegrator(myReal *yOld, myReal *yFinal, funct odeFUN,
                           myReal &t);

template <void (*T)(myReal *,  myReal *, funct, myReal &)>
void primaryIntegrator(myReal *yOld, myReal *yNew, funct odeFUN,
                       int integratorSteps, myReal &t);
template <void (*T)(myReal *,  myReal *, funct, myReal &)>
void projectiveIntegrator(myReal *yOld, myReal *yNew, funct odeFUN,
                          myReal &t, myReal dt, int k);

template <void (*T)(myReal *,  myReal *, funct, myReal &)>
void BDF(myReal *yOld, myReal *yNew, funct odeFUN,
         myReal &t, myReal dt,  int m, int k);
#endif
