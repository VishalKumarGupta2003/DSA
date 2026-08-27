#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr,int low,int high)
{
    int pivot=low,i=low,j=high;
    while(i<j){
        while(i<=high && arr[i]<=arr[pivot]){
            i++;
        }
        while (j>=low && arr[j]>arr[pivot])
        {
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[pivot],arr[j]);
    return j;
}
void quickSort(vector<int> &arr,int low,int high)
{
    if(low<high)
    {
        int index = partition(arr,low,high);
        quickSort(arr,low,index-1);
        quickSort(arr,index+1,high);
    }
    return ;
}
int main()
{
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        arr[i]=num;
    }
    cout<<"Original Array :- ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quickSort(arr,0,n-1);
    cout<<"Sorted Array :- ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}