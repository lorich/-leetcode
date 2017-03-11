// 208. Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree/
// 

#define CHAR_SIZE 26
typedef struct TrieNode {
	char val;
	bool isWord;	//flag for word
    struct TrieNode* child[CHAR_SIZE];
}TrieNode;

/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
    TrieNode * node = (TrieNode*)malloc(sizeof(TrieNode));
    for (int i = 0; i < CHAR_SIZE; ++i)
    {
    	node->child[i] = NULL;
    }
    node->isWord = false;
    return node;
}

struct TrieNode* trieCreateVal(char c) {
    TrieNode * node = trieCreate();
    node->val = c;
    return node;
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* root, char* word) 
{
    int i=0;
    char cur;
    while((cur=word[i++]))
    {
    	int index = cur-'a';
    	if (NULL != root->child[index])
    	{
    		root = root->child[index];
    		continue;
    	}
    	TrieNode * node = trieCreateVal(cur);
    	root->child[index] = node;
    	root = node;
    }
    root->isWord = true;
}

/** Returns if the word is in the trie. */
bool search(struct TrieNode* root, char* word) 
{
    int i=0;
    char cur;
    while((cur=word[i++]))
    {
    	int index = cur-'a';
    	if (NULL == root->child[index])
    	{
    		return false;
    	}
    	root = root->child[index];
    }
    return root->isWord;
}

/** Returns if there is any word in the trie 
    that starts with the given prefix. */
bool startsWith(struct TrieNode* root, char* prefix) 
{
    int i=0;
    char cur;
    while((cur=prefix[i++]))
    {
    	int index = cur-'a';
    	if (NULL == root->child[index])
    	{
    		return false;
    	}
    	root = root->child[index];
    }
    return true;
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) 
{
	for (int i = 0; i < CHAR_SIZE; ++i)
    {
    	if (NULL != root->child[i])
    	{
    		trieFree(root->child[i]);
    	}
    }    
   
    free(root);
}

/*
Implement a trie with insert, search, and startsWith methods. Note: You may assume that all inputs are consist of lowercase letters a-z. Subscribe to see which companies asked this question. Show Tags Design Trie Show Similar Problems (M) Add and Search Word - Data structure design
*/
