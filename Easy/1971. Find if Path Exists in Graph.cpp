class Solution {
public:
    bool dfs(int current_node, int destination, unordered_map<int, vector<int>>& adj, unordered_set<int>& visited){
        if(current_node == destination){
            return true;
        }

        visited.insert(current_node);

        if(adj.count(current_node)){
            for(int neighbor: adj.at(current_node)){
                if(visited.find(neighbor) == visited.end()){
                    if(dfs(neighbor, destination, adj, visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination){
            return true;
        }

        unordered_map<int, vector<int>> adj;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_set<int> visited;

        return dfs(source, destination, adj, visited);
    }

};
