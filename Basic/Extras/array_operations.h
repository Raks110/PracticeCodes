//
// Created by rakshitgl on 10/29/2019.
//

#ifndef P1_ARRAY_OPERATIONS_H
#define P1_ARRAY_OPERATIONS_H

#include <stdio.h>

void print_array(const int *arr, int n, char *message){

    printf("\n====================================\n");
    printf("%s: ",message);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n====================================\n");
}

#endif //P1_ARRAY_OPERATIONS_H
