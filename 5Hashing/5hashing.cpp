#include <bits/stdc++.h>
using namespace std;

// 1) HASHING A SIMPLE ARRAY
// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for (int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int hash[n+1]={0};
//     for(int i=0;i<n;i++){
//         hash[arr[i]]+=1;
//     }
//     int q;
//     cin>>q;
//     while(q>0){
//         int num;
//         cin>>num;
//         cout<<hash[num]<<<<endl;
//         q--;
//     }
//     return 0;
// }

// 2) HASHING A STRING ASSUMING STRING IS ALL ALPHABET AND IN LOWERCASE OTHERWISE
// int main()
// {
//     string s;
//     cin>>s;
//     int size=s.size();
//     int hash[26]={0}; //HASH[256]==> IF WE HAD TO COUNT EVERY CHARACTER INCLUDING SYMBOLS
//     for(int i=0;i<size;i++){
//         hash[s[i]-'a'] +=1;    //HASH[S[I]];
//     }
//     int q;
//     cin>>q;
//     while(q>0){
//         char ch;
//         cin>>ch;
//         cout<<hash[ch-'a']<<endl;
//         q--;
//     }
//     return 0;
// }

// 3)HASHING USING MAPPING
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    //  // ==>mpp[arr[i]]+=1; SAVES TIME  IF MAP IS INITIALISED EARLY
    // }
    // map<int,int> mpp;
    // for(int i=0;i<n;i++){
    //     mpp[arr[i]]+=1;
    // }
//     int q;
//     cin>>q;
//     while(q>0){
//         int num;
//         cin>>num;
//         cout<<mpp[num]<<",,"<<endl;
//         q--;
//     }
//     return 0;
// }
// 4) HASHING AND PRINTING LOWEST AND HIGHEST COUNT
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     map<int,int> mpp;
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//         mpp[arr[i]]+=1;
//     }
//     pair<int,int> low={-1,n};
//     pair<int,int> high={-1,0};

//     for(auto &it: mpp){
//         if(it.second<=low.second) {
//             low.first=it.first;
//             low.second=it.second;
//         }
//         if(it.second>=high.second){
//              high.first=it.first;
//              high.second=it.second;
//         }
//     }
//     cout<<"The element with lowest count is:-"<<low.first<<"->"<<low.second<<endl;;
//     cout<<"The element with highest count is:-"<<high.first<<"->"<<high.second;
// }