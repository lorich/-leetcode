// 205. Isomorphic Strings
// https://leetcode.com/problems/isomorphic-strings/
// 

#define MAP_SIZE 260
typedef struct _charMap
{
	int curIndex;
	int map[MAP_SIZE];
}charMap;

int getCharMapping(char c, charMap* cm)
{
	if (cm->map[(int)c])
	{
		return cm->map[(int)c];
	}
	else
	{
		cm->curIndex++;
		cm->map[(int)c] = cm->curIndex;
		return cm->curIndex;
	}
}

bool isIsomorphic(char* s, char* t) 
{
	int i = 0;
	charMap * sCharMap = (charMap*)malloc(sizeof(charMap));
	charMap * tCharMap = (charMap*)malloc(sizeof(charMap));
	sCharMap->curIndex = tCharMap->curIndex = 0;
	memset(sCharMap->map, 0, MAP_SIZE*sizeof(int));
	memset(tCharMap->map, 0, MAP_SIZE*sizeof(int));
	while(s[i] && t[i])
	{
		if (getCharMapping(s[i], sCharMap) != getCharMapping(t[i], tCharMap))
		{
			return false;
		}
		i++;
	}
	return true;
}

/*
Given two strings s and t, determine if they are isomorphic. Two strings are isomorphic if the characters in s can be replaced to get t. All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself. For example, Given "egg", "add", return true. Given "foo", "bar", return false. Given "paper", "title", return true. Note: You may assume both s and t have the same length. Subscribe to see which companies asked this question. Show Tags Hash Table Show Similar Problems (E) Word Pattern
*/
