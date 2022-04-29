#ifndef _TELESCOPIC_PROJECTIVE_H_
#define _TELESCOPIC_PROJECTIVE_H_

#include "functions.hpp"

void projective(myReal *yOld, myReal *yNew,
                funct odeFUN, myReal dt,
                myReal &t, int level,std::ofstream &file);

#endif
