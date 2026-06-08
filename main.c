#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO "tarefas.txt"

typedef struct No {
    char tarefa[100];
    struct No *next;
} No;

typedef struct {
    No *front;
    No *rear;
} Fila;

typedef struct {
    No *top;
} Pilha;



void inicializarFila(Fila *fila) {
    fila->front = NULL;
    fila->rear = NULL;
}

void enqueue(Fila *fila, char tarefa[]) {
    No *novo = (No *)malloc(sizeof(No));

    strcpy(novo->tarefa, tarefa);
    novo->next = NULL;

    if (fila->rear == NULL) {
        fila->front = novo;
        fila->rear = novo;
    } else {
        fila->rear->next = novo;
        fila->rear = novo;
    }
}

int dequeue(Fila *fila, char tarefa[]) {
    if (fila->front == NULL)
        return 0;

    No *temp = fila->front;

    strcpy(tarefa, temp->tarefa);

    fila->front = fila->front->next;

    if (fila->front == NULL)
        fila->rear = NULL;

    free(temp);

    return 1;
}



void inicializarPilha(Pilha *pilha) {
    pilha->top = NULL;
}

void push(Pilha *pilha, char tarefa[]) {
    No *novo = (No *)malloc(sizeof(No));

    strcpy(novo->tarefa, tarefa);

    novo->next = pilha->top;
    pilha->top = novo;
}

int pop(Pilha *pilha, char tarefa[]) {
    if (pilha->top == NULL)
        return 0;

    No *temp = pilha->top;

    strcpy(tarefa, temp->tarefa);

    pilha->top = pilha->top->next;

    free(temp);

    return 1;
}



void listarTarefas(Fila *fila) {
    No *aux = fila->front;

    if (aux == NULL) {
        printf("\nNenhuma tarefa pendente.\n");
        return;
    }

    printf("\n=== TAREFAS PENDENTES ===\n");

    while (aux != NULL) {
        printf("- %s\n", aux->tarefa);
        aux = aux->next;
    }
}



void salvarArquivo(Fila *fila) {
    FILE *fp = fopen(ARQUIVO, "w");

    if (fp == NULL)
        return;

    No *aux = fila->front;

    while (aux != NULL) {
        fprintf(fp, "%s\n", aux->tarefa);
        aux = aux->next;
    }

    fclose(fp);
}

void carregarArquivo(Fila *fila) {
    FILE *fp = fopen(ARQUIVO, "r");

    if (fp == NULL)
        return;

    char tarefa[100];

    while (fgets(tarefa, sizeof(tarefa), fp)) {

        tarefa[strcspn(tarefa, "\n")] = '\0';

        enqueue(fila, tarefa);
    }

    fclose(fp);
}


int main() {

    Fila fila;
    Pilha historico;

    inicializarFila(&fila);
    inicializarPilha(&historico);

    carregarArquivo(&fila);

    int opcao;
    char tarefa[100];

    do {

        printf("\n=== SISTEMA DE GERENCIAMENTO DE TAREFAS ===\n");
        printf("1 - Adicionar tarefa\n");
        printf("2 - Listar tarefas pendentes\n");
        printf("3 - Concluir proxima tarefa\n");
        printf("4 - Desfazer ultima conclusao\n");
        printf("5 - Salvar\n");
        printf("6 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        getchar();

        switch(opcao) {

            case 1:

                printf("Digite a tarefa: ");
                fgets(tarefa, sizeof(tarefa), stdin);

                tarefa[strcspn(tarefa, "\n")] = '\0';

                enqueue(&fila, tarefa);

                printf("Tarefa adicionada.\n");

                break;

            case 2:

                listarTarefas(&fila);

                break;

            case 3:

                if (dequeue(&fila, tarefa)) {

                    push(&historico, tarefa);

                    printf("Tarefa concluida: %s\n", tarefa);

                } else {

                    printf("Fila vazia.\n");

                }

                break;

            case 4:

                if (pop(&historico, tarefa)) {

                    enqueue(&fila, tarefa);

                    printf("Conclusao desfeita: %s\n", tarefa);

                } else {

                    printf("Nenhuma tarefa para desfazer.\n");

                }

                break;

            case 5:

                salvarArquivo(&fila);

                printf("Dados salvos.\n");

                break;

            case 6:

                salvarArquivo(&fila);

                printf("Encerrando...\n");

                break;

            default:

                printf("Opcao invalida.\n");
        }

    } while(opcao != 6);

    return 0;
}
