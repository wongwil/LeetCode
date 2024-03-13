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
