#include <stdio.h>

int main() {
    int dollarAmount;
    int count_20 = 0, count_10 = 0, count_5 = 0, count_1 = 0;

    printf("Enter your dollar amount: ");
    scanf("%d", &dollarAmount);

    count_20 = dollarAmount / 20;
    dollarAmount %= 20;

    count_10 = dollarAmount / 10;
    dollarAmount %= 10;

    count_5 = dollarAmount / 5;
    dollarAmount %= 5;

    count_1 = dollarAmount;
    
    printf("$20 bills: %d\n", count_20);
    printf("$10 bills: %d\n", count_10);
    printf("$5 bills: %d\n", count_5);
    printf("$1 bills: %d\n", count_1);

    return 0;
}