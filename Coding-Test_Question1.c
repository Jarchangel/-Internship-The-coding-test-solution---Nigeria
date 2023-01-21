#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    enum Operation { ADD, SUB, MUL, DIV, FIB } op;
    struct Node *left;
    struct Node *right;
    int result;
} Node;

Node* makeFunc(enum Operation op){

Node* newNode = ( Node*)malloc(sizeof( Node));
    newNode->op = op;
        return newNode;
}

int fibonacci(int n) {
    int a = 1, b = 2, c = 0;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

void calc(Node* node) {
    if (node->op == ADD) {
        node->result = node->left->result + node->right->result;
    } else if (node->op == SUB) {
        node->result = node->left->result - node->right->result;
    } else if (node->op == MUL) {
        node->result = node->left->result * node->right->result;
    } else if (node->op == DIV) {
        node->result = node->left->result / node->right->result;
    } else if (node->op == FIB) {
        node->result = fibonacci(node->left->result);
    }
}

int main() {
    Node *add = makeFunc(ADD);
    add->left = (Node*)malloc(sizeof(Node));
    add->left->result = 10;
    add->right = (Node*)malloc(sizeof(Node));
    add->right->result = 6;

    Node *mul = makeFunc(MUL);
    mul->left = (Node*)malloc(sizeof(Node));
    mul->left->result = 5;
    mul->right = (Node*)malloc(sizeof(Node));
    mul->right->result = 4;

    Node *sub = makeFunc(SUB);
    sub->left = add;
    sub->right = mul;

    Node *fibo = makeFunc(FIB);
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
