#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <immintrin.h>
#include <string>
#include <ctime>
#include <fstream>
#include <cassert>
#include "omp.h"
using namespace std;

void print_matrix(double * __restrict__ M,
                  const int m,
                  const int n){

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            int k = i * n + j;
            cout << fixed << setw(15) << setprecision(10) << M[k] << " ";
        }
        cout << endl;
    }

}


void init_matrix(double * __restrict__ A,
                 double * __restrict__ B,
                 double * __restrict__ C,
                 const int m,
                 const int n){
  int i, j, k;
  for (i = 0; i < m; i++){
    for (j = 0; j < n; j++){
      k = i * n + j;
      C[k] = 0.0f;
      A[k] = (rand() / static_cast<float>(RAND_MAX));
      if (i == j)
        B[k] = 1.0f;
      else
        B[k] = 0.0f;
    }
  }
}


void mult_matrix(double * __restrict__ A,
                 double * __restrict__ B,
                 double * __restrict__ C,
                 const int m,
                 const int n){
  int l,o,k,i,j,c;
  double z;
  #pragma omp parallel shared(A,B,C) private(z,l,o,i,j,c, k) firstprivate(m, n) num_threads(2)
  {
    #pragma omp for
      for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
          k = i * n + j;
          C[k] = 0.0f;
          z= 0.0f;
          for (c = 0; c < n; c++){
              l = c * n + j;
              o = i * m + c;
              z += (A[l] * B[o]);
          }
          #pragma omp critical
          {
            C[k] += z;
          }
        }
      }
  }
}


int main (int ac, char **av){

    int m = stoi(av[1]);
    int n = stoi(av[2]);
    bool is_print = stoi(av[3]);
   // double output[5];

    double  *A = NULL,
            *B = NULL,
            *C = NULL;

    cout << endl;
    cout << "Benchmarking" << endl;
    cout << "\t Memoria alocada: [" <<  (3 * m * n * sizeof(double)) << "] Bytes" << endl;

    posix_memalign(reinterpret_cast <void**>(&A), 64, m * n * sizeof(double));
    posix_memalign(reinterpret_cast <void**>(&B), 64, m * n * sizeof(double));
    posix_memalign(reinterpret_cast <void**>(&C), 64, m * n * sizeof(double));


  srand (42);
  init_matrix(A, B, C, m ,n);
  mult_matrix(A, B, C, m ,n);
  
  
  if (is_print){
    print_matrix(A, m, n); cout << endl << endl;
    print_matrix(B, m, n); cout << endl << endl;
    print_matrix(C, m, n); cout << endl << endl;
  }
  free(A); free(B); free(C);
  cout << endl << endl;

  return EXIT_SUCCESS;
}
