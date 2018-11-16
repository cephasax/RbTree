/*
 * RBTree.cpp
 *
 *  Created on: 12 de nov de 2018
 *  Author: Cephas
 */

#include <string>
#include <iostream>
#include <fstream>

#include "Dictionary.cpp"
#include "Node.cpp"
#include "RbT.cpp"

using namespace std;

int main(int argc, char const *argv[]) {

	ifstream file;
	string path;

	if (argv[1] == nullptr) {
		cout << "RbTree made with default value cause file pointed is invalid";
		path = "dicionario1.txt";
	}
	else {
		path = argv[1];
	}
	file.open(path);
	if (!file.is_open())
		return -1;

	std::string word;
	int option;

	Dictionary dic;
	dic.openFile("src/dicionario1.txt");
	dic.processFileCommands();
	dic.printSpace();

}

