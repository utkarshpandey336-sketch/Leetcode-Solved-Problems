class Solution {
public:
     string mp[10] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };
     void solve(int index, string digits, string current, vector<string>& ans){
        if(index == digits.size())
        {
            ans.push_back(current);
            return;
        }
        string letters = mp[digits[index]-'0'];
         for(char ch : letters)
        {
            solve(index + 1, digits, current + ch, ans);
        }
     }
    vector<string> letterCombinations(string digits) {
         vector<string> ans;

        if(digits.empty())
            return ans;

        solve(0, digits, "", ans);

        return ans;
    }
};