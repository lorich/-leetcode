// 46. Permutations
// https://leetcode.com/problems/permutations/
// 

class Solution {
public:
    void perm(vector<int> &num, size_t nIndex, vector<vector<int> >& vecRes)
    {
        if (nIndex == num.size() - 1)
        {
            vector<int> vecLine = num;
            vecRes.push_back(vecLine);
        }
        else
        {
            for (size_t i = nIndex; i < num.size(); ++i)
            {
                swap(num[i], num[nIndex]);
                perm(num, nIndex+1, vecRes);
                swap(num[i], num[nIndex]);
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > vecRes;
        perm(num, 0, vecRes);
        return vecRes;
    }
};

/*
Given a collection of distinct numbers, return all possible permutations. For example, [1,2,3] have the following permutations: 
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 Subscribe to see which companies asked this question. Show Tags Backtracking Show Similar Problems (M) Next Permutation (M) Permutations II (M) Permutation Sequence (M) Combinations
*/
