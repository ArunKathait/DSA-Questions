*******************************************APPROACH 1st(DFS)**********************************************************

class Solution {// Time Complexity: O(n)                       Space Complexity: O(n)
public:

    // DFS function
    // employee     -> current employee we are visiting
    // adj           -> stores manager -> list of employees
    // informTime    -> time each employee takes to inform their subordinates
    // currentTime   -> time taken to reach the current employee
    // maxTime       -> maximum time needed to inform everyone
    void dfs(int employee, unordered_map<int, vector<int>>& adj, vector<int>& informTime, int currentTime, int& maxTime)
    {
        // Update maximum time reached so far
        maxTime = max(maxTime, currentTime);

        // Visit all employees who are directly managed by current employee
        for(auto& child : adj[employee])
        {
            // Current employee takes informTime[employee] minutes
            // to inform this child.
            //
            // So the time taken to reach the child is:
            // currentTime + informTime[employee]
            dfs(child, adj, informTime, currentTime + informTime[employee],maxTime);
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        // Adjacency list:
        // manager -> employees working directly under that manager
        unordered_map<int, vector<int>> adj;

        // Build the manager -> employee relationship
        for(int i = 0; i < n; i++)
        {
            // manager[i] == -1 means employee i is the head
            if(manager[i] != -1)
            {
                // Employee i works under manager[i]
                adj[manager[i]].push_back(i);
            }
        }

        // Initially, no time has passed
        int maxTime = 0;

        // Start DFS from the head of the company
        // Head is reached at time 0
        dfs(headID, adj, informTime, 0, maxTime);

        // Maximum time required to inform all employees
        return maxTime;
    }
};

/*

┌──────────────────────────────────────┐
│       LC 1376 — DFS Cheat Box        │
├──────────────────────────────────────┤
│ Pattern: Tree + DFS                  │
│                                      │
│ Build: manager → employees           │
│                                      │
│ DFS(employee):                       │
│   maxTime = max(maxTime,currentTime) │
│                                      │
│   For every child:                   │
│     time = currentTime               │
│          + informTime[employee]      │
│     DFS(child)                       │
│                                      │
│ Answer = maximum time reached        │
│                                      │
│ Key Point:                           │
│ Add informTime[employee], NOT        │
│ informTime[child].                   │
│                                      │
│ TC: O(n)                             │
│ SC: O(n)                             │
└──────────────────────────────────────┘

*/

*********************************************APPROACH 2nd(BFS)********************************************************

class Solution {// TC: O(n)                                  SC: O(n)
public:

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        // Adjacency list:
        // adj[manager] = list of employees directly managed by that manager
        //
        // Example:
        // manager = [-1, 0, 0, 1, 1]
        //
        // adj:
        // 0 -> {1, 2}
        // 1 -> {3, 4}
        unordered_map<int, vector<int>> adj;

        // Build the manager -> employees relationship
        for(int i = 0; i < n; i++)
        {
            // manager[i] == -1 means employee i is the head
            if(manager[i] != -1)
            {
                // Employee i works directly under manager[i]
                adj[manager[i]].push_back(i);
            }
        }

        // Stores the maximum time required to reach any employee
        int maxTime = 0;

        // Queue stores:
        // {employee, time taken to reach this employee}
        //
        // Initially, head is already informed,
        // so the time taken to reach head = 0
        queue<pair<int, int>> q;
        q.push({headID, 0});

        // BFS traversal
        while(!q.empty())
        {
            // Get the employee and the time taken
            // to reach this employee
            auto [employee, time] = q.front();
            q.pop();

            // Update the maximum time seen so far
            maxTime = max(maxTime, time);

            // Visit all employees directly managed
            // by the current employee
            for(auto& child : adj[employee])
            {
                // Current employee needs informTime[employee]
                // minutes to inform the child.
                //
                // Therefore:
                //
                // time taken to reach child
                // = time taken to reach current employee
                //   + time current employee takes to inform
                //
                // Example:
                // Current employee reached at 5 minutes
                // informTime[employee] = 3
                //
                // Child will receive information at:
                // 5 + 3 = 8 minutes

                q.push({child,time + informTime[employee]});
            }
        }

        // The employee who receives the information last
        // determines the total time required.
        return maxTime;
    }
};

/*

┌──────────────────────────────────────┐
│       LC 1376 — BFS Cheat Box        │
├──────────────────────────────────────┤
│ Pattern: Tree + BFS                  │
│                                      │
│ Build: manager → children            │
│                                      │
│ Queue: {employee, currentTime}       │
│ Start: {headID, 0}                   │
│                                      │
│ For each child:                      │
│   childTime = currentTime            │
│              + informTime[employee]  │
│                                      │
│ maxTime = max(maxTime, currentTime)  │
│                                      │
│ Key Point: Add current employee's    │
│ informTime, NOT child's.             │
│                                      │
│ TC: O(n)                             │
│ SC: O(n)                             │
└──────────────────────────────────────┘

*/
