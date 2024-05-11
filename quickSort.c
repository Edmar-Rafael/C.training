#include <stdio.h>

int particiona(int *v, int inicio, int fim) {
  int pivo = (v[inicio] + v[fim] + v[(inicio + fim) / 2]) / 3;

  while(inicio < fim) {
    while(inicio < fim && v[inicio] <= pivo) {
     inicio++; 
    }

    while(inicio < fim && v[fim] > pivo) {
      fim--;
    }

    int aux = v[inicio];
    v[inicio] = v[fim];
    v[fim] = aux;
  }
  return inicio;
}

void quickSort(int *v, int inicio, int fim) {
  if(inicio < fim) {
    int pos = particiona(v, inicio, fim);

    quickSort(v, inicio, pos - 1);

    quickSort(v, pos + 1, fim);
  }
}

void imprimir(int *v, int length) {
  for(int i = 0; i < length; i++) {
    printf("%d, ", v[i]);
  }
  printf("\n");
}

int main() {
  int vet[] = {10,11,23,44,8,15,3,9,12,45,56,45,45,47,1};
  int length = sizeof(vet) / sizeof(vet[0]);

  imprimir(vet, length);

  quickSort(vet, 0, length - 1);

  imprimir(vet, length);

  return 0;
}