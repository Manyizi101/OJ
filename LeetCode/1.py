class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        Len = len(nums)
        for i in range(Len):
            for j in range(i+1,Len):
                if nums[i]+nums[j] == target:
                    return [i,j]