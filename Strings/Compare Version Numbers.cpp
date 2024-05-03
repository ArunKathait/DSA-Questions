**********************************************APPROACH 1st*****************************************************

class Solution {// TC--->O(max(n + m))            SC--->O(n + m)
public:
    // Function to split a string by a given delimiter and return a vector of integers
    vector<int>splitString(string &s,char delimeter)
    {
        // Initialize an empty vector to store the integers
        vector<int>ans;
        
        // Initialize the start index for searching
        int start = 0;
        
        // Find the first occurrence of the delimiter
        int end = s.find(delimeter,start);
        
        // Loop until the delimiter is found
        while(end != string::npos)
        {
            // Extract the substring between start and end indices
            string temp = s.substr(start,end-start);
                 
            // Convert the substring to an integer and push it to the vector

            ans.push_back(stoi(temp));
            
            // Update the start index for the next iteration
            start = end+1;
            
            // Find the next occurrence of the delimiter
            end = s.find(delimeter,start);
        }
        
        // After the loop, extract the last substring (or the remaining string)
        string temp = s.substr(start,end-start);
        
        // Convert the last substring to an integer and push it to the vector
        ans.push_back(stoi(temp));
        
        // Return the vector containing the split integers
        return ans;
    }

        int compareVersion(string version1, string version2) {
            
        // Split the version strings into vectors of integers using '.' as the delimiter
        vector<int>v1=splitString(version1,'.');
        vector<int>v2=splitString(version2,'.');
        
        // Loop through the maximum length of both vectors
        for(int i=0;i<max(version1.length(),version2.length());i++)
        {
            // Get the value at index i from both vectors
            int val1 = i < v1.size() ? v1[i] : 0;
            int val2 = i < v2.size() ? v2[i] : 0;
            
            // Compare the values
            if(val1 < val2)
            {
                return -1;
            }
            else if(val1 > val2)
            {
                return 1;
            }
        }
            
            // If no differences were found, return 0 (versions are equal)
            return 0;
    }
};


*********************************************APPROACH 2nd****************************************************

class Solution {// TC--->O(max(N + M))             SC--->O(1)
public:
    int compareVersion(string version1, string version2) {
        // Variable to store the integer value extracted from version1
        int num1;
        
         // Variable to store the integer value extracted from version2
        int num2;
        
        // Index for version1
        int i=0;
        
        // Index for version2
        int j=0;
        
        // Loop until either version1 or version2 is fully processed
        while(i<version1.length() || j<version2.length())
        {
             // Reset num1 for each iteration
            num1=0;
            
            // Reset num2 for each iteration
            num2=0;
            
            // Extract the integer value from version1 until a '.' is encountered
            while(i<version1.length() && version1[i] != '.')
            {
                // Convert character to integer and accumulate
                num1 = num1*10 + (version1[i] - '0');
                
                // Move to the next character
                i++;
            }
            
             // Extract the integer value from version2 until a '.' is encountered
            while(j<version2.length() && version2[j] != '.')
            {
                // Convert character to integer and accumulate
                num2 = num2*10 + (version2[j] - '0');
                
                // Move to the next character
                j++;
            }
            
            // Compare the extracted integer values
            if(num1>num2)
            {
                // version1 is greater than version2
                return 1;
            }
            if(num1<num2) 
            {
                // version1 is less than version2
                return -1;
            }
            
            // If the extracted integer values are equal, move to the next segment
            // Move to the next character after the '.'
            i++;
            
             // Move to the next character after the '.'
            j++;
        }
        
        // If all segments are equal, return 0
        return 0;
    }
};
