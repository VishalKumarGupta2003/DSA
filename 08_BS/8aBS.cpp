

#include <bits/stdc++.h>
using namespace std;

// 1) BS USING RECURSION
// int bin(vector<int> &arr,int target,int low,int high){
//     if(low>high) return -1;
//     int mid=(low+high)/2;
//     if(arr[mid] == target) return mid;
//     else if (arr[mid] < target){
//         return bin(arr,target,mid+1,high);
//     }
//     else return bin(arr,target,low,mid-1);
//     return -1;
// }
// int search(vector<int>& nums, int target) {
//     int index = bin(nums,target,0,nums.size()-1);
//     return index;
// }

// 2) LOWER BOUND
    // Main Logic: Find the first index where nums[index] >= x.
    // If nums[mid] >= x, store mid as a possible answer and search left
    // for an earlier valid index. Otherwise, search the right half.
    // int lowerBnd(vector<int> &nums, int x){
    //     sort(nums.begin(),nums.end());
    //     int ans = nums.size(); // If no valid index exists, return size of array
    //     int low=0;
    //     int high = nums.size()-1;
    //     while(low<=high){
    //         int mid = low + ((high-low)/2); // Avoids possible overflow
    //         if(nums[mid] >= x){
    //             ans =  mid; // mid can be the lower bound
    //             high=mid-1; // Search for an earlier valid index
    //         }
    //         else{
    //             low = mid+1; // nums[mid] is too small, search right
    //         }
    //     }
    //     int ans=lower_bound(nums.begin(),nums.end(),x)-nums.begin();
    //     return ans;
    // }
// 

// 3) UPPER BPOUND
// METHOD 1:-
// int upperBnd(vector<int> &nums, int x){
    //     sort(nums.begin(),nums.end());
    //     int ans = nums.size(); // If no valid index exists, return size of array
    //     int low=0;
    //     int high = nums.size()-1;
    //     while(low<=high){
    //         int mid = low + ((high-low)/2); // Avoids possible overflow
    //         if(nums[mid] > x){
    //             ans =  mid; // mid can be the lower bound
    //             high=mid-1; // Search for an earlier valid index
    //         }
    //         else{
    //             low = mid+1; // nums[mid] is too small, search right
    //         }
    //     }
    //     int ans=lower_bound(nums.begin(),nums.end(),x)-nums.begin();
    //     return ans;
    // }
// METHOD 2:-STL METHOD:
// int ans=lower_bound(nums.begin(),nums.end(),x)-nums.begin();

// 4)SEARCH INSERT POSITION
    // int searchInsert(vector<int>& nums, int target) {
    //     int n=nums.size();
    //     int ans=n;
    //     int low=0,high=n-1;
    //     while(low <= high){
    //         int mid=(low+high)/2;
    //         if(nums[mid]>=target) {
    //             high=mid-1;
    //             ans=mid;
    //         }
    //         else{
    //             low=mid+1;
    //         }
    //     }
    //     return ans;
    // }

// 5) FLOOR AND CEIL IN SORTED ARRAY
    // int findFloor(vector<int> &arr,int x){
    //     int n=arr.size();
    //     int low=0,high=n-1;
    //     int ans=-1;
    //     while(low<=high){
    //         int mid=(low+high)/2;
    //         if(arr[mid]<=x){
    //             ans=arr[mid];
    //             low=mid+1;
    //         }
    //         else{
    //             high=mid-1;
    //         }
    //     }
    //     return ans;
    // }
    // int findCeil(vector<int> &arr,int x){
    //     int n=arr.size();
    //     int low=0,high=n-1;
    //     int ans=-1;
    //     while(low<=high){
    //         int mid=(low+high)/2;
    //         if(arr[mid] >= x){
    //             ans=arr[mid];
    //             high=mid-1;
    //         }
    //         else{
    //             low=mid+1;
    //         }
    //     }
    //     return ans;
    // }
    // vector<int> getFloorAndCeil(vector<int> nums, int x) {
    //     int floor =findFloor(nums,x);
    //     int ceil=findCeil(nums,x);
    //     return {floor,ceil}; 
    // }   

// 6) FIRST AND LAST OCCURENCE 
// METHOD 1:- FIIRST OCCURENCE IS LOWERBOUND AND LAST OCCURENCE IS UPPENBOUND
// int lowerBound(vector<int> &nums, int x){
//         int ans = nums.size();
//         int low=0;
//         int high = nums.size()-1;
//         while(low<=high){
//             int mid = low + ((high-low)/2);
//             if(nums[mid] >= x){
//                 ans =  mid;
//                 high=mid-1;
//             }
//             else{
//                 low = mid+1;
//             }
//         }
//         return ans;
//     }
//     int upperBound(vector<int> &nums, int x){
//         int ans = nums.size();
//         int low=0;
//         int high = nums.size()-1;
//         while(low<=high){
//             int mid = low + ((high-low)/2);
//             if(nums[mid] > x){
//                 ans =  mid;
//                 high=mid-1;
//             }
//             else{
//                 low = mid+1;
//             }
//         }
//         return ans;
//     }
// vector<int> searchRange(vector<int>& nums, int target) {
//         int lb= lowerBound(nums,target);
//         if(lb == nums.size() || nums[lb] != target) return {-1,-1};
//         return {lb,upperBound(nums,target)-1};
//     }
// METHOD 2:- SIMPLE BINARY SEARCH
// int firstOcc(vector<int> &arr,int target){
//     int first=-1;
//     int n=arr.size();
//     int low=0;
//     int high=n-1;
//     while(low<=high){
//         int mid=(low+high)/2;
//         if(arr[mid] == target) {
//             first=mid;
//             high=mid-1;
//         }
//         else if(arr[mid]>target) high=mid-1;
//         else low=mid+1;
//     }
//     return first;
// }
// int lasttOcc(vector<int> &arr,int target){
//     int last=-1;
//     int n=arr.size();
//     int low=0;
//     int high=n-1;
//     while(low<=high){
//         int mid=(low+high)/2;
//         if(arr[mid] == target) {
//             last=mid;
//             low=mid+1;
//         }
//         else if(arr[mid]>target) high=mid-1;
//         else low=mid+1;
//     }
//     return last;
// }
// vector<int> searchRange(vector<int>& nums, int target) {
//         int first=firstOcc(nums,target);
//         if(first == -1) return {-1,-1};
//         return {first,lastOcc(nums,target)};
// }

// 7)Count occurrences in Array
// class Solution {
// public:
//     int firstOcc(vector<int> &arr,int target){
//         int first=-1;
//         int n=arr.size();
//         int low=0;
//         int high=n-1;
//         while(low<=high){
//             int mid=(low+high)/2;
//             if(arr[mid] == target) {
//                 first=mid;
//                 high=mid-1;
//             }
//             else if(arr[mid]>target) high=mid-1;
//             else low=mid+1;
//         }
//         return first;
//     }
//     int lastOcc(vector<int> &arr,int target){
//         int last=-1;
//         int n=arr.size();
//         int low=0;
//         int high=n-1;
//         while(low<=high){
//             int mid=(low+high)/2;
//             if(arr[mid] == target) {
//                 last=mid;
//                 low=mid+1;
//             }
//             else if(arr[mid]>target) high=mid-1;
//             else low=mid+1;
//         }
//             return last;
//     }  
//     pair<int,int> searchRange(vector<int>& nums, int target) {
//         int first=firstOcc(nums,target);
//         if(first == -1) return {-1,-1};
//         return {first,lastOcc(nums,target)};
//     }
//     int countOccurrences(vector<int>& arr, int target) {
//         pair<int,int> ans =searchRange(arr,target);
//         if(ans.first == -1) return 0;
//         return ans.last-ans.first+1;
//     }
// };

// 8) SEARCH IN ROTATED SORTED ARRAY
// Main Logic: In a rotated sorted array, at least one half is always sorted.
// Check which half is sorted, then determine whether x lies inside that half.
// If yes, search there; otherwise, search the other half.
// int search(vector<int>& arr, int x) {
//     int n=arr.size();
//     int low=0;int high=n-1;
//     int ans=-1;
//     while(low<=high){
//         int mid=(low+high)/2;
//         if(arr[mid] == x) return mid; // Target found
//         // LEFT HALF SORTED
//         if(arr[low]<=arr[mid]){
//             // x lies inside the sorted left half
//             if(arr[low]<=x && x<=arr[mid]) high= mid-1;
//             else low=mid+1; // x must be in the right half
//         }
//         //RIGHT HALF SORTED
//         else{
//             // x lies inside the sorted right half
//             if(arr[mid]<=x && x<=arr[high]) low=mid+1;
//             else high=mid-1; // x must be in the left half
//         }
//     }
//     return -1; // x not found
// }

// 9) SEARCH IN ROTATED SORTED ARRAY WITH DUPLICATES
// bool search(vector<int>& arr, int x) {
//         int n=arr.size();
//         int low=0;int high=n-1;
//         int ans=-1;
//         while(low<=high){
//             int mid=(low+high)/2;
//             if(arr[mid] == x) return true;
//             if(arr[mid] == arr[low] && arr[mid]== arr[high]){
//                 low++;
//                 high--;
//                 continue;
//             }
//             // LEFT HALF SORTED
//             if(arr[low]<=arr[mid]){
//                 if(arr[low]<=x && x<=arr[mid]) high= mid-1;
//                 else low=mid+1;
//             }
//             //RIGHT HALF SORTED
//             else{
//                 if(arr[mid]<=x && x<=arr[high]) low=mid+1;
//                 else high=mid-1;
//             }
//         }
//         return false;
//     }

// 10) FIND MINIMUM IN ROTATED SORTED ARRAY
        //  while(low<=high){
        //     int mid=(low+high)/2;
        //     //SEARCH SPACE IS ALREADY SORTED
        //     if(a[low]<=a[high]) {
        //         mini=min(mini,a[low]);
        //         break;
        //     }
        //     //LEFT HALF SORTED
        //     if(a[low]<=a[mid]){ // in case where low and mid is pointing to same element
        //         mini=min(a[low],mini); // if sorted then pick minimum
        //         low=mid+1;
        //     }
        //     else{
        //         mini=min(mini,a[mid]);
        //         high=mid-1;
        //     }
        // }

 // 11) FIND SINGLE ELEMRNT IN SORTED ARRAY WHERE EVERY OTHER ELEMENTS HAS DOUBLE OCCURENCES
    // Main Logic: Before the single element, pairs start at even indices; after it,
    // pairs start at odd indices. Check the pair pattern around mid to determine
    // which half contains the single element, then eliminate the other half.
    // int singleNonDuplicate(vector<int>& arr) {
    //     int n= arr.size();
    //     if(n==1) return arr[0]; // Only one element
    //     if(arr[0] != arr[1] ) return arr[0]; // Single element is at the beginning
    //     if(arr[n-1] != arr[n-2]) return arr[n-1]; // Single element is at the end
    //     int low=1;
    //     int high=n-2;
    //     while(low<=high){
    //         int mid=(low+high)/2;
    //         if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid]; // mid itself is single
    //         //LEFT HALF IS DOUBLED , SO ELIMINATE IT
    //         if((mid%2 == 0 && arr[mid]==arr[mid+1] ) || mid%2==1 && arr[mid] == arr[mid-1]){
    //             low=mid+1; // Pair pattern is correct, so single lies on the right
    //         }
    //         else{
    //             high=mid-1; // Pair pattern is broken, so single lies on the left
    //         }
    //     }
    //     return -1;  

// 12) FIND PEAK IN AN ARRAY
// Main Logic: In a peak-finding binary search, if a[mid] > a[mid-1], we are
// on an increasing slope, so a peak must exist on the right. Otherwise, we
// are on a decreasing slope, so a peak must exist on the left.
// int findPeakElement(vector<int>& a) {
//     int n=a.size();
//     if(n==1) return 0; // Only one element, so it is a peak
//     if(a[0] >a[1] ) return 0; // First element is a peak
//     if(a[n-1] > a[n-2]) return n-1; // Last element is a peak
//     int low=1;
//     int high=n-2;
//     while(low<=high){
//         int mid=(low+high)/2;
//         if(a[mid] > a[mid-1] && a[mid]> a[mid+1]) return mid; // mid is a peak
//         else if(a[mid] > a[mid-1]) low=mid+1; // Increasing slope, move right
//         else  high=mid-1; // Decreasing slope, move left
//     }
//     return -1;
// }    

