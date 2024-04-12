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
