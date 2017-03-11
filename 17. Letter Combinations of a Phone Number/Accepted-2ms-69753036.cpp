// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// 

class Solution {
private:
    const map<char, string> mapDict = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"},
    };
public:
    vector<string> letterCombinations(string& digits) 
    {
        vector<string> vecRes;
        if(string::npos != digits.find('0') || string::npos != digits.find('1')) return vecRes;
        auto itr=mapDict.find(digits.back());
        if (itr != mapDict.end())
        {
            digits.pop_back();
            auto vecHead = this->letterCombinations(digits);
            const auto& strDict = itr->second;
            if (vecHead.empty())
            {
                vecHead.push_back("");
            }
            for(auto str:vecHead)
            for(auto c:strDict)
            {
                vecRes.push_back(str+c);
            }
        }
        return vecRes;
    }
};

/*
Given a digit string, return all possible letter combinations that the number could represent. A mapping of digit to letters (just like on the telephone buttons) is given below. 
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 Note: Although the above answer is in lexicographical order, your answer could be in any order you want. Subscribe to see which companies asked this question. Show Tags Backtracking String Show Similar Problems (M) Generate Parentheses (M) Combination Sum (E) Binary Watch
*/
