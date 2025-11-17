#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

bool isFull(Stack *s) {
    return s->top==MAX-1;
}

bool isEmpty(Stack *s) {
    return s->top==-1;
}

void push(Stack *s, char c) {
    if (!isFull(s)) s->items[++(s->top)] = c;
}

char pop(Stack *s) {
    if (!isEmpty(s)) return s->items[(s->top)--];
}

char peek(Stack *s) {
    if (!isEmpty(s)) return s->items[(s->top)];
}

int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return 0;
}

void inToPre(char infix[MAX], char prefix[MAX]) {
    Stack s;
    init(&s);

    int len = strlen(infix);
    int j = 0;

    for (int i=len-1; i>=0; i--) {
        char c = infix[i];

        if (isalnum(c)) prefix[j++] = c;
        else if (c == ')') push(&s, c);
        else if (c == '(') {
            while (!isEmpty(&s) && peek(&s) != ')') {
                prefix[j++] = pop(&s);
            }
            pop(&s);
        } else {
            while (!isEmpty(&s) && precedence(peek(&s)) > precedence(c)) {
                prefix[j++] = pop(&s);
            }
            push(&s, c);    

        }
    }

    while (!isEmpty(&s)) prefix[j++] = pop(&s);
    prefix[j] = '\0';

    int n = strlen(prefix);
    for (int i = 0; i < n/2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[n - i - 1];
        prefix[n - i - 1] = temp;
    }

}

int main() {
    char infix[MAX], prefix[MAX];
    scanf("%s", infix);
    printf("infix string: %s\n", infix);
    inToPre(infix, prefix);
    printf("prefix string: %s\n", prefix);

}