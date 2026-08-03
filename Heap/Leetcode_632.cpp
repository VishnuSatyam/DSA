/*Brute Force Idea

We need to find a range [L, R] such that:

Every one of the k lists contributes at least one element inside [L, R].
Among all such ranges, choose the one with the smallest width.

The brute force approach is:

Try every possible range and check if it covers all lists.

Step 1

Collect every element from every list.

Example:

List1 : 4 10 15 24 26
List2 : 0 9 12 20
List3 : 5 18 22 30

Store all elements in one array.

4 10 15 24 26 0 9 12 20 5 18 22 30

Sort it.

0 4 5 9 10 12 15 18 20 22 24 26 30

Suppose there are N total numbers.

Step 2

Choose every possible pair.

[0,4]
[0,5]
[0,9]
...
[0,30]

[4,5]
[4,9]
...
[4,30]

...

[26,30]

There are roughly

N²

possible ranges.

Step 3

For every range

[L,R]

check whether every list has at least one element inside it.

Example

Range

[20,24]

Check

List1

4 10 15 24 26
          ✓

List2

0 9 12 20
       ✓

List3

5 18 22 30
      ✓

All three lists contribute.

So this is a valid range.*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int currentMax = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            currentMax = max(currentMax, nums[i][0]);
        }

        int start = 0, end = INT_MAX;

        while (true) {

            auto curr = pq.top();
            pq.pop();

            int value = curr[0];
            int row = curr[1];
            int col = curr[2];

            if (currentMax - value < end - start) {
                start = value;
                end = currentMax;
            }

            if (col + 1 == nums[row].size())
                break;

            pq.push({nums[row][col + 1], row, col + 1});
            currentMax = max(currentMax, nums[row][col + 1]);
        }

        return {start, end};
    }
};

/*Time: O(N log k)
Space: O(k)*/


/*Idea

Suppose

List1 : 4 10 15 24 26
List2 : 0 9 12 20
List3 : 5 18 22 30

Initially, take the first element of every list.

4 (L1)
0 (L2)
5 (L3)

Current range

min = 0
max = 5

Range = [0,5]

This range contains one element from every list.

Which pointer should we move?

Suppose we move the largest element (5).

4
0
18

Range becomes

[0,18]

It only becomes larger.

Instead, move the smallest element.

Current minimum is

0 (List2)

Advance List2.

4
9
5

Now

min = 4
max = 9

Range = [4,9]

The range may shrink.

Important Observation

To improve the range, always move the list containing the current minimum element.

How do we quickly find the minimum?

Use a Min Heap.

Each heap node stores

(value, row, col)

value -> actual number
row   -> which list
col   -> index inside that list

Initially insert

(4,0,0)
(0,1,0)
(5,2,0)

Heap top is always the smallest element.

Also maintain

currentMax

because the largest element among the current k elements determines the right boundary of the range.

Algorithm
Step 1

Insert the first element of every list into the heap.

Also compute

currentMax
Step 2

Current range is

heap.top().value
to
currentMax

Update the answer if this range is better.

Step 3

Remove the minimum element.

Suppose we removed

(value,row,col)

Advance in the same list.

col++

If another element exists,

push

(nums[row][col+1], row, col+1)

Update

currentMax
Step 4

Repeat until one list finishes.

Why stop?

Because once one list has no more elements, we cannot have a range containing at least one element from every list anymore.

Dry Run
L1 : 4 10 15 24 26
L2 : 0 9 12 20
L3 : 5 18 22 30

Initial heap

0 4 5
max = 5

Range = [0,5]

Pop 0

Push 9

Heap

4 5 9

max = 9

Range = [4,9]

Pop 4

Push 10

Heap

5 9 10

max = 10

Range = [5,10]

Pop 5

Push 18

Heap

9 10 18

max = 18

Range = [9,18]

Continue...

Eventually the best range becomes

[20,24]

which is the answer.*/