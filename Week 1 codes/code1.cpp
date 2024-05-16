I. Given an array of nonnegative integers, design a linear algorithm and implement it using a 
program to find whether given key element is present in the array or not. Also, find total number 
of comparisons for each input case. (Time Complexity = O(n), where n is the size of input) Sample 
I/O Problem - 1:

#include <stdio.h>

int linear_search(int a[], int n, int k, int *c) {
    for (int i = 0; i < n; ++i) {
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
        int found = linear_search(a, n, k, &c);

        if (found) {
            printf("Present\n");
        } else {
            printf("Not Present\n");
        }
        printf("Comparisons: %d\n", c);
    }

    return 0;
}


