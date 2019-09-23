//
//  RojiBlanco.h
//  Arboles
//
//  Created by Sebastian Medina  on 9/19/19.
//  Copyright © 2019 Sebastian Medina . All rights reserved.
//

#ifndef RojiBlanco_h
#define RojiBlanco_h
#include "ArbolBinarioSegundo.h"
using namespace std;

template<class T>
class RojiNegro : public ArbolBinarioSegundo<T>{
public:
    RojiNegro();
    
    Nodo<T> *padre(Nodo<T> * nodo);
    Nodo<T> *hijo(Nodo<T> * nodo);
    Nodo<T> *nieto(Nodo<T> * nodo);
    Nodo<T> *maximo(Nodo<T> * nodo);
    
    string color(Nodo<T> * nodo);
    
    void girarLeft(Nodo<T> * nodo);
    void girarRight(Nodo<T> * nodo);

    void insertarRB(T valor);
    void insertarCaso1(Nodo<T> * nodo);
    void insertarCaso2(Nodo<T> * nodo);
    void insertarCaso3(Nodo<T> * nodo);
    void insertarCaso4(Nodo<T> * nodo);
    void insertarCaso5(Nodo<T> * nodo);

    void borrarRB(T valor);
    void borrarCaso1(RojiNegro * arbol, Nodo<T> * nodo);
    void borrarCaso2(RojiNegro * arbol, Nodo<T> * nodo);
    void borrarCaso3(RojiNegro * arbol, Nodo<T> * nodo);
    void borrarCaso4(RojiNegro * arbol, Nodo<T> * nodo);
    void borrarCaso5(RojiNegro * arbol, Nodo<T> * nodo);
    void borrarCaso6(RojiNegro * arbol, Nodo<T> * nodo);
    
};

template<class T>
RojiNegro<T>::RojiNegro() : ArbolBinarioSegundo<T>() {}

template<class T>
Nodo<T> * RojiNegro<T>::padre(Nodo<T> * nodo){
    if(nodo != nullptr && nodo->getPadre() != nullptr)
        return nodo->getPadre()->getPadre();
    else
        return nullptr;
}

template<class T>
Nodo<T> * RojiNegro<T>::hijo(Nodo<T> * nodo)
{
    Nodo<T> * abuelo = padre(nodo);
    
    if(abuelo == nullptr)
        return nullptr;
    else if(nodo->getPadre() == abuelo->getLeft())
        return abuelo->getRight();
    else
        return abuelo->getLeft();
}

template<class T>
Nodo<T> * RojiNegro<T>::nieto(Nodo<T> * nodo)
{
    if(nodo != nullptr && nodo->getPadre() != nullptr)
    {
        if(nodo == nodo->getPadre()->getLeft())
            return nodo->getPadre()->getRight();
        else
            return nodo->getPadre()->getLeft();
    }
    else
        return nullptr;
}

template<class T>
Nodo<T> * RojiNegro<T>::maximo(Nodo<T> * nodo)
{
    while (nodo->getRight() != nullptr)
    {
        nodo = nodo->getRight();
    }
    return nodo;
}

template<class T>
string RojiNegro<T>::color(Nodo<T> * nodo)
{
    if(nodo == nullptr)
        return "negro";
    else
        return nodo->getColor();
}

template<class T>
void RojiNegro<T>::girarLeft(Nodo<T> * left)
{
    Nodo<T> *right;
    
    if(left->getRight() == nullptr)
    {
        return;
    }
    
    right = left->getRight();
    
    if(right->getLeft() != nullptr)
    {
        right->getLeft()->setPadre(left);
        left->setRight(right->getLeft());
    }
    
    right->setPadre(left->getPadre());
    
    if(left->getPadre() == nullptr)
    {
        this->setRaiz(right);
    }
    else if(left == left->getPadre()->getLeft())
    {
        left->getPadre()->setLeft(right);
    }
    else{
        
        left->getPadre()->setRight(right);
    }
    
    left->setRight(right->getLeft());
    right->setLeft(left);
    left->setPadre(right);
}

template<class T>
void RojiNegro<T>::girarRight(Nodo<T> * right)
{
    Nodo<T> *left;
    
    if(right->getLeft() == nullptr)
    {
        return;
    }
    
    left = right->getLeft();
    
    if(left->getRight() != nullptr)
    {
        left->getRight()->setPadre(right);
        right->setLeft(left->getRight());
    }
    
    left->setPadre(right->getPadre());
    
    if(right->getPadre() == nullptr)
    {
        this->setRaiz(left);
    }
    else if(right == right->getPadre()->getLeft())
    {
        right->getPadre()->setLeft(left);
    }
    else
    {
        right->getPadre()->setRight(left);
    }
    
    right->setLeft(left->getRight());
    left->setRight(right);
    right->setPadre(left);
}


template<class T>
void RojiNegro<T>::insertarRB(T valor)
{
    Nodo<T> * nodo = this->insertar(valor);
    nodo->setColor("rojo");
    if(nodo->getPadre() == nullptr)
        nodo->setColor("negro");
    else
    {
        if(nodo->getPadre()->getColor() == "negro")
            return;
        else
        {
            if(color(hijo(nodo)) == "rojo")
            {
                nodo->getPadre()->setColor("negro");
                hijo(nodo)->setColor("negro");
                padre(nodo)->setColor("rojo");
                insertarCaso1(padre(nodo));
            }
            else
            {
                if(nodo == nodo->getPadre()->getRight() && nodo->getPadre() == padre(nodo)->getLeft())
                {
                    girarLeft(nodo->getPadre());
                    nodo = nodo->getLeft();
                }
                else if(nodo == nodo->getPadre()->getLeft() && nodo->getPadre() == padre(nodo)->getRight())
                {
                    girarRight(nodo->getPadre());
                    nodo = nodo->getRight();
                }
                nodo->getPadre()->setColor("negro");
                padre(nodo)->setColor("rojo");
                if (nodo == nodo->getPadre()->getLeft() && nodo->getPadre() == padre(nodo)->getLeft())
                {
                    girarRight(padre(nodo));
                }
                else
                {
                    girarLeft(padre(nodo));
                }
            }
        }
    }
    //verifyProperties();
}

template<class T>
void RojiNegro<T>::insertarCaso1(Nodo<T> * nodo)
{
    if(nodo->getPadre() == nullptr)
        nodo->setColor("negro");
    else
        insertarCaso2(nodo);
}

template<class T>
void RojiNegro<T>::insertarCaso2(Nodo<T> * nodo)
{
    if(nodo->getPadre()->getColor() == "negro")
        return;
    else
        insertarCaso3(nodo);
}

template<class T>
void RojiNegro<T>::insertarCaso3(Nodo<T> * nodo)
{
    if(color(hijo(nodo)) == "rojo")
    {
        nodo->getPadre()->setColor("negro");
        hijo(nodo)->setColor("negro");
        padre(nodo)->setColor("rojo");
        insertarCaso1(padre(nodo));
    }
    else
    {
        insertarCaso4(nodo);
    }
}

template<class T>
void RojiNegro<T>::insertarCaso4(Nodo<T> * nodo)
{
    if(nodo == nodo->getPadre()->getRight() && nodo->getPadre() == padre(nodo)->getLeft())
    {
        girarLeft(nodo->getPadre());
        nodo = nodo->getLeft();
    }
    else if(nodo == nodo->getPadre()->getLeft() && nodo->getPadre() == padre(nodo)->getRight())
    {
        girarRight(nodo->getPadre());
        nodo = nodo->getRight();
    }
    insertarCaso5(nodo);
}

template<class T>
void RojiNegro<T>::insertarCaso5(Nodo<T> * nodo)
{
    nodo->getPadre()->setColor("negro");
    padre(nodo)->setColor("rojo");
    if (nodo == nodo->getPadre()->getLeft() && nodo->getPadre() == padre(nodo)->getLeft())
    {
        girarRight(padre(nodo));
    }
    else
    {
        girarLeft(padre(nodo));
    }
}

template <class T>
void RojiNegro<T>::borrarRB(T valor)
{
    Nodo<T> * hijo;
    Nodo<T> * nodo;
    nodo = this->buscar(valor);
    if (nodo == nullptr)
        return;
    
    if (nodo->getLeft() != nullptr && nodo->getRight() != nullptr)
    {
        Nodo<T> * pred = maximo(nodo->getLeft());
        nodo->setData(pred->getData());
        nodo = pred;
    }
    hijo = nodo->getRight() == nullptr ? nodo->getLeft()  : nodo->getRight();
    if (color(nodo) == "negro")
    {
        nodo->getColor() = color(hijo);
        borrarCaso1(this, nodo);
    }
    
    
    if (nodo->getPadre() == nullptr)
    {
        this->setRaiz(hijo);
    }
    else
    {
        if (nodo == nodo->getPadre()->getLeft())
            nodo->getPadre()->setLeft(hijo);
        else
            nodo->getPadre()->setRight(hijo);
    }
    if (hijo != nullptr)
    {
        hijo->setPadre(nodo->getPadre());
    }
    delete nodo;
    //verifyProperties();
}

template <class T>
void RojiNegro<T>::borrarCaso1(RojiNegro * arbol, Nodo<T> * nodo)
{
    if(nodo->getPadre() == nullptr)
        return;
    else
        borrarCaso2(this, nodo);
}

template <class T>
void RojiNegro<T>::borrarCaso2(RojiNegro * arbol, Nodo<T> * nodo)
{
    if (color(nieto(nodo)) == "rojo")
    {
        nodo->getPadre()->setColor("rojo");
        nieto(nodo)->setColor("negro");
        if (nodo == nodo->getPadre()->getLeft())
            girarLeft(nodo->getPadre());
        else
            girarRight(nodo->getPadre());
    }
    borrarCaso3(this, nodo);
}

template <class T>
void RojiNegro<T>::borrarCaso3(RojiNegro * arbol, Nodo<T> * nodo)
{
    if (color(nodo->getPadre()) == "negro" && color(nieto(nodo)) == "negro" &&
        color(nieto(nodo)->getLeft()) == "negro" && color(nieto(nodo)->getRight()) == "negro")
    {
        nieto(nodo)->setColor("rojo");
        borrarCaso1(this, nodo->getPadre());
    }
    else
        borrarCaso4(this, nodo);
}

template <class T>
void RojiNegro<T>::borrarCaso4(RojiNegro * arbol, Nodo<T> * nodo)
{
    if (color(nodo->getPadre()) == "rojo" && color(nieto(nodo)) == "negro" &&
        color(nieto(nodo)->getLeft()) == "negro" && color(nieto(nodo)->getRight()) == "negro")
    {
        nieto(nodo)->setColor("rojo");
        nodo->getPadre()->setColor("negro");
    }
    else
        borrarCaso5(this, nodo);
}

template <class T>
void RojiNegro<T>::borrarCaso5(RojiNegro * arbol, Nodo<T> * nodo)
{
    if (nodo == nodo->getPadre()->getLeft() && color(nieto(nodo)) == "negro" &&
        color(nieto(nodo)->getLeft()) == "rojo" && color(nieto(nodo)->getRight()) == "negro")
    {
        nieto(nodo)->setColor("rojo");
        nieto(nodo)->getLeft()->setColor("negro");
        girarRight(nieto(nodo));
    }
    else if (nodo == nodo->getPadre()->getRight() && color(nieto(nodo)) == "negro" &&
             color(nieto(nodo)->getRight()) == "rojo" && color(nieto(nodo)->getLeft()) == "negro")
    {
        nieto(nodo)->setColor("rojo");
        nieto(nodo)->getRight()->setColor("negro");
        girarLeft(nieto(nodo));
    }
    borrarCaso6(this, nodo);
}

template <class T>
void RojiNegro<T>::borrarCaso6(RojiNegro * arbol, Nodo<T> * nodo)
{
    nieto(nodo)->setColor(color(nodo->getPadre()));
    nodo->getPadre()->setColor("negro");
    if (nodo == nodo->getPadre()->getLeft())
    {
        nieto(nodo)->getRight()->setColor("negro");
        girarLeft(nodo->getPadre());
    }
    else
    {
        nieto(nodo)->getLeft()->setColor("negro");
        girarRight(nodo->getPadre());
    }
}




#endif /* RojiBlanco_h */
