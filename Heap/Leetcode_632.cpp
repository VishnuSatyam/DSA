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

