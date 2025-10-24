
class Solution {// TC--->O(N)+O(N)+O(k×logN)≈O(N+klogN)            SC--->O(N)
  public:
    int minOperations(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Calculate the total sum of the array using floating-point precision
        double sum = accumulate(arr.begin(), arr.end(), 0.0);
        
        // Step 2: Calculate the target (half of the total sum)
        // We need to reduce the array's total sum to be <= half
        double half = sum / 2;
        
        // Step 3: Create a max-heap (priority queue) to always pick the largest element quickly
        // The largest element will contribute most to reducing the sum
        priority_queue<double> pq(arr.begin(), arr.end());
        
        int operations = 0;  // To count the number of operations performed
        
        // Step 4: Continue halving the largest elements until the sum becomes <= half
        while (sum > half) 
        {
            // Get the largest element in the array
            double val = pq.top();
            pq.pop();
            
            // Halve its value
            double subtractVal = val / 2.0;
            
            // Reduce the total sum by the amount saved (since we replaced val with val/2)
            sum -= subtractVal;
            
            // Push the halved value back into the heap (since it might still be useful later)
            pq.push(subtractVal);
            
            // Increment operation count
            operations++;
        }
        
        // Step 5: Return the total number of operations needed
        return operations;
    }
};
