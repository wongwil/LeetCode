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

### Solution (C++)
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

## Remove Element
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
- Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
- Return k (❗ EDIT: the exercise had a mistake on leetcode. it is supposed to return the pointer of the last element, so it should be k-1)

 ### Example
- Input: nums = [3,2,2,3], val = 3
- Output: 2, nums = [2,2,_,_] (❗ EDIT: should return 1)
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).

### Solution (C++)
The idea is to go through nums from left to right. We skip values that are equals val but with a pointer, we keep track of the last element which was val to insert the next element which is not val.
When we insert a valid element, we increment our pointer.

```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ptr = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == val){
                // skip and do nothing, we increment i in the next iteration
            } else{
                nums[ptr] = nums[i];
                ptr++;
            }
        }
        return ptr; // required to return pointer of last element
    }
};
```

## Remove Duplicates from Sorted Array

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.

### Example
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

### Solution (C++)
The idea is to have to indeces. One index "a" which iterates through the whole list, "looking for the next unique element" and
one in-place index b, which defines the last unique element.
As the list is sorted, we can check for the next unequal element than the element in index b.

```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int b = 0; // inplace index, points to last unique element

        // a starts at 1, since the 0-th element is always unique
        for (int a = 1; a < nums.size(); a++){
            if(nums[b] != nums[a]){ // compare last unique to new
                nums[b+1] = nums[a]; // set new unique element 
                b++;
            }
        }

        // ! increment by 1, as this should be the number of unique elements
        return b+1; 
    }
};
```
