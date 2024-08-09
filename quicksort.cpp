#include "quicksort.h"
#include <vector>
#include <iostream>

using namespace std;

void troca(vector<long>& v, long a, long b) {
    long aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

int particao(vector<long>& v, long inicio, long fim) {
    long meio = (inicio + fim) / 2;
    long pivo = v[meio];

    while (inicio <= fim) {
        while (v[inicio] < pivo) {
            inicio++;
        }
        while (v[fim] > pivo) {
            fim--;
        }
        if (inicio <= fim) {
            troca(v, inicio, fim);
            inicio++;
            fim--;
        }
    }
    return inicio;
}

void quicksort(vector<long>& v, long inicio, long fim) {
    if (inicio < fim) {
        long pos = particao(v, inicio, fim);
        quicksort(v, inicio, pos - 1);
        quicksort(v, pos, fim);
    }
}

