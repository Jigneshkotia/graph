#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class graph{
    public : 

    bool detectCycleBFS_Directed(int n, vector<pair <int,int> > &edges){
        unordered_map<int , list<int> > adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i].first;
            int v = edges[i].second;

            adj[u].push_back(v);
        }
        
        vector<int> indegree(n);
        for(auto i : adj){
            for(auto j : i.second){
                indegree[j]++;
            }
        }
        queue<int> q;
        for(int i =0 ; i<n; i++){
            if(indegree[i]== 0){
                q.push(i);
            }
        }

        int count = 0 ;
        while(!q.empty()){
            int front = q.front();
            q.pop();

            count ++ ;
            
            for(auto neighbour:adj[front]){
                indegree[neighbour]--;
                if(indegree[neighbour]== 0){
                    count ++;
                }
            }
        }
        if(count == n){
            return false;
        }else{
            return true;
        }
    }
};