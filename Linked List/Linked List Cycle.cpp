class Solution { //TC--->O(N)        SC--->O(1)
public:
    bool hasCycle(ListNode *head) {
        
        //If our head or head->next is equal to NULL we return false
        if(head==NULL || head->next==NULL)
            return false;
        
        //Assign head to slow
        ListNode *slow=head;
        
        //Assign head to fast
        ListNode *fast=head;
        
        //Check till fast->next and fast->next->next not reach to end
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            //Move slow to its next
            slow=slow->next;
            
            //Move fast to its next->next
            fast=fast->next->next;
            
            //if slow is equal to fast it means there is a cycle so we return true
            if(slow==fast)
                return true;
        }
        
        //Else we return false
        return false;
    }
};
