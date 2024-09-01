#ifndef FILA_DE_PROCESSOS_COM_PRIORIDADES
#define FILA_DE_PROCESSOS_COM_PRIORIDADES
#include "processQueue.h"

typedef struct priority_queue Pqueue;


/**
 * Interfaces para a manipulação da Lista de Prioridades
 * */
Pqueue* pqueue_create(void);
void pqueue_destroy(Pqueue *pq);
int pqueue_insert_proc(Pqueue *pq, PCB proc);
void pqueue_print(Pqueue *pq);
void priorityQueue_algorithm(Pqueue *pq);


/**
 * Algoritmo auxiliar de escalonamento circular
 * */
unsigned int round_robin(Pqueue *pq, Fila* fila);

#endif