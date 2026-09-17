class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans=0;
        vector<vector<int>> v;
        for(int i=0;i<costs.size();i++){
            int diff = costs[i][0] - costs[i][1];
            v.push_back({diff, costs[i][0], costs[i][1]});
}
        
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(i<v.size()/2){
                ans+=v[i][1];;
            }
            else{
                ans+=v[i][2];;
            }
        }
        return ans;
    }
};