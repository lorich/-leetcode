class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        dicts=dict.fromkeys(list(set(s)), 0)
        for c in s:
        	dicts[c]+=1
        lists=sorted(dicts.items(), key=lambda it:it[1], reverse=True)
        res=''
        for i in lists:
        	res+=i[0]*i[1]
        return res

print(Solution().frequencySort('AbdcAaaaa'))
