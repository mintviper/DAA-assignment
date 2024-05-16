/*Given a knapsack of maximum capacity w. N items are provided, each having its
own value and weight. You have to Design an algorithm and implement it using a
program to find the list of the selected items such that the final selected content has
weight w and has maximum value. You can take fractions of items,i.e. the items can
be broken into smaller pieces so that you have to carry
only a fraction xi of item i, where 0 ≤xi≤ 1.
Input Format:
First input line will take number of items N which are provided.
Second input line will contain N space-separated array containing weights of all N items.
Third input line will contain N space-separated array containing values of all N items.
Last line of the input will take the maximum capacity w of knapsack.
Output Format:
First output line will give maximum value that can be achieved.
Next Line of output will give list of items selected along with their fraction of amount which has
been taken.
*/

  #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
    double density;
    int index;
};

bool compare(Item i1, Item i2) {
    return i1.density > i2.density;
}

vector<pair<int, double>> fractionalKnapsack(int N, vector<int>& weights, vector<int>& values, int W) {
    vector<Item> items(N);
    for (int i = 0; i < N; i++) {
        items[i].value = values[i];
        items[i].weight = weights[i];
        items[i].density = (double)values[i] / weights[i];
        items[i].index = i;
    }

    sort(items.begin(), items.end(), compare);

    vector<pair<int, double>> selectedItems;

    int remainingWeight = W;
    for (int i = 0; i < N; i++) {
        if (remainingWeight <= 0)
            break;

        if (items[i].weight <= remainingWeight) {
            selectedItems.push_back({ items[i].index, 1.0 });
            remainingWeight -= items[i].weight;
        } else {
            double fraction = (double)remainingWeight / items[i].weight;
            selectedItems.push_back({ items[i].index, fraction });
            remainingWeight = 0;
        }
    }

    return selectedItems;
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

    vector<pair<int, double>> selectedItems = fractionalKnapsack(N, weights, values, W);

    double maxValue = 0;
    for (auto item : selectedItems) {
        cout << item.first + 1 << ": " << item.second << endl;
        maxValue += item.second * values[item.first];
    }

    cout << maxValue << endl;

    return 0;
}
