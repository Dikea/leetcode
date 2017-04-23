# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findTilt(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ans = 0
        def findSum(root):
            if not root : return 0
            left = findSum(root.left);
            right = findSum(root.right);
            self.ans += abs(left - right);
            # print left, right
            return left + right + root.val
        
        findSum(root)
        return self.ans
        
        
        
        
