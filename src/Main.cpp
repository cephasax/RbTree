//============================================================================
// Name        : RbTree.cpp
// Author      : Cephas Barreto
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include "RbTree.cpp"
#include "Node.cpp"
#include "FileManager.cpp"

using namespace std;

int main() {

	/* SIMPLE DEBUG

	RbTree *rbt = new RbTree();

	Node nodeNelson("Nelson Ned");
	Node nodeDago("Dago");
	Node nodeZezo("Zezo");

	rbt->insertNode(&nodeNelson);
	rbt->insertNode(&nodeDago);
	rbt->insertNode(&nodeZezo);

	cout << rbt->root->toString() << endl;

	*/

	Dictionary dic;
	dic.openFile("src/dicionario3.txt");
	dic.processFileCommands();

	dic.printSpace();

	dic.checkTree();

	return 0;
}
