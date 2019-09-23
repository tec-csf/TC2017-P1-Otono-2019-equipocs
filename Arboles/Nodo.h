//
//  Nodo.h
//  Arboles
//
//  Created by Sebastian Medina  on 9/18/19.
//  Copyright © 2019 Sebastian Medina . All rights reserved.
//

#ifndef Nodo_h
#define Nodo_h

using namespace std;
#include <iostream>

template<class T>
class Nodo{
protected:
    
    Nodo<T> *padre = nullptr;//Nodo padre
    Nodo<T> *left = nullptr;//Nodo hijo izquierda
    Nodo<T> *right = nullptr;//Nodo hijo derecha
    string color;//variable para RojiBlanco.h
    T data;

public:
    
    Nodo(){ } // constructor1
    Nodo(const T & _data) : data (_data) {} // constructor2
    Nodo(const Nodo<T> &); // constructor3
    
    virtual ~Nodo(); // clase abstracta
    
    //setters y getters
    
    T getData() const{ return data; }
    void setData(const T & valor){ data = valor; }
    
    Nodo<T> * getLeft() const{
        return left;
    }
    
    void setLeft(Nodo<T> *valor){
        left = valor;
    }
    
    Nodo<T> * getRight() const{
        return right;
    }
    
    void setRight(Nodo<T> *valor){
        right = valor;
    }
    
    Nodo<T> * getPadre() const{
        return padre;
    }
    
    void setPadre(Nodo<T> *valor){
        padre = valor;
    }
    
    void setColor(string color);
    string getColor();

    
    // Overloading Binary Operator
    template<typename Tn>
    friend ostream& operator<< (std::ostream & os, const Nodo<Tn>  & nodo);
    
};

// método para asignar color
template<class T>
void Nodo<T>::setColor(string color){
    this->color=color;
}

// método para obtener color
template<class T>
string Nodo<T>::getColor(){
    return color;
}

template<class T>
Nodo<T>::Nodo(const Nodo<T> & mas){
    data = mas.data;
    left = mas.left;
    right = mas.right;
    padre = mas.padre;
}

// método de clase abstracta
template<class T>
Nodo<T>::~Nodo(){
    data.~T();
    left = right = padre = nullptr;
}

// método de Overloading Binary Operator
template<class T>
ostream & operator <<(ostream & os, const Nodo<T>  & nodo){
    os << nodo.data;
    return os;
}


#endif /* Nodo_h */


