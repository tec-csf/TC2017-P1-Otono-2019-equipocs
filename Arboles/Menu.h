//
//  Menu.h
//  Arboles
//
//  Created by Sebastian Medina  on 9/19/19.
//  Copyright © 2019 Sebastian Medina . All rights reserved.
//

#ifndef Menu_h
#define Menu_h
#include <iostream>
#include <time.h>
#include <iterator>
#include <cstring>
#include "AVL.h"
#include "RojiNegro.h"
#include "ArbolB.h"
#include "Arbol23.h"
using namespace std;

template <class T>
void MenuAVL(AVL<T>* avlTree)
{
    clock_t t;
    int op = 0;
    while(op != 99){
        cout << "Árbol AVL" << endl;
        cout << "Eliga una opción: " << endl;
        cout << "1) Insertar valor" << endl;
        cout << "2) Borrar valor" << endl;
        cout << "3) Buscar valor" << endl;
        cout << "4) Imprimir ascendentemente" << endl;
        cout << "5) Imprimir descendentemente" << endl;
        cout << "6) Obtener altura de un nodo" << endl;
        cout << "7) Obtener profundidad de un nodo" << endl;
        cout << "8) Obtener nivel de un nodo" << endl;
        cout << "9) Insertar n valores al arbol" << endl;
        cout << "10) Regresar a menu principal" << endl;
        cout << " " << endl;
        while(!(cin >> op)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida";
        }
        switch(op){
            case 1:{
                int x=0;
                cout << " " << endl;
                cout << "Valor que desea ingresar" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                avlTree->insertar(x);
                cout << " " << endl;
                cout << "Valor insertado" << endl;
                cout << " " << endl;
                break;
            }
            case 2:{
                int x=0;
                cout << " " << endl;
                cout << "Valor que desea borrar" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                avlTree->borrar(x);
                cout << " " << endl;
                break;
            }
            case 3:{
                int x=0;
                cout << " " << endl;
                cout << "Valor que desea buscar" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                cout << " " << endl;
                t = clock();
                avlTree->buscar(x) ? cout << "El valor fue encontrado" << endl : cout << "El valor no existe" << endl;
                t = clock() - t;
                double time_taken = ((double)t)/CLOCKS_PER_SEC;
                printf("%f ms \n", time_taken*1000);
                cout << " " << endl;
                break;
            }
            case 4:{
                cout << " " << endl;
                cout << "Impresión ascendentemente" << endl;
                cout << " " << endl;
                avlTree->inOrder();
                cout << " " << endl;
                cout << " " << endl;
                break;
            }
            case 5:{
                cout << " " << endl;
                cout << "Impresión ascendentemente" << endl;
                cout << " " << endl;
                avlTree->reverseInOrder();
                cout << " " << endl;
                cout << " " << endl;
                break;
            }
            case 6:{
                int x=0;
                cout << " " << endl;
                cout << "Ingrese el valor deseado" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                Nodo<T>* nodo = avlTree->buscar(x);
                cout << " " << endl;
                cout << "Altura: " << avlTree->getAltura(nodo) << endl;
                cout << " " << endl;
                break;
            }
            case 7:{
                int x=0;
                cout << " " << endl;
                cout << "Ingrese el valor deseado" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                Nodo<T>* nodo = avlTree->buscar(x);
                cout << " " << endl;
                cout << "Profundidad: " << avlTree->getProfundidad(nodo) << endl;
                cout << " " << endl;
                break;
            }
            case 8:{
                int x=0;
                cout << " " << endl;
                cout << "Ingrese el valor deseado" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                Nodo<T>* nodo = avlTree->buscar(x);
                cout << " " << endl;
                cout << "Nivel: " << avlTree->getNivel(nodo) << endl;
                cout << " " << endl;
                break;
            }
            case 10:{
                op = 99;
                break;
            }
            case 9:{
                int constant;
                cout << " " << endl;
                cout << "De cuanto quieres que sea tu arbol" << endl;
                cout << " " << endl;
                while(!(cin >> constant)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                int i;
                int arr[constant];
                for (i=0; i<constant; i++){
                    arr[i] = i;
                }
                if (constant > 1)
                {
                    //srand(time(NULL));
                    for (i = 0; i < constant - 1; i++)
                    {
                        size_t j = i + rand() / (RAND_MAX / (constant - i) + 1);
                        int t = arr[j];
                        arr[j] = arr[i];
                        arr[i] = t;
                        avlTree->insertar(arr[i]);
                    }
                }
                cout << " " << endl;
                break;
            }
            default:
                std::cout << "Opción inválida, elige otra" << std::endl;
                break;
        }
    }
}

template <class T>
void MenuRojiNegro(RojiNegro<T>* rjTree){
    clock_t t;
    int op = 0;
    while(op != 99){
        cout << "Árbol Rojiblanco" << endl;
        cout << "Eliga una opción: " << endl;
        cout << "1) Insertar valor" << endl;
        cout << "2) Borrar valor" << endl;
        cout << "3) Buscar valor" << endl;
        cout << "4) Imprimir ascendentemente" << endl;
        cout << "5) Imprimir descendentemente" << endl;
        cout << "6) Obtener altura de un nodo" << endl;
        cout << "7) Obtener profundidad de un nodo" << endl;
        cout << "8) Obtener nivel de un nodo" << endl;
        cout << "9) Regresar a menu principal" << endl;
        cout << "10) Insertar n valores al arbol" << endl;
        cout << " " << endl;
        while(!(cin >> op)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida";
        }
        switch(op){
            case 1: {
                int x=0;
                cout << " " << endl;
                cout << "Valor que desea ingresar" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                rjTree->insertarRB(x);
                cout << " " << endl;
                cout << "Valor insertado" << endl;
                cout << " " << endl;
                break;
            }
            case 2: {
                int x=0;
                cout << " " << endl;
                cout << "Valor que desea borrar" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                rjTree->borrarRB(x);
                cout << " " << endl;
                break;
            }
            case 3: {
                int x=0;
                cout << " " << endl;
                cout << "Valor que desea buscar" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                cout << " " << endl;
                t = clock();
                rjTree->buscar(x) ? cout << "El valor fue encontrado" << endl : cout << "El valor no existe" << endl;
                t = clock() - t;
                double time_taken = ((double)t)/CLOCKS_PER_SEC;
                printf("%f ms \n", time_taken*1000);
                cout << " " << endl;
                break;
            }
            case 4: {
                cout << " " << endl;
                cout << "Impresión ascendentemente" << endl;
                cout << " " << endl;
                rjTree->inOrder();
                cout << " " << endl;
                cout << " " << endl;
                break;
            }
            case 5: {
                cout << " " << endl;
                cout << "Impresión descendentemente" << endl;
                cout << " " << endl;
                rjTree->reverseInOrder();
                cout << " " << endl;
                cout << " " << endl;
                break;
            }
            case 6: {
                int x=0;
                cout << " " << endl;
                cout << "Ingrese el valor deseado" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                Nodo<T>* nodo = rjTree->buscar(x);
                cout << " " << endl;
                cout << "Altura: " << rjTree->getAltura(nodo) << endl;
                cout << " " << endl;
                break;
            }
            case 7: {
                int x=0;
                cout << " " << endl;
                cout << "Ingrese el valor deseado" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                Nodo<T>* nodo = rjTree->buscar(x);
                cout << " " << endl;
                cout << "Profundidad: " << rjTree->getProfundidad(nodo) << endl;
                cout << " " << endl;
                break;
            }
            case 8: {
                int x=0;
                cout << " " << endl;
                cout << "Ingrese el valor deseado" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                Nodo<T>* nodo = rjTree->buscar(x);
                cout << " " << endl;
                cout << "Nivel: " << rjTree->getNivel(nodo) << endl;
                cout << " " << endl;
                break;
            }
            case 9: {
                op = 99;
                break;
            }
            case 10: {
                int constant;
                cout << " " << endl;
                cout << "De cuanto quieres que sea tu arbol" << endl;
                cout << " " << endl;
                while(!(cin >> constant)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                int i;
                int arr[constant];
                for (i=0; i<constant; i++){
                    arr[i] = i;
                }
                if (constant > 1)
                {
                    //srand(time(NULL));
                    for (i = 0; i < constant - 1; i++)
                    {
                        size_t j = i + rand() / (RAND_MAX / (constant - i) + 1);
                        int t = arr[j];
                        arr[j] = arr[i];
                        arr[i] = t;
                        rjTree->insertar(arr[i]);
                    }
                }
                cout << " " << endl;
                break;
            }
            default:
                std::cout << "Opción inválida, elige otra" << std::endl;
                break;
        }
    }
}

template <class T>
void MenuB(ArbolB<T>* BTree){
    clock_t t;
    int op = 0;
    while(op != 99){
        cout << "Árbol B" << endl;
        cout << "Eliga una opción: " << endl;
        cout << "1) Insertar valor" << endl;
        cout << "2) Borrar valor" << endl;
        cout << "3) Buscar valor" << endl;
        cout << "4) Imprimir ascendentemente" << endl;
        cout << "5) Imprimir descendentemente" << endl;
        cout << "6) Obtener altura de un nodo" << endl;
        cout << "7) Obtener profundidad de un nodo" << endl;
        cout << "8) Obtener nivel de un nodo" << endl;
        cout << "9) Regresar a menu principal" << endl;
        cout << "10) Insertar n valores al arbol" << endl;
        cout << " " << endl;
        while(!(cin >> op)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida";
        }
        switch(op){
            case 1:{
                int x=0;
                cout << " " << endl;
                cout << "Valor que desea ingresar" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                BTree->insertar(x);
                cout << " " << endl;
                cout << "Valor insertado" << endl;
                cout << " " << endl;
                break;
            }
            case 2:{
                int x=0;
                cout << " " << endl;
                cout << "Valor que desea borrar" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                BTree->borrar(x);
                cout << " " << endl;
                cout << "Valor borrado" << endl;
                cout << " " << endl;
                break;
            }
            case 3:{
                int x=0;
                cout << " " << endl;
                cout << "Valor que desea buscar" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                t = clock();
                BTree->buscarNodo(x) ? cout << "El valor fue encontrado" << endl : cout << "El valor no existe" << endl;
                t = clock() - t;
                double time_taken = ((double)t)/CLOCKS_PER_SEC;
                printf("%f ms \n", time_taken*1000);
                cout << " " << endl;
                break;
            }
            case 4:{
                cout << " " << endl;
                cout << "Impresión ascendentemente" << endl;
                cout << " " << endl;
                BTree->inOrder();
                cout << " " << endl;
                cout << " " << endl;
                break;
            }
            case 5:{
                cout << " " << endl;
                cout << "Impresión descendentemente" << endl;
                cout << " " << endl;
                BTree->reverseInOrder();
                cout << " " << endl;
                cout << " " << endl;
                break;
            }
            case 6:{cout << "Código no disponible :(" << endl; break;}
            case 7:{cout << "Código no disponible :(" << endl; break;}
            case 8:{cout << "Código no disponible :(" << endl; break;}
            case 9:{
                op = 99;
                break;
            }
            case 10:{
                int constant;
                cout << " " << endl;
                cout << "De cuanto quieres que sea tu arbol" << endl;
                cout << " " << endl;
                while(!(cin >> constant)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                int i;
                int arr[constant];
                for (i=0; i<constant; i++){
                    arr[i] = i;
                }
                if (constant > 1)
                {
                    //srand(time(NULL));
                    for (i = 0; i < constant - 1; i++)
                    {
                        size_t j = i + rand() / (RAND_MAX / (constant - i) + 1);
                        int t = arr[j];
                        arr[j] = arr[i];
                        arr[i] = t;
                        BTree->insertar(arr[i]);
                    }
                }
                cout << " " << endl;
                break;
            }
            default:
                std::cout << "Opción inválida, elige otra" << std::endl;
                break;
        }
    }
}

template <class T>
void MenuArbol23(Arbol23<T>* TTTree){
    clock_t t;
    int op = 0;
    while(op != 99){
        cout << "Árbol 2-3" << endl;
        cout << "Eliga una opción: " << endl;
        cout << "1) Insertar valor" << endl;
        cout << "2) Borrar valor" << endl;
        cout << "3) Buscar valor" << endl;
        cout << "4) Imprimir ascendentemente" << endl;
        cout << "5) Imprimir descendentemente" << endl;
        cout << "6) Obtener altura de un nodo" << endl;
        cout << "7) Obtener profundidad de un nodo" << endl;
        cout << "8) Obtener nivel de un nodo" << endl;
        cout << "9) Regresar a menu principal" << endl;
        cout << "10) Insertar n valores al arbol" << endl;
        cout << " " << endl;
        while(!(cin >> op)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida";
        }
        switch(op){
            case 1:{
                int x=0;
                cout << " " << endl;
                cout << "Valor que desea ingresar" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                TTTree->insertar(x);
                cout << " " << endl;
                cout << "Valor insertado" << endl;
                cout << " " << endl;
                break;
            }
            case 2:{
                int x=0;
                cout << " " << endl;
                cout << "Valor que desea borrar" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                TTTree->borrar(x);
                cout << " " << endl;
                cout << "Valor borrado" << endl;
                cout << " " << endl;
                break;
            }
            case 3:{
                int x=0;
                cout << " " << endl;
                cout << "Valor que desea buscar" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                t = clock();
                TTTree->buscarNodo(x) ? cout << "El valor fue encontrado" << endl : cout << "El valor no existe" << endl;
                t = clock() - t;
                double time_taken = ((double)t)/CLOCKS_PER_SEC;
                printf("%f ms \n", time_taken*1000);
                cout << " " << endl;
                break;
            }
            case 4:{
                cout << " " << endl;
                cout << "Impresión ascendentemente" << endl;
                cout << " " << endl;
                TTTree->inOrder();
                cout << " " << endl;
                cout << " " << endl;
                break;
            }
            case 5:{
                cout << " " << endl;
                cout << "Impresión descendentemente" << endl;
                cout << " " << endl;
                TTTree->reverseInOrder();
                cout << " " << endl;
                cout << " " << endl;
                break;
            }
            case 6:{
                int x=0;
                cout << " " << endl;
                cout << "Ingrese el valor deseado" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                Nodo23<T>* nodo = TTTree->buscarNodo(x);
                cout << " " << endl;
                cout << "Altura: " << TTTree->getAltura(nodo) << endl;
                cout << " " << endl;
                break;
            }
            case 7:{
                int x=0;
                cout << " " << endl;
                cout << "Ingrese el valor deseado" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                Nodo23<T>* nodo = TTTree->buscarNodo(x);
                cout << " " << endl;
                cout << "Altura: " << TTTree->getProfundidad(nodo) << endl;
                cout << " " << endl;
                break;
            }
            case 8:{
                int x=0;
                cout << " " << endl;
                cout << "Ingrese el valor deseado" << endl;
                cout << " " << endl;
                while(!(cin >> x)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                Nodo23<T>* nodo = TTTree->buscarNodo(x);
                cout << " " << endl;
                cout << "Altura: " << TTTree->getNivel(nodo) << endl;
                cout << " " << endl;
                break;
            }
            case 9:{
                op = 99;
                break;
            }
            case 10:{
                int constant;
                cout << " " << endl;
                cout << "De cuanto quieres que sea tu arbol" << endl;
                cout << " " << endl;
                while(!(cin >> constant)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida" << endl;
                    cout << " " << endl;
                }
                int i;
                int arr[constant];
                for (i=0; i<constant; i++){
                    arr[i] = i;
                }
                if (constant > 1)
                {
                    //srand(time(NULL));
                    for (i = 0; i < constant - 1; i++)
                    {
                        size_t j = i + rand() / (RAND_MAX / (constant - i) + 1);
                        int t = arr[j];
                        arr[j] = arr[i];
                        arr[i] = t;
                        TTTree->insertar(arr[i]);
                    }
                }
                cout << " " << endl;
                break;
            }
            default:
                std::cout << "Opción inválida, elige otra" << std::endl;
                break;
        }
    }
}



#endif /* Menu_h */
