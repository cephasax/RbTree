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

using namespace std;

int main(int argc, char const *argv[]) {

	ifstream file;
	string path;
	Dictionary dic;

	//GET FILENAME
	if (argv[1] != NULL) {
		path = argv[1];
	}

	//TRY TO OPEN THE GIVEN FILE AND OPEN WITH DEFAULT IF NAME IS INVALID
	dic.openFile(path);
	if (!dic.file.is_open()){
		cout << "The RbTree will use default file name because the given file is invalid. Default file name is \"dicionarioFrutas.txt\"" << endl;
		path.clear();
		path = "src\\dicionarioFrutas.txt";
		dic.openFile(path);
	}

	//Process file words and make tree according to it
	dic.processFileCommands();
	dic.printSpace();

	//print status of Dictionary's Tree
	dic.printStatus();

	dic.userSearch();
	dic.printBye();


}

