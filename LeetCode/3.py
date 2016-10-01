class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans = len(set(s))
        while ans != 1:
            if len(s)-ans:
                for i in range(len(s)-ans+1):
                    if len(set(s[i:i+ans])) == ans:
                        return ans
            else:
                return ans
            ans -= 1
        return ans