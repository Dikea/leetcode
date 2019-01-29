# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if len(preorder) == 0:
            return None
        
        val = preorder[0]
        idx = inorder.index(val)
        left_preorder = preorder[1: 1+idx]
        left_inorder = inorder[:idx]
        right_preorder = preorder[1+idx:]
        right_inorder = inorder[idx+1:]
        
        node = TreeNode(val)
        node.left = self.buildTree(left_preorder, left_inorder)
        node.right = self.buildTree(right_preorder, right_inorder)
        return node
