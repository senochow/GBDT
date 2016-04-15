/* ############################################################################
* 
* Copyright (c) 2016 ICT MCG Group, Inc. All Rights Reserved
* 
* ###########################################################################
* Brief: 
 
* Authors: zhouxing(@ict.ac.cn)
* Date:    2016/04/15 14:56:22
* File:    config.h
*/
#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <cstdio>
#include <cstring>
#include <string>
#include <istream>
#include <fstream>
#include "./utils.h"

namespace gbdt {

class ConfigIterator {
public:
  const char* name() const {
    return s_name.c_str();
  }
  
  const char* val() const {
    return s_val.c_str();
  }

  bool Next() {
    while(!fin.eof()) {
      if (GetNextPair(s_name, s_val)) {
        return true;
      }else return false;
    }
  }
private:
  std:string s_name, s_val, line;
  ifstream fin;
private:
  // get next name or val
  bool GetNextPair(std::string& key, std::string& val) {
    key.clear();
    val.clear();
    if (getline(fin, line)) {
      // empty line or # to pass
      if (line.empty() || line[0] == '#') return GetNextPair(key, val);
      int index = key.find('#');
      if (index != std::string::npos) {
        key = line.substr(0, index);
        val = line.substr(index+1);
        utils::trim(key);
        utils::trim(val);
        return true;
      }else return GetNextPair(key, val);
    }else return false;
  }
public:
  ConfigIterator(const char* filename) {
    fin.open(filename);
    if (!fin) {
      utils::Error("can't open file %s", filename);
    }
  }
  ~ConfigIterator() {
    fin.close();
  }
};
} // namespace