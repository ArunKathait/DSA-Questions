************************************************APPROACH 1st(USING VECTOR)********************************************

#include <bits/stdc++.h>
using namespace std;

// Time: get = O(n), put = O(n)                     Space: O(n) (where n = capacity)
class LRUCache {
public:
    // cache storage (each element = {key, value})
    vector<pair<int,int>> vec; 

    // maximum capacity of the cache
    int size;  

    // Constructor: initialize cache with given capacity
    LRUCache(int capacity) 
    {
        size = capacity;
    }
    
    // Get the value of a key if it exists, else return -1
    int get(int key) {
        // Iterate over the cache to find the key
        for (int i = 0; i < vec.size(); i++) 
        {
            if (vec[i].first == key) 
            { 
                // if key is found
                int val = vec[i].second;

                // Since this key was just used, move it to the back
                // (mark as most recently used)
                vec.erase(vec.begin() + i);
                vec.push_back({key, val});
                
                // return the value
                return val; 
            }
        }
        // key not found
        return -1;
    }
    
    // Put a key-value pair into the cache
    void put(int key, int value) {
        // If key already exists, update its value and move it to back
        for (int i = 0; i < vec.size(); i++) 
        {
            if (vec[i].first == key) 
            {
                // remove old {key, value}
                vec.erase(vec.begin() + i);

                // add updated {key, value} at back           
                vec.push_back({key, value});          
                return;
            }
        }

        // If cache is full, remove the least recently used (front element)
        if (vec.size() == size) 
        {
            // remove LRU (front element)
            vec.erase(vec.begin());                  
        }

        // Insert the new {key, value} as the most recently used (back of vector)
        vec.push_back({key, value});
    }
};

/**
 * Example of usage:
 *
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



