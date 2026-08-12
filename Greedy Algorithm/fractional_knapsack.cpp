/*Fractional Knapsack

The Fractional Knapsack problem is a classic Greedy Algorithm problem.

Problem

You have:

n items
Each item has a weight and value
Knapsack has maximum capacity W

Unlike 0/1 Knapsack, here you can take a fraction of an item.

Example

Suppose:

| Item | Value | Weight | Value/Weight |
| ---- | ----: | -----: | -----------: |
| A    |    60 |     10 |            6 |
| B    |   100 |     20 |            5 |
| C    |   120 |     30 |            4 |

Capacity = 50

We should take items in decreasing order of value/weight ratio.

Take A completely → weight 10, value 60
Take B completely → weight 20, value 100
Remaining capacity = 20
C weighs 30, but we can take 20/30 of it.

Value obtained from C:

120× (20/30) = 80
Therefore:

60+100+80=240
	​


Answer = 240

Why Greedy Works?

The key idea is:

Always take the item having the highest value per unit weight first.*/

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<double, pair<int, int>>> items;

        for (int i = 0; i < val.size(); i++) {
            items.push_back({(double)val[i] / wt[i], {val[i], wt[i]}});
        }

        sort(items.rbegin(), items.rend());

        double ans = 0;

        for (auto item : items) {
            double ratio = item.first;
            int value = item.second.first;
            int weight = item.second.second;

            if (capacity >= weight) {
                ans += value;
                capacity -= weight;
            } else {
                ans += ratio * capacity;
                break;
            }
        }

        return ans;
    }
};

// tc is O(n log n)