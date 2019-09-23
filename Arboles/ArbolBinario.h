//
//  BinaryTree.h
//  Arboles
//
//  Created by Sebastian Medina  on 9/18/19.
//  Copyright © 2019 Sebastian Medina . All rights reserved.
//

//CÓDIGO PARA HACER EL ÁRBOL BINARIO

#ifndef BinaryTree_h
#define BinaryTree_h

#include "Nodo.h"
#include <iomanip>
#include <iostream>
using namespace std;

// DECLARACIÓN DE MÉTODOS

template<class T>
class ArbolBinario{
protected:
    Nodo<T> *raiz = nullptr;
    
public:
    ArbolBinario() {}
    virtual ~ArbolBinario();
    bool empty();
    void clear();
    void clear(Nodo<T> *nodo);
    
    Nodo<T> *getRaiz() const;
    void setRaiz(Nodo<T> *nodo);
    
    virtual Nodo<T> * insertar(T valor);
    virtual Nodo<T> * insertar(Nodo<T> * padre, Nodo<T> * nodo);
    
    void preOrder() const;
    void preOrder(Nodo<T> *node) const;
    void postOrder() const;
    void postOrder(Nodo<T> *node) const;
    
    // impresión descendente y ascendente
    void inOrder() const;
    void inOrder(Nodo<T> *nodo) const;
    void reverseInOrder() const;
    void reverseInOrder(Nodo<T> *nodo) const;
    
    // obtener si existe un predecesor
    void predecessor(Nodo<T> *nodo) const;
    
    //
    void leaf() const;
    void leaf(Nodo<T> *nodo) const;
    
    // obtener la altura
    int getAltura() const;
    int getAltura(Nodo<T> *nodo) const;
    
    // obtener la profundidad
    int getProfundidad() const;
    int getProfundidad(Nodo<T> *nodo) const;

    // obtener el nivel del nodo
    int getNivel() const;
    int getNivel(Nodo<T> *nodo) const;

    // saber si esta balanceado o no
    int balanceFactor() const;
    int balanceFactor(Nodo<T> *nodo) const;
    
    void print(Nodo<T> *print, int indent);
    
};

//MÉTODOS DEBAJO

template<class T>
ArbolBinario<T>::~ArbolBinario(){
    clear();
}

template<class T>
bool ArbolBinario<T>::empty(){
    return raiz == nullptr;
}

template<class T>
void ArbolBinario<T>::clear(){
    clear(raiz);
}

template<class T>
void ArbolBinario<T>::clear(Nodo<T> *nodo){
    if(nodo){
        clear(nodo->getLeft());
        clear(nodo->getRight());
        delete nodo;
    }
}

template<class T>
Nodo<T>* ArbolBinario<T>::getRaiz() const{
    return raiz;
}

template <class T>
void ArbolBinario<T>::setRaiz(Nodo<T> *nodo){
    raiz = nodo;
}

template <class T>
Nodo<T> * ArbolBinario<T>::insertar(T valor){
    Nodo<T> * nodo = new Nodo<T>(valor);
    return insertar(this->raiz, nodo);
}

//asignar un nodo en un lugar ya ocupado
template <class T>
Nodo<T> * ArbolBinario<T>::insertar(Nodo<T> * padre, Nodo<T> * nodo){
    if(empty())
    {
        setRaiz(nodo);
    }
    else{
        if(nodo->getData() < padre->getData()){
            if(padre->getLeft() == nullptr){
                padre->setLeft(nodo);
                nodo->setPadre(padre);
            } else{
                insertar(padre->getLeft(), nodo);
            }
        } else {
            if(padre->getRight() == nullptr){
                padre->setRight(nodo);
                nodo->setPadre(padre);
            } else{
                insertar(padre->getRight(), nodo);
            }
        }
    } return nodo;
}

template<class T>
void ArbolBinario<T>::preOrder() const{
    preOrder(raiz);
}

template<class T>
void ArbolBinario<T>::preOrder(Nodo<T> *nodo) const{
    if(nodo){
        cout << *nodo << ", ";
        preOrder(nodo->getLeft());
        preOrder(nodo->getRight());
    }
}

template<class T>
void ArbolBinario<T>::inOrder() const{
    inOrder(raiz);
}

template<class T>
void ArbolBinario<T>::inOrder(Nodo<T> *nodo) const{
    if(nodo){
        inOrder(nodo->getLeft());
        cout << *nodo << ", ";
        inOrder(nodo->getRight());
    }
}

template<class T>
void ArbolBinario<T>::reverseInOrder() const{
    reverseInOrder(raiz);
}

template<class T>
void ArbolBinario<T>::reverseInOrder(Nodo<T> *nodo) const{
    if(nodo){
        reverseInOrder(nodo->getRight());
        cout << *nodo << ", ";
        reverseInOrder(nodo->getLeft());
    }
}

template<class T>
void ArbolBinario<T>::postOrder() const{
    postOrder(raiz);
}

template<class T>
void ArbolBinario<T>::postOrder(Nodo<T> *nodo) const{
    if(nodo){
        preOrder(nodo->getLeft());
        preOrder(nodo->getRight());
        cout << *nodo << ", ";
    }
}

template<class T>
void ArbolBinario<T>::leaf() const{
    leaf(raiz);
}

template<class T>
void ArbolBinario<T>::leaf(Nodo<T> *nodo) const{
    if(nodo) {
        if(!nodo->getLeft() && !nodo->getRight()){
            cout << *nodo << endl;
        } else {
            leaf(nodo->getLeft());
            leaf(nodo->getRight());
        }
    }
}

template<class T>
void ArbolBinario<T>::predecessor(Nodo<T> *nodo) const{
    if(nodo){
        cout << *nodo << " - ";
        predecessor(nodo->getPadre());
    }
}

template<class T>
int ArbolBinario<T>::getAltura() const{
    return getAltura(raiz);
}

template<class T>
int ArbolBinario<T>::getAltura(Nodo<T> *nodo) const {
    if (!nodo) return -1;
    return 1 + max(getAltura(nodo->getLeft()), getAltura(nodo->getRight()));
}

template<class T>
int ArbolBinario<T>::getNivel() const{
    return getNivel(raiz);
}

template<class T>
int ArbolBinario<T>::getNivel(Nodo<T> *nodo) const{
    if(nodo == nullptr){
        return 0;
    }
    else {
        return getNivel(nodo->getPadre()) + 1;
    }
}

template<class T>
int ArbolBinario<T>::getProfundidad() const{
    return getProfundidad(raiz);
}

template<class T>
int ArbolBinario<T>::getProfundidad(Nodo<T> *nodo) const{
    return getNivel(nodo) - 1;
}

template<class T>
int ArbolBinario<T>::balanceFactor() const
{
    return balanceFactor(raiz);
}

template<class T>
int ArbolBinario<T>::balanceFactor(Nodo<T> *nodo) const{
    if (nodo){
        return getAltura(nodo->getRight()) - getAltura(nodo->getLeft());
    }
    return 0;
}

template<class T>
void ArbolBinario<T>::print(Nodo<T> *print, int indent){
    if(print != nullptr){
        if(print->getRight()){
            print(print->getRight(), indent+4);
        }
        if (indent)
        {
            cout << setw(indent) << ' ';
        }
        if (print->getRight()) cout<<" /\n" << setw(indent) << ' ';
        cout<< print->getInfo() << "\n ";
        if(print->getLeft())
        {
            cout << setw(indent) << ' ' <<" \\\n";
            print(print->getLeft(), indent+4);
        }
    }
}

#endif /* BinaryTree_h */
