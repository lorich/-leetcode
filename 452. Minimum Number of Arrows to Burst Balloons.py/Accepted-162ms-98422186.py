class Solution(object):
	def findMinArrowShots(self, points):
		""" 
		:type points: List[List[int]]
		:rtype: int
		"""
		shootPoint=None
		res=0
		sortPoints=sorted(points, key=lambda point:point[1])
		for p in sortPoints:
			if shootPoint != None and p[0] <= shootPoint:
				continue
			else:
				shootPoint=p[1]
				res=res+1
		return res 
