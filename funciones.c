#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"
#include "listaC.h"
#define LARGOLINE 500000




//-------------------------------------
/*
 * Funcion existsFile
*/
int existsFile(char* filename) {
	FILE* f = NULL;
	f = fopen(filename,"r");
	if (f == NULL) 
		return 0;
	else {
		fclose(f);
		return 1;
	}
	return 0;
}

/*
 * Funcion rtrim
*/
void rtrim(char* string){
	while(string[strlen(string)-1]==' ' 
		|| string[strlen(string)-1]=='\n' 
		|| string[strlen(string)-1]=='\t'
		|| string[strlen(string)-1]=='\r'){
		string[strlen(string)-1]='\0';
	}
}

/*
 * Funcion inicializarMatrizAdy
*/
int** inicializarMatrizAdy(int vertices){
	int** matriz=(int**)malloc(sizeof(int*)*vertices);
	int i,j;
	for (i=0;i<vertices;i++){
		matriz[i]=(int*)malloc(sizeof(int*)*vertices);
	}
	for (i=0;i<vertices;i++){
		for (j=0;j<vertices;j++){
			matriz[i][j]=0;
		}
	}
	return matriz;
}

/*
 * Funcion showMatriz
*/
void showMatriz(int** matriz,int vertices){
	int i,j;
	for (i=0;i<vertices;i++){
		for (j=0;j<vertices;j++){
			printf("%d ",matriz[i][j] );
		}
		printf("\n");
	}
}

/*
 * Funcion inicializarGrafo
*/
Grafo* inicializarGrafo(int vertices){
	Grafo* grafo=(Grafo*)malloc(sizeof(Grafo));
	grafo->vertices=vertices;
	grafo->ListAdy=(List**)malloc(sizeof(List*)*vertices);
	grafo->matrizAdy=inicializarMatrizAdy(vertices);
	grafo->marcas=(int*)malloc(sizeof(int)*vertices);
	int i;
	for (i=0;i<vertices;i++)
	{
		grafo->ListAdy[i]=createList();
	}
	for ( i = 0; i < vertices; ++i)
	{
		grafo->marcas[i]=0;
	}
	return grafo;
}

/*
 * Funcion destruirGrafo
*/
void destruirGrafo(Grafo* grafo){
	free(grafo->marcas);
	int i;
	for (i=0;i<grafo->vertices;i++){
		free(grafo->ListAdy[i]);//ver lo de destruir la lista de dentro!
	}
	free(grafo->ListAdy);
	for (i=0;i<grafo->vertices;i++){
		free(grafo->matrizAdy[i]);
	}
	free(grafo->matrizAdy);
	free(grafo);
}


void mostrarGrafo(Grafo* grafo){
	printf("\nGRAFO: \n");

	printf("Vertices: %d\n",grafo->vertices);

	printf("Lista adyacencia: \n" );
	int i,j;
	for (i=0;i<grafo->vertices;i++){
		printf("Vertice %d: ",i+1 );
		for (j=0;j<grafo->ListAdy[i]->length;j++){
			printf("%d ",getNumber(grafo->ListAdy[i],j)+1 );
		}
		printf("\n");


		//printf("Vertice %d: ",i );
		//showListFL(grafo->ListAdy[i]);
	}

	printf("Matriz de adyacencia: \n");
	showMatriz(grafo->matrizAdy,grafo->vertices);

	/*printf("Marcas: ");
	for (i = 0; i < grafo->vertices; ++i)
	{
		printf("%d ",grafo->marcas[i] );	
	}*/
	printf("\n\n");

}
/*
 * Funcion verticesAdy
*/
void verticesAdy(List* lista,char* string){
	rtrim(string);
	
	char charBuffer[100];
	int intBuffer;
	int inicio,fin;
	inicio=0;
	int i;
	for(i = 0; i<(strlen(string)); i++){
		if(string[i] == ' ' ){
			fin=i;
			memset(charBuffer,'0',100);
			memcpy(charBuffer,&string[inicio],fin);
			intBuffer=atoi(charBuffer);
			add(lista,intBuffer-1);
			inicio=fin;

		}   	
	}

	if(inicio<strlen(string)){
		memset(charBuffer,'0',100);
		memcpy(charBuffer,&string[inicio],strlen(string));
		intBuffer=atoi(charBuffer);
		add(lista,intBuffer-1);
	}
	deleteNodo(lista,0);
}

/*
 * Funcion cargarGrafo
*/
Grafo* cargarGrafo(char* nameFile){
	char stringBuffer[LARGOLINE];
	FILE* file= fopen(nameFile,"r");

	fgets(stringBuffer,LARGOLINE,file);
	int vertices=atoi(stringBuffer);
	Grafo* grafo=inicializarGrafo(vertices);
	//cargar listaAdy
	int i=0;
	while (i<vertices){
		fgets (stringBuffer, LARGOLINE, file);
		verticesAdy(grafo->ListAdy[i],stringBuffer);
		i+=1;
	}
	//cargar matriz de adyacencia
	int j;
	for(i=0;i<grafo->vertices;i++){
		for (j=0;j<grafo->ListAdy[i]->length;j++){
			grafo->matrizAdy[i][getNumber(grafo->ListAdy[i],j)]=1;
		}
	}
	fclose(file);
	return grafo;


}



/*
 * Funcion busqueda
*/
void busqueda(Grafo* grafo,int vertice){
	int i;
	for (i=0;i<grafo->vertices;i++){
		grafo->marcas[i]=0;
	}

	List* cola= (List*) createList();
	encolar(cola,vertice);
	int v,w;
	while(!(vacia(cola))){
		v= inicio(cola);
		grafo->marcas[v]=2;
		for (i=0;i<grafo->ListAdy[v]->length;i++){
			w=getNumber(grafo->ListAdy[v],i);
			if (grafo->marcas[w]==0){
				grafo->marcas[w]=1;
				encolar(cola,w);

			}
			/*else{
				if (find(cola,w) && grafo->marcas[w]==1){
					grafo->marcas[w]=2;
				}
			}
			*/
		}
		desencolar(cola);
	}

}


/*
 * Funcion verificar conexo
*/
int verificarConexo(Grafo* grafo){
	busqueda(grafo,0);
	int i;
	for (i=0;i<grafo->vertices;i++){
		if(grafo->marcas[i]!=2){
			return 0;
		}
	}
	return 1;
}

/*
 * Funcion centralidadGrafo
*/
void centralidadGrado(Grafo* grafo){
	int i,j;
	for (i=0;i<grafo->vertices;i++){
		grafo->marcas[i]=0;
	}
	for (i=0;i<grafo->vertices;i++){
		grafo->marcas[i]=grafo->ListAdy[i]->length;
	}
	int max=grafo->marcas[0];
	for (i=1;i<grafo->vertices;i++){
		if (max<grafo->marcas[i]){
			max=grafo->marcas[i];
		}
	}
	for (i=max;i>=0;i--){
		for (j=0;j<grafo->vertices;j++){
			if(grafo->marcas[j]==i){
				printf("Vertice %d: grado %d\n",j+1,i );
			}
		}
	}
}

Grafo* grafocpy(Grafo* grafo){
	Grafo* copia=inicializarGrafo(grafo->vertices);
	int i,j;
	for (i=0;i<grafo->vertices;i++){
		copia->ListAdy[i]=(List*)listcpy(grafo->ListAdy[i]);
	}
	for (i=0;i<grafo->vertices;i++){
		for (j=0;j<grafo->vertices;j++){
			copia->matrizAdy[i][j]=grafo->matrizAdy[i][j];
		}
	}
	return copia;


}











//haciendo uso de la lista implementada




