*************************************************APPROACH 1st(BRUTE FORCE)******************************************

class Solution {// Time Complexity: O(n log n)                 Space Complexity: O(n)
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // If the linked list is empty,
        // there is nothing to delete.
        if(head == NULL) 
        {
            return NULL;
        }

        // 'current' is used to traverse the linked list.
        ListNode* current = head;

        // Store frequency of every value.
        // Example:
        // 1 -> 2 -> 2 -> 3 -> 4 -> 4
        //
        // ump[1] = 1
        // ump[2] = 2
        // ump[3] = 1
        // ump[4] = 2
        map<int, int> ump;


        // ------------------------------------------------
        // STEP 1: COUNT FREQUENCY OF EVERY VALUE
        // ------------------------------------------------

        while(current != NULL) 
        {
            // Increase the frequency of current node's value.
            //
            // If value is seen for the first time:
            // ump[value] becomes 1
            //
            // If seen again:
            // ump[value] becomes 2, 3, ...
            ump[current->val]++;

            // Move to the next node.
            current = current->next;
        }


        // ------------------------------------------------
        // STEP 2: CREATE A DUMMY NODE
        // ------------------------------------------------

        // Dummy node is placed before the actual head.
        //
        // Dummy -> head -> ...
        //
        // It makes it easier to connect the remaining nodes,
        // especially when the first node itself is duplicated.
        ListNode* dummy = new ListNode();

        // Connect dummy node to the original head.
        dummy->next = head;

        // 'prev' represents the last node that we decided
        // to KEEP in the result.
        //
        // Initially, no real node has been kept,
        // so prev points to dummy.
        ListNode* prev = dummy;

        // Start traversing the original list again.
        current = head;


        // ------------------------------------------------
        // STEP 3: KEEP ONLY UNIQUE VALUES
        // ------------------------------------------------

        while(current != NULL) 
        {
            // Check how many times current value appeared.
            //
            // If frequency == 1:
            // This value is unique, so KEEP the node.
            if(ump[current->val] == 1) 
            {
                // Connect the previous kept node
                // to the current node.
                prev->next = current;

                // Current node is now the last kept node.
                prev = current;
            }

            // If frequency > 1:
            // We do NOT connect current node.
            // Therefore, it is skipped.


            // Move to the next node in the original list.
            current = current->next;
        }


        // ------------------------------------------------
        // STEP 4: CUT OFF REMAINING NODES
        // ------------------------------------------------

        // This is very important.
        //
        // Suppose:
        // 1 -> 2 -> 2 -> NULL
        //
        // We keep 1, but the original '1' node
        // may still point to 2.
        //
        // So we explicitly terminate the result:
        //
        // 1 -> NULL
        prev->next = NULL;


        // dummy->next points to the first node
        // of our final linked list.
        return dummy->next;
    }
};

/*

┌─────────────────────────────────────┐
│     REMOVE DUPLICATES — LC 82       │
├─────────────────────────────────────┤
│ IDEA: Count frequency → keep only   │
│       values appearing once         │
│                                     │
│ STEP 1:                             │
│ map[value]++                        │
│ → Count every value                 │
│                                     │
│ STEP 2:                             │
│ Traverse original list again        │
│                                     │
│ freq == 1 → KEEP node               │
│ freq > 1  → SKIP node               │
│                                     │
│ prev → last kept node               │
│ current → scans original list       │
│ dummy → handles head easily         │
│                                     │
│ IMPORTANT:                          │
│ prev->next = NULL                   │
│ → cut leftover duplicate nodes      │
│                                     │
│ TC: O(n log n)  → map               │
│ SC: O(n)       → frequency map      │
│                                     │
│ unordered_map → Avg TC O(n)         │
└─────────────────────────────────────┘

*/

**********************************************APPROACH 2nd(OPTIMAL)***************************************************

class Solution {// Time: O(n)                                        Space: O(1)
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // If the list is empty, return NULL.
        if(head == NULL) 
        {
            return NULL;
        }


        // Create a dummy node before the actual head.
        //
        // Example:
        // Original: 1 -> 2 -> 2 -> 3
        //
        // dummy -> 1 -> 2 -> 2 -> 3
        //
        // Dummy helps when the duplicate group starts
        // from the head itself.
        ListNode* dummy = new ListNode(0);

        // Connect dummy to the original head.
        dummy->next = head;


        // 'prev' points to the last node that we know
        // should remain in the final list.
        //
        // Initially, no actual node is confirmed unique,
        // so prev points to dummy.
        ListNode* prev = dummy;


        // 'current' is used to scan the linked list.
        ListNode* current = head;


        while(current != NULL) {

            // Check whether current is the beginning of
            // a duplicate group.
            //
            // Example:
            // 1 -> 2 -> 2 -> 3
            //     ↑
            //   current
            //
            // current->val == current->next->val
            // means 2 is duplicated.
            if(current->next != NULL && current->val == current->next->val) 
            {
                // Skip the entire duplicate group.
                //
                // Example:
                // 1 -> 2 -> 2 -> 2 -> 3
                //     ↑
                //   current
                //
                // After this loop:
                //
                // 1 -> 2 -> 2 -> 2 -> 3
                //                  ↑
                //               current
                //
                // current is now pointing to the LAST
                // node of the duplicate group.
                while(current->next != NULL && current->val == current->next->val) 
                {

                    current = current->next;
                }


                // Remove the entire duplicate group.
                //
                // prev is the last valid node before
                // the duplicate group.
                //
                // current is the last node of the duplicate group.
                //
                // So connect prev directly to the node
                // after the duplicate group.
                //
                // Example:
                //
                // 1 -> 2 -> 2 -> 3
                // ↑         ↑
                // prev    current
                //
                // Becomes:
                //
                // 1 -> 3
                prev->next = current->next;
            }

            else 
            {
                // Current value is unique because current
                // is not equal to the next node.
                //
                // Therefore, current should remain in
                // the final linked list.
                //
                // Move prev forward to current.
                prev = prev->next;
            }


            // Move current to the next node.
            current = current->next;
        }


        // Return the actual head of the resulting list.
        //
        // We return dummy->next because dummy itself
        // is not part of the answer.
        return dummy->next;
    }
};

/*

┌─────────────────────────────────────┐
│   REMOVE DUPLICATES — LC 82         │
├─────────────────────────────────────┤
│ IDEA: Remove the entire duplicate   │
│       group from the list           │
│                                     │
│ prev    → last valid/kept node      │
│ current → node being checked        │
│                                     │
│ current == next                     │
│      ↓                              │
│ Skip entire duplicate group         │
│      ↓                              │
│ prev->next = current->next          │
│                                     │
│ current != next                     │
│      ↓                              │
│ Move prev forward                   │
│                                     │
│ At end: return dummy->next          │
│                                     │
│ KEY: Dummy handles duplicate head   │
│      Inner while skips duplicates   │
│                                     │
│ TC: O(n)                            │
│ SC: O(1)                            │
└─────────────────────────────────────┘

*/
