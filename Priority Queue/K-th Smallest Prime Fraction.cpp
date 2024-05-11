********************************************APPROACH 1st(USING BRUTE FORCE)*****************************************

class Solution {// TC--->O(N^2 + NlogN)          SC--->O(N^2)
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // Get the size of the input array
        int n =arr.size();
        
        // Create a vector of pairs to store fractions along with their corresponding numerator and denominator
        // Each pair contains: (fraction, {numerator, denominator})
        vector<pair<double,pair<int,int>>>vec;
        
        // Generate all possible fractions using pairs of elements from the input array
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                // Calculate the fraction by dividing the smaller number by the larger number
                double frac = (double)arr[i]/arr[j];
                
                // Store the fraction along with its corresponding numerator and denominator in the vector
                vec.push_back({frac,{arr[i],arr[j]}});
            }
        }
        
        // Sort the vector of pairs based on the fractions in ascending order
        sort(vec.begin(),vec.end());
        
        // Retrieve the kth smallest fraction from the sorted vector
        // Retrieve the numerator
        int x = vec[k - 1].second.first;
        
        // Retrieve the denominator
        int y = vec[k - 1].second.second;
        
        // Return the kth smallest prime fraction as a vector containing the numerator and denominator
        return {x,y};
    }
};

***************************************************APPROACH 2nd(USING MAX HEAP)************************************

class Solution {// TC--->O(N^2.log(K))                 SC--->O(K)
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // Get the size of the input array
        int n = arr.size();
        
       // Declare a max-heap priority queue to store fractions along with their corresponding numerators and denominators priority_queue<pair<double,pair<int,int>>>pq;
        
        // Generate all possible fractions using pairs of elements from the input array
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                // Calculate the fraction
                double fraction = (double) arr[i]/arr[j];

                // Push the fraction and its corresponding numerator and denominator to the priority queue
                pq.push({fraction,{arr[i],arr[j]}});
                
                // If the size of the priority queue exceeds k, pop the top element
                if(pq.size() > k)
                {
                    pq.pop();
                }
            }
        }
        
        // Retrieve the kth smallest fraction from the priority queue
        // Get the numerator and denominator of the top element
        pair<int,int>p = pq.top().second;
        
        // Pop the top element
        pq.pop();
        
        // Extract the numerator and denominator
        int x = p.first;
        int y = p.second;
        
        // Return the numerator and denominator as a vector
        return {x,y};
    }
};


***********************************************APPROACH 3rd(USING MIN-HEAP)******************************************

class Solution {// TC--->O((N+K)logN)              SC--->O(N)
public:
  
    // Define a shorthand for vector<double> as V
    typedef vector<double>V;
  
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        // Get the size of the input array
        int n = arr.size();
        
        // Define a min-heap priority queue to store vectors of doubles
        // Each vector contains: [fraction, numerator index, denominator index]
        priority_queue<V,vector<V>,greater<V>>pq;
        
        // Push initial fractions into the priority queue
        for(int i=0;i<n;i++)
        {
            // Calculate the fraction
            double fraction = 1.0* arr[i]/arr[n-1];
            
            // Push the fraction along with its numerator and denominator indices
            pq.push({fraction,double(i),double(n-1)});
        }
        
        // Counter for the kth smallest fraction
        int smallest = 1;
        
        // Continue until the kth smallest fraction is found
        while(smallest < k)
        {
            // Get the top element from the priority queue
            V vec = pq.top();
            
            // Remove the top element
            pq.pop();
            
            // Get the index of the numerator
            int x = vec[1];
            
            // Get the index of the denominator (decremented by 1)
            int y = vec[2] - 1;
            
            // Calculate the next fraction using the new denominator
            pq.push({1.0*arr[x]/arr[y],(double)x,(double)y});
            
            // Increment the counter
            smallest++;
        }
        
        // Get the top element from the priority queue
        V ans = pq.top();
        
        // Get the index of the numerator
        int x = ans[1];
        
        // Get the index of the denominator
        int y = ans[2];
        
        // Return the numerator and denominator as a vector
        return {arr[x],arr[y]};
    }
};
