#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int m[3][3] = {0};


    for (size_t i=0; i < 3; i++) {
        for (size_t j=0; j < 3; j++) {
            scanf("%d", (*(m+i)+j));
        } 
    }

    for (size_t i=0; i < 3; i++) {
        for (size_t j=0; j < 3; j++) {
            printf("%d ", m[i][j]);
        } 
    }

    // int** p = m;

    // *p == m[0]
    // *(*p) == m[0][0];

    //m[i] == *(p + i)
    //m[i][j] == *(*(p+i) + j)


}