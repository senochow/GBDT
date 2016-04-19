/* ############################################################################
* 
* Copyright (c) 2016 ICT MCG Group, Inc. All Rights Reserved
* 
* ###########################################################################
* Brief: 
 
* Authors: zhouxing(@ict.ac.cn)
* Date:    2016/04/14 23:24:35
* File:    data.h
*/
#ifndef _DATA_H
#define _DATA_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace gbdt {

struct DFeature {
	float* feature;
	float label;
	float target;
	float weight;
	DFeature() {
		feature = NULL;
		label = 0;
		target = 0;
		weight = 0;
	}
	~DFeature() {
		delete[] feature;
	}
};

DFeature FromString(const std::string& s_fea) {
	DFeature fea;
	fea.feature = new float[]
}

typedef std::vector<DFeature> DataVector;

bool LoadDataFromFile(const std::string& filename, DataVector& data, ) {
	data.clear();
	ifstream fin(filename);
	if (!fin) {
		Error("Can't open file %s", filename);
		return false;
	}
	std::string line;
	while (getline(fin, line)) {
		DFeature fea = FromString(line);
		data.push_back(fea);
	}
	return true;
}

} // namespace gbdt

#endif