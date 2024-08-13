
class KthLargest {// TC--->O(N*logK)                      SC--->O(K)
public:
    // Declare a priority queue (min-heap) to store the K largest elements.
    priority_queue<int,vector<int>,greater<int>>pq;
    
    // Variable to store the value of K, which represents the Kth largest element.
    int K;
    
    // Constructor that initializes the class with an integer k and a vector of integers nums.
    KthLargest(int k, vector<int>& nums) {
        // Set K to the input value k.
        K = k;
        
        // Iterate through the elements of the nums vector.
        for(auto x:nums)
        {
            // Add each element to the priority queue (min-heap).
            pq.push(x);
            
            // If the size of the priority queue exceeds K, remove the smallest element.
            // This ensures that the priority queue only contains the K largest elements.
            if(pq.size() > K)
            {
                // Remove the smallest element from the heap.
                pq.pop();
            }
        }
    }
    
    // Method to add a new element to the stream and return the Kth largest element.
    int add(int val) {
        // Add the new value to the priority queue.
        pq.push(val);
        
        // If the size of the priority queue exceeds K, remove the smallest element.
        if(pq.size() > K)
        {
            // Remove the smallest element from the heap.
            pq.pop();
        }
        
        // The top of the priority queue is the Kth largest element, so return it.
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
