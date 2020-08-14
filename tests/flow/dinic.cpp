#include "../utils.hpp"

#include <utility>
#include <sstream>
#include <algorithm>
#include <queue>


using namespace std;

namespace _dinic {
    #include <graph/flow/dinic.cpp>

    /* Submit the above file and the main function below to Kattis to get AC:
     * https://open.kattis.com/problems/maxflow

    int main() {
        ios_base::sync_with_stdio(0), cin.tie(0);

        int n, m, s, t;
        cin >> n >> m >> s >> t;

        Dinic solver;
        for(int i = 0; i < m; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            solver.make_edge(u, v, c);
        }

        int f = solver.max_flow(s, t);
        vector<tuple<int, int, int>> ans;
        for(int i = 0; i < n; i++) {
            for(auto &e : solver.v[i]) {
                if(e.flow > 0)
                    ans.emplace_back(i, e.to, e.flow);
            }
        }

        cout << n << ' ' << f << ' ' << ans.size() << '\n';
        for(auto &[u, v, x] : ans) {
            cout << u << ' ' << v << ' ' << x << '\n';
        }
    }
     */
}

namespace graph {
    void dinic_test(int) {
        throw test_skipped_error("tested on Kattis problem 'maxflow'");
    }
}
