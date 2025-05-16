// Time Complexity: O(log(n))
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        // if nums1 > nums2 use a recursive call to swap 
            // nums1 is the smaller array
        if ( nums1.length > nums2.length) {
            return findMedianSortedArrays(nums2, nums1);
        }

        // store the length of each array
        int n1 = nums1.length;
        int n2 = nums2.length;

        int total = n1 + n2;
        int target = (total + 1) / 2;

        int left = 0;
        int right = n1;

        while (true) {
            // take1 is the middle index in the smaller array
            int take1 = 1 + (right - left) / 2;
            // take2 calculates the corresponding index in the larger array based on the amount of space take1 consumed on the left side from the target
            int take2 = target - take1;

            // max1 is the max value of the left side of the smaller array
            int max1 = (take1 == 0) ? Integer.MIN_VALUE : nums1[take1 - 1];
            // min1 is the min value of the right side of the smaller array
            int min1 = (take1 == n1) ? Integer.MAX_VALUE : nums1[take1];

            // max2 is the max value of the left side of the larger array
            int max2 = (take2 == 0) ? Integer.MIN_VALUE : nums2[take2 - 1];
            // min2 is the min vlaue of the right side of the larger array
            int min2 = (take2 == n2) ? Integer.MAX_VALUE : nums2[take2];
            
            // adjust the search range, finds invalid splits
            // adjusts the binary search boundaries
            if (max1 > min2) {
                right = take1 - 1;
                continue;
            }

            if (max2 > min1) {
                left = take1 + 1;
                continue;
            }

            // calculate the median value for odd number of elements.
            int medianValueOdd = Math.max(max1, max2);
            if ( total % 2 == 1) {
                return medianValueOdd;
            // add max of left side from arrays and min of right side from arrays then divide by 2.0 to recieve the median as a double
            } else { 
                return (medianValueOdd + Math.min(min1, min2)) / 2.0;
            }
        }
    }
}
