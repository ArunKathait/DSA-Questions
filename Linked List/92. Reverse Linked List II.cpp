***************************************************APPROACH 1st(USING STACK)****************************************

class Solution {// TC ---> O(N)                               SC ---> O(right - left)--->Stack
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // Edge case:
        // 1) Empty list
        // 2) left == right → no need to reverse anything
        if (head == NULL || left == right) 
        {
            return head;
        }

        // Dummy node is used to simplify edge cases
        // especially when left == 1 (head changes)
        ListNode dummy(-1);
        dummy.next = head;

        // prev will point to the node just BEFORE
        // the part that needs to be reversed
        ListNode* prev = &dummy;

        // Move prev to (left - 1)th position
        // After this loop:
        // prev -> node at position (left - 1)
        for (int i = 1; i < left; i++) 
        {
            prev = prev->next;
        }

        // current points to the first node
        // of the sublist that needs to be reversed
        ListNode* current = prev->next;

        // Stack to store nodes from position left to right
        stack<ListNode*> st;

        // Push nodes [left ... right] into stack
        // This reverses their order logically
        for (int i = left; i <= right; i++) 
        {
            st.push(current);
            current = current->next;   // move forward
        }

        // connector is used to reconnect nodes
        // It initially points to prev
        ListNode* connector = prev;

        // Pop nodes from stack and connect them
        // This builds the reversed sublist
        while (!st.empty()) 
        {
            connector->next = st.top(); // attach top node
            st.pop();
            connector = connector->next; // move forward
        }

        // Connect the last reversed node
        // to the remaining part of the list
        connector->next = current;

        // dummy.next is the new head of the list
        return dummy.next;
    }
};

****************************************************APPROACH 2nd(OPTIMAL APPROACH)*************************************
  
