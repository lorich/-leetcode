// 399. Evaluate Division
// https://leetcode.com/problems/evaluate-division/
// 

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations,
                                vector<double>& values, vector<pair<string, string>> query)
    {
        unordered_map<string, unordered_map<string, double>> m;
        vector<double> res;
        for (int i = 0; i < values.size(); ++i)
        {
            m[equations[i].first].insert(make_pair(equations[i].second, values[i]));
            if (values[i] != 0)
                m[equations[i].second].insert(make_pair(equations[i].first, 1 / values[i]));
        }

        unordered_set<string> s;
        for (auto i : query)
        {
            s.clear();
            res.push_back(dfs(i.first, i.second, m, s));
        }
        return res;
    }

    double dfs(const string& up, const string& down,
               unordered_map<string, unordered_map<string, double>> &m,
               unordered_set<string> &s)
    {
        if (m[up].find(down) != m[up].end()) return m[up][down];
        for (auto i : m[up])
        {
            if (s.find(i.first) == s.end())
            {
                s.insert(i.first);
                double tmp = dfs(i.first, down, m, s);
                if (abs(tmp + 1) > 1e-10) return i.second * tmp;
            }
        }
        return -1.0;
    }
};

/*
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0. Example: Given a / b = 2.0, b / c = 3.0. queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . return [6.0, 0.5, -1.0, 1.0, -1.0 ]. The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>. According to the example above: equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction. Subscribe to see which companies asked this question. Show Tags Graph
*/
