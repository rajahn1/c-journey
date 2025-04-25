#include <stdio.h>

#define PI 3.14

int main() {
  printf("Calculate volume of the sphere!\n");

  float radius, volume;

  printf("Please input the radius of your sphere!\n");
  scanf("%f", &radius);

  volume = (4.0f / 3.0f) * PI * (radius * radius * radius);
  printf("Volume: %.1f cubic meters\n", volume / 1000);
  return 0;
}
