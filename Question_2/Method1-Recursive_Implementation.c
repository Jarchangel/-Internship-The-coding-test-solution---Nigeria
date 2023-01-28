#include<stdio.h>

//Method 1: Recursive implementation

int F(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return F(n-3) + F(n-2);
}
void main() {
printf("Method 1: Recursive implementation\n Advantages:\n (1) Simple to understand and implement.\n (2) Code is easy to read.\n Disadvantages:\n (1) Very inefficient for large values of n, as it requires recalculating the same values multiple times.\n (2) May cause stack overflow for large values of n.\n");
}
