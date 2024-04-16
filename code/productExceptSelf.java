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
