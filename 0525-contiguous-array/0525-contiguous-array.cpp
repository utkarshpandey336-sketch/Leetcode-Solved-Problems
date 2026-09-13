class Solution { 
public: 
    int findMaxLength(vector<int>& nums) { 
        
        int sum = 0; 
        int ans = 0; 
        
        // Stores: prefix sum -> first index where it appeared
        unordered_map<int, int> mp; 
        
        // Prefix sum 0 exists before the array starts
        mp[0] = -1; 
        
        for (int i = 0; i < nums.size(); i++) { 
            
            // Treat 0 as -1
            if (nums[i] == 0) { 
                sum -= 1; 
            } 
            // Treat 1 as +1
            else { 
                sum += 1; 
            } 
            
            // If this sum appeared before,
            // the elements between the previous index and i
            // have equal number of 0s and 1s
            if (mp.count(sum)) { 
                
                // Calculate length of that subarray
                ans = max(ans, i - mp[sum]); 
            } 
            
            else { 
                
                // Store only the FIRST occurrence
                // because it gives the longest possible subarray
                mp[sum] = i; 
            } 
        } 
        
        return ans; 
    } 
};