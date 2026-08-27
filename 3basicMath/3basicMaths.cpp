#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main(){

//# 1)FOR COUNTING DIGIT
//     int num;
//     cin>>num;
    // int count=0;
    // while(num > 0){
    //     num = num/10;
    //     count = 1+count;
    // } //===>TIME COMPLEXEITY IS BIG O of (log10(n))
// //OR
//     //     int cnt=(int)(log10(num)+1);
//     //     return cnt;
//     //countDigit(num);
//     cout<<"ANSWER:- "<<count;

// 2) REVERSE OF NUMBER SUCH THAT IF 26300 ==> 362 and not 00362
    // int num , rev=0,lastd;
    // cout<<"Enter a integer : ";
    // cin >> num;
    // while(num>0){
    //     lastd =num%10;
    //     rev = rev*10+lastd;
    //     cout<<"hello"<<endl;
    //     num = num/10;
    // }
    // cout<<"Answer:-"<<rev<<endl;


// 3)CHECK IF PALINDROME OR NOT    
    // int num , rev=0,lastd;
    // cout<<"Enter a integer : ";
    // cin >> num;
    // int num2 =num;
    // while(num>0){
    //     lastd =num%10;
    //     rev = rev*10+lastd;
    //     num = num/10;
    // }
    // if(rev ==num2)
    // {cout<<"Answer:- palindrome"<<endl;}else{
    //     cout<<"Answer:-  Not a palindrome"<<endl;
    // }

// 4)CHECK ARMSTRONG OR NOT    
    // int num,arm =0,num2;
    // cout<<"Enter a number : "<<endl;
    // cin>>num;
    // num2=num;
    // int cnt=(int)(log10(num)+1);
    // while(num!=0){
    //     arm=pow(num%10,cnt)+arm;
    //     num/=10;
    // }
    // if(arm == num2){
    //     cout<<"Armstrong"<<endl;
    // }
    // else{
    //     cout<<"nope";
    // }

//# 5)PRINT ALL DIVISORS
    // int num;
    // cout<<"Enter a number: ";
    // cin>>num;
    // cout<<"All divisors of "<<num<<" are:"<<endl;
    // for(int i=1;i<=num;i++){
    //     if(num%i==0){
    //         cout<<i<<endl;
    //     }
    // }
    //return 0; //TIME COMPLEXEITY IS BIG O OF(n)
//OR
//     int num,n;
//     cout<<"Enter a number==> ";
//     cin>>num;
//     vector<int> ls; //VECTOR OF C++ AND LIST FOR JAVA
//     n=sqrt(num);
// //O(sqrt(n))
//     for(int i=1;i<=n;i++){
//         if(num%i ==0){
//             ls.push_back(i);
//             if(num/i != i){
//                 ls.push_back(num/i);
//             }
//         }
//     }
// //0(number of factors* log(number of factors))
//     sort(ls.begin(),ls.end());
// //O(number of factors)
//     for(auto it :ls) cout<<it<<" ,";

// 6) TO CHRECK PRIME OR NOT
    // int num , cnt=0;
    // cout<<"Enter a number";
    // cin>>num;
    // for(int i=1;i*i<=num;i++){
    //     if(num%i==0)
    //     {
    //         cnt++;
    //         if(num/i!=i){
    //             cnt++;
    //         }
    //     }
    // }
    // if(cnt==2){
    //     cout<<"Prime";
    // }
    // else{
    //     cout<<"nope";
    // }
    
// 7) FIND HCF OF 2 NUMBERS
    // for(i=1;i<=min(n1,n2);i++){
    //     if(ni%i==0&&n2%i==0)  gcd=i;
    // }

//OR THE OTHER WAY 
    //for(i=min(n1,n2),i>=1;i--)  print i;break; 

//OR EQUILIDEAN algorithm
    // GCD(N1,N2) = GCD(N1-N2 ,  N2)
    // USING THIS WE CONCLUDE THAT MODULUS METHOD
//     int n2,n1;
//     cout<<"Enter two numbers for gcd:- ";
//     cin>>n1;
//     cin>>n2;
//     while(n1>0 && n2>0){
//         if(n1>n2) {
//             n1=n1%n2;
//         }
//         else {
//             n2=n2%n1;
//         }
//     }
//     if(n1==0) {
//         cout<<n2;
//     }
//     else {
//         cout<<n1;
//     }

//     return 0;
// }