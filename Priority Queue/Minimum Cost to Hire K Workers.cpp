*************************************************APPROACH 1st(BRUTE FORCE)************************************************

// This will give Time Limit Exceed.
class Solution {//TC--->O(n * (n + klogk))         SC--->O(n+k)
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
        // Number of workers
        int n  = quality.size();
        
        // Initialize the result to maximum possible double value
        double result = DBL_MAX;
        
        // Iterate through each manager
        for(int manager=0;manager<n;manager++)
        {
            // Calculate the manager-to-worker wage ratio
            double managerRatio = (double)min_wage[manager]/quality[manager];
            
             // Vector to store the wages of workers the manager can hire
            vector<double>group;
            
            // Iterate through each worker
            for(int worker=0;worker<n;worker++)
            {
                // Calculate the wage for the worker based on the manager's ratio
                double worker_wage = quality[worker]*managerRatio;
                
                // Check if the calculated wage meets the minimum wage requirement for the worker
                if(worker_wage >= min_wage[worker])
                {
                    // If yes, add the wage to the group

                    group.push_back(worker_wage);
                }
            }
            
            // If the number of workers in the group is less than required, continue to the next manager
            if(group.size() < k)
            {
                continue;
            }
            
             // Create a heap to store the k lowest wages
            priority_queue<double>pq;
            
            // Variable to store the sum of wages
            double sum_wage = 0;
            
            // Iterate through each wage in the group
            for(auto wage:group)
            {
                // Add the wage to the sum
                sum_wage += wage;
                
                // Push the wage to the priority queue
                pq.push(wage);
                
                // If the size of the priority queue exceeds k, remove the highest wage from the sum
                if(pq.size() > k)
                {
                    sum_wage -= pq.top();
                    pq.pop();
                }
            }
            
            // Update the result with the minimum of the current result and the sum of wages
            result = min(result,sum_wage);
        }
        
        // Return the minimum cost
        return result;
    }
};

*********************************************APPROACH 2nd(BETTER APPROACH)*********************************************


  class Solution {// TC--->O(nlogn + klogk + n*log(k))                SC--->O(n+k)
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        // Number of workers
        int n = quality.size();

        // Store each worker's wage-to-quality ratio along with their quality
        vector<pair<double, int>> worker_ratio(n);
        
        // Calculate and store the wage-to-quality ratio for each worker
        for(int worker = 0; worker < n; worker++)
        {
            worker_ratio[worker] = make_pair((double)wage[worker]/quality[worker], quality[worker]);
        }
        
        // Sort the workers based on their wage-to-quality ratio
        sort(worker_ratio.begin(),worker_ratio.end());

        // Initialize a max heap to keep track of the k lowest quality values
        priority_queue<double> pq;
        
        // Variable to store the sum of quality values for the k lowest workers
        double sum_quality = 0;
        
        // Select the k lowest quality workers and calculate the sum of their quality values
        for(int i = 0; i < k; i++)
        { 
            // Push the quality of the worker to the heap
            pq.push(worker_ratio[i].second); 
            
            // Add the quality to the sum
            sum_quality += worker_ratio[i].second; 
        }

        // Calculate the manager's ratio based on the highest wage-to-quality ratio among the k lowest workers
        double managerRatio = worker_ratio[k-1].first; 
        
        // Calculate the initial result by multiplying the manager's ratio with the sum of quality values
        double result = managerRatio * sum_quality;

        // Iterate through the remaining workers starting from the (k+1)th worker
        for(int manager = k; manager < n; manager++) 
        {
            // Update the manager's ratio to that of the current worker
            managerRatio = worker_ratio[manager].first;

            // Include the current worker's quality into consideration
            pq.push(worker_ratio[manager].second); 
            sum_quality += worker_ratio[manager].second;

            // If the number of workers in the heap exceeds k, remove the worker with the highest quality
            if(pq.size() > k)
            {
                sum_quality -= pq.top();
                pq.pop();
            }

            // Update the result with the minimum of the current result and the new manager's cost
            result = min(result, managerRatio*sum_quality);

        }

        // Return the minimum cost to hire k workers
        return result;
    }
};
