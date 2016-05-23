#pragma once
#include <string>
using namespace std;

class ComputerException {
	string info;
public:
	ComputerException(const string& str) :info(str) {}
	string getInfo() const { return info; }
};