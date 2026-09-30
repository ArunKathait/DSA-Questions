************************************************APPROACH 1st(STACK-BASED)*********************************************

class Solution {// Time: O(n + m)                             Space: O(n + m) for the two stacks
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Stack stores digits of l1.
        //
        // Example:
        // l1 = 7 -> 2 -> 4 -> 3
        //
        // Stack:
        //     3  <- top
        //     4
        //     2
        //     7
        //
        // The top gives us the last digit first.
        stack<int> st1;

        // Stack stores digits of l2.
        stack<int> st2;


        // ------------------------------------------------
        // STEP 1: PUSH ALL DIGITS OF l1 INTO st1
        // ------------------------------------------------

        while(l1 != NULL)
        {
            // Store current digit in the stack.
            st1.push(l1->val);

            // Move to the next node.
            l1 = l1->next;
        }


        // ------------------------------------------------
        // STEP 2: PUSH ALL DIGITS OF l2 INTO st2
        // ------------------------------------------------

        while(l2 != NULL)
        {
            // Store current digit in the stack.
            st2.push(l2->val);

            // Move to the next node.
            l2 = l2->next;
        }


        // 'head' will point to the first node
        // of our answer list.
        ListNode* head = NULL;

        // Stores carry from the previous addition.
        int carry = 0;


        // ------------------------------------------------
        // STEP 3: ADD DIGITS FROM RIGHT TO LEFT
        // ------------------------------------------------

        // Continue while:
        //
        // 1. st1 still has digits, OR
        // 2. st2 still has digits, OR
        // 3. carry is still present.
        //
        // The carry condition is important for cases like:
        // 9 + 1 = 10
        //
        // After both stacks become empty,
        // carry = 1 still needs to be processed.
        while(!st1.empty() || !st2.empty() || carry)
        {
            // Store the sum of the current digits.
            int sum = 0;


            // If st1 has a digit,
            // take the top digit.
            if(!st1.empty())
            {
                sum += st1.top();

                // Remove that digit because
                // we have processed it.
                st1.pop();
            }


            // If st2 has a digit,
            // take the top digit.
            if(!st2.empty())
            {
                sum += st2.top();

                // Remove that digit.
                st2.pop();
            }


            // Add carry from the previous calculation.
            sum += carry;


            // Calculate carry for the next position.
            //
            // Example:
            // sum = 15
            //
            // carry = 15 / 10 = 1
            carry = sum / 10;


            // Current digit of the answer.
            //
            // Example:
            // sum = 15
            // digit = 15 % 10 = 5
            ListNode* newNode = new ListNode(sum % 10);


            // Insert the new node at the FRONT.
            //
            // Why?
            //
            // We are calculating from right to left,
            // but the answer must be stored
            // from left to right.
            //
            // Example:
            //
            // First calculated digit = 7
            // head = 7
            //
            // Next calculated digit = 0
            // newNode -> 0 -> 7
            //
            // Next calculated digit = 8
            // newNode -> 8 -> 0 -> 7
            //
            // Final:
            // 7 -> 8 -> 0 -> 7
            newNode->next = head;
            head = newNode;
        }


        // Return the head of the answer list.
        return head;
    }
};

/*

┌─────────────────────────────────────┐
│       ADD TWO NUMBERS II            │
├─────────────────────────────────────┤
│ IDEA: Use stacks to process digits  │
│       from RIGHT → LEFT             │
│                                     │
│ STEP 1:                             │
│ Push l1 digits → st1                │
│ Push l2 digits → st2                │
│                                     │
│ STEP 2:                             │
│ Take top digits                     │
│ + carry                             │
│                                     │
│ digit = sum % 10                    │
│ carry = sum / 10                    │
│                                     │
│ STEP 3:                             │
│ Insert new node at FRONT            │
│ → keeps answer in forward order     │
│                                     │
│ Continue while:                     │
│ st1 || st2 || carry                 │
│                                     │
│ KEY: Stack → right-to-left addition │
│      Insert front → correct order   │
│                                     │
│ TC: O(n + m)                        │
│ SC: O(n + m)                        │
└─────────────────────────────────────┘

*/

**********************************************APPROACH 2nd(REVERSE LIST)***********************************************

class Solution {// Time Complexity: O(n + m)                     Space Complexity: O(1) auxiliary space
public:

    // ------------------------------------------------
    // FUNCTION: Reverse a linked list
    // ------------------------------------------------
    ListNode* reverseList(ListNode* head)
    {
        // 'current' points to the node we are currently processing.
        ListNode* current = head;

        // 'prev' will become the new head after reversal.
        ListNode* prev = NULL;

        while(current != NULL)
        {
            // Save the next node before changing current->next.
            //
            // Example:
            // 1 -> 2 -> 3
            //     ↑
            //   current
            //
            // We save 3 before changing 2's next pointer.
            ListNode* next = current->next;


            // Reverse the direction of the current node.
            //
            // Instead of:
            // current -> next
            //
            // Make it:
            // current -> prev
            current->next = prev;


            // Move 'prev' to the current node.
            //
            // Current node is now the first node
            // of the reversed portion.
            prev = current;


            // Move 'current' to the next original node.
            current = next;
        }

        // 'prev' is now the head of the reversed list.
        return prev;
    }


    // ------------------------------------------------
    // FUNCTION: Add Two Numbers II
    // ------------------------------------------------
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {

        // The numbers are given in forward order.
        //
        // Example:
        // l1 = 7 -> 2 -> 4 -> 3
        //       = 7243
        //
        // Normal addition starts from the RIGHTMOST digit.
        //
        // So reverse both lists.
        //
        // l1 = 3 -> 4 -> 2 -> 7
        // l2 = 4 -> 6 -> 5
        l1 = reverseList(l1);
        l2 = reverseList(l2);


        // Create a dummy node to make building
        // the result list easier.
        ListNode* dummy = new ListNode();

        // 'temp' always points to the last node
        // in our result list.
        ListNode* temp = dummy;


        // Stores carry from the previous digit addition.
        int carry = 0;


        // Continue while:
        //
        // 1. l1 still has digits, OR
        // 2. l2 still has digits, OR
        // 3. carry is still present.
        //
        // The carry condition handles cases like:
        // 9 + 1 = 10
        while(l1 || l2 || carry)
        {
            // Store the sum of the current digits.
            int sum = 0;


            // If l1 still has a node,
            // add its digit.
            if(l1)
            {
                sum += l1->val;

                // Move l1 to the next digit.
                l1 = l1->next;
            }


            // If l2 still has a node,
            // add its digit.
            if(l2)
            {
                sum += l2->val;

                // Move l2 to the next digit.
                l2 = l2->next;
            }


            // Add carry from the previous calculation.
            sum += carry;


            // Calculate carry for the next position.
            //
            // Example:
            // sum = 15
            //
            // carry = 15 / 10 = 1
            carry = sum / 10;


            // Get the current digit of the answer.
            //
            // Example:
            // sum = 15
            // digit = 15 % 10 = 5
            ListNode* newNode = new ListNode(sum % 10);


            // Attach the new node to the result list.
            temp->next = newNode;


            // Move temp to the newly created node.
            temp = temp->next;
        }


        // At this point, the result is in REVERSE order.
        //
        // Example:
        //
        // Actual answer:
        // 7 -> 8 -> 0 -> 7
        //
        // We generated:
        // 7 -> 0 -> 8 -> 7
        //
        // So reverse the result one more time.
        return reverseList(dummy->next);
    }
};

/*

┌─────────────────────────────────────┐
│       ADD TWO NUMBERS II            │
├─────────────────────────────────────┤
│ IDEA: Reverse → Add → Reverse       │
│                                     │
│ 1. Reverse l1 and l2                │
│    → process digits RIGHT → LEFT    │
│                                     │
│ 2. Add corresponding digits         │
│    sum = digit1 + digit2 + carry    │
│                                     │
│    digit = sum % 10                 │
│    carry = sum / 10                 │
│                                     │
│ 3. Build result using dummy node    │
│                                     │
│ 4. Reverse result                   │
│    → restore LEFT → RIGHT order     │
│                                     │
│ LOOP: l1 || l2 || carry             │
│                                     │
│ KEY: carry handles extra digit      │
│                                     │
│ TC: O(n + m)                        │
│ SC: O(1) auxiliary                  │
│ Output: O(max(n,m))                 │
└─────────────────────────────────────┘

*/
