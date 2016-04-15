/* ############################################################################
* 
* Copyright (c) 2016 ICT MCG Group, Inc. All Rights Reserved
* 
* ###########################################################################
* Brief: 
 
* Authors: zhouxing(@ict.ac.cn)
* Date:    2016/04/14 22:34:22
* File:    gbdt_main.cpp
*/
#include "gbdt.h"
#include <iostream>
#include "./utils/utils.h"
#include "./utils/config.h"

namespace gbdt {

class GBDTLearnTask {
public:
	int run(int argc, char** argv) {
		// 1. set param
		ConfigIterator conf_iter(argv[1]);
		while (conf_iter.Next()) {
			this->SetParam(conf_iter.name(), conf_iter.val());
		}
		// 2. run task
		if (task == "train") {
			this->TaskTrain();
			return 0;
		}
		if (task == "predict") {
			this->TaskPredict();
		}
		return 0;
	}

	void SetParam(const char* name, const char* val) {
		if (!strcmp("num_round", name)) num_round = atoi(val);
		if (!strcmp("task", name)) task = val;
		if (!strcmp("model_in", name)) model_in = val;
    	if (!strcmp("model_out", name)) model_out = val;
    	if (!strcmp("train_file", name)) train_file = val;
		if (!strcmp("test_file", name)) test_file = val;
		gbdt.SetParam(name, val);
	}
private:
	void TaskTrain() {
		
	}
	void TaskPredict() {
		
	}
private:
	int num_round;
	std::string train_file, test_file;
	std::string model_in;
	std::string model_out;
	std::string task;

private:
	GBDT gbdt;
};
} // namespace gbdt

void info() {
    std::cout << "Config file" << std::endl;
}
int main(int argc, char** argv) {
    if (argc < 2) {
        info();
        return -1;
    }
    gbdt::GBDTLearnTask gbdt_task;
    gbdt_task.run(argc, argv);
    return 0;
}
