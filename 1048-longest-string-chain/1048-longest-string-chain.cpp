class Solution {
public:
    bool check(string shorter,string longer){
        int i=0;
        int j=0;
        while(i<shorter.size()&&j<longer.size()){
            if(shorter[i]==longer[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return i==shorter.size();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
                // Sort according to length
        sort(words.begin(), words.end(),
            [](string &a, string &b) {
                return a.size() < b.size();
            }
        );
         vector<int> dp(n, 1);

        int ans = 1;
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < i; j++) {

                // Previous word must be exactly 1 shorter
                if(words[j].size() + 1 == words[i].size()
                   && check(words[j], words[i])) {

                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};