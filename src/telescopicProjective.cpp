#include "telescopicProjective.hpp"

void projective(myReal *yOld, myReal *yNew,
                funct odeFUN, myReal dt,
                myReal &t, int level,
                std::ofstream &file) {
  if (level > 1) {
    myReal yOldCopy[SIZE] = {0.0};
    copyFirstArrayToSecond(yOld, yOldCopy);
    for (int i = 1; i <= odeFUN.mLevels[level]; i++) {
      projective(yOldCopy, yNew, odeFUN, dt, t, level - 1,file);
      copyFirstArrayToSecond(yNew, yOldCopy);
    }
    copyFirstArrayToSecond(yOldCopy, yOld);
    t = t + odeFUN.mLevels[level] * odeFUN.DTLevel[level];

    // k step jump
    myReal yTemp1[SIZE] = {0.0};
    myReal yImplicit[SIZE] = {0.0};
    myReal gradient[SIZE] = {0.0};
    myReal timeTemp1 = t;
    myReal timeTemp2 = t;

    projective(yOldCopy, yNew, odeFUN, dt, t, level - 1,file);
    implicitScheme(yOldCopy, yTemp1, yImplicit, odeFUN, dt, timeTemp2);
    for (int elem = 0; elem < SIZE; elem++) {
      gradient[elem] = yImplicit[elem] - yOld[elem];
    }
    for (int elem = 0; elem < SIZE; elem++) {
      yNew[elem] = yOld[elem] + odeFUN.kLevels[level] * gradient[elem];
    }
    t = t + odeFUN.kLevels[level] * odeFUN.DTLevel[level];
    if(level == 3)
      printToFile(0, t, yNew, file);
  } else {
    myReal yOldCopy[SIZE] = {0.0};
    copyFirstArrayToSecond(yOld, yOldCopy);
    for (int i = 1; i <= odeFUN.mLevels[level]; i++) {
      eulerIntegrator(yOld, yNew, odeFUN, t);
      copyFirstArrayToSecond(yNew, yOld);
    }
    copyFirstArrayToSecond(yNew, yOldCopy);
    t = t + odeFUN.mLevels[level] * odeFUN.dt;

    // k step jump
    myReal yTemp1[SIZE] = {0.0};
    myReal yImplicit[SIZE] = {0.0};
    myReal gradient[SIZE] = {0.0};
    myReal timeTemp1 = t;
    myReal timeTemp2 = t;

    eulerIntegrator(yOld, yNew, odeFUN, t);
    implicitScheme(yOldCopy, yTemp1, yImplicit, odeFUN, dt, timeTemp2);
    for (int elem = 0; elem < SIZE; elem++) {
      gradient[elem] = yImplicit[elem] - yOld[elem];
    }
    for (int elem = 0; elem < SIZE; elem++) {
      yNew[elem] = yOld[elem] + odeFUN.kLevels[level] * gradient[elem];
    }
    t = t + odeFUN.kLevels[level] * odeFUN.dt;
    copyFirstArrayToSecond(yNew, yOld);
  //  std::cout << t << " " << level << std::endl;
  }
}