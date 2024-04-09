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

or 

Simplified code, where we loop through each element, and only increment b, if we found a new unique element.
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int b=0;
        for (auto ele : nums){
            if (b == 0 || nums[b-1] != ele){
                nums[b] = ele;
                b++;
            }
        }
        
        return b;
    }
};
```

## Remove Duplicates from Sorted Array II

Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at **most twice**. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

### Example
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

### Solution (C++)
The idea is similar to before. We go through each element, and decide if we want to insert it. If it's the first two elements, they can be inserted anyways or if the second last unique element is not equals.

```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int b = 0;

        for(auto ele : nums){
            if(b <= 1 || nums[b-2] != ele){
                nums[b] = ele;
                b++;
            }
        }

        return b;

    }
};
```

## Majority Element
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Could you solve the problem in linear time and in O(1) space?

### Example
Input: nums = [3,2,3]
Output: 3

### Solution (C++)
Go through array, increment majority element, decrement if it's different. Set new majority, if count is 0.

```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = -1;
        int ctr = 0;

        for(auto ele : nums){
            if (ctr == 0){
                maj = ele;
                ctr = 1;
            }else if (maj != ele){
                ctr--;
            }else if (maj == ele){
                ctr++;
            }
        }

        return maj;
    }
};
```

## Rotate Array
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Could you do it in-place with O(1) extra space?

### Example
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

### Solution (C++)
The idea is two do the "reverse" approach: You reverse nums once. Then you reverse the subarrays in length k and n-k separately.
You can either use built-in reverse functions (for C++: reverse()) or code it your own. For practice, I coded my own reverse function.
To do that, do a swap function, where first element gets swapped with last, second with second last etc., so switch i with n-i.

Note that k can be larger than n in some test cases. You need to handle it by k = k % n since it's has cyclic equivalence.

```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n; // ensure k is within 0 to (n-1), as rotation of n same as k=0.
        // one could also use reverse(nums.begin(), nums.end());
        custom_reverse(nums, 0, nums.size()-1);
        custom_reverse(nums, 0, k-1);
        custom_reverse(nums, k, nums.size()-1);
    }
    
    void custom_reverse(vector<int>& nums, int a, int b){
        for(int i=0; i < (b+1-a) / 2; i++){
            int temp = nums[a+i];
            nums[a+i] = nums[b-i];
            nums[b-i] = temp;
        }
    }

};
```


## Best Time to Buy and Sell Stock
You are given an array prices where prices[i] is the price of a given stock on the i-th day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

### Example
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

### Solution (C++)
Clearly we go from left to right. The way to tackle this problem is to look at two cases: (1) If the next day has a larger price and (2) if the next day has a lower price. If price stays the same, trivial case, don't do anything at all.
(1) easy case, we update our max_profit.
(2) in case of a lower price, it's definitely better to "buy" this stock instead of the older one, as for ANY new price coming, it's always better to have a lower buy price for maximum profit.

That's it!

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_buy = prices[0];
        int n=prices.size();
        for(int i=0; i<n; i++){
            if(prices[i] < min_buy){
                min_buy = prices[i];
            } else if(max_profit < (prices[i] - min_buy)){
                max_profit =  prices[i] - min_buy;
            }   
        }

        return max_profit;
    }
};
```

