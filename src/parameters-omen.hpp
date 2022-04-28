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
#ifndef _PARAMETERS_H_
#define _PARAMETERS_H_

#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>

typedef double myReal;

#define SIZE 23

enum cmp {CH4,    O2,   CH3,    HO2, CH3O,
            O,  CH2O,    OH,  CH3O2,  HCO,
           CO,  C2H6,  H2O2,      M,  CH2,
            H, CH3OH, CH2OH, CH3O2H,   H2,
          CO2,   H2O,  CHO};

struct funct{
  myReal finalTime = 0.1;
  myReal dt  = 1.e-13;

  int m = 50;
  int k = 200;

  int m1 = 50;
  int k1 = 200;

  int m2 = 50;
  int k2 = 200;

  int m3 = 50;
  int k3 = 200;

  myReal DT = (m+k)*dt;
  myReal DT2 = (m1+k1)*DT;
  myReal DT3 = (m2+k2)*DT2;
  myReal DT4 = (m3+k3)*DT3;

  void operator()(myReal *y, myReal t, myReal *f) const {
    myReal A[83];
    myReal E[83];
    myReal n[83];
    myReal k[83];

    myReal Temp = 450.0+273.0; // K
    myReal R = 1.98720425864083;

    A[0]  = 3.97e13;    E[0]  = 56800.0;   n[0] =  0.0;
    A[1]  = 7.52e12;    E[1]  = 28200.0;   n[1] =  0.0;
    A[2]  = 1.85e12;    E[2]  = 20260.0;   n[2] =  0.0;
    A[3]  = 8.1e11 ;    E[3]  = 0.0;       n[3] =  0.0;
    A[4]  = 4.10e12;    E[4]  = 8840.0;    n[4] =  0.0;
    A[5]  = 1.20e14;    E[5]  = 0.0;       n[5] =  0.0;
    A[6]  = 3.60e13;    E[6]  = 0.0;       n[6] =  0.0;
    A[7]  = 1.2e10 ;    E[7]  = -600.0;    n[7] =  0.0;
    A[8]  = 1.00e16;    E[8]  = 90500.0;   n[8] =  0.0;
    A[9]  = 2.40e11;    E[9]  = 10400.0;   n[9] =  0.0;
    A[10] = 4.45e11;    E[10] = 1000.0;    n[10] = 0.0;
    A[11] = 4.45e11;    E[11] = 1000.0;    n[11] = 0.0;
    A[12] = 2.40e12;    E[12] = 9930.0;    n[12] = 0.0;
    A[13] = 1.80e11;    E[13] = 18500.0;   n[13] = 0.0;
    A[14] = 1.81e12;    E[14] = 13700.0;   n[14] = 0.0;
    A[15] = 3.01e11;    E[15] = 0.0;       n[15] = 0.0;
    A[16] = 2.48e3 ;    E[16] = 40000.0;   n[16] = 2.98;
    A[17] = 3.01e13;    E[17] = 26000.0;   n[17] = 0.0;
    A[18] = 1.57e11;    E[18] = 8840.0;    n[18] = 0.0;
    A[19] = 1.00e11;    E[19] = 2980.0;    n[19] = 0.0;
    A[20] = 3.00e11;    E[20] = 4060.0;    n[20] = 0.0;
    A[21] = 3.01e9 ;    E[21] = 2580.0;    n[21] = 0.0;
    A[22] = 6.02e13;    E[22] = 0.0;       n[22] = 0.0;
    A[23] = 6.80e13;    E[23] = 26320.0;   n[23] = 0.0;
    A[24] = 5.42e13;    E[24] = 13500.0;   n[24] = 0.0;
    A[25] = 4.70e10;    E[25] = 2280.0;    n[25] = 0.0;
    A[26] = 9.03e12;    E[26] = 24630.0;   n[26] = 0.0;
    A[27] = 2.00e13;    E[27] = 0.0;       n[27] = 0.0;
    A[28] = 3.60e12;    E[28] = 0.0;       n[28] = 0.0;
    A[29] = 2.20e11;    E[29] = -1550.0;   n[29] = 0.0;
    A[30] = 3.01e12;    E[30] = 13070.0;   n[30] = 0.0;
    A[31] = 9.60e10;    E[31] = 12570.0;   n[31] = 0.0;
    A[32] = 1.14e12;    E[32] = 0.0;       n[32] = 0.0;
    A[33] = 7.30e11;    E[33] = 18470.0;   n[33] = 0.0;
    A[34] = 1.50e14;    E[34] = 23700.0;   n[34] = 0.0;
    A[35] = 1.77e14;    E[35] = 13770.0;   n[35] = 0.0;
    A[36] = 2.00e13;    E[36] = 0.0;       n[36] = 0.0;
    A[37] = 8.60e12;    E[37] = 3460.0;    n[37] = 0.0;
    A[38] = 1.10e14;    E[38] = 15500.0;   n[38] = 0.0;
    A[39] = 1.95e16;    E[39] = 0.0;       n[39] = 0.0;
    A[40] = 2.99e11;    E[40] = 14140.0;   n[40] = 0.0;
    A[41] = 1.69e12;    E[41] = 3760.0;    n[41] = 0.0;
    A[42] = 4.28e13;    E[42] = 1410.0;    n[42] = 0.0;
    A[43] = 1.20e11;    E[43] = 0.0;       n[43] = 0.0;
    A[44] = 1.00e13;    E[44] = 0.0;       n[44] = 0.0;
    A[45] = 6.00e13;    E[45] = 0.0;       n[45] = 0.0;
    A[46] = 5.70e13;    E[46] = 8200.0;    n[46] = 0.0;
    A[47] = 1.81e13;    E[47] = 0.0;       n[47] = 0.0;
    A[48] = 6.02e12;    E[48] = 0.0;       n[48] = 0.0;
    A[49] = 1.00e12;    E[49] = 0.0;       n[49] = 0.0;
    A[50] = 3.30e13;    E[50] = 0.0;       n[50] = 0.0;
    A[51] = 8.50e10;    E[51] = 0.0;       n[51] = 0.0;
    A[52] = 9.99e12;    E[52] = 1700.0;    n[52] = 0.0;
    A[53] = 1.86e12;    E[53] = 720.0;     n[53] = 0.0;
    A[54] = 1.20e12;    E[54] = 0.0;       n[54] = 0.0;
    A[55] = 4.60e12;    E[55] = 4170.0;    n[55] = 0.0;
    A[56] = 1.10e14;    E[56] = 0.0;       n[56] = 0.0;
    A[57] = 2.83e14;    E[57] = 12930.0;   n[57] = 0.0;
    A[58] = 8.40e13;    E[58] = 0.0;       n[58] = 0.0;
    A[59] = 6.02e12;    E[59] = 0.0;       n[59] = 0.0;
    A[60] = 1.80e13;    E[60] = 3080.0;    n[60] = 0.0;
    A[61] = 5.00e13;    E[61] = 0.0;       n[61] = 0.0;
    A[62] = 9.99e12;    E[62] = 4690.0;    n[62] = 0.0;
    A[63] = 9.81e12;    E[63] = 4510.0;    n[63] = 0.0;
    A[64] = 3.00e13;    E[64] = 0.0;       n[64] = 0.0;
    A[65] = 3.00e13;    E[65] = 0.0;       n[65] = 0.0;
    A[66] = 4.30e13;    E[66] = 10430.0;   n[66] = 0.0;
    A[67] = 6.00e14;    E[67] = 42280.0;   n[67] = 0.0;
    A[68] = 3.00e14;    E[68] = 48500.0;   n[68] = 0.0;
    A[69] = 9.31e15;    E[69] = 42110.0;   n[69] = 0.0;
    A[70] = 5.80e12;    E[70] = 0.0;       n[70] = 0.0;
    A[71] = 8.00e15;    E[71] = 53500.0;   n[71] = 0.0;
    A[72] = 1.26e16;    E[72] = 77860.0;   n[72] = 0.0;
    A[73] = 5.65e15;    E[73] = 69550.0;   n[73] = 0.0;
    A[74] = 1.98e12;    E[74] = 11660.0;   n[74] = 0.0;
    A[75] = 3.99e13;    E[75] = 15520.0;   n[75] = 0.0;
    A[76] = 3.10e12;    E[76] = 0.0;       n[76] = 0.0;
    A[77] = 7.94e-1;    E[77] = 0.0;       n[77] = 0.0;
    A[78] = 5.01e-1;    E[78] = 20000.0;   n[78] = 0.0;
    A[79] = 2.51e-2;    E[79] = 0.0;       n[79] = 0.0;
    A[80] = 5.01e1 ;    E[80] = 0.0;       n[80] = 0.0;
    A[81] = 1.00e10;    E[81] = 40000.0;   n[81] = 0.0;
    A[82] = 7.94e4 ;    E[82] = 0.0;       n[82] = 0.0;

    for (int index = 0; index < 83; index++) {
      k[index] = A[index] * std::pow(Temp, n[index]) * std::exp(-E[index]/(R*Temp));
    }

    f[cmp::CH4]  = - k[0]*y[cmp::CH4]*y[cmp::O2]
                   + k[4]*y[cmp::CH3]*y[cmp::CH2O]
                   + k[5]*y[cmp::CH3]*y[cmp::HCO]
                   + k[7]*y[cmp::CH3]*y[cmp::H2O2]
                   + k[9]*y[cmp::CH3]*y[cmp::CH3OH]
                   - k[13]*y[cmp::CH4]*y[cmp::CH3O2]
                   - k[17]*y[cmp::CH4]*y[cmp::CH3O]
                   - k[26]*y[cmp::CH4]*y[cmp::HO2]
                   + k[28]*y[cmp::CH3]*y[cmp::HO2]
                   - k[35]*y[cmp::CH4]*y[cmp::H]
                   - k[46]*y[cmp::CH4]*y[cmp::OH]
                   - k[57]*y[cmp::CH4]*y[cmp::O];

    f[cmp::O2] = - k[0]*y[cmp::CH4]*y[cmp::O2]
                 - k[1]*y[cmp::O2]*y[cmp::CH3]
                 - k[2]*y[cmp::O2]*y[cmp::CH3]
                 - k[3]*y[cmp::O2]*y[cmp::CH3]
                 + k[10]*y[cmp::CH3O2]*y[cmp::CH3O2]
                 + k[11]*y[cmp::CH3O2]*y[cmp::CH3O2]
                 - k[25]*y[cmp::O2]*y[cmp::CH3O]
                 + k[28]*y[cmp::CH3]*y[cmp::HO2]
                 + k[29]*y[cmp::HO2]*y[cmp::CH3O2]
                 + k[32]*y[cmp::HO2]*y[cmp::HO2]
                 - k[38]*y[cmp::O2]*y[cmp::H]
                 - k[39]*y[cmp::O2]*y[cmp::M]*y[cmp::H]
                 + k[42]*y[cmp::HO2]*y[cmp::H]
                 + k[50]*y[cmp::HO2]*y[cmp::OH]
                 - k[70]*y[cmp::O2]*y[cmp::CH2OH]
                 - k[71]*y[cmp::O2]*y[cmp::CH2O]
                 - k[76]*y[cmp::O2]*y[cmp::HCO]
                 + k[77]*y[cmp::CH3O2]
                 + k[78]*y[cmp::HO2]
                 + k[79]*y[cmp::CH3O]
                 + k[81]*y[cmp::CH3O2H];

    f[cmp::CH3] = + k[0]*y[cmp::CH4]*y[cmp::O2]
                  - k[1]*y[cmp::O2]*y[cmp::CH3]
                  - k[2]*y[cmp::O2]*y[cmp::CH3]
                  - k[3]*y[cmp::O2]*y[cmp::CH3]
                  - k[4]*y[cmp::CH3]*y[cmp::CH2O]
                  - k[5]*y[cmp::CH3]*y[cmp::HCO]
                  - 2.0*k[6]*y[cmp::CH3]*y[cmp::CH3]
                  - k[7]*y[cmp::CH3]*y[cmp::H2O2]
                  - k[8]*y[cmp::CH3]*y[cmp::M]
                  - k[9]*y[cmp::CH3]*y[cmp::CH3OH]
                  + k[13]*y[cmp::CH4]*y[cmp::CH3O2]
                  + k[17]*y[cmp::CH4]*y[cmp::CH3O]
                  + k[26]*y[cmp::CH4]*y[cmp::HO2]
                  - k[27]*y[cmp::CH3]*y[cmp::HO2]
                  - k[28]*y[cmp::CH3]*y[cmp::HO2]
                  + k[35]*y[cmp::CH4]*y[cmp::H]
                  + k[44]*y[cmp::H]*y[cmp::CH2OH]
                  + k[46]*y[cmp::CH4]*y[cmp::OH]
                  - k[54]*y[cmp::CH3]*y[cmp::OH]
                  + k[57]*y[cmp::CH4]*y[cmp::O]
                  - k[58]*y[cmp::CH3]*y[cmp::O]
                  - k[80]*y[cmp::CH3];

    f[cmp::HO2] = + k[0]*y[cmp::CH4]*y[cmp::O2]
                  + k[7]*y[cmp::CH3]*y[cmp::H2O2]
                  + k[12]*y[cmp::CH3O2]*y[cmp::H2O2]
                  + k[21]*y[cmp::CH3O]*y[cmp::H2O2]
                  + k[25]*y[cmp::O2]*y[cmp::CH3O]
                  - k[26]*y[cmp::CH4]*y[cmp::HO2]
                  - k[27]*y[cmp::CH3]*y[cmp::HO2]
                  - k[28]*y[cmp::CH3]*y[cmp::HO2]
                  - k[29]*y[cmp::HO2]*y[cmp::CH3O2]
                  - k[30]*y[cmp::HO2]*y[cmp::CH2O]
                  - k[31]*y[cmp::HO2]*y[cmp::CH3OH]
                  - 2.0*k[32]*y[cmp::HO2]*y[cmp::HO2]
                  - k[33]*y[cmp::HO2]*y[cmp::H2]
                  - k[34]*y[cmp::HO2]*y[cmp::CO]
                  + k[39]*y[cmp::O2]*y[cmp::M]*y[cmp::H]
                  + k[41]*y[cmp::H2O2]*y[cmp::H]
                  - k[42]*y[cmp::HO2]*y[cmp::H]
                  + k[49]*y[cmp::OH]*y[cmp::H2O2]
                  - k[50]*y[cmp::HO2]*y[cmp::OH]
                  + k[70]*y[cmp::O2]*y[cmp::CH2OH]
                  + k[71]*y[cmp::O2]*y[cmp::CH2O]
                  + k[76]*y[cmp::O2]*y[cmp::HCO];

    f[cmp::CH3O] = + k[1]*y[cmp::O2]*y[cmp::CH3]
                   + 2.0*k[10]*y[cmp::CH3O2]*y[cmp::CH3O2]
                   - k[15]*y[cmp::CH3O]*y[cmp::CH3O2]
                   - k[17]*y[cmp::CH4]*y[cmp::CH3O]
                   - k[19]*y[cmp::CH3O]*y[cmp::CH2O]
                   - k[20]*y[cmp::CH3O]*y[cmp::CH3OH]
                   - k[21]*y[cmp::CH3O]*y[cmp::H2O2]
                   - 2.0*k[22]*y[cmp::CH3O]*y[cmp::CH3O]
                   - k[23]*y[cmp::CH3O]
                   - k[24]*y[cmp::CH3O]*y[cmp::M]
                   - k[25]*y[cmp::O2]*y[cmp::CH3O]
                   + k[27]*y[cmp::CH3]*y[cmp::HO2]
                   - k[36]*y[cmp::CH3O]*y[cmp::H]
                   - k[47]*y[cmp::CH3O]*y[cmp::OH]
                   + k[52]*y[cmp::OH]*y[cmp::CH3OH]
                   - k[59]*y[cmp::CH3O]*y[cmp::O]
                   + k[62]*y[cmp::O]*y[cmp::CH3OH]
                   + k[67]*y[cmp::CH3O2H]
                   - k[79]*y[cmp::CH3O];

    f[cmp::O] = + k[1]*y[cmp::O2]*y[cmp::CH3]
                + k[38]*y[cmp::O2]*y[cmp::H]
                - k[57]*y[cmp::CH4]*y[cmp::O]
                - k[58]*y[cmp::CH3]*y[cmp::O]
                - k[59]*y[cmp::CH3O]*y[cmp::O]
                - k[60]*y[cmp::O]*y[cmp::CH2O]
                - k[61]*y[cmp::O]*y[cmp::CH2OH]
                - k[62]*y[cmp::O]*y[cmp::CH3OH]
                - k[63]*y[cmp::O]*y[cmp::CH3OH]
                - k[64]*y[cmp::O]*y[cmp::HCO]
                - k[65]*y[cmp::O]*y[cmp::HCO]
                - k[66]*y[cmp::O]*y[cmp::H2];

    f[cmp::CH2O] = + k[2]*y[cmp::O2]*y[cmp::CH3]
                   - k[4]*y[cmp::CH3]*y[cmp::CH2O]
                   + k[15]*y[cmp::CH3O]*y[cmp::CH3O2]
                   + k[16]*y[cmp::CH3O2]
                   - k[19]*y[cmp::CH3O]*y[cmp::CH2O]
                   + k[22]*y[cmp::CH3O]*y[cmp::CH3O]
                   + k[23]*y[cmp::CH3O]
                   + k[24]*y[cmp::CH3O]*y[cmp::M]
                   + k[25]*y[cmp::O2]*y[cmp::CH3O]
                   - k[30]*y[cmp::HO2]*y[cmp::CH2O]
                   + k[36]*y[cmp::CH3O]*y[cmp::H]
                   - k[37]*y[cmp::CH2O]*y[cmp::H]
                   + k[45]*y[cmp::H]*y[cmp::CH2OH]
                   + k[47]*y[cmp::CH3O]*y[cmp::OH]
                   - k[48]*y[cmp::CH2O]*y[cmp::OH]
                   + k[58]*y[cmp::CH3]*y[cmp::O]
                   + k[59]*y[cmp::CH3O]*y[cmp::O]
                   - k[60]*y[cmp::O]*y[cmp::CH2O]
                   + k[61]*y[cmp::O]*y[cmp::CH2OH]
                   + k[70]*y[cmp::O2]*y[cmp::CH2OH]
                   - k[71]*y[cmp::O2]*y[cmp::CH2O]
                   - k[72]*y[cmp::CH2O]*y[cmp::M]
                   - k[73]*y[cmp::CH2O]*y[cmp::M]
                   - k[74]*y[cmp::CH2O]*y[cmp::CH3O2];

    f[cmp::OH] = + k[2]*y[cmp::O2]*y[cmp::CH3]
                 + k[16]*y[cmp::CH3O2]
                 + k[27]*y[cmp::CH3]*y[cmp::HO2]
                 + k[34]*y[cmp::HO2]*y[cmp::CO]
                 + k[38]*y[cmp::O2]*y[cmp::H]
                 + k[44]*y[cmp::H]*y[cmp::CH2OH]
                 - k[46]*y[cmp::CH4]*y[cmp::OH]
                 - k[47]*y[cmp::CH3O]*y[cmp::OH]
                 - k[48]*y[cmp::CH2O]*y[cmp::OH]
                 - k[49]*y[cmp::OH]*y[cmp::H2O2]
                 - k[50]*y[cmp::HO2]*y[cmp::OH]
                 - k[51]*y[cmp::OH]*y[cmp::CO]
                 - k[52]*y[cmp::OH]*y[cmp::CH3OH]
                 - k[53]*y[cmp::OH]*y[cmp::CH3OH]
                 - k[54]*y[cmp::CH3]*y[cmp::OH]
                 - k[55]*y[cmp::OH]*y[cmp::H2]
                 - k[56]*y[cmp::OH]*y[cmp::HCO]
                 + k[57]*y[cmp::CH4]*y[cmp::O]
                 + k[59]*y[cmp::CH3O]*y[cmp::O]
                 + k[60]*y[cmp::O]*y[cmp::CH2O]
                 + k[61]*y[cmp::O]*y[cmp::CH2OH]
                 + k[62]*y[cmp::O]*y[cmp::CH3OH]
                 + k[63]*y[cmp::O]*y[cmp::CH3OH]
                 + k[65]*y[cmp::O]*y[cmp::HCO]
                 + k[66]*y[cmp::O]*y[cmp::H2]
                 + k[67]*y[cmp::CH3O2H]
                 + 2.0*k[68]*y[cmp::H2O2]
                 + 2.0*k[69]*y[cmp::H2O2]*y[cmp::M]
                 - k[82]*y[cmp::OH];

    f[cmp::CH3O2] = + k[3]*y[cmp::O2]*y[cmp::CH3]
                    - 2.0*k[10]*y[cmp::CH3O2]*y[cmp::CH3O2]
                    - 2.0*k[11]*y[cmp::CH3O2]*y[cmp::CH3O2]
                    - k[12]*y[cmp::CH3O2]*y[cmp::H2O2]
                    - k[13]*y[cmp::CH4]*y[cmp::CH3O2]
                    - k[14]*y[cmp::CH3O2]*y[cmp::CH3OH]
                    - k[15]*y[cmp::CH3O]*y[cmp::CH3O2]
                    - k[16]*y[cmp::CH3O2]
                    - k[18]*y[cmp::CH3O2]*y[cmp::H2]
                    - k[29]*y[cmp::HO2]*y[cmp::CH3O2]
                    - k[74]*y[cmp::CH2O]*y[cmp::CH3O2]
                    - k[77]*y[cmp::CH3O2];

    f[cmp::HCO] = + k[4]*y[cmp::CH3]*y[cmp::CH3O]
                  - k[5]*y[cmp::CH3]*y[cmp::HCO]
                  + k[19]*y[cmp::CH3O]*y[cmp::CH2O]
                  + k[30]*y[cmp::HO2]*y[cmp::CH2O]
                  + k[37]*y[cmp::CH2O]*y[cmp::H]
                  - k[43]*y[cmp::HCO]*y[cmp::H]
                  + k[48]*y[cmp::CH3O]*y[cmp::OH]
                  - k[56]*y[cmp::OH]*y[cmp::HCO]
                  + k[60]*y[cmp::O]*y[cmp::CH2O]
                  - k[64]*y[cmp::O]*y[cmp::HCO]
                  - k[65]*y[cmp::O]*y[cmp::HCO]
                  + k[71]*y[cmp::O2]*y[cmp::CH2O]
                  + k[74]*y[cmp::CH2O]*y[cmp::CH3O2]
                  - k[75]*y[cmp::HCO]*y[cmp::M]
                  - k[76]*y[cmp::O2]*y[cmp::HCO];

    f[cmp::CO] = + k[5]*y[cmp::CH3]*y[cmp::HCO]
                 - k[34]*y[cmp::HO2]*y[cmp::CO]
                 + k[43]*y[cmp::HCO]*y[cmp::H]
                 - k[51]*y[cmp::OH]*y[cmp::CO]
                 + k[56]*y[cmp::OH]*y[cmp::HCO]
                 + k[65]*y[cmp::O]*y[cmp::HCO]
                 + k[73]*y[cmp::CH2O]*y[cmp::M]
                 + k[75]*y[cmp::HCO]*y[cmp::M]
                 + k[76]*y[cmp::O2]*y[cmp::HCO];

    f[cmp::C2H6] = + k[6]*y[cmp::CH3]*y[cmp::CH3]
                   + 0.5*k[77]*y[cmp::CH3O2]
                   + 0.5*k[79]*y[cmp::CH3O]
                   + 0.5*k[80]*y[cmp::CH3]
                   + 0.5*k[81]*y[cmp::CH3O2H];

    f[cmp::H2O2] = - k[7]*y[cmp::CH3]*y[cmp::H2O2]
                   - k[12]*y[cmp::CH3O2]*y[cmp::H2O2]
                   - k[21]*y[cmp::CH3O]*y[cmp::H2O2]
                   + k[26]*y[cmp::CH4]*y[cmp::HO2]
                   + k[30]*y[cmp::HO2]*y[cmp::CH2O]
                   + k[31]*y[cmp::HO2]*y[cmp::CH3OH]
                   + k[32]*y[cmp::HO2]*y[cmp::HO2]
                   + k[33]*y[cmp::HO2]*y[cmp::H2]
                   - k[41]*y[cmp::H2O2]*y[cmp::H]
                   - k[49]*y[cmp::OH]*y[cmp::H2O2]
                   - k[68]*y[cmp::H2O2]
                   - k[69]*y[cmp::H2O2]*y[cmp::M]
                   + 0.5*k[82]*y[cmp::OH] ;

    f[cmp::M] = 0;

    f[cmp::CH2] = + k[8]*y[cmp::CH3]*y[cmp::M];

    f[cmp::H] = + k[8]*y[cmp::CH3]*y[cmp::M]
                + k[18]*y[cmp::CH3O2]*y[cmp::H2]
                + k[23]*y[cmp::CH3O]
                + k[24]*y[cmp::CH3O]*y[cmp::M]
                + k[33]*y[cmp::HO2]*y[cmp::H2]
                - k[35]*y[cmp::CH4]*y[cmp::H]
                - k[36]*y[cmp::CH3O]*y[cmp::H]
                - k[37]*y[cmp::CH2O]*y[cmp::H]
                - k[38]*y[cmp::O2]*y[cmp::H]
                - k[39]*y[cmp::O2]*y[cmp::M]*y[cmp::H]
                - k[40]*y[cmp::H]*y[cmp::CH3OH]
                - k[41]*y[cmp::H2O2]*y[cmp::H]
                - k[42]*y[cmp::HO2]*y[cmp::H]
                - k[43]*y[cmp::HCO]*y[cmp::H]
                - k[44]*y[cmp::H]*y[cmp::CH2OH]
                - k[45]*y[cmp::H]*y[cmp::CH2OH]
                + k[51]*y[cmp::OH]*y[cmp::CO]
                + k[55]*y[cmp::OH]*y[cmp::H2]
                + k[58]*y[cmp::CH3]*y[cmp::O]
                + k[64]*y[cmp::O]*y[cmp::HCO]
                + k[66]*y[cmp::O]*y[cmp::H2]
                + k[72]*y[cmp::CH2O]*y[cmp::M]
                + k[75]*y[cmp::HCO]*y[cmp::M];

    f[cmp::CH3OH] = - k[9]*y[cmp::CH3]*y[cmp::CH3OH]
                    + k[11]*y[cmp::CH3O2]*y[cmp::CH3O2]
                    - k[14]*y[cmp::CH3O2]*y[cmp::CH3OH]
                    + k[17]*y[cmp::CH4]*y[cmp::CH3O]
                    + k[19]*y[cmp::CH3O]*y[cmp::CH2O]
                    + k[21]*y[cmp::CH3O]*y[cmp::H2O2]
                    + k[22]*y[cmp::CH3O]*y[cmp::CH3O]
                    - k[31]*y[cmp::HO2]*y[cmp::CH3OH]
                    - k[40]*y[cmp::H]*y[cmp::CH3OH]
                    - k[52]*y[cmp::OH]*y[cmp::CH3OH]
                    - k[53]*y[cmp::OH]*y[cmp::CH3OH]
                    + k[54]*y[cmp::CH3]*y[cmp::OH]
                    - k[62]*y[cmp::O]*y[cmp::CH3OH]
                    - k[63]*y[cmp::O]*y[cmp::CH3OH];

    f[cmp::CH2OH] = + k[9]*y[cmp::CH3]*y[cmp::CH3OH]
                    + k[20]*y[cmp::CH3O]*y[cmp::CH3OH]
                    + k[31]*y[cmp::HO2]*y[cmp::CH3OH]
                    + k[40]*y[cmp::H]*y[cmp::CH3OH]
                    - k[44]*y[cmp::H]*y[cmp::CH2OH]
                    - k[45]*y[cmp::H]*y[cmp::CH2OH]
                    + k[53]*y[cmp::OH]*y[cmp::CH3OH]
                    - k[61]*y[cmp::O]*y[cmp::CH2OH]
                    + k[63]*y[cmp::O]*y[cmp::CH3OH]
                    - k[70]*y[cmp::O2]*y[cmp::CH2OH];

    f[cmp::CH3O2H] = + k[12]*y[cmp::CH3O2]*y[cmp::H2O2]
                     + k[13]*y[cmp::CH4]*y[cmp::CH3O2]
                     + k[14]*y[cmp::CH3O2]*y[cmp::CH3OH]
                     + k[15]*y[cmp::CH3O]*y[cmp::CH3O2]
                     + k[18]*y[cmp::CH3O2]*y[cmp::H2]
                     + k[29]*y[cmp::HO2]*y[cmp::CH3O2]
                     - k[67]*y[cmp::CH3O2H]
                     + k[74]*y[cmp::CH2O]*y[cmp::CH3O2]
                     - k[81]*y[cmp::CH3O2H];

    f[cmp::H2] = - k[18]*y[cmp::CH3O2]*y[cmp::H2]
                 - k[33]*y[cmp::HO2]*y[cmp::H2]
                 + k[35]*y[cmp::CH4]*y[cmp::H]
                 + k[36]*y[cmp::CH3O]*y[cmp::H]
                 + k[37]*y[cmp::CH2O]*y[cmp::H]
                 + k[40]*y[cmp::H]*y[cmp::CH3OH]
                 + k[41]*y[cmp::H2O2]*y[cmp::H]
                 + k[42]*y[cmp::HO2]*y[cmp::H]
                 + k[43]*y[cmp::HCO]*y[cmp::H]
                 + k[45]*y[cmp::H]*y[cmp::CH2OH]
                 - k[55]*y[cmp::OH]*y[cmp::H2]
                 - k[66]*y[cmp::O]*y[cmp::H2]
                 + k[73]*y[cmp::CH2O]*y[cmp::M];

    f[cmp::CO2] = + k[34]*y[cmp::HO2]*y[cmp::CO]
                  + k[51]*y[cmp::OH]*y[cmp::CO]
                  + k[64]*y[cmp::O]*y[cmp::HCO];

    f[cmp::H2O] = + k[46]*y[cmp::CH4]*y[cmp::OH]
                  + k[47]*y[cmp::CH3O]*y[cmp::OH]
                  + k[48]*y[cmp::CH2O]*y[cmp::OH]
                  + k[49]*y[cmp::OH]*y[cmp::H2O2]
                  + k[50]*y[cmp::HO2]*y[cmp::OH]
                  + k[52]*y[cmp::OH]*y[cmp::CH3OH]
                  + k[53]*y[cmp::OH]*y[cmp::CH3OH]
                  + k[55]*y[cmp::OH]*y[cmp::H2]
                  + k[56]*y[cmp::OH]*y[cmp::HCO]
                  + 0.5*k[78]*y[cmp::HO2]
                  + 0.5*k[81]*y[cmp::CH3O2H];

    f[cmp::CHO] = + k[72]*y[cmp::CH2O]*y[cmp::M];
  }

  void initialConditions(myReal *y) {
    y[cmp::CH4] = 1.0 ;
    y[cmp::O2] = 2.0 ;
    for (int index = 2; index<SIZE; index++) {
      y[index] = 0.0;
    }
  }
};


#endif
