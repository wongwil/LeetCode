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
