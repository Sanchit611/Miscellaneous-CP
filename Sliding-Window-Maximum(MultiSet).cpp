//https://leetcode.com/problems/sliding-window-maximum/ 
// O(nlogn)
 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n=nums.size();
        multiset<int,greater<int>> s;
        vector<int>ans;
        for(int i=0;i<k;i++){
            s.insert(nums[i]);
        }
        ans.push_back(*s.begin());
        for(int i=k;i<n;i++){
            s.erase(s.lower_bound(nums[i-k]));
            s.insert(nums[i]);
            ans.push_back(*s.begin());
        }
        
        return ans;
    }
};
