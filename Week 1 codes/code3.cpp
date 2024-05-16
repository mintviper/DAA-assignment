
III. Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether a given key element is present in the sorted array or not. For an array 
arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k
] and so on. Once the interval (arr[2k
] 
< key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k
to find the element 
key. (Complexity < O(n), where n is the number of elements need to be scanned for searching): 
Jump Search
Input format:
The first line contains number of test cases, T.
For each test case, there will be three input lines.
First line contains n (the size of array).
Second line contains n space-separated integers describing array.
Third line contains the key element that need to be searched in the array.
Output format:
The output will have T number of lines. 
For each test case, output will be “Present” if the key element is found in the array, otherwise 
“Not Present”.


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int jump_search(int a[], int n, int k, int *c) {
    int j = sqrt(n);
    int p = 0, q = 0;

    while (q < n && a[q] < k) {
        p = q;
        q += j;
        (*c)++;
    }

    for (int i = p; i < (q < n ? q : n); ++i) {
        (*c)++;
        if (a[i] == k) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        int a[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }

        int k;
        scanf("%d", &k);

        int c = 0;
        int found = jump_search(a, n, k, &c);

        if (found) {
            printf("Present\n");
        } else {
            printf("Not Present\n");
        }
        printf("Comparisons: %d\n", c);
    }

    return 0;
}
