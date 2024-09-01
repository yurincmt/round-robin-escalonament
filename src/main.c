/**
 * Implementação do algoritmo de escalonamento de processos por
 * Fila de Prioridades.
 * 
 * O presente exemplo de execução do algoritmo recebe informações
 * de uma quantidade PROCESS_QTY processos, tais que elas são, 
 * na seguinte ordem:
 *
 *  + nome
 *  + pid
 * 	+ prioridade
 *  + quantum
 *  + tempo de execução
 * 
 * Para facilitar a interação, o arquivo 'input.txt' possui 15
 * exemplos de processos, podendo ser usado como entrada para o
 * executável. Para usá-lo, faça o seguinte:
 * 
 * 	COMPILAÇÃO:
 * 		make build
 * 
 * 	EXECUÇÃO TEST:
 * 		make test
 * */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include "processQueue.h"
#include "priorityQueue.h"

#define PROCESS_QTY 15


void pqueue_feed(Pqueue* pq) {
	for(int a = 0; a < PROCESS_QTY; ++a) {
		PCB proc;
		scanf("\n%32s", proc.name);
		scanf("%d", &proc.pid);
		scanf("%d", &proc.priority);
		scanf("%d", &proc.quantum);
		scanf("%d", &proc.exec_time);

		pqueue_insert_proc(pq, proc);
	}
}


int main (int argc, char const *argv[])
{
	Pqueue *node = pqueue_create();

	pqueue_feed(node);

	priorityQueue_algorithm(node);

	return 0;
}