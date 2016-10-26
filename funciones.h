#include "listaC.h"


#ifndef _FUNCIONES_H
#define _FUNCIONES_H

typedef	struct grafo
{
	int vertices;
	List** ListAdy;
	int** matrizAdy;
	int* marcas;

}Grafo;

/*
 * Funcion existFile
 * funcion que verifica si un archivo de texto plano existe
 * @param char* filename, nombre del archivo
 * @return entero 1 en caso de que si exista y 0 en caso contrario
*/
int existsFile(char* filename);

/*
 * Funcion rtrim
 * funcion que elimina todos los caracteres de espacio (" ") al final de un string
 * @param char* string, string a modificar
*/
void rtrim(char* string);

/*
 * Funcion inicializarMatrizAdy
 * funcion que inicializa una matriz de enteros
 * @param int vertices, numero de filas y columnas que tendra la matriz
*/
int** inicializarMatrizAdy(int vertices);

/*
 * Funcion showMatriz 
 * funcion que muestra por consola una matriz
 *@param int** matriz, int vertices, matriz es la matriz a mostrary vertices la cantidad de filas y columnas de ella
*/
void showMatriz(int** matriz,int vertices);

/*
 * Funcion inicializarGrafo
 * funcion que inicializa un puntero a grafo pidiendo memoria para él.
 * se inicializa la matriz, la lista de adyacencia, un arreglo de enteros de largo vertices.
 * @param int vertices, cantidad de vertices de un grafo, 
 *
*/
Grafo* inicializarGrafo(int vertices);

/*
 * Funcion destruirGrafo
 * funcion que libera el espacio pedido para un grafo (libera todas las caracteristicas dentro del grafo)
 * @param Grafo* grafo, puntero a grafo a liberar
*/
void destruirGrafo(Grafo* grafo);

/*
 * Funcion mostrarGrafo
 * funcion que muestra por consola todas las caracteristicas del grafo
 * @param Grafo* grafo, puntero a grafo a mostrar
*/
void mostrarGrafo(Grafo* grafo);

/*
 * Funcion verticesAdy
 * funcion agrega desde un string todos los numeros contenidos en él a una lista.
 * @param List* list, char* string, "list" refiere a la lista que se le agregaran los numeros contenidos en "string"
*/
void verticesAdy(List* lista,char* string);

/*
 * Funcion cargarGrafo
 * funcion que crea la matriz de adyacenia y lista de adyacencia de un grafo a partir de un archivo de texto plano
 * @param char* nameFile, refiere al nombre del archivo de cual se cargaran los datos
 * @return Grafo* puntero a grafo que contiene la matriz y lista de adyacencia a partir del archivo
*/
Grafo* cargarGrafo(char* nameFile);

/*
 * funcion busqueda
 * funcion que realiza una busqueda por anchura y realiza marcas por los nodos visitados
 * @param Grafo* grafo, int vertice, grafo refiere al grafo que se aplicara 
 * la busqueda y vertice al nodo por el cual se empeiza a buscar
*/
void busqueda(Grafo* grafo,int vertice);

/*
 * Funcion verificarConexto 
 * funcion que verifica si un grafo es conexto o no
 * @param Grafo* grafo, refiere al grafo que se analizará
 * @return entero 1 en caso de ser un grafo conexo , 0 en caso contrario
*/
int verificarConexo(Grafo* grafo);

/*
 * Funcion centralidadGrado
 * funcion que muestra por pantalla nos nodos ordenados segun la centralidad de grafo 
 * @param Grafo* grafo, puntero a grafo que contiene los nodos a analizar.
*/
void centralidadGrado(Grafo* grafo);




#endif