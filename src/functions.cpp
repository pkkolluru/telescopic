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
  t = t + odeFUN.dt;
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

void projectiveEulerSecondDerivatives(myReal *yOld, myReal *yProj, funct odeFUN,
                                      int k, myReal dt, myReal t) {
  myReal yTemp1[SIZE] = {0.0};
  myReal yTemp2[SIZE] = {0.0};
  myReal gradient1[SIZE] = {0.0};
  myReal gradient2[SIZE] = {0.0};
  myReal yImplicit1[SIZE] = {0.0};
  myReal yImplicit2[SIZE] = {0.0};
  myReal gradientOfGradient[SIZE] = {0.0};

  forwardEuler(yOld, yTemp1, odeFUN, 1, dt, t);
  implicitScheme(yOld, yTemp1, yImplicit1, odeFUN, dt, t);
  for (int elem = 0; elem < SIZE; elem++) {
    gradient1[elem] = yImplicit1[elem] - yOld[elem];
  }

  forwardEuler(yImplicit1, yTemp2, odeFUN, 1, dt, t+dt);
  implicitScheme(yImplicit1, yTemp2, yImplicit2, odeFUN, dt,  t+dt);
  for (int elem = 0; elem < SIZE; elem++) {
    gradient2[elem] = yImplicit2[elem] - yImplicit1[elem];
  }

  for (int elem = 0; elem < SIZE; elem++) {
    gradientOfGradient[elem] = gradient2[elem] - gradient1[elem];
  }

  for (int elem = 0; elem < SIZE; elem++) {
    yProj[elem] =  yOld[elem] + k*gradient1[elem]
    + 0.5*k*k*dt*gradientOfGradient[elem];
  }
}

myReal getTheDominantEigenValue(myReal *ymn, funct odeFUN, myReal dt, myReal t){
  myReal ymn1[SIZE] = {0.0};
  myReal ymn2[SIZE] = {0.0};
  myReal gradient[SIZE] = {0.0};
  myReal gradient2[SIZE] = {0.0};
  myReal secondDer[SIZE] = {0.0};
  myReal eps = 1e-12;

  forwardEuler(ymn, ymn1, odeFUN, 1, dt, t+dt);
  forwardEuler(ymn1, ymn2, odeFUN, 1, dt, t+2*dt);

  for (int elem = 0; elem < SIZE; elem++) {
    gradient[elem] = ymn1[elem] - ymn[elem];
    gradient2[elem] = ymn2[elem] - ymn1[elem];
    secondDer[elem] = gradient2[elem] - gradient[elem];
  }

  myReal val1 = eps;
  for (int elem = 0; elem < SIZE; elem++) {
    val1 += secondDer[elem]*gradient[elem];
  }

  myReal val2 = eps;
  for (int elem = 0; elem < SIZE; elem++) {
    val2 +=  gradient[elem]*gradient[elem];
  }

  if (std::fabs(val1 - eps) < eps)
    val1 = 0.0;

  return (val1/val2)/dt;
}

void copyFirstArrayToSecond(myReal *arr1, myReal *arr2) {
  for (int elem = 0; elem < SIZE; elem++)
    arr2[elem] = arr1[elem];
}

void printToFile(int step, myReal timeLocal, myReal *y, myReal *yExact,
                 std::ofstream &file) {
  file << step << std::setw(24) << timeLocal << std::setw(24);
  for (int elem = 0; elem < SIZE; elem++)
    file << y[elem] <<  std::setw(24);
  //   for(int elem = 0; elem < SIZE; elem++)
  //     file << yExact[elem] <<  std::setw(24);
  file << std::endl;
}
