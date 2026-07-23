class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp1;
        for(char c:t){
          mp1[c]++;
        }
        unordered_map<char,int>mp2;
         int left = 0;
        int count = 0;

        int minLen = INT_MAX;
        int start = 0;
        for(int right=0;right<s.size();right++){
            char c = s[right];
            mp2[c]++;
            if(mp1.count(c)&& mp2[c]<=mp1[c]){
                count++;
            }
            while(count==t.size()){
            if(right-left+1 < minLen){
                    minLen = right-left+1;
                    start = left;
                }
                mp2[s[left]]--;
                if(mp1.count(s[left])&& mp2[s[left]]<mp1[s[left]]){
                    count--;
                }
                left++;

            }
        }
         return minLen == INT_MAX ? "" : s.substr(start,minLen);
    }
};