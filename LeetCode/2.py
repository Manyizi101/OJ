# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        data = []
        while True:
            tmp = ListNode(0)
            tmp.val = l1.val + l2.val
            data.append(tmp)
            if not l1.next and not l2.next:
                break
            if l1.next:
                l1 = l1.next
            else:
                l1 = ListNode(0)
            if l2.next:
                l2 = l2.next
            else:
                l2 = ListNode(0)
        data.append(ListNode(0))
        for i in range(len(data)-1):
            data[i].next = data[i+1]
            if data[i].val >= 10:
                data[i].val %= 10
                data[i+1].val += 1
        if data[-1].val == 0:
            data[-2].next = None
        return data[0]