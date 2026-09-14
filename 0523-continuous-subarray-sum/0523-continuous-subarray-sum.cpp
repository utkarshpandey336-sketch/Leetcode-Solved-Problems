class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0;
        int ans=0;
        unordered_map<int,int>mp;
        mp[0] = -1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum%k;
            if(mp.count(rem)){
                ans=max(ans,i-mp[rem]);
            }
            else{
                mp[rem]=i;
            }
        }
        return ans>=2;
    }
};