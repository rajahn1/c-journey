#include <stdio.h>
const int DIMENSIONAL_BOX = 166;

int main(){
    float profit, loss, total;
    int height, width, length, volume, weight;

    height = 8;
    length = 12;
    width = 10;

    volume = height * length * width;
    weight = (volume + 165) / DIMENSIONAL_BOX;

    printf("Dimensions %dx%dx%d\n", length, width, height);
    printf("Volume (cubic inch) %d\n", volume);
    printf("Weight (pounds) %d\n", weight);

    total = 0.00f;
    profit = 6420.29f;
    loss = 3240.30f;

    return 0;
}

