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
    breadth_first_search(list, v, 0);
    cout << "\n";
    depth_first_search(list, v, 8);
    return 0;
}