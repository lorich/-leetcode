// 341. Flatten Nested List Iterator
// https://leetcode.com/problems/flatten-nested-list-iterator/
// 

class NestedIterator {
public:
    vector<int> vecSeq;
    size_t nIndex;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        stack<NestedInteger> stackRun;
        for(int i=0; i<nestedList.size(); i++)
        {
            stackRun.push(nestedList[i]);
            while(!stackRun.empty())
            {
                const NestedInteger oNestedInteger = stackRun.top();
                stackRun.pop();
                if (oNestedInteger.isInteger())
                {
                    vecSeq.push_back(oNestedInteger.getInteger());
                }
                else
                {
                    const vector<NestedInteger> & vecNestedInteger =  oNestedInteger.getList();
                    for (int j = vecNestedInteger.size()-1; j >= 0; --j)
                    {
                        stackRun.push(vecNestedInteger[j]);
                    }
                }
            }
        }

        nIndex=0;
    }

    int next() {
        return this->vecSeq[nIndex++];
    }

    bool hasNext() {
        return this->nIndex < this->vecSeq.size();
    }
};

/*
Given a nested list of integers, implement an iterator to flatten it. Each element is either an integer, or a list -- whose elements may also be integers or other lists. Example 1: Given the list [[1,1],2,[1,1]], By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1]. Example 2: Given the list [1,[4,[6]]], By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6]. Subscribe to see which companies asked this question. Show Tags Stack Design Show Similar Problems (M) Flatten 2D Vector (M) Zigzag Iterator (M) Mini Parser
*/
