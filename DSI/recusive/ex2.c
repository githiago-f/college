#include <stdio.h>

int power(int num, int powe) {
    if(powe <= 1) {
        return num;
    }
    return power(num, powe-1) * num;
}

int main() {
    printf("%d\n", power(2, 2));
    printf("%d", power(2, 3));
}