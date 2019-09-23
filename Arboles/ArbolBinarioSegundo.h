//
//  BinaryTreeSecond.h
//  Arboles
//
//  Created by Sebastian Medina  on 9/18/19.
//  Copyright © 2019 Sebastian Medina . All rights reserved.
//

#ifndef BinaryTreeSecond_h
#define BinaryTreeSecond_h

#include "ArbolBinario.h"


template <class T>
class ArbolBinarioSegundo : public ArbolBinario<T>
{
public:
    ArbolBinarioSegundo();
    ~ArbolBinarioSegundo();
    
    Nodo<T> *buscar(const T valor) const;
    Nodo<T> *buscar(const T valor, Nodo<T> * nodo) const;
    
    Nodo<T> * insertar(T valor);
};

template <class T>
ArbolBinarioSegundo<T>::ArbolBinarioSegundo() : ArbolBinario<T>() {}

template <class T>
ArbolBinarioSegundo<T>::~ArbolBinarioSegundo(){}

template <class T>
Nodo<T> * ArbolBinarioSegundo<T>::buscar(const T valor) const{
    return buscar(valor, this->raiz);
}

template <class T>
Nodo<T> * ArbolBinarioSegundo<T>::buscar(const T valor, Nodo<T> * nodo)const
{
    if (nodo == nullptr)
    {
        return nullptr;
    }
    else {
        T nodoValor = nodo->getData();
        if (valor == nodoValor)
        {
            return nodo;
        }
        else if (valor < nodoValor)
        {
            return buscar(valor, nodo->getLeft());
        }
        else {
            return buscar(valor, nodo->getRight());
        }
    }
}

template <class T>
Nodo<T> * ArbolBinarioSegundo<T>::insertar(T valor)
{
    Nodo<T> * node = new Nodo<T>(valor);
    Nodo<T> * king;
    
    node->setRight(nullptr);
    node->setLeft(nullptr);
    
    king = node->getPadre();
    
    if(this->empty())
    {
        this->setRaiz(node);
    }
    else
    {
        Nodo<T> * actual = new Nodo<T>();
        actual = this->getRaiz();
        
        while (actual)
        {
            king = actual;
            
            if(node->getData() >= actual->getData())
            {
                actual = actual->getRight();
            }
            else
            {
                actual = actual->getLeft();
            }
        }
        
        if(node->getData() >= king->getData())
        {
            king->setRight(node);
            node->setPadre(king);
        }
        else
        {
            king->setLeft(node);
            node->setPadre(king);
        }
    }
    return node;
}


#endif /* BinaryTreeSecond_h */
