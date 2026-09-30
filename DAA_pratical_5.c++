#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve 0/1 Knapsack
int knapsack(int capacity, vector<int>& weight, vector<int>& profit, int n)
{
    // Create DP table
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= capacity; w++)
        {
            // If current item can fit
            if (weight[i - 1] <= w)
            {
                // Maximum of including and excluding the item
                dp[i][w] = max(
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }
            else
            {
                // Cannot include the item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n);
    vector<int> profit(n);

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    cout << "Enter profits of items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }

    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    int maximumProfit = knapsack(capacity, weight, profit, n);

    cout << "Maximum Profit: " << maximumProfit << endl;

    return 0;
}