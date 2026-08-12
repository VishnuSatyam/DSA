/*First, understand what nums[i] means

At index i:

nums[i] = maximum number of steps you can jump forward

Example:

[2, 3, 1, 1, 4]

From index 0, you can reach:

0 → 1
0 → 2

The question is:

Can I reach the last index?

The key observation

Don't think:

"Which index should I jump to?"

Instead ask:

"How far can I reach so far?"

Maintain:

int maxReach = 0;

This represents:

The furthest index that I can currently reach.

Now scan from left to right.

At index i, if:

i > maxReach

then we've reached an index that was never reachable.

Therefore:

false

Otherwise, from this index we can potentially reach:

i + nums[i]

So update:

maxReach = max(maxReach, i + nums[i]);
Example
[2, 3, 1, 1, 4]

Start:

maxReach = 0

Index 0:

0 <= maxReach
maxReach = max(0, 0 + 2)
         = 2

Index 1:

1 <= 2

maxReach = max(2, 1 + 3)
         = 4

Now:

maxReach = 4

Last index is 4.

Done → true.*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) return false;

            maxReach = max(maxReach, i + nums[i]);

            if (maxReach >= nums.size() - 1) return true;
        }

        return true;
    }
};

// tc is O(n) and sc is O(1)