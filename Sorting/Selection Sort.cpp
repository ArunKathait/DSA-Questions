#include<iostream>
using namespace std;
void selectionsort(int a[],int n)
{
   for(int i=0;i<n;i++)
   {
       int mini = i;
       
       for(int j=i+1;j<n;j++)
       {
           if(a[j] < a[mini])
           {
               mini=j;
           }
       }
       int temp= a[i];
       a[i]=a[mini];
       a[mini]=temp;
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
    
    selectionsort(a,n);
    
    for(auto x:a)
    {
        cout<<x<<" ";
    }
}
