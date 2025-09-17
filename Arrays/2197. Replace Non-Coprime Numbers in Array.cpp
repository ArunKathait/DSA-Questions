
class Solution {// Time Complexity: O(n log M)                             Space Complexity: O(n)
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        // 'ans' will store the final sequence after merging non-coprime numbers
        vector<int> ans;

        // Traverse each number in the input array
        for (auto num : nums) 
        {
            // Keep merging the current 'num' with the last element of 'ans'
            // until they are coprime (GCD == 1)
            while (!ans.empty()) 
            {
                // last number already in result
                int lastElement = ans.back(); 

                // current number from input  
                int currentNumber = num;        

                // Find GCD
                int gcdValue = gcd(lastElement, currentNumber); 

                // If they are coprime (GCD = 1), stop merging
                if (gcdValue == 1) 
                {
                    break;
                }

                // Otherwise, merge them into their LCM
                // Formula: LCM(a, b) = (a * b) / GCD(a, b)
                int lcmValue = lastElement / gcdValue * currentNumber;

                // Remove the last element from result
                ans.pop_back();

                // Update 'num' with the merged LCM value
                num = lcmValue;
            }

            // After merging, push the resulting 'num' into the result
            ans.push_back(num);
        }

        // Return the final processed array
        return ans;
    }
};
