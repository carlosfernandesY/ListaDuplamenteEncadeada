#include <stdio.h>
#include <stdlib.h>cle
#include <string.h>

typedef struct No {
    char *dado;
    struct No *next;
    struct No *pre;
} No;

typedef struct DoubleList {
    struct No *firstNo;
    struct No *lastNo;
} DoubleList;

No *createNo(char *data) {
    No *newNode = malloc(sizeof(No));
    if (newNode == NULL) {
        printf("Erro em alocar memória");
        return NULL;
    }
    newNode->dado = data;
    newNode->next = NULL;
    newNode->pre = NULL;
    return newNode;
}

void insertNode(DoubleList *double_list, char *data) {
    No *newNode = createNo(data);
    if (double_list->lastNo != NULL) {
        newNode->pre = double_list->lastNo;
        double_list->lastNo->next = newNode;
    } else {
        double_list->firstNo = newNode;
    }
    double_list->lastNo = newNode;
}

No *findBydata(const DoubleList *list, const char *data) {
    No *aux = list->firstNo;
    while (aux != NULL) {
       if (strcmp(aux->dado, data) == 0) {
            return aux;
        } else {
            aux = aux->next;
        }
    }
    return NULL;
}

void printList(const DoubleList *list) {
    No *aux = list->firstNo;
    while (aux != NULL) {
        printf("%s\n", aux->dado);
        aux = aux->next;
    }
}

void deleteItem(DoubleList *list, const char *data) {
    No *noExcluir = findBydata(list, data);
    if (noExcluir == NULL)return;

    if (noExcluir->pre == NULL) {
        list->firstNo = noExcluir->next;
    } else {
        noExcluir->pre->next = noExcluir->next;
    }
    if (noExcluir->next == NULL) {
        list->lastNo = noExcluir->pre;
    } else {
        noExcluir->next->pre = noExcluir->pre;
    }
    free(noExcluir);
}

int main() {
    struct DoubleList list;
    list.lastNo = NULL;
    list.firstNo = NULL;
    insertNode(&list, "aaa");
    insertNode(&list, "bbb");
    insertNode(&list, "ccc");
    insertNode(&list, "ddd");
    deleteItem(&list, "aaa");
    printList(&list);
    return 0;
}
