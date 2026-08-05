class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

         // 1. Remove leading spaces
        while(i < n && s[i] == ' ')
        {
            i++;
        }
         // 2. Check sign
        int sign = 1;

        if(i < n && (s[i] == '+' || s[i] == '-'))
        {
            if(s[i] == '-')
                sign = -1;

            i++;
        }

        // 3. Build the number
        long long ans = 0;

        while(i < n && isdigit(s[i]))
        {
            int digit = s[i] - '0';

            ans = ans * 10 + digit;

            // overflow check
            if(sign * ans > INT_MAX)
                return INT_MAX;

            if(sign * ans < INT_MIN)
                return INT_MIN;

            i++;
        }
         return sign * ans;
    
    }
};