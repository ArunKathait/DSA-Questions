

class Solution {// TIME COMPLEXITY:  O(n log n)                     SPACE COMPLEXITY: O(n)
public:
    // Pair stores {processingTime, originalIndex}.
    typedef pair<int,int> P;

    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        // Store each task as:
        // {enqueueTime, processingTime, originalIndex}.
        vector<array<int,3>> sortedTasks;

        for(int i = 0; i < n; i++)
        {
            int enqueueTime = tasks[i][0];
            int processingTime = tasks[i][1];

            // Store the original index because sorting changes task order.
            sortedTasks.push_back({enqueueTime, processingTime, i});
        }

        // Sort tasks based on enqueueTime.
        // If enqueueTime is equal, compare processingTime,
        // and then originalIndex.
        sort(sortedTasks.begin(), sortedTasks.end());

        // Min heap stores {processingTime, originalIndex}.
        // It selects:
        // 1. Task with minimum processingTime.
        // 2. If tied, task with minimum originalIndex.
        priority_queue<P, vector<P>, greater<P>> pq;

        // Tracks the current time of the CPU.
        long long currentTime = 0;

        // Points to the next task in sortedTasks.
        int i = 0;

        // Stores the order in which tasks are processed.
        vector<int> ans;

        // Continue until all tasks are processed
        // and the priority queue becomes empty.
        while(i < n || !pq.empty())
        {
            // If no task is available in the heap,
            // move CPU time to the next task's enqueueTime.
            if(pq.empty() && currentTime < sortedTasks[i][0])
            {
                currentTime = sortedTasks[i][0];
            }

            // Add all tasks whose enqueueTime is
            // less than or equal to the current CPU time.
            while(i < n && sortedTasks[i][0] <= currentTime)
            {
                int processingTime = sortedTasks[i][1];
                int originalIndex = sortedTasks[i][2];

                // Push the available task into the min heap.
                pq.push({processingTime, originalIndex});

                // Move to the next task in sortedTasks.
                i++;
            }

            // Select the task with minimum processingTime.
            // If processingTime is equal, minimum index is selected.
            auto [processingTime, originalIndex] = pq.top();

            // Remove the selected task from the heap.
            pq.pop();

            // CPU executes the selected task completely.
            // Update currentTime after task completion.
            currentTime += processingTime;

            // Store the original index in the answer.
            ans.push_back(originalIndex);
        }

        // Return the order in which tasks were processed.
        return ans;
    }
};

/*

┌──────────────────────────────────────────────────────┐
│          SINGLE-THREADED CPU (LC 1834)               │
├──────────────────────────────────────────────────────┤
│ APPROACH: Sorting + Min Heap                         │
│                                                      │
│ KEY IDEA:                                            │
│ • Store {enqueueTime, processingTime, originalIndex}.│
│ • Sort tasks by enqueueTime.                         │
│ • Push all available tasks into a min heap.          │
│ • Select the task with minimum processingTime.       │
│ • If processing times tie, select minimum index.     │
│ • Update currentTime after task execution.           │
│ • If heap is empty, move time to the next task's     │
│   enqueueTime.                                       │
│                                                      │
│ TIME COMPLEXITY:  O(n log n)                         │
│ SPACE COMPLEXITY: O(n)                               │
│ TOTAL SPACE:      O(n)                               │
└──────────────────────────────────────────────────────┘

*/
