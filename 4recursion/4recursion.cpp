#include<bits/stdc++.h>
#include<iostream>

using namespace std;

// 1)PRINT NAME N TIMES USING RECURSION
// void printName1(int i,int n,string str){
//     if(i>n){
//         return;
//     }
//     else{
//         cout<<str<<endl;
//         i++;
//         printName1(i,n,str);
//     }
// }
// int main(){
//     string str;
//     int i=1,n;
//     cout<<"Enter how many times you want to print your name:- ";
//     cin>>n;
//     cout<<"Enter the name:- ";
//     getline(cin>>ws,str);
//     printName1(i,n,str);
//     return 0;
// }

// 2) PRINT LINEARLY FROM 1 TO N 
// void printLinearly2(int i,int n){
//     if(i>n) return;
//     else { 
//         cout<<i<<endl;
//         printLinearly2(i+1,n);
//     }
// }
// int main(){
//     int i=1,n;
//     cout<<"Enter:- ";
//     cin>>n;
//     printLinearly2(i,n);
//     return 0;
// }

// 3) print in reverse order
// void printRerverse3(int i){
//     if(i<1) return;
//     else {
//         cout<<i<<" ";
//         printRerverse3(i-1);
//     }
// }
// int main(){
//     int i;
//     cout<<"Enter : ";
//     cin>>i;
//     if(i<1){
//         cout<<"Enter valid ";
//         return 0;
//     }
//     else{
//         printRerverse3(i);
//     }
//     return 0;
// }

// 4) PRINT LINEARLY FROM 1 TO N BY BACKTRACKING
  //BACKTRAcking mein print line , recursion call ke baad hota h
// void printByBacktracking4(int n){
//     if(n<1) return;
//     printByBacktracking4(n-1);
//     cout<<n<<endl;
// }
// int main(){
//     int n;
//     cout<<"Enter:---";
//     cin>>n;
//     printByBacktracking4(n);
//     return 0;
// }

// 5)Parameterized SUM OF N NUMBERS
// void print(int n,int sum){
//   if(n<1){
//     cout<<sum;
//     return;
//   }
//   else print(n-1,sum+n);
// }
// int main(){
//   int n,sum=0;
//   cin>>n;
//   print(n,sum);
//   return 0;
// }


// 6)FUNCTIONAL RECURSION FOR SUM OF N NUMBERS
// int sum(int n){
//   if(n==0) return 0;
//   else return n+sum(n-1);
// }
// int main(){
//   int n;
//   cin>>n;
//   cout<<"Sum is: "<<sum(n);
//   return 0;
// }
 
// 7)Factorial
// int fact(int n){
//   if(n==1) return 1;
//   else return n*fact(n-1);
// }
// int main(){
//   int n;
//   cin>>n;
//   cout<<"Factorial is:- "<<fact(n);
//   return 0;
// }

//# 8) REverse an Array
// void rev(int i,int arr[],int n){
//   if(i==n/2) return;
//   else {
//     swap(arr[i],arr[n-i-1]);
//     rev(i+1,arr,n);
//   }
// }
// int main(){
//   int n;
//   cin>>n;
//   int arr[n];
//   for(int i=0;i<n;i++) cin>>arr[i];
//   rev(0,arr,n);
//   for(int i=0;i<n;i++){
//     cout<<arr[i]<<" ";
//   }
// }

// 9) PALINDROME STRING OR NOT
// bool peli(string &str,int i){
//   if(i>=(str.size())/2) return true;
//   if (str[i]!=str[(str.size())-1-i]) return false;
//   else return peli(str,i+1);
// }
// int main(){
//   string str;
//   cin>>str;
//   cout<<"Answer is : "<<peli(str,0);
//   return 0;
// }

// 10)FIBONACCI
// int fib(int n){
//   if(n<=1) return n;
//   else{
//     return fib(n-1)+fib(n-2);
//   }
// }
// int main(){
//   int n;
//   cin>>n;
//   cout<<"bvchj"<<fib(n);
// }

//# 11)SUBSEQUENCES==> WHERE SEQUENCES OF SUBSET OF ARRAY MAINTAINS THE ORDER OF ELEMENTS OF ARRAYS(THE ORDER IS ACCORDING TO ARRAY )
// void print(int i,vector<int> &ds, int arr[],int n){
//   if(i>=n){
//     for(auto it:ds){
//       cout<<it<<" ";
//     }
//     if(ds.size()==0){
//       cout<<"{}";
//     }
//     cout<<endl;
//     return ;
//   }
//   else{
//     print(i+1,ds,arr,n);
//     ds.push_back(arr[i]);
//     print(i+1,ds,arr,n);
//     ds.pop_back();
//   }
// }
// int main(){
//  int n;
//  cin>>n;
//  int arr[n];
//  for(int i=0;i<n;i++){
//     cin>>arr[i];
//  }
//  vector<int> ds;
//  print(0,ds,arr,n);
// }

// 12) SUBSEQUENCE SUM
// void print(int i,vector<int> &ds, int arr[],int n,int sum,int s){
//   if(i>=n){
//     if(sum==s){
//       for(auto it:ds){
//       cout<<it<<" ";
//     }
//     if(ds.size()==0){
//       cout<<"{ ,}";
//     }
//     cout<<endl;
//     }
//     return;
//   }
//   else{
//     ds.push_back(arr[i]);
//     s+=arr[i];
//     print(i+1,ds,arr,n,sum,s);
//     s-=arr[i];
//     ds.pop_back();
//     print(i+1,ds,arr,n,sum,s);
//   }
// }
// int main(){
//  int n,sum=2,s=0;
//  cin>>n;
//  int arr[n];
//  for(int i=0;i<n;i++){
//     cin>>arr[i];
//  }
//  vector<int> ds;
//  print(0,ds,arr,n,sum,0);
// }

// 13) ONLY ONE SEBSEQUENCE SUM
// bool print(int i,vector<int> &ds, int arr[],int n,int sum,int s){
//   if(i>=n){
//     if(sum==s){
//       for(auto it:ds){
//       cout<<it<<" ";
//     }
//     return true;
//   }
//     return false;
//   }
//   else{
//     ds.push_back(arr[i]);
//     s+=arr[i];
//     if(print(i+1,ds,arr,n,sum,s)== true) return true;
//     s-=arr[i];
//     ds.pop_back();
//     if (print(i+1,ds,arr,n,sum,s)== true) return true;
//     return false;
//   }
// }
// int main(){
//  int n,sum=2,s=0;
//  cin>>n;
//  int arr[n];
//  for(int i=0;i<n;i++){
//     cin>>arr[i];
//  }
//  vector<int> ds;
//  print(0,ds,arr,n,sum,0);
// }

//# 14) COUNT THE NUMBER OF SUBSEQUENCES WHICH HAS SUM = REQ. SUM
    // BASE case
    //  IF TRUE RETURN 1
    //  ELSE RETURN FALSE
    // L = F();
    // R= F();
    // RETURN L+R; 
// int print(int arr[],int n,int id,int s,int sum){
//   if(id==n){
//     if(s==sum){
//       return 1;
//     }
//     else return 0;
//   }
//   s+=arr[id];
//   int l=print(arr,n,id+1,s,sum);
//   s-=arr[id];
//   int r=print(arr,n,id+1,s,sum);
//   return l+r;
// }
// int main(){
//   int n,s=0,sum=4;
//   cin>>n;
//   int arr[n];
//   for(int i=0;i<n;i++){
//     cin>>arr[i];
//   }
//   cout<<print(arr,n,0,s,sum);
//   return 0;
// }



