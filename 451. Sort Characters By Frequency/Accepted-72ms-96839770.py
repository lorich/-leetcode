class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        dicts=dict.fromkeys(set(s), 0)
        for c in s:
        	dicts[c]+=1
        return ''.join([i[0]*i[1] for i in sorted(dicts.items(), key=lambda it:it[1], reverse=True)])

print(Solution().frequencySort('AbdcAaaaa'))
