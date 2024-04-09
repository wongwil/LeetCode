# LeetCode

Notes and solution for LeetCode problems [(Top Interview 150)](https://leetcode.com/studyplan/top-interview-150/) by William Wong.

The problems are split into the following topics:

| Topic                      | Done   |
|-----------------------------|--------|
| Array / Strings             |   7/24     |
| Two Pointers               |        |
| Sliding Window             |        |
| Matrix                     |        |
| Hashmap                    |        |
| Intervals                  |        |
| Stack                       |        |
| Linked List                |        |
| Binary Tree General         |        |
| Binary Tree BFS            |        |
| Binary Search Tree         |        |
| Graph General               |        |
| Graph BFS                  |        |
| Trie                        |        |
| Backtracking               |        |
| Divide & Conquer           |        |
| Kadane's Algorithm          |        |
| Binary Search              |        |
| Heap                        |        |
| Bit Manipulation           |        |
| Math                        |        |
| 1D DP                       |        |
| Multidim. DP               |        |

I include a summary of the thought process and code (usually in Java, Python or C++).

## General common mistakes
In LeetCode, the tasks often require you to modify an array of size n in-place. In some cases, the modified array will have a size smaller than n (e.g. removing certain elements). The tester verifies the array based on the returned parameter k, which denotes the number of the first k-elements which are suppossed to be "correct" according to the task. Make sure k is correct! Depending on the task description which can be quite ambigious, you should return either 1) number of elements or 2) index of the last element.
