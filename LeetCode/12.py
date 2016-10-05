class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """

        def cal(n, a, b, c):
            n = int(n)
            if n == 0:
                return ""
            elif n == 1:
                return a
            elif n == 2:
                return a * 2
            elif n == 3:
                return a * 3
            elif n == 4:
                return a + b
            elif n == 5:
                return b
            elif n == 6:
                return b + a
            elif n == 7:
                return b + a * 2
            elif n == 8:
                return b + a * 3
            elif n == 9:
                return a + c

        num = str(num)
        ans = ""
        if len(num) == 4:
            ans += cal(num[0], "M", "", "")
            ans += cal(num[1], "C", "D", "M")
            ans += cal(num[2], "X", "L", "C")
            ans += cal(num[3], "I", "V", "X")
        elif len(num) == 3:
            ans += cal(num[0], "C", "D", "M")
            ans += cal(num[1], "X", "L", "C")
            ans += cal(num[2], "I", "V", "X")
        elif len(num) == 2:
            ans += cal(num[0], "X", "L", "C")
            ans += cal(num[1], "I", "V", "X")
        else:
            ans += cal(num[0], "I", "V", "X")
        return ans