#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
    int *data;
    int size;
    int capacity;
} ListaLinear;

void inicializarLista(ListaLinear *lista, int capacidade);
void inserirElemento(ListaLinear *lista, int elemento);
void removerElemento(ListaLinear *lista, int chave);

int buscaLinear(ListaLinear *lista, int chave);
int buscaBinariaIterativa(ListaLinear *lista, int chave);
int buscaBinariaRecursivaAux(int *array, int chave, int inicio, int fim);
int buscaBinariaRecursiva(ListaLinear *lista, int chave);

void inicializarLista(ListaLinear *lista, int capacidade) {
    lista->data = (int*)malloc(capacidade * sizeof(int));
    if (lista->data == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    lista->size = 0;
    lista->capacity = capacidade;
}

void inserirElemento(ListaLinear *lista, int elemento) {
    if (lista->size < lista->capacity) {
        lista->data[lista->size] = elemento;
        lista->size++;
    } else {
        printf("A lista está cheia. Não é possível inserir mais elementos.\n");
    }
}

int buscaLinear(ListaLinear *lista, int chave) {
    for (int i = 0; i < lista->size; i++) {
        if (lista->data[i] == chave) {
            return i;
        }
    }
    return -1;
}

int buscaBinariaIterativa(ListaLinear *lista, int chave) {
    int inicio = 0;
    int fim = lista->size - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (lista->data[meio] == chave) {
            return meio;
        } else if (lista->data[meio] < chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}
int buscaBinariaRecursivaAux(int *array, int chave, int inicio, int fim) {
    if (inicio > fim) {
        return -1;
    }
    int meio = (inicio + fim) / 2;
    if (array[meio] == chave) {
        return meio;
    } else if (array[meio] < chave) {
        return buscaBinariaRecursivaAux(array, chave, meio + 1, fim);
    } else {
        return buscaBinariaRecursivaAux(array, chave, inicio, meio - 1);
    }
}
int buscaBinariaRecursiva(ListaLinear *lista, int chave) {
    return buscaBinariaRecursivaAux(lista->data, chave, 0, lista->size - 1);
}

void removerElemento(ListaLinear *lista, int chave) {
    int posicao = buscaLinear(lista, chave);
    if (posicao != -1) {
        for (int i = posicao; i < lista->size - 1; i++) {
            lista->data[i] = lista->data[i + 1];
        }
        lista->size--;
        printf("Elemento %d removido com sucesso.\n", chave);
    } else {
        printf("Elemento %d não encontrado na lista.\n", chave);
    }
}