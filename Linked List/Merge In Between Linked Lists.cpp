****************************************APPROACH 1st***********************************************************
class Solution {// TC--->O(N + M)       SC--->O(1)
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // Initialize variables
        
        // Index to keep track of the current position
        int index = 0;
        
        // Pointer to the node before the section to be replaced
        ListNode *left = NULL;
        
        // Pointer to the node after the section to be replaced
        ListNode *right = NULL;
        
        // Temporary pointer to traverse list1
        ListNode *temp = list1;
        
        // Traverse list1 to find the left and right boundary nodes
        while(temp!=NULL)
        {
            // If we reach the node just before the section to be replaced (node a-1)
            if(index == a-1)
            {
                // Update left to point to this node
                left = temp;
            }
            // If we reach the node just after the section to be replaced (node b+1)
            if(index == b+1)
            {
                // Update right to point to this node
                right = temp;
            }
            
            // Move to the next node
            temp = temp->next;
            
            // Increment the index to keep track of the current position
            index++;
        }
        
        // Traverse list2 to find its last node
        ListNode *list2End = list2;
        while(list2End->next!=NULL)
        {
            // Move to the next node in list2
            list2End = list2End->next;
        }
        
        // Update pointers to merge list2 into list1
        // Connect the last node of the section before list2
        left->next = list2;
        
        // Connect the last node of list2 to the node after the section to be replaced
        list2End->next = right;
        
        // Return the modified list1
        return list1;
        
    }
};

/*

NOTE:If our head of list1 will change then we make a dummy node but in this case our head is not changing so below steps are not required.

ListNode* dummy = new ListNode(0);
dummy->next = list1;

*/


*****************************************APPROACH 2nd***********************************************************
class Solution {// TC--->O(N + M)           SC--->O(1)
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        // Pointer to the node just before the section to be replaced
        ListNode *left = NULL;
        
        // Pointer to the node after the section to be replaced, initialized to list1
        ListNode *right = list1;
        
        
        // Traverse list1 to find the left and right boundary nodes
        for(int i=0;i<=b+1;i++)
        {
            // If we reach the node just before the section to be replaced (node a-1)
            if(i == a-1)
            {
                // Update left to point to this node
                left = right;
            }
            else
            {
                // Move right pointer to the next node
                right = right->next;
            }
        }
        
        // Temporary pointer to traverse list2
        ListNode *temp = list2;
        
        // Traverse list2 to find its last node
        while(temp->next  != NULL)
        {
            // Move to the next node in list2
            temp = temp->next;
        }
        
        // Update pointers to merge list2 into list1
        // Connect the last node of the section to list2
        left->next = list2;
        
         // Connect the last node of list2 to the node after the section to be replaced
        temp->next = right;
        
         // Return the modified list1
        return list1;
    }
}; 
