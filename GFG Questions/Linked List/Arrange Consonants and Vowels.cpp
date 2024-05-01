*******************************************APPROACH 1st***********************************************

  class Solution {// TC--->O(N)            SC--->O(N)
  public:
  
    // Function to check if a character is a vowel.
    bool isVowel(char ch)
    {
        // Check if the character is 'a', 'e', 'i', 'o', or 'u'.
        // Return true if it is a vowel, otherwise return false.
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            return true;
        }
        return false;
    }
    
    // Function to rearrange the linked list such that vowels appear first followed by consonants.
    struct Node* arrangeCV(Node* head) {
        
        // Create vectors to store vowels and consonants.
        vector<char>vowels;
        vector<char>consonants;
        
        // Traverse the linked list and separate vowels and consonants into respective vectors.
        // Initialize a temporary pointer 'temp' to the head of the linked list.
        Node *temp = head;
        
        // Loop until 'temp' reaches the end of the linked list.
        while(temp != NULL)
        {
            // Check if the current character is a vowel.
            if(isVowel(temp->data))
            {
                // If it is a vowel, add it to the 'vowels' vector.
                vowels.push_back(temp->data);
            }
            else
            {
                // If it is a consonant, add it to the 'consonants' vector.
                consonants.push_back(temp->data);
            }
            
            // Move 'temp' to the next node in the linked list.
            temp = temp->next;
        }
        
        // Reset temp pointer to the head of the linked list.
        temp = head;
        
        // Rewrite the linked list with vowels followed by consonants.
        // Iterate through the 'vowels' vector.
        for(int i=0;i<vowels.size();i++)
        {
            // Update the data of the current node with the vowel.
            temp->data = vowels[i];
            
            // Move 'temp' to the next node in the linked list.
            temp = temp->next;
        }
        
        // Iterate through the 'consonants' vector.
        for(int j=0;j<consonants.size();j++)
        {
            // Update the data of the current node with the consonant.
            temp->data = consonants[j];
            
            // Move 'temp' to the next node in the linked list.
            temp = temp->next;
        }
        
        // Return the head of the rearranged linked list.
        return head;
    }
};

****************************************APPROACH 2nd******************************************************

  class Solution {// TC--->O(N)            SC--->O(1)
  public:
    
    // Function to rearrange the linked list such that vowels appear first followed by consonants.
    struct Node* arrangeCV(Node* head) {
        
        // Create two dummy nodes to represent the heads of lists for vowels and consonants.
        // Create a dummy node for vowels, initialized with '#' data.
        Node *vowelHead = new Node('#');
        
        // Create a dummy node for consonants, initialized with '#' data.
        Node *consonantHead = new Node('#');
        
        // Create pointers to keep track of the current nodes for vowels and consonants.
        // Initialize the pointer for vowels to the dummy node.
        Node *currentVowel = vowelHead;
        
         // Initialize the pointer for consonants to the dummy node.
        Node *currentConsonant = consonantHead;
        
        // Initialize a temporary pointer to traverse the original linked list.
        Node *temp = head;
        
         // Traverse the original linked list.
        while(temp != NULL)
        {
            // Retrieve the character data stored in the current node of the linked list.
            char ch = temp->data;
            
            // Check if the current character is a vowel.
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                // If it is a vowel, append it to the list of vowels.
                currentVowel->next = temp;
                
                // Move the pointer to the new last node in the vowels list.
                currentVowel = currentVowel->next;
            }
            else
            {
                // If it is a consonant, append it to the list of consonants.
                currentConsonant->next = temp;
                
                 // Move the pointer to the new last node in the consonants list.
                currentConsonant = currentConsonant->next;
            }
            // Move to the next node in the original linked list.
            temp = temp->next;
        }
        
        // Set the next pointers of the last nodes in both lists to NULL to terminate the lists.
        currentVowel->next = NULL;
        currentConsonant->next = NULL;
        
        // Concatenate the list of consonants to the end of the list of vowels.
        currentVowel->next = consonantHead->next;
        
        // Return the head of the rearranged linked list (head of the list of vowels).
        return vowelHead->next;
    }
};

****************************************APPROACH 3rd******************************************************

  class Solution {// TC--->O(N)            SC--->O(1)
  public:
    
    // Function to check if a character is a vowel.
    bool isVowel(char ch)
    {
        // Check if the character is 'a', 'e', 'i', 'o', or 'u'.
        // Return true if it is a vowel, otherwise return false.
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            return true;
        }
        return false;
    }
    
    // Function to rearrange the linked list such that vowels appear first followed by consonants.
    struct Node* arrangeCV(Node* head) {
        
        // Create two dummy nodes to represent the heads of lists for vowels and consonants.
        // Create a dummy node for vowels, initialized with '#' data.
        Node *vowelHead = new Node('#');
        
        // Create a dummy node for consonants, initialized with '#' data.
        Node *consonantHead = new Node('#');
        
        // Create pointers to keep track of the current nodes for vowels and consonants.
        // Initialize the pointer for vowels to the dummy node.
        Node *currentVowel = vowelHead;
        
         // Initialize the pointer for consonants to the dummy node.
        Node *currentConsonant = consonantHead;
        
        // Initialize a temporary pointer to traverse the original linked list.
        Node *temp = head;
        
         // Traverse the original linked list.
        while(temp != NULL)
        {
            // Check if the current character is a vowel.
            if(isVowel(temp->data))
            {
                // If it is a vowel, append it to the list of vowels.
                currentVowel->next = temp;
                
                // Move the pointer to the new last node in the vowels list.
                currentVowel = currentVowel->next;
            }
            else
            {
                // If it is a consonant, append it to the list of consonants.
                currentConsonant->next = temp;
                
                 // Move the pointer to the new last node in the consonants list.
                currentConsonant = currentConsonant->next;
            }
            // Move to the next node in the original linked list.
            temp = temp->next;
        }
        
        // Set the next pointers of the last nodes in both lists to NULL to terminate the lists.
        currentVowel->next = NULL;
        currentConsonant->next = NULL;
        
        // Concatenate the list of consonants to the end of the list of vowels.
        currentVowel->next = consonantHead->next;
        
        // Return the head of the rearranged linked list (head of the list of vowels).
        return vowelHead->next;
    }
};
