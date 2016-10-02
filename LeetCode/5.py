class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = "#" + "#".join(s) + "#"
        pos = 0
        RL = [0] * len(s)
        ans = ""
        MaxRight = 0
        tmp = ""
        for i in range(len(s)):
            if i < MaxRight:
                RL[i] = min(RL[2*pos-i], MaxRight-i)
            else:
                RL[i] = 1
            while i - RL[i] >=0 and i+RL[i]<len(s) and s[i -RL[i]] == s[i+RL[i]]:
                tmp = s[i-RL[i]:i+RL[i]+1]
                RL[i]+=1
            if RL[i]+i>MaxRight:
                MaxRight = RL[i]+i
                pos = i
            ans = tmp if len(tmp.split("#")) >= len(ans.split("#")) else ans
        return "".join(ans.split("#"))