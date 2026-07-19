class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int ans=0;
        unordered_map<char,int>mp;
        for(int right=0;right<s.size();right++){
            // Include current character in the window
            mp[s[right]]++;

            // If current character is duplicated,
            // shrink the window
            while(mp[s[right]]>1){
                mp[s[left]]--;
                left++;
            }
             // Window is now valid
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};