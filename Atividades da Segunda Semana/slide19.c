#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    int t, j = 1, *p, *g;
    t = 5;

    p = &t;

    j = 3;

    g = &j;

    *p = (*g + t) * 2;

    *g = 4;

    g = p;

    for(j = 0; j < 2;j++) {
        *g = t*j + 1;

    }

    *p = t + j + *g;



    printf("%d\n", *p);
}

// t   j  p  g
//     1
// 5   1 
// 5   1  &t 
// 5   3  &t
// 5   3  &t &j
// 16  3  &t &j
// 16  4  &t &j
// 16  4  &t &t
// 1  1  &t &t
// 2  2  &t &t
// 6  2  &t &t