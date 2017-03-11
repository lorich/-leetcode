// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/
// 

#define ABS(a) ((a)>0?(a):(-(a)))
bool isEqual(char a, char b)
{
	return a == b || ABS(a-b) == 'a' - 'A'; 
}
bool isAlphanumeric(char c)
{
	return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
bool isPalindrome(char* s) 
{
	int i = 0, j = 0;
	while(s[j])j++;
	j--;
	while(i<j)
	{
		while(!isAlphanumeric(s[i]) && i < j)i++;
		while(!isAlphanumeric(s[j]) && i < j)j--;
		if (!isEqual(s[i], s[j]))
		{
			break;
		}
		i++, j--;
	}
	return i >= j;
}

/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases. For example, "A man, a plan, a canal: Panama" is a palindrome. "race a car" is not a palindrome. Note: Have you consider that the string might be empty? This is a good question to ask during an interview. For the purpose of this problem, we define empty string as valid palindrome. Subscribe to see which companies asked this question. Show Tags Two Pointers String Show Similar Problems (E) Palindrome Linked List
*/
