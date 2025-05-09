class TarjanSolver {
    private:
        vector<vector<int>> rev_adj;
        vector<int> post;
        vector<int> comp;
        vector<bool> visited;
        int timer = 0;
        int id = 0;

        void fill_post(int at) {
                visited[at] = true;
                for (int n : rev_adj[at]) {
                        if (!visited[n]) { fill_post(n); }
                }
                post[at] = timer++;
        }

        void find_comp(int at) {
                visited[at] = true;
                comp[at] = id;
                comp_size[id]++;
                for (int n : adj[at]) {
                        if (!visited[n]) { find_comp(n); }
                }
        }

    public:
        const vector<vector<int>> &adj;
        vector<int> comp_size;

        TarjanSolver(const vector<vector<int>> &adj)
                : adj(adj), rev_adj(adj.size()), post(adj.size()), comp(adj.size()),
                    visited(adj.size()) {
                vector<int> nodes(adj.size());
                for (int n = 0; n < adj.size(); n++) {
                        nodes[n] = n;
                        for (int next : adj[n]) { rev_adj[next].push_back(n); }
                }

                for (int n = 0; n < adj.size(); n++) {
                        if (!visited[n]) { fill_post(n); }
                }
                std::sort(nodes.begin(), nodes.end(),
                                    [&](int n1, int n2) { return post[n1] > post[n2]; });

                visited.assign(adj.size(), false);
                comp_size.clear();
                
                for (int n : nodes) {
                        if (!visited[n]) {
                                comp_size.push_back(0);
                                find_comp(n);
                                id++;
                        }
                }
        }

        int comp_num() const { return id; }
        int get_comp(int n) const { return comp[n]; }
        int get_comp_size(int comp_id) const { return comp_size[comp_id]; }
};