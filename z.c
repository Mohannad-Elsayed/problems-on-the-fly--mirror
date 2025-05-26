#include <stdio.h>

int ackermann(int m, int n) {
    printf("%d %d\n", m, n);
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return ackermann(m - 1, 1);
    } else {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

int main() {
    int m = 4, 
        n = 2;
    printf("Ackermann(%d, %d) = %d\n", m, n, ackermann(m, n));
    return 0;
}
