#include <stdio.h>
#include <stdlib.h>
#include "processQueue.h"


struct elemento {	// Elemento da fila; contém um processo e o próximo elemto, na fila
	PCB process;
	struct elemento *prox;
};
typedef struct elemento Elem;


struct fila {	// Nó descritor do tipo fila; contém informações para manipular a fila
	Elem *inicio;
	Elem *final;
	unsigned int priority;
	int qty;
};


Fila* fila_create(unsigned int p) {
	Fila *fila = malloc(sizeof(Fila));
	if (fila != NULL) {		// verifica se a fila foi realmente criada
		fila->inicio = NULL;
		fila->final = NULL;
		fila->priority = p;
		fila->qty = 0;
	} return fila;
}


void fila_destroy(Fila* fi) {
	/**
	 * Exclui todos os elementos da fila, bem como o nó descritor da fila.
	 * */
	if (fi != NULL) {		// verifica se a fila passada foi criada corretamente
		Elem* no;
		while (fi->inicio != NULL) {
			no = fi->inicio;
			fi->inicio = fi->inicio->prox;
			free(no);
		}
		free(fi);
	}
}


int fila_insert(Fila* fi, PCB proc) {
	
	if (fi == NULL) return 0;	// se a fila passada não foi corretamente alocada

	Elem* no = malloc(sizeof(Elem));
	
	if (no == NULL) return 0;	// houve erro na alocação do nó

	no->process = proc;
	no->prox = NULL;
	
	if (fi->final == NULL)		// fina está vazia e não tem nó final
		fi->inicio = no;
	else
		fi->final->prox = no;
	fi->final = no;
	fi->qty++;
	return 1;
}


void *fila_remove(Fila *fi) {
	/**
	 * Remove o elemento da cabeça da fila 
	 * */

	if (fi == NULL) return 0;

	if (fi->inicio == NULL) return 0;

	Elem* no = fi->inicio;
	// o novo início da fila será o prox do antigo início
	fi->inicio = fi->inicio->prox;
	free(no);

	if(fi->inicio == NULL)
		fi->final = NULL;
	fi->qty--;
}


int fila_headProcess(Fila* fila, PCB *proc) {
	/**
	 * Consulta o processo que está no início da fila.
	 * */
	if (fila == NULL) return 0;

	if (fila->inicio == NULL) return 0;

	*proc = fila->inicio->process;
	return 1;
}


int fila_empty(Fila* fila) {
	if (fila == NULL) {
		return -1;
	} if(fila->inicio == NULL) {
		return 1;
	} return 0;
}


int fila_priority(Fila* fila) {
	return fila->priority;
}


void fila_print(Fila *fila) {
	Elem* aux = fila->inicio;
	while (aux != NULL) {
		printf("-[ %1s:%1d ]", aux->process.name, aux->process.exec_time);
		aux = aux->prox;
	} putchar('\n');
}
