//
//  Nodo23.h
//  Arboles
//
//  Created by Sebastian Medina  on 9/21/19.
//  Copyright © 2019 Sebastian Medina . All rights reserved.
//

#ifndef Nodo23_h
#define Nodo23_h


template <class T>
class Nodo23{
    bool hasSmall = false;
    bool hasHigh = false;
    bool full = false;
    T* lower = nullptr;
    T* higher = nullptr;
    T* auxMiddle = nullptr;
    Nodo23<T>* padre = nullptr;
    Nodo23<T>* left = nullptr;
    Nodo23<T>* middle = nullptr;
    Nodo23<T>* right = nullptr;
    Nodo23<T>* aux = nullptr;
public:
    Nodo23<T>():left(nullptr),middle(nullptr),right(nullptr),padre(nullptr),lower(nullptr),higher(nullptr),auxMiddle(nullptr),aux(nullptr){}
    Nodo23(T _smaller){
        lower = new T(_smaller);
        hasSmall = true;
    }
    virtual ~Nodo23(){
        left = middle = right = padre = aux = nullptr;
        lower = higher = nullptr;
    }
    
    Nodo23<T>* getTempChild()
    {
        return aux;
    }
    
    void setTempChild(Nodo23<T>* nodo)
    {
        aux = nodo;
    }
    
    T getTempMiddle()
    {
        return *auxMiddle;
    }
    
    void deleteTempMiddle()
    {
        if(auxMiddle)
        {
            auxMiddle = nullptr;
        }
    }
    
    void setAuxMiddle(T valor)
    {
        if(auxMiddle == nullptr)
        {
            auxMiddle = new T(valor);
        }
        else
        {
            *auxMiddle = valor;
        }
    }
    
    bool hasAuxMiddle()
    {
        if(auxMiddle)
            return true;
        else
            return false;
    }
    
    void setLower(T valor)
    {
        if(lower!=nullptr)
        {
            *lower = valor;
        }
        else
        {
            lower = new T(valor);
        }
    }
    
    void setHigher(T _value)
    {
        if(higher!=nullptr)
        {
            *higher = _value;
        }
        else
        {
            higher = new T(_value);
        }
    }
    
    T getLower()
    {
        return *lower;
    }
    
    T getHigher()
    {
        return *higher;
    }
    
    bool isFull()
    {
        if(higher && lower)
            return true;
        return false;
    }
    
    bool has3Keys()
    {
        return higher && lower && auxMiddle;
    }
    
    void setValue(T _value)
    {
        if(!lower)
        {
            lower = new T(_value);
        }
        else
        {
            if(_value >= *lower)
            {
                if(!higher)
                {
                    higher = new T(_value);
                }
            }
            else if(_value < *lower)
            {
                higher = new T(*lower);
                *lower = _value;
            }
        }
    }
    
    void deleteAllKeys()
    {
        if(lower)
            lower = nullptr;
        if(higher)
            higher = nullptr;
    }
    
    void setMiddleValue(T _value)
    {
        if(higher && lower)
        {
            if(!auxMiddle)
            {
                auxMiddle = new T(_value);
                if(_value < *lower)
                {
                    *auxMiddle = *lower;
                    *lower = _value;
                }
                else if(_value >= *lower && _value <= *higher)
                {
                    *auxMiddle = _value;
                }
                else
                {
                    *auxMiddle = *higher;
                    *higher = _value;
                }
            }
            else
            {
                if(_value < *lower)
                {
                    *auxMiddle = *lower;
                    *lower = _value;
                }
                else if(_value >= *lower && _value <= *higher)
                {
                    *auxMiddle = _value;
                }
                else
                {
                    *auxMiddle = *higher;
                    *higher = _value;
                }
            }
        }
    }
    
    void deleteHigher()
    {
        if(higher)
        {
            higher = nullptr;
        }
    }
    
    void deleteLower()
    {
        if(lower)
            lower = nullptr;
    }
    
    void swapHigherToLower()
    {
        if(!lower)
            lower = new T(*higher);
        else
            *lower = *higher;
        higher = nullptr;
    }
    
    
    bool hasLower(){
        if(lower==nullptr)
            return false;
        else
            return true;
    }
    
    bool hasHigher(){
        if(higher==nullptr)
            return false;
        else
            return true;
    }
    
    bool hasNoKeys()
    {
        return !lower && !higher;
    }
    
    Nodo23<T> * getLeft() const { return left; }
    void setLeft(Nodo23<T> * value) { left = value; }
    
    Nodo23<T> * getRight() const { return right; }
    void setRight(Nodo23<T> * value) { right = value; }
    
    Nodo23<T> * getMiddle() const { return middle; }
    void setMiddle(Nodo23<T> * value) { middle = value; }
    
    Nodo23<T> * getParent() const { return padre; }
    void setParent(Nodo23<T> * value) { padre = value; }
};

#endif /* Nodo23_h */
