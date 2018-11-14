#ifndef _NODE_
#define _NODE_

#include <iostream>
#include <string>
#include "Color.cpp"

using namespace std;

class Node{

    public:

        string key;
        Color color;
        Node* parent;
        Node* left;
        Node* right;

        Node(string key ){
            this->key = key;
            this->color = Color::BLACK;
            this->parent = nullptr;
            this->left = nullptr;
            this->right = nullptr;
        }

        Node(){
            this->key = "NIL";
            this->color = Color::BLACK;
            this->parent = nullptr;
            this->left = nullptr;
            this->right = nullptr;
        }

        bool isNullNode(){
            if((this->key == "NIL") && (this->color == Color::BLACK)){
                return true;
            }
            else{
                return false;
            }
        }

        string toString(){

            string nodeText;

            nodeText += "(";

            if(this->parent == nullptr){
                nodeText += "NIL";
            }
            else{
                nodeText += this->parent->key;
            }
            nodeText += ", ";

            nodeText += this->key;
            nodeText += ", ";

            if(this->color == Color::RED){
                nodeText += "vermelho";
            }
            else{
                nodeText += "preto";
            }
            nodeText += ", ";

            nodeText += to_string(this->blackHeight(this,this));
            nodeText += ", ";

            if(this->left != nullptr){

                if(this->left->isNullNode()){
                    nodeText += "NIL";
                }
                else{
                    nodeText += this->left->key;
                }
            }
            else{
                nodeText += "NULO";
            }
            nodeText += ", ";

            if(this->right != nullptr){
                if(this->right->isNullNode()){
                    nodeText += "NIL";
                }
                else{
                    nodeText += this->right->key;
                }
            }
            else{
                nodeText += "NULO";
            }
            nodeText += ")";

            return nodeText;
        }

        int blackHeight(Node* node, Node* root){

        	//COUNT IF NODE IS (BLACK AND NIL) or NODE IS (BLACK AND NOT THE ROOT)
        	if(node->isNullNode() && (node == root)){
        		left = 0;
        		right = 0;
        	}
        	else{
        		if(node->isNullNode()){
        			return 1;
        		}else{

                	int left = 0;
                	int right = 0;
                	int no = 0;

                	if(node->color==Color::BLACK && node!=root){
                		no=1;
                	}

        			if(node->left != nullptr){
        				left = no+blackHeight(node->left,root);
        			}

        			if(node->right != nullptr){
        				right = no+blackHeight(node->right,root);
        			}

        			if(left>=right){
        				return left;
        			}
        			else{
        				return right;
        			}
        		}
        	}

        	return 0;
        }
};

#endif // _NODE_
