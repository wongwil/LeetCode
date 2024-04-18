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
