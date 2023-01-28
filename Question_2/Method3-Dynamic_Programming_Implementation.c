#include<stdio.h>

//Method 3: Dynamic Programming implementation

int F(int n) {
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-3] + dp[i-2];
    }
    return dp[n];
}

void main() {
printf("Advantages: \n (1) Most efficient and memory-efficient way to implement the given recurrence relation. \n (2) Uses an array to store calculated values and reuses them whenever possible. \n Disadvantage: \n (1) May be more difficult to understand and implement for someone new to dynamic programming. \n");
}
