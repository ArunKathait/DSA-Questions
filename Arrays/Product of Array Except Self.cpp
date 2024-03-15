**********************************************APPROACH 1st BRUTE FORCE*****************************************
// NOTE: This will give time limit exceed.
class Solution {// TC--->O(N^2)          SC--->O(N) ~ O(1) (i.e we are returning the ans vector)
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            int prod = 1;
            for(int j=0;j<n;j++)
            {
                if(i == j)
                {
                    continue;
                }
                else
                {
                    prod = prod*nums[j];
                }
            }
            ans[i] = prod;
        }
        return ans;
    }
};

*******************************************2nd APPROACH****************************************************
// NOTE:But we have to do without using division operation.
  
class Solution {// TC--->O(N)         SC--->O(N)(i.e For returning the ans vector)
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Count the number of zeros in the input array
        int countZeros = 0;
        
        // Calculate the product of all non-zero elements in the input array
        int product_without_zeros = 1;
        
        // Get the size of the input array
        int n = nums.size();
        
        // Loop through each element in the input array
        for(auto x:nums)
        {
            if(x == 0)
            {
                // If the element is zero, increment the count of zeros
                countZeros++;
            }
            else
            {
                // If the element is not zero, multiply it to the product of non-zero elements
                product_without_zeros *= x;
            }
        }
        
        // Initialize the result array with size equal to the input array
       vector<int>ans(n);
        
        // Loop through each element in the input array
        for(int i=0;i<n;i++)
        {
            // If the current element is not zero
            if(nums[i] != 0)
            {
                // If there are one or more zeros in the input array
                if(countZeros > 0)
                {
                    // Set the corresponding element in the result array to 0
                    ans[i] = 0;
                }
                else
                {
                    // If there are no zeros, divide the product of all non-zero elements by the current element
                    ans[i] = product_without_zeros/nums[i];
                }
            }
            // If the current element is zero
            // If there are more than one zeros in the input array
            else if(nums[i] == 0)
            {
                if(countZeros > 1)
                {
                    // Set the corresponding element in the result array to 0
                    ans[i] = 0;
                }
                else
                {
  // If there is exactly one zero, set the corresponding element in the result array to the product of all  
  // non-zero elements
                    ans[i] = product_without_zeros;
                }
            }
        }
        
        // Return the result array
        return ans;
    }
};

******************************************APPROACH 3rd********************************************
class Solution {// TC--->O(3N) ~ O(N)          SC--->O(3N) ~ O(N)
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         // Get the size of the input vector
        int n = nums.size();
        
        // Initialize two vectors to store left and right products
        vector<int>left(n);// Store products to the left of current index
        vector<int>right(n);// Store products to the right of current index
    
        
        // Calculate left products
        left[0] = 1;// Since there are no elements to the left of the first element
        for(int i=1;i<nums.size();i++)
        {
            // Multiply all elements to the left
            left[i] = left[i-1] * nums[i-1];
        }
        
        // Calculate right products
        right[n-1] = 1;// Since there are no elements to the right of the last element
        for(int j=n-2;j>=0;j--)
        {
            // Multiply all elements to the right
            right[j] = right[j+1] * nums[j+1];
        }
        
        // Calculate final product by multiplying left and right products
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            // Multiply corresponding left and right products
            ans[i] = left[i] * right[i];
        }
        
        // Return the resulting vector
        return ans;
    }
};

******************************************APPROACH 4th********************************************************
class Solution {//  TC--->O(2N) ~ O(N)         SC--->O(N)(i.e O(1) because we are returning ans vector)
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Get the size of the input vector
        int n = nums.size();
        
        // Initialize a vector to store the result
        vector<int>ans(n);
        
        // Set the first element of ans to 1
        ans[0] = 1;
        
        // Calculate the product of all elements to the left of each element
        for(int i=1;i<n;i++)
        {
            // Multiply the previous element in ans with the corresponding element in nums
            ans[i] = ans[i-1] * nums[i-1];
        }
        
        // Initialize a variable right to store the product of elements to the right
        int right = 1;
        
        // Calculate the product of all elements to the right of each element and update ans
        for(int j=n-1;j>=0;j--)
        {
            // Multiply the current element in ans with the right
            ans[j] = ans[j] * right;
            
            // Update the right by multiplying with the corresponding element in nums
            right = right * nums[j];
           
        }
        
         // Return the resulting vector
        return ans;
    }
};
