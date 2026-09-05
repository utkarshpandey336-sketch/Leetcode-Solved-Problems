class Solution {
public:
    bool solve(int i, int j, string &s) {
        if(i >= j) {
            return true;
        }

        if(s[i] != s[j]) {
            return false;
        }

        return solve(i + 1, j - 1, s);
    }

    bool isPalindrome(string s) {
        string temp = "";

        for(int i = 0; i < s.size(); i++) {
            if(isalnum(s[i])) {
                temp += tolower(s[i]);
            }
        }

        if(temp.empty()) {
            return true;
        }

        return solve(0, temp.size() - 1, temp);
    }
};