#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Definindo a estrutura da pilha
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Inicializa a pilha
void initialize(Stack *stack) {
    stack->top = -1;
}

// Verifica se a pilha está vazia
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Verifica se a pilha está cheia
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Insere um elemento na pilha
void push(Stack *stack, int value) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = value;
    } else {
        printf("Erro: Pilha cheia\n");
        exit(EXIT_FAILURE);
    }
}

// Remove e retorna o elemento do topo da pilha
int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    } else {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
}

// Retorna o elemento do topo da pilha sem removê-lo
int peek(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top];
    } else {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
}

// Verifica se um caractere é um operador
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Obtém a precedência de um operador
int getPrecedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Converte uma expressão infixa para a forma posfixa
void infixToPostfix(char infix[], char postfix[]) {
    Stack operatorStack;
    initialize(&operatorStack);

    int i, j;
    char token, op;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        token = infix[i];

        if (isdigit(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(&operatorStack, token);
        } else if (token == ')') {
            while (peek(&operatorStack) != '(') {
                postfix[j++] = pop(&operatorStack);
            }
            pop(&operatorStack); // Remove o '(' da pilha
        } else if (isOperator(token)) {
            while (!isEmpty(&operatorStack) && getPrecedence(token) <= getPrecedence(peek(&operatorStack))) {
                postfix[j++] = pop(&operatorStack);
            }
            push(&operatorStack, token);
        }
    }

    // Limpa a pilha
    while (!isEmpty(&operatorStack)) {
        postfix[j++] = pop(&operatorStack);
    }

    postfix[j] = '\0'; // Adiciona o caractere nulo ao final da expressão posfixa
}

// Avalia uma expressão posfixa
int evaluatePostfix(char postfix[]) {
    Stack operandStack;
    initialize(&operandStack);

    int i, operand1, operand2, result;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(&operandStack, postfix[i] - '0');
        } else if (isOperator(postfix[i])) {
            operand2 = pop(&operandStack);
            operand1 = pop(&operandStack);

            switch (postfix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }

            push(&operandStack, result);
        }
    }

    return peek(&operandStack);
}

int main() {
    char infixExpression[MAX_SIZE];
    char postfixExpression[MAX_SIZE];

    printf("Digite a expressao infixa (com inteiros de um digito): ");
    scanf("%s", infixExpression);

    infixToPostfix(infixExpression, postfixExpression);

    printf("Expressao posfixa: %s\n", postfixExpression);

    int result = evaluatePostfix(postfixExpression);
    printf("Resultado da expressao: %d\n", result);

    return 0;
}