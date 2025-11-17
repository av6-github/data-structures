#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

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

void inToPost(char infix[MAX], char postfix[MAX]) {
    Stack s;
    init(&s);

    int j = 0;

    for (int i=0; infix[i] != '`\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) postfix[j++] = c;
        else if (c == '(') push(&s, c);
        else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        } else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c)) {
                postfix[j++] = pop(&s);
            }
            push(&s, c);    

        }
    }

    while (!isEmpty(&s)) postfix[j++] = pop(&s);
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    scanf("%s", infix);
    printf("infix string: %s\n", infix);
    inToPost(infix, postfix);
    printf("postifx string: %s\n", postfix);

}