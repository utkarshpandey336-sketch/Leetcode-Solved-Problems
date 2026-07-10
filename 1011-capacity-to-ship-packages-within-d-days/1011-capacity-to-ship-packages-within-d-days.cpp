class Solution {
public:
    int daysRequired(vector<int>& weights, int capacity) {

    int days = 1;
    int load = 0;

    for (int i = 0; i < weights.size(); i++) {

        if (load + weights[i] <= capacity) {
            load += weights[i];
        }
        else {
            days++;
            load = weights[i];
        }
    }

    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0;
         for (int i = 0; i <weights.size(); i++) {
             low = max(low, weights[i]);
        }
        int high=0;
         for (int i = 0; i <weights.size(); i++) {
             high =high+weights[i];
        }int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int Mdays=daysRequired(weights,mid);
            if(Mdays<=days){
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