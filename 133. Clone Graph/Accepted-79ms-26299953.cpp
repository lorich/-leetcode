// 133. Clone Graph
// https://leetcode.com/problems/clone-graph/
// 

class Solution {
public:
	unordered_map<int, UndirectedGraphNode*> mapGraph;
	UndirectedGraphNode* clontIt(int iLabel)
	{
		UndirectedGraphNode* node = new UndirectedGraphNode(iLabel);
		mapGraph[iLabel] = node;
		return node;
	}
	UndirectedGraphNode* DfsClone(UndirectedGraphNode *node)
	{
		UndirectedGraphNode * newNode = clontIt(node->label);
		const vector<UndirectedGraphNode *>& vecNeighbors = node->neighbors;
		for (size_t i = 0; i < vecNeighbors.size(); ++i)
		{
			if (mapGraph.find(vecNeighbors[i]->label) == mapGraph.end())
			{
				DfsClone(vecNeighbors[i]);
			}
			newNode->neighbors.push_back(mapGraph[vecNeighbors[i]->label]);
		}
		return newNode;
	}
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if (node)
        {
        	return DfsClone(node);
        }
        return NULL;
    }
};

/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors. OJ's undirected graph serialization: Nodes are labeled uniquely. We use # as a separator for each node, and , as a separator for node label and each neighbor of the node. As an example, consider the serialized graph {0,1,2#1,2#2,2}. The graph has a total of three nodes, and therefore contains three parts as separated by #. First node is labeled as 0. Connect node 0 to both nodes 1 and 2. Second node is labeled as 1. Connect node 1 to node 2. Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle. Visually, the graph looks like the following: 
       1
      / \
     /   \
    0 --- 2
         / \
         \_/
 Subscribe to see which companies asked this question. Show Tags Depth-first Search Breadth-first Search Graph Show Similar Problems (M) Copy List with Random Pointer
*/
