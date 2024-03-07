## Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and 
two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead 
be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, 
where the first m elements denote the elements that should be merged, and the last n 
elements are set to 0 and should be ignored. nums2 has a length of n.

### Example
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

### Solution:
Have three pointers, p1, p2, p_merged. All of them should start at the end of the arrays, 
and we set the last element in the merged list to the bigger element of the two. 

```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //ptr_merged = n+m - 1;
        int ptr1 = m - 1;
        int ptr2 = n - 1;

        for (int ptr_merged = n+m - 1; ptr_merged >= 0; ptr_merged--){
            // base case: pointer has reached start of array
            if (ptr1 < 0){
                nums1[ptr_merged] = nums2[ptr2];
                ptr2--;
            }
            else if (ptr2 < 0){
                nums1[ptr_merged] = nums1[ptr1];
                ptr1--;
            }
            else if (nums1[ptr1] >= nums2[ptr2]){
                // ptr1 has larger element => take it 
                nums1[ptr_merged] = nums1[ptr1];
                ptr1--;
            }
            else {
                // ptr2 has larger element => take it 
                nums1[ptr_merged] = nums2[ptr2];
                ptr2--;
            }
        }
    }
};
```
 
