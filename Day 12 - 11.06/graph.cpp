#include <bits/stdc++.h>
using namespace std;

class graph{
    int vertices;
    vector<vector<int>> adj_list;
    public:
        graph(int vertex):vertices(vertex){
            adj_list(v);
        }

        void addEdge(int node1, int node2,bool directed=true){ // if it is directed then we have to install only in 1 direction
            add_list[node1].push_back(node2);
            if(!directed){
                adj_list[node2].push_back(node1);
            }
        }

        void addVertext(int vertext){
            vertices++;
            adj_list[vertex]={};
        }

        void bfs(int startNode, vector<vector<int>>adj_list,vector<bool>&visited){
            queue<int>q;
            q.push(startNode);
            visited[startNode]=true;
            while(!q.empty()){
                int cur=q.front();
                q.pop();
                cout << cur << " ";
                for (auto adj:adj_list[cur]){
                    if(!visited[adj]){
                        visited[adj]=true;
                        q.push(adj);
                    }
                }
            }
        }
        
        void dfs(int currentnode,vector<vector<int>> adj_list,vector<bool>&visited){
            visited[cuurrentnode]=true;
            cout<<currentnode<< "  ";
            for (auto it:adj_list[currentnode]){
                dfs(it,adj_list,visited);
            }
        }
}