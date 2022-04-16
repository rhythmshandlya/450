#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

/*
	Graph Traversal:
		- BFS
		- DFS
*/

void bfs(vector<int> list[], int v, int e) {
	vector<bool> visited(v, false);

	for (int i = 0; i < v; ++i)
	{
		if (!visited[i])
		{
			queue<int> q;

			q.push(i);
			visited[i] = true;

			while (!q.empty()) {
				int node = q.front();
				q.pop();
				cout << node << " ";
				for (int i : list[node]) {
					if (!visited[i]) {
						q.push(i);
						visited[i] = true;
					}
				}
			}
		}
	}
}


void __dfs(vector<int> list[], vector<bool> &visited , int node) {
	visited[node] = true;
	cout << node << " ";
	for (int i : list[node]) {
		if (!visited[i]) {
			__dfs(list, visited, i);
		}
	}
}

void dfs(vector<int> list[], int v, int e) {
	vector<bool> visited(v, false);

	for (int i = 0; i < v; ++i)
	{
		if (!visited[i])
			__dfs(list, visited, i);
	}
}

/*
	Cycle Detection:
		- Undirected Graph
			-BFS
			-DFS
		- Directed Graph
			-DFS
			-BFS
				-Topological Sorting
*/

bool has_cycle_bfs(vector<int> list[], int v, int e) {
	vector<bool> visited(v, false);

	for (int i = 0; i < v; ++i)
	{
		if (!visited[i])
		{
			queue<pair<int, int>> q;

			q.push({i, -1});
			visited[i] = true;

			while (!q.empty()) {
				int node = q.front().first;
				int parent = q.front().second;
				q.pop();
				for (int i : list[node]) {
					if (!visited[i]) {
						q.push({i, node});
						visited[i] = true;
					}
					else {
						if (i != parent) {
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

bool __has_cycle_dfs(vector<int> list[], vector<bool> &visited , int node, int parent) {
	visited[node] = true;
	for (int i : list[node]) {
		if (!visited[i]) {
			return __has_cycle_dfs(list, visited, i, node);
		} else {
			if (i != parent) {
				return true;
			}
		}
	}
	return true;
}

bool has_cycle_dfs(vector<int> list[], int v, int e) {
	vector<bool> visited(v, false);

	for (int i = 0; i < v; ++i)
	{
		if (!visited[i] && __has_cycle_dfs(list, visited, i, -1))
			return true;
	}
	return false;
}

bool __has_cycle_directed_dfs(vector<int> list[], vector<bool> &visited, vector<bool> &currentVisit  , int node) {
	visited[node] = true;
	currentVisit[node] = true;

	for (int i : list[node])
	{
		if (!visited[i]) {
			return __has_cycle_directed_dfs(list, visited, currentVisit, i);
		} else if (currentVisit[i])
		{
			return true;
		}
	}
	currentVisit[node] = false;
	return false;
}

bool has_cycle_directed_dfs(vector<int> list[], int v, int e) {
	vector<bool> visited(v, false);
	vector<bool> currentVisit(v, false);
	for (int i = 0; i < v; ++i)
	{
		if (!visited[i] && __has_cycle_directed_dfs(list, visited, currentVisit, i))
			return true;
	}
	return false;
}

//TopoSort with DFS is easy, just maintain a stack when DFS call is over!
// TOPO Sort BFS
vector<int> topo_sort_bfs(vector<int> list[], int v, int e) {
	//STEP 1: calculate in-degree of every node;
	vector<int> indegree(v, 0);
	vector<int> ans;
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < list[i].size(); j++) {
			indegree[list[i][j]]++;
		}
	}
	//STEP 2: calculate in-degree=0;
	queue<int> q;
	for (int i = 0; i < v; i++) {
		if (!indegree[i]) {
			q.push(i);
		}
	}

	//STEP 3
	while (!q.empty()) {
		int node = q.front();
		ans.push_back(node);
		q.pop();
		for (int i : list[node]) {
			if (!(--indegree[i])) {
				q.push(i);
			}
		}
	}
	return ans;
}


bool has_cycle_directed_bfs(vector<int> list[], int v, int e) {
	//STEP 1: calculate in-degree of every node;
	vector<int> indegree(v, 0);
	int ans = 0;
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < list[i].size(); j++) {
			indegree[list[i][j]]++;
		}
	}
	//STEP 2: calculate in-degree=0;
	queue<int> q;
	for (int i = 0; i < v; i++) {
		if (!indegree[i]) {
			q.push(i);
		}
	}

	//STEP 3
	while (!q.empty()) {
		int node = q.front();
		ans++;
		q.pop();
		for (int i : list[node]) {
			if (!(--indegree[i])) {
				q.push(i);
			}
		}
	}
	return ans != v;
}

/*
	Shortest Path
		-UnWeighted/UnitWeighted Directed Graph.
		-Weighted Directed Graph.
		-Weighted Directed Acyclic Graph(DAG).
*/


void shortest_path_unweighted_undirected(vector<int> list[], int v, int e) {
	vector<bool> visited(v, false);
	vector<int> distance(v, INT_MAX);

	queue<int> q;

	q.push(0);
	distance[0] = 0;
	visited[0] = true;

	while (!q.empty()) {
		int node = q.front();
		int dist = distance[node];
		q.pop();

		for (int i : list[node]) {
			if (dist + 1 < distance[i]) {
				distance[i] = dist + 1;
				q.push(i);
			}

		}
	}

	for (int i : distance) cout << i << " ";
}


void shortest_path_directed_asyclic(vector<int> list[], int v, int e) {

	vector<bool> visited(v, false);
	vector<int> distance(v, INT_MAX);

	vector<int> topo = topo_sort_bfs(list, v, e);
	int it = 0;
	distance[topo[it]] = 0;
	while (it < topo.size()) {
		int node = topo[it++];
		int dist = distance[node];

		if (dist != INT_MAX) {
			for (int i : list[node]) {
				if (dist + 1 < distance[i]) { //+ 1 or + i.wt ;)

					distance[i] = dist + 1;
				}
			}
		}

	}

	for (int i : distance) cout << i << " ";
}

void shortest_path_weighted_undirected(vector<pair<int, int>> list[], int v, int e) {
	vector<int> distance(v, INT_MAX);
	priority_queue<pair<int, int>> q;
	//q.first -> distance, q.second -> edge

	q.push({0, 0});
	distance[0] = 0;

	while (!q.empty()) {
		int node = q.top().second;
		int dist = q.top().first;
		q.pop();
		for (auto i : list[node]) {
			if (dist + i.second < distance[i.first]) {
				distance[i.first] = dist + i.second;
				q.push({distance[i.first], i.first});
			}
		}

	}
	for (int i : distance) cout << i << " ";
}

/*
	Minimum Spanning Trees:
		-Prims Algorithm
		-Kruskal's Algorithm
*/


// Brutal Implementation!
void prims(vector<pair<int, int>> list[], int v, int e) {

	vector<int> parent(v, -1);
	vector<int> key(v, INT_MAX); key[0] = 0;
	vector<bool> isMst(v, false);

	for (int i = 0; i < v - 1; ++i)
	{
		int mn = INT_MAX, u;
		for (int j = 0; j < v; j++) {
			if (!isMst[j] && key[j] < mn)
				mn = key[j], u = j;
		}
		isMst[u] = true;

		for (auto i : list[u]) {
			int v = i.first;
			int weight = i.second;
			if (!isMst[v] && weight < key[v]) {
				key[v] = weight;
				parent[v] = u;
			}
		}
	}
	for (int i : parent) cout << i << " ";
}


class DisjSet {
	int *rank, *parent, n;

public:
	DisjSet(int n)
	{
		rank = new int[n];
		parent = new int[n];
		this->n = n;
		makeSet();
	}

	void makeSet()
	{
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int find(int x)
	{
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void unionOf(int x, int y)
	{
		int u = find(x);
		int v = find(y);

		if (rank[u] < rank[v]) {
			parent[u] = v;
		}
		else if (rank[u] > rank[v]) {
			parent[v] = u;
		}
		else {
			parent[v] = u;
			rank[u]++;
		}
	}
};

int main() {
	// v is number of vertex, e is number of edge
	int v, e;
	cin >> v >> e;

	//Adjacency Matrix
	//vector<vector<bool>> matrix(v, vector<bool>(v, 0));
	//vector<vector<int>> matrix(v, vector<int>(v, 0));

	//Adjacency List
	//vector<int> list[v];

	// If the graph was weighted
	// vector<pair<int, int>> list[v + 1];

	// for (int i = 0; i < e; i++) {
	// 	int e1, e2;
	// 	cin >> e1 >> e2;
	// 	list[e1].push_back(e2);
	// 	list[e2].push_back(e1);
	// 	matrix[e1][e2] = true;
	// 	matrix[e2][e1] = true;
	// }
	// For udirected graph

	// for (int i = 0; i < e; i++) {
	// 	int e1, e2;
	// 	cin >> e1 >> e2;
	// 	list[e1].push_back(e2);
	// 	matrix[e1][e2] = true;
	// }

	// Weighted Graph

	vector<pair<int, int>> list[v];
	for (int i = 0; i < e; i++) {
		int e1, e2, wt;
		cin >> e1 >> e2 >> wt;
		list[e1].push_back({e2, wt});
		list[e2].push_back({e1, wt});
	}
	prims(list, v, e);
	return 0;
}