//
//  AVL.h
//  Arboles
//
//  Created by Sebastian Medina  on 9/18/19.
//  Copyright © 2019 Sebastian Medina . All rights reserved.
//

#ifndef AVL_h
#define AVL_h
#include "ArbolBinarioSegundo.h"

template<class T>
class AVL : public ArbolBinarioSegundo<T>{
public:
    AVL(){}
    ~AVL();
    
    /*MOVIMIENTOS DEL BALANCEO
    LL = LEFT LEFT
    RR = RIGHT RIGHT
    LR = LEFT RIGHT
    RL = RIGHT LEFT
    */
    void LL(Nodo<T> *nodo);
    void RR(Nodo<T> *nodo);
    void LR(Nodo<T> *nodo);
    void RL(Nodo<T> *nodo);
    Nodo<T> * insertar(Nodo<T> *padre, Nodo<T> *nodo);
    Nodo<T> * insertar(T valor);
    void borrar(T valor);
    
    Nodo<T> * getMaxMin(Nodo<T> * nodo) const;
    Nodo<T> * getMaxMin() const;

};

template <class T>
AVL<T>::~AVL(){ }



template <class T>
void AVL<T>::LL(Nodo<T> * pivote){
    Nodo<T> * aux = pivote->getRight();
    
    if(pivote->getPadre() && pivote->getData() <= pivote->getPadre()->getData()){
        pivote->getPadre()->setLeft(aux);
    } else if (pivote->getPadre()){
        pivote->getPadre()->setRight(aux);
    } else {
        this->setRaiz(aux);
    }
    
    aux->setPadre(pivote->getPadre());
    pivote->setPadre(aux);
    pivote->setRight(aux->getLeft());
    aux->setLeft(pivote);
    
    if(pivote->getRight()){
        pivote->getRight()->setPadre(pivote);
    }
}

template <class T>
void AVL<T>::RR(Nodo<T> * pivote){
    Nodo<T> * aux = pivote->getLeft();
    
    if(pivote->getPadre() && pivote->getData() <= pivote->getPadre()->getData()){
        pivote->getPadre()->setLeft(aux);
    } else if (pivote->getPadre()){
        pivote->getPadre()->setRight(aux);
    } else {
        this->setRaiz(aux);
    }
    
    aux->setPadre(pivote->getPadre());
    pivote->setPadre(aux);
    pivote->setLeft(aux->getRight());
    aux->setRight(pivote);
    
    if(pivote->getLeft()){
        pivote->getLeft()->setPadre(pivote);
    }
    
}

template <class T>
void AVL<T>::LR(Nodo<T> * pivote){
    Nodo<T> * aux = pivote->getRight();
    LL(pivote);
    RR(aux->getPadre());
}

template <class T>
void AVL<T>::RL(Nodo<T> * pivote){
    Nodo<T> * aux = pivote->getLeft();
    RR(pivote);
    LL(aux->getPadre());
}

template <class T>
Nodo<T> * AVL<T>::insertar(Nodo<T> *padre, Nodo<T> *nodo){
    if (this->empty())
    {
        this->setRaiz(nodo);
    }
    else
    {
        if(nodo->getData() < padre->getData())
        {
            
            if (padre->getLeft() == nullptr)
            {
                padre->setLeft(nodo);
                nodo->setPadre(padre);
                
            }
            else
            {
                insertar(padre->getLeft(), nodo);
            }
        }
        else if(nodo->getData() > padre->getData()){
            if(padre->getRight() == nullptr){
                padre->setRight(nodo);
                nodo->setPadre(padre);
            } else {
                insertar(padre->getRight(), nodo);
            }
        } else {
            return nullptr;
        }
        
        if(this->balanceFactor(padre->getPadre()) == -2 && this->balanceFactor(padre->getPadre()->getLeft())== -1){
            RR(padre->getPadre());
        }
        if(this->balanceFactor(padre->getPadre()) == -2 && this->balanceFactor(padre->getPadre()->getLeft())== 1){
            LR(padre);
        }
        if(this->balanceFactor(padre->getPadre()) == 2 && this->balanceFactor(padre->getPadre()->getRight())== 1){
            LL(padre->getPadre());
        }
        if(this->balanceFactor(padre->getPadre()) == 2 && this->balanceFactor(padre->getPadre()->getRight())== -1){
            RL(padre);
        }
        
    }
    return nodo;
}

template <class T>
Nodo<T> * AVL<T>::insertar(T valor)
{
    Nodo<T> * nodo = new Nodo<T>(valor);
    return insertar(this->raiz, nodo);
}

template <class T>
void AVL<T>::borrar(T valor)
{
    Nodo<T> * nodo = this->buscar(valor);
        
    if(nodo != nullptr)
    {
        Nodo<T> * padre = nodo->getPadre();
        Nodo<T> * newNode = getMaxMin(nodo);
        
        if(newNode)
        {
            newNode->setRight(nodo->getRight());
            if(newNode->getRight())
            {
                newNode->getRight()->setPadre(newNode);
            }
            newNode->getPadre()->setRight(newNode->getLeft());
            newNode->setPadre(nodo->getPadre());
            
            if(nodo->getLeft() == newNode)
            {
                if(!newNode->getLeft())
                {
                    newNode->setLeft(nullptr);
                }
            }
            else
            {
                newNode->setLeft(nodo->getLeft());
            }
        }
        
        if(!nodo->getPadre())
        {
            ArbolBinario<T>::setRaiz(newNode);
        }
        else if(nodo->getData() <= nodo->getPadre()->getData())
        {
            nodo->getPadre()->setLeft(newNode);
        }
        else
        {
            nodo->getPadre()->setRight(newNode);
        }
        
        delete nodo;
        cout << " " << endl;
        cout << "Valor borrado" << endl;
        cout << " " << endl;
        
        if(this->balanceFactor(padre) == -2 && this->balanceFactor(padre->getLeft()) == -1)
        {
            RR(padre);
        }
        if(this->balanceFactor(padre) == -2 && this->balanceFactor(padre->getLeft())== 1)
        {
            LR(padre->getLeft());
        }
        if(this->balanceFactor(padre) == 2 && this->balanceFactor(padre->getRight())== 1)
        {
            LL(padre);
        }
        if( (this->balanceFactor(padre) == 2 && this->balanceFactor(padre->getRight())== -1))
        {
            RL(padre->getRight());
        }
        padre =  padre->getPadre();
        
        
        if(this->balanceFactor(newNode) == -2 && this->balanceFactor(newNode->getLeft()) == -1)
        {
            RR(newNode);
        }
        if(this->balanceFactor(newNode) == -2 && this->balanceFactor(newNode->getLeft())== 1)
        {
            LR(newNode->getLeft());
        }
        if(this->balanceFactor(newNode) == 2 && this->balanceFactor(newNode->getRight())== 1)
        {
            LL(newNode);
        }
        if(this->balanceFactor(newNode) == 2 && this->balanceFactor(newNode->getRight())== -1)
        {
            RL(newNode->getRight());
        }
    } else {
        cout << " " << endl;
        cout << "El valor que ingresaste no existe" << endl;
        cout << " " << endl;
    }
}

template <class T>
Nodo<T> * AVL<T>::getMaxMin() const
{
    return getMaxMin(this->raiz);
}

template <class T>
Nodo<T> * AVL<T>::getMaxMin(Nodo<T> * nodo) const
{
    if (nodo)
    {
        Nodo<T> * workingNode = nodo->getLeft();
        if(workingNode)
        {
            while (workingNode->getRight() != nullptr)
            {
                workingNode = workingNode->getRight();
            }
            return workingNode;
        }
        return nullptr;
    }
    else
    {
        return nullptr;
    }
}

#endif /* AVL_h */
