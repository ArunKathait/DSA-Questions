*****************************************************APPROACH 1st(USING LIST)****************************************

class MyCircularDeque {// TC--->O(1)                  SC--->O(k)
public:
    // Declaring a list to act as the circular deque
    list<int>l;
    
    // Variable to store the capacity of the deque
    int capacity;
    
    // Constructor to initialize the deque with maximum size 'k'
    MyCircularDeque(int k) {
        // Setting the capacity of the deque
        capacity = k;
    }
    
    // Inserts 'value' at the front of the deque
    bool insertFront(int value) {
        // If the deque is already full, insertion is not possible
        if(l.size() >= capacity)
        {
            // Deque is full
            return false;
        }
        
        // Insert the value at the front of the deque
        l.push_front(value);
        
        // Insertion successful
        return true;
    }
    
    // Inserts 'value' at the end of the deque
    bool insertLast(int value) {
        // If the deque is already full, insertion is not possible
        if(l.size() >= capacity)
        {
            // Deque is full
            return false;
        }
        
        // Insert the value at the end of the deque
        l.push_back(value);
        
        // Insertion successful
        return true;
    }
    
    // Deletes the element at the front of the deque
    bool deleteFront() {
        // If the deque is empty, deletion is not possible
        if(l.empty())
        {
            // Deque is empty, cannot delete
            return false;
        }
        else
        {
            // Remove the front element from the deque
            l.pop_front();
            
            // Deletion successful
            return true;
        }
    }
    
    // Deletes the element at the end of the deque
    bool deleteLast() {
        // If the deque is empty, deletion is not possible
        if(l.empty())
        {
            // Deque is empty, cannot delete
            return false;
        }
        else
        {
            // Remove the last element from the deque
            l.pop_back();
            
            // Deletion successful
            return true;
        }
    }
    
    // Gets the front element of the deque
    int getFront() {
        // If the deque is empty, return -1 as there is no front element
        if(l.empty())
        {
            // Deque is empty
            return -1;
        }
        else
        {
            // Return the front element
            return l.front();
        }
    }
    
    // Gets the last element of the deque
    int getRear() {
        // If the deque is empty, return -1 as there is no rear element
        if(l.empty())
        {
            // Deque is empty
            return -1;
        }
        else
        {
            // Return the rear element
            return l.back();
        }
    }
    
    // Checks whether the deque is empty
    bool isEmpty() {
        // Return true if the deque has no elements
        return l.empty();
    }
    
    // Checks whether the deque is full
    bool isFull() {
        // Return true if the deque's size is equal to its capacity
        return l.size() == capacity;
    }
};



*************************************************************APPROACH 2nd(USING ARRAY)******************************

class MyCircularDeque {// TC--->O(1)                      SC--->O(K)
public:
    // Vector to store the elements of the deque
    vector<int>deque;
    
    // Maximum capacity of the deque
    int K;
    
    // Index of the front element in the deque
    int front;
    
    // Index of the rear element in the deque
    int rear;
    
    // Number of elements currently in the deque
    int currentCount;
    
    // Constructor to initialize the deque with a capacity of 'k'
    MyCircularDeque(int k) {
        // Set the maximum capacity
        K = k;
        
        // Initialize deque as a fixed-size vector of size K, with all elements as 0
        deque = vector<int>(K,0);
        
        // Initialize front pointer to 0 (start of the deque)
        front = 0;
        
        // Initialize rear pointer to K-1 (end of the deque)
        rear = k-1;
        
        // No elements in the deque initially
        currentCount = 0;
    }
    
    // Inserts 'value' at the front of the deque
    bool insertFront(int value) {
        if(isFull())
        {
            // Cannot insert if the deque is full
            return false;
        }
        
        // Decrease front pointer in a circular manner
        front = (front - 1 + K)%K;
        
        // Insert the value at the front
        deque[front] = value;
        
        // Increment the number of elements in the deque
        currentCount++;
        
        // Return true to indicate successful insertion
        return true;
    }
    
    // Inserts 'value' at the rear of the deque
    bool insertLast(int value) {
        if(isFull())
        {
            // Cannot insert if the deque is full
            return false;
        }
        
        // Increase rear pointer in a circular manner
        rear = (rear + 1)%K;
        
        // Insert the value at the rear
        deque[rear] = value;
        
        // Increment the number of elements in the deque
        currentCount++;
        
        // Return true to indicate successful insertion
        return true;
    }
    
    // Deletes an element from the front of the deque
    bool deleteFront() {
        if(isEmpty())
        {
            // Cannot delete if the deque is empty
            return false;
        }
        // Move the front pointer forward in a circular manner
        front = (front + 1)%K;
        
        // Decrease the number of elements in the deque
        currentCount--;
        
         // Return true to indicate successful deletion
        return true;
    }
    
    // Deletes an element from the rear of the deque
    bool deleteLast() {
        if(isEmpty())
        {
            // Cannot delete if the deque is empty
            return false;
        }
        
        // Move the rear pointer backward in a circular manner
        rear = (rear - 1 + K)%K;
        
        // Decrease the number of elements in the deque
        currentCount--;
        
        // Return true to indicate successful deletion
        return true;
    }
    
    // Gets the element at the front of the deque
    int getFront() {
        if(isEmpty())
        {
            // If the deque is empty, return -1
            return -1;
        }
        
        // Return the front element
        return deque[front];
    }
    
    // Gets the element at the rear of the deque
    int getRear() {
        if(isEmpty())
        {
            // If the deque is empty, return -1
            return -1;
        }
        // Return the rear element
        return deque[rear];
    }
    
    // Checks if the deque is empty
    bool isEmpty() {
        // The deque is empty if currentCount is 0
        return currentCount == 0;
    }
    
    // Checks if the deque is full
    bool isFull() {
         // The deque is full if currentCount equals the maximum capacity (K)
        return currentCount == K;
    }
};

