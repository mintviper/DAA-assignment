II. Given an already sorted array of positive integers, design an algorithm and implement it using a 
program to find whether given key element is present in the array or not. Also, find total number 
of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input).


#include <stdio.h>
#include <stdlib.h>

int binary_search(int a[], int n, int k, int *c) {
    qsort(a, n, sizeof(int), cmp);

    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        (*c)++;

        if (a[mid] == k) {
            return 1;
        } else if (a[mid] < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return 0;
}

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
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
        int found = binary_search(a, n, k, &c);

        if (found) {
            printf("Present\n");
        } else {
            printf("Not Present\n");
        }
        printf("Comparisons: %d\n", c);
    }

    return 0;
}
