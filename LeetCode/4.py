class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        nums1.extend(nums2)
        ans = sorted(nums1)
        l = len(ans)
        print(ans)
        if l % 2:
            return ans[(l-1)//2]
        else:
            return (ans[l//2]+ans[l//2-1])/2.0