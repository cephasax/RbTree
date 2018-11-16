/*
 * FileManager.cpp
 *
 *  Created on: 12 de nov de 2018
 *      Author: cephas
 */

#include <string>
#include <iostream>
#include <fstream>

#include "Node.cpp"
#include "RbT.cpp"

using namespace std;

class Dictionary{

	public:

		RbTree *rbt = new RbTree();
		ifstream file;

		Dictionary(){

		}

		void openFile(string path) {
			this->file.open(path);

			if (!file.is_open()) {
				cout << "The file wasn't opened. Please check entire path and file name." << endl;
				return;
			}
		}

		void processFileCommands(){
			string word;
			int option;
			while (file >> word) {
				cout << endl;
				file >> option;
				Node* node;

				//INSERT
				if (option == 1) {

					cout << "Insert of word: " << word << endl;
					node = rbt->search(word);
					//NODE IS NOT IN TREE
					if(node->isNullNode()){
						insertWord(word);
						cout << "Insertion made with success" << endl;
					}
					//NODE IS ALREADY IN TREE
					else{
						cout << "Unrealized insertion" << endl;
					}
				}

				//DELETE
				else if (option == 0) {

					cout << "Delete of word: " << word << endl;
					node = rbt->search(word);

					//NODE IS ALREADY IN TREE
					if(!node->isNullNode()){
						deleteWord(node);
						cout << "Deletion made with success" << endl;
					}
					//NODE IS NOT IN TREE
					else{
						cout << "Unrealized deletion" << endl;
					}
				}
				cout << "------------------------" << endl;
			}

		}

		void insertWord(string word){
			Node* node = new Node(word);
			rbt->insertNode(node);
			checkTree();

		}

		void deleteWord(Node* node){
			rbt->deleteNode(node);
			checkTree();
		}

		void checkTree(){
			cout << endl << "TREE CHECK:" << endl;
			rbt->rbtCheck(rbt->root);
		};

		void printSpace(){
			cout << "----------------------------------------" << endl;
			cout << "----------------------------------------" << endl;
		}

		void printRbHeight(){
			cout << endl << "TREE HEIGHT: " ;
			cout << rbt->root->blackHeight(rbt->root, rbt->root);
			cout << endl;
		}

		void printRbKeys(){
			cout << endl << "TREE KEYS: " << endl;
			string s = rbt->rbtPrint(rbt->root);
			cout << s;
			cout << endl;
		}
};

