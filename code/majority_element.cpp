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
