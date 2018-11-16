//============================================================================
// Name        : RbTree project
// Author      : Cephas Barreto
// Description : Dictionary program using RBTREE structure for lexicography words organization
//============================================================================

#ifndef _TESTALL_
#define _TESTALL_

#include <iostream>

#include "Dictionary.cpp"
#include "Node.cpp"
#include "RbT.cpp"

using namespace std;

class TestAll{

	public:

		void doAll(){
			Dictionary dic;
			dic.openFile("src/dicionario1.txt");
			dic.processFileCommands();
			dic.printSpace();

			dic.checkTree();
			dic.printSpace();

			dic.printRbHeight();
			dic.printSpace();

			dic.printRbKeys();
			dic.printSpace();

			dic.checkTree();
			dic.printSpace();
		}

};

#endif //_TESTALL_
