#include<stdio.h>

//Method 2: Iterative implementation

int F(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    int a = 0, b = 1, c = 2;
    for (int i = 3; i <= n; i++) {
        int d = a + b;
        a = b;
        b = c;
        c = d;
    }
    return c;
}
void main() {
printf("Method 2: Iterative implementation\n Advantages: \n (1) More efficient than the recursive implementation, as it reduces the number of function calls\n (2) Easy to understand\n Disadvantage: \n (1) Requires more memory to store all the intermediate values\n");
}
