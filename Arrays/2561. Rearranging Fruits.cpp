
class Solution {// TC--->O((n + m) log(n + m))                       SC--->O(n + m)
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        // Hash map to store frequency difference of each element
        unordered_map<int,int> ump; 

        // Will track the minimum element across both baskets
        int minElement = INT_MAX;   

        // Count frequency of elements in basket1
        for(auto &x : basket1) 
        {
            // Increment count
            ump[x]++;

            // Update minimum element if needed 
            minElement = min(minElement, x);  
        }

        // Subtract frequency of elements in basket2
        for(auto &x : basket2) 
        {
            // Decrement count
            ump[x]--; 

            // Update minimum element if needed
            minElement = min(minElement, x); 
        }
        
        // Store the elements that need to be swapped
        vector<int> toSwap; 

        // Loop through the frequency map
        for(auto &it : ump) 
        {
            int cost = it.first;              // Element value
            int freq = abs(it.second);        // Difference in frequency between basket1 and basket2

            if(freq == 0) 
            {
                // No imbalance for this element
                continue;  
            }

            if(freq % 2 != 0) 
            {
                // Odd imbalance → cannot balance baskets → return -1
                return -1; 
            }

            // Add half the unbalanced count (because each swap resolves two differences)
            for(int i = 1; i <= freq / 2; i++) 
            {
                toSwap.push_back(cost);
            }
        }

        // Sort the elements to prioritize cheaper swaps
        sort(toSwap.begin(), toSwap.end());

        long long ans = 0;

        // To minimize cost, only take the smallest half of the unbalanced elements
        for(int i = 0; i < toSwap.size() / 2; i++) 
        {
            // Compare direct swap cost with the indirect cost via two swaps using minElement
            ans += min(toSwap[i], 2 * minElement);
        }
        
        // Return the total minimum cost to make baskets equal
        return ans; 
    }
};
