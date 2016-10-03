class Solution(object):
    def myAtoi(self, a):
        """
        :type str: a
        :rtype: int
        """

        def isempty(s):
            if len(s):
                return False
            else:
                return True

        def isvalid(s):
            if isempty(s):
                return False
            if s[0] in "+-":
                if len(s) == 1:
                    return False
                elif s[1] not in digit:
                    return False
                else:
                    return True
            elif s[0] in digit:
                return True
            else:
                return False

        digit = "0123456789"
        b = a.split(" ")
        flag = 0
        tmp = ""
        ans = ""
        great = [1, -1]
        for i in b:
            if isempty(i):
                continue
            else:
                tmp = i
                break

        if isvalid(tmp):
            if tmp[0] in "+-":
                flag = 0 if tmp[0] == "+" else 1
                tmp = tmp[1:]
            for i in tmp:
                if i in digit:
                    ans += i
                else:
                    break
            ans = int(ans) * great[flag]
            if ans >= 2147483647:
                return 2147483647
            elif ans <= -2147483648:
                return -2147483648
            else:
                return ans
        return 0
