#include <vector>
#include <iostream>

using namespace std;


class Solution
{
  private:
    void dfs(const vector<vector<int>> &graph, vector<int>& path, vector<vector<int>>& paths, int src, int tgt)
    {
		path.push_back(src);
		if(src == tgt)
		{
			paths.push_back(path);
			return;
		}
		for(auto i : graph[src])
		{
			dfs(graph, path, paths, i, tgt);
			path.pop_back();
		}
    }
  public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
		vector<int> path;
		vector<vector<int>> paths;
		dfs(graph, path, paths, 0, graph.size()-1);
		return paths;
    }
};

int main()
{
	vector<vector<int>> v = {{1,2,3},{3},{1},{}};
	Solution so;
	auto res = so.allPathsSourceTarget(v);
	for ( auto v:res)
	{
		for( auto i:v)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}
