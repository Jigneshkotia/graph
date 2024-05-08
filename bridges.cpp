#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;


class graph{
    public:

    void dfs(int node,int parent, int timmer ,vector<int> &desc, vector<int> &low, unordered_map<int,bool> &visited, unordered_map<int , list<int> > &adj, vector<vector<int> > &result ){
        visited[node]= true;
        desc[node]= low[node] = timmer++;

        for(auto nbr:adj[node]){
            if(nbr == parent){
                continue;
            }
            else if(!visited[nbr]){
                dfs(nbr , node , timmer , desc, low, visited , adj , result);
                low[node]= min( low[node] , low[nbr]);
                if(low[nbr]>desc[node]){
                    vector<int> ans;
                    ans.push_back(node);
                    ans.push_back(nbr);
                    result.push_back(ans);
                }
            }else{
                low[node] = min (low[node], desc[nbr]);
            }
        }

    }

    vector<vector<int> > findBridges(vector<vector<int> > &edges, int v , int e){
        //adj list
        unordered_map<int, list<int> > adj;
        for(int i =0 ; i < e; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int timmer = 0;
        vector<int> desc(v);
        vector<int> low(v);
        int parent = -1 ;
        unordered_map<int,bool> visited;

        for(int i =0 ; i<v ; i++){
            desc[i]=-1;
            low[i]=-1;
        }

        vector <vector <int> > result ;
        for(int i =0 ; i<v ; i++){
            if(!visited[i]){
                dfs(i ,parent , timmer, desc, low, visited , adj, result);
            }
        }
        return result ;
    }
};