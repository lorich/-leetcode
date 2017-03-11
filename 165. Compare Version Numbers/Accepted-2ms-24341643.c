// 165. Compare Version Numbers
// https://leetcode.com/problems/compare-version-numbers/
// 

int compareVersion(char *version1, char *version2)
{
    int i=0, j=0;
    int subv1=0, subv2=0;
    while(version1[i] || version2[j])
    {
    	subv1=0, subv2=0;
    	while('.' == version1[i])i++;
    	while('.' == version2[j])j++;
    	while(version1[i] && '.' != version1[i])
    	{
    		subv1 = subv1*10 + version1[i]-'0';
    		i++;
    	}
    	while(version2[j] && '.' != version2[j])
    	{
    		subv2 = subv2*10 + version2[j]-'0';
    		j++;
    	}
    	if (subv1 > subv2)
    	{
    		return 1;
    	}
    	if (subv1 < subv2)
    	{
    		return -1;
    	}
    }
    return 0;
}

/*
Compare two version numbers version1 and version2. If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0. You may assume that the version strings are non-empty and contain only digits and the . character. The . character does not represent a decimal point and is used to separate number sequences. For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision. Here is an example of version numbers ordering: 0.1 < 1.1 < 1.2 < 13.37 Credits: Special thanks to @ts for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags String
*/
