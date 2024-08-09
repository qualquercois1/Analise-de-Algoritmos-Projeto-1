#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;
using namespace std::chrono;

long buscaSequencial(vector<long>& v, long alvo){
  for(long a : v) {
      if(a==alvo) {
          return a;
      }
  }
  return -1;
}

int main() {
    long nExecs = 100000;//10^5
   const long double conversor = 1e+9;
   vector<bool> resultado(nExecs + 1);

   random_device rd;
   mt19937 gen(rd());
   uniform_int_distribution<> dis(0, 10000000);
    for(int w=0; w<4; w++){
        long tamVetor = 10000 * pow(10, w); // multiplica o tamanho do vetor por 10 a cada iteração
        cout << tamVetor << endl;
        
        vector<long> vetor(tamVetor);
            generate(vetor.begin(), vetor.end(), [&]() { return dis(gen); });
  
            auto tempoInicio = high_resolution_clock::now();

            for(long i=0; i<=nExecs; i++) {
                long alvo = vetor[dis(gen) % vetor.size()];
                resultado[i] = buscaSequencial(vetor, alvo);
            }
            auto tempoFim = high_resolution_clock::now();
            long double tempo = duration_cast<nanoseconds>(tempoFim-tempoInicio).count();
            cout << "tempo final: " << tempo/conversor << " s" << endl; 
            
    }

  return 0;
}





