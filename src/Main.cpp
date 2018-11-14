//============================================================================
// Name        : RbTree project
// Author      : Cephas Barreto
// Description : Dictionary program using RBTREE structure for lexicography words organization
//============================================================================

#include <iostream>

#include "Dictionary.cpp"
#include "RbTree.cpp"
#include "Node.cpp"

using namespace std;

int main() {


	Dictionary dic;
	dic.openFile("src/dicionario4.txt");
	dic.processFileCommands();
	dic.printSpace();

	dic.checkTree();
	dic.printSpace();

	dic.printRbHeight();
	dic.printSpace();

	dic.printRbKeys();
	dic.printSpace();

	return 0;
}
