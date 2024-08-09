#ifndef __QUICKSORT_H
#define __QUICKSORT_H

#include <vector>

void troca(std::vector<long>& v, long a, long b);
int particao(std::vector<long>& v, long inicio, long fim);
void quicksort(std::vector<long>& v, long inicio, long fim);

#endif