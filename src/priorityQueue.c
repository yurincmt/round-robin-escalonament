#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "priorityQueue.h"
#include "processQueue.h"


struct priority_queue{
	Fila *fila1;
	Fila *fila2;
	Fila *fila3;
	Fila *fila4;
};


Pqueue* pqueue_create(void) {
	/**
	 * Cria 4 filas com suas devidas prioridades
	 * */
	
	Pqueue *new_pq = malloc(sizeof(Pqueue));
	if (new_pq != NULL) {
		new_pq->fila1 = fila_create(1);
		new_pq->fila2 = fila_create(2);
		new_pq->fila3 = fila_create(3);
		new_pq->fila4 = fila_create(4);
	} return new_pq;
}


void pqueue_destroy(Pqueue *pq) {
	if (pq != NULL) {
		fila_destroy(pq->fila1);
		fila_destroy(pq->fila2);
		fila_destroy(pq->fila3);
		fila_destroy(pq->fila4);
	} free(pq);
}


int pqueue_insert_proc(Pqueue *pq, PCB proc) {
	/**
	 * Insere o processo 'proc' em uma das filas, na estrutura Lista de Prioridades.
	 *
	 * O processo é inserido considerando seu nível de prioridade, que será equivalente a prioridade de uma das filas.
	 * */

	if (pq != NULL) {

		if (fila_priority(pq->fila1) == proc.priority) {
			fila_insert(pq->fila1, proc);

		} else if (fila_priority(pq->fila2) == proc.priority) {
			fila_insert(pq->fila2, proc);

		} else if (fila_priority(pq->fila3) == proc.priority) {
			fila_insert(pq->fila3, proc);

		} else if (fila_priority(pq->fila4) == proc.priority) {
			fila_insert(pq->fila4, proc);
		} 
	}
}


void pqueue_print(Pqueue *pq) {
	/**
	 * Mostra as listas de prioridades com seus devidos processos.
	 * 
	 * Os processos são mostrados da seguinte forma:
	 * 		[ X:Y ]  tal que X = "Nome do processo" , Y = "Tempo de execução restante do processo".
	 * */

	printf("P[%d]: ", fila_priority(pq->fila4));
	fila_print(pq->fila4);

	printf("P[%d]: ", fila_priority(pq->fila3));
	fila_print(pq->fila3);

	printf("P[%d]: ", fila_priority(pq->fila2));
	fila_print(pq->fila2);
	
	printf("P[%d]: ", fila_priority(pq->fila1));
	fila_print(pq->fila1);
}


void priorityQueue_algorithm(Pqueue *pq) {
	/**
	 * Agrupa processos em 4 filas de prioridades e usa o escalonamento
	 * circular de processos dentro de cada fila. Lembrando que as filas
	 * possuem níveis distintos de prioridade. Processos que estão em
	 * filas que possuem prioridades superiores são executados primeiro.
	 * */

	round_robin(pq, pq->fila4);
	round_robin(pq, pq->fila3);
	round_robin(pq, pq->fila2);
	round_robin(pq, pq->fila1);
}


unsigned int round_robin(Pqueue *pq, Fila* fila) {
	/**
	 * A cada processo é designado um intervalo, chamado de seu quantum, durante o qual ele é deixado
	 * executar. Se o processo ainda está executando ao fim do quantum, a CPU sofrerá uma preempção e
	 * receberá outro processo.
	 * 
	 * Quando o processo usa todo o seu quantum, ele é colocado no fim da fila.
	 * 
	 * OBS: Na prática, conforme os processos estão no estado de PRONTO para serem executados, eles são colocados no final
	 * da fila, para aguardarem o momento de sua execução. Não consegui implementar essa chegada de processos
	 * aleatória, por isso, primeiro alimentei a fila com processos e, depois, passei ela para o round_robin().
	 * */

	
	unsigned int time = 0;
	while (!fila_empty(fila)) {
		
		PCB proc;
		fila_headProcess(fila, &proc);

		pqueue_print(pq);
		sleep(1);
		system("clear");

		time += proc.quantum;
		unsigned int counter = 0;
		while (proc.exec_time > 0 && counter < proc.quantum) {
			++counter;
			--proc.exec_time;
		}

		fila_remove(fila);

		if (proc.exec_time > 0) {
			fila_insert(fila, proc);
		}
	}
	return time;
}