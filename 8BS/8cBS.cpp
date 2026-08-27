#include <bits/stdc++.h>
using namespace std;

// 1)Find row with maximum 1's
// class Solution {
// public:
//     int countOnes(vector<int>& mat){
//         int m=mat.size();
//         int low=0;
//         int high= m-1;
//         while(low<=high){
//             int mid=(low+high) >> 1;
//             if(mat[mid]>=1){
//                 high=mid-1;
//             }
//             else{
//                 low=mid+1;
//             }
//         }
//         return low;
//     }
//     vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
//         int n=mat.size();
//         int m=mat[0].size();
//         int cntMax=0;
//         int index=0;
//         for(int i=0; i<n;i++){
//             sort(mat[i].begin(), mat[i].end());
//             int cntOnes=m-countOnes(mat[i]);
//             if(cntOnes > cntMax){
//                 cntMax=cntOnes;
//                 index=i;
//             }
//         }
//         return {index,cntMax};
//     }
// };

// 2)Search in a 2D SORTED Matrix
// Main Logic: Treat the 2D matrix like a single sorted 1D array and apply binary search.
// Convert a 1D index mid back to matrix coordinates using row=mid/m and col=mid%m.
// bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     int n=matrix.size();
//     int m = matrix[0].size();
//     int low=0;
//     int high=(n*m)-1;
//     while(low<=high){
//         int mid= (low+high) >> 1; // Middle index in the virtual 1D array
//         int row= mid / m; // Convert 1D index to row
//         int col=mid % m; // Convert 1D index to column
//         if(matrix[row][col] == target ) return true; // Target found
//         else if(matrix[row][col] < target) low=mid+1; // Search right half
//         else high=mid-1; // Search left half
//     }
//     return false; // Target not found
// }

// 3)Search in a 2D Matrix II
// Main Logic: Start from the top-right corner. If the current element is smaller
// than target, move down because all elements to its left are even smaller.
// If it is greater than target, move left because all elements below are even greater.
// bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     int n=matrix.size();
//     int m=matrix[0].size();
//     int row=0;
//     int col=m-1;
//     while(row<n && col>=0){
//         if(matrix[row][col] == target) return true; // Target found
//         else if(matrix[row][col] < target) row++; // Move down
//         else col--; // Move left
//     }
//     return false; // Target not found
// }

// 4)Find Peak Element-II 
// class Solution {
// public:
//     // Main Logic: Binary search on columns. For each middle column, find the row
//     // having the maximum element in that column. Since this element is already
//     // greater than its upper and lower neighbors, only left and right neighbors
//     // need to be checked. If left is greater, search left; otherwise search right.
//     int maxRow(vector<vector<int>>& mat,int n,int m,int col){
//         int maxi=INT_MIN;
//         int index=-1;
//         for(int i=0;i<n;i++){
//             if(mat[i][col] > maxi){
//                 maxi=mat[i][col];
//                 index=i;
//             }
//         }
//         return index; // Row containing maximum element in the current column
//     }
//     vector<int> findPeakGrid(vector<vector<int>>& mat) {
//         int n = mat.size();
//         int m = mat[0].size();
//         int low = 0;
//         int high = m-1;
//         while(low <= high){
//             int mid = (low+high) >> 1; // Middle column
//             int row = maxRow(mat,n,m,mid); // Find maximum element's row in this column
//             int left = (mid-1 >= 0)? mat[row][mid-1] : -1; // Left neighbor
//             int right = (mid+1 < m) ? mat[row][mid+1] : -1; // Right neighbor
//             if(mat[row][mid] > left && mat[row][mid] > right){
//                 return {row,mid}; // Current element is a peak
//             }
//             else if(mat[row][mid] < left){
//                 high = mid-1; // Left neighbor is greater, search left half
//             }
//             else{
//                 low= mid+1; // Right neighbor is greater, search right half
//             }
//         }
//         return {-1,-1}; // No peak found
//     }
// };

// 5) MEDIAN OF ROW-WISE SORTED 2-D MATRIX
// class Solution {
//   public:
//   // Main Logic: Binary search the answer between the smallest first element and
//   // largest last element. For each mid, count how many elements are <= mid using
//   // upper bound in every sorted row. If count <= half, median must be larger;
//   // otherwise, search smaller.
//   int upperbound(vector<int >  & mat, int m,int target){
//         int low=0;
//         int high=m-1;
//         while(low<=high){
//             int mid= (low+high)/2;
//             if(mat[mid] > target) high=mid-1; // Find first element greater than target
//             else low= mid+1; // Current element <= target, move right
//         }
//         return low; // Number of elements <= target
//   }
//   int countSmallEqual(vector<vector<int>> &mat , int n ,int m ,int target){
//       int cnt=0;
//       for(int i=0;i<n;i++){
//           cnt += upperbound(mat[i],m,target); // Count elements <= target in each row
//       }
//       return cnt;
//   }
//     int median(vector<vector<int>> &mat) {
//         // code here
//         int high=INT_MIN;
//         int low=INT_MAX;
//         int n=mat.size();
//         int m= mat[0].size();
//         for(int i = 0; i< n ; i++){
//             high=max(high,mat[i][m-1]); // Maximum possible median
//             low=min(low,mat[i][0]); // Minimum possible median
//         }
//         int req= (n*m) /2; // Number of elements that can be <= median before the answer
//         while(low<=high){
//             int mid =(low + high) >>1; // Try current value as median
//             int smallEqual = countSmallEqual(mat,n,m,mid); // Count elements <= mid
//             if(smallEqual <= req) low=mid+1; // Not enough elements, move right
//             else high= mid-1; // Enough elements, try smaller value
//         }
//         return low; // Smallest value having more than half elements <= it
//     }
// };

