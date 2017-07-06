#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

class TrieNode{
public:
    bool isWord;
    TrieNode * children[26];

public:
    TrieNode(): isWord(false) 
    { 
        memset(children, 0, sizeof(children)); 
    };
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        if(words.empty()) return result; 
        auto mycomp = [](const string& str1, const string& str2){return str1.size() < str2.size();};
        sort(words.begin(), words.end(), mycomp);
        
        root = new TrieNode();
        for(auto& word: words) {
            if(dfs(word, 0, root, 0)) 
                result.push_back(word);
            else 
                trie_insert(word);
        }
        return result;
    }
    
private:
    TrieNode* root;
    
    void trie_insert(const string& word) {
        auto cur = root;
        for(char c: word) {
            if(cur->children[c-'a'] == NULL) {
                cur->children[c-'a'] = new TrieNode();;
            }
            cur = cur->children[c-'a'];
        }
        cur->isWord = true;
    }
    
    bool dfs(string& word, int pos, TrieNode* node, int nb) {
        if(pos == word.size()) {
            if(node->isWord && nb > 0) return true;
            else return false;
        }
        
        if(node->children[word[pos]-'a'] == NULL) return false;
        auto next = node->children[word[pos]-'a'];
        if(next->isWord) {
            if(dfs(word, pos+1, root, nb+1)) return true;
        }
        if(dfs(word, pos+1, next, nb)) return true;
        else return false;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<string> vIn;
    vIn.push_back("bcdefgh");
    vIn.push_back("abcdef");
    vIn.push_back("bcde");
    vIn.push_back("fgh");
    Solution so;
    cout << so.findAllConcatenatedWordsInADict(vIn)[0] << endl;
    return 0;
}