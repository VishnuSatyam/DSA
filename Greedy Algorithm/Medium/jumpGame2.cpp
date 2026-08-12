class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, l = 0, r = 0;

        while(r < n - 1){
            int farthest = 0;

            for(int i = l; i <= r; i++){
                farthest = max(farthest, i + nums[i]);
            }

            l = r + 1;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
};

// tc is O(n) and sc is O(1)

/*Initial
nums = [2, 3, 1, 1, 4]
        0  1  2  3  4

jumps = 0
l = 0
r = 0

r < n-1 → 0 < 4 ✅

1st iteration

Current range:

[l, r] = [0, 0]

So we can currently reach only index 0.

i = 0

i + nums[i]
0 + 2 = 2

farthest = 2

Now update:

l = r + 1 = 1
r = farthest = 2
jumps = 1

So:

        [1-------2]
nums = [2,3,1,1,4]
        0 1 2 3 4

Meaning: with 1 jump, we can reach indices 1 through 2.

2nd iteration

Current range:

[l, r] = [1, 2]

We check both indices.

i = 1
1 + nums[1]
1 + 3 = 4

farthest = 4
i = 2
2 + nums[2]
2 + 1 = 3

farthest = max(4, 3)
         = 4

So:

farthest = 4

Update:

l = r + 1 = 3
r = farthest = 4
jumps = 2

Now:

nums = [2,3,1,1,4]
        0 1 2 3 4
                ↑
                r

r = 4 and n-1 = 4.

Therefore:

r < n-1
4 < 4 ❌

Loop stops.

Answer
jumps = 2*/