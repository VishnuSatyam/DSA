#include <string>
using namespace std;

class Solution {
public:
    string getActual(string input) {
        string actual = "";
        int hashCount = 0;

        for (int i = input.length() - 1; i >= 0; i--) {
            if (input[i] == '#') {
                hashCount++;
            }
            else {
                if (hashCount > 0) {
                    hashCount--;  // skip this character
                } else {
                    // insert at beginning
                    actual = input[i] + actual;
                }
            }
        }

        return actual;
    }

    bool backspaceCompare(string s, string t) {
        return getActual(s) == getActual(t);
    }
};

// tc is O(n) and sc is O(n)