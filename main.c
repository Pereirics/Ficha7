#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula *prox;
} *Palavras;

void libertaLista (Palavras l) {
    free(l->palavra);
}

int quantasP (Palavras l) {
    while (l != NULL) {

    }
}