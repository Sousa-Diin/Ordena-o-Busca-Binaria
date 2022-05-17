#include <iostream>
using namespace std;

void exibe(int v[], int t);
void insertion(int v[], int t);
int buscaBinaria(int v[], int incio, int fim, int busca);

int main() { /* INICIO DA FUNÇÃO PRINCIPAL*/
  int TAM;
  cout << "Tamanho: ";
  cin >> TAM;

  int busca, encontrado, vet[TAM], i;
  for (i = 0; i < TAM; i++) {
    cin >> vet[i];
  }
  cout << "\n\nTeste: " << endl << endl;

  insertion(vet, TAM);
  exibe(vet, TAM);
  cout << "\nEntre com o elemento para busca: \n";
  cin >> busca;

  encontrado = buscaBinaria(vet, 0, TAM, busca);
  if (encontrado != -1) {
    cout << "Posição do elemento encontrado -> " << encontrado << endl;
  } else {
    cout << "Elemento não encontrado." << endl;
  }

  return 0;
} /* FIM DA FUNÇÃO PRINCIPAL*/

// INICIO DAS FUNÇÕES//
void exibe(int v[], int t) {
  if (t == 1) {
    cout << v[t - 1] << endl;
  } else {
    exibe(v, t - 1);
    cout << v[t - 1] << endl;
  }
}
void insertion(int v[], int t) {
  int pivo, j;
  for (int i = 1; i < t; i++) {
    pivo = v[i];
    j = i - 1;
    while ((j >= 0) and (pivo < v[j])) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = pivo;
  }
}
int buscaBinaria(int v[], int inicio, int fim, int busca) {
  int meio;
  if (inicio < fim) {
    meio = (inicio + fim) / 2;
    if (v[meio] == busca) {
      return meio;
      inicio = fim + 1;
    } else if (v[meio] < busca)
      return buscaBinaria(v, meio + 1, fim, busca);
    return buscaBinaria(v, inicio, meio, busca);
  }
  return -1;
}