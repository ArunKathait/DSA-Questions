
class Solution {// TC: O(m log m + q log q)                            SC: O(m + q + n)
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        int m = logs.size();

        // Sort logs based on timestamp (logs[i][1])
        // This allows us to process requests in increasing time order.
        auto lambda = [](vector<int>& vec1, vector<int>& vec2)
        {
            return vec1[1] < vec2[1];
        };

        sort(logs.begin(), logs.end(), lambda);

        int q = queries.size();

        // Stores the final answer for each query.
        vector<int> ans(q);

        // Store each query along with its original index.
        // We sort queries by time, but need to return answers
        // in the original order.
        vector<pair<int, int>> timeIndex(q);

        for(int i = 0; i < q; i++)
        {
            timeIndex[i] = {queries[i], i};
        }

        // Process queries in increasing order of time.
        sort(timeIndex.begin(), timeIndex.end());

        // Stores the frequency of requests made by each server
        // inside the current sliding window.
        unordered_map<int, int> ump;

        // i = left pointer of the sliding window.
        // j = right pointer of the sliding window.
        int i = 0;
        int j = 0;

        for(auto [time, index] : timeIndex)
        {
            // Current query's time window is [time - x, time].
            int start = time - x;
            int end = time;

            // Expand the window:
            // Include all logs whose timestamp is <= end.
            while(j < m && logs[j][1] <= end)
            {
                // Increase the request count for this server.
                ump[logs[j][0]]++;

                // Move right pointer forward.
                j++;
            }

            // Shrink the window:
            // Remove logs whose timestamp is < start.
            while(i < m && logs[i][1] < start)
            {
                // Decrease the request count for this server.
                ump[logs[i][0]]--;

                // If this server has no requests left in the window,
                // remove it from the map.
                if(ump[logs[i][0]] == 0)
                {
                    ump.erase(logs[i][0]);
                }

                // Move left pointer forward.
                i++;
            }

            // ump.size() = number of servers that received
            // at least one request in the current time window.
            //
            // Total servers - active servers = inactive servers.
            ans[index] = n - ump.size();
        }

        // Return answers in the original query order.
        return ans;
    }
};

/*

┌──────────────────────────────────────────────────────┐
│       COUNT SERVERS THAT DIDN'T RECEIVE REQUESTS     │
├──────────────────────────────────────────────────────┤
│ APPROACH: Sorting + Sliding Window + HashMap         │
│                                                      │
│ KEY IDEA:                                            │
│ • Sort logs based on timestamp.                      │
│ • Store queries with their original indices.         │
│ • Sort queries by timestamp.                         │
│ • Maintain window [time - x, time].                  │
│ • Use j to include logs (timestamp <= end).          │
│ • Use i to remove logs (timestamp < start).          │
│ • HashMap stores request frequency of each server.   │
│ • Erase server when its frequency becomes zero.      │
│ • Count inactive servers = n - ump.size().           │
│                                                      │
│ IMPORTANT CONDITIONS:                                │
│ • logs[j][1] <= end   → Add log to window            │
│ • logs[i][1] < start  → Remove log from window       │
│ • ump[server] == 0    → Erase server from map        │
│                                                      │
│ ANSWER:                                              │
│ ans[index] = n - ump.size()                          │
│                                                      │
│ COMPLEXITY:                                          │
│ • Time:  O(M log M + Q log Q)                        │
│ • Space: O(M + Q + N)                                │
│                                                      │
│ PATTERN: Sorting + Offline Queries + Sliding Window  │
└──────────────────────────────────────────────────────┘

*/
