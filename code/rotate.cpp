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
