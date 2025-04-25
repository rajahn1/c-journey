#include <stdio.h>

float calculatePower(int power, float number);
int main() {
  float x;
  printf("Enter a value for X\n");
  scanf("%f", &x);

  float resultPoly = 3 * calculatePower(5, x) + 2 * calculatePower(4, x) -
                     5 * calculatePower(3, x) - calculatePower(2, x) + 7 * x -
                     6;

  printf("Poly: %.2f\n", resultPoly);
  return 0;
}

float calculatePower(int power, float number) {
  float result;
  result = number;
  for (int i = 1; i < power; i++) {
    result = result * number;
  }

  return result;
}
