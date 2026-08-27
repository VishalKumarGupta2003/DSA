#include<iostream>

using namespace std;

//CPPBasic

// int main(){
//     std::cout<<"I am Vishal";
//     std::cout<<"I am Vishal"<<"\n";
//     std::cout<<"I am Vishal Gupta"<<std::endl;
//     std::cout<<"I am Vishal"<<std::endl<<"Myself Vishal";
//     std::cout<<"I am Vishal1";
// }

// int main(){
//     cout<<"I am Vishal";
//     cout<<"I am Vishal"<<"\n";
//     cout<<"I am Vishal Gupta"<<endl;
//     cout<<"I am Vishal"<<endl<<"Myself Vishal";
//     cout<<"I am Vishal1";ṇ
// }

// int main(){
//      int x,y;
//      cin >> x >>y;
//      cout << "x:" << x <<" "<< "y:" <<y;
//      return 0;
//  }

  
// int main(){
    // int x=10;
    // float y=12.3;
    // cout << "x:efr" <<x <<"y:" <<y;

    // string s1;
    // cin>>s1;
    // cout <<s1;

    // string s1;
    // string s2;
    // cin>>s1>>s2;
    // cout<<s1 <<" + "<<s2;

    // string str;
    // getline(cin,str);
    // cout<<str<<"+";

 //WRITE A PRGM TAKING AGE AND SAY IF ADULT OR NOT   
    // int age;
    // cin>>age;
    // if(age>=18){
    //     cout<<"Adult";
    // }
    // else{
    //     cout<<"Minor";
    // }

    //FOR LOOPS
    // int i;
    // for(i=1;i<=5;i++){
    //     cout << "Hello " << i <<endl;
    // }
    
    //WHILE LOOPS
    // int i=1;
    // while(i<5){
    //     cout << "Hell " << i <<endl;
    //     i++;
    // }
     
    //DO WHILE LOOPS
    // int i=6;
    // do{
    //     cout << "Helloo " << i <<endl;
    // }while (i<5);
//     return 0;
// }






//DATA TYPE
// #include<iostream>

// using namespace std;

// int main(){
//     int x=10;
//     float y=12.3;
//     cout << "x:efr" <<x <<"y:" <<y;

//     string s1;
//     cin>>s1;
//     cout <<s1;

//     string s1;
//     string s2;
//     cin>>s1>>s2;
//     cout<<s1 <<" + "<<s2;

//     string str;
//     getline(cin,str);
//     cout<<str;

//  //WRITE A PRGM TAKING AGE AND SAY IF ADULT OR NOT   
//     int age;
//     cin>>age;
//     if(age>=18){
//         cout<<"Adult";
//     }
//     else{
//         cout<<"Minor";
//     }

//     //FOR LOOPS
//     int i;
//     for(i=1;i<=5;i++){
//         cout << "Hello " << i <<endl;
//     }
    
//     //WHILE LOOPS
//     int i=1;
//     while(i<5){
//         cout << "Hell " << i <<endl;
//         i++;
//     }
     
//     //DO WHILE LOOPS
//     int i=6;
//     do{
//         cout << "Helloo " << i <<endl;
//     }while (i<5);
//     return 0;
// }









//CPPFunctions


// VOID -->WHICH DOES NOT RETURNS ANYTHING
// return
// PARAMETERISED
// NON-PARAMETERISED

// void printName(string name){
//     cout <<"Hello " <<name;
// }
// int main(){
//     string name;
//     cin >> name;
//     printName(name);
//     return 0;
// }

//PASS  BY VALUE ==> COPY OF THE VALUE GOES AND NOT THE ORIGINAL
// void doSomething(int num){
//     cout << num<<endl;
//     num+=5;
//     cout << num<<endl;
//     num+=5;
//     cout << num<<endl;
// }
// int main(){
//     int num;\
//     cin>>num;
//     doSomething(num);
//     cout << num<<endl;//    WILL PRINT THE NUMBER GIVEN BY USER AND NOT THE UPDATED ONE.
// }

//PASS BY REFERENCE
// void doSomething(string &str){  // &Variable_Name ==> passes reference
//     str[0] = 't';
//     cout << str<<endl;
// }
// int main(){
//     string originalStr ="Raj";
//     cout<<originalStr<<endl;
//     doSomething(originalStr);
//     cout<<originalStr<<endl;
//     return 0;
// }

// ARRAY IS ALWAYS PASSED BY REFERENCE
// void  doSomething (int arr[],int n){
//     arr[0]+=100;
//     cout <<"Inside function "<<arr[0]<<endl;
// }
// int main(){
//     int n=5;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     cout <<"Inside main function BEFORE calling doSomething function"<<arr[0]<<endl;
//     doSomething(arr,n);
//     cout <<"Inside main function "<<arr[0];

// }




//PATTERNS


//RECTANGULAR PATTERN
// void print(int n){
//     for(int i = 0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }

//RIGHT TRIANGLE
// void print(int n){
//     for(int i = 1;i<=n;i++){
//         for(int j=1;j<=i;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }

//RIGHT TRIANGLE WITH NUMBERS
// 1
// 12
// 123
//  void print(int n){
//     for(int i = 1;i<=n;i++){
//         for(int j=1;j<=i;j++){
//             cout<<j;
//         }
//         cout<<endl;
//     }
// }

//PRINT RIGHT TRIANGLE WITH ROW NUMBERS
//1
//22
// void print(int n){
//     for(int i = 1;i<=n;i++){
//         for(int j=1;j<=i;j++){
//             cout<<i;
//         }
//         cout<<endl;
//     }
// }

//REVERSE RIGHT TRIANGLE OF STARS
// ***
// **
// *
// void print(int n){
    // for(int i =0;i<=n;i++){
    //     for(int j=0;j<=n-i-1;j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
 //OR
    // for(int i = n;i>=1;i--){
    //     for(int j=i;j>=1;j--){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
//}

//REVERSE RIGHT TRIANGLE WITH NUMBERS
//123
//12
//1
// void print(int n){
//     for(int i=0;i<n;i++){
//         for(int j=1;j<=n-i;j++){
//             cout<<j;
//         }
//         cout<<endl;
//     }
// }

//#PYRAMID OF STARS
//   *
//  ***
// *****   
// void print(int n){
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n-i;j++){
//             cout<<" ";
//         }
//#         for(int j=1;j<=2*i-1;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }

// REVERSE OF PYRAMIDS OF STARS
// void print(int n){
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<i;j++){
//             cout<<" ";
//         }
//         for(int j=1;j<=2*n-(2*i+1);j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }

//PYRAMIDS OF STARS AND THEN MIRROR IT DOWN 
//   *
//  ***
// *****
// *****
//  ***
//   *
// void print(int n){
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n-i;j++){
//             cout<<" ";
//         }
//         for(int j=1;j<=2*i-1;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     //COPY OF PREVIOUS REVERSE OF PYRAMID
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<i;j++){
//             cout<<" ";
//         }
//         for(int j=1;j<=2*n-(2*i+1);j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }

//ROTATED PYRAAMID;NO. OF ROWS=(2N-1)
// *
// **
// ***
// **
// *
// void print(int n){
//     for(int i=1;i<=2*n-1;i++){
//         int stars=i;
//         if(i>n){
//             stars=2*n-i;
//         }
//         for(int j=0;j<stars;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }

// 1
// 01
// 101
// 0101
// 10101
// void print(int n){
    // for(int i=0;i<=n;i++){
    //     int d=i%2;
    //     for(int j=0;j<=i;j++){
    //         if(d==0){
    //             cout<<"1";
    //             d+=1;
    //         }
    //         else{
    //             cout<<"0";
    //             d=d-1;
    //         }
    //     }
    //     cout<<endl;
    // }
  //OR  
//     int start;
//     for(int i=0;i<n;i++){
//         if(i%2==0) {
//             start=1;
//         }
//         else{
//             start=0;
//         }
//         for(int j=0;j<=i;j++){
//             cout<<start;
//             start=1-start;
//         }
//         cout<<endl;
//     }
// }

// 1    1 //number space number
// 12  21
// 123321
// void print(int n){
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=i;j++){
//             cout<<j;
//         }
//         for(int space=1;space<=2*n-2*i;space++)
//         {
//             cout<<" ";
//         }
//         for(int j =i;j>=1;j--){
//             cout<<j;
//         }
//         cout<<endl;
//     }
// }

// 1
// 23
// 345
// 6789
// void print(int n){
//     int num=1;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=i;j++){
//             cout<<num;
//             num+=1;
//         }
//         cout<<endl;
//     }
// }

// A
// AB 
// ABC 
// ABCD
// void print(int n){
//     for(int i=1;i<=n;i++){
//         for(char ch = 'A';ch<='A'+i-1;ch++){
//             cout<<ch<<" ";
//         }
//         cout<<endl;
//     }   
// } 

//ABCD
//ABC
//AB
//A
// void print(int n){
//     for(int i=1;i<=n;i++){
//         for(char ch = 'A';ch<='A'+n-i;ch++){
//             cout<<ch<<" ";
//         }
//         cout<<endl;
//     } 
// } 

// A 
// BB 
// CCC 
// void print(int n){
//     for(int i=0;i<n;i++){
//         char ch='A'+i;
//         for(int j=0;j<=i;j++){
//             cout<<ch<<" ";
//         }
//         cout<<endl;
//     }
// }//

// --A--
// -ABA-
// ABCBA
// void print(int n){
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n-i;j++){
//             cout<<" ";
//         }
//         char ch='A';
//         for(int j=1;j<=2*i-1;j++)
//         {
//             cout<<ch;
//             if(j<i){
//             ch++;
//             }else{
//                 ch=ch-1;
//             }
//         }
//         cout<<endl;
//     }
// }

// D 
// CD 
// BCD 
// ABCD
// void print(int n){
//     for(int i=0;i<n;i++){
//         char ch='A'+n-i-1;
//         for(int j=0;j<=i;j++){
//             cout<<ch<<" ";
//             ch++;
//         }
//         cout<<endl;
//     }
// }

// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********
// void print(int n){
//     //FIRST HALF
//     for(int i=0;i<n;i++){
//         for(int j =0;j<n-i;j++){
//             cout<<"*";
//         }
//         for(int j=0;j<2*i;j++){
//             cout<<" ";
//         }
//         for(int j=n-i;j>0;j--){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     //SECOND HALF
//     for(int i=1;i<=n;i++){
//         for(int j=0;j<i;j++){
//             cout<<"*";
//         }
//         for(int j=0;j<2*(n-i);j++){
//             cout<<" ";
//         }
//         for(int j=0;j<i;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }

// *--------*  //stars=2n-1
// **------**
// ***----***
// ****--****
// **********
// ****--****
// ***----***
// **------**
// *--------*
// void print(int n){
//     for(int i=1;i<=2*n-1;i++){
//         int stars=i;
//         if(i>n) stars=2*n-i;
//         for(int j=1;j<=stars;j++){
//             cout<<"*";
//         }
//         for(int j=1;j<=2*(n-stars);j++){
//             cout<<" ";
//         }
//         for(int j=1;j<=stars;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }

// * * * *
// *     *
// *     *
// * * * *
// void print(int n){
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(i==0||j==0||j==n-1||i==n-1) {
//                 cout<<"* ";
//             }
//             else cout<<"  ";
//         }
//         cout<<endl;
//     }
// }

// 4444444 //IMPORTANT
// 4333334
// 4322234
// 4321234
// 4322234
// 4333334
// 4444444
// void print(int n){
//     for(int i=0;i<2*n-1;i++){
//         for(int j=0;j<2*n-1;j++){
//             //DISTANCES BETWEEN ELEMENT AND THAT VERTEX
//             int top = i;
//             int left=j;
//             int right= 2*n-2-j;
//             int bottom=2*n-2-i;
//             cout<< n - min(min(top,bottom),min(left,right));
//         }
//         cout<<endl;
//     }
// }


// int main(){

//     //FOR TESTS CASES
//     int t;
//     cout<<"Enter no of times abcd"<<endl;
//     cin>>t;
//     for(int j=0;j<t;j++)
//     {
//         int n;
//         cin>>n;
//         print(n);
//         cout<<endl;

//     }
    
//     return 0;
// }