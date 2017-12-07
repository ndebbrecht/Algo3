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

BinarySearchTree::BinarySearchTree(int key, string value) {
    //this->root = new Knoten(key, value);
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& orig) {
}

BinarySearchTree::BinarySearchTree(){
    this->root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
    
}

void BinarySearchTree::insert(int key, string value){
    Knoten* u = new Knoten(key, value);
    Knoten* v = this->root;
    while(v != NULL){
        if(u->getKey() < v->getKey()){
            if(v->getLeft() == NULL){
                v->setLeft(u);
                return;
            } else {
                v = v->getLeft();
            }
        } else {
            if(v->getRight() == NULL){
                v->setRight(u);
                return;
            } else {
                v = v->getRight();
            }
        }
    }
    this->root = u;
    
}

Knoten* BinarySearchTree::search(int k){
    Knoten* v = this->root;
    while(v != NULL){
        if(k < v->getKey()){
            v = v->getLeft();
        } else if(k == v->getKey()){
            return v;
        } else {
            v = v->getRight();
        }
        return NULL;
    }
    return NULL;
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
    Knoten* toDelete = this->search(key);
    if(toDelete !=NULL){
        cout<<"hallo"<<endl;
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
                this->root = NULL;
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
                if(toDelete!=this->root){
                    if(parentIsBigger){
                        parent->setLeft(successor);
                    }else{
                        parent->setRight(successor);
                    }
                    successor->setRoot(parent);
                }else{
                    this->root = successor;
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
                if(this->root==toDelete){
                    this->root = successor;
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
                    this->root = toDelete->getRight();
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