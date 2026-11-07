

class Solution {// Time Complexity: O(nlog n + mlog n)                         SC ---> O(n + m)
public:
    // Pair: {weight, index}
    typedef pair<int, int> P;

    // Tuple: {finishTime, weight, index}
    typedef tuple<long, int, int> T;

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        int n = servers.size();
        int m = tasks.size();

        // Min heap of available servers.
        // Select server with:
        // 1. Minimum weight
        // 2. Minimum index if weights are equal
        priority_queue<P, vector<P>, greater<P>> freeServers;

        // Initially, all servers are available
        for (int i = 0; i < n; i++) 
        {
            freeServers.push({servers[i], i});
        }

        // Min heap of busy servers.
        // Select server with:
        // 1. Earliest finish time
        // 2. Minimum weight
        // 3. Minimum index
        priority_queue<T, vector<T>, greater<T>> busyServers;

        vector<int> ans(m);

        // Process tasks in their original order
        for (int i = 0; i < m; i++) 
        {
            // Move all servers that have completed their tasks
            // back into the available servers heap
            while (!busyServers.empty() && get<0>(busyServers.top()) <= i) 
            {

                auto [finTime, wt, index] = busyServers.top();
                busyServers.pop();

                freeServers.push({wt, index});
            }

            // Case 1: No server is currently available
            if (freeServers.empty()) 
            {
                // Pick the server that will become free earliest
                auto [finTime, wt, index] = busyServers.top();
                busyServers.pop();

                // Assign the current task to this server
                ans[i] = index;

                // Server will finish after completing this task
                busyServers.push({finTime + tasks[i], wt, index});
            }

            // Case 2: At least one server is available
            else 
            {
                // Pick the server with minimum weight,
                // then minimum index
                auto [wt, index] = freeServers.top();
                freeServers.pop();

                // Store the assigned server index
                ans[i] = index;

                // Server becomes busy until task completion
                busyServers.push({i + tasks[i], wt, index});
            }
        }

        return ans;
    }
};

/*

┌──────────────────────────────────────────────────────┐
│          PROCESS TASKS USING SERVERS (LC 1882)       │
├──────────────────────────────────────────────────────┤
│ APPROACH: Greedy + Two Min Heaps                     │
│                                                      │
│ KEY IDEA:                                            │
│ • Maintain two priority queues: free and busy.       │
│ • Free heap stores {weight, index}.                  │
│ • Busy heap stores {finishTime, weight, index}.      │
│ • Initially, insert all servers into free heap.      │
│ • Process tasks in their original order.             │
│ • Move completed servers back to the free heap.      │
│ • If free server exists, choose minimum weight.      │
│ • If weights are equal, choose minimum index.        │
│ • If no server is free, choose earliest finish time. │
│ • Update finish time and push server into busy heap. │
│                                                      │
│ IMPORTANT CONDITIONS:                                │
│ • finishTime <= i  → Move server to free heap        │
│ • freeServers.empty() → Select earliest busy server  │
│ • i + tasks[i] → Finish time (free server)           │
│ • finTime + tasks[i] → Finish time (busy server)     │
│                                                      │
│ ANSWER:                                              │
│ ans[i] = index of assigned server                    │
│                                                      │
│ COMPLEXITY:                                          │
│ • Time:  O(n log n + m log n)                        │
│ • Space: O(n + m)                                    │
│ • Auxiliary Space: O(n)                              │
│                                                      │
│ PATTERN: Greedy + Priority Queue + Simulation        │
└──────────────────────────────────────────────────────┘

*/
