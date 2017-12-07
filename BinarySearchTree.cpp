/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinarySearchTree.cpp
 * Author: niklas_debbrecht
 * 
 * Created on 23. November 2017, 11:07
 */

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
    this->root = NULL;
}
Knoten* BinarySearchTree::getRoot() {
    return this->root;
}
void BinarySearchTree::setRoot(Knoten *newRoot) {
    this->root = newRoot;
}

bool BinarySearchTree::insert(int key, std::string value) {
    Knoten* v = this->root;
    Knoten* toInsert = new Knoten(key,value);
    while (v!=NULL){
        if(toInsert->getKey() < v->getKey()){
            if(v->getLeft() == NULL){
                v->setLeft(toInsert);
                toInsert->setRoot(v);
                return true;
            }else{
                v = v->getLeft();
            }
        }else if(toInsert->getKey() == v->getKey()){
           return false;
        }else{
            if(v->getRight() == NULL){
                v->setRight(toInsert);
                toInsert->setRoot(v);
                return true;
            }else{
                v = v->getRight();
            }
        }
    }
    //If Tree empty new node is root
    this->root=toInsert;
    return true;
}

void BinarySearchTree::remove(int key){
    /*Knoten* u = this->search(key);
    if(u->getLeft() == NULL && u->getRight() == NULL){ //no leafs
        if(u->getRoot()->getLeft()->getKey() == u->getKey()){ //check for u being the right or left leaf
            u->getRoot()->setLeft(NULL);
            u->~Knoten();
        } else {
            u->getRoot()->setRight(NULL);
            u->~Knoten();
        }
    } else if(u->getLeft() != NULL && u->getRight() != NULL){ // 2 leafs
        if(u->getRoot()->getLeft()->getKey() == u->getKey()){
            u->getRoot()->setLeft(u->getLeft());
            //this->insert(u->getRight());
            u->~Knoten();
        } else {
           u->getRoot()->setRight(u->getRight());
           //this->insert(u->getLeft());
           u->~Knoten();
        }
    } else { // one leaf
        if(u->getLeft() != NULL){
            if(u->getRoot()->getLeft()->getKey() == u->getKey()){ //check for u being the right or left leaf
                u->getRoot()->setLeft(u->getLeft());
                u->~Knoten();
            } else {
                u->getRoot()->setRight(u->getLeft());
                u->~Knoten();
            }
        } else {
            if(u->getRoot()->getLeft()->getKey() == u->getKey()){ //check for u being the right or left leaf
                u->getRoot()->setLeft(u->getRight());
                u->~Knoten();
            } else {
                u->getRoot()->setRight(u->getRight());
                u->~Knoten();
            }
        }
    }*/
    Knoten* toDelete = this->searchKnoten(key);
    if(toDelete !=NULL){
    Knoten* parent = toDelete->getRoot();
    bool parentIsBigger = false;
    if(parent!=NULL) {
        parentIsBigger = (parent->getKey() > toDelete->getKey());
    }
        if(toDelete->getRight()==NULL&&toDelete->getLeft()==NULL){
            //1: toDelete is leaf
            if(parent!=NULL){
                if(parentIsBigger){
                    //if parent ID is greater; parents left Child = NULL
                    parent->setLeft(NULL);
                }else{
                    //if parent ID is smaller; parents left Child = NULL
                    parent->setRight(NULL);
                }
            }
            else{
                this->setRoot(NULL);
            }
            delete toDelete;
        }else if((toDelete->getRight()!=NULL)&&(toDelete->getLeft()!=NULL)){
            //2: toDelete has two children

            //find successor
            Knoten* successor = toDelete->getRight();
            while(successor->getLeft()!=NULL){
                successor=successor->getLeft();
            }

            if(toDelete->getRight()==successor){
                successor->setLeft(toDelete->getLeft());
                if(toDelete!=this->getRoot()){
                    if(parentIsBigger){
                        parent->setLeft(successor);
                    }else{
                        parent->setRight(successor);
                    }
                    successor->setRoot(parent);
                }else{
                    this->setRoot(successor);
                    successor->setRoot(NULL);
                }
            }else{
                if(successor->getRight()!=NULL){
                    //if in right sub tree of successor there still are values put the right child in successors position
                    successor->getRoot()->setLeft(successor->getRight());
                    successor->getRight()->setRoot(successor->getRoot());
                }
                else{
                    //else remove sucessor from tree
                    successor->getRoot()->setLeft(NULL);
                }
                //give successor childs and parent of toDelete (same order)
                successor->setLeft(toDelete->getLeft());
                successor->setRight(toDelete->getRight());
                successor->setRoot(parent);
                //update parent - check if root
                if(this->getRoot()==toDelete){
                    this->setRoot(successor);
                }else{
                    if(parentIsBigger){
                        parent->setLeft(successor);
                    }else{
                        parent->setRight(successor);
                    }
                }
                successor->getLeft()->setRoot(successor);
                successor->getRight()->setRoot(successor);


            }
            toDelete->setRight(NULL);
            toDelete->setLeft(NULL);
            toDelete->setRoot(NULL);
            delete toDelete;
        }else {
            //3: toDelete has only one Child
            if(toDelete->getRight() == NULL){
                //left child now correct child of parent
                if(parent!=NULL){
                    if(parentIsBigger){
                        parent->setLeft(toDelete->getLeft());
                        parent->getLeft()->setRoot(parent);
                    } else{
                        parent->setRight(toDelete->getLeft());
                        parent->getRight()->setRoot(parent);
                    }
                } else{
                    this->root = toDelete->getLeft();
                    toDelete->getLeft()->setRoot(NULL);
                }
            }else if(toDelete->getLeft() == NULL){
                //right child now correct child of parent
                if(parent!=NULL){
                    if(parentIsBigger){
                        parent->setLeft(toDelete->getRight());
                        parent->getLeft()->setRoot(parent);
                    } else{
                        parent->setRight(toDelete->getRight());
                        parent->getRight()->setRoot(parent);
                    }
                } else{
                    this->setRoot(toDelete->getRight());
                    toDelete->getRight()->setRoot(NULL);
                }
            }
            delete toDelete;
        }
    }
    else{
      //  std::cout<<"Das gesuchte Element ist nicht im Baum!"<<std::endl;
    }
}

bool BinarySearchTree::check(){
    return check(this->root, INT_MIN, INT_MAX);
}

bool BinarySearchTree::check(Knoten* v, int min, int max){
    /*if(v.getLeft() != NULL){
bool BinarySearchTree::check(Knoten v){
    if(v.getLeft() != NULL){
        if(v.getLeft()->getKey() < v.getKey()){
            check(v.getLeft());
        } else {
            return false;
        }
    }
    if(v.getRight() != NULL){
        
    }*/
    //if tree empty or recursion end
    if(v==NULL) {
        return true;
    }else if((v->getKey() < min)||(v->getKey() > max)){
        //Check if key in limits
        return false;
    } else{
        //call isBST with fitting new min or max (recursive)
        return check(v->getLeft(),min,v->getKey())&&
               check(v->getRight(),v->getKey(),max);
    }
    return true;
}

int BinarySearchTree::height(){
    height(this->root);
}

int BinarySearchTree::height(Knoten* v){
    if(v == NULL){
        return -1;
    }
    return 1 + max(height(v->getLeft()), height(v->getRight()));
}

string BinarySearchTree::search(int key) {
    Knoten* temp = this->searchKnoten(key);
    return temp->getValue();
}

Knoten* BinarySearchTree::searchKnoten(int key) {
    Knoten* v = this->root;
    while (v!=NULL){
        if(key<v->getKey()){
            v = v->getLeft();
        }else if(key == v->getKey()){
            return v;
        }
        else{
            v=v->getRight();
        }
    }
    return NULL;
}