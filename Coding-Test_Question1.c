#include<stdio.h>
#include<stdlib.h>
enum Operation { ADD, SUB, MUL, DIV, FIB };

struct Node {
    enum Operation op;
    struct Node *left;
    struct Node *right;
    int result;
};

struct Node* makeFunc(enum Operation op) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->op = op;
    return newNode;
}

void calc(struct Node* node) {
    if (node->op == ADD) {
        node->result = node->left->result + node->right->result;
    } else if (node->op == SUB) {
        node->result = node->left->result - node->right->result;
    } else if (node->op == MUL) {
        node->result = node->left->result * node->right->result;
    } else if (node->op == DIV) {
        node->result = node->left->result / node->right->result;
    } else if (node->op == FIB) {
        int n = node->left->result;
        int a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }
        node->result = b;
    }
}

int main() {
    struct Node *add = makeFunc(ADD);
    add->left = (struct Node*)malloc(sizeof(struct Node));
    add->left->result = 10;
    add->right = (struct Node*)malloc(sizeof(struct Node));
    add->right->result = 6;

    struct Node *mul = makeFunc(MUL);
    mul->left = (struct Node*)malloc(sizeof(struct Node));
    mul->left->result = 5;
    mul->right = (struct Node*)malloc(sizeof(struct Node));
    mul->right->result = 4;

    struct Node *sub = makeFunc(SUB);
    sub->left = add;
    sub->right = mul;

    struct Node *fibo = makeFunc(FIB);
    fibo->left = sub;

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    printf("Fibo: %d\n", fibo->result);
    printf("add: %d\n", add->result);
    printf("mul: %d\n", mul->result);
    printf("sub: %d\n", sub->result);

    return 0;
}
