#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &num)
{
    // Set to store unique triplets
    set<vector<int>> st;

    // Try all possible triplets
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {

                // Check if sum is zero
                if (num[i] + num[j] + num[k] == 0) {

                    // Store the triplet
                    vector<int> temp = {num[i], num[j], num[k]};

                    // Sort to avoid duplicates
                    sort(temp.begin(), temp.end());

                    // Insert into set
                    st.insert(temp);
                }
            }
        }
    }

    // Convert set to vector
    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    vector<vector<int>> result = triplet(n, num);

    // Print the triplets
    for (auto &t : result) {
        for (int x : t) {  
                                      /*Outer loop → each triplet
                                        Inner loop → each number in that triplet*/
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}


// better approach 

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> triplet(int n, vector<int> &num)
{
    set<vector<int>> st;
    for(int i = 0; i<n; i++) {
        set<int> hashset; // we are using hashset here because each time i moves hashset start fresh 
        for(int j = i+1; j<n; j++) {
            int third = -(num[i] + num[j]);
            if(hashset.find(third) != hashset.end()) {
                vector<int> temp = {num[i], num[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(num[j]); // each time we move j we keep storing previous j's in hashset  
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// optimal approach 

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &num) {
    vector<vector<int>> ans;

    sort(num.begin(), num.end());

    for (int i = 0; i < n; i++) {

        if (i > 0 && num[i] == num[i - 1]) continue;
        if (num[i] > 0) break;   // optimization

        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            int sum = num[i] + num[j] + num[k];

            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                ans.push_back({num[i], num[j], num[k]});

                while (j < k && num[j] == num[j + 1]) j++;
                while (j < k && num[k] == num[k - 1]) k--;

                j++;
                k--;
            }
        }
    }
    return ans;
}
