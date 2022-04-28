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
#include"projectiveOrder2.hpp"


void fourthOrderIntegrator(myReal *yOld, myReal *yFinal, funct odeFUN,
                           myReal &t) {
  myReal yEuler[SIZE];
  myReal yOldCopy[SIZE] = {0.0};
  copyFirstArrayToSecond(yOld, yOldCopy);

  for (int i = 1; i <= odeFUN.m3 ; i++) {
    thirdOrderIntegrator(yOldCopy, yEuler, odeFUN, t);
    copyFirstArrayToSecond(yEuler, yOldCopy);
  }

  myReal yn[SIZE];
  myReal yn1[SIZE];
  myReal yn2[SIZE];
  myReal yBDF[SIZE];

  copyFirstArrayToSecond(yEuler, yn);
  projectiveIntegrator<thirdOrderIntegrator>(yEuler, yFinal, odeFUN, t,
                                              odeFUN.DT2, odeFUN.k2/2);
  copyFirstArrayToSecond(yFinal, yn1);
  projectiveIntegrator<thirdOrderIntegrator>(yFinal, yn2, odeFUN, t,
                                              odeFUN.DT2, odeFUN.k2/2);

//   copyFirstArrayToSecond(yn2, yBDF);
//   for (int count = 0; count < 5; count++)
//     backwardDifferenceOrder2(yn, yn1, yBDF,
//                              yBDF, odeFUN, odeFUN.k2*odeFUN.DT2/2.0, t);
}


void thirdOrderIntegrator(myReal *yOld, myReal *yFinal, funct odeFUN,
                           myReal &t) {
  myReal yEuler[SIZE];
  myReal yOldCopy[SIZE] = {0.0};
  copyFirstArrayToSecond(yOld, yOldCopy);

  for (int i = 1; i <= odeFUN.m2 ; i++) {
    secondOrderIntegrator(yOldCopy, yEuler, odeFUN, t);
    copyFirstArrayToSecond(yEuler, yOldCopy);
  }

  myReal yn[SIZE];
  myReal yn1[SIZE];
  myReal yn2[SIZE];
  myReal yBDF[SIZE];

  copyFirstArrayToSecond(yEuler, yn);
  projectiveIntegrator<secondOrderIntegrator>(yEuler, yFinal, odeFUN, t,
                                              odeFUN.DT, odeFUN.k1/2);

  copyFirstArrayToSecond(yFinal, yn1);
  projectiveIntegrator<secondOrderIntegrator>(yFinal, yn2, odeFUN, t,
                                              odeFUN.DT, odeFUN.k1/2);

//   copyFirstArrayToSecond(yn2, yBDF);
//   for (int count = 0; count < 5; count++)
//     backwardDifferenceOrder2(yn, yn1, yBDF,
//                              yBDF, odeFUN, odeFUN.k1*odeFUN.DT/2.0, t);
}


void secondOrderIntegrator(myReal *yOld, myReal *yFinal, funct odeFUN,
                           myReal &t) {
  myReal yEuler[SIZE];
  myReal yOldCopy[SIZE] = {0.0};
  copyFirstArrayToSecond(yOld, yOldCopy);

  myReal yn[SIZE];
  myReal yn1[SIZE];
  myReal yn2[SIZE];
  myReal yBDF[SIZE];

  for (int i = 1; i <= odeFUN.m1; i++) {
    eulerIntegrator(yOldCopy, yEuler, odeFUN, t);
    copyFirstArrayToSecond(yEuler, yOldCopy);
  }

  copyFirstArrayToSecond(yEuler, yn);
  projectiveIntegrator<eulerIntegrator>(yEuler, yFinal, odeFUN, t,
                                        odeFUN.dt, odeFUN.k/2);

  copyFirstArrayToSecond(yFinal, yn1);
  projectiveIntegrator<eulerIntegrator>(yFinal, yn2, odeFUN, t,
                                        odeFUN.dt, odeFUN.k/2);

//   copyFirstArrayToSecond(yn2, yBDF);
//   for (int count = 0; count < 5; count++)
//     backwardDifferenceOrder2(yn, yn1, yBDF,
//                              yBDF, odeFUN, odeFUN.k*odeFUN.dt/2.0, t);
}

template <void (*T)(myReal *,  myReal *, funct, myReal &)>
void primaryIntegrator(myReal *yOld, myReal *yNew, funct odeFUN,
                       int integratorSteps, myReal &t) {
  myReal yOldCopy[SIZE] = {0.0};
  copyFirstArrayToSecond(yOld, yOldCopy);
  for (int i = 1; i <= integratorSteps; i++) {
    T(yOldCopy, yNew, odeFUN, t);
    copyFirstArrayToSecond(yNew, yOldCopy);
  }
}


template <void (*T)(myReal *,  myReal *, funct, myReal &)>
void projectiveIntegrator(myReal *yOld, myReal *yNew, funct odeFUN,
                          myReal &t, myReal dt, int k) {
  myReal yTemp1[SIZE] = {0.0}; myReal yTemp2[SIZE] = {0.0};
  myReal gradient1[SIZE] = {0.0}; myReal gradient2[SIZE] = {0.0};
  myReal yImplicit1[SIZE] = {0.0}; myReal yImplicit2[SIZE] = {0.0};
  myReal yOldCopy[SIZE] = {0.0};
  myReal gradientOfGradient[SIZE] = {0.0};

  myReal timeTemp1 = t;
  myReal timeTemp2 = t;

  copyFirstArrayToSecond(yOld, yOldCopy);

  T(yOldCopy, yTemp1, odeFUN, timeTemp1);
  implicitScheme(yOldCopy, yTemp1, yImplicit1, odeFUN, dt, timeTemp2);
  for (int elem = 0; elem < SIZE; elem++) {
    gradient1[elem] = yImplicit1[elem] - yOld[elem];
  }

  timeTemp2 = timeTemp1;

  T(yImplicit1, yTemp2, odeFUN, timeTemp1);
  implicitScheme(yImplicit1, yTemp2, yImplicit2, odeFUN, dt, timeTemp2);
  for (int elem = 0; elem < SIZE; elem++) {
    gradient2[elem] = yImplicit2[elem] - yImplicit1[elem];
  }

  for (int elem = 0; elem < SIZE; elem++) {
    gradientOfGradient[elem] = gradient2[elem] - gradient1[elem];
  }

  for (int elem = 0; elem < SIZE; elem++) {
    yNew[elem] =  yOld[elem] + k*gradient1[elem]
                    + 0.5*k*k*dt*gradientOfGradient[elem];
  }
  t = t + k*dt;
}


// template <void (*T)(myReal *,  myReal *, funct, myReal &)>
// void BDF(myReal *yOld, myReal *yNew, funct odeFUN,
//          myReal &t, myReal dt, int m, int k)  {
// 
//   myReal yn[SIZE] = {0.0};
//   myReal yn1[SIZE] = {0.0};
//   myReal yn2[SIZE] = {0.0};
//   myReal yBDF[SIZE] = {0.0};
//   myReal yPrimary[SIZE] = {0.0};
//   myReal yProj[SIZE] = {0.0};
// 
//     copyFirstArrayToSecond(yOld, yn);
// 
//     // dt/2
//     primaryIntegrator<T>(yOld, yPrimary, odeFUN,
//                                             m, t);
//     projectiveIntegrator<T>(yPrimary, yProj, odeFUN, t,
//                                                 dt, k/2.0);
// 
//     copyFirstArrayToSecond(yProj, yn1);
//     copyFirstArrayToSecond(yProj, yOld);
// 
//     // dt
//     primaryIntegrator<T>(yOld, yPrimary, odeFUN,
//                                             m, t);
//     projectiveIntegrator<T>(yPrimary, yProj, odeFUN, t,
//                                                 dt, k/2.0);
//     copyFirstArrayToSecond(yProj, yn2);
//     copyFirstArrayToSecond(yProj, yBDF);
// 
//     for (int count = 0; count < 5; count++)
//       backwardDifferenceOrder2(yn, yn1, yBDF,
//                               yBDF, odeFUN, k*dt/2.0, t);
// 
// //     copyFirstArrayToSecond(yBDF, yOld);
//     copyFirstArrayToSecond(yBDF, yNew);
// }




// Explicit template definitions
template void primaryIntegrator<&eulerIntegrator>(myReal*, myReal*, funct, int,
                                                  myReal&);
template void primaryIntegrator<&secondOrderIntegrator>(myReal*, myReal*,
                                                        funct, int, myReal&);
template void primaryIntegrator<&thirdOrderIntegrator>(myReal*, myReal*,
                                                        funct, int, myReal&);
template void primaryIntegrator<&fourthOrderIntegrator>(myReal*, myReal*,
                                                        funct, int, myReal&);

template void projectiveIntegrator<&eulerIntegrator>(myReal *yOld, myReal *yNew,
                funct odeFUN, myReal &t, myReal dt, int k);
template void projectiveIntegrator<&secondOrderIntegrator>(myReal *yOld,
                myReal *yNew, funct odeFUN, myReal &t, myReal dt, int k);
template void projectiveIntegrator<&thirdOrderIntegrator>(myReal *yOld,
                myReal *yNew, funct odeFUN, myReal &t, myReal dt, int k);
template void projectiveIntegrator<&fourthOrderIntegrator>(myReal *yOld,
                myReal *yNew, funct odeFUN, myReal &t, myReal dt, int k);



// template void BDF<&eulerIntegrator> (myReal *yOld, myReal *yNew, funct odeFUN,
//          myReal &t, myReal dt, int m, int k);
// 
// template void BDF<&secondOrderIntegrator> (myReal *yOld, myReal *yNew, funct odeFUN,
//          myReal &t, myReal dt, int m, int k);
// 
// template void BDF<&thirdOrderIntegrator> (myReal *yOld, myReal *yNew, funct odeFUN,
//          myReal &t, myReal dt, int m, int k);
// 
// template void BDF<&fourthOrderIntegrator> (myReal *yOld, myReal *yNew, funct odeFUN,
//          myReal &t, myReal dt,  int m, int k);
