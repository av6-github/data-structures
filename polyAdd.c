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

Poly *addPoly(Poly *p1, Poly *p2) {
    Poly *res = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            res = insert(res, p1->coeff+p2->coeff, p1->exp);
            p1=p1->next;
            p2=p2->next;
        } else if (p1->exp > p2->exp) {
            res = insert(res, p1->coeff, p1->exp);
            p1=p1->next;
        } else {
            res = insert(res, p2->coeff, p2->exp);
            p2=p2->next;
        }
    }

    while (p1 != NULL) {
        res = insert(res, p1->coeff, p1->exp);
        p1=p1->next;
    }

    while (p2 != NULL) {
        res = insert(res, p2->coeff, p2->exp);
        p2=p2->next;
    }

    return res;

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
    printPoly(addPoly(p1, p2));


}