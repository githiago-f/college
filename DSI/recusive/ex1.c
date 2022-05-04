#include <stdio.h>
#include <stdlib.h>

void sum(int n) {
    if(n < 1) {
        return;
    }
    printf("%d + %d = %d\n", n, n, n + n);
    return sum(n-1);
}

int main() {
    sum(5);
}