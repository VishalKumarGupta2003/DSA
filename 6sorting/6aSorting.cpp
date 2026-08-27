// #include <bits/stdc++.h>
// using namespace std;

// void selection(int arr[],int n){
//     for(int i=0;i<n-1;i++){
//         int min=i;
//         for(int j=i;j<n;j++){
//             if(arr[j]<arr[min]) min=j;
//         }
//         int temp =arr[min];
//         arr[min]=arr[i];
//         arr[i]= temp;
        // cout<<"Step "<<i+1<<":-";
        // for(int i=0;i<n;i++){
        // cout<<arr[i]<<" ";
        // }
        // cout<<endl;
//     }
// }

// void bubble(int arr[],int n){
//     for(int i=0;i<n-1;i++){
//         int didSwap=0;
//         for(int j=0;j<n-i-1;j++){
//             if(arr[j]>arr[j+1]){
//                 int temp=arr[j];
//                 arr[j]=arr[j+1];
//                 arr[j+1]=temp;
//                 didSwap=1;
//             }
//         }
//         if(didSwap==0) break;
//         cout<<"Step "<<i+1<<":-";
//         for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//         }
//         cout<<endl;
//     }
//     return ;
// }

// void insertion(int arr[],int n){
//     for(int i=1;i<n;i++){
//         // for(int j=i;j>0;j--){
//         //     if(arr[j]<arr[j-1]){
//         //         swap(arr[j],arr[j-1]);
//         //     }
//         // }
//         //BETTER APPROACH IS:-
//         while(j>0 && arr[j-1]>arr[j]){
//             swap(arr[j],arr[j-1]);
//         }
//         cout<<"step "<<i+1<<":-";
//         for(int i=0;i<n;i++){
//             cout<<arr[i]<< " ";
//         }
//         cout<<endl;
//     }
// }
// int main()
// {
//     int n;cin>>n;
//     int arr[n];
//     cout<<"defs"<<endl;
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     //SELECTION SORTING==> HERE WE PLACE MINIMMUM AT FIRST
//     // selection(arr,n);

//     //BUBBLE SORTING BY PUSHING MAXIMUM AT LAST BY SWAPPING ADJACENT
//     //bubble(arr,n);

//     //INSERTION ==> TAKES AN ELEMENT AND PLACES IT IN IT'S CORRECT POSITION
//     insertion(arr,n);

//     return 0;
// }


