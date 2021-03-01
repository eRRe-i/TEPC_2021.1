/*
 * Esse exercício resolve a integra x^2 no intervalo [0:1], ou seja,
 * o valor exato é de 1/3
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "omp.h"

double func(double x){ return pow(x, 2.0); }
int main(int ac, char**av) {
  double h = atof(av[1]),
         k = h / 2,
		 x = 0.0,
		 sum = 0.0,
		 sumTotal = 0.0;
	unsigned int i = 0;
  unsigned long steps = (unsigned long) 1.0 / h;

  fprintf(stdout, "\nIntegração de uma função f(x)\n");
  fprintf(stdout, "Qtde. de trapézios: %lu - valor do h = %15.10lf\n", steps, h);

#pragma omp parallel shared(sumTotal) private(h, x, i, k,sum) num_threads(2)
	{
	  h = atof(av[1]);
      k = h / 2;
	  x = 0.0;
	  sum = 0.0;

	  #pragma omp for
	  for ( i = 0; i <= steps; i++){
			  double offset = h * (double) i;
			  double aux = 2.0 * k;
			  if ((i == 0) || (i == steps))
				  aux = k;

			  sum += (func(x + offset) * aux);
	  }
		
      #pragma omp critical
      {
          sumTotal += sum;
      }
	  
	}
	  fprintf(stdout, "resultado: I = %15.10lf\n", sumTotal);

	  return EXIT_SUCCESS;
	
}
