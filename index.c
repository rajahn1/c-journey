#include <stdio.h>

int main(){
    float profit, loss, total;
    int height, width;

    total = 0.00f;
    profit = 6420.29f;
    loss = 3240.30f;

    total = profit - loss;

    printf("You have: $ %.2f", total);
}

