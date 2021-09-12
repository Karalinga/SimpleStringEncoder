#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <fstream>
std::vector<int> v = {5,13,25,7,55,12};
std::vector<int> sascii;
std::vector<std::string> strings;
std::ifstream file("strings_to_convert.txt");
std::ofstream outFile("converted_strings.txt");
int pscount = 0;
int newCount;
std::string line;
void mainLoop(std::string s){
	//std::cout << char(-123) <<std::endl;
	outFile<< s <<" = ";
	for(int i =0;i<s.length();i++){
		s[i] = char(int(s[i])+v[pscount]);
		sascii.push_back(int(s[i]));
		if(pscount>v.size()-2){
			pscount = 0;
		}
		else{pscount ++;}
	}
	//std::cout<<s<<std::endl;
	newCount = int((s.length()%v.size())-1);
	//std::cout <<"why does it work here "<< newCount <<std::endl;
	for(int i =s.length()-1;i>=0;i--){
		s[i] = char(sascii[i]-v[newCount]);
		if(newCount==0){
			newCount = v.size()-1;
		}
		else{newCount --;}
	}
	//std::cout <<s <<std::endl;
	
	outFile <<"printString({";
	for(int i = 0;i<sascii.size();i++){
		outFile<<sascii[i];
		if(i<sascii.size()-1){
			outFile<<",";
		}
	}
	if(pscount ==0){
		pscount = v.size();
	}
	outFile<<"});\n";
	//std::cout << pscount << ")"<<std::endl;
	sascii.clear();
	pscount = 0;
}
int main(){
	if (file.is_open()) {
		
		while (std::getline(file, line)) {
			mainLoop(line);
		}
	}
	file.close();
	
	return 0;
	
	
}
