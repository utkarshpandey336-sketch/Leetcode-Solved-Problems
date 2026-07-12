class Solution {
public:
    bool helper(vector<int> &nums, int k,int minSum){
        int arrNo=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=minSum){
                sum=sum+nums[i];
            }
            else{
                arrNo++;
                sum=nums[i];
            }
        }
        if(arrNo<=k){
            return true;
        }
        else{
            return false;
        }
    }
    int splitArray(vector<int>& nums, int k) {
         int low=nums[0];
        for(int i=1;i<nums.size();i++){
            low=max(low,nums[i]);
        }
        int high=0;
        for(int i=0;i<nums.size();i++){
            high=high+nums[i];
        }
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(helper(nums,k,mid)==true){
                ans=mid;
                high=mid-1;

            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};