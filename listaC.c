#include <stdlib.h>
#include <stdio.h>
#include "listaC.h"
/**
 * Funcion createNodo
*/
Nodo* createNodo(int number){ // crea un nodo con una letra dentro
	Nodo* new= (Nodo*)malloc(sizeof(Nodo));
	if(new!=NULL){
		new->number=number;
		new->next=NULL;
		new->back=NULL;
	}
	return new;
}

/**
 * Funcion  createList
*/
List* createList(){ //crea una lsita incializada
	List* list=(List*)malloc(sizeof(List));
	if (list!=NULL){
		list->first=NULL;
		list->last=NULL;
		list->length=0;
		return list;
	}
}

/**
 * Funcion add
*/
void add(List* list, int number){ // arega una letra a la lista
	Nodo* new=(Nodo*)createNodo(number);
	if(list->first==NULL){
		list->first=new;
		list->first->next=list->first;
		list->last=list->first;
		list->first->back=list->last;
	}
	else{
		list->last->next=new;
		new->next=list->first;
		new->back=list->last;
		list->last=new;
		list->first->back=list->last;
	}
	list->length+=1;

}

/**
 * Funcion invert
*/
List* invert(List* list){
	List* listInvert= (List*)createList();
	Nodo* actual=list->last;
	do{
		//printf("letter: %c\n",actual->letter );
		add(listInvert,actual->number);
		actual=actual->back;
	}while(actual!=list->last);
	return listInvert;
}

/**
 * Funcion delete
*/
void deleteNodo(List* list,int position){
	Nodo* actual=list->first;
	
	if(list->length==1 && position == 0){
		free(actual);
		list->length-=1;
		list->first=NULL;
		list->last->next=NULL;

	}

	if(list->first!=NULL && list->length>0){
		//printf("caracter eliminado: %c\n",actual->letter );
		int i;
		for (i = 0; i < position; i++){
			actual = actual->next;
		}

		if (actual==list->first){
			list->first=list->first->next;
			list->first->back=list->last;
			list->last->next=list->first;


		}
		else if(actual==list->last){
			list->last=list->last->back;
			list->last->next=list->first;
			list->first->back=list->last;
		}
		else{
			actual->back->next=actual->next;
			actual->next->back=actual->back;
		}
		
		list->length-=1;
		free(actual);
		
	}
		
	
}

/**
 * Funcion deleteList
*/
void deleteList(List* list){
	//printf("holaaa entre al deleteList\n");
	int i;
	int length=list->length;
	if (list->first!=NULL){
		int contador=0;
		for(i=0;i<length;i++){
			deleteNodo(list,0);
			//printf("contador deteleList: %d\n",contador );
			contador+=1;
			//printf("holaa\n");
			//printf("eleimine\n");
			//showListFL(list);
		}
	}
	//printf("largo : %d\n",list->length );
	if (list->length==0){

		//printf("entre a la cabeza\n");
		//printf("caracter eliminado: %c\n",list->first->letter );
		//free(list->first);
		list->first=NULL;
		list->last=NULL;
		free(list);
	}
}
/**
 * Funcion find
*/
int find(List* list,int number){ // verifica si se encuentra la letra en la lista ->0:no esta , 1:si esta
	Nodo* actual=list->first;
	if(list->first==NULL){
		return 0;
	}
	do{
		if(actual->number==number){
			return 1;
		}
		else{
			actual=actual->next;
		}
	}while(actual!=list->first);
	return 0;
}

/**
 * Funcion getLetter
*/
int getNumber(List* list,int position){
	Nodo* actual=list->first;
	if(list->first==NULL){
		return -1;
	}
	if(position==0){
		return actual->number;
	}
	else{
		do{
			actual=actual->next;
			position-=1;
		}while(position>0);

	}
	return actual->number;
}


/**
 * Funcion showListFL
*/
void showListFL(List* list){ //muestra la lista adelante hacia atras
	Nodo* actual=list->first;
	if(list->first==NULL){
		printf("()\n");
	}
	else{
		printf("(" );
		do{
			printf("%d ",actual->number );
			actual=actual->next;
		}while(actual!=list->first);
		printf(")\n");
	}
}

/**
 * Funcion showListLF
*/
void showListLF(List* list){ //muestra la lista desde atras hacia delante
	Nodo* actual=list->last;
	if(list->first==NULL){
		printf("()\n");
	}
	else{
		printf("(");
		do{
			printf("%d ",actual->number );
			actual=actual->back;
		}while(actual!=list->last);
		printf(")\n");
	}
}
/**
 * Funcion listcpy
*/
List* listcpy(List* list){
	List* listNew=(List*)createList();
	if(list->first==NULL){
		return listNew;
	}
	else{
		Nodo* actual=list->first;
		do{
			add(listNew,actual->number);
			actual=actual->next;
		}while(actual!=list->first);
	}
	return listNew;
}

//Funciones para COLA!:

/*
 * Funcion inicio 
*/
int inicio(List* list){
	return getNumber(list,0);
}

/*
 * encolar
*/
void encolar(List* list,int number){
	add(list,number);
}

/*
 * desencolar
*/
void desencolar(List* list){
	deleteNodo(list, 0);
}

/*
 * vacia
*/
int vacia(List* list){
	if (list->length==0){
		return 1;
	}
	else{
		return 0;
	}
}


