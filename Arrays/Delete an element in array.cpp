
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    int val;
    cout<<"Enter the value you want to delete:\n";
    cin>>val;
    
    int index = -1;
    for(int i=0;i<n;i++)
    {
        if(a[i] == val)
        {
            index = i;
            break;
        }
    }
    
    if(index == -1)
    {
        cout<<"Please enter correct value\n";
    }
    else
    {
        for(int i=index;i<n-1;i++)
        {
            a[i] = a[i+1];
        }
        n--;
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
