#include "other_operations.h"
#include "graph_operations.h"

int main() {
    int arr[10] = {3,5,2,4,1,9,6,8,7,0};
    comparison_sort(arr,10);

    char *str = "Hello World Boys and Girls.";
    char *pattern = " and";
    string_pattern_search(str,pattern);

    int arr1[10] = {4,1,4,2,3,2,1,4,5,1};
    distribution_counting_sort(arr1,10,1,6);

    shortest_spanning_tree();

    return 0;
}