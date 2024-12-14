# LeetCode

Notes and solution for LeetCode problems [(Top Interview 150)](https://leetcode.com/studyplan/top-interview-150/) by William Wong.

The problems are split into the following topics:

| Topic                      | Done   |
|-----------------------------|--------|
| Array / Strings             |   20/24     |
| Two Pointers               |    5/5    |
| Sliding Window             |    2/4    |
| Matrix                     |    5/5   |
| Hashmap                    |    9/9    |
| Intervals                  |    4/4    |
| Stack                       |   5/5     |
| Linked List                |    10/11    |
| Binary Tree General         |    12/13    |
| Binary Tree BFS            |    4/4   |
| Binary Search Tree         |    3/3    |
| Graph General               |    0/6    |
| Graph BFS                  |    0/3    |
| Trie                        |    0/3    |
| Backtracking               |   0/7     |
| Divide & Conquer           |    1/5    |
| Kadane's Algorithm          |    0/2    |
| Binary Search              |     1/7   |
| Heap                        |   1/4     |
| Bit Manipulation           |    4/6    |
| Math                        |    3/6    |
| 1D DP                       |   5/5     |
| Multidim. DP               |    0/8    |

In my [blog](https://wongwil.github.io/), I offer a summary of the thought process and code (usually in Java, Python or C++) for each solved problem.
You can also follow my solutions on my  [leetcode profile](https://leetcode.com/u/wongwil/).
## General common mistakes
In LeetCode, the tasks often require you to modify an array of size n in-place. In some cases, the modified array will have a size smaller than n (e.g. removing certain elements). The tester verifies the array based on the returned parameter k, which denotes the number of the first k-elements which are suppossed to be "correct" according to the task. Make sure k is correct! Depending on the task description which can be quite ambigious, you should return either 1) number of elements or 2) index of the last element.


