/*
 ============================================================================
 Name        : Prompt.c
 Author      : 
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct dataNode{
	int id;
} DataNode;

typedef struct node {
	DataNode data;
	struct node* next;
}Node;

typedef struct list{
	int size;
	Node* head;
} List;


List* createList();
void push(List* list, DataNode data);
void printList(List* list);
void pop(List* list);
bool isEmpty(List* list);
Node* atPos(List* list,int index);

List* createList(){
	List* list = (List*) malloc(sizeof(List));

	list->size = 0;
	list->head = NULL;

	return list;
}

void print_entry(char *entry) {
	printf("You entered: %s\n", entry);
}

void push(List * list, DataNode data){
	Node* node = (Node*) malloc(sizeof(Node));

	node ->data = data;
	node->next = list->head;
	list->head = node;
	list->size++;
}

void printList(List* list){
	

	if(isEmpty(list)){
		printf("Lista Vazia");
		return;
	}
	
	Node* pointer = list->head;
	while (pointer != NULL){
		printf("%d", pointer->data.id);
		pointer = pointer->next;
	}

	printf("\n");
}

bool isEmpty(List* list){
	return (list->size == 0);
}

void pop(List* list){
	if(!isEmpty(list)){
		Node* pointer = list->head;

		list->head = pointer->next;
		free(pointer);
		list->size--;
	}
}

Node* atPos(List* list, int index){
	if(index >= 0 && index < list->size){
		Node* node = list->head;

		int i;
		for(i = 0; i < index; i++)
			node = node->next;

			return node;
		
	}
	printf("Indice Invalido");
	return NULL;
}


int main(int argc, char *argv[]) {
	List* l = createList();

	DataNode data;

	data.id = 5;
	push(l, data);

	data.id = 9;
	push(l, data);

	printList(l);

	pop(l);
	printList(l);

	if( atPos(l, 0) != NULL)
		printf("%d", atPos(l, 0)->data.id);



	char input[201];
	
	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}

		if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
		}

		print_entry(input);
	}

	return EXIT_SUCCESS;
}
