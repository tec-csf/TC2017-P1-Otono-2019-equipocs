//
//  23.h
//  Arboles
//
//  Created by Sebastian Medina  on 9/21/19.
//  Copyright © 2019 Sebastian Medina . All rights reserved.
//

#ifndef _3_h
#define _3_h
#include <iomanip>
#include <queue>
#include <iostream>
#include <vector>
#include "Nodo23.h"


template <class T>
class Arbol23 {
    
protected:
    Nodo23<T> * root = nullptr;
    std::vector<T> leafLevels;
    
public:
    Arbol23() {}
    ~Arbol23();
    
    bool empty();
    
    void clear();
    void clear(Nodo23<T> * node);
    
    Nodo23<T> * getRoot() const;
    void setRoot(const T element);
    void setRoot(Nodo23<T> * node);
    bool isRoot(Nodo23<T> * node);
    
    void insertar(T item);
    void insertar(Nodo23<T> * item);
    void insertar(Nodo23<T> * parent, Nodo23<T> * item);
    void insertar(Nodo23<T> * parent, T item);
    
    void inOrder(Nodo23<T> * node, int level);
    void inOrder();
    
    void reverseInOrder(Nodo23<T> * node, int level);
    void reverseInOrder();
    
    void forceRoot(Nodo23<T>* root);
    
    void redistributeChildren(Nodo23<T>* container, Nodo23<T>* n1, Nodo23<T>* n2);
    void split(Nodo23<T>* container);
    bool is2Node(Nodo23<T>* node);
    bool is3Node(Nodo23<T>* node);
    bool hasFreeChildren(Nodo23<T>* node);
    bool isTT ();
    bool isTT(Nodo23<T>* node);
    Nodo23<T>* buscarNodo(const T item, Nodo23<T> * node);
    
    Nodo23<T>* findNodeToDelete(Nodo23<T>*, T value);
    bool borrar(Nodo23<T>* node);
    bool borrar(T value);
    void fixTree(Nodo23<T>* node);
    Nodo23<T>* getInorderSuccesor(Nodo23<T>* node);
    
    void getLeafLevels(Nodo23<T>* node);
    bool getNodeKeys(Nodo23<T>* node);
    bool getNodeChildren(Nodo23<T>* node);
    bool findNode(Nodo23<T>*, T value);
    
    void isLeaf() ;
    bool isLeaf(Nodo23<T> * node) ;
    
    void ancestors(Nodo23<T> * node) const;
    
    int getAltura() const;
    int getAltura(Nodo23<T> * node) const ;
    
    int getProfundidad() const;
    int getProfundidad(Nodo23<T> * node) const;
    
    int getNivel() const;
    int getNivel(Nodo23<T> * node) const;
    
    void sort(T a[], int N);
    Nodo23<T>* buscarNodo(const T value);
};


template <class T>
Arbol23<T>::~Arbol23()
{
    clear();
}

template <class T>
bool Arbol23<T>::empty()
{
    return root == nullptr;
}

template <class T>
void Arbol23<T>::clear()
{
    clear(root);
}

template <class T>
void Arbol23<T>::clear(Nodo23<T> * node)
{
    if (node) {
        clear(node->getLeft());
        clear(node->getRight());
        delete node;
    }
}

template <class T>
Nodo23<T> * Arbol23<T>::getRoot() const
{
    return root;
}

template <class T>
void Arbol23<T>::setRoot(const T element)
{
    Nodo23<T> * node = new Nodo23<T>(element);
    setRoot(node);
}

template <class T>
void Arbol23<T>::setRoot(Nodo23<T> * node)
{
    if (!empty()) {
        node->setLeft(root);
        root->setParent(node);
        root = node;
    }
    else {
        root = node;
    }
}

template <class T>
bool Arbol23<T>::isRoot(Nodo23<T> * node){
    return node == this->root;
}

template <class T>
void Arbol23<T>::insertar(T item)
{
    insertar(this->root, item);
}

template <class T>
void Arbol23<T>::insertar(Nodo23<T> * item)
{
    insertar(this->root, item);
}

template <class T>
void Arbol23<T>::forceRoot(Nodo23<T>* node)
{
    root = node;
}

template <class T>
void Arbol23<T>::redistributeChildren(Nodo23<T>* container, Nodo23<T>* n1, Nodo23<T>* n2)
{
    n1->setLeft(container->getLeft());
    n1->setRight(container->getMiddle());
    n2->setLeft(container->getTempChild());
    n2->setRight(container->getRight());
    n1->getLeft()->setParent(n1);
    n1->getRight()->setParent(n1);
    n2->getLeft()->setParent(n2);
    n2->getRight()->setParent(n2);
}

template <class T>
void Arbol23<T>::split(Nodo23<T>* container)
{
    if(isRoot(container))
    {
        Nodo23<T>* newRoot = new Nodo23<T>(container->getTempMiddle());
        forceRoot(newRoot);
        Nodo23<T>* n1 = new Nodo23<T>(container->getLower());
        Nodo23<T>* n2 = new Nodo23<T>(container->getHigher());
        if(container->getTempChild()!=nullptr)
            redistributeChildren(container, n1, n2);
        newRoot->setLeft(n1);
        newRoot->setRight(n2);
        newRoot->getLeft()->setParent(newRoot);
        newRoot->getRight()->setParent(newRoot);
        delete container;
    }
    else if(container->getParent() != nullptr)
    {
        Nodo23<T>* parent = container->getParent();
        if(parent->isFull())
        {
            parent->setMiddleValue(container->getTempMiddle());
            if(parent->getRight() == container)
            {
                Nodo23<T>* n1 = new Nodo23<T>(container->getLower());
                Nodo23<T>* n2 = new Nodo23<T>(container->getHigher());
                if(container->getTempChild()!=nullptr)
                    redistributeChildren(container, n1, n2);
                parent->setRight(n2);
                parent->setTempChild(n1);
                parent->getRight()->setParent(parent);
                parent->getTempChild()->setParent(parent);
                delete container;
            }
            else if(parent->getLeft() == container)
            {
                Nodo23<T>* n1 = new Nodo23<T>(container->getLower());
                Nodo23<T>* n2 = new Nodo23<T>(container->getHigher());
                if(container->getTempChild()!=nullptr)
                    redistributeChildren(container, n1, n2);
                parent->setLeft(n1);
                parent->setTempChild(parent->getMiddle());
                parent->setMiddle(n2);
                parent->getLeft()->setParent(parent);
                parent->getMiddle()->setParent(parent);
                parent->getTempChild()->setParent(parent);
                delete container;
                
            }
            else
            {
                Nodo23<T>* n1 = new Nodo23<T>(container->getLower());
                Nodo23<T>* n2 = new Nodo23<T>(container->getHigher());
                if(container->getTempChild()!=nullptr)
                    redistributeChildren(container, n1, n2);
                parent->setMiddle(n1);
                parent->setTempChild(n2);
                parent->getMiddle()->setParent(parent);
                parent->getTempChild()->setParent(parent);
                delete container;
            }
            split(parent);
        }
        else
        {
            parent->setValue(container->getTempMiddle());
            if(parent->getRight() == container)
            {
                Nodo23<T>* n1 = new Nodo23<T>(container->getLower());
                Nodo23<T>* n2 = new Nodo23<T>(container->getHigher());
                if(container->getTempChild()!=nullptr)
                    redistributeChildren(container, n1, n2);
                parent->setRight(n2);
                parent->setMiddle(n1);
                parent->getRight()->setParent(parent);
                parent->getMiddle()->setParent(parent);
                delete container;
            }
            else if(parent->getLeft() == container)
            {
                Nodo23<T>* n1 = new Nodo23<T>(container->getLower());
                Nodo23<T>* n2 = new Nodo23<T>(container->getHigher());
                if(container->getTempChild()!=nullptr)
                    redistributeChildren(container, n1, n2);
                parent->setLeft(n1);
                parent->setMiddle(n2);
                parent->getLeft()->setParent(parent);
                parent->getMiddle()->setParent(parent);
                delete container;
            }
            if(parent->has3Keys())
                split(parent);
        }
    }
}

template <class T>
bool Arbol23<T>:: is2Node(Nodo23<T>* node)
{
    if((node->hasLower() && !node->hasHigher()) || (!node->hasLower() && node->hasHigher()))
        return true;
    else
        return false;
}

template <class T>
bool Arbol23<T>:: is3Node(Nodo23<T>* node)
{
    if(node->hasLower() && node->hasHigher())
        return true;
    else
        return false;
}

template <class T>
bool Arbol23<T>::hasFreeChildren(Nodo23<T>* node)
{
    if(node->getLeft() == nullptr || node->getMiddle() == nullptr || node->getRight() == nullptr)
        return true;
    else
        return false;
}

template <class T>
void Arbol23<T>::insertar(Nodo23<T> * parent, T item)
{
    Nodo23<T>* container = new Nodo23<T>();
    if(root == nullptr)
    {
        forceRoot(new Nodo23<T>(item));
        return;
    }
    container = buscarNodo(item, root);
    if(is2Node(container))
    {
        container->setValue(item);
        container->deleteTempMiddle();
    }
    else if(is3Node(container))
    {
        container->setMiddleValue(item);
        split(container);
    }
}

template <class T>
Nodo23<T>* Arbol23<T>::buscarNodo(const T value)
{
    return buscarNodo(value, root);
    
}

template <class T>
Nodo23<T>* Arbol23<T>::buscarNodo(const T value, Nodo23<T> * node)
{
    if(node == nullptr)
        return nullptr;
    if(isLeaf(node))
        return node;
    else if(is2Node(node))
    {
        if(value <= node->getLower())
            return buscarNodo(value, node->getLeft());
        else
            return buscarNodo(value, node->getRight());
    }
    else if(is3Node(node))
    {
        if(value <= node->getLower())
            return buscarNodo(value, node->getLeft());
        else if(value > node->getHigher())
            return buscarNodo(value, node->getRight());
        else
            return buscarNodo(value, node->getMiddle());
    }
    return node;
}

template <class T>
void Arbol23<T>::inOrder()
{
    inOrder(root, 0);
    std::cout << std::endl;
}

template <class T>
void Arbol23<T>::inOrder(Nodo23<T> * node, int lv)
{
    if(node == nullptr) return;
    if(isLeaf(node))
    {
        if(is2Node(node))
        {
            std::cout << node->getLower() << " "<< std::flush;
        }
        else if(is3Node(node))
        {
            std::cout << node->getLower() << " " << node->getHigher();
        }
    }
    else if(is2Node(node))
    {
        inOrder(node->getLeft(), lv);
        std::cout << node->getLower() << " "<< std::flush;
        inOrder(node->getRight(), lv);
    }
    else if(is3Node(node))
    {
        inOrder(node->getLeft(), lv);
        std::cout << node->getLower() << " "<< std::flush;
        inOrder(node->getMiddle(), lv);
        std::cout << node->getHigher() << " "<< std::flush;
        inOrder(node->getRight(), lv);
    }
}

template <class T>
void Arbol23<T>::reverseInOrder()
{
    reverseInOrder(root, 0);
    std::cout << std::endl;
}

template <class T>
void Arbol23<T>::reverseInOrder(Nodo23<T> * node, int lv)
{
    if(node == nullptr) return;
    if(isLeaf(node))
    {
        if(is2Node(node))
        {
            std::cout << node->getLower() << " "<< std::flush;
        }
        else if(is3Node(node))
        {
            std::cout << node->getHigher() << " " << node->getLower() << " ";
        }
    }
    else if(is2Node(node))
    {
        reverseInOrder(node->getRight(), lv);
        std::cout << node->getLower() << " "<< std::flush;
        reverseInOrder(node->getLeft(), lv);
    }
    else if(is3Node(node))
    {
        reverseInOrder(node->getRight(), lv);
        std::cout << node->getHigher() << " "<< std::flush;
        reverseInOrder(node->getMiddle(), lv);
        std::cout << node->getLower() << " "<< std::flush;
        reverseInOrder(node->getLeft(), lv);
    }
}


template <class T>
void Arbol23<T>::fixTree(Nodo23<T>* node)
{
    if(isRoot(node))
    {
        forceRoot(node->getMiddle());
        delete node;
    }
    else
    {
        bool threeKeys = false;
        Nodo23<T>* parent = node->getParent();
        if(is2Node(parent))
        {
            Nodo23<T>* sibling = new Nodo23<T>();
            if(parent->getRight() == node)
                sibling = parent->getLeft();
            else
                sibling = parent->getRight();
            if(parent->getRight() == node)
            {
                if(is3Node(parent->getLeft()))
                {
                    threeKeys = true;
                    T siblingLower = sibling->getLower();
                    T siblingHigher = sibling->getHigher();
                    T parentVal = parent->getLower();
                    T keys[3] = {siblingLower,siblingHigher,parentVal};
                    sort(keys,3);
                    T low = keys[0];
                    T mid = keys[1];
                    T high = keys[2];
                    node->setValue(high);
                    parent->deleteAllKeys();
                    parent->setValue(mid);
                    sibling->deleteAllKeys();
                    sibling->setValue(low);
                    
                    
                    if(!isLeaf(node))
                    {
                        node->setRight(node->getMiddle());
                        node->setMiddle(nullptr);
                        node->setLeft(sibling->getRight());
                        node->getLeft()->setParent(node);
                        sibling->setRight(sibling->getMiddle());
                        sibling->setMiddle(nullptr);
                    }
                }
            }
            else
            {
                if(is3Node(parent->getRight()))
                {
                    threeKeys = true;
                    T siblingLower = sibling->getLower();
                    T siblingHigher = sibling->getHigher();
                    T parentVal = parent->getLower();
                    T keys[3] = {siblingLower,siblingHigher,parentVal};
                    sort(keys,3);
                    T low = keys[0];
                    T mid = keys[1];
                    T high = keys[2];
                    node->setValue(low);
                    parent->deleteAllKeys();
                    parent->setValue(mid);
                    sibling->deleteAllKeys();
                    sibling->setValue(high);
                    
                    if(!isLeaf(node))
                    {
                        node->setLeft(node->getMiddle());
                        node->setMiddle(nullptr);
                        node->setRight(sibling->getLeft());
                        node->getRight()->setParent(node);
                        sibling->setLeft(sibling->getMiddle());
                        sibling->setMiddle(nullptr);
                    }
                }
            }
        }
        else if(is3Node(parent))
        {
            Nodo23<T>* sibling = new Nodo23<T>();
            if(parent->getRight() == node)
            {
                if(is3Node(parent->getMiddle()))
                {
                    threeKeys = true;
                    sibling = parent->getMiddle();
                    node->setValue(parent->getHigher());
                    parent->setHigher(sibling->getHigher());
                    sibling->deleteHigher();
                    if(!isLeaf(node))
                    {
                        node->setRight(node->getMiddle());
                        node->setLeft(sibling->getRight());
                        node->getLeft()->setParent(node);
                        sibling->setRight(sibling->getMiddle());
                        sibling->setMiddle(nullptr);
                    }
                }
            }
            else if(parent->getMiddle() == node)
            {
                if(is3Node(parent->getLeft()))
                {
                    threeKeys = true;
                    sibling = parent->getLeft();
                    node->setValue(parent->getLower());
                    parent->setLower(sibling->getHigher());
                    sibling->deleteHigher();
                    if(!isLeaf(node))
                    {
                        node->setRight(node->getMiddle());
                        node->setLeft(sibling->getRight());
                        node->getLeft()->setParent(node);
                        sibling->setRight(sibling->getMiddle());
                        sibling->setMiddle(nullptr);
                    }
                }
            }
            else
            {
                if(is3Node(parent->getMiddle()))
                {
                    threeKeys = true;
                    sibling = parent->getMiddle();
                    node->setValue(parent->getLower());
                    parent->setLower(sibling->getLower());
                    sibling->swapHigherToLower();
                    if(!isLeaf(node))
                    {
                        node->setLeft(node->getMiddle());
                        node->setRight(sibling->getLeft());
                        node->getRight()->setParent(node);
                        sibling->setLeft(sibling->getMiddle());
                        sibling->setMiddle(nullptr);
                    }
                }
            }
        }
        if(!threeKeys)
        {
            Nodo23<T>* sibling = new Nodo23<T>();
            if(is2Node(parent))
            {
                if(parent->getRight() == node)
                {
                    sibling = parent->getLeft();
                    sibling->setValue(parent->getLower());
                    if(!isLeaf(node))
                    {
                        sibling->setMiddle(sibling->getRight());
                        sibling->setRight(node->getMiddle());
                    }
                    parent->setMiddle(sibling);
                    parent->getMiddle()->setParent(parent);
                    parent->setLeft(nullptr);
                    parent->setRight(nullptr);
                    parent->deleteAllKeys();
                    delete node;
                }
                else
                {
                    sibling = parent->getRight();
                    sibling->setValue(parent->getLower());
                    if(!isLeaf(node))
                    {
                        sibling->setMiddle(sibling->getLeft());
                        sibling->setLeft(node->getMiddle());
                        sibling->getLeft()->setParent(sibling);
                    }
                    parent->setMiddle(sibling);
                    parent->getMiddle()->setParent(parent);
                    parent->setLeft(nullptr);
                    parent->setRight(nullptr);
                    parent->deleteAllKeys();
                    delete node;
                }
            }
            else if(is3Node(parent))
            {
                if(parent->getRight() == node)
                {
                    sibling = parent->getMiddle();
                    sibling->setValue(parent->getHigher());
                    if(!isLeaf(node))
                    {
                        sibling->setMiddle(sibling->getRight());
                        sibling->setRight(node->getMiddle());
                        sibling->getRight()->setParent(sibling);
                    }
                    parent->setRight(sibling);
                    parent->getRight()->setParent(parent);
                    parent->setMiddle(nullptr);
                    parent->deleteHigher();
                    delete node;
                }
                else if(parent->getMiddle() == node)
                {
                    sibling = parent->getLeft();
                    sibling->setValue(parent->getLower());
                    if(!isLeaf(node))
                    {
                        sibling->setMiddle(sibling->getRight());
                        sibling->setRight(node->getMiddle());
                        sibling->getRight()->setParent(sibling);
                    }
                    parent->setLeft(sibling);
                    parent->getLeft()->setParent(parent);
                    parent->setMiddle(nullptr);
                    parent->deleteLower();
                    parent->swapHigherToLower();
                    delete node;
                }
                else
                {
                    sibling = parent->getMiddle();
                    sibling->setValue(parent->getLower());
                    if(!isLeaf(node))
                    {
                        sibling->setMiddle(sibling->getLeft());
                        sibling->setLeft(node->getMiddle());
                        sibling->getLeft()->setParent(sibling);
                    }
                    parent->setLeft(sibling);
                    parent->getLeft()->setParent(parent);
                    parent->setMiddle(nullptr);
                    parent->deleteLower();
                    parent->swapHigherToLower();
                    delete node;
                }
            }
            if(parent->hasNoKeys())
            {
                sibling->setParent(parent);
                fixTree(parent);
            }
        }
    }
}

template <class T>
bool Arbol23<T>::borrar(T value)
{
    Nodo23<T>* node = new Nodo23<T>();
    node = findNodeToDelete(root, value);
    if(node)
    {
        Nodo23<T>* leafNode = new Nodo23<T>();
        if(!isLeaf(node))
        {
            leafNode = getInorderSuccesor(node);
            T swapVal = leafNode->getLower();
            node->setLower(swapVal);
        }
        else
        {
            if(node->getHigher() == value)
            {
                node->deleteHigher();
                return true;
            }
        }
        leafNode->deleteLower();
        if(leafNode->hasNoKeys())
        {
            fixTree(leafNode);
        }
        return true;
    }
    else
        return false;
}

template <class T>
Nodo23<T>* Arbol23<T>::getInorderSuccesor(Nodo23<T>* node)
{
    if (node)
    {
        Nodo23<T> * workingNode = node->getLeft();
        if(workingNode){
            while (workingNode->getRight() != nullptr)
            {
                workingNode = workingNode->getRight();
            }
            return workingNode;
        }
        return nullptr;
        
    } else{
        return nullptr;
    }
}

template <class T>
Nodo23<T>* Arbol23<T>::findNodeToDelete(Nodo23<T>* node, T value)
{
    if(node == nullptr)
        return nullptr;
    if(isLeaf(node))
    {
        if(is2Node(node))
        {
            if(node->getLower() == value)
            {
                return node;
            }
        }
        else if(is3Node(node))
        {
            if(node->getLower() == value || node->getHigher() == value)
            {
                return node;
            }
        }
        return nullptr;
    }
    else if(is2Node(node))
    {
        if(value == node->getLower())
        {
            return node;
        }
        
        if(value < node->getLower())
            return findNodeToDelete(node->getLeft(), value);
        else
            return findNodeToDelete( node->getRight(), value);
    }
    else if(is3Node(node))
    {
        if(node->getLower() == value || node->getHigher() == value)
        {
            return node;
        }
        if(value < node->getLower())
            return findNodeToDelete(node->getLeft(), value);
        else if(value > node->getHigher())
            return findNodeToDelete(node->getRight(), value);
        else
            return findNodeToDelete(node->getMiddle(), value);
    }
    return nullptr;
}

template <class T>
bool Arbol23<T>::findNode(Nodo23<T>* node, T value)
{
    if(node == nullptr)
        return false;
    if(isLeaf(node))
    {
        if(is2Node(node))
        {
            if(node->getLower() == value)
            {
                return true;
            }
        }
        else if(is3Node(node))
        {
            if(node->getLower() == value || node->getHigher() == value)
            {
                return true;
            }
        }
        return false;
    }
    else if(is2Node(node))
    {
        if(value == node->getLower())
        {
            return true;
        }
        
        if(value < node->getLower())
            return findNode(node->getLeft(), value);
        else
            return findNode( node->getRight(), value);
    }
    else if(is3Node(node))
    {
        if(node->getLower() == value || node->getHigher() == value)
        {
            return true;
        }
        if(value < node->getLower())
            return findNode(node->getLeft(), value);
        else if(value > node->getHigher())
            return findNode(node->getRight(), value);
        else
            return findNode(node->getMiddle(), value);
    }
    return false;
}

template <class T>
bool Arbol23<T>::isTT()
{
    return isTT(root);
}

template <class T>
bool Arbol23<T>::isTT(Nodo23<T>* node)
{
    leafLevels.clear();
    getLeafLevels(root);
    T cmp = leafLevels[0];
    bool leafs = true;
    for(int i=1; i<leafLevels.size(); i++)
    {
        if(leafLevels[i] != cmp)
            leafs = false;
    }
    return leafs;
}

template <class T>
void Arbol23<T>::getLeafLevels(Nodo23<T>* node)
{
    if(node == nullptr) return;
    if(isLeaf(node))
    {
        leafLevels.push_back(getNivel(node));
    }
    else if(is2Node(node))
    {
        getLeafLevels(node->getLeft());
        getLeafLevels(node->getRight());
    }
    else if(is3Node(node))
    {
        getLeafLevels(node->getLeft());
        getLeafLevels(node->getMiddle());
        getLeafLevels(node->getRight());
    }
}

template <class T>
void Arbol23<T>::isLeaf()
{
    isLeaf(root);
}

template <class T>
bool Arbol23<T>::isLeaf(Nodo23<T> * node)
{
    if(node->getLeft() == nullptr && node->getMiddle() == nullptr && node->getRight() == nullptr)
        return true;
    else
        return false;
}

template <class T>
void Arbol23<T>::ancestors(Nodo23<T> * node) const
{
    if (node) {
        std::cout << *node << " -> ";
        ancestors(node->getParent());
    }
}

template <class T>
int Arbol23<T>::getAltura() const
{
    return getAltura(root);
}

template <class T>
int Arbol23<T>::getAltura(Nodo23<T> * node) const
{
    if (!node) return -1;
    return 1 + std::max(getAltura(node->getLeft()), getAltura(node->getRight()));
}

template <class T>
int Arbol23<T>::getProfundidad() const
{
    return getProfundidad(root);
}

template <class T>
int Arbol23<T>::getProfundidad(Nodo23<T> * node) const
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        return getProfundidad(node->getParent())+1;
    }
}

template <class T>
int Arbol23<T>::getNivel() const
{
    return getNivel(root);
}

template <class T>
int Arbol23<T>::getNivel(Nodo23<T> * node) const
{
    int level = 0;
    while (node != nullptr && node->getParent() != nullptr) {
        level++;
        node = node->getParent();
    }
    return level;
}

template <class T>
void Arbol23<T>::sort(T a[], int N)
{
    int i, j, flag = 1;
    int temp;
    int numLength = N;
    for(i = 1; (i <= numLength) && flag; i++)
    {
        flag = 0;
        for (j=0; j < (numLength -1); j++)
        {
            if (a[j+1] < a[j])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
    }
    return;
}

#endif /* _3_h */
