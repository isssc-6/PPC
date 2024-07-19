#include <stdio.h>
#include <stdlib.h>

void countSort(int *A, int n, int m){
  int i, j;
  // Quantidade de andares
  int v = m;
  int *D = (int*) malloc(v*sizeof(int));
  int *S = (int*) malloc(n*sizeof(int));

  for(j=0; j<v; j++)
    D[j] = 0;

  for(i=0; i<n; i++)
    D[A[i]-1]++;

  for(i=1; i<v; i++)
    D[i] += D[i-1];

  for(i=n-1; i>=0; i--){
    j = A[i]-1;
    S[D[j]-1] = A[i];
    D[j]--;
  }

  for (i = 0; i < n; i++)
      A[i] = S[i];

  free(D);  
  free(S);
}

int elevador(int *A, int N, int C, int M){
  
  int energia = 0;
  // Ordena os andares
  countSort(A, M, N);

  // Cada passo é determinado pela capacidade
  for(int i = M-1; i >= 0; i-=C)
    energia += 2*A[i];
  return energia;
}

int main() {

  int T, N, C, M;
  scanf("%d", &T);
  
  while (T > 0){
    scanf("%d %d %d", &N, &C, &M);
    int *andares = (int*)malloc(M*sizeof(int));
    for (int i = 0; i < M; i++)
      scanf("%d", &andares[i]);

    printf("%d\n", elevador(andares, N, C, M));
    
    free(andares);
    T--;
  }
  return 0;
}