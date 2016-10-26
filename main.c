#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listaC.h"
#include "funciones.h"

#define LARGOLINE 500000



int main(){

	Grafo* grafo=NULL;
	char nameFile[255];
	int opcion;
	do{
		printf("1) Cargar grafo desde un archivo\n");
		printf("2) Mostrar caracteristicas del grafo\n");
		printf("3) Verificar si el grafo es conexo\n");
		printf("4) Ordenar vertices del grafo por centralidad de grado \n");
		printf("5) Ordenar vertices del grafo por centralidad de betweenness\n");
		printf("6) Salir\n");

		printf("\nIngrese una opcion: ");
		fflush(stdin);
		scanf("%d",&opcion);
		switch(opcion){
			case 1:
				
				memset(nameFile,'0',255);
				//char stringBuffer[LARGOLINE];
				printf("\nIngrese el nombre de un archivo: ");
				scanf("%s", nameFile);
				
				//printf("cargar grafo \n");
				if (existsFile(nameFile)){
					if(grafo!=NULL){
						destruirGrafo(grafo);
					}
					grafo=cargarGrafo(nameFile);
					printf("Grafo cargado\n\n");
					
				}
				else{
					printf("El archivo no existe\n\n");
				}
				break;
			case 2:
				//printf("Mostrar grafo conexo\n");
				if(grafo!=NULL){
					mostrarGrafo(grafo);
				}
				else{
					printf("\nNo existe ningun grafo cargado\n\n");
				}
				
				break;

			case 3:
				//printf("verificar grafo conexo\n");
				if(grafo!=NULL){
					if(verificarConexo(grafo)){
						printf("\nEl grafo es conexo\n\n");
					}
					else{
						printf("\nEl grafo NO es conexo\n\n");
					}
				}
				else{
					printf("\nNo existe ningun grafo cargado\n\n");
				}
				
				break;
			case 4:
				//printf("ordenar por centralidad de grado\n");
				if(grafo!=NULL){
					printf("\n");
					centralidadGrado(grafo);
					printf("\n");
				}
				else{
					printf("\nNo existe ningun grafo cargado\n\n");
				}
				
				break;

			case 5: 
				printf("ordenar por centralidad de betweenness\n");
				break;


		}

	}while(opcion!=6);

	//Grafo* copia=(Grafo*)grafocpy(grafo);
	//mostrarGrafo(copia);


	
	
	//
	//mostrarGrafo(grafo2);

	/*List* lista=(List*)createList();
	add(lista,3);
	add(lista,3);
	add(lista,3);
	add(lista,3);
	add(lista,3);
	showListFL(lista);
	deleteList(lista);
	showListFL(lista);*/


	/*Grafo grafo;
	grafo.vertices=2;
	grafo.ListAdy=(List**)malloc(sizeof(List*)*2);
	grafo.ListAdy[0]=createList();
	add(grafo.ListAdy[0],2);
	showListFL(grafo.ListAdy[0]);*/


	//lo que comenteee anteeesasdasd
	/*Grafo grafo;
	grafo = createGrafo(nameFile);
	showListFL(grafo.ListAdy[0]);
	int* marcas = (int*)busqueda(grafo,1);
	int i;
	for (i=0;i<grafo.vertices;i++){
		printf("%d ",marcas[i] );
	}
	printf("\n");
	showMatriz(grafo.matrizAdy,grafo.vertices);*/





	//List** lista=(List**)createListAdy(nameFile);
	 
	//printf("vertice %d: ",i );
	//showListFL(arreglo[i]);
	/*List* cola= (List*) createList();
	encolar(cola,1);
	encolar(cola,2);
	encolar(cola,5);
	showListFL(cola);
	desencolar(cola);
	showListFL(cola);
	printf("%d\n",inicio(cola));
	printf("%d\n",vacia(cola) );
	desencolar(cola);
	desencolar(cola);
	printf("%d\n",vacia(cola) );
	showListFL(cola);*/
	//printf("aad\n");


	return 0;
}