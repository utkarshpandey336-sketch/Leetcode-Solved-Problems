class Solution {
public:
    int noOfBouquet(vector<int>& bloomDay,int mid,int k){
        int count=0;
        int ans=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                count++;
            }
            else{
                ans=ans+count/k;
                count=0;
            }
        }
        ans=ans+count/k;
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > bloomDay.size())
        return -1;
        int low = bloomDay[0];
        for (int i = 1; i <bloomDay.size(); i++) {
             low = min(low, bloomDay[i]);
        }
        int high = bloomDay[0];
        for (int i = 1; i <bloomDay.size(); i++) {
             high = max(high, bloomDay[i]);
        }
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int bouquet=noOfBouquet(bloomDay,mid,k);
            if(bouquet>=m){
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