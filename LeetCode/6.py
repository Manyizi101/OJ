class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        ans = [""] * numRows
        if numRows == 1:
            return s
        elif numRows==2:
            for i in range(len(s)):
                ans[i%2]+=s[i]
            return "".join(ans)
        else:
            flag = 1
            cur = 0
            for i in s:
                if flag:
                    ans[cur]+=i
                    cur+=1
                    if cur == numRows:
                        flag = 0
                        cur = 0
                else:
                    ans[numRows-cur-2]+=i
                    cur+=1
                    if cur == numRows - 2:
                        flag = 1
                        cur = 0
            # print(ans)
            return "".join(ans)