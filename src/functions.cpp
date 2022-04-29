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

#include"functions.hpp"

void eulerIntegrator(myReal *yOld, myReal *yNew, funct odeFUN, myReal &t) {
  myReal f[SIZE] = {0.0};
  odeFUN(yOld, t, f);
  for (int elem = 0; elem < SIZE; elem++) {
    yNew[elem] = yOld[elem] + odeFUN.dt*f[elem];
  }
//  t = t + odeFUN.dt;
}

void forwardEuler(myReal *yOld, myReal *yNew, funct odeFUN, int m, myReal dt,
                  myReal t) {
  myReal f[SIZE] = {0.0};
  myReal yOldCopy[SIZE] = {0.0};

  copyFirstArrayToSecond(yOld, yOldCopy);
  for (int i = 1; i <= m; i++) {
    odeFUN(yOldCopy, t, f);
    for (int elem = 0; elem < SIZE; elem++) {
      yNew[elem] = yOldCopy[elem] + dt*f[elem];
    }
    copyFirstArrayToSecond(yNew, yOldCopy);
  }
}

void projectiveEuler(myReal *yOld, myReal *yProj, funct odeFUN, int k,
                     myReal dt, myReal t) {
  myReal yTemp[SIZE] = {0.0};
  myReal gradient[SIZE] = {0.0};

  forwardEuler(yOld, yTemp, odeFUN, 1, dt, t);
  for (int elem = 0; elem < SIZE; elem++) {
    gradient[elem] = yTemp[elem] - yOld[elem];
  }
  for (int elem = 0; elem < SIZE; elem++) {
    yProj[elem] =  yOld[elem] + k*gradient[elem];
  }
}

void implicitScheme(myReal *yN, myReal *yNPlus1, myReal *yNew,
                    funct odeFUN, myReal dt, myReal t) {
  myReal f[SIZE] = {0.0};
  myReal yMidPoint[SIZE] = {0.0};
  for (int elem = 0; elem < SIZE; elem++) {
    yMidPoint[elem] = 0.5*(yN[elem] + yNPlus1[elem]);
  }
  myReal tMidPoint = t + dt/2.0;
  odeFUN(yMidPoint, tMidPoint, f);
  for (int elem = 0; elem < SIZE; elem++) {
    yNew[elem] = yN[elem] + dt*f[elem];
  }
}

void projectiveEulerImplicit(myReal *yOld, myReal *yProj, funct odeFUN,
                             int k, myReal dt, myReal t) {
  myReal yTemp[SIZE] = {0.0};
  myReal yImplicit[SIZE] = {0.0};
  myReal gradient[SIZE] = {0.0};

  forwardEuler(yOld, yTemp, odeFUN, 1, dt, t);
  implicitScheme(yOld, yTemp, yImplicit, odeFUN, dt, t);
  for (int elem = 0; elem < SIZE; elem++) {
    gradient[elem] = yImplicit[elem] - yOld[elem];
  }
  for (int elem = 0; elem < SIZE; elem++) {
    yProj[elem] =  yOld[elem] + k*gradient[elem];
  }
}

void copyFirstArrayToSecond(myReal *arr1, myReal *arr2) {
  for (int elem = 0; elem < SIZE; elem++)
    arr2[elem] = arr1[elem];
}

void printToFile(int step, myReal timeLocal, myReal *y,
                 std::ofstream &file) {
  file << step << std::setw(24) << timeLocal << std::setw(24);
  for (int elem = 0; elem < SIZE; elem++)
    file << y[elem] <<  std::setw(24);
  file << std::endl;
}
