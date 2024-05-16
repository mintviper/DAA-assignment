/*
 Given a sequence of matrices, write an algorithm to find most efficient way to
multiply these matrices together. To find the optimal solution, you need to find the
order in which these matrices should be multiplied.
Input Format:
First line of input will take number of matrices n that you need to multiply.
For each line i in n, take two inputs which will represent dimensions aXb of matrix i.
Output Format:
Output will be the minimum number of operations that are required to multiply the list
of matrices.
Sample I/O Problem I:
Input: Output:
3 4500
10 30
30 5
5 60
Solved Example: Consider a sequence of three matrices A of size 10X30, B of size
30X5, C of size 5X60. Then,
(AB)C = (10*30*5) + (10*5*60) = 4500
operations A(BC) = (30*5*60) +
(10*30*60) = 27000 operations. Hence
the ouput of the program must be 4500
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainOrder(vector<pair<int, int>>& dimensions) {
    int n = dimensions.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int length = 2; length < n; length++) {
        for (int i = 1; i < n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1].first * dimensions[k].second * dimensions[j].second;
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }
    return dp[1][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    vector<pair<int, int>> dimensions(n);
    cout << "Enter dimensions of matrices (a X b): \n";
    for (int i = 0; i < n; i++) {
        cin >> dimensions[i].first >> dimensions[i].second;
    }

    int minOperations = matrixChainOrder(dimensions);
    cout << "Minimum number of operations required: " << minOperations << endl;

    return 0;
}
