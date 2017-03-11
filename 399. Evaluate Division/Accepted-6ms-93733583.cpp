// 399. Evaluate Division
// https://leetcode.com/problems/evaluate-division/
// 

class Solution {
private:
	// int: 解类别，类别内可计算，类别间隔离; double: 解 
	typedef pair<int, double> nodeRes;
	unordered_map<string, nodeRes> mapSolvedVar;

	// string: 依赖于map KeyVar的变量; double: 系数，dependVar=ratio * KeyVar
	typedef pair<string, double> nodeDepend;
	unordered_map<string, vector<nodeDepend> > mapUnsolvedVar;

public:
	//每回合的计算只针对这个类别做一个假设
	void calcOneRound(const int category)
	{
		string strSolved = mapUnsolvedVar.begin()->first;
		mapSolvedVar[strSolved] = nodeRes({category, 1.0});
		stack<string> stackSolved;
		stackSolved.push(strSolved);
		while(!stackSolved.empty())
		{
			strSolved = stackSolved.top();
			double dNewSolved = mapSolvedVar[strSolved].second;
			stackSolved.pop();
			auto itrUnsolved = mapUnsolvedVar.find(strSolved);
			if (itrUnsolved != mapUnsolvedVar.end())
			{
				auto vecUnsolved = itrUnsolved->second;
				for (const auto& node:vecUnsolved)
				{
					mapSolvedVar[node.first] = nodeRes({category, dNewSolved * node.second});
					stackSolved.push(node.first);
				}
				mapUnsolvedVar.erase(itrUnsolved);
			}
		}

	}
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        assert(equations.size() == values.size());
        //初始化
        for (size_t i = 0; i < equations.size(); ++i)
        {
        	const string& numerator = equations[i].first;		//分子
        	const string& denominator = equations[i].second;	//分母
        	double ratio = values[i];

        	mapUnsolvedVar[numerator].push_back(nodeDepend({denominator, 1/ratio}));
        	mapUnsolvedVar[denominator].push_back(nodeDepend({numerator, ratio}));
        }

        int category=0;
        while(! mapUnsolvedVar.empty())
        {
        	this->calcOneRound(++category);
        }

        vector<double> vecRes;
        for (const auto& query:queries)
        {
        	auto itrNumerator = mapSolvedVar.find(query.first);
        	auto itrDenominator = mapSolvedVar.find(query.second);
        	if (itrNumerator != mapSolvedVar.end() && itrDenominator != mapSolvedVar.end() 
        		&& itrNumerator->second.first == itrDenominator->second.first)
        	{
        		vecRes.push_back(itrNumerator->second.second/itrDenominator->second.second);
        	}
        	else
        	{
        		vecRes.push_back(-1.0);
        	}
        }
        return vecRes;
    }
};

/*
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0. Example: Given a / b = 2.0, b / c = 3.0. queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . return [6.0, 0.5, -1.0, 1.0, -1.0 ]. The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>. According to the example above: equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction. Subscribe to see which companies asked this question. Show Tags Graph
*/
