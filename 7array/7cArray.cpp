#include <bits/stdc++.h>
using namespace std;


//1) PASCAL'S TRIANGLE
// i)TO FIND THE ELEMENT AT THE 'r'th ROW & 'c'TH COLUMN
// METHOD 1:-
// (r-1)C(c-1)
// CONSIDERING THAT ROOT IS AT 0TH ROW
// int ncr(int r,int c){
//     long long res=1;
//     for(int i=0;i<c;i++){
//         res=res*(r-i);
//         res=res/(i+1);
//     }
//     return res;
// }
// int main(){
//     int r,c;
//     cin>>r>>c;
//     cout<<ncr(r-1,c-1);
//     return 0;
// }
// ii) PRINT AN ENTIRE ARRAY
// METHOD 1:-JUST USE ncr(r-1,c-1) for for r-1 times in the loop
// METHOD 2:- FOR NEXT ELEMENT WE CAN USE THE ANSWER THE OF IT'S PREVIOUS ELEMENT
// void printRow(int r){
//     long long ans=1;
//     cout<<ans<<" ";
//     for(int i=1;i<r;i++){
//         ans=(r-i)*ans;
//         ans=ans/i;
//         cout<<ans<<" ";
//     }
//     return;
// }
// int main(){
//     int r;
//     cin>>r;
//     printRow(r);
//     return 0;
// }
// iii) PRINTING THE PASCAL'S TRIANGLE
// class Solution {
// public:
//     vector<int> generateRow(int row){
//     vector<int> ansRow;
//     ansRow.push_back(1);
//     long long ans=1;
//     for(int i=1;i<=row;i++){
//         ans=(row-i)*ans;
//         ans=ans/i;
//         ansRow.push_back(ans);
//     }
//     return ansRow;
// }
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> ans;
//         for(int i=1;i<=numRows;i++){
//             ans.push_back(generateRow(i));
//         }
//         return ans;
//     }
// };

// 2) MAJORITY ELEMENT WITH COUNT FREQUENCY MORE THAN N/3
// METHOD 1:-__hash_empty_baseclass Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//        map<int,int> mpp;
//        vector<int> ls;
//        int mini=int(nums.size()/3) +1;
//        int n=nums.size();
//        for(int i=0;i<n;i++){
//             mpp[nums[i]]+=1;
//             if(mpp[nums[i]]==mini) ls.push_back(nums[i]);
//             if(ls.size()>2) break;
//        }
//        return ls;
//     }
// };
// METHOD 2:- 
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int el1=INT_MIN;
//         int el2=INT_MIN;
//         int cnt1=0,cnt2=0;
//         vector<int> ls;
//         int mini=int(nums.size()/3)+1;
//         for(int i=0;i<nums.size();i++){
//             if(cnt1==0 && nums[i]!=el2){
//                 cnt1++;
//                 el1=nums[i];
//             }
//             else if(cnt2==0 && nums[i]!=el1){
//                 cnt2++;
//                 el2=nums[i];
//             }
//             else if(nums[i]==el1) cnt1++;
//             else if(nums[i]==el2) cnt2++;
//             else {
//                 cnt1--;
//                 cnt2--;
//             }
//         }
//         cnt1=0;
//         cnt2=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==el1) cnt1++;
//             if( nums[i]==el2) cnt2++;
//         }
//         if(cnt1>=mini) ls.push_back(el1);
//         if(cnt2>=mini) ls.push_back(el2);
//         return ls;
//     }
// };

// 3) 3 SUM PROBLEM ==> USE HASHING AND FRO UNIQUENESS USE SET
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>> st;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             set<int> hashSet;
//             for(int j=i+1;j<n;j++){
//                 int target= -(nums[i]+nums[j]);
//                 if(hashSet.find(target)!=hashSet.end()){
//                     vector<int> temp={nums[i],nums[j],target};
//                     sort(temp.begin(),temp.end());
//                     st.insert(temp);
//                 }
//                 hashSet.insert(nums[j]);
//             }
//         }
//         vector<vector<int>> ans(st.begin(),st.end());
//         return ans;
//     }
// }; 
//METHOD 2:-
// vector<vector<int>> tripleSum(vector<int> & arr){
//     sort(arr.begin(),arr.end());
//     int n= arr.size();
//     vector<vector<int>> ans;
//     for(int i=0;i<n;i++){
//         if(i>0 && arr[i]==arr[i-1]) continue;
//         int k = n-1;
//         int j=i+1;
//         while(j<k){
//             int sum=arr[i]+arr[j]+arr[k];
//             if(sum<0) j++;
//             else if(sum>0) k--;
//             else {
//                 vector<int> temp={arr[i],arr[j],arr[k]};
//                 ans.push_back(temp); 
//                 k--;
//                 j++;
//                 while(j<k && arr[j]==arr[j-1]) j++;
//                 while(j<k && arr[k]==arr[k+1]) k--;
//             }
//         }
//     }
//     return ans;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<vector<int>> ans=tripleSum(arr);
//     for(int i=0;i<ans.size();i++){
//         for(int j=0;j<ans[i].size();j++) cout<<ans[i][j]<<" ";
//         cout<<endl;
//     }
//     return 0;
// }

// 4) 4 SUM PROBLEM
// METHOD 1:-USING HASHSET AND FINDING REMAINING SUM
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         set<vector<int>> st;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 for(int k=j+1;k<n;k++){
//                     for(int l=k+1;l<n;l++){
//                         long long sum=nums[i]+nums[j];
//                         sum+=nums[k];
//                         sum+=nums[l];
//                         if(sum==target){
//                             vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
//                             sort(temp.begin(),temp.end());
//                             st.insert(temp);
//                         }
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> ans(st.begin(),st.end());
//         return ans;
//     }
// };
// METHOD 2:- TWO POINTER APPROACH
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         vector<vector<int>> ans;
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             if(i!=0 && nums[i]==nums[i-1]) continue;
//             for(int j=i+1;j<n;j++){
//                 if(j!=i+1 && nums[j]== nums[j-1]) continue;
//                 int k=j+1;
//                 int l=n-1;
//                 while(k<l){
//                     long long sum=nums[i]+nums[j];
//                     sum+=nums[k];
//                     sum+=nums[l];
//                     if(sum>target){
//                         l--;
//                         while(k<l && nums[l]==nums[l+1]){
//                             l--;
//                         }
//                     }
//                     else if(sum<target){
//                         k++;
//                         while(k<l && nums[k]==nums[k-1]){
//                             k++;
//                         }
//                     }
//                     else{
//                         vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
//                         ans.push_back(temp);
//                         k++;
//                         l--;
//                         while(nums[k]==nums[k-1] && k<l) k++;
//                         while(nums[l]== nums[l+1] && k<l) l--;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

// 4) LARGEST SUB-ARRAY WITH ZERO SUM

// 5) Number of Subarrays with xor K //SIMILAR TO SUB-ARRAY WITH SUM=K
//METHOD 1:- BRUTE METHOD
// LOOP i=0 to n-1 
//     xor=0;
//     LOOP j=i+1 to n-1
//     xor=xor^arr[j]
//     if(xor==k) cnt++;
// //METHOD 2:- REMEMBER
//  if : x^k=xr 
//  =>   (x^k)^k=xr^k
//  =>    x=xr^k
// int xorCount(vector<int> &arr,int k){
//     int n=arr.size();
//     int xr=0;
//     int cnt=0;
//     map<int,int> mpp;
//     mpp[0]++;//important
//     for(int i=0;i<n;i++){
//         xr=xr^arr[i];
//         int rem=xr^k;
//         cnt=cnt+mpp[rem];
//         mpp[xr]++;
//     }
//     return cnt;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int k;
//     cin>>k;
//     cout<<xorCount(arr,k);
//     return 0;
// }

// 6) MERGE OVERLAPPING INTERVALS
// METHOD 1:-
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& arr) {
//         sort(arr.begin(),arr.end()); // Sort intervals by starting point
//         vector<vector<int>> ans; // Stores the final merged intervals
//         for(int i=0;i<arr.size();i++){
//             int start=arr[i][0]; // Starting point of current interval
//             int end = arr[i][1]; // Ending point of current interval
//             if(!ans.empty() && end<=ans.back()[1]){
//                 continue; // Current interval is completely covered by previous merged interval
//             }
//             for(int j=i+1;j<arr.size();j++){
//                 if(arr[j][0]<=end){
//                     end=max(end,arr[j][1]); // Overlapping interval, extend the current end
//                 }
//                 else break; // No overlap; since sorted, further intervals won't overlap either
//             }
//             ans.push_back({start,end}); // Store the completely merged interval
//         }
//         return ans; // Return all merged intervals
//     }
// };
// METHOD 2:-
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>> ans; // Stores the merged intervals
//         sort(intervals.begin(),intervals.end()); // Sort intervals by starting point
//         int n=intervals.size(); // Store number of intervals
//         for(int i=0;i<n;i++){
//             if(ans.empty() || intervals[i][0]>ans.back()[1]){
//                 ans.push_back(intervals[i]); // No overlap, so add current interval
//             }
//             else{
//                 ans.back()[1]=max(intervals[i][1],ans.back()[1]); // Overlap, merge by extending the ending point
//             }
//         }
//         return ans; // Return all merged intervals
//     }
// };

// 7) Merge Sorted Arrays Without Extra Space
// METHOD 1:-BRUTE METHOD
// left=0,right=0
// LOOP while(left<n && right < m)
//     store in arr3 
// NOW AGIAN TRANSFER IN ARR1 & ARR2
// // METHOD 2:-
// class Solution {
// public:
//     void merge(vector<int>& arr1,int m, vector<int>& arr2,int n) {
//         // Main Logic: Compare the largest element of arr1 with the smallest
//         // element of arr2 and swap when they are in the wrong order.
//         // Then sort both arrays and copy arr2 into the empty part of arr1.
//         // int n = arr1.size();
//         // int m= arr2.size();
//         int left=m-1;
//         int right = 0;
//         while(left >= 0 && right <= n-1){
//             if(arr1[left]>arr2[right]) {
//                 swap(arr1[left],arr2[right]);
//                 left--;
//                 right++;
//             }
//             else break;
//         }
//         sort(arr1.begin(),arr1.begin()+m);
//         sort(arr2.begin(),arr2.end());
//         for(int i=m;i<n+m;i++){
//             arr1[i]=arr2[i-m];
//         }
//         return;
//     }
// };
// METHOD 3:- GAP FLT_EVAL_METHODclass Solution {
// public:
//     // Main Logic: Treat nums1 and nums2 as one virtual sorted array.
//     // Use the Gap method: compare elements that are 'gap' positions apart
//     // and swap them if they are in the wrong order. Gradually reduce the
//     // gap until it becomes 1. Finally, copy nums2 into the empty part of nums1.
//     void swapIfGreater(vector<int > & nums1,vector <int> &nums2,int left,int right){
//         // Swap the elements if the element in the first array is greater
//         if(nums1[left]>nums2[right]) {
//             swap(nums1[left],nums2[right]);
//         }
//         return;
//     }
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { 
//         // int m = nums1.size();
//         // int n =nums2.size()
//         int len = n+m; // Total number of valid elements
//         int gap = len/2 + len%2; // GETTING CEIL VALUE
//         int left=0;
//         int right=gap;
//         // Keep comparing elements until gap becomes 1
//         while(gap>0){
//             int left=0; // Reset left pointer for every gap
//             int right = left+gap; // Right pointer is gap positions ahead
//             while(right<len){
//                 // nums 1 and nums2
//                 if( left < m && right >= m){
//                     // left is in nums1, right is in nums2
//                     swapIfGreater(nums1, nums2,left,right-m);
//                 }
//                 // nums2 and nums2
//                 else if(left>=m){
//                     // Both left and right are in nums2
//                     swapIfGreater(nums2, nums2,left-m,right-m);
//                 }
//                 else {
//                     // Both left and right are in nums1
//                     swapIfGreater(nums1, nums1,left,right);
//                 }
//                 right++; // Move right pointer forward
//                 left++; // Move left pointer forward
//             }
//             // If gap is 1, one final comparison pass is completed
//             if(gap==1) break;
//             // Reduce gap using ceil(gap/2)
//             gap = gap/2 + gap%2;
//         }
//         // Copy sorted nums2 into the empty positions of nums1
//         for(int i=m;i<n+m;i++){
//             nums1[i]=nums2[i-m];
//         }
//         return;
//     }
// };

// 8) Count Inversions in an Array
// METHOD 1:- BRUTE METHOD WITH TIME COMPLEXITY OF O(N^2)
//METHOD 2:- USING THE MERGE SORT TECHNIQUE
// class Solution {
// public:
//     // Main Logic: Use merge sort. While merging two sorted halves, if arr[left] > arr[right],
//     // then arr[right] is smaller than every remaining element from left to mid.
//     // Therefore, all those remaining left-half elements form inversions with arr[right].
//     long long int merge(vector<int> &arr,int low,int high ,int mid){
//         int left = low,right=mid+1;
//         vector <int> temp;
//         long long int cnt=0;
//         while(left<=mid && right <=high){
//             if(arr[left]<=arr[right]){
//                 temp.push_back(arr[left]);
//                 left++;
//             }
//             else{
//                 temp.push_back(arr[right]);
//                 right++;
//                 cnt += (mid-left+1); // All remaining left-half elements form inversions
//             }
//         }
//         while(left<=mid){
//             temp.push_back(arr[left]);
//             left++;
//         }
//         while(right<=high){
//             temp.push_back(arr[right]);
//             right++;
//         }
//         for(int i=low;i<=high;i++){
//             arr[i]=temp[i-low]; // Copy sorted elements back into original array
//         }
//         return cnt;
//     }
//     long long int mergeSort(vector<int> &arr,int low,int high){
//         long long int cnt=0;
//         if(low>=high) return cnt; // Single element has no inversion
//         int mid=(low+high)/2;
//         cnt += mergeSort(arr,low,mid); // Count inversions in left half
//         cnt += mergeSort(arr,mid+1,high); // Count inversions in right half
//         cnt += merge(arr,low,high,mid); // Count cross inversions during merging
//         return cnt;
//     }
//     long long int numberOfInversions(vector<int> nums) {
//         long long int cnt=mergeSort(nums,0,nums.size()-1);
//         return cnt;
//     }
// };

// 9) REVERSE PAIRS
// class Solution {
// public:
//     // Main Logic: Use merge sort. After sorting both halves, count reverse pairs
//     // (i,j) where i is in the left half, j is in the right half and arr[i] > 2*arr[j].
//     // Because both halves are sorted, use a moving right pointer to count all valid
//     // pairs efficiently, then merge the two halves.
//     int merge(vector<int> &arr,int low,int high ,int mid){
//         int left = low,right=mid+1;
//         vector <int> temp;
//         int cnt=0;
//         while(left<=mid && right <=high){
//             if(arr[left]<=arr[right]){
//                 temp.push_back(arr[left]);
//                 left++;
//             }
//             else{
//                 temp.push_back(arr[right]);
//                 right++;
//                 // if(arr[left]>2*arr[right]) cnt=mid-left+1; logic is wrong as ==> Our merge loop is designed around: arr[left] <= arr[right] ; Which is the ordinary sorting comparison.
//                 // it is only checking one left element for each right element
//                 //arr[left] <= arr[right]
//                 //which is the ordinary sorting comparison
//             }
//         }
//         while(left<=mid){
//             temp.push_back(arr[left]);
//             left++;
//         }
//         while(right<=high){
//             temp.push_back(arr[right]);
//             right++;
//         }
//         for(int i=low;i<=high;i++){
//             arr[i]=temp[i-low];
//         }
//         return cnt;
//     }
//     int countPair(vector<int> &arr,int low,int mid,int high){
//         int cnt=0;
//         int right =mid+1;
//         for(int i=low;i<=mid;i++){
//             while(right<=high && arr[i]>2LL*arr[right]) right++; // Count all right-half elements satisfying the condition
//             cnt += right-(mid+1); // Number of valid right elements for current i
//         }
//         return cnt;
//     }
//     int mergeSort(vector<int> &arr,int low,int high){
//         int cnt=0;
//         if(low>=high) return cnt; // One element cannot form a pair
//         int mid=(low+high)/2;
//         cnt += mergeSort(arr,low,mid); // Count reverse pairs in left half
//         cnt += mergeSort(arr,mid+1,high); // Count reverse pairs in right half
//         cnt += countPair(arr,low,mid,high);// this could be added in merge function as well but due code readability we use it as different function
//         merge(arr,low,high,mid); // Merge both sorted halves
//         return cnt;
//     }
//     int reversePairs(vector<int>& nums) {
//         return mergeSort(nums,0,nums.size()-1);
//     }
// };
