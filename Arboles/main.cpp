//
//  main.cpp
//  Arboles
//
//  Created by Sebastian Medina  on 9/18/19.
//  Copyright © 2019 Sebastian Medina . All rights reserved.
//

#include <iostream>
#include "Menu.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    int op = 0;
    while(op != 99){
        cout << "MENU PRINCIPAL" << endl;
        cout << "1) Árbol AVL" << endl;
        cout << "2) Árbol Rojinegro" << endl;
        cout << "3) Árbol B" << endl;
        cout << "4) Árbol 2-3" << endl;
        cout << "5) Salir" << endl;

        while(!(cin >> op)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida";
        }
        switch(op){
            case 1: {
                cout << " " << endl;
                AVL<int> * avlTree = new AVL<int>();
                MenuAVL(avlTree);
                break;
            }
            case 2: {
                cout << " " << endl;
                RojiNegro<int> * rjTree = new RojiNegro<int>();
                MenuRojiNegro(rjTree);
                break;
            }
            case 3: {
                int orden;
                cout << "Escoge el orden el árbol" << endl;
                while(!(cin >> orden)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida";
                }
                cout << " " << endl;
                ArbolB<int> * BTree = new ArbolB<int>(orden);
                MenuB(BTree);
                break;
            }
            case 4: {
                cout << " " << endl;
                Arbol23<int> * TTtree = new Arbol23<int>();
                MenuArbol23(TTtree);
                break;
            }
            case 5: {
                op = 99;
                break;
            }
            default:
                cout << "Inválido" << endl;
        }
    }
    

    
}
