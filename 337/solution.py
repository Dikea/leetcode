# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        valMap = {}
        def getMax(root) :
            if root is None : return 0
            if root in valMap : return valMap[root]
            
            val = 0
            if root.left :
                val += getMax(root.left.left) + getMax(root.left.right)
            if root.right :
                val += getMax(root.right.left) + getMax(root.right.right)
            ret = max(val + root.val, getMax(root.left) + getMax(root.right))
            valMap[root] = ret
            return ret
        
        return getMax(root)
                
                
