#ifndef FILA_DE_PROCESSOS
#define FILA_DE_PROCESSOS


/**
 * Definição da estrutura de um processo, de acordo com o PCB, da atividade
 * */
struct process{
	char name[32];
	int pid;
	int priority;
	int quantum;
	int exec_time;		// tempo de execução
};
typedef struct process PCB;
typedef struct fila Fila;


/**
 * Interfaces para manipulação da estrutura Fila
 * */
Fila* fila_create(unsigned int p);
void fila_destroy(Fila* fi);
int fila_insert(Fila* fi, PCB proc);
void *fila_remove(Fila *fi);
void fila_head(Fila* fi);
int fila_headProcess(Fila* fi, PCB *proc);
int fila_tamanho(Fila* fi);
int fila_empty(Fila* fi);
int fila_cheia(Fila* fi);
int fila_priority(Fila* fila);
void fila_print(Fila *fi);

#endif