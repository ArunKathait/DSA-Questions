
class Solution {//TC ---> O(N)                       SC ---> O(N)
public:

    vector<int> getNextSmallerLeft(int n, vector<int>& arr)
    {
        vector<int> nextSmallerLeft(n);
        stack<int> indexStack;

        for(int i = 0; i < n; i++)
        {
            while(!indexStack.empty() && arr[indexStack.top()] >= arr[i])
            {
                indexStack.pop();
            }

            nextSmallerLeft[i] = indexStack.empty() ? -1 : indexStack.top();
            indexStack.push(i);
        }

        return nextSmallerLeft;
    }

    vector<int> getNextSmallerRight(int n, vector<int>& arr)
    {
        vector<int> nextSmallerRight(n);
        stack<int> indexStack;

        for(int i = n - 1; i >= 0; i--)
        {
            while(!indexStack.empty() && arr[indexStack.top()] > arr[i])
            {
                indexStack.pop();
            }

            nextSmallerRight[i] = indexStack.empty() ? n : indexStack.top();
            indexStack.push(i);
        }

        return nextSmallerRight;
    }

    int sumSubMins(vector<int>& arr)
    {
        int n = arr.size();

        vector<int> nextSmallerLeft = getNextSmallerLeft(n, arr);
        vector<int> nextSmallerRight = getNextSmallerRight(n, arr);

        long long totalSum = 0;

        for(int i = 0; i < n; i++)
        {
            long long elementsOnLeft = i - nextSmallerLeft[i];
            long long elementsOnRight = nextSmallerRight[i] - i;

            totalSum += elementsOnLeft * elementsOnRight * arr[i];
        }

        return totalSum;
    }
};
