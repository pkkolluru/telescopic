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
#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
#include<chrono>

#include"src/parameters.hpp"
#include"src/functions.hpp"
#include"src/projectiveOrder2.hpp"

int main() {
  myReal initvalue[SIZE] = {0.0};
  myReal yExact[SIZE] = {0.0};
  myReal yOld[SIZE] = {0.0};
  myReal yNew[SIZE] = {0.0};
  myReal yPrimary[SIZE] = {0.0};
  myReal yProj[SIZE] = {0.0};

  myReal yn[SIZE] = {0.0};
  myReal yn1[SIZE] = {0.0};
  myReal yn2[SIZE] = {0.0};
  myReal yBDF[SIZE] = {0.0};

  int printFreq = 1;
  myReal t = 0.0;

  std::ofstream file;
  file.open("./results/telescopic.data");


  funct odeFunction;
  odeFunction.setParams();
 const myReal finalTime =  odeFunction.finalTime;

  odeFunction.initialConditions(initvalue);
  printToFile(0, t, initvalue, yExact, file);

//   std::cout << "Euler:              " << odeFunction.m  << "\n";
//   std::cout << "projSteps:          " << odeFunction.k  << "\n";
//   std::cout << "Integrator:         " << odeFunction.m1 << "\n";
//   std::cout << "Proj integrator:    " << odeFunction.k1 << "\n";
  std::cout << "dt:                 " << odeFunction.dt << "\n";

  for (int i = 0; i < odeFunction.numberOfProjectiveLevels; i++) {
    std::cout << "DTLevel[" << i << "]: " << odeFunction.DTLevel[i] << "\n";
 }

  //   std::cout << "proj_5 Jump:        " << odeFunction.DT4*odeFunction.k4 << "\n";
  //   std::cout << "lambdaDt:           " << odeFunction.lambdaDt << "\n \n \n";

  copyFirstArrayToSecond(initvalue, yOld);

  auto CpuStartTime = std::clock();
  auto WallStartTime = std::chrono::high_resolution_clock::now();


//   for (int step = 1; ; step++) {
//     primaryIntegrator<fourthOrderIntegrator>(yOld, yPrimary, odeFunction,
//                                             odeFunction.m3, t);
//     projectiveIntegrator<fourthOrderIntegrator>(yPrimary, yProj, odeFunction, t,
//                                                 odeFunction.DT3, odeFunction.k3);
// //     primaryIntegrator<thirdOrderIntegrator>(yOld, yPrimary, odeFunction,
// //                                             odeFunction.m2, t);
// //     projectiveIntegrator<thirdOrderIntegrator>(yPrimary, yProj, odeFunction, t,
// //                                                 odeFunction.DT2, odeFunction.k2);
// //     primaryIntegrator<secondOrderIntegrator>(yOld, yPrimary, odeFunction,
// //                                             odeFunction.m1, t);
// //     projectiveIntegrator<secondOrderIntegrator>(yPrimary, yProj, odeFunction, t,
// //                                                 odeFunction.DT, odeFunction.k1);
// 
// //      BDF<eulerIntegrator>(yOld, yNew, odeFunction, t, odeFunction.dt, odeFunction.k);
// 
// //      BDF<secondOrderIntegrator>(yOld, yNew, odeFunction, t, odeFunction.dt, odeFunction.k);
// 
// //      BDF<thirdOrderIntegrator>(yOld, yNew, odeFunction, t, odeFunction.DT2, odeFunction.m2, odeFunction.k2);
// 
// //      BDF<fourthOrderIntegrator>(yOld, yNew, odeFunction, t, odeFunction.DT3, odeFunction.m3, odeFunction.k3);
//     
//      copyFirstArrayToSecond(yProj, yOld);
// 
// 
//     if (step%printFreq == 0) {
// //       exactSolution(yOld, yExact, odeFunction, t);
//       printToFile(step, t, yProj, yExact, file);
//     }
// 
//     if (t > finalTime)
//       break;
//   }
// 
//   for (int elem = 0; elem < SIZE; elem++)
//     std::cout << yProj[elem] <<  std::endl;

  auto CpuEndTime = std::clock();
  auto WallEndTime = std::chrono::high_resolution_clock::now();
  std::cout << " \n \nExecution Time: \n";
  std::cout << "CPU Clock Time "
            << 1000*(CpuEndTime-CpuStartTime)/CLOCKS_PER_SEC << " ms\n";
  std::cout << "Wall Clock Time " << std::chrono::duration_cast
  <std::chrono::milliseconds>(WallEndTime - WallStartTime).count() <<" ms\n";

  file.close();

  return 0;
}

