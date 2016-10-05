class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        a = height
        rh = [a[len(a)-1]]
        ri = [len(a)-1]
        lh = [a[0]]
        li = [0]
        ans = 0
        for i in range(1,len(a)):
            if a[i] > lh[len(lh)-1]:
                lh.append(a[i])
                li.append(i)
        for i in range(len(a)-1,0,-1):
            if a[i] > rh[len(rh)-1]:
                rh.append(a[i])
                ri.append(i)
        for i in range(len(lh)):
            for j in range(len(rh)):
                if ri[j] > li[i]:
                    ans = max(ans, min(lh[i],rh[j])*(ri[j]-li[i]))
        return ans