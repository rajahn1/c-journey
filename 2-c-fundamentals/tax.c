#include <stdio.h>

// calculate tax from dollar amount
int main() {
  float amount, result, tax;

  printf("Type the ammout you want to calculate: \n");
  scanf("%f", &amount);

  printf("now type the tax: \n");
  scanf("%f", &tax);

  result = amount + (amount * (tax / 100));
  printf("%.2f\n", result);

  return 0;
}
