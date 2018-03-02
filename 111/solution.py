# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ret = []
        stack = []
        while root or stack:
            while root:
                ret.append(root.val)
                if root.left:
                    stack.append(root.left)
                root = root.right
            if stack:
                root = stack.pop()
        return ret[::-1]   
