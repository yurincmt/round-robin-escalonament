## Escalonamento de Processos (Round Robin)
No contexto de sistemas operacionais, processos são programas em execução que competem pelos recursos do sistema, como a CPU e a memória. O escalonamento de processos determina quais processos devem ser executados em um dado momento, quanto tempo eles devem ser executados e em que ordem.

Existem diversos algoritmos de escalonamento, cada um com suas características e objetivos, como maximizar a eficiência da CPU, minimizar o tempo de espera dos processos, ou garantir que todos os processos recebam uma quantidade justa de tempo de CPU.

O Round Robin é um algoritmo de escalonamento preemptivo, o que significa que ele pode interromper a execução de um processo para dar lugar a outro. Este algoritmo é particularmente conhecido por sua simplicidade e por proporcionar uma distribuição equitativa do tempo de CPU entre todos os processos. O funcionamento básico do Round Robin envolve a atribuição de uma "quantum de tempo" fixo para cada processo. O quantum de tempo é o intervalo durante o qual um processo pode executar antes de ser interrompido.

## Implementação

Implementação do algoritmo de escalonamento de processos Round Robin, utilizando filas circulares de prioridade.

Os algoritmos principais que implementam a Fila de Prioridade e Round Robin, bem como suas explicações, estão no arquivo `src/priorityQueue.c`.

A estrutura de cada processo, ou Bloco de Controle de Processo, dá-se da seguinte forma:

    + nome              -> nome do processo
    + pid               -> process id
    + prioridade        -> a fila prioritária que o processo se encontra
    + quantum           -> parcela de tempo que a CPU deve dedicar para o processo
    + tempo de execução -> tempo total de execução do processo


Essas são as propriedades que cada processo terá e que serão utilizadas pelo o algoritmo de escalonamento.

## Round Robin em Ação!

No video a seguir, cada processo é mostrado da seguinte forma:

 	[ X:Y ]  tal que X = "Nome do processo" , Y = "Tempo de execução restante do processo".

[emacao.webm](https://github.com/user-attachments/assets/34bba0dc-3d37-48b0-b17a-da42d7527c4f)


## Experimente em sua Máquina

Para compilar os arquivos do projeto, instale as dependências:

    sudo apt install build-essential

> Os comando make devem ser executado no diretório raiz do projeto (onde o arquivo Makefile se encontra).

#### Compilar a Aplicação

    make build


#### Execute Algunas Testes

Para ver como a implementação se comporta, experimente um exemplo que se encontra no arquivo `data/example.txt`.

    make test

    ## Ou
	./roundrobin < ./data/example.txt


A presente implementação executa uma quantidade de PROCESS_QTY processos. Essa quantidade pode ser alterada no arquivo `main.c`.

O executável espera receber PROCESS_QTY processo, sendo que cada propriedade de cada processo será lida na seguinte ordem:

    + nome
    + pid
    + prioridade
    + quantum
    + tempo de execução

Para ter uma ideia de como é a entrada que o executável espera receber, veja o arquivo `data/example.txt`.


## Estrutura do Projeto

    .
    ├── data
    │   └── example.txt
    ├── Makefile
    ├── README.md
    ├── roundrobin
    └── src
        ├── main.c
        ├── priorityQueue.c
        ├── priorityQueue.h
        ├── processQueue.c
        └── processQueue.h
