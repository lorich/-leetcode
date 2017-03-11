// 127. Word Ladder
// https://leetcode.com/problems/word-ladder/
// 

class Solution {
public:
	inline bool isLadder(const string& strA, const string& strB)
	{
		size_t i=0, nSize = strA.size();
		while(i < nSize && strA[i] == strB[i])i++;
		i++;
		while(i < nSize && strA[i] == strB[i])i++;
		return i == nSize;
	}
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) 
    {
    	if (beginWord == endWord)
    	{
    		return 1;
    	}
    	else if (wordDict.empty())
    	{
    		return -1;
    	}
    	vector<string*> vecDict;
    	unordered_set<string>::const_iterator itr = wordDict.begin();
    	for (; itr != wordDict.end(); itr++)
    	{
    		vecDict.push_back(new string(*itr));
    	}
    	vecDict.push_back(&endWord);
    	size_t nDictSize = vecDict.size();
        bool visit[nDictSize];
        memset(visit, 0, nDictSize);
        queue<string*> queBFS;
        queue<string*> queBFSTemp;
        queBFS.push(&beginWord);
        int iRes = 1;
        while(!queBFS.empty())
        {
        	iRes++;
        	//printf("iRes:%d\n", iRes);
        	while(!queBFS.empty())
        	{
        		string* strCur = queBFS.front();
        		queBFS.pop();
        		//printf("  strCur:%s, ", (*strCur).c_str());
        		for (size_t i = 0; i < nDictSize; ++i)
        		{
        			if (!visit[i] && isLadder(*strCur, *vecDict[i]))
        			{
        				//printf("%zu-%s, ", i, (*vecDict[i]).c_str());
        				if (i == nDictSize-1)
        				{
        					return iRes;
        				}
        				visit[i] = true;
        				queBFSTemp.push(vecDict[i]);
        			}
        		}
        		//printf("\n");
        	}
        	swap(queBFS, queBFSTemp);
        }
        return 0;
    }
};

/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that: Only one letter can be changed at a time. Each transformed word must exist in the word list. Note that beginWord is not a transformed word. For example, Given: beginWord = "hit" endWord = "cog" wordList = ["hot","dot","dog","lot","log","cog"] As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", return its length 5. Note: Return 0 if there is no such transformation sequence. All words have the same length. All words contain only lowercase alphabetic characters. You may assume no duplicates in the word list. You may assume beginWord and endWord are non-empty and are not the same. UPDATE (2017/1/20): The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes. Subscribe to see which companies asked this question.
*/
