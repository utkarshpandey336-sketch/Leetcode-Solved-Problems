class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int med=low+(high-low)/2;
            if(nums[med]==target){
                return med;
            }
            //left half is sorted
            if(nums[low]<=nums[med]){
              if(nums[low]<=target&&nums[med]>target){
                high=med-1;
              }
              else{
                low=med+1;
              }
            }
            //right half sorted
            else{
                if(nums[med]<target&&nums[high]>=target){
                low=med+1;
              }
                else{
                    high=med-1;
                }
            }
        }
        return -1;
    }
};