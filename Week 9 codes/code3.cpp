/*

III. Given an array of elements. Assume arr[i] represents the size of file i. Write an algorithm and a
program to merge all these files into single file with minimum computation. For given two files
A and B with sizes m and n, computation cost of merging them is O(m+n). (Hint: use greedy
approach)
Input Format:
First line will take the size n of the array.
Second line will take array s an input.
Output Format:
Output will be the minimum computation cost required to merge all the elements of the array.
Sample I/O Problem III:
Input: Output:
10 960
10 5 100 50 20 15 5 20 100 10
Solved example: Consider arr[5] = { 10, 5, 100, 50, 20, 15}. As per the brute force approach,
first of all merge first two files (having 10 and 5 file size).
Cost of merging will be = 10+5=15.
List will become {15, 100, 50, 20, 15}.
Similarly, again merging first two files ( i.e. having 15 and 100 file size).
Cost of merging will be = 15+100=115.
List will become {115, 50, 20, 15}.
For the subsequent steps the list becomes, (165, 20, 15}, {185, 15} and {200}.
Therefore total cost of merging = 15+115+165+185+200 = 680.
But this is not minimum computation cost. To find minimum cost, consider the order arr[5] = {5,
10, 15, 20, 50, 100}. By applying the same approach, the total cost of merging =
15+30+50+100+200 = 395.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
    double fraction;
};

bool compare(Item i1, Item i2) {
    return (double)i1.value / i1.weight > (double)i2.value / i2.weight;
}

double fractionalKnapsack(int N, vector<int>& weights, vector<int>& values, int W) {
    vector<Item> items(N);
    for (int i = 0; i < N; i++) {
        items[i].value = values[i];
        items[i].weight = weights[i];
        items[i].fraction = 0.0;
    }

    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int remainingWeight = W;

    for (int i = 0; i < N; i++) {
        if (remainingWeight <= 0)
            break;

        if (items[i].weight <= remainingWeight) {
            totalValue += items[i].value;
            remainingWeight -= items[i].weight;
            items[i].fraction = 1.0;
        } else {
            double fraction = (double)remainingWeight / items[i].weight;
            totalValue += fraction * items[i].value;
            remainingWeight = 0;
            items[i].fraction = fraction;
        }
    }

    cout << "Maximum value that can be achieved: " << totalValue << endl;
    cout << "Selected items with their fraction taken:\n";
    for (int i = 0; i < N; i++) {
        cout << "Item " << i + 1 << ": " << items[i].fraction << " fraction taken\n";
    }

    return totalValue;
}

int main() {
    int N;
    cin >> N;

    vector<int> weights(N), values(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }

    int W;
    cin >> W;

    fractionalKnapsack(N, weights, values, W);

    return 0;
}
