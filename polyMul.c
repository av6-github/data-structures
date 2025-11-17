#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Poly{
    int coeff, exp;
    struct Poly *next;
} Poly;

Poly* createPoly(int coeff, int exp) {
    Poly *newPoly = (Poly *)malloc(sizeof(Poly));
    newPoly->exp=exp;
    newPoly->coeff=coeff;
    newPoly->next=NULL;
    return newPoly;
}

Poly *insert(Poly *head, int coeff, int exp) {
    Poly *newPoly = createPoly(coeff, exp);
    if (head == NULL) return newPoly;
    Poly *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next=newPoly;
    return head;
}

Poly *mulPoly(Poly *p1, Poly *p2) {
    Poly *res = NULL;
    for (Poly *a=p1; a; a=a->next) {
        for (Poly *b=p2; b; b=b->next) {
            res = insert(res, a->coeff*b->coeff, a->exp+b->exp);
        }
    }

    return res;
}

void combine(Poly *head) {
    Poly *curr = head;
    while (curr != NULL) {
        Poly *runner = curr;
        while (runner->next != NULL) {
            if (runner->next->exp == curr->exp) {
                curr->coeff += runner->next->coeff;

                Poly *dup = runner->next;
                runner->next = runner->next->next;
                free(dup);
            } else runner = runner -> next;
        }

        curr = curr->next;
    }
}

void printPoly(Poly *head) {
    Poly *temp = head;
    while (temp != NULL) {
        if (temp->exp==0) printf("%d", temp->coeff);
        else printf("%dx^%d", temp->coeff, temp->exp);
        if (temp -> next != NULL) printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Poly *p1=NULL, *p2 = NULL;
    int coeff, exp;

    while (true) {
        printf("add node in p1? ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d%d", &coeff, &exp);
            p1 = insert(p1, coeff, exp);
        } else if (choice == 0) break;
    }

    while (true) {
        printf("add node in p2? ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d%d", &coeff, &exp);
            p2 = insert(p2, coeff, exp);
        } else if (choice == 0) break;
    }

    printPoly(p1);
    printPoly(p2);
    Poly *res = mulPoly(p1, p2);
    combine(res);
    printPoly(res);

}