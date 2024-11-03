/* Implementation Square-Root operation using Taylor Approximation
 * Reference: https://en.wikipedia.org/wiki/Methods_of_computing_square_roots
 * A program by: Eren SOYLU
*/


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 0.00001

float sqrtTA(float x);

int main(int argc, char *argv[])
{
  printf("Calculation of Square-Root\n");
  printf("The Number    Library SR      Taylor SR       Error\n");
  for(int i = 0;i < 1001; i++){
    float ansL = sqrt((float)i*EPS);
    float ansTA = sqrtTA((float)i*EPS);
    printf("%.5f          %.5f            %.5f            %.10f\n", i*EPS, ansL, ansTA, ansL-ansTA);
  }
  return EXIT_SUCCESS;
}

float sqrtTA(float x){
  if(x>0){
    float k = 0.00000;
    float dK = 0.00000;
    do {
      k = k + EPS;
      dK = x - k*k;
      } while (dK > EPS);
    return k*(1 + (dK/(2*k*k)) - ((dK*dK)/(8*k*k*k*k)) + ((dK*dK*dK)/(16*k*k*k*k*k*k)) - ((5*dK*dK*dK*dK)/(128*k*k*k*k*k*k*k*k)));
  } else {
    return 0;
  }
}
