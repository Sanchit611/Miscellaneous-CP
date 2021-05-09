//Maximum Sum Subarray using Kadan's Algo 
//https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       //Kadan's Algo
        int max_sum=INT_MIN;
        int cur_sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            cur_sum+=nums[i];
            if(cur_sum>max_sum){
                max_sum=cur_sum;  
            }
            if(cur_sum<0)
                cur_sum=0;
        }
//           Kadanes for array with negative elements
//          for(int i=0;i<n;i++){
//             cur_sum+=nums[i];
//             if(cur_sum>max_sum){
//                 max_sum=cur_sum;  
//             }
//             if(cur_sum<nums[i])
//                 cur_sum=nums[i];
//         }
        return max_sum;
    }
};
