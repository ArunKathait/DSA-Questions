
class Solution {// TC--->O(N)                                       SC--->O(1)
  public:
  
  // Function to reverse a linked list
  Node *reverseList(Node *head)
  {
      // Pointer to traverse the list
      Node *temp = head;
      
      // Pointer to keep track of the previous node
      Node *prev = NULL;
      
      // Traverse the list and reverse the links
      while(temp != NULL)
      {
          // Store the next node
          Node *next = temp->next;
          
          // Reverse the current node's link
          temp->next = prev;
          
           // Move 'prev' to the current node
          prev = temp;
          
          // Move 'temp' to the next node
          temp = next;
      }
      
      // 'prev' will be the new head after reversal
      return prev;
  }
  
  // Function to add one to the number represented by the linked list
    Node* addOne(Node* head) {
        // Step 1: Reverse the linked list to make addition easier
       head = reverseList(head);
       
       // Pointer to traverse the reversed list
       Node *temp = head;
       
       // Initialize carry with 1 (since we want to add 1)
       int carry = 1;
       
       // Step 2: Traverse the list and add the carry
       while(temp != NULL)
       {
           if(temp->data < 9)
           {
               // If the current node's value is less than 9, simply add the carry
               temp->data = temp->data + 1;
               
               // No carry left to propagate
               carry = 0;
               
               // Addition done, exit the loop
               break;
           }
           else
           {
               // If the current node's value is 9, it becomes 0 (since 9 + 1 = 10)
               temp->data = 0;
               // Carry remains 1, continue to the next node
           }
           
           // Move to the next node
           temp = temp->next;
       }
       
       // Step 3: Reverse the list again to restore the original order
       head = reverseList(head);
       
       // Step 4: If there's still a carry left, we need to add a new node at the beginning
       if(carry)
       {
           // Create a new node with value 1
           Node *newHead = new Node(1); 
           
           // Link the new node to the current head
           newHead->next = head;
           
           // Return the new head
           return newHead;
       }
       // Return the modified list
       return head;
    }
};
