#include <stdio.h>
#include <stdlib.h>
typedef struct typenode *typeptr;
typedef struct typenode {int info; typeptr next;} typenode;
int main() {
    typeptr a, b, c, d;
    a = (typenode *)malloc(sizeof(typenode));
    b = (typenode *)malloc(sizeof(typenode));
    d = b;
    a->info = 20;
    b->info = 4 * a->info - 10;
    c = a;
    d->next = a;
    c->next = d;
    c->info = 2 * d->info;
    b->next = c;
    b->info = 30;
    printf("a->next->info / d 30 = %d\n", a->next->info);
    printf("b->next->info / c 140 = %d\n", b->next->info);
    printf("c->next->info / d 30 = %d\n", c->next->info);
    printf("d->next->info / c 140 = %d ", d->next->info);
    return 0;
}
