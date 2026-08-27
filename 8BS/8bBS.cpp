// REMEMBER THAT IF WE NEED TO FIND SOMETHING LIKE MINIMUM OR MAXIMUM OR KNOW THAT THE ANSWER WILL IN A KNOWN RANGE THEN USE BINARY SEARCH

#include <bits/stdc++.h>
using namespace std;

// 1) Finding Sqrt of a number using Binary Search
// int floorSqrt(int n)  {
//         int low=1,high=n;
//         int ans=-1;
//         while(low<=high){
//             long long mid=low + (high-low)/2;
//             long long value=mid*mid;
//             if(value <= n){
//                 ans=mid;
//                 low=mid+1;
//             }
//             else{
//                 high=mid-1;
//             }
//         }
//         return ans;
//     }

// 2) Find the Nth root of an Integer
// class Solution {
// public:
//     // Main Logic: Binary search for the answer. For each mid, findPow checks
//     // whether mid^N is equal to, smaller than, or greater than M. If smaller,
//     // search right; if greater, search left. Stop immediately when the product
//     // exceeds M to avoid unnecessary multiplication and overflow.
//     int findPow(int mid,int n,int m){
//         // return 1 if == M
//         // return 0 if < M
//         // return 2 >M
//         long long ans = 1;
//         for(int i=1;i<=n;i++){
//             ans=ans*mid;
//             if(ans >m) return 2; // mid^n is already greater than M
//         }
//         if(ans == m) return 1; // mid^n == M
//         return 0; // mid^n < M
//     }
//     int NthRoot(int N, int M) {
//         int low=1,high=M;
//         int ans=-1;
//         while(low<=high){
//             int mid=low+(high-low)/2; // Avoid overflow in calculating mid
//             // this might actually overflow
//             // int value =pow(mid,N);
//             int value=findPow(mid,N,M); // Safely compare mid^N with M
//             if(value==1) {
//                 return mid; // Exact Nth root found
//             }
//             if(value<1) low=mid+1; // mid^N < M, search right
//             else high=mid-1; // mid^N > M, search left
//         }
//         return -1; // No integer Nth root exists
//     }
// };

// 3) Koko eating bananas
// class Solution {
// public:
//     // Main Logic: Binary search the minimum eating speed. For each speed mid,
//     // calculate the total hours needed. If hours <= h, mid is possible, so
//     // search for a smaller speed; otherwise, increase the speed.
//     int maxFind(vector<int> &a,int n){
//         int maxi=INT_MIN;
//         for(int i=0;i<n;i++){
//             maxi=max(a[i],maxi); // Find the maximum pile
//         }
//         return maxi;
//     }
//     double hrs(vector<int> &a,int hourly,int n){
//         double hr=0;
//         for(int i=0;i<n;i++){
//             hr+=ceil((double)a[i]/(double)hourly); // Hours needed for each pile
//         }
//         return hr;
//     }
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int n=piles.size();
//         int low=1;
//         int high=maxFind(piles,n); // Maximum speed needed in the worst case
//         while(low<=high){
//             int mid=(low+high)/2; // Try current eating speed
//             double hr=hrs(piles,mid,n); // Calculate total required hours
//             if(hr<=h) high=mid-1; // Speed works, try smaller speed
//             else low=mid+1; // Speed is too slow, increase it
//         }
//         return low; // Minimum speed that satisfies h hours
//     }
// };

// 4)MINIMUM NUMBER OF DAYS TO MAKE M BOUQUESTS
// Main Logic: Binary search the minimum day on which at least m bouquets can be made.
// For a given day, count consecutive flowers that have bloomed. Every k consecutive
// bloomed flowers form one bouquet. If bouquets >= m, try an earlier day; otherwise,
// search for a later day.
// int bouquests(int day,vector<int> &arr,int flower,int n){
//     int fc=0,bc=0;
//     for(int i=0;i<n;i++){
//         if(arr[i]<=day){
//             fc+=1; // Flower has bloomed, extend the current consecutive group
//         }
//         else{
//             bc+=fc/flower; // Complete bouquets from the current consecutive group
//             fc=0; // Reset because consecutive sequence is broken
//         }
//     }
//     bc+=fc/flower; // Count bouquets from the final consecutive group
//     return bc;
// }
// int minDays(vector<int>& bloomDay, int m, int k) {
//     int n=bloomDay.size();
//     long long value =(long long) m* (long long) k; // Total flowers required
//     if(value > n) return -1; // Not enough flowers to make m bouquets
//     int maxi=INT_MIN;
//     int mini=INT_MAX;
//     for(int i=0;i<n;i++){
//         mini=min(bloomDay[i],mini); // Earliest blooming day
//         maxi=max(bloomDay[i],maxi); // Latest blooming day
//     }
//     int low=mini;
//     int high=maxi;
//     while(low<=high){
//         int mid=(low+high)/2; // Try this day
//         int bc=bouquests(mid,bloomDay, k , n); // Count bouquets possible by this day
//         if(bc >= m){
//             high=mid-1; // Enough bouquets, try to find an earlier day
//         }
//         else{
//             low=mid+1; // Not enough bouquets, need more days
//         }
//     }
//     return low; // Minimum day on which m bouquets can be made
// }

// 5) FIND THE SMALLEST DIVISOR
// Main Logic: Binary search the smallest divisor. For each divisor, calculate the sum
// of ceil(arr[i]/divisor). If the sum <= threshold, the divisor is valid, so try a
// smaller divisor; otherwise, increase the divisor.
// bool divideSum(int divisor,vector<int> &arr,int n,int threshold){
//     int sum=0;
//     for(int i=0;i<n;i++){
//         sum += (arr[i] + divisor - 1) / divisor; // Calculates ceil(arr[i]/divisor)
//     }
//     return sum <= threshold; // Check whether this divisor satisfies the threshold
// }
// int smallestDivisor(vector<int>& nums, int threshold) {
//     int maxi=INT_MIN;
//     int n= nums.size();
//     if(n > threshold) return -1;
//     for(int i=0;i<n;i++){
//         maxi=max(nums[i],maxi); // Maximum possible divisor
//     }
//     int low=1;
//     int high=maxi;
//     while(low<=high){
//         int mid=(low+high)/2; // Try current divisor
//         if(divideSum(mid,nums,n,threshold)){
//             high=mid-1; // Valid divisor, try smaller
//         }
//         else{
//             low=mid+1; // Invalid divisor, need larger divisor
//         }
//     }
//     return low; // Smallest valid divisor
// }

// 6) Capacity to Ship Packages within D Days
    // Main Logic: Binary search the minimum ship capacity. For each capacity,
    // greedily load consecutive packages until adding the next package exceeds
    // the capacity, then start a new day. If required days <= given days, the
    // capacity is valid, so search for a smaller capacity; otherwise increase it.
    // bool capacity(vector<int>& weights,long long limit, int days,int n){
    //     int dayCount=1;
    //     long long sumWt =0;
    //     for(int i=0;i<n;i++){
    //         if(sumWt + weights[i] > limit){
    //             dayCount++; // Current day cannot take this package, start next day
    //             sumWt=weights[i]; // Put current package on the new day
    //         }
    //         else{ 
    //             sumWt += weights[i]; // Add package to the current day
    //         }
    //     }
    //     return dayCount //<= days; // Check whether this capacity works
    // }
    // int shipWithinDays(vector<int>& weights, int days) {
    //     int n=weights.size();
    //     long long high=0;
    //     long long low=0;
    //     for(int i=0;i<n;i++){
    //         high+=weights[i]; // Maximum capacity = total weight of all packages
    //         low=max((long long) weights[i],low); // Minimum capacity = heaviest package
    //     }
    //     while(low<=high){
    //         long long mid=(low+high)/2; // Try current shipping capacity
    //         if(capacity(weights,mid,days,n)){
    //             high=mid-1; // Valid capacity, try smaller
    //         }
    //         else{
    //             low=mid+1; // Invalid capacity, increase it
    //         }
    //     }
    //     return low; // Minimum capacity that can ship all packages within days
    // }

// 7)Kth Missing Positive Number | Maths + Binary Search
// METHOD 1:-
// Main Logic: Start with k as the candidate missing number. Traverse the sorted array.
// If arr[i] <= k, that element occupies a position before or at k, so the kth missing
// number shifts forward by 1. Once arr[i] > k, no further element can affect the answer.
// int findMissing(vector<int> &arr,int n,int k){
//     for(int i=0;i<n;i++){
//         if(arr[i]<=k) k++;
//         else break;
//     }
//     return k;
// } 
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     sort(arr.begin(),arr.end()); // Sort the array so missing numbers can be counted in order
//     int k;
//     cin>>k;
//     int ans=findMissing(arr,n,k);
//     cout<<"The answer is :-"<<ans;
//     return 0;
// }
// METHOD 2:-
// Main Logic: For every index mid, missing numbers before arr[mid] = arr[mid]-mid-1.
// If this count is less than k, the kth missing number lies to the right; otherwise,
// it lies to the left. After binary search, high is the last index having fewer than
// k missing numbers, so the answer is k+high+1.
// int findKthPositive(vector<int>& arr, int k) {
//     int n =arr.size();
//     int low=0;
//     int high=n-1;
//     int miss=0;
//     while(low<=high){
//         int mid = (low+high)/2;
//         miss=arr[mid]-mid-1; // Number of missing positive integers before arr[mid]
//         if(miss<k) low=mid+1; // Need more missing numbers, move right
//         else{
//             high=mid-1; // Too many missing numbers, move left
//         }
//     }
//     return k+high+1; // Calculate the kth missing number
// }

// 8) AGGRESSIVE COWS
// Main Logic: Sort the stalls and try every possible minimum distance.
// For a given distance, greedily place each cow at the earliest stall that
// is at least 'dis' away from the previous cow. The largest distance for
// which k cows can be placed is the answer.
// bool isPossible(vector<int> &arr,int n,int k,int dis){ 
//     int cowCnt=1; // First cow is placed at the first stall
//     int last=0; // Index of the last stall where a cow was placed
//     for(int i=1;i<n;i++){ 
//         if(arr[i]-arr[last]>=dis){ // Current stall is far enough from last cow
//             cowCnt++; 
//             last=i; 
//         } 
//         if(cowCnt==k){ // All k cows have been placed
//             return true; 
//         } 
//     } 
//     return false; // Cannot place k cows with this distance
// } 
// int aggressiveCows(vector<int> & arr,int n,int k){ 
//     sort(arr.begin(),arr.end()); // Sort stalls to place cows greedily
//     int range=arr[n-1]-arr[0]; // Maximum possible minimum distance
//     for(int i=0;i<=range;i++){ // Try every possible distance
        // if(isPossible(arr,n,k,i)){ 
        //     continue; // Distance is possible, try a larger distance
        // } 
//         else return i-1; // First impossible distance, so previous is maximum possible
//     } 
//     return range; // All distances were possible
// }
// int main(){
//     int n,k;
//     cin>>n>>k;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++) cin>>arr[i];
//     cout<<aggressiveCows(arr,n,k);
//     return 0;
// }
//METHOD 2:-
    // Main Logic: Sort the stalls and binary search the maximum possible minimum distance.
    // For each distance, greedily place cows at the earliest possible stalls. If k cows
    // can be placed, the distance is possible, so search for a larger distance; otherwise,
    // search for a smaller distance. 'high' finally stores the maximum possible distance.
//     bool isPossible(vector<int> &arr,int n,int k,int dis){ 
//         int cowCnt=1; // First cow is placed at the first stall
//         int last=0; // Index of the last stall where a cow was placed
//         for(int i=1;i<n;i++){ 
//             if(arr[i]-arr[last]>=dis){ // Current stall is far enough from last cow
//                 cowCnt++; 
//                 last=i; 
//             } 
//             if(cowCnt==k){ // All k cows have been placed
//                 return true; 
//             } 
//         } 
//         return false; // Cannot place k cows with this distance
//     } 
//     int aggressiveCows(vector<int> &arr, int k) {
//         int n=arr.size();
//         sort(arr.begin(),arr.end()); // Sort stalls to use greedy placement
//         int low=0; // Minimum possible distance
//         int high=arr[n-1]-arr[0]; // Maximum possible distance
//         while(low<=high){
//             int mid=(low+high)/2; // Try this minimum distance
//             if(isPossible(arr,n,k,mid)){
//                 low=mid+1; // Distance works, try a larger distance
//             } 
//             else{
//                 high=mid-1; // Distance does not work, try a smaller distance
//             }
//         }
//         return high; // Maximum possible minimum distance
//     }
// };

// 9) BOOK ALLOCATION
// func(arr,pages){
//     stu=1;pageStudent=0;
//     for(i=0 to n-1){
//         if(arr[i]+pagesStudents<=pages){
//             pageStudents+=arr[i];
//         }
//         else{
//             pageStudents = arr[i];
//             stu++;
//         }
//     }
//     return stu;
// }
// int low=maximum element of array
// high=sum(array)
// for(pages=low upto high){
//     cntStudents=func(arr,pages);
//     if(cntstudents == m){
//         return pages;
//     }
// }
//METHOD 2:-
    // Main Logic: Binary search the minimum possible maximum pages.
    // For each pageLimit, allocate books contiguously to students. If the
    // required students <= m, the limit is possible, so search smaller;
    // otherwise, increase the limit. The final low is the minimum maximum pages.
//     int nStudents(vector<int> &arr, long long pageLimit,int n){
//         int stu=1;
//         long long pages=0;
//         for(int i=0;i<n;i++){
//             if(arr[i]+pages>pageLimit ){
//                 stu++; // Current student cannot take this book
//                 pages=arr[i]; // Give this book to the next student
//             }
//             else{
//                 pages+=arr[i]; // Add book to current student's allocation
//             }
//         }
//         return stu; // Number of students required for this page limit
//     }
//     int findPages(vector<int> &nums, int m)  {
//         int maxi=INT_MIN;
//         long long sum=0;
//         int n= nums.size();
//         for(int i=0;i<n;i++){
//             maxi=max(nums[i],maxi); // Minimum possible limit = largest book
//             sum+=nums[i]; // Maximum possible limit = total pages
//         }
//         int low=maxi;
//         int high=sum;
//         while(low<=high){
//             long long mid = ((long long) low + (long long) high)/2; // Try page limit
//             if(nStudents(nums,mid,n) <= m){
//                 high=mid-1; // Valid limit, try a smaller one
//             }
//             else{
//                 low=mid+1; // Too small, need a larger limit
//             }
//         }
//         return low; // Minimum possible maximum pages
//     }

//10 & 11) SPLIT ARRAY LARGEST SUM AND PAINTER'S PARTITION
// class Solution {
// public:
//     // Main Logic: Binary search the minimum possible maximum subarray sum.
//     // For each limit, greedily split the array into contiguous parts and count
//     // how many painters/subarrays are needed. If required parts <= k, the limit
//     // is possible, so search smaller; otherwise, increase the limit.
//     int nHours(vector<int>& nums, int hrsLimit,int n){
//         int nPainter=1;
//         int hrs=0;
//         for(int i=0;i<n;i++){
//             if(nums[i]+hrs>hrsLimit){
//                 nPainter++; // Current part cannot take this element, start a new part
//                 hrs = nums[i]; // Put current element in the new part
//             }
//             else{
//                 hrs+=nums[i]; // Add current element to the current part
//             }
//         }
//         return nPainter; // Number of parts required for this limit
//     }
//     int splitArray(vector<int>& nums, int k) {
//         int maxi=INT_MIN;
//         int n =nums.size();
//         long long sum=0;
//         for(int i=0;i<n;i++){
//             maxi=max(nums[i],maxi); // Minimum possible limit = largest element
//             sum+=nums[i]; // Maximum possible limit = total sum
//         }
//         long long low=maxi;
//         long long high=sum;
//         while(low<=high){
//             long long mid= (low+high)/2; // Try current maximum subarray sum
//             if(nHours(nums,mid,n) <= k){
//                 high=mid-1; // Valid limit, try a smaller limit
//             }
//             else{
//                 low=mid+1; // Too small, need a larger limit
//             }
//         }
//         return low; // Minimum possible maximum subarray sum
//     }

// 12)Minimise Maximum Distance between Gas Stations | 3 Approaches
// METHOD 1:-
// class Solution {
// public:
//     // Main Logic: Keep track of how many new gas stations are placed in each gap.
//     // For every new station, find the gap having the current maximum section length
//     // and place the station there. After placing all k stations, calculate the maximum
//     // remaining section length, which is the minimum possible maximum distance.
//     long double minimiseMaxDistance(vector<int> &arr, int k) {
//        int n = arr.size();
//        vector<int> howMany(n-1,0); // Number of new stations placed in each gap
//        for(int gasStation=1;gasStation<=k;gasStation++){
//             long double maxLen=-1;
//             int maxInd=-1;
//             for(int i=0;i<n-1;i++){
//                 long double secLen = (long double)(arr[i+1]-arr[i])/(howMany[i]+1); // Current maximum section length
//                 if(secLen > maxLen){
//                     maxLen = secLen; // Update maximum section length
//                     maxInd = i; // Store the gap with maximum section length
//                 }
//             }
//             howMany[maxInd]++; // Place a new station in the largest gap
//        }
//        long double ans=-1;
//        for(int i=0;i<n-1;i++){
//             long double secLen=(long double) (arr[i+1]-arr[i])/(long double)(howMany[i]+1); // Final section length
//             ans = max(ans,secLen); // Find the maximum final section length
//        }
//        return ans; // Minimum possible maximum distance
//     }
// };
// METHOD 2:-
// class Solution {
// public:
//     // Main Logic: Store every gap in a max-heap so the gap with the largest
//     // current section is always on top. Place each new gas station in that
//     // largest gap, update its section length, and push it back. After placing
//     // all k stations, the top of the heap is the minimum possible maximum distance.
//     long double minimiseMaxDistance(vector<int> &arr, int k) {
//        int n = arr.size();
//        vector<int> howMany(n-1,0); // Number of new stations placed in each gap
//        priority_queue <pair <long double,int>> pq; // Max-heap: {current section length, gap index}
//        for(int i=0;i<n-1;i++){
//             pq.push({arr[i+1]-arr[i] , i}); // Initially, each gap has one section
//        }
//        for(int i=1;i<=k;i++){
//             auto tp = pq.top(); // Get the gap with the largest current section
//             pq.pop();
//             int index=tp.second; // Index of the selected gap
//             howMany[index]++; // Place one new station in this gap
//             long double iniDiff = arr[index+1]-arr[index]; // Original length of the gap
//             long double newDiff = iniDiff/(long double)(howMany[index]+1); // New section length
//             pq.push({newDiff,index}); // Put updated gap back into the max-heap
//        }
//        return pq.top().first; // Largest remaining section = minimum possible maximum distance
//     }
// };
//# METHOD 3:-
// class Solution {
//   public:
//     // Main Logic: Binary search the minimum possible maximum distance.
//     // For a given distance 'dis', count how many extra stations are needed
//     // to make every gap <= dis. If required stations > k, dis is too small,
//     // so increase it; otherwise, try a smaller distance.
//     int nGasStations(long double dis,vector<int > & arr , int n){
//         int cnt=0;
//         for(int i=0;i<n-1;i++){
//             long double division = (long double)(arr[i+1]-arr[i]) / dis; // Number of sections possible in this gap
//             int nInBetween = (int)division; // Initially assume this many stations are needed
//             if(fabs(division - nInBetween) < 1e-12){ // If division is exactly an integer
//                 nInBetween--; // Exact division needs one less station between the endpoints
//             }
//             cnt+=nInBetween; // Add required stations for this gap
//         }
//         return cnt;
//     }
//     double minMaxDist(vector<int> &arr, int k) {
//         // Code here
//         int n= arr.size();
//         long double high=0.0;
//         long double low=0.0;
//         for(int i=0;i<n-1;i++){
//             high=max(high,(long double )(arr[i+1]-arr[i])); // Maximum possible distance
//         }
//         long double diff = 1e-6; // Required precision
//         while((high-low) > diff){
//             long double mid = (high + low)/ 2; // Try a maximum distance
//             int cnt = nGasStations(mid,arr,n); // Count stations required for this distance
//             if(cnt>k) {
//                 low=mid; // Too many stations needed, increase distance
//             }
//             else{
//                 high=mid; // Distance is possible, try smaller distance
//             }
//         }
//         return (double)high; // Minimum possible maximum distance
//     }
// };

// 13) Median of two Sorted Arrays of Different Sizes
// METHOD 1:- 
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int n1= nums1.size();
    //     int n2 = nums2.size();
    //     vector<int> arr3;
    //     int n= n1+n2;
    //     int i=0,j=0;
    //     while(i<n1 && j<n2){
    //         if(nums1[i]<nums2[j]) arr3.push_back(nums1[i++]);
    //         else arr3.push_back(nums2[j++]);
    //     }
    //     while(i<n1)  arr3.push_back(nums1[i++]);
    //     while(j<n2)  arr3.push_back(nums2[j++]);
    //     if(n%2 == 1) return arr3[n/2];
    //     return (double) ((double)arr3[n/2]+(double)arr3[(n/2) -1 ])/2.0;
// METHOD 2:-
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int n1= nums1.size();
//         int n2 = nums2.size();
//         int n= n1+n2;
//         int i=0,j=0;
//         int id2=n/2;
//         int id1= n/2 -1;
//         int cnt=0;
//         int inel1=-1;
//         int inel2 = -1;
//         while(i<n1 && j<n2){
//             if(nums1[i]<nums2[j]){
//                 if(cnt == id1){
//                     inel1=nums1[i];
//                 }
//                 if(cnt == id2){
//                     inel2 = nums1[i];
//                 }
//                 i++;
//                 cnt++;
//             }
//             else{
//                 if(cnt == id1){
//                     inel1=nums2[j];
//                 }
//                 if(cnt == id2){
//                     inel2 = nums2[j];
//                 }
//                 j++;
//                 cnt++;
//             }
//         }
//         while(i<n1){
//                 if(cnt == id1){
//                     inel1=nums1[i];
//                 }
//                 if(cnt == id2){
//                     inel2 = nums1[i];
//                 }
//                 i++;
//                 cnt++;
//         }
//         while(j<n2){           
//                 if(cnt == id1){
//                     inel1=nums2[j];
//                 }
//                 if(cnt == id2){
//                     inel2 = nums2[j];
//                 }
//                 j++;
//                 cnt++;
//         }
//         if(n%2 == 1) return inel2;
//         return (double) ((double)inel1+(double)inel2)/2.0;
//     }
// };
// METHOD 3:-
// Main Logic: Binary search the partition in the smaller array. We divide both sorted
// arrays into left and right parts such that the left side contains half of all elements.
// A valid partition satisfies l1<=r2 and l2<=r1. For odd total length, the median is
// max(l1,l2); for even length, it is (max(l1,l2)+min(r1,r2))/2.
// double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
//     int n1= a.size();
//     int n2 = b.size();
//     if(n1>n2) return findMedianSortedArrays(b,a); // Always binary search the smaller array
//     int n= n1+n2;
//     int low=0;
//     int high = n1;
//     int left = (n1+n2+1)/2; // Number of elements required on the left side
//     while(low<=high){
//         int mid1= (low+high)/2; // Partition position in array a
//         int mid2= left-mid1; // Remaining left elements come from array b
//         int l1=INT_MIN;
//         int l2=INT_MIN;
//         int r1=INT_MAX;
//         int r2=INT_MAX;
//         if(mid1<n1) r1=a[mid1]; // First element on right side of a
//         if(mid2<n2) r2=b[mid2]; // First element on right side of b
//         if(mid1-1>=0) l1=a[mid1-1]; // Last element on left side of a
//         if(mid2-1>=0) l2=b[mid2-1]; // Last element on left side of b
//         if(l1 <= r2 && l2 <= r1){ // Valid partition found
//             if(n%2 == 1) return max(l1,l2); // Odd: median is maximum of left side
//             else {
//                 return (double)(max(l1,l2) + min(r1,r2))/2.0; // Even: average of middle two
//             }
//         }
//         else if(l1>r2) high=mid1-1; // Too many elements from a on left, move partition left
//         else low=mid1+1; // Too few elements from a on left, move partition right
//     }
//     return 0.0;
// }

// 14) K-th element of two sorted arrays
// #include<bits/stdc++.h>
// class Solution {
//   public:
    // Main Logic: Binary search the partition in the smaller array. We need exactly
    // k elements on the left side of the partition. A valid partition satisfies
    // l1<=r2 and l2<=r1. Once the partition is valid, the kth element is max(l1,l2).
//     int kthElement(vector<int> &a, vector<int> &b, int k) {
//         // code here
//         int n1=a.size();
//         int n2= b.size();
//         if(n1> n2) return kthElement(b,a,k); // Binary search on the smaller array
//         int n= n1+ n2;
//         int low= max(0,k-n2); // Minimum elements that can be taken from a
//         int high=min(k,n1); // Maximum elements that can be taken from a
//         int left=k; // Total elements required on the left side
//         while(low<=high){
//             int mid1= (low+high) >> 1; // Elements taken from a
//             int mid2 = left-mid1; // Remaining elements taken from b
//             int l1=INT_MIN;
//             int l2=INT_MIN;
//             int r1=INT_MAX;
//             int r2=INT_MAX;
//             if(mid1<n1) r1=a[mid1]; // First element on right side of a
//             if(mid2<n2) r2=b[mid2]; // First element on right side of b
//             if(mid1-1>=0) l1=a[mid1-1]; // Last element on left side of a
//             if(mid2-1>=0) l2=b[mid2-1]; // Last element on left side of b
//             if(l1 <= r2 && l2 <= r1){ // Valid partition found
//                 return max(l1,l2); // kth element is the largest element on the left
//             }
//             else if(l1>r2) high=mid1-1; // Too many elements from a, move left
//             else low=mid1+1; // Too few elements from a, move right
//         }
//         return 0;
//     }
// };

