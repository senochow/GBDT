/* ############################################################################
* 
* Copyright (c) 2016 ICT MCG Group, Inc. All Rights Reserved
* 
* ###########################################################################
* Brief: 
 
* Authors: zhouxing(@ict.ac.cn)
* Date:    2016/04/14 23:24:16
* File:    gbdt.cpp
*/
#include "gbdt.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

#ifdef USE_OPENMP
#include <parallel/algorithm>  // openmp
#endif
namespace gbdt {
void GBDT::SetParam(const char* name, const char* val) {
	if (!strcmp("shrinkage", name)) shrinkage = atoi(val);

}

GBDT::GBDT() {
    shrinkage = 0.1;
    bias = 0;
}




} // namespace
