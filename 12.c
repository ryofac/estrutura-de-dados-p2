#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 100

// Definindo a estrutura da pilha
typedef struct {
    float data[MAX_SIZE];
    int top;
} FloatStack;

// Inicializa a pilha
void initializeFloatStack(FloatStack *stack) {
    stack->top = -1;
}

// Verifica se a pilha está vazia
int isFloatEmpty(FloatStack *stack) {
    return stack->top == -1;
}

// Verifica se a pilha está cheia
int isFloatFull(FloatStack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Insere um elemento na pilha
void pushFloat(FloatStack *stack, float value) {
    if (!isFloatFull(stack)) {
        stack->data[++stack->top] = value;
    } else {
        printf("Erro: Pilha cheia\n");
        exit(EXIT_FAILURE);
    }
}

// Remove e retorna o elemento do topo da pilha
float popFloat(FloatStack *stack) {
    if (!isFloatEmpty(stack)) {
        return stack->data[stack->top--];
    } else {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
}

// Retorna o elemento do topo da pilha sem removê-lo
float peekFloat(FloatStack *stack) {
    if (!isFloatEmpty(stack)) {
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
    FloatStack operatorStack;
    initializeFloatStack(&operatorStack);

    int i, j;
    char token;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        token = infix[i];

        if (isdigit(token) || token == '.') {
            postfix[j++] = token;
        } else if (token == '(') {
            pushFloat(&operatorStack, token);
        } else if (token == ')') {
            while (peekFloat(&operatorStack) != '(') {
                postfix[j++] = popFloat(&operatorStack);
            }
            popFloat(&operatorStack); // Remove o '(' da pilha
        } else if (isOperator(token)) {
            while (!isFloatEmpty(&operatorStack) && getPrecedence(token) <= getPrecedence(peekFloat(&operatorStack))) {
                postfix[j++] = popFloat(&operatorStack);
            }
            pushFloat(&operatorStack, token);
        }
    }

    // Limpa a pilha
    while (!isFloatEmpty(&operatorStack)) {
        postfix[j++] = popFloat(&operatorStack);
    }

    postfix[j] = '\0'; // Adiciona o caractere nulo ao final da expressão posfixa
}

// Avalia uma expressão posfixa
float evaluatePostfix(char postfix[]) {
    FloatStack operandStack;
    initializeFloatStack(&operandStack);

    int i;
    float operand1, operand2, result;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i]) || postfix[i] == '.') {
            // Converte o caractere para float e empilha
            float num = atof(&postfix[i]);
            pushFloat(&operandStack, num);

            // Move o índice para o próximo caractere após o número
            while (isdigit(postfix[i]) || postfix[i] == '.') {
                i++;
            }
            i--;
        } else if (isOperator(postfix[i])) {
            operand2 = popFloat(&operandStack);
            operand1 = popFloat(&operandStack);

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

            pushFloat(&operandStack, result);
        }
    }

    return peekFloat(&operandStack);
}

int main() {
    char infixExpression[MAX_SIZE];
    char postfixExpression[MAX_SIZE];

    printf("Digite a expressao infixa (com numeros reais): ");
    scanf("%s", infixExpression);

    infixToPostfix(infixExpression, postfixExpression);

    printf("Expressao posfixa: %s\n", postfixExpression);

    float result = evaluatePostfix(postfixExpression);
    printf("Resultado da expressao: %.2f\n", result);

    return 0;
}