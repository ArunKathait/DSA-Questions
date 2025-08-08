*******************************************APPROACH 1st(USING STACK)*********************************************

// Define the BrowserHistory class
class BrowserHistory {      // Space Complexity ---> O(N)
public:
    // Stack to store previously visited pages (for back operation)
    stack<string> past;

    // Stack to store forward history (for forward operation)     
    stack<string> future;

    // String to keep track of the current page   
    string curr;            

    // Constructor initializes the browser with the homepage
    BrowserHistory(string homepage) 
    {
        // Set the current page to the homepage
        curr = homepage;    
    }

    // Visit a new URL
    void visit(string url)// TC ----------------------> O(1)
    {
        // Save the current page in the 'past' stack before moving
        past.push(curr);

        // Set the current page to the new URL    
        curr = url;         

        // Clear the forward history because visiting a new page breaks the forward chain
        while(!future.empty()) 
        {
            future.pop();
        }
    }

    // Move back by a certain number of steps
    string back(int steps) // TC ----------------------->O(steps)
    {
        // While there are steps left and the past stack is not empty
        while(steps > 0 && !past.empty()) 
        {
            // Push the current page into 'future' stack to enable forward
            future.push(curr);

            // Set current page to the top of the past stack (previous page)     
            curr = past.top();  

            // Remove the top element from past stack   
            past.pop(); 

            // Decrease the number of steps           
            steps--;               
        }
         // Return the current page after going back
        return curr;              
    }

    // Move forward by a certain number of steps
    string forward(int steps) // TC ----------------------->O(steps)
    {
        // While there are steps left and the future stack is not empty
        while(steps > 0 && !future.empty()) 
        {
            // Push the current page into 'past' stack to enable going back
            past.push(curr);

            // Set current page to the top of the future stack (next page)       
            curr = future.top();  

            // Remove the top element from future stack 
            future.pop(); 

            // Decrease the number of steps         
            steps--;               
        }
        // Return the current page after going forward
        return curr;               
    }
};

**********************************************APPROACH 2nd(USING DOUBLY LINKED LIST)******************************

