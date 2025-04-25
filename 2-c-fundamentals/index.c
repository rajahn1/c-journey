#include <stdio.h>

#define INCHES_PER_POUND 166

int main() {
  float profit, loss, total;
  int height, width, length, volume, weight;
  printf("Hello, lets calculate the ideal weight for your box!\n");

  printf("Please insert the height\n");
  scanf("%d", &height);

  while (height <= 0) {
    printf("Please insert a valid height\n");
    scanf("%d", &height);
  }
  scanf("%d", &width);

  printf("Please insert the length\n");
  scanf("%d", &length);

  volume = height * length * width;
  weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;

  printf("Dimensions %dx%dx%d\n", length, width, height);
  printf("Volume (cubic inch) %d\n", volume);
  printf("Weight (pounds) %d\n", weight);

  total = 0.00f;
  profit = 6420.29f;
  loss = 3240.30f;

  return 0;
}
