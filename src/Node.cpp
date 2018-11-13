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

            nodeText += to_string(this->blackHeight(this));
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

        int blackHeight(Node* node){

            int leftHeight = 1;
            int rightHeight = 1;

            //check if is a null node
            if(node->isNullNode()){
                return 0;
            }
            else{
                if(node->color == Color::BLACK){
                    leftHeight++;
                    rightHeight++;
                }
            }

            //increment recursive blackHeight for only not-null sides
            if(node->left != nullptr){
                leftHeight += blackHeight(node->left);
            }
            if(node->right != nullptr){
                rightHeight += blackHeight(node->right);
            }

            //return the major value
            if(leftHeight >= rightHeight){
                return leftHeight;
            }
            else{
                return rightHeight;
            }
        }

    private:

};

#endif // _NODE_
