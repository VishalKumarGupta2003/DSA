#include <bits/stdc++.h>
using namespace std;

// 1) REQUIRED SUM OF TWO ELEMENTS IN AN ARRAY
// int main(){
//     int n,flag=0;
//     cin>>n;
//     vector<int> arr(n);
//     map<int,int> mpp;
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int target;
//     cin>>target;
//     int more=0;
//     for(int i=0;i<n;i++){
//         more=target-arr[i];
//         if(mpp.find(more) != mpp.end()){
//             // return true; //return {mpp[more],i}
//             cout<<mpp[more]<<" and "<<i;
//             return 0;
//         }
//         mpp[arr[i]]=i;
//     }
//     cout<<"The pair for the sum doesn't exist:- ";
//     return 0;
// }
// METHOD 3:- IF THE ARRAY IS SORTED
// string read(vector<int> &arr,int n,int k){
//     int sum=0;
//     int i=0,j=n-1;
//     sort(arr.begin(),arr.end());
//     while(i<j){
//         sum=arr[i]+arr[j];
//         if(sum==k) return "Yes";
//         else if(sum<k) i++;
//         else j--;
//     }
//     return "No";
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int k;
//     cin>>k;
//     cout<<read(arr,n,k);
//     return 0;
// }

// # 2) SORT AN ARRAY OF 0's ,1's & 2's
// METHOD 1:- SORT IT USING MERGE SORT
//  METHOD 2:- COUNT 0 , 1 & 2 AND REWRITE THE ARRAY MANUALY
// METHOD 3:-DUTCH NATIONAL FLAG ALGORITHM
// --> FROM idx=0 to low-1 =>0
// --> FROM idx=low to mid-1 => 1
// --> FROM idx =high+1 to n-1 ==> 2
// --> FROM idx=mid to high ==> unordered
//  class Solution {
//  public:
//      void sortColors(vector<int>& nums) {
//          int low=0,mid=0,high=nums.size()-1;
//          while(mid<=high){
//              if(nums[mid]==0){
//                  swap(nums[low],nums[mid]);
//                  low++;
//                  mid++;
//              }
//              else if(nums[mid]==1) mid++;
//              else{
//                  swap(nums[mid],nums[high]);
//                  high--;
//              }
//          }
//      }
//  };

// # 3) MAJORITY ELEMENT WHICH HAS COUNT FREQUENCY OF N/2
//  METHOD 1:- BRUTE METHOD
//  METHOD 2:- USING HASH
//  class Solution {
//  public:
//      int majorityElement(vector<int>& arr) {
//          map<int,int> mpp;
//          int n=arr.size();
//          for(int i=0;i<n;i++){
//              mpp[arr[i]]+=1;
//          }
//          for(auto it: mpp){
//              if(it.second>n/2) return it.first;
//          }
//          return -1;
//      }
//  };
//  METHOD 3:- Boyer–Moore Majority Vote Algorithm --> CHECK WHICH HAS CHANCE OF BEING THE MAJORITY ELEMENT IF NEW EL APPEARS CNT=1 SAME APPEARS CNT++ ELSE CNT-- 
//  class Solution {
//  public:
//      int majorityElement(vector<int>& nums) {
//          int el,cnt=0;
//          for(int i=0;i<nums.size();i++){
//              if(cnt==0){
//                  cnt++;
//                  el=nums[i];
//              }
//              else if(nums[i]==el){
//                  cnt++;
//              }
//              else cnt--;
//          }
//          int cnt1=0;
//          for(int i=0;i<nums.size();i++){
//              if(nums[i]==el) cnt1++;
//          }
//          if(cnt1>nums.size()/2) return el;
//          return 0;
//      }
//  };

// # 4) SUB-ARRAY WITH MAXIMUM SUM
// METHOD 1:-BRUTE METHOD
// maxSum=MIN_INT;
// LOOP i=0 TO n
//     sum=0
//     LOOP j=0 to n
//         sum=sum+arr[j]
//         maxSum=max(maxSum,sum)
// METHOD 2:-KADAN ALGORITHM--> -VE SUM KO CARRY NHI KARNA
// class Solution {
// public:
//     int maxSubArray(vector<int>& arr) {
//         int n=arr.size();
//         int maxSum=INT_MIN;
//         int sum=0;
//         for(int i=0;i<n;i++){
//             sum+=arr[i];
//             maxSum=max(maxSum,sum);
//             if(sum<0) sum=0;
//         }
//     return maxSum;
//     }
// };

// # 5) SUB-ARRAY WITH MAXIMUM SUM AND PRINTING IT
//     int maxSubArray(vector<int>& arr) {
//         int n=arr.size();
//         int maxSum=INT_MIN;
//         int sum=0;
//         int start=0,ansEnd=-1,ansStart=-1;
//         for(int i=0;i<n;i++){
//             if(sum==0) start=i;
//             sum+=arr[i];
//             if(sum>maxSum){
//                 maxSum=max(maxSum,sum);
//                 ansStart=start;
//                 ansEnd=i;
//             }
//             if(sum<0) sum=0;
//         }
//     return maxSum;
//     }
// };

// 6)REARRANGE EQUAL NUMBERS OF POSITIVE AND NEGATIVE ALTERNATIVELY ==> {+,-,+,-,+,-}
// METHOD 1:- BRUTE METHOD
// vector pos and neg
// LOOP i=0 to n
//     if(i<0) pos.push_back(a[i])
//     else neg.push_back(a[i])
// LOOP i=0 to n/2
//     arr[2*i]=pos[i]
//     arr[2*i+1]=neg[i]
// METHOD 2:-OPTIMAL SOLUTION --> +VE AT 2*iTH INDEX 
// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         int pos=0,neg=1;
//         int n=nums.size();
//         vector<int> ans(n);
//         for(int i=0;i<n;i++){
//             if(nums[i]<0) {
//             ans[neg]=nums[i];
//             neg+=2;
//     }
//     else{
//         ans[pos]=nums[i];
//         pos+=2;
//     }
// }
//         return ans;
//     }
// };

// # 7)REARRANGE UNEQUAL NUMBERS OF POSITIVE AND NEGATIVE ALTERNATIVELY ==> {+,-,+,-,+,-}
// FALLBACK TO BRUTE METHOD
// vector<int> rearrange(vector<int> &arr, int n)
// {
//     vector<int> ans(n, 0);
//     vector<int> pos;
//     vector<int> neg;
//     for(int i=0;i<n;i++){
//         if(arr[i]>=0){
//             pos.push_back(arr[i]);
//         }
//         else{
//             neg.push_back(arr[i]);
//         }
//     }
//     if(pos.size()>neg.size()){
//         for(int i=0;i<neg.size();i++){
//             ans[2*i]=pos[i];
//             ans[2*i+1]=neg[i];
//         }
//         int idx=neg.size();
//         for(int i=2*neg.size();i<n;i++){
//             ans[i]=pos[idx];
//             idx++;
//         }
//     }
//     else{
//         for(int i=0;i<pos.size();i++){
//             ans[2*i]=pos[i];
//             ans[2*i+1]=neg[i];
//         }
//         int idx=pos.size();
//         for(int i=2*pos.size();i<n;i++){
//             ans[i]=neg[idx];
//             idx++;
//         }
//     }
//     return ans;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> ans= rearrange(arr,n);
//     for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
//     return 0;
// }

// 8)# NEXT PERMUTATION
// METHOD 1:- BRUTE METHOD
// FIND ALL PERMUTATIONS IN SORTED ORDER 
// LINEAR SEARCH
// PRINT THE NEXT PERMUTATION
// METHOD 2:- 
// IN CPP USING STL
// next.permutation(a.begin(),a.end());
//METHOD 3:- OPTIMAL APPROACH
// LONGER PREFIX MATCH a[i]<a[i+1]
// FIND BREAKING POINT :-digit>i ,BUT SMALLEST TO REMAIN CLOSE
// TRY TO PLACE THE REMAINING (AFTER THAT BREAKING INDEX) IN SORTED ARRAY
// vector<int> nextPermutation(vector<int> &arr,int n){
//     int idx=-1;
//     for(int i=n-2;i>=0;i--){
//         if(arr[i]<arr[i+1]) {
//             idx=i;
//             break;
//         }
//     }
//     if(idx==-1){
//         reverse(arr.begin(),arr.end());
//         return arr;
//     }
//     for(int i=n-1;i>idx;i--){
//         if(arr[i]>arr[idx]){
//             swap(arr[i],arr[idx]);
//             break;
//         }
//     }
//     reverse(arr.begin()+idx+1,arr.end());
//     return arr;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> ans=nextPermutation(arr,n);
//     for(int i=0;i<n;i++) cout<<ans[i]<<" ";
//     return 0;
// }

// 9) LEADERS IN AN ARRAY
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int maxi=INT_MIN;
//     vector<int> ans;
//     for(int i=n-1;i>=0;i--){
//         if(arr[i]>maxi){
//             ans.push_back(arr[i]);
//             maxi=arr[i];
//         }
//     }
//     cout<<"Leaders in an array are: ";
//     for(auto it:ans){
//         cout<<it<<" ";
//     }
//     return 0;
// }

// 10) LONGEST CONSECUTIVE SEQUENCE IN AN ARRAY
//METHOD 1:-BRUTE METHOD
//METHOD 2:-BETTER SOLUTION :-
// SORT THE ARRAY
// maxSeq=0;
// LOOP i=1 to n
//     if(arr[i]==arr[i]+1){
//         cur++;
//         maxSeq=max(maxSeq,cur);
//     }
//     else if(arr[i]==arr[i-1]){
//         //duplicate ,ignore it
//     }
//     else(
//         cur=1
//     )
// METHOD 3:- OPTIMAL SOLUTION --> find an element el whose presessor (el-1) is not present signifying that if it is involved in sequence then it's first member of sequence
// class Solution {
// public:
//     int longestConsecutive(vector<int>& arr) {
//         int n=arr.size();
//         if(n==0) return 0;
//         int maxi=1;
//         unordered_set<int> st;
//         for(int i=0;i<n;i++){
//             st.insert(arr[i]);
//         }
//         for(auto it:st){
//             if(st.find(it-1)==st.end()){
//                 int cnt=1;
//                 int x=it;
//                 while(st.find(x+1)!=st.end()){
//                     cnt++;
//                     x++;
//                 }
//                 maxi=max(cnt,maxi);
//             }
//         }
//         return maxi;
//     }
// };

//11) SET MATRIX ZEROES
// METHOD 1:-BRUTE METHOD
// HERE IN CASE OF arr[i][j]=0 MARK IT'S CORRESPONDING ELEMENTS -1 
// AFTER COMPLETION OF NESTED LOOP AGAIN LOOP FOR TURNING -1 TO 0
// METHOD 2:- CREATE ANOTHER 1-DIMENSIONAL VECTORS ROW AND COL FOR MARKING WHICH I AND j ARE RESPECTIVELY MARKED
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         int m=matrix[0].size();
//         vector<int> row(n,0);
//         vector<int> col(m,0);
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(matrix[i][j]==0){
//                     row[i]=1;
//                     col[j]=1;
//                 }
//             }
//         }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(row[i]==1||col[j]==1) matrix[i][j]=0;
//             }
//         }
//         return ;    
//     }
// };
//OPTIMAL SOLUTION:-
// OPTIMISE SPACE COMPLEXITY
// TAKE 1ST ROW THAT IS MATRIX[0][...] AS EQUIVALENT TO col(m,0)
// TAKE 1ST COLUMN THAT IS MATRIX[...][0] AS EQUIVALENT TO row(n,0) EXCEPT ARR[0][0] IS NOT TAKEN TO AVOID REPITITION 
// THEREFORE, TAKE ANOTHER VARIABLE e.g: col0 
// NOW BEGIN MAKING CHANGES AND DO NOT INVOLVE 1ST ROW AND 1ST COLUMN FOR THIS, AS IT WILL LEAD TO CATASTRIPHIC ALTERATIONS AND WILL IMOPACT THE REQUIRED MATRIX
// AFTER MARKING THOSE START WITH REVERSE OF ROW
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int col0=1;
//         int n=matrix.size();
//         int m=matrix[0].size();
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(matrix[i][j]==0){
//                     matrix[i][0]=0;
//                     if(j!=0){
//                         matrix[0][j]=0;
//                     }
//                     else{
//                         col0=0;
//                     }
//                 }
//             }
//         }
//         for(int i=1;i<n;i++){
//                 for(int j=1;j<m;j++){
//                     if( matrix[0][j]==0 || matrix[i][0]==0 ) matrix[i][j]=0;
//                 }
//             }
//             if(matrix[0][0]==0){
//                 for(int i=1;i<m;i++){
//                     matrix[0][i]=0;
//                 }
//             }
//             if(col0==0 ){
//                 for(int i=0;i<n;i++){
//                     matrix[i][0]=0;
//                 }
//             }
//     }
// };

//12) ROTATE THE MATRIX BY 90 DEGREE CLOCKWISE
// METHOD 1:- OBSERVE THAT EACH ROW IS MOVED CORRESPONDING (n-i-1)th COLUMN 
// void rotateMatrix(vector<vector<int>> &matrix){
//     int n=matrix.size();
//     int m=matrix[0].size();
//     vector<vector<int>> ans(m,vector<int>(n));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//            ans[j][n-1-i]=matrix[i][j];
//         }
//     }
//     matrix=ans;
//     return ;
// }
// METHOD 2:- TRANSPOSE THE MATRIX AND THEN REVERSE EACH ROW ONLY FOR SQUARE MATRIX
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         for (int i = 0; i < n-1; i++) {
//             for (int j = i+1; j < m; j++) {
//                 swap(matrix[i][j],matrix[j][i]);
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             reverse(matrix[i].begin(),matrix[i].end());
//         }
//         return;
//     }
// };
// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> matrix(n,vector<int>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++) cin>>matrix[i][j];
//     }
//     rotate(matrix);
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++) cout<<matrix[i][j]<<" ,";
//         cout<<endl;
//     }
//     return 0;
// }

//13) MATRIX IN SPIRAL
// ONLY ONE SOLUTION ---> TOP RIGHT BOTTOM AND THEN LEFT
// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         int m = matrix[0].size();
//         vector<int> ans;
//         int top=0,left=0,bottom=n-1,right=m-1;
//         while(left<=right && top<=bottom){
//             for(int i=left;i<=right;i++){
//                 ans.push_back(matrix[top][i]);
//             }
//             top++;
//             for(int i=top;i<=bottom;i++){
//                 ans.push_back(matrix[i][right]);
//             }
//             right--;
//             if(top<=bottom){
//                for(int i=right;i>=left;i--){
//                     ans.push_back(matrix[bottom][i]);
//                 } 
//             }
//             bottom--;
//             if(left<=right){
//                 for(int i=bottom;i>=top;i--){
//                     ans.push_back(matrix[i][left]);
//                 }
//             }
//             left++;
//         }
//         return ans;
//     }
// };

//14) NO. OF SUB-ARRAYS WITH SUM=K ==> 
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         map<int,int> mpp;
//         int presum=0,cnt=0;
//         mpp[0]=1; // Prefix sum 0 exists once before the array starts
//         for(int i=0;i<nums.size();i++){
//             presum += nums[i]; // Calculate prefix sum up to current index
//             int rem = presum - k; // We need an earlier prefix sum = presum-k
//             cnt += mpp[rem]; // Every occurrence of rem gives a subarray with sum k
//             mpp[presum]++; // Store current prefix sum for future subarrays
//         }
//         return cnt; // Total number of subarrays having sum k
//     }
// };