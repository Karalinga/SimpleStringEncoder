#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
std::vector<int> v = { 5,13,25,7,55,12 };
std::string s,s2;
int newCount;
std::string printString(std::vector<int> inputVector) {
	newCount = int((inputVector.size() % v.size()) - 1);
	if (newCount == -1) {
		newCount = v.size() - 1;
	}
	for (int i = inputVector.size() - 1; i >= 0; i--) {
		s.push_back(char(inputVector[i] - v[newCount]));
		if (newCount == 0) {
			newCount = v.size() - 1;
		}
		else { newCount--; }
	}
	s2.clear();
	for (int i = inputVector.size()-1; i >= 0; i--) {
		s2.push_back(s[i]);
	}
	s.clear();
	return s2;
}