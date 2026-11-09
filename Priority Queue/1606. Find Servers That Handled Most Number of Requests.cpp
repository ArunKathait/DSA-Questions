
class Solution {// TC ---> O(k + nlogk)                       SC ---> O(k)
public:
    // Stores {finishTime, serverIndex}
    typedef pair<int,int> P;

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        int n = arrival.size();

        // Stores the indices of all currently available servers.
        // Initially, all k servers are available.
        set<int> availableServers;

        for(int i = 0; i < k; i++)
        {
            availableServers.insert(i);
        }

        // Stores how many requests each server has handled.
        vector<int> countRequests(k, 0);

        // Min heap stores {finishTime, serverIndex}.
        // The server that finishes earliest is at the top.
        priority_queue<P, vector<P>, greater<P>> busyServers;

        // Process requests in the order of their arrival.
        for(int i = 0; i < n; i++)
        {
            int time = arrival[i];

            // Step 1: Release all servers whose requests
            // have finished at or before the current arrival time.
            while(!busyServers.empty() && busyServers.top().first <= time)
            {
                // Get the server that has completed its request.
                int server = busyServers.top().second;

                // Mark this server as available again.
                availableServers.insert(server);

                // Remove the completed request from the min heap.
                busyServers.pop();
            }

            // Step 2: Find the preferred server for this request.
            // Requests are assigned in a round-robin manner.
            // Request i prefers server (i % k).
            int target = i % k;

            // Find the smallest available server index >= target.
            auto it = availableServers.lower_bound(target);

            // If no such server exists, wrap around
            // and start searching from the smallest available server.
            if(it == availableServers.end())
            {
                it = availableServers.begin();
            }

            // Step 3: If no server is available,
            // drop the current request.
            if(availableServers.empty())
            {
                continue;
            }

            // Get the selected available server.
            int targetServer = *it;

            // Mark this server as busy by removing it from the set.
            availableServers.erase(it);

            // Calculate when this server will finish processing
            // the current request and insert it into the min heap.
            busyServers.push({time + load[i], targetServer});

            // Increase the number of requests handled by this server.
            countRequests[targetServer]++;
        }

        // Step 4: Find the maximum number of requests handled
        // by any server.
        int maxNumberOfRequests = *max_element(countRequests.begin(), countRequests.end());

        // Store all servers that handled the maximum number of requests.
        vector<int> ans;

        for(int i = 0; i < k; i++)
        {
            if(countRequests[i] == maxNumberOfRequests)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

/*

┌────────────────────────────────────────────────────────┐
│       BUSIEST SERVERS (LEETCODE 1606)                  │
├────────────────────────────────────────────────────────┤
│ APPROACH: Greedy + Set + Min Heap                      │
│                                                        │
│ KEY IDEA:                                              │
│ • Set stores currently available servers.              │
│ • Min Heap stores busy servers by finishing time.      │
│ • Release servers when finishTime <= arrival[i].       │
│ • Find next available server using lower_bound(i % k). │
│ • If no server is available, skip the request.         │
│ • Count requests handled by each server.               │
│                                                        │
├────────────────────────────────────────────────────────┤
│ TIME COMPLEXITY:  O(k + n log k)                       │
│ SPACE COMPLEXITY: O(k)                                 │
│ EXTRA SPACE:      O(k)                                 │
└────────────────────────────────────────────────────────┘

*/
