import java.util.ArrayList;

/*
 * @lc app=leetcode.cn id=4 lang=java
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        ArrayList<Integer> list=mergeSort(nums1, nums2);
        return list.size()%2==0?
        ((double)list.get(list.size()/2)+(double)list.get(list.size()/2-1))/2
        :(double)list.get(list.size()/2);

    }

    public ArrayList<Integer> mergeSort(int[] nums1, int[] nums2) {
        ArrayList<Integer> ar = new ArrayList<>();
        int i = 0, j = 0;
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] < nums2[j]) {
                ar.add(nums1[i]);
                i++;
            } else {
                ar.add(nums2[j]);
                j++;
            }
        }
        int[] temp = i < nums1.length ? nums1 : nums2;
        int l = i < nums1.length ? i : j;
        while(l<temp.length){
            ar.add(temp[l]);
            l++;
        }

        return ar;

    }

}
// @lc code=end
