#include <bits/stdc++.h>
using namespace std;

// 1)LARGEST IN ARRAY
// int main() {
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<=n-1;i++){
//         cin>>arr[i];
//     }
//     int largest=arr[0];
//     for(int i=1;i<=n-1;i++){
//         if(arr[i]>largest) largest=arr[i];
//     }
//     cout<<largest;
//     return 0;
// }

// 2)SECOND LARGEST AND SECOND SMALLEST WITHOUT SORTING
// int secSmallest(vector<int> &arr,int n){
//     int smallest=arr[0];
//     int sSmallest=INT_MAX;
//     for(int i=1;i<n;i++){
//         if(arr[i]<smallest){
//             sSmallest=smallest;
//             smallest=arr[i];
//         }
//         else if(arr[i]==smallest) {}
//         else if (arr[i]>smallest && arr[i]<sSmallest){
//             sSmallest=arr[i];
//         }
//     }
//     return sSmallest;
// }
// int secLargest(vector <int> &arr,int n){
//     int largest=arr[0];
//     int slargest=INT_MIN;
//     for(int i=1;i<n;i++){
//         if(arr[i]>largest){
//             slargest=largest;
//             largest=arr[i];
//         }
//         else if(arr[i]==largest) {}
//         else if(arr[i]<largest && arr[i]>slargest){
//             slargest=arr[i];
//         }
//     }
//     return slargest;
// }
// vector<int> getSecondOrder(vector <int> &arr,int n)
// {
//     int sSmallest=secSmallest(arr,n);
//     int sLargest = secLargest(arr,n);
//     return {sSmallest,sLargest};
// }
// int main(){
// int n;
// cin>>n;
// vector<int> arr(n);
// for(int i=0;i<=n-1;i++){
//     cin>>arr[i];
// }
//     vector<int> ans=getSecondOrder(arr,n);
//     for(int i=0;i<2;i++){
//         cout<<ans[i]<<;
//     }
//     return 0;
// }

// 3) SORTED OR NOT
// bool isSorted(vector<int> &arr,int n){
//     for(int i=0;i<n-1;i++){
//         if(arr[i]<=arr[i+1]){}
//         else return false;
//     }
//     return true;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<=n-1;i++){
//         cin>>arr[i];
//     }
//     if(isSorted(arr,n)==true){
//     cout<<"The array is sorted";
//     }
//     else cout<<"The array is not sorted";
//     return 0;
// }

// 4) REMOVE DUPLICACY IN SORTED ARRAY AND REPORT UNIQUE COUNT
//  int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<=n-1;i++){
//         cin>>arr[i];
//     }
//     cout<<"Original Array:- ";
//     for(auto it: arr){
//         cout<<it<<" ";
//     }
//     cout<<endl;
//     int i=0;
//     for(int j=0;j<n;j++){
//         if(arr[j]!=arr[i]){
//             arr[i+1]=arr[j];
//             i++;
//         }
//     }
//     cout<<"Modified Array:- ";
//     for(auto it: arr){
//         cout<<it<<" ";
//     }
//     cout<<endl;
//     cout<<"Number of unique elements in the original array is :- "<<i+1;
//  }

// 5) ROTATE THE ARRAY LEFT
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<=n-1;i++){
//         cin>>arr[i];
//     }
//     cout<<"Original Array:- ";
//     for(auto it: arr){
//         cout<<it<<" ";
//     }
//     cout<<endl;
//     int temp=arr[0];
//     for(int i=1;i<n;i++){
//         arr[i-1]=arr[i];
//     }
//     arr[n-1]=temp;
//     cout<<"Modified Array:- ";
//     for(auto it: arr){
//         cout<<it<<" ";
//     }
//     return 0;
// }

// 6) ROTATE THE ARRAY LEFT by DISTANCE D
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<=n-1;i++){
//         cin>>arr[i];
//     }
//     cout<<"Original Array:- ";
//     for(auto it: arr){
//         cout<<it<<" ";
//     }
//     cout<<endl;
//     int d;
//     cin>>d;
//     d=d%n;
// vector <int> temp(d);
// for(int i=0;i<d;i++){
//     temp[i]=arr[i];
// }
// for(int i=d;i<n;i++){
//     arr[i-d]=arr[i];
// }
// for(int i=0;i<d;i++){
// arr[n-d+i]=temp[i];
// }
// OPTIMAL SOLUTION
//     reverse(arr[0],arr[d]);
//     reverse(arr[d],arr[n]);
//     reverse(arr[0],arr[n]);
//     cout<<"Modified Array:-  ";
//     for(auto it: arr){
//         cout<<it<<" ";
//     }
//     return 0;
// }

// # 7)PUT ZEROES OF THE ARRAY AT THE END
//  int main(){
//      int n;
//      cin>>n;
//      vector<int> arr(n);
//      for(int i=0;i<=n-1;i++){
//          cin>>arr[i];
//      }
//      cout<<"Original Array:- ";
//      for(auto it: arr){
//          cout<<it<<" ";
//      }
//      cout<<endl;
// METHOD 1:- BRUTE METHOD
//  vector<int> temp;
//  for(int i=0;i<n;i++){
//      if(arr[i]!=0) temp.push_back(arr[i]);
//  }
//  int s=temp.size();
//  for(int i=0;i<s;i++){
//      arr[i]=temp[i];
//  }
//  for(int i=s;i<n;i++){
//      arr[i]=0;
//  }
//  cout<<"Modified Array:- ";
//  for(auto it: arr){
//      cout<<it<<" ";
//  }
// METHOD 2:- UNSTABLE
// int i=0,j=n-1;
// while (i<j){
//     if(arr[i]!=0) i++;
//     if(arr[j]==0) j--;
//     if(arr[i]==0 && arr[j]!=0) swap(arr[i],arr[j]);
// }
// METHOD 3:- OPTIMAL AS IT WILL  BE STABLE THAT IS MAINTAINS THE ORDER OF THE ELEMNENT
//     int j= -1;
//     for(int i=0;i<n;i++){
//         if(arr[i]==0){
//             j=i;
//             break;
//         }
//     }
//     if(j==-1) {
//     cout<<"Modified Array:- ";
//     for(auto it: arr){
//         cout<<it<<" ,";
//     }
//     cout<<endl;
//     return 0;
//     }
//     for(int i=j+1;i<n;i++){
//         if(arr[i]!=0){
//             swap(arr[i],arr[j]);
//             j++;
//         }
//     }
//     cout<<"Modified Array:- ";
//     for(auto it: arr){
//         cout<<it<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

// # 8)MISSING NUMBER IN N-1 ARRAY
// METHOD 1:- BRUTE METHOD
//  for(int i=1;i<n;i++)
//      flag =0
//      for(j= 0 to n)
//          if(arr[j]==i)
//              flag =1
//              break
//      if(flag == 0) return i as i was missing
// METHOD 2:- USING HASH METHOD
//  hash(n)={0}
//  FOR(I=0->N)
//      hash[arr[i]=1]
//  iterate for hash.second=0 --> hash.first is missing
// METHOD 3:- SUMMATION METHOD
//  SUM FOR N natural numbers is (N*(N+1))/2
//  loop for i=0 to i=n
//      s=s+arr[i]
//  missing number = sum-s;
//  XOR METHOD ==> a^a=0 ; a^o=a
//  xor1=0 // XOR OF N NATURAL NUMBERS
//  xor2 =0 //XOR OF ARRAY
//  eg:- (1^2^3^4^5)^
//       (1^2^4^5) ==> 3
//  for(i=0 to n-1)
//      xor2=xor2^arr[i];
//      xor1=xor1^(i+1)
//  missing number= xor1^xor2

// 9)HIGHEST COUNT OF CONSECUTIVE 1
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<=n-1;i++){
//         cin>>arr[i];
//     }
//     int cur=0,highest=0;
//     // for(int i=0;i<n;i++){
//     //     if(arr[i]==1&&i<n-1){
//     //         cur++;
//     //     }
//     //     else if(arr[i]==1 && i==n-1){
//     //         cur++;
//     //         highest=(cur>highest)?cur:highest;
//     //     }
//     //     else if(arr[i]!=1 && i<n-1){
//     //         highest=(cur>highest)?cur:highest;
//     //         cur=0;
//     //     }
//     // }
//     for(int i=0;i<n;i++){
//         if(arr[i]==1){
//             cur++;
//             highest=max(cur,highest);
//         }
//         else cur=0;
//     }
//     cout<<"Highest count of consecutive 1 is :-"<< highest;
// }

// 10) RETURN THE NUMBER WHICH APPEARS ONLY ONCE IN AN ARRAY WHERE EVERY OTHER ELEMENT APPEARS TWICE
// METHOD 1:- BRUTE METHOD
// LOOP i=0 to n
//     num arr[i]
//     c=0
//     LOOP j to n
//         if(arr[j]==num)
//         c++
//     if(c==1) return arr[j]
// METHOD 2:- USING HASHING
// maxi=arr[0]
// LOOP i 1 to n
//     maxi(maxi,arr[i])
// DEFINE int hash[maxi] ={0}
// LOOP i=0 to n
//     hash[arr[i]]++
// iterate in hash
// return hash[i]==1
// METHOD 3:- USING MAP
// STORE:- mpp.first= element and mpp.second= count
// return mpp.first whose mpp.second ==1
// METHOD 4:- USING XOR
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     int xor1=0;
//     for(int i=0;i<n;i++){
//         xor1=xor1^arr[i];
//     }
//     cout<<"The answer is:- "<<xor1;
//     return 0;
// }

// 11) LONGEST SUBARRAY WITH SUM K --> SUBARRAY REFERS TO CONTIGUOS SUB-PART OF ARRAY
// METHOD 1:- BRUTE
// LOOP i=0 to n
//     LOOP j=i to n
//         LOOP k=i to j
//             s+=a[k]
//             if(s==sum) {
//                 length=max(length,j-i+1)
//                 break;<sumMap,count>
//             }
// OPTIMAL SOLUTION FOR NEGATIVE NUMBERS AND ZERO--> USING HASHING AND IN HASHMAP the element are <sumMap,count>
// #include <bits/stdc++.h>
// int longestSubarrayWithSumK(vector<int> a, long long k) {
//     map<long long, int> preSumMap;
//     long long sum = 0;
//     int maxLen = 0;
//     for (int i = 0; i < a.size(); i++) {
//         sum += a[i];
//         if (sum == k) {
//             maxLen = max(maxLen, i + 1);
//         }
//         long long rem = sum - k;
//         if (preSumMap.find(rem) != preSumMap.end()) {
//             int len = i - preSumMap[rem];
//             maxLen = max(maxLen, len);
//         }
//         if (preSumMap.find(sum) == preSumMap.end()) {
//             preSumMap[sum] = i;
//         }
//     }
//     return maxLen;
// }
// OPTIMAL SOLUTION FOR NON-NEGATIVE NUMBERS AND ZERO
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     long long k;
//     cin>>k;
//     int left =0,right=0,maxLen=0;
//     long long sum=0;
//     while(right<n){
//         sum+=arr[right];
//         while(left<right && sum>k){
//             sum-=arr[left];
//             left++;
//         }
//         if(sum==k){
//             maxLen=max(maxLen,right-left+1);
//         }
//         right++;
//     }
//     cout<<"Maximum lenth of subArray whose sum is "<<k<<" : "<<maxLen;
//     return 0;
// }

// 12) UNION OF ELEMENTS
// vector<int> uni(vector <int> &a, vector <int> &b){
//     int n1=a.size();
//     int n2=b.size();
//BRUTE METHOD
    // set <int> st;
    // for(int i=0;i<n1;i++){
    //     st.insert(a[i]);
    // }
    // for(int i=0;i<n2;i++){
    //     st.insert(b[i]);
    // }
    // vector<int> temp;
    // for(auto it:st){
    //     temp.push_back(it);
    // }
    // return temp;
//OPTIMAL SOLUTION
//     vector <int> temp; 
//     int i=0,j=0;
//     while(i < n1 && j < n2){
//         if(a[i] <= b[j]){
//             if(temp.size()==0 || a[i] != temp.back() ){
//                 temp.push_back(a[i]);
//             }
//             i++;
//         }
//         else{
//             if(temp.size()==0 || b[j] != temp.back() ){
//                 temp.push_back(b[j]);
//             }
//             j++;
//         }
//     }
//     while(i < n1){
//         if(temp.size()==0 || a[i] != temp.back() ){
//                 temp.push_back(a[i]);
//             }
//             i++;
//     } 
//     while(j < n2){
//         if(temp.size()==0 || b[j] != temp.back() ){
//                 temp.push_back(b[j]);
//             }
//             j++;
//     }
//     return temp;
// }

// 13) INTERSECTION OF ELEMENTS
// vector<int> inter(vector<int> &a,vector<int> &b){
//     int n1= a.size();
//     int n2=b.size();
    // int visited[n2]={0};
    // vector<int> ans;
    // for(int i=0;i<n1;i++){
    //     for(int j=0;j<n2;j++){
    //         if(a[i]==b[j] && visited[j]==0){
    //             ans.push_back(b[j]);
    //             visited[j]=1;
    //             break;
    //         }
    //         if(b[j]>a[i]){break;}    
    //     }
    // }
//     int i=0,j=0;
//     vector<int> ans;
//     while(i<n1 && j<n2){
//         if(a[i]<b[j]){
//             i++;
//         }
//         else if(a[i]>b[j]){
//             j++;
//         }
//         else{
//            ans.push_back(a[i]) ;
//            i++;
//            j++;
//         }
//     }
//     return ans;
// }
// int main()
// {
//     int n1,n2;
//     cin>>n1;
//     vector<int> arr1(n1);
//     for(int i=0;i<=n1-1;i++){
//         cin>>arr1[i];
//     }
//     cout<<"Array A :- ";
//     for(auto it: arr1){
//         cout<<it<<" ";
//     }
//     cout<<endl;
//     cin>>n2;
//     vector<int> arr2(n2);
//     for(int i=0;i<=n2-1;i++){
//         cin>>arr2[i];
//     }
//     cout<<"Array B :- ";
//     for(auto it: arr2){
//         cout<<it<<" ";
//     }
//     cout<<endl;
//     // vector<int> result=uni(arr1,arr2);
//     vector<int> result=inter(arr1,arr2);
//     cout<<"Resultant Array:- ";
//     for(auto it:result){
//         cout<<it<<" ";
//     }
//     return 0;
// }

// 14) FIND REPEATING AND MISSING NUMBERS
// METHOD 1:- USING HASHING
// class Solution {
// public:
//     // Main Logic: Use a frequency array where hash[i] stores how many times
//     // number i appears. If hash[i] == 2, i is repeating; if hash[i] == 0,
//     // i is missing.
//     vector<int> findMissingRepeatingNumbers(vector<int> nums) {
//         int n=nums.size();
//         int hash[n+1]={0};
//         // Count the frequency of every number
//         for(int i=1;i<=n;i++){
//             hash[nums[i]]+=1;
//         }
//         int missing=-1,repeating =-1;
//         // Find the number appearing twice and the number not appearing
//         for(int i=1;i<=n;i++){
//             if(hash[i]==2) repeating=i;
//             else if(hash[i]==0) missing=i;
//             // Stop once both numbers are found
//             if(missing != -1 && repeating != -1) break;
//         }
//         return {repeating,missing};
//     }
// };
// METHOD 2:- MATHEMATICAL REASONING
// class Solution {
// public:
//     // Main Logic: Let x = repeating and y = missing.
//     // Sum gives x-y = s-sn. Difference of squares gives x²-y² = s2-s2n.
//     // Since x²-y²=(x-y)(x+y), get x+y=(s2-s2n)/(s-sn).
//     // Then x=(x-y+x+y)/2 and y=(x+y)-(x).
//     vector<int> findMissingRepeatingNumbers(vector<int> nums) {
//         // x-y = s-sum // x is repeated and y is missung
//         // x2-y2 = s2-squaredSum => 
//         // x+y = (s2-squaredSum)/(s-sum)
//         // x-y = s-sn
//         // x2-y2 = s2-s2n => 
//         // x+y = (s2-s2n)/(s-sn)
//         int n=nums.size();
//         long long sn=(n*(n+1))/2;
//         long long s2n= (n*(n+1)*((2*n)+1))/6;
//         long long s=0,s2=0;
//         for(int i=0;i<n;i++){
//             s+=nums[i];
//             s2 += (long long)nums[i] * (long long)nums[i];
//         }
//         long long val1=s-sn; // x-y
//         long long val2=s2-s2n; // x²-y²
//         val2= val2/val1; // x+y
//         int x=val1+ val2; // (x-y)+(x+y)=2x
//         x=x/2;
//         int y=val2-x; // y=(x+y)-x
//         return {x,y};
//     }
// };
// METHOD 3:- USING XOR
// class Solution {
// public:
//     // Main Logic: XOR all array elements with 1..n to get repeating^missing.
//     // Find a set bit where the two numbers differ, then divide both array
//     // and 1..n into two groups based on that bit. XOR each group to get
//     // the two numbers. Finally, count which one appears twice to identify
//     // repeating and missing.
//     vector<int> findMissingRepeatingNumbers(vector<int> a) {
//         long long n = a.size();
//         int xr=0;
//         for(int i=0;i<n;i++){
//             xr=xr^a[i]; // XOR array elements
//             xr=xr^(i+1); // XOR numbers from 1 to n
//         }
//         int bitno=0;
//         while(1){
//             if(xr & (1<<bitno) !=0) { // Find a bit where repeating and missing differ
//                 break;
//             }
//             bitno++;
//         }  //OR int number = xr & ~(xr-1); // REPLACES int bitno=....; and the following loop of while(1)
//         int one=0;
//         int zero=0;
//         for(int i=0;i<n;i++){
//             if(a[i] & (1<<bitno)!=0){ // Put element in 'one' group
//                 one=one^a[i];// OR if(a[i] & (number)!=0){
//             }
//             else{ // Put element in 'zero' group
//                 zero=zero^a[i];
//             }
//         }
//         for(int i=1;i<=n;i++){
//             if(i & (1<<bitno)!=0){ // Put number in 'one' group
//                 one=one^i;
//             }
//             else{ // Put number in 'zero' group
//                 zero=zero^i;
//             }
//         }
//         int cnt=0;
//         for(int i=0;i<n;i++){
//             if(a[i]==zero) cnt++; // Check which candidate is repeating
//         }
//         if(cnt==2) return {zero,one}; // zero = repeating, one = missing
//         return {one,zero}; // one = repeating, zero = missing
//     }
// };

// 15) MAXIMUM PRODUCT SUB-ARRAY
// class Solution {
// public:
//     // Main Logic: Keep a prefix product from the left and a suffix product from the right.
//     // A zero breaks a subarray, so reset the corresponding product to 1 after encountering 0.
//     // At every index, check both products and keep the maximum product found.
//     int maxProduct(vector<int>& arr) {
//         int n =arr.size();
//         int prefix=1,suffix=1;
//         int maxi= INT_MIN;
//         for(int i=0;i<n;i++){
//             if(prefix == 0) prefix=1; // Reset after a zero
//             if(suffix == 0) suffix=1; // Reset after a zero
//             prefix*=arr[i]; // Product from left
//             suffix*=arr[n-i-1]; // Product from right
//             maxi=max(maxi,max(prefix,suffix)); // Update maximum product
//         }
//         return maxi;
//     }
// };