

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
		int allOk = 0;

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

		void printStatus(){
			if(this->file.is_open() && !this->rbt->root->isNullNode()){
				cout << "RbTree was made with success and you can proceed with other operations" << endl;
				this->allOk = 1;
			}
			else{
				cout << "There is no RbTree built, please exit and run again" << endl;
			}
		}

		void userSearch(){
			string s;
			while(true){

				s.clear();
				cout << endl;
				cout << "Enter word to search inside the RbTree built" << endl;

				getline(cin, s);

				//SEARCH FOR SOME WORD GIVEN OR GETOUT IF THERE IS NO WORD
				if(s != ""){
					rbt->search(s);
				}
				else{
					cout << "No one word to find, so..." << endl;
					printRbKeys();
					checkTree();
					break;
				}


			}
		}

		void printBye(){
			cout << endl << endl;
			cout << "     <(o_o)> " << "bye";
		}
};

