# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def solve(self, root):
        inc, dec = 0, 0
        if root.left : 
            linc, ldec = self.solve(root.left)
            if root.val == root.left.val + 1 : 
                inc = max(inc, linc + 1)
            if root.val == root.left.val - 1 :
                dec = max(dec, ldec + 1)
            
        if root.right : 
            rinc, rdec = self.solve(root.right)
            if root.val == root.right.val + 1 : 
                inc = max(inc, rinc + 1)
            if root.val == root.right.val - 1 :
                dec = max(dec, rdec + 1)
        
        self.ans = max(self.ans, inc + dec + 1)
        return inc, dec
        
    
    def longestConsecutive(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ans = 0
        if root : self.solve(root)
        return self.ans
        
