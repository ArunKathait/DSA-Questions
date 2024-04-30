class Solution {// TC--->O(N)           SC--->O(N)
public:
    
    // Define a typedef for long long as ll
    typedef long long ll;
        
    long long wonderfulSubstrings(string word) {
        
        // Create an unordered_map to store cumulative xor values and their frequencies
        unordered_map<ll,ll>ump;
        
        // Initialize the map with cumulative xor value 0 and frequency 1
        ump[0] = 1;
        
        // Initialize the answer variable to 0
        ll ans = 0;
        
        // Initialize cumulative xor value to 0
        int cumulative_xor = 0;
        
        // Iterate over each character in the given word
        for(auto ch:word)
        {
            // Calculate the shift needed for the character
            ll shift = ch - 'a';
            
            // Compute the binary representation of the character
            ll binary = (1 << shift);
            
            // Update cumulative xor value by xor-ing with the binary representation of the character
            cumulative_xor ^= binary;
            
            // Add the frequency of the current cumulative xor value to the answer
            ans += ump[cumulative_xor];
                
            // Iterate over characters from 'a' to 'j'
            for(char ch1 = 'a';ch1 <= 'j';ch1++)
            {
                // Calculate the shift for the current character
                shift = ch1 - 'a';
                
                // Compute the binary representation of the current character
                ll binary = (1 << shift);
                
                // Compute the xor value after toggling the current character
                ll check_xor = (cumulative_xor ^ binary);
                
                // Add the frequency of the computed xor value to the answer
                ans += ump[check_xor];
            }
            
            // Increment the frequency of the current cumulative xor value
            ump[cumulative_xor]++;
        }
        
        // Return the final answer
        return ans;
    }
};
