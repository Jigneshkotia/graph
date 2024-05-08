#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;

class graph
{
public:
    unordered_map<int, list<int> > adj;

    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void bfs(unordered_map<int, list<int> > &adj,
             unordered_map<int, bool> &visited,
             vector<int> &ans, int node)
    {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty())
        {
            int frontnode = q.front();
            q.pop();
            ans.push_back(frontnode);

            for (auto i : adj[frontnode])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    vector<int> BFS(int vertex, unordered_map<int, list<int> > &adj)
    {
        vector<int> ans;
        unordered_map<int, bool> visited;

        for (int i = 0; i < vertex; i++)
        {
            if (!visited[i])
            {
                bfs(adj, visited, ans, i);
            }
        }
        return ans;
    }
    
    void dfs( int node , 
              unordered_map< int , bool> &visited, 
              vector<int> &component, 
              unordered_map<int, list<int> > &adj)
    {
        component.push_back(node);
        visited[node]= true;

        for( auto i:adj[node]){
            if(!visited[i]){
                dfs(i , visited , component, adj);
            }
        }
    }

    vector <vector<int> > DFS (int v , int e , unordered_map<int, list<int> > adj ){
        vector < vector<int> > ans;
        unordered_map< int , bool> visited;
        for ( int i=0; i < v ; i++){
            if(!visited[i]){
                vector<int> component;
                dfs(i , visited , component , adj );
                ans.push_back(component);
            }
        }return ans;
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes: " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges: " << endl;
    cin >> m;

    graph g;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b, 0);
    }

    cout << endl;
    g.printAdjList();
    vector<int> ans = g.BFS(n, g.adj);
    cout << "BFS traversal result:" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
