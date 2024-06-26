## Merge Sorted Array

You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and 
two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.

Merge `nums1` and `nums2` into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead 
be stored inside the array nums1. To accommodate this, `nums1` has a length of `m + n`, 
where the first m elements denote the elements that should be merged, and the last `n` 
elements are set to 0 and should be ignored. `nums2` has a length of n.

### Example
- Input: `nums1` = [1,2,3,0,0,0], `m` = 3, `nums2` = [2,5,6], `n` = 3
- Output: [1,2,2,3,5,6]
- Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

### Solution (C++)
The easiest and quickest solution in `O(n)` is to ave three pointers, `p1`, `p2`, `p_merged`. All of them should start at the end of the arrays, 
and we set the last element in the merged list to the bigger element of the two. 

```c++
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
Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in nums in-place. The order of the elements may be changed. Then return the number of elements in `nums` which are not equal to `val`.

Consider the number of elements in nums which are not equal to `val` be `k`, to get accepted, you need to do the following things:
- Change the array `nums` such that the first `k` elements of `nums` contain the elements which are not equal to `val`. The remaining elements of nums are not important as well as the size of nums.
- Return k (❗ EDIT: the exercise had a mistake on leetcode. It is supposed to return the pointer of the last element, so it should be `k-1`)

 ### Example
- Input: `nums` = [3,2,2,3], `val` = 3
- Output: 2, `nums` = [2,2,_,_] (❗ EDIT: should return 1)
- Explanation: Your function should return `k` = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned `k` (hence they are underscores).

### Solution (C++)
The idea is to go through `nums` from left to right. We skip values that are equals val but with a pointer, we keep track of the last element which was `val` to insert the next element which is not `val`.
When we insert a valid element, we increment our pointer.

```c++
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

Given an integer array `nums` sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in `nums`.

Consider the number of unique elements of `nums` to be `k`, to get accepted, you need to do the following things:

Change the array `nums` such that the first `k` elements of `nums` contain the unique elements in the order they were present in `nums` initially. The remaining elements of `nums` are not important as well as the size of `nums`.
Return `k`.

### Example
- Input: `nums` = [0,0,1,1,1,2,2,3,3,4]
- Output: 5, `nums` = [0,1,2,3,4,_,_,_,_,_]
- Explanation: Your function should return `k` = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned `k` (hence they are underscores).

### Solution (C++)
The idea is to have to indeces. One index `a` which iterates through the whole list, "looking for the next unique element" and one in-place index `b`, which defines the last unique element.
As the list is sorted, we can check for the next unequal element than the element in index b.

```c++
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
```c++
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

Given an integer array `nums` sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at **most twice**. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array `nums`. More formally, if there are `k` elements after removing the duplicates, then the first `k` elements of `nums` should hold the final result. It does not matter what you leave beyond the first `k` elements.

Return `k` after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

### Example
- Input: `nums` = [1,1,1,2,2,3]
- Output: 5, `nums` = [1,1,2,2,3,_]
- Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

### Solution (C++)
The idea is similar to before. We go through each element, and decide if we want to insert it. If it's the first two elements, they can be inserted anyways or if the second last unique element is not equals.

```c++
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
Given an array `nums` of size `n`, return the majority element.
The majority element is the element that appears more than $⌊n / 2⌋$ times. You may assume that the majority element always exists in the array.

Could you solve the problem in linear time and in O(1) space?

### Example
- Input: nums = [3,2,3]
- Output: 3

### Solution (C++)
Go through array, increment majority element, decrement if it's different. Set new majority, if count is 0.

```c++
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
Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.

Could you do it in-place with O(1) extra space?

### Example
- Input: `nums` = [1,2,3,4,5,6,7], `k` = 3
- Output: [5,6,7,1,2,3,4]

### Solution (C++)
The idea is two do the "reverse" approach: You reverse nums once. Then you reverse the subarrays in length `k` and `n-k` separately.
You can either use built-in reverse functions (for C++: reverse()) or code it your own. For practice, I coded my own reverse function.
To do that, do a swap function, where first element gets swapped with last, second with second last etc., so switch `i` with `n-i`.

Note that `k` can be larger than `n` in some test cases. You need to handle it by $k = k % n$ since it's has cyclic equivalence.

```c++
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
You are given an array `prices` where `prices[i]` is the price of a given stock on the i-th day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

### Example
- Input: prices = [7,1,5,3,6,4]
- Output: 5
- Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

### Solution (C++)
Clearly we go from left to right. The way to tackle this problem is to look at two cases: (1) If the next day has a larger price and (2) if the next day has a lower price. If price stays the same, trivial case, don't do anything at all.
- (1) easy case, we update our max_profit (if profit is larger than previous).
- (2) in case of a lower price, it's definitely better to "buy" this stock instead of the older one, as for ANY new price coming, it's always better to have a lower buy price for maximum profit.

That's it!

```c++
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

## Best Time to Buy and Sell Stock II
You are given an integer array `prices` where `prices[i]` is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

### Example
- Input: prices = [7,1,5,3,6,4]
- Output: 7
- Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

### Solution (C++)
Similar to before, we consider two cases: When the next day's price is larger (1) and lower (2).
- (1) In case it's larger, we definitely have to sell! One might wonder, why is that the case? Couldn't there be a later better day, where the stock price is higher? That's true, but by the definition of the task, we can always buy and sell the stock at the same day for the same price. For the array: 1 2 3 4, assuming we buy at day 0 (price=1), if we buy and sell the next day, we have the intermediate profit of 1. Proceeding the same way until the end of array, we have a total profit of 3, the same as when "keeping" the stock and wait until the last day to sell.
By doing this, we always ensure having intermediate profits, and in case of 1 2 1, waiting would actually result to no profit, so selling immediately after the stock price rises is better.
- (2) In case it's smaller, we update the buy_price. The reasoning is the same as previous task: For any future prices, a lower buy_price always results to a higher profit.

If you are more into math, one could imagine this approach as summing up the positive gradient in a non-linear graph from left to right.

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int buy_price = prices[0];

        for(int i=1; i < prices.size(); i++){
            if(buy_price < prices[i]){
                // there is a higher price, we sell
                max_profit += prices[i] - buy_price;
                buy_price = prices[i];
            } else if (buy_price > prices[i]){
                // there is a cheaper buy price, no profit but better "potential" for profit
                buy_price = prices[i];
            }
        }

        return max_profit;
    }
};
```

## Jump Game
You are given an integer array `nums`. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return `true` if you can reach the last index, or `false` otherwise.

### Example
Ex. 1:
- Input: nums = [2,3,1,1,4]
- Output: true
- Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Ex.2:
- Input: nums = [3,2,1,0,4]
- Output: false
- Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

### Solution (C++/Java)
The first (and slower) approach is DP. Each entry in our dp-array denotes if we can reach the end. To do that, one should look at the array from right to left (backwards). The last entry is cleary true, then we go one entry left, and check if any of the right entries (`dp[i]` of them) entries have one that is true. If that is the case, it means that the current i can also reach the end. We do this for each i, and check if `dp[0]` is true. However, this is in `O(n^2)`.
```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int dp[n];

        for(int i=0; i<n; i++){
            dp[i] = 0;
        }

        dp[n-1] = 1;

        for(int i=n-2; i>=0; i--){
            int min_id = min(n-1, nums[i]+i);
            for(int j=i; j<=min_id; j++){
                if(dp[j] == 1){
                    dp[i] = 1;
                    break;
                }
            }
            

        }
        
        return dp[0] == 1;
    }
};
```

The second approach looks at the problem from another perspective. One notices that an array without 0's e.g., `[1,4,5,2,4]` will always be true, since we can always move forward. Tricky cases are when there is a 0, e.g. `[1,4,0,5]`. Let's look at the entry `j`, where `dp[j] = 0`.
In that case, one could imagine this as an "obstacle" where the person has to "jump" over it to reach the end (unless `j` is the last element trivially). If we are not able to jump over `j` and we always land on `j` from previous entries, we cannot move further and get stuck.
Now, how do we find out if we can jump over `j`? The easiest way is to keep track of the "maximum_jump" entry as we iterate through entries that are not 0. When we land on 0, we check if the maximum_jump is larger than `j`, and we know that we can jump over it.
If at the end the maximum_jump is larger or equals `n-1`, we know we can reach the end.

```java
class Solution {
    public boolean canJump(int[] nums) {
        int max_jump = 0;
        int n = nums.length;

        for(int i=0; i<n; i++){
            if(nums[i] == 0 && i < n-1 && max_jump <= i){
                return false;
            }else if(max_jump < (i+nums[i])){
                max_jump = i+nums[i];
            }
        }
        
        return max_jump >= n-1;
    }
}
```

## Jump Game 2
You are given a 0-indexed array of integers `nums` of length `n`. You are initially positioned at `nums[0]`.

Each element `nums[i]` represents the maximum length of a forward jump from index `i`. In other words, if you are at `nums[i]`, you can jump to any `nums[i + j]` where:
`0 <= j <= nums[i]` and `i + j < n`
Return the minimum number of jumps to reach `nums[n - 1]`. The test cases are generated such that you can reach `nums[n - 1]`.
It's guaranteed that you can reach `nums[n - 1]`.

### Example
- Input: `nums` = [2,3,1,1,4]
- Output: 2
- Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

### Solution (Java)
Imagine splitting the array into little subarrays where we categorize entries together, that can be reached with the same amount of jumps.
For the given example it would be `[2],[3,1],[1,4]`.

In order to do so, we iterate from left to right. First we use 0 jumps and are at `i=0`. We look at the furthest point we can reach which is `i=3`. We know that any entries in between them can be reached with 1 jump. We go through each of them and keep track of the furthest point we can reach. All entries until that "furthest" point are in the "2-jump" category. If we reach the end of the "1-jump" category, we move onto the "2-jump" category and so on.
Trivially, if the answer is `j`, and we are in the "j-1-jump category" if we can land on `> j`, we can break.

```java
class Solution {
    public int jump(int[] nums) {
        // left to right, keep track of farthest point, increment jumps
        // if farthers point from previous jump reached

        // one could imagine this as a tree, where each level denotes the
        // min. number of jumps required to these nodes OR
        // imagine by splitting the array into little subsections where categorize
        // entries together, that can be reached with the same amount of jumps

        // e.g. 1 -> 2,3 -> 4,5,6 (3 requires 1 jump, 6 requires 2)
        // [1],[2,3],[4,5]
        int n = nums.length;
        int jumps = 0;
        int farthest = 0; // farthest point that can reached in the current "jump" level
        int end = 0; // denotest the end of the level in the tree, before going to next level

        for(int i=0; i<n-1; ++i){
            farthest = Math.max(farthest, nums[i]+i);

            if(farthest >= n-1){
                jumps++;
                return jumps;
            }

            if(i==end){ // if we iterated through all entries that could be reached from last jump
                end=farthest; 
                jumps++;
            }
        }

        return jumps;
    }
}
```

## H-index
Given an array of integers `citations` where `citations[i]` is the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

### Example
- Input: citations = [3,0,6,1,5]
- Output: 3
- Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.

### Solution 
Think of this problem like using a frequency diagram. For each possible h-value (0 - n), we keep track of papers that have exact h-citations which is in `O(n)`.
We iterate the frequency array from right to left, while cumulating the frequencies and break if `cumulative >= i`, trivially return i.

```java
class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;
        int freq[] = new int[n+1]; // frequency for each possible h_value

        for(int citation : citations){
            if (citation >= n){
                freq[n]++; // if it has more than n citations, it goes to h=n.
            }else{
                freq[citation]++;
            }
        }

        int cumulative = 0;
        for(int i=n; i>= 0; --i){
            cumulative += freq[i];

            if(cumulative >= i){
                return i;
            }
        }
        return 0;
    }
}
```

## Insert Delete GetRandom O(1)

Implement the RandomizedSet class:
- `RandomizedSet()`: Initializes the RandomizedSet object.
- `bool insert(int val)`: Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
- `int getRandom()`: Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works in average O(1) time complexity.

No examples, as task description is pretty self-explanatory.

### Solution (Java)
Clearly, to achieve O(1) for insert and remove, it requires you to use a Hash-like datastructure. However, unlike arrays, they are indexed by their own key (and not like in arrays where i in 0-n). This means, using a random generator, you cannot get items in O(1). The trick is to use both datastructures: 
1. ArrayList which contains all items unordered
2. HashMap, contains the to be inserted x as the key, and the index in the arraylist (1) as the value.

- (1) can easily be used to get random items in O(1)
- (2) can be used to verify if it exists in O(1), also to add and remove items.

When adding items, the new entry in the hashmap is just `(val, arr.size())`
When removing items, you get the index from the hashmap. Then we just remove it from the array, also we replace the index of the last element to the one that was deleted, so we don't need to update all values in the hashmap (assuming there are enough items).

```java
class RandomizedSet {

    private Random random;
    private ArrayList<Integer> array;
    private HashMap<Integer, Integer> map;
    public RandomizedSet() {
        random = new Random();
        array = new ArrayList<Integer>();
        map = new HashMap<Integer, Integer>();
    }
    
    public boolean insert(int val) {
        if(map.containsKey(val)){
            return false;
        } else{
            // insert
            array.add(val); // add at the end
            map.put(val, array.size()-1); // points to the end
            return true;
        }
    }
    
    public boolean remove(int val) {
        if(map.containsKey(val)){
            int index = map.get(val);
            array.set(index, array.get(array.size() - 1)); // set last element to that position
            map.put(array.get(index), index); // update index for that element

            map.remove(val);
            array.remove(array.size() - 1);
            return true;
        }else{
            return false;
        }
    }
    
    public int getRandom() {
        // nextInt(n) is exclusive n. So [0,n)
        return array.get(random.nextInt(array.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
```
## Product of Array except itself
Given an integer array `nums`, return an array answer such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

The product of any prefix or suffix of `nums` is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and **without using the division operation**.

### Solution (Java)
As we cannot use division, the idea is to create a prefix and suffix array, such that ans[i] = pref [i] * suff[i].

```java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] prefix = new int[n];
        int[] suffix = new int[n];
        int[] answer = new int[n];
        // goal is ans[i] = pref[i] * suff[i]
        // edge values as 1 s.t. ans[i] = 1* suff[i], vice-verca

        prefix[0] = 1;
        suffix[n-1] = 1;
        for(int i=1; i<n; ++i){
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for(int i=(n-2); i>=0; --i){
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        for(int i=0; i<n; ++i){
            answer[i] = prefix[i] * suffix[i];
        }

        return answer;
    }
}
```

Further space O(1) optimization: Use only one answer array and an intermediate variable, which calculates
the suffix and prefix before-hand.

```java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] answer = new int[n];
        // goal is ans[i] = pref[i] * suff[i]
        // edge values as 1 s.t. ans[i] = 1* suff[i], vice-verca

        Arrays.fill(answer, 1);
        int current = 1;
        for(int i=0; i<n; ++i){
            answer[i] *= current;
            current *= nums[i]; // preparing for next iteration
        }
        
        current = 1;
        for(int i=(n-1); i>=0; --i){
            answer[i] *= current;
            current *= nums[i];
        }

        return answer;
    }
}
```

## Gas Station (Medium)
There are `n` gas stations along a circular route, where the amount of gas at the ith station is `gas[i]`.

You have a car with an unlimited gas tank and it costs `cost[i]` of gas to travel from the `i-th` station to its next `(i + 1)-th` station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays `gas` and `cost`, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return `-1`. If there exists a solution, it is guaranteed to be unique.

### Example
- Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
- Output: 3
- Explanation:
```
Start at station 3 (index 3) and fill up with 4 unit of gas. 
Your tank = 0 + 4 = 4  
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
```
Is it possible to do it in O(n)?

### Solution (Java)
I really recommend drawing the example on paper. There are two important points to note before attempting this problem:
1. How can we verify that a solution exists? Think of a condition that must hold for the car to be able to travel the whole route.
2. Assuming we have started at some point, but at another point, the tank is not enough. Can we derive a further conclusion?

To the first question: Let `reserve[i] = gas[i]-cost[i]` be the reserve we have travelling to point `i+1` after filling up the tank by `+gas[i]`. More simply, it's the amount of fuel we have at point `i+1`. Note that if we sum up each reserve, the sum has to be positive! This is because the tank size is unlimited and we always fill up the maximum amount we can. If the sum would be negative, wherever we start, we would end up negative at the end of the loop (since the available resources are negative). Therefore, we can use this condition `sum(reserve) >= 0` to check, if there exists a solution.

To the second question: Note that if we start at some point `a`, and end up at a point `b` where the tank will be negative, then similar to the jump game problem, starting to any points in between will result to a negative tank at point `b` => none of these points can be used as starting point.

Combining these two points will easily lead to the following solution.

```java
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;

        int tank = 0; 
        int total_reserves = 0;
        int start = 0;
        for(int i=0; i<n; ++i){
            int reserve = gas[i] - cost[i]; // reserve we will have in next station
            total_reserves += reserve; // verify if solution exists

            tank += reserve;
            if(tank < 0){ // tank is negative, we have to restart at next node
                start = i + 1;
                tank = 0;
            }
        }

        // solution exists iff sum of all reserves is positive or 0
        return (total_reserves >= 0) ? start : -1;
    }
}
```

## Roman to Integer (Easy)
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
```
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

### Example
- Input: s = "MCMXCIV"
- Output: 1994
- Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

### Solution (Java)
This is pretty straight forward. Note that the "special" cases appear iff the left letter is smaller than the right one. In other cases, we just easily sum up. Note that you should use a map or switch case, to identify which letter belongs to which value.
As such we go from the string backwards, save the previous value (right one) and check if the current one is smaller than the previous value (in that case, it's substraction).

```java
class Solution {
    private HashMap<Character, Integer> map = new HashMap<Character, Integer>();
    public int romanToInt(String s) {
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);

        int ans = 0;
        int rightVal = 0; // we loop backwards, and save the previous val
        for(int i=s.length()-1; i>=0; --i){
            int currentVal = map.get(s.charAt(i));
            if(currentVal >= rightVal){
                ans += currentVal;
            }else{
                // the case of IV
                ans -= currentVal;
            }
            rightVal = currentVal;
        }

        return ans;
    }
}
```

