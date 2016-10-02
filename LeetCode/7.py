class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x>=0:
            s = str(x)
            ans = int(s[::-1])
            if ans >= pow(2,31):
                return 0
            else:
                return ans
        else:
            s = str(abs(x))
            ans = int(s[::-1])*-1
            if ans <= -1 * pow(2,31):
                return 0
            else:
                return ans