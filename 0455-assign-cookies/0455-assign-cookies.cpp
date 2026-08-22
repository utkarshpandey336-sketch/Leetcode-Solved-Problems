class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int left = 0;
        int count = 0;

        for(int i = 0; i < g.size(); i++) {

            while(left < s.size() && s[left] < g[i]) {
                left++;
            }

            if(left == s.size()) {
                break;
            }

            count++;
            left++;
        }

        return count;
    }
};