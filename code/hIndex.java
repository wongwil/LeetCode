class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;
        int freq[] = new int[n+1]; // frequency for each possible h_value

        for(int citation : citations){
            if (citation >= n){
                freq[n]++; // if it has more than n citations, it goes to h=n.
            }else{
                freq[citation]++;
            }
        }

        int cumulative = 0;
        for(int i=n; i>= 0; --i){
            cumulative += freq[i];

            if(cumulative >= i){
                return i;
            }
        }
        return 0;
    }
}
