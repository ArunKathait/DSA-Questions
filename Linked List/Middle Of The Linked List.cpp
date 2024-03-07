***************************************************APPROACH 1***************************************************
  
class Solution { //TC--->O(N)         SC--->O(1)
public:
    ListNode* middleNode(ListNode* head) {

        // Initialize two pointers, slow and fast, both starting at the head of the linked list
        ListNode* slow=head;
        ListNode* fast=head;

        // Traverse the linked list using two pointers:
        // - The 'slow' pointer moves one step at a time
        // - The 'fast' pointer moves two steps at a time
        while(fast!=NULL && fast->next!=NULL )
        {
            slow=slow->next;// Move slow pointer one step forward
            fast=fast->next->next; // Move fast pointer two steps forward
        }

        // When the fast pointer reaches the end of the linked list (NULL), 
        // the slow pointer will be pointing to the middle node.
        return slow;
    }
};

*************************************APPROACH 2****************************************************************
  
class Solution {//TC--->O(N)        SC--->O(1)
public:
    ListNode* middleNode(ListNode* head) {

      // Create a temporary pointer to traverse the linked list starting from the head
        ListNode* temp=head;

      // Initialize a variable to count the number of nodes in the linked list
        int count=0;

      // Loop through the linked list and count the number of nodes
        while(temp!=NULL)
        {
          // Move the pointer to the next node
            temp=temp->next;
          
          // Increment the count
            count++;
        }

      // Reset the temporary pointer to the head of the linked list
        temp=head;

      // Traverse halfway through the linked list to find the middle node
        for(int i=0;i<count/2;i++)
        {
          // Move the pointer to the next node
            temp=temp->next;
        }
      
      // Return the pointer pointing to the middle node of the linked list
      return temp;  
    }
};
