#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

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
class node {
public:
	int u, v, wt;
	node(int a, int b, int c) {
		u = a;
		v = b;
		wt = c;
	}
};
int main() {
	int v, e;
	cin >> v >> e;
	vector<node> list;
	vector<pair<int, int>> mst;
	for (int i = 0; i < e; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		list.push_back(node(u, v, wt));
	}
	sort(list.begin(), list.end(), [](node a, node b) {
		return a.wt < b.wt;
	});
	DisjSet st(v);
	for (int i = 0; i < list.size(); i++) {
		if (st.find(list[i].u) != st.find(list[i].v)) {
			mst.push_back({list[i].u, list[i].v});
			st.unionOf(list[i].u, list[i].v);
		}
	}
	for (auto i : mst) cout << i.first << "-" << i.second << endl;
	return 0;
}