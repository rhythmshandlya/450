#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

using namespace std;
/*
9 9
0 1
0 4
1 3
4 5
5 3
1 2
3 2
6 7
7 8
*/

void breadth_first_search(vector<int> list[], int v, int n = 0)
{
    vector<bool> visited(v, false);

    // For a disconnected graph!
    for (int j = n, k = 0; k < v; j++, k++)
    {
        j = j % v;
        if (!visited[j])
        {
            queue<int> q;
            q.push(j);
            visited[j] = true;
            while (!q.empty())
            {
                int node = q.front();
                cout << node << " ";
                q.pop();
                for (auto &i : list[node])
                {
                    if (!visited[i])
                    {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
    }
}

void __dfs(vector<int> list[], vector<bool> &visited, int v, int node = 0)
{
    if (!visited[node])
    {
        visited[node] = true;
        for (int i : list[node])
        {
            if (!visited[i])
            {
                __dfs(list, visited, v, i);
            }
        }
    }
    cout << node << " ";
}

void depth_first_search(vector<int> list[], int v, int node = 0)
{
    vector<bool> visited(v, false);
    for (int i = node; i < v + node; i++)
    {
        if (!visited[i % v])
        {
            __dfs(list, visited, v, i % v);
            visited[i % v] = true;
        }
    }
}

// Cycle detection using DFS
bool _hc(vector<int> list[], vector<bool> visited, int parent, int node)
{
    visited[node] = true;
    for (int i : list[node])
    {
        if (visited[i])
        {
            if (i != parent)
            {
                return true;
            }
        }
        else
        {
            if (_hc(list, visited, node, i))
                return true;
        }
    }
    return false;
}

bool has_cycle(vector<int> list[], int v)
{
    vector<bool> visited(v, false);

    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && _hc(list, visited, -1, i))
            return true;
    }
    return false;
}

// Cycle detection using BFS
bool detect_cycle_bfs(vector<int> list[], int v)
{
    vector<bool> visited(v, false);

    for (int j = 0; j < v; j++)
    {
        if (!visited[j])
        {
            queue<pair<int, int>> q;
            //{Node,Parent}
            q.push({j, -1});
            visited[j] = true;

            while (!q.empty())
            {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();
                for (auto &i : list[node])
                {
                    if (!visited[i])
                    {
                        q.push({i, node});
                        visited[i] = true;
                    }
                    else
                    {
                        if (i != parent)
                            return true;
                    }
                }
            }
        }
    }
    return false;
}

bool is_bipartite(vector<int> list[], int v)
{
    vector<short> visited(v, -1);
    queue<int> q;
    q.push(0);
    visited[0] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i : list[node])
        {
            if (visited[i] != -1)
            {
                if (visited[i] == visited[node])
                    return false;
            }
            else
            {
                q.push(i);
                visited[i] = !visited[node];
            }
        }
    }
    return true;
}

int shortest_path_bfs(vector<int> list[], int v, int start)
{
    queue<int> q;
    vector<int> path(v, INT_MAX);
    q.push(start);
    path[start] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i : list[node])
        {
            if (path[i] > path[node] + 1)
            {
                path[i] = path[node] + 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    // Adjecency List
    vector<int> list[v + 1];
    // Adjecency Matrix
    vector<vector<bool>> matrix(v, vector<bool>(v, false));

    // Taking Input
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        // v1 and v2 have an edge!
        cin >> v1 >> v2;
        if (v1 < v && v2 < v && v1 >= 0 && v2 >= 0)
        {
            matrix[v1][v2] = true;
            matrix[v2][v1] = true;
            list[v1].push_back(v2);
            list[v2].push_back(v1);
        }
        else
        {
            cout << "Out of range provided!\n";
            --i;
        }
    }

    return 0;
}