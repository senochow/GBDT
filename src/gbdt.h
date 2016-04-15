#ifndef _GBDT_H_
#define _GBDT_H_

/* ############################################################################
* 
* Copyright (c) 2016 ICT MCG Group, Inc. All Rights Reserved
* 
* ###########################################################################
* Brief: 
 
* Authors: zhouxing(@ict.ac.cn)
* Date:    2016/04/14 22:36:51
* File:    gbdt.h
*/
#include <vector>
#include <cstdlib>
#include "tree.h"
namespace gbdt {
class GBDT {
    private:
        std::vector<CART> trees;
        double bias;
        double shrinkage;
    public:
        GBDT();
        void train();
        void Predict();
        void SetParam(const char* name, const char* val);
};// class GBDT
} // namespace gbdt

#endif
