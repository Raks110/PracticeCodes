//
// Created by rakshitgl on 10/29/2019.
//

#ifndef P1_GRAPH_OPERATIONS_H
#define P1_GRAPH_OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>

#define INF 9999

void read_graph(int **arr, int vertices){

    printf("\nEnter edges and their weights\n");
    int i,j,v;

    for (int k=0;k<vertices;k++) {
        for (int l=0;l<vertices;l++)
            arr[k][l] = INF;
    }

    while(1){

        scanf("%d",&i);
        scanf("%d",&j);
        scanf("%d",&v);

        if(i == -1 || j == -1 || v == -1)
            break;

        if(i >= vertices || j >= vertices) {
            printf("W102: Index out of bounds.\n");
            continue;
        }

        arr[i][j] = v;
        arr[j][i] = v;
    }
}

int search(const int *arr, int length, int key){

    for (int i = 0; i < length; ++i) {

        if(arr[i] == key)
            return 1;
    }

    return 0;
}

void compute_min(int **arr, int vertices){

    int *res = (int*)malloc(sizeof(int) * vertices);

    res[0] = 0;
    int size_res = 1;

    while(size_res != vertices){

        int min = INF;
        int min_node = -1;
        int from_node = -1;

        for(int i=0;i<vertices;i++){
            if(!search(res,size_res,i))
                continue;
            for (int j=0;j<vertices;j++) {
                if(search(res,size_res,j))
                    continue;

                if(arr[i][j] < min){
                    min = arr[i][j];
                    min_node = j;
                    from_node = i;
                }
            }
        }
        res[size_res] = min_node;
        printf("%3d %3d %3d\n",from_node,min_node,min);
        size_res++;
    }
}

void shortest_spanning_tree(){
    int **arr, vertices;

    printf("\nEnter vertices: ");
    scanf("%d",&vertices);

    arr = (int**)malloc(sizeof(int)*vertices);
    for(int i=0;i<vertices;i++){
        arr[i] = (int*)malloc(sizeof(int) * vertices);
    }

    read_graph(arr,vertices);
    compute_min(arr,vertices);
}

#endif //P1_GRAPH_OPERATIONS_H
