
#include<iostream>
using namespace std;

int partition(int a[],int low,int high)
{
    int pivot = a[low];
    int i = low;
    int j = high;
    
    while(i < j)
    {
        
        while(i < high && a[i] <= pivot)
        {
            i++;
        }
        
        while(j >= low + 1 && a[j] > pivot)
        {
            j--;
        }
        
        if(i < j)
        {
            swap(a[i],a[j]);
        }
    }
    
    swap(a[low],a[j]);
    return j;
}

void quicksort(int a[],int low,int high)
{
    if(low < high)
    {
        int partitionIndex = partition(a,low,high);
        quicksort(a,low,partitionIndex - 1);
        quicksort(a,partitionIndex + 1,high);
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    quicksort(a,0,n-1);
    
    for(auto x:a)
    {
        cout<<x<<" ";
    }
}
