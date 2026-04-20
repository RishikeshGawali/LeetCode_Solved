//-----------------------------------------Problem Statement--------------------------------------------

/*
4. Median of Two Sorted Arrays
Hard
Topics
premium lock icon
Companies
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

*/

//-----------------------------------------Solution--------------------------------------------


class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if (A.size() > B.size()) return findMedianSortedArrays(B, A);

        int m = A.size(), n = B.size();
        int left = 0, right = m;

        while (left <= right) {
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;

            int maxLeftA = (i == 0) ? INT_MIN : A[i - 1];
            int minRightA = (i == m) ? INT_MAX : A[i];

            int maxLeftB = (j == 0) ? INT_MIN : B[j - 1];
            int minRightB = (j == n) ? INT_MAX : B[j];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if ((m + n) % 2 == 0)
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                else
                    return max(maxLeftA, maxLeftB);
            }
            else if (maxLeftA > minRightB) {
                right = i - 1;
            }
            else {
                left = i + 1;
            }
        }

        return 0.0;
    }
};