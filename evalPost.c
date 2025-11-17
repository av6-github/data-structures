#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct{
    int data[100];
    int top;
} Stack;

void init(Stack *s){ s->top=-1; }
void push(Stack *s,int x){ s->data[++s->top]=x; }
int pop(Stack *s){ return s->data[s->top--]; }

int main(){
    char exp[100];
    scanf("%s", exp);

    Stack s; 
    init(&s);

    for(int i=0;exp[i];i++){
        char c=exp[i];
        if(isdigit(c)) push(&s,c-'0');
        else{
            int a=pop(&s), b=pop(&s);
            switch(c){
                case '+': push(&s,a+b); break;
                case '-': push(&s,a-b); break;
                case '*': push(&s,a*b); break;
                case '/': push(&s,a/b); break;
            }
        }
    }
    printf("%d", pop(&s));
    return 0;
}
