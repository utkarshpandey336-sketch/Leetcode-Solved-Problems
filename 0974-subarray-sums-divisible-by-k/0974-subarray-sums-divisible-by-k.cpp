class Solution { 
public: 
    int subarraysDivByK(vector<int>& nums, int k) { 
        
        int sum = 0; 
        int ans = 0; 
        
        // Stores: remainder -> number of times it has appeared
        unordered_map<int, int> mp; 
        
        // Remainder 0 exists before the array starts
        // This helps count subarrays starting from index 0
        mp[0] = 1; 
        
        for (int i = 0; i < nums.size(); i++) { 
            
            // Calculate prefix sum
            sum += nums[i]; 
            
            // Find remainder of prefix sum
            int remainder = sum % k; 
            
            // C++ can give a negative remainder
            // Convert it to a positive remainder
            if (remainder < 0) 
                remainder += k; 
            
            // If this remainder appeared before,
            // each previous occurrence gives one
            // subarray whose sum is divisible by k
            if (mp.count(remainder)) { 
                ans += mp[remainder]; 
            } 
            
            // Increase the frequency of this remainder
            mp[remainder]++; 
        } 
        
        return ans; 
    } 
};