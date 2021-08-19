#include <bits/stdc++.h>

using namespace std;

struct FlowEdge
{
    int u, v;
    long long c, f = 0;
    FlowEdge(){}
    FlowEdge(int _u,int _v,long long _c)
    {
        u = _u; v = _v; c = _c;
    }
};

struct Template_Dinic
{
    const long long flow_INF = 1e18;    
    vector<FlowEdge> Edges;
    vector<vector<int>> AdjList;
    int n, s, t, m = 0;
    vector<int> d, ptr;
    queue<int> q;

    void init(int _n,int _s,int _t)
    {
        n = _n, s = _s, t = _t;
        AdjList.resize(n + 1); 
        d.resize(n + 1);
        ptr.resize(n + 1);
    }

    void add_edge(int u,int v,long long c)
    {
        Edges.push_back(FlowEdge(u,v,c));
        Edges.push_back(FlowEdge(v,u,0)); // Set this to c if the edge is undirected
        AdjList[u].push_back(m);
        AdjList[v].push_back(m + 1);
        m += 2;
    }

    bool bfs()
    {
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i=0;i<AdjList[u].size();i++)
            {
                int id = AdjList[u][i];
                if (Edges[id].f < Edges[id].c && d[Edges[id].v] == -1)
                {
                    d[Edges[id].v] = d[u] + 1;
                    q.push(Edges[id].v);
                }
            }
        }
        return d[t] != -1;
    }

    long long dfs(int u, long long cur)
    {
        if (cur == 0) return 0;
        if (u == t) return cur;
        for (int& cid = ptr[u];cid < AdjList[u].size();cid++)
        {
            int id = AdjList[u][cid];
            int v = Edges[id].v;
            if (d[u] + 1 == d[v] && Edges[id].f < Edges[id].c)
            {
                long long nxt = dfs(v, min(cur,Edges[id].c - Edges[id].f));
                if (!nxt) continue;
                Edges[id].f += nxt;
                Edges[id ^ 1].f -= nxt;
                return nxt;
            }
        }
        return 0;
    }

    long long flow()
    {
        long long res = 0;
        while(1)
        {
            for (int i=0;i<d.size();i++) d[i] = -1;
            d[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            for (int i=0;i<ptr.size();i++) ptr[i] = 0;
            while(long long cur = dfs(s, flow_INF))
                res += cur;     
        }
        return res;
    }
}Dinic;

int n;
int a[51], b[51];

int ans[51][51];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int s = 0, t = 2 * n + 1;
	Dinic.init(2 * n + 10, s, t);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		Dinic.add_edge(s, i, a[i]);
	}	
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		Dinic.add_edge(n + i, t, b[i]);
	}	

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			Dinic.add_edge(i, n + j, 1);

	int sa = accumulate(a + 1, a + 1 + n, 0);
	int sb = accumulate(b + 1, b + 1 + n, 0);
	if (sa != sb) {
		cout << -1;
		return 0;
	}

	if (Dinic.flow() != sa) {
		cout << -1;
		return 0;
	}
	for (int e1 : Dinic.AdjList[s]) {
		int u = Dinic.Edges[e1].v;
		for (int e2 : Dinic.AdjList[u]) {
			if (Dinic.Edges[e2].f >= 1) {
				int v = Dinic.Edges[e2].v;
				ans[u][v - n] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (ans[i][j]) cout << 'X'; 
			else cout << '.';
		}
		cout << '\n';
	}	
}