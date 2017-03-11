// 151. Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string/
// 

void deleteRedundantSpace(char *s, int *len)
{
	int i=0, j=0;
	while(s[j])
	{
		while(' ' == s[j])j++;
		while(s[j] && ' ' != s[j])
		{
			s[i++] = s[j++];
		}
		s[i++] = s[j];
	}
	if (i > 2 && ' ' == s[i-2])
	{
		s[i-2]=0;
		i--;
	}
	*len=i-1;
}

void reverseWord(char *s, int start, int end)
{
	while(start < end)
	{
		char temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++, end--;
	}
}

void reverseWords(char *s) 
{
	int len=0;
    deleteRedundantSpace(s, &len);
    reverseWord(s, 0, len-1);
    int i=0, j=0;
    while(j<len)
    {
    	while(' ' == s[i])i++;
    	j=i;
    	while(s[j] && ' ' != s[j])j++;
    	reverseWord(s, i, j-1);
    	i=j;
    }
}

/*
Given an input string, reverse the string word by word. For example, Given s = "the sky is blue", return "blue is sky the". Update (2015-02-12): For C programmers: Try to solve it in-place in O(1) space. click to show clarification. Clarification: What constitutes a word? A sequence of non-space characters constitutes a word. Could the input string contain leading or trailing spaces? Yes. However, your reversed string should not contain leading or trailing spaces. How about multiple spaces between two words? Reduce them to a single space in the reversed string. Subscribe to see which companies asked this question. Show Tags String Show Similar Problems (M) Reverse Words in a String II
*/
