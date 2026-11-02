
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {// Time Complexity: O(n)                         Space Complexity: O(1)
public:

    // Finds the kth node starting from temp.
    // For example:
    // temp = 1 -> 2 -> 3 -> 4, k = 3
    // Returns node 3.
    ListNode *findKthNode(ListNode *temp, int k)
    {
        // Move k-1 steps to reach the kth node.
        while(k > 1 && temp != NULL)
        {
            temp = temp->next;
            k--;
        }

        return temp;
    }

    // Reverses a linked list using three pointers.
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *current = head;

        while(current != NULL)
        {
            // Store the next node before changing the link.
            ListNode *nextNode = current->next;

            // Reverse the current node's link.
            current->next = prev;

            // Move prev and current one step forward.
            prev = current;
            current = nextNode;
        }

        // Prev becomes the new head after reversal.
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        // Points to the first node of the current group.
        ListNode *temp = head;

        // Stores the last node of the previously reversed group.
        ListNode *prevLast = NULL;

        while(temp != NULL)
        {
            // Find the kth node of the current group.
            ListNode *kthNode = findKthNode(temp, k);

            // If kthNode is NULL, fewer than k nodes remain.
            // These remaining nodes should not be reversed.
            if(kthNode == NULL)
            {
                // Connect the previous reversed group
                // to the remaining unreversed nodes.
                if(prevLast)
                {
                    prevLast->next = temp;
                }

                break;
            }

            // Save the node immediately after the current group.
            // We need this because we will disconnect the group.
            ListNode *nextNode = kthNode->next;

            // Disconnect the current group from the remaining list.
            kthNode->next = NULL;

            // Reverse the current group.
            // The original head (temp) becomes its last node.
            reverseList(temp);

            // If this is the first group, update the list head.
            if(head == temp)
            {
                head = kthNode;
            }
            else
            {
                // Connect the previous group's last node
                // to the new head of the current reversed group.
                prevLast->next = kthNode;
            }

            // The original first node is now the last node
            // of the reversed group.
            prevLast = temp;

            // Move to the next group.
            temp = nextNode;
        }

        return head;
    }
};

/*

┌──────────────────────────────────────────────────────┐
│             REVERSE NODES IN K-GROUPS                │
├──────────────────────────────────────────────────────┤
│ APPROACH: Iterative Linked List Reversal             │
│                                                      │
│ KEY IDEA:                                            │
│ 1. Find the kth node of the current group.           │
│ 2. If fewer than k nodes remain, stop reversing.     │
│ 3. Save the next group's starting node.              │
│ 4. Disconnect the current group.                     │
│ 5. Reverse the current group.                        │
│ 6. Connect it with the previous reversed group.      │
│ 7. Move to the next group.                           │
│                                                      │
│ IMPORTANT POINTERS:                                  │
│ • temp     → Start of current group                  │
│ • kthNode  → End of current group                    │
│ • nextNode → Start of next group                     │
│ • prevLast → Last node of previous reversed group    │
│                                                      │
│ EDGE CASE:                                           │
│ Remaining nodes < k → Keep them unchanged.           │
│                                                      │
├──────────────────────────────────────────────────────┤
│ TIME COMPLEXITY:  O(n)                               │
│ SPACE COMPLEXITY: O(1)  (Auxiliary)                  │
└──────────────────────────────────────────────────────┘

*/
