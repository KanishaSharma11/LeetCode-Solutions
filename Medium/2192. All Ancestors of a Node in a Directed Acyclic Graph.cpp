class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            inDegree[v]++;
        }

        vector<set<int>> ancestors(n);

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v: adj[u]){
                ancestors[v].insert(ancestors[u].begin(), ancestors[u].end());
                ancestors[v].insert(u);

                if(--inDegree[v] == 0){
                    q.push(v);
                }
            }
        }

        vector<vector<int>> result(n);
        for(int i = 0; i < n; i++){
            result[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }

        return result;
    }
};
