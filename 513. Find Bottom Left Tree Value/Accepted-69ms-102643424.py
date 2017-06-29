#Definition for a binary tree node.
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None

class Solution(object):
	def findBLVWithDepth(self, root, parent):
		if root == None:
			return parent.val, 1
		else:
			blleft, depthl = self.findBLVWithDepth(root.left, root)
			blright, depthr = self.findBLVWithDepth(root.right, root)
			if depthl < depthr:
				return blright, depthr+1
			else:
				return blleft, depthl+1

	def findBottomLeftValue(self, root):
		"""
		:type root: TreeNode
		:rtype: int
		"""
		return self.findBLVWithDepth(root,None)[0]
