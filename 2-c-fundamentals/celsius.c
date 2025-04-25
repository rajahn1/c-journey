#include <stdio.h>
#define FREEZING_PT 32.0f
#define SCALE_FACTOR (5.0f / 9.0f)

int main() {
  float fahreinheit, celsius;

  printf("Enter fahreinheit temperature\n");
  scanf("%f", &fahreinheit); // pointer to fahreinheit

  celsius = (fahreinheit - FREEZING_PT) * SCALE_FACTOR;
  printf("Celsius equivalent is: %.1f\n", celsius);

  return 0;
}
