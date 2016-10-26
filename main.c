#include <stdio.h>
#include "listaC.h"

int main(){
	
	List* arreglo[5];	
	arreglo[0]= createList();
	arreglo[1]= createList();
	arreglo[2]= createList();
	arreglo[3]= createList();
	arreglo[4]= createList();
	
	//primer vertice
	add(arreglo[0], 2);
	add(arreglo[0], 4);
	
	//segundo vertice
	add(arreglo[1], 1);
	add(arreglo[1], 3);
	add(arreglo[1], 5);
	
	//tercer vertice
	add(arreglo[2], 2);
	add(arreglo[2], 4);
	
	//cuarto vertice
	add(arreglo[3], 1);
	add(arreglo[3], 3);
	add(arreglo[3], 5);
	
	//quinto vertice
	
	add(arreglo[4], 2);
	add(arreglo[4], 4);
	
	int i;
	for (i=0;i<5;i++){
		showListFL(arreglo[i]);
		
	}
	
	
	
	
	
	
		

	return 1;
}