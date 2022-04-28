#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula *prox;
} *Palavras;

void libertaLista (Palavras l) {
    while (l != NULL) {
        free(l->palavra);
        free(l);
        l = l->prox;
    }
}

int quantasP (Palavras l) {
    int cont = 0;
    while (l != NULL) {
        cont++;
        l = l->prox;
    }
    return cont;
}

void listaPal (Palavras l) {
    while (l != NULL) {
        printf("%s, %d ocorrências\n", l->palavra, l->ocorr);
        l = l->prox;
    }
}

char* ultima (Palavras l) {
    char* r;
    while (l != NULL) {
        r = l->palavra;
        l = l->prox;
    }
    return r;
}

Palavras acrescentaInicio (Palavras l, char* p) {
    Palavras temp = malloc(sizeof(struct celula));
    temp->palavra = p;
    temp->ocorr = 1;
    temp->prox = l;
    l = temp;
    return l;
}

Palavras acrescentaFim (Palavras l, char* p) {
    Palavras temp = malloc(sizeof(struct celula));
    temp->palavra = p;
    temp->ocorr = 1;
    l->prox = temp;
    return l;
}

/*
Palavras acrescenta (Palavras l, char* p) {
    Palavras temp = l;
    while (temp != NULL && l->palavra != p) {
        temp = temp->prox;
    }
    if (temp != NULL && temp->palavra == p) {
        Palavras temp2 = l;
        while (temp2->palavra != temp->palavra) {
            temp2 = temp2->prox;
        }
        temp2->ocorr += 1;
        Palavras temp3;
        while (temp3->palavra != temp2->palavra) {
            acrescentaFim(temp3, l->palavra);
            l->prox;
        }
        acrescentaFim(temp3,)
    }
    else {

    }
}
 */

struct celula* maisFreq (Palavras l) {
    int maior = 0;
    Palavras r = malloc(sizeof(struct celula));
    while (l != NULL) {
        if (l->ocorr > maior) {
            maior = l->ocorr;
            r = l;
        }
    }
    return r;
}

int main () {
    Palavras dic = NULL;

    char *canto1[44] = {"as", "armas", "e", "os", "baroes", "assinalados",
                        "que", "da", "ocidental", "praia", "lusitana",
                        "por", "mares", "nunca", "de", "antes", "navegados",
                        "passaram", "ainda", "alem", "da", "taprobana",
                        "em", "perigos", "e", "guerras", "esforcados",
                        "mais", "do", "que", "prometia", "a", "forca", "humana",
                        "e", "entre", "gente", "remota", "edificaram",
                        "novo", "reino", "que", "tanto", "sublimaram"};

    printf("\n_____________ Testes _____________\n\n");

    int i;
    struct celula *p;
    for (i = 0; i < 44; i++)
        dic = acrescentaInicio(dic, canto1[i]);

    printf("Foram inseridas %d palavras\n", quantasP(dic));
    printf("palavras existentes:\n");
    listaPal(dic);
    printf("última palavra inserida: %s\n", ultima(dic));

    libertaLista(dic);

    dic = NULL;
}