//
// Created by rakshitgl on 10/29/2019.
//

#ifndef P1_OTHER_OPERATIONS_H
#define P1_OTHER_OPERATIONS_H

#include "array_operations.h"
#include <string.h>

void comparison_sort(const int *arr, int n){

    int result[n], final[n];

    for(int i=0;i<n;i++){
        result[i] = 0;
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){

            if(arr[j] < arr[i]){
                result[i]++;
            }
            else{
                result[j]++;
            }
        }
    }

    for(int i=0;i<n;i++){

        final[result[i]] = arr[i];
    }

    print_array(final,n, "Comparison Counting Sort");
}

void distribution_counting_sort(const int *arr, int n, int l, int u){

    int distinct[u-l], result[n];

    for(int i=0;i<u-l;i++){
        distinct[i] = 0;
    }

    for(int i=0;i<n;i++){
        distinct[arr[i]-1]++;
    }

    for(int i=1;i<u-l;i++){
        distinct[i] = distinct[i-1] + distinct[i];
    }

    for(int i =0;i<n;i++){

        int j = arr[i]-1;
        distinct[j]--;
        result[distinct[j]] = arr[i];
    }

    print_array(result,n,"Distribution Counting Sort");
}

int max(int a, int b){
    return a > b ? a : b;
}

void string_pattern_search(char *str, char *pattern){

    unsigned int bad_chars[150];
    const int NUM_CHARS = 150;

    for(int i=0;i<NUM_CHARS;i++){
        bad_chars[i] = -1;
    }

    for(unsigned int i=0;i<strlen(pattern);i++){
        bad_chars[(int) pattern[i]] = i;
    }

    int shift = 0;

    while(shift <= (strlen(str) - strlen(pattern))){

        int j = (int) strlen(pattern) - 1;

        while(j >= 0 && pattern[j] == str[shift + j])
            j--;

        if(j < 0){

            printf("\nMOORE: Pattern occurs at position %d.\n",shift);
            return;
        }
        else{

            shift += max(1,j-bad_chars[(int) str[shift+j]]);
        }
    }

    printf("\nMOORE: Pattern was not found.\n");
}

#endif //P1_OTHER_OPERATIONS_H
