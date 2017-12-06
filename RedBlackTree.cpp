/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RedBlackTree.cpp
 * Author: sandragall
 * 
 * Created on December 6, 2017, 3:01 PM
 */

#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() {
    this->root=this->nil;
    this->nil->setRoot(this->nil);
}

void RedBlackTree::insert(int key, string value){
    Knoten* y = this->nil; 
    Knoten* x = this->root;
    Knoten* z = new Knoten(key,value);
    while(x != this->nil ) {
        y = x; /* Vorgaenger merken */
        if( z->getKey() < x->getKey() ){
            x = x->getLeft();
        } else{ 
            x = x->getRight();
        }
    }
    z->setRoot(y);
    if( y == nil ){ 
        this->root = z; /* Baum leer -> neue Wurzel */
    }   else {
        if( z->getKey() < y->getKey() ){ 
            y->setLeft(z);
        } else{ 
            y->setRight(z);
        }
    }
    /* Knoten z ist eingefuegt */
    z->setLeft(this->nil);
    z->setRight(this->nil); 
    z->setColor(RED);
    
    /* Rot-Schwarz Eigenschaften reparieren */
    RB_Repair_Insert(z);
};

Knoten* RedBlackTree::search(int k){
    Knoten* v = this->root;
    while(v != this->nil){
        if(k < v->getKey()){
            v = v->getLeft();
        } else if(k == v->getKey()){
            return v;
        } else {
            v = v->getRight();
        }
        return this->nil;
    }
    return this->nil;
}

void RedBlackTree::RB_Repair_Insert(Knoten* z) {
    Knoten* help;
    while(z->getRoot()->getColor()==RED){
        if(z->getRoot()==z->getRoot()->getRoot()->getLeft()){
            help = z->getRoot()->getRoot()->getRight();
            if(help->getColor()==RED){
                z->getRoot()->setColor(BLACK);
                help->setColor(BLACK);
                z->getRoot()->getRoot()->setColor(RED);
                z = z->getRoot()->getRoot();
            }else{
                if(z == z->getRoot()->getRight()){
                    z = z->getRoot();
                    rotateLeft(z);
                }else{
                    z->getRoot()->setColor(BLACK);
                    z->getRoot()->getRoot()->setColor(RED);
                    rotateRight(z->getRoot()->getRoot());
                }
            }
        }else{
            help = z->getRoot()->getRoot()->getLeft();
            if(help->getColor()==RED){
                z->getRoot()->setColor(BLACK);
                help->setColor(BLACK);
                z->getRoot()->getRoot()->setColor(RED);
                z = z->getRoot()->getRoot();
            }else{
                if(z == z->getRoot()->getLeft()){
                    z = z->getRoot();
                    rotateRight(z);
                }
                z->getRoot()->setColor(BLACK);
                z->getRoot()->getRoot()->setColor(RED);
                rotateLeft(z->getRoot()->getRoot());
            }
        }
    }
    this->root->setColor(BLACK);
}


void RedBlackTree::rotateLeft(Knoten* x){
    if(x->getRight()==this->nil){
        return;
    } else{
        Knoten* help;
        help = x->getRight();
        x->setRight(help->getLeft());
        if(help->getLeft()!=this->nil) {
            help->getLeft()->setRoot(x);
        }
        help->setRoot(x->getRoot());
        if(x->getRoot()==this->nil){
            //node is root
            this->root = help;
        }else{
            //node is left child
            if(x==x->getRoot()->getLeft()){
                x->getRoot()->setLeft(help);
            }else{
                //node is right child
                x->getRoot()->setRight(help);
            }
        }
        help->setLeft(x);
        x->setRoot(help);
    }
};

void RedBlackTree::rotateRight(Knoten* x){
    if(x->getLeft()==this->nil){
        return;
    } else{
        Knoten* help;
        help = x->getLeft();
        x->setLeft(help->getRight());
        if(help->getRight()!=this->nil) {
            help->getRight()->setRoot(x);
        }
        help->setRoot(x->getRoot());
        if(x->getRoot()==this->nil){
            //node is root
            this->root = help;
        }else{
            //node is left child
            if(x==x->getRoot()->getRight()){
                x->getRoot()->setRight(help);
            }else{
                //node is right child
                x->getRoot()->setLeft(help);
            }
        }
        help->setRight(x);
        x->setRoot(help);
    }
};

bool RedBlackTree::isRedBlack(Knoten* k) {
    /*
     A node is either red or black.
   */
    //The root is black.
    if(this->root->getColor()==RED){
        return false;
    }
    //All leaves (NIL) are black.(All leaves are same color as the root.)
    if((k->getKey()==-1) && (k->getColor()==RED)){
        return false;
    }
    //Every red node must have two black child nodes (and therefore it must have a black parent).
    if((k->getColor()==RED)){
        if((k->getLeft()->getColor() == RED) || (k->getRight()->getColor() == RED) ||
                (k->getRoot()->getColor() == RED)){
            return false;
        }
    }
    //Every path from a given node to any of its descendant NIL nodes contains the same number of black nodes.
    if(blackHeight(this->root)==0){
        return false;
    }
    return true;

}

int RedBlackTree::blackHeight(Knoten *k) {
    if (k == this->nil){
        return 1;
    }

    int leftBlackHeight = blackHeight(k->getLeft());
    if (leftBlackHeight == 0){
        return leftBlackHeight;
    }

    int rightBlackHeight = blackHeight(k->getRight());
    if (rightBlackHeight == 0){
        return rightBlackHeight;
    }

    if (leftBlackHeight != rightBlackHeight){
        return 0;
    } else{
        if(k->getColor()==BLACK){
            return leftBlackHeight + 1;
        } else{
            return leftBlackHeight + 0;
        }
    }

}

int RedBlackTree::height(){
    height(this->root);
}

int RedBlackTree::height(Knoten* v){
    if(v == this->nil){
        return -1;
    }
    return 1 + max(height(v->getLeft()), height(v->getRight()));
}

bool RedBlackTree::check(){
    return (check(this->root, INT_MIN, INT_MAX) && isRedBlack(this->root));
}

bool RedBlackTree::check(Knoten* v, int min, int max){
    //if tree empty or recursion end
    if(v==this->nil) {
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