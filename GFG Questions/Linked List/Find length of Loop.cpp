**************************************************APPROACH 1st(USING MAP)***********************************************

// Time Complexity = O(N)                     Space Complexity = O(N)
class Solution {
  public:
    int lengthOfLoop(Node *head) {
        
        // pointer to traverse the linked list
        Node *temp = head;   
        
        // hashmap to store each node's first visit time
        unordered_map<Node*,int> ump; 
        
        // counter to mark visiting order
        int timer = 1;  
        
        while (temp != NULL) 
        {
            // Case 1: If current node has been visited before → loop found
            if (ump.find(temp) != ump.end()) 
            {
                int val = ump[temp];        // time when this node was first visited
                return timer - val;         // difference = loop length
            }

            // Case 2: First time visiting this node → store visit time
            ump[temp] = timer;

            timer++;              // increment time for next node
            temp = temp->next;    // move to the next node
        }
        
        // If traversal reaches NULL → no loop exists
        return 0;
    }
};

*************************************************APPROACH 2nd(SLOW AND FAST POINTER)***********************************

// Total Time Complexity = O(N + K) = O(N)                     Space Complexity = O(1)
class Solution {
  public:
    // Helper function to find the length of the loop
    int findLength(Node *slow , Node *fast)
    {
        // we are already at one node in the loop
        int length = 1;
        
        // move fast one step ahead
        fast = fast->next;       
        
        // Keep moving fast until it meets slow again
        while (slow != fast) 
        {
            length++;
            fast = fast->next;
        }
        
        // total number of nodes in the loop
        return length;  
    }
    
    int lengthOfLoop(Node *head) {
        
        Node *slow = head;  // slow pointer moves 1 step at a time
        Node *fast = head;  // fast pointer moves 2 steps at a time
        
        // Traverse the linked list
        while (fast != NULL && fast->next != NULL) 
        {
            // move slow one step
            slow = slow->next;
            
            // move fast two steps
            fast = fast->next->next;    
            
            // If slow and fast meet → loop detected
            if (slow == fast) 
            {
                // Pass meeting point to helper function to count loop length
                return findLength(slow, fast);
            }
        }
        
        // If we exit the loop, that means no cycle
        return 0;
    }
};
