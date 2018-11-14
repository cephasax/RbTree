#ifndef _RB_TREE_
#define _RB_TREE_

#include <iostream>
#include <string>
#include <algorithm>
#include "Node.cpp"

using namespace std;

class RbTree{

    public:

        Node* root;

        RbTree(){
            this->root = new Node();
        }

        RbTree(Node& rootNode){
            this->root = &rootNode;
        }

        string RbPrint(){

            return "";
        }

        Node* treeMin(Node* node){
            Node* aux = node;
            while(!aux->isNullNode()){
                aux = node->left;
            }
            return aux;
        }

        Node* treeMax(Node* node){
            Node* aux = node;
            while(!aux->isNullNode()){
                aux = node->right;
            }
            return aux;
        }

        void leftRotate(Node* node){

            Node* y = node->right;
            node->right = y->left;

            if(!y->left->isNullNode()){
                y->left->parent = node;
            }

            y->parent = node->parent;

            if(node->parent->isNullNode()){
            	this->root = y;
            }
            else{
            	if(node == node->parent->left){
            		node->parent->left = y;
            	}
            	else{
            		node->parent->right = y;
            	}
            }
            y->left = node;
            node->parent = y;
        }

        void rightRotate(Node* node){
        	Node* y = node->left;
			node->left = y->right;

			if(!y->right->isNullNode()){
				y->right->parent = node;
			}

			y->parent = node->parent;

			if(node->parent->isNullNode()){
				this->root = y;
			}
			else{
				if(node == node->parent->right){
					node->parent->right = y;
				}
				else{
					node->parent->left = y;
				}
			}
			y->right = node;
			node->parent = y;
        }

        void insertNodeFixUp(Node* node){

            Node* y = new Node();

            //WHILE NODE PARENT IS RED
            while(node->parent->color == Color::RED){

                //IF NODE PARENT IS LEFT
                if(node->parent == node->parent->parent->left){
                    y = node->parent->parent->right;

                    //IF NODE PARENT IS RED
                    if(y->color == Color::RED){
                        node->parent->color = Color::BLACK;
                        y->color = Color::BLACK;
                        node->parent->parent->color = Color::RED;
                        node = node->parent->parent;
                    }
                    //NODE PARENT IS BLACK
                    else{
                        //NODE IS RIGHT
                        if(node == node->parent->right){
                            node = node->parent;
                            leftRotate(node);
                        }
                        node->parent->color = Color::BLACK;
                        node->parent->parent->color = Color::RED;
                        rightRotate(node->parent->parent);
                    }
                }

                //NODE PARENT IS RIGHT
                else{
                    y = node->parent->parent->left;

                    //IF NODE PARENT IS RED
                    if(y->color == Color::RED){
                        node->parent->color = Color::BLACK;
                        y->color = Color::BLACK;
                        node->parent->parent->color = Color::RED;
                        node = node->parent->parent;
                    }
                    //NODE PARENT IS BLACK
                    else{
                        //NODE IS LEFT
                        if(node == node->parent->left){
                            node = node->parent;
                            rightRotate(node);
                        }
                        node->parent->color = Color::BLACK;
                        node->parent->parent->color = Color::RED;
                        leftRotate(node->parent->parent);
                    }
                }
            }
            this->root->color = Color::BLACK;
        }

        void insertNode(Node* node){
            Node* y = new Node();
            Node* x = this->root;

            while(!x->isNullNode()){
                y = x;
                if(node->key.compare(x->key) < 0){
                    x = x->left;
                }
                else{
                    x = x->right;
                }
            }
            node->parent = y;

            if(y->isNullNode()){
                this->root = node;
            }
            else{
                if(node->key.compare(y->key) < 0){
                    y->left = node;
                }
                else{
                    y->right = node;
                }
            }
            node->right = new Node();
            node->left = new Node();
            node->color = Color::RED;
            insertNodeFixUp(node);
        }

        void deleteNodeFixUp(Node* node){

            Node* y = new Node();

            //WHILE NODE IS NOT THE ROOT AND ITS COLOR IS BLACK
            while(node != this->root && node->color == Color::BLACK){

                if(node == node->parent->left){
                    y = node->parent->right;

                    if(y->color == Color::RED){
                        y->color = Color::BLACK;
                        node->parent->color = Color::RED;
                        leftRotate(node->parent);
                        y = node->parent->right;
                    }

                    if(y->left->color == Color::BLACK && y->right->color == Color::BLACK){
                        y->color = Color::RED;
                        node = node->parent;
                    }
                    else{
                        if(y->right->color == Color::BLACK){
                            y->left->color = Color::BLACK;
                            y->color = Color::RED;
                            rightRotate(y);
							y = node->parent->right;
                        }
                        y->color = node->parent->color;
                        node->parent->color = Color::BLACK;
                        y->right->color = Color::BLACK;
                        leftRotate(node->parent);
                        node = this->root;
                    }
                }
                else{
                	y = node->parent->left;

					if(y->color == Color::RED){
						y->color = Color::BLACK;
						node->parent->color = Color::RED;
						rightRotate(node->parent);
						y = node->parent->left;
					}

					if(y->right->color == Color::BLACK && y->left->color == Color::BLACK){
						y->color = Color::RED;
						node = node->parent;
					}
					else{
						if(y->left->color == Color::BLACK){
							y->right->color = Color::BLACK;
							y->color = Color::RED;
							leftRotate(y);
							y = node->parent->left;
						}
						y->color = node->parent->color;
						node->parent->color = Color::BLACK;
						y->left->color = Color::BLACK;
						rightRotate(node->parent);
						node = this->root;
					}
				}
            }
            node->color = Color::BLACK;
        }

        void transplant(Node* u, Node* v){
            if(u->parent->isNullNode()){
                this->root = v;
            }
            else{
                if(u == u->parent->left){
                    u->parent->left = v;
                }
                else{
                    u->parent->right = v;
                }
            }
            v->parent = u->parent;
        }

        void deleteNode(Node* node){
            Node* y = new Node();
            Node* x = new Node();
            y = node;
            Color originalYColor = y->color;

            if(node->left->isNullNode()){
                x = node->right;
                transplant(node, node->right);

            }
            else if(node->right->isNullNode()){
                x = node->left;
                transplant(node, node->left);
            }
            else{
                y = treeMin(node->right);
                originalYColor = y->color;
                x = y->right;

                if(y->parent == node){
                    x->parent = y;
                }
                else{
                    transplant(y, y->right);
                    y->right = node->right;
                    y->right->parent = y;
                }
                transplant(node, y);
                y->left = node->left;
                y->left->parent = y;
                y->color = node->color;
            }
            if(originalYColor == Color::BLACK){
                deleteNodeFixUp(x);
            }
        }

        Node* search(string key){

            Node* actual = this->root;

            //IF RB-TREE IS EMPTY
            if(actual->isNullNode()){
                cout << "This RbTree is empty" << endl;
                Node* node = new Node();
                return node;
            }

			int resultFromCompare = actual->key.compare(key);

			while((resultFromCompare != 0) && (!actual->isNullNode())){
				if(resultFromCompare > 0){
					actual = actual->left;
					resultFromCompare = actual->key.compare(key);
				}
				else{
					actual = actual->right;
					resultFromCompare = actual->key.compare(key);
				}
			}

			if(resultFromCompare == 0){
				cout << "Key: \"" << actual->key << "\" was found inside node -> ";
				cout << actual->toString() << endl;
			}
			else{
				cout << "This RbTree doesn't have this key: " + key << endl;
			}

			return actual;
        }

        void rbtCheck(Node* n){
        	if(!n->isNullNode()){
        		cout << n->toString() << endl;
        		rbtCheck(n->left);
        		rbtCheck(n->right);
        	}
        }

};

#endif // _RB_TREE_
