
class Solution {// TC--->O(N)                            SC--->O(1)
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        // Two pointers: one at the beginning and one at the end
        int left = 0;
        int right = n - 1;
        
        // to store the maximum area found so far
        int maxArea = 0; 
       
        // Move pointers towards each other until they meet
        while(left < right)
        {
            // Length of water is the minimum height of the two lines
            int length = min(height[left], height[right]);
            
            // Width is the distance between the two pointers
            int width = right - left;
            
            // Area = length * width
            int area = length * width;

            // Update maxArea if we found a bigger one
            maxArea = max(maxArea, area);

            // Move the pointer pointing to the smaller line inward
            // Why? Because the smaller line is limiting the area.
            if(height[left] < height[right]) 
            {
                left++;
            }
            else 
            {
                right--;
            }
        }
        // final maximum area
        return maxArea; 
    }
};
