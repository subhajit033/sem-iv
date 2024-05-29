#include <stdio.h>
#include <limits.h>

#define V 4

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to reverse an array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

// Function to find the next permutation of an array
int findNextPermutation(int arr[], int n) {
    int i, j;

    // Find the largest index i such that arr[i] < arr[i+1]
    for (i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            break;
        }
    }

    // If no such index exists, the permutation is the last permutation
    if (i < 0) {
        return 0;
    }

    // Find the largest index j greater than i such that arr[i] < arr[j]
    for (j = n - 1; j > i; j--) {
        if (arr[j] > arr[i]) {
            break;
        }
    }

    // Swap arr[i] and arr[j]
    swap(&arr[i], &arr[j]);

    // Reverse the suffix starting at arr[i+1]
    reverse(arr, i + 1, n - 1);

    return 1;
}

// Function to implement traveling Salesman Problem
int travellingSalesmanProblem(int graph[][V], int s) {
    // Store all vertices apart from the source vertex
    int vertex[V - 1];
    for (int i = 0, j = 0; i < V; i++) {
        if (i != s) {
            vertex[j++] = i;
        }
    }

    // Store minimum weight Hamiltonian Cycle
    int min_path = INT_MAX;
    do {
        // Store current path weight (cost)
        int current_pathweight = 0;

        // Compute current path weight
        int k = s;
        for (int i = 0; i < V - 1; i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];

        // Update minimum path
        min_path = min(min_path, current_pathweight);

    } while (findNextPermutation(vertex, V - 1));

    return min_path;
}

// Driver code
int main() {
    // Matrix representation of the graph
    int graph[V][V] = {{0, 10, 15, 20},
                        {10, 0, 35, 25},
                        {15, 35, 0, 30},
                        {20, 25, 30, 0}};
    int s = 0;
    printf("%d\n", travellingSalesmanProblem(graph, s));
    return 0;
}
