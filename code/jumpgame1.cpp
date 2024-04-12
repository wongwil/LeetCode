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
