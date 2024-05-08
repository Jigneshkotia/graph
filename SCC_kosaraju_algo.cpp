#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<list>

using namespace std;

class graph{
    public:
    
    void dfs(int node, unordered_map<int,bool> &visited,unordered_map<int,list<int> > &adj,stack<int> &s ){
        visited[node]=true;
        for(auto nbr:adj[node]){
            if(!visited[nbr]){
            dfs(nbr,visited,adj,s);
            }
        }
        s.push(node);
    }
    
    void newdfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int> > &transpose ){
        visited[node]=true;
        for(auto nbr:transpose[node]){
            if(!visited[nbr]){
                newdfs(nbr,visited,transpose);
            }
        }
    }
    int stronglyConnectedComponent(int v , vector<vector<int> > &edges){
        unordered_map<int,list<int> > adj;
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }

        //topo sort
        stack<int> s;
        unordered_map<int,bool> visited;
        for(int i=0; i<v;i++){
            if(!visited[i]){
                dfs(i, visited, adj, s);
            }
        }
       
        //creating a transpose graph
        unordered_map<int, list<int> > transpose;
        for(int i=0; i<v;i++){
            visited[i]=0;
            for(auto nbr:adj[i]){
                transpose[nbr].push_back(i);
            }
        }
        
        //dfs call using above ordering
        int count =0;
        while (!s.empty())
        {
            int top = s.top();
            s.pop();

            if(!visited[top]){
                count ++;
                newdfs(top,visited, transpose);
            }
        }
        return count;

    }
    
    
};