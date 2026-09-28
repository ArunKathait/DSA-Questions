************************************************APPROACH 1st(BRUTE FORCE)*********************************************

class Solution {
/*
Constructor:
Time  = O(n)
Space = O(n)

getRandom():
Time  = O(1)
Space = O(1) extra 
*/

public:

    // Vector to store all values of the linked list
    vector<int> nums;

    // Constructor receives the head of the linked list
    Solution(ListNode* head) {

        // Start traversing the linked list from head
        ListNode* temp = head;

        // Continue until we reach the end of the linked list
        while(temp != NULL)
        {
            // Store the current node's value in the vector
            nums.push_back(temp->val);

            // Move to the next node
            temp = temp->next;
        }
    }

    // Function to return a random node's value
    int getRandom() {

        // Get the total number of elements
        int n = nums.size();

        // rand() generates a random number.
        // % n converts it into an index from 0 to n-1.
        int randomIndex = rand() % n;

        // Return the value at the randomly selected index
        return nums[randomIndex];
    }
};

/*

┌─────────────────────────────────────┐
│       LINKED LIST RANDOM NODE       │
├─────────────────────────────────────┤
│ IDEA                                │
│ Linked List → Vector                │
│ Random index → Return value         │
│                                     │
│ CONSTRUCTOR                         │
│ Traverse linked list                │
│ Store each node value in nums       │
│                                     │
│ getRandom()                         │
│ n = nums.size()                     │
│ index = rand() % n                  │
│ return nums[index]                  │
│                                     │
│ rand() % n → index [0 ... n-1]      │
│                                     │
│ TC: Constructor = O(n)              │
│     getRandom() = O(1)              │
│                                     │
│ SC: O(n)                            │
│                                     │
│ KEY IDEA                            │
│ Store all values once, then use     │
│ random index for O(1) retrieval.    │
└─────────────────────────────────────┘

*/

***********************************************APPROACH 2nd(BETTER APPROACH)**************************************

class Solution {// Time:  O(n)                     Space: O(1) 
public:

    // Store the head of the linked list
    ListNode* Head;

    // Constructor receives the head node
    Solution(ListNode* head) {
        Head = head;
    }

    int getRandom() {

        // count = number of nodes seen so far
        // Start with 1 because we are processing the first node
        int count = 1;

        // ans stores the randomly selected node's value
        int ans = 0;

        // Start traversing from the head
        ListNode* temp = Head;

        // Traverse the complete linked list
        while(temp != NULL)
        {
            // Choose the current node with probability 1/count
            //
            // rand() % count generates a number from:
            // 0 to count-1
            //
            // Only when the result is 0 do we select
            // the current node.
            //
            // Therefore probability = 1/count
            if(rand() % count == 0)
            {
                // Replace the previously selected value
                // with the current node's value
                ans = temp->val;
            }

            // We have now processed one more node
            count++;

            // Move to the next node
            temp = temp->next;
        }

        // Return the randomly selected value
        return ans;
    }
};

/*

┌─────────────────────────────────────┐
│       LINKED LIST RANDOM NODE       │
├─────────────────────────────────────┤
│ IDEA                                │
│ Traverse list without storing it.   │
│                                     │
│ STATE                               │
│ count = nodes seen so far           │
│ ans   = selected value              │
│                                     │
│ FOR EACH NODE                       │
│ 1. Probability = 1 / count          │
│ 2. if rand() % count == 0           │
│       ans = current value           │
│ 3. count++                          │
│ 4. move to next node                │
│                                     │
│ KEY                                 │
│ Each node gets equal final chance   │
│ of being selected.                  │
│                                     │
│ TC: O(n)                            │
│ SC: O(1)                            │
│                                     │
│ Remember:                           │
│ Vector → O(n) space                 │
│ Reservoir → O(1) space              │
└─────────────────────────────────────┘

*/
