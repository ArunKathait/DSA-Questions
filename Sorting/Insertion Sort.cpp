
#include<iostream>
using namespace std;
void insertionsort(int a[],int n)
{
   for(int i=0;i<n;i++)
   {
       int j = i;
       while(j > 0 && a[j-1] > a[j])
       {
           int temp = a[j-1];
           a[j-1] = a[j];
           a[j] = temp;
           j--;
       }
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
    
    insertionsort(a,n);
    
    for(auto x:a)
    {
        cout<<x<<" ";
    }
}
