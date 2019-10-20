En este repositorio, se incluyen dos carpetas de diferentes algoritmos y acciones en un grafo solamente que con diferentes librerías. Las dos librerías que se utilizaron fueron BoostGraph y Snap. 

Los algoritmos y acciones que se realizaron directamente del grafo fueron:

1. Prim
2. Kruskal
3. Dijkstra
4. Floyd Warshall
5. Insertar un vértice
6. Insertar una arista
7. Eliminar un vértice
8. Eliminar una arista

----------------------------------------------------------------
                                           Compilación librería Snap
----------------------------------------------------------------

1. Desde la carpeta de Snap en tu máquina virtual introducir el comando "$ make all" para compilar toda la librería. (Nosotros utilizamos Vagrant-Ubuntu64)
2. Sustituir el codigo de "testgraph" con el propio. 
3. Desde la terminal, introducir el siguiente código "g++ -std=c++98 -Wall -O3 -DNDEBUG -fopenmp -o testgraph testgraph.cpp ../../snap-core/Snap.o -I../../snap-core -I../../snap-adv -I../../glib-core -I../../snap-exp -lrt" para poder compilarlo.

**Importante no modificar ningun Makefile y tener una máquina virtual Ubuntu para que pueda compilarse
