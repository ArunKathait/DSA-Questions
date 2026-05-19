
class Solution {
public:

    // TC ---> O(N)
    // SC ---> O(N)

    int minJumps(vector<int>& arr) {

        int n = arr.size();

        // Edge case
        if(n == 1)
        {
            return 0;
        }

        // Value -> all indices mapping
        unordered_map<int, vector<int>> ump;

        for(int i = 0; i < n; i++)
        {
            ump[arr[i]].push_back(i);
        }

        queue<int> q;

        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        int steps = 0;

        while(!q.empty())
        {
            int size = q.size();

            // Process one BFS level
            while(size--)
            {
                int index = q.front();
                q.pop();

                // Reached destination
                if(index == n - 1)
                {
                    return steps;
                }

                // -----------------------------------
                // Left neighbor
                // -----------------------------------
                int left = index - 1;

                if(left >= 0 && !visited[left])
                {
                    visited[left] = true;
                    q.push(left);
                }

                // -----------------------------------
                // Right neighbor
                // -----------------------------------
                int right = index + 1;

                if(right < n && !visited[right])
                {
                    visited[right] = true;
                    q.push(right);
                }

                // -----------------------------------
                // Same value neighbors
                // -----------------------------------
                for(auto next : ump[arr[index]])
                {
                    if(!visited[next])
                    {
                        visited[next] = true;
                        q.push(next);
                    }
                }

                // IMPORTANT OPTIMIZATION
                ump[arr[index]].clear();
            }

            // One jump completed
            steps++;
        }

        return -1;
    }
};
