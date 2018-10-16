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
        carry = 0
        outputHead = ListNode(0)
        outputNodeCurr = outputHead
        while l1.next != None or l2.next != None:
            temp = l1.next.val + l2.next.val + carry
            outputNodeCurr.next = ListNode()
            outputNodeCurr = outputNodeCurr.next
            if temp >= 10:
                carry = 1
            else:
                carry = 0
            l1 = l1.next
            l2 = l2.next
        return outputHead



        
