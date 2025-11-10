*************************************************APPROACH 1st(USING BRUTE FORCE)**************************************

class Solution {// TC ---> O(N^2)                          SC ---> O(N)
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // ✅ Step 1: Get the size of the input array
        int n = nums.size();   

        // ✅ Step 2: Create a result vector initialized with -1.
        // If no next greater element exists, -1 will remain as default.
        vector<int> nge(n, -1);

        // ✅ Step 3: Traverse each element in the array
        for (int i = 0; i < n; i++) 
        {
            // ✅ Step 4: For each element nums[i], look for the next greater element
            // We loop through the next (n-1) elements in a circular manner
            for (int j = i + 1; j < i + n; j++) 
            {
                // Use modulo to wrap around (circular array)
                int index = j % n;

                // ✅ Step 5: If a greater element is found, store it and break
                if (nums[index] > nums[i]) 
                {
                    nge[i] = nums[index];
                    break;  // Stop at the first greater element
                }
            }
        }

        // ✅ Step 6: Return the vector containing next greater elements
        return nge;
    }
};

***********************************************APPROACH 2nd(USING OPTIMAL APPROACH)*************************************

class Solution {// TC ---> O(4*N)                              SC ---> O(2*N)
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        // Initialize a result array of size n with -1
        // (-1 means "no greater element found")
        vector<int> nge(n, -1);

        // Stack to store potential "next greater" elements
        stack<int> st; 

        // Traverse the array twice (circular array simulation)
        // i goes from 2n-1 → 0 to handle circular nature
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            // Remove all elements from stack that are smaller or equal
            // to the current element because they can't be the "next greater"
            while (!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }

            // For the first pass (i < n),
            // assign the top of stack as the next greater element
            if (i < n)
            {
                // If stack is empty → no greater element found → -1
                // Else → top of stack is the next greater element
                nge[i] = st.empty() ? -1 : st.top();
            }

            // Push the current element (in circular fashion) into the stack
            st.push(nums[i % n]);
        }

        // Return the result array containing next greater elements
        return nge;
    }
};
