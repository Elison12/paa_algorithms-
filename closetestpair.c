#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
  int x; int y;
} XY;

void imp(XY P[], int esq, int dir){
  for(int i = esq; i <= dir; i ++) {
    printf("(%d, %d) ", P[i].x, P[i].y);
  }
  printf("\n");
}

float min(float dr, float de){
  return (dr < de) ? dr : de;
}

float distancia(XY a, XY b) {
  int Dx = pow(a.x - b.x, 2);
  int Dy = pow(a.y - b.y, 2);

  return sqrt(Dx + Dy);
}

float bruto(XY X[], int esq, int n) {
  // printf("%d %d \n", esq, n);
  float min = distancia(X[esq], X[esq + 1]);
  for (int i = esq; i <= n; ++i){
    // printf("%d %d) ", X[i].x, X[i].y);
    for (int j = i+1; j <= n; ++j){
      if (distancia(X[i], X[j]) < min) min = distancia(X[i], X[j]);
    }       
  }
  // printf("\n");
  return min;
}

void imprima(XY P[], int n){
  for(int i = 0; i < n; i ++) {
    printf("(%d, %d) ", P[i].x, P[i].y);
  }
  printf("\n");
}

void intercalaX(XY P[], int le, int m, int r) {
  int tamA = m - le + 1, tamB = r - m;
  
  XY A[tamA];
  XY B[tamB];
  for(int i = 0; i < tamA; i++) {
    A[i] = P[i + le];
  }
  for(int i = 0; i < tamB; i++) {
    B[i] = P[m + i + 1];
  }

  int i = 0, j = 0, k = le;
  while(i < tamA && j < tamB) {
    if (A[i].x < B[j].x || (A[i].x == B[j].x && A[i].y <= B[i].y)) {
      P[k] = A[i]; 
      i++;
    }
    else {
      P[k] = B[j]; 
      j++;
    }
    k++;
  }

  while(i < tamA) {P[k] = A[i]; i++;  k++;}
  while(j < tamB) {P[k] = B[j]; j++; k++;}
}

void intercalaY(XY P[], int le, int m, int r) {
  int tamA = m - le + 1, tamB = r - m;
  
  XY A[tamA];
  XY B[tamB];
  for(int i = 0; i < tamA; i++) {
    A[i] = P[i + le];
  }
  for(int i = 0; i < tamB; i++) {
    B[i] = P[m + i + 1];
  }

  int i = 0, j = 0, k = le;
  while(i < tamA && j < tamB) {
    if (A[i].y < B[j].y || (A[i].y == B[j].y && A[i].x <= B[i].x)) {
      P[k] = A[i]; 
      
      i++;
    }
    else {
      P[k] = B[j]; 
      
      j++;
    }
    k++;
  }

  while(i < tamA) {P[k] = A[i]; i++;  k++;}
  while(j < tamB) {P[k] = B[j]; j++; k++;}
  // imp(P, le, r);
}

void Mergesort(XY P[], int esq, int dir, int zOu) {
  if(esq < dir) {
    int meio = (esq + dir)/2;
    Mergesort(P, esq, meio, zOu);
    Mergesort(P, meio + 1, dir, zOu);
    if(zOu == 1) intercalaY(P, esq, meio, dir);
    else intercalaX(P, esq, meio, dir);
    
  }
}



float proximos(XY P[], int esq, int dir){
  // praticamente tempo constante O(1)
  if(dir - esq <= 2) {
    int m = (dir + esq)/2;
    intercalaY(P, esq, m, dir);
    return bruto(P, esq, dir);
  }

  int m = (dir + esq)/2;
  // printf("%d %d %d \n", esq ,m , dir);
  float de = proximos(P, esq, m); // n/2
  float dd = proximos(P, m + 1, dir); // n/2

  float d = min(de, dd);
  intercalaY(P, esq, m, dir);
  // printf("%.2f\n", dd);

  int j = 0;
  XY possibilidades[dir - esq + 1];

  // imp(P, esq, dir);


  for(int i = 0; i < dir - esq + 1; i++){
    possibilidades[i].x = 0;
    possibilidades[i].y = 0;
    if(abs(P[i].x - P[m].x) < d) {
      possibilidades[j] = P[i + esq]; j++;
    }
  }

  // O(n.log(n))
  Mergesort(possibilidades, 0, j - 1, 1);

  // imprima(possibilidades, j);
// O(n)
  for(int i = 0; i < j; i++){
    for(int k = i + 1; k < 6 && k < j; k++ ){
      d = min(d, distancia(possibilidades[i], possibilidades[k]));
    }
  }

  return d;
}

int main(void) {
  
  XY P[] = {{2, 233}, {12, 30}, {40, 51}, {7, 28}, {8, 100}, {5, 231}, {15, 11}, {15, 30}, {1,2},{3,4}};
  int n = sizeof(P) / sizeof(P[0]);

  Mergesort(P, 0, n - 1, 0);

  // imprima(P, n);
  printf("%.2f\n", proximos(P, 0, n - 1));
  // imprima(P, n);
  return 0;
}