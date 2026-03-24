class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        // Case 1: k == 0
        if (k == 0) return result;

        for (int i = 0; i < n; i++) {
            int sum = 0;

            // Case 2: k > 0 → forward
            if (k > 0) {
                for (int j = 1; j <= k; j++) {
                    sum += code[(i + j) % n];
                }
            }
            // Case 3: k < 0 → backward
            else {
                for (int j = 1; j <= abs(k); j++) {
                    sum += code[(i - j + n) % n];
                }
            }

            result[i] = sum;
        }

        return result;
    }
};

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        
        if (k == 0) return result;

        int start, end, sum = 0;

        if (k > 0) {
            start = 1;
            end = k;
        } else {
            k = abs(k);
            start = n - k;
            end = n - 1;
        }

        // initial window sum
        for (int i = start; i <= end; i++) {
            sum += code[i % n];
        }

        for (int i = 0; i < n; i++) {
            result[i] = sum;

            // slide window
            sum -= code[start % n];
            start++;
            end++;
            sum += code[end % n];
        }

        return result;
    }
};


//optimal approach 