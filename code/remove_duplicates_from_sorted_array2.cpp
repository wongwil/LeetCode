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
