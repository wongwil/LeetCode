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