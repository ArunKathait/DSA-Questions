
  class Solution{
	public:
	vector<int> findMissing(int a[], int b[], int n, int m) 
	{ 
	    // Create a vector to store the missing elements
	    vector<int>ans;
	    
	    // Create an unordered_set 'set' containing all elements of array 'b'
        // This allows fast O(1) lookups to check if an element from 'a' is in 'b'
	    unordered_set<int>set(b,b+m);
	    
	    // Iterate through each element of array 'a'
	    for(int i=0;i<n;i++)
	    {
	        // If the current element of 'a' is not found in 'b'
	        if(set.find(a[i]) == set.end())
	        {
	            // Add the current element of 'a' to the 'ans' vector
	            ans.push_back(a[i]);
	        }
	    }
	    
	    // Return the vector containing the missing elements
	    return ans;
	} 
};
