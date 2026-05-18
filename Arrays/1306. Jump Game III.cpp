***************************************************APPROACH 1st(DFS)**************************************************

class Solution {
public:

    // TC ---> O(N)
    // SC ---> O(N) recursion stack

    bool solve(int index, int n, vector<int>& arr)
    {
        // Out of bounds
        // or already visited
        if(index < 0 || index >= n || arr[index] < 0)
        {
            return false;
        }

        // Reached zero
        if(arr[index] == 0)
        {
            return true;
        }

        // Store jump value before marking visited
        int jump = arr[index];

        // Mark visited
        arr[index] *= -1;

        // Move left or right
        bool left = solve(index - jump, n, arr);
        bool right = solve(index + jump, n, arr);

        return left || right;
    }

    bool canReach(vector<int>& arr, int start) {

        int n = arr.size();

        // Start DFS from start index
        return solve(start, n, arr);
    }
};

*************************************************APPROACH 2nd(BFS)***************************************************

class Solution {
public:

    // TC ---> O(N)
    // SC ---> O(N)

    bool canReach(vector<int>& arr, int start) {

        int n = arr.size();

        queue<int> q;

        // Visited array to avoid cycles
        vector<bool> visited(n, false);

        // Start BFS from given index
        q.push(start);
        visited[start] = true;

        while(!q.empty())
        {
            int index = q.front();
            q.pop();

            // Reached value 0
            if(arr[index] == 0)
            {
                return true;
            }

            // -----------------------------------
            // Jump right
            // -----------------------------------
            int right = index + arr[index];

            if(right < n && !visited[right])
            {
                visited[right] = true;
                q.push(right);
            }

            // -----------------------------------
            // Jump left
            // -----------------------------------
            int left = index - arr[index];

            if(left >= 0 && !visited[left])
            {
                visited[left] = true;
                q.push(left);
            }
        }

        // Cannot reach any 0
        return false;
    }
};
