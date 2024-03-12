class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //ptr_merged = n+m - 1;
        int ptr1 = m - 1;
        int ptr2 = n - 1;

        for (int ptr_merged = n+m - 1; ptr_merged >= 0; ptr_merged--){
            // base case: pointer has reached start of array
            if (ptr1 < 0){
                nums1[ptr_merged] = nums2[ptr2];
                ptr2--;
            }
            else if (ptr2 < 0){
                nums1[ptr_merged] = nums1[ptr1];
                ptr1--;
            }
            else if (nums1[ptr1] >= nums2[ptr2]){
                // ptr1 has larger element => take it 
                nums1[ptr_merged] = nums1[ptr1];
                ptr1--;
            }
            else {
                // ptr2 has larger element => take it 
                nums1[ptr_merged] = nums2[ptr2];
                ptr2--;
            }
        }
    }
};