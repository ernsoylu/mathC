/*
Implementation Square-Root operation using Taylor Approximation
Reference: https://en.wikipedia.org/wiki/Methods_of_computing_square_roots
A program by: Eren SOYLU 
*/


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 0.00001

float sqrtTA(float x);
float Q_rsqrt(float x);
float sqrtNT(float x);

int main(int argc, char *argv[]) {
  printf("%.5f\n", Q_rsqrt(144.0));
  // printf("Calculation of Square-Root\n");
  // printf("The Number    Library SR      Quake II SR       Error\n");
  // for(int i = 0;i < 1001; i++){
    // float ansL = sqrt((float)i);
    // float ansTA = sqrtTA((float)i);
    // printf("%.5f  %.5f  %.5f  %.10f\n", (float)i, sqrt(i), Q_rsqrt((float)i), sqrt(i) - Q_rsqrt((float)i));
  // }
  return EXIT_SUCCESS;
}

//Taylor Expansion for finding Square-Root
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

float sqrtNT(float x){
  float initialGuess = EPS;

  return 0;
}

//Greg Shaw's Quake III areano Fast Inverse Square-Root Algorithm
float Q_rsqrt(float x) {
  float xhalf = 0.5F*x;
  int i = *(int*)&x;
  i = 0x5f3759df - (i>>1);
  x = *(float*)&i;
  x = x*(1.5F-xhalf*x*x);
  return x;
}
