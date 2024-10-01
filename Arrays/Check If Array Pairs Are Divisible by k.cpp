
class Solution {// TC--->O(N + K)                       SC--->O(K)
public:
    bool canArrange(vector<int>& arr, int k) {
        // Get the size of the input array 'arr'
        int n = arr.size();
        
        // Create a frequency array 'mp' to count how many elements have each remainder when divided by k
        // Size 'k', initialized to 0 for each remainder (0 to k-1)
        vector<int>mp(k,0);
        
         // Iterate through the array and calculate the remainder of each element when divided by 'k'
        for(int i=0;i<n;i++)
        {
            // Calculate the remainder and ensure it is non-negative by using (arr[i]%k + k)%k
            int remainder = (arr[i]%k + k)%k;
            
            // Increment the count for this remainder in the 'mp' array
            mp[remainder]++;
        }
        
        // Special case: If the remainder is 0, we need an even number of such elements to pair them up
        if(mp[0]%2 != 0)
        {
            // If the count of remainder 0 is odd, return false (cannot pair all)
            return false;
        }
        
        // Now, check for all other remainders:
        // For remainder 'rem', we need the count of 'rem' to match the count of 'k - rem'
        for(int rem=1;rem<=k/2;rem++)
        {
            // The complementary remainder to make the sum divisible by 'k'
            int counterHalf = k - rem;
            
            // If the count of 'rem' and 'k - rem' don't match, return false
            if(mp[counterHalf] != mp[rem])
            {
                return false;
            }
        }
        
        // If all checks are passed, return true (all pairs can be arranged)
        return true;
    }
};

/*
 NOTE:
      
     * (arr[i] % k + k) % k: This ensures that any negative remainders are converted into their positive
       counterparts.
     
     *  Why this works: When arr[i] % k gives a negative remainder, adding k makes it positive, and the               
        second modulo operation % k ensures the remainder is in the range [0, k-1].
     
     EXAMPLE:
     
        If arr = [-3, 9] and k = 6:

      *  Without adjustment, -3 % 6 = -3, and 9 % 6 = 3. These won't pair properly because the remainders              
         don't match our expectation of being non-negative.
        
      *  After adjustment:
      
          *  For -3, we calculate the remainder as ( -3 % 6 + 6) % 6 = ( -3 + 6 ) % 6 = 3.
          *  Now both -3 and 9 have a remainder of 3, making it possible to pair them correctly.
*/ 
