
class RandomizedSet {
public:

    // Vector stores all the values present in the set.
    //
    // Example:
    // nums = [10, 20, 30]
    //
    // Index:
    //        0   1   2
    //
    // We use vector because nums[index] gives O(1) access.
    vector<int> nums;


    // HashMap stores:
    //
    // value -> index in nums
    //
    // Example:
    //
    // nums = [10, 20, 30]
    //
    // ump:
    // 10 -> 0
    // 20 -> 1
    // 30 -> 2
    //
    // This helps us find the position of any value in O(1)
    // average time.
    unordered_map<int, int> ump;


    // Constructor
    RandomizedSet() {

        // Nothing needs to be initialized explicitly.
        // vector and unordered_map are empty automatically.
    }


    // Insert a value into the set.
    //
    // Returns:
    // true  -> insertion was successful
    // false -> value already exists
    bool insert(int val) {// O(1) average

        // Check whether val already exists in the hashmap.
        //
        // If found, val is already present.
        if(ump.find(val) != ump.end()) {
            return false;
        }


        // Add val at the end of the vector.
        nums.push_back(val);


        // Get the index of the newly inserted element.
        //
        // Vector is 0-indexed.
        //
        // Example:
        // nums = [10, 20, 30]
        //
        // After inserting 40:
        // nums = [10, 20, 30, 40]
        //
        // index of 40 = 3
        int index = nums.size() - 1;


        // Store the value and its index in the hashmap.
        //
        // ump[40] = 3
        ump[val] = index;

        return true;
    }


    // Remove a value from the set.
    //
    // Returns:
    // true  -> removal was successful
    // false -> value doesn't exist
    bool remove(int val) {// O(1) average

        // Check whether val exists.
        //
        // If it doesn't exist, we cannot remove it.
        if(ump.find(val) == ump.end()) {
            return false;
        }


        // Get the index of val from the hashmap.
        //
        // Example:
        //
        // nums = [10, 20, 30, 40]
        // ump[20] = 1
        //
        // index = 1
        int index = ump[val];


        // Get the last element of the vector.
        //
        // Example:
        // nums = [10, 20, 30, 40]
        // lastElement = 40
        int lastElement = nums.back();


        // Move the last element to the position of val.
        //
        // Before:
        //
        // nums = [10, 20, 30, 40]
        //             ↑        ↑
        //            val      last
        //
        // After:
        //
        // nums = [10, 40, 30, 40]
        //
        // We do this instead of shifting elements,
        // so removal remains O(1).
        nums[index] = lastElement;


        // Remove the duplicate last element.
        //
        // nums = [10, 40, 30]
        nums.pop_back();


        // Update the hashmap because lastElement
        // has moved to 'index'.
        //
        // Example:
        //
        // 40 was at index 3.
        // Now 40 is at index 1.
        //
        // Therefore:
        // ump[40] = 1
        ump[lastElement] = index;


        // Finally remove val from the hashmap.
        ump.erase(val);

        return true;
    }


    // Returns a random element from the set.
    int getRandom() {// O(1) 

        // Number of elements currently in nums.
        int n = nums.size();


        // Generate a random index between:
        //
        // 0 and n-1
        //
        // rand() % n gives an index in this range.
        int randomIndex = rand() % n;


        // Return the element at that random index.
        //
        // Vector provides O(1) random access.
        return nums[randomIndex];
    }
};

/*  

┌───────────────────────────────────────────┐
│             RANDOMIZED SET                │
├───────────────────────────────────────────┤
│ Data structures:                          │
│                                           │
│ vector  → value storage                   │
│ hashmap → value → index                   │
│                                           │
│ INSERT:                                   │
│ push_back() + store index                 │
│                                           │
│ REMOVE:                                   │
│ find index                                │
│       ↓                                   │
│ replace with last element                 │
│       ↓                                   │
│ pop_back()                                │
│       ↓                                   │
│ update hashmap                            │
│                                           │
│ GET RANDOM:                               │
│ random index → nums[index]                │
│                                           │
│ Time:                                     │
│ insert   = O(1) average                   │
│ remove   = O(1) average                   │
│ random   = O(1)                           │
│                                           │
│ Space = O(N)                              │
│                                           │
│ KEYWORD:                                  │
│ "Swap with last element"                  │
└───────────────────────────────────────────┘

*/
