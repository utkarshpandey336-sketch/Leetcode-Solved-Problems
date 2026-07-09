class Solution {
public:
     long long calTime(vector<int>& piles, int mid) {
    long long time = 0;

    for (int i = 0; i < piles.size(); i++) {
        time += (piles[i] + mid - 1) / mid;
    }

    return time;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high = piles[0];
        for (int i = 1; i < piles.size(); i++) {
             high = max(high, piles[i]);
        }
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long tMid=calTime(piles,mid);
            if(tMid<=h){
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