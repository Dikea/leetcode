# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        
        if len(inorder) == 0:
            return None
        
        val = postorder[-1]
        idx = inorder.index(val)
        left_inorder = inorder[:idx]
        left_postorder = postorder[:idx]
        right_inorder = inorder[idx+1:]
        right_postorder = postorder[idx:-1]
        
        node = TreeNode(val)
        node.left = self.buildTree(left_inorder, left_postorder)
        node.right = self.buildTree(right_inorder, right_postorder)
        
        return node
