#ifndef _LISTA_CIRCULAR_
#define _LISTA_CIRCULAR_


typedef struct Nodo{
	int number;
	struct Nodo* next;
	struct Nodo* back;
}Nodo;

typedef struct List{
	int length;
	Nodo* first;
	Nodo* last;
}List;


/**
 * Funcion createNodo
 * crea un nodo con el caracter entregado
 * @param char letter, caracter a guardar en el nodo a crear
 * @return nodo con la informacion guardada

*/
Nodo* createNodo(int number); // crea un nodo con una letra dentro 
/**
 * Funcion createList
 * crea un tipo de dato List inicializado listo para ocupar
 * @return List*, Puntero a una lista
*/
List* createList(); //crea una lsita incializada
/**
 * Funcion add
 * agrega un elemento a una lista al final de esta
 * @param List* list, lista a la cual se le agregara el elemento
 * @param char letter,caracter que se agregara a la lista
*/
void add(List* list, int number); // arega una letra a la lista
/**
 * Funcion invert
 * crea un nueva lista invertida a partir de una lista anterior
 * @param List* list,lista a invertir
 * @return List*, puntero a la nueva lista invertida
*/
List* invert(List* list);
/**
 * Funcion delete
 * funcion que elimina un nodo en una posicion especifica
 * @param List* list, lista a la cual se le eliminara un nodo
 * @param int position, correstponde a la posicion del nodo que se quiere eliminar
*/
void deleteNodo(List* list,int position);
/**
 * Funcion deleteList
 * funcion que elimina todos los nodos de una lista
 * @param List* list, corresponde a la lista que se le eliminaran los nodos
*/
void deleteList(List* list);

/**
 * Funcion find
 * funcion que busca una letra dentro de un lista 
 * @param List* list, corresponde a la lista en la cual se buscara la letra.
 * @param char letter, corresponde a la letra a buscar dentro de la lista.
 * @return int, esta funcion retorna 0 en caso de no encontrar la letra y 1 en caso de si encontrala.
*/
int find(List* list,int number); // verifica si se encuentra la letra en la lista ->0:no esta , 1:si esta

/**
 * Funcion getLetter
 * funcion que busca una letra segun la posicion entregada
 * @param List* list, corresponde a la lista en la cual se obtendra la letra
 * @param int position, corresponde a la posicion de la letra en la lista
 * @retrun char, corresponde a la letra de la lista en la posicion entregada como parametro.
*/
int getNumber(List* list,int position);

/**
 * Funcion showListFL
 * funcion que muestra por pantalla una lista desde el inicio a fin.
 * @param List* list, corresponde a la lista que se desea mostrar.
*/
void showListFL(List* list); //muestra la lista adelante hacia atras
/**
 * Funcion showListLF
 * funcion que muestra por pantalla una lista desde el fin a inicio.
 * @param List* list, corresponde a la lsita que se desea mostrar.
*/
void showListLF(List* list); //muestra la lista desde atras hacia delante
List* listcpy(List* list);


//IMPLEMENTACION DE COLA CON ESTA LISTA (ADAPTACION)
/*
 * Funcion inicio
 * funcion que devuelve el primer numero de una lista (cola)
 * @param List* list, lista que contiene numeros
 * @return primer numero de la lista
*/
int inicio(List* list);
/*
 * Funcion encolar
 * funcion que ingresa un numero al final de una lista (cola)
 * @param List* list, int number, lista a la cueal se le agregara el numero "number"
*/
void encolar(List* list,int number);

/*
 * Funcion desencolar
 * funcion que elimina el primer elemento de una lista (cola)
 * @param List* list, lista a la cual se le eliminara el primer elemento
*/
void desencolar(List* list);

/*
 * Funcion vacia
 * funcion que verifica si una lista (cola) esta vacia, en otras palabras, que no contiene ningun elemento
 * @param List* list, lista (cola) a verificar
 * @return la funcion retorna 1 en caso de que este vacia la lista y 0 en caso contrario.
*/
int vacia(List* list);
#endif