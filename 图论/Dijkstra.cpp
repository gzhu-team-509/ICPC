#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;
int n, m, s, t;
int path[220][220];
int dis[220];
bool vis[220];

void dijkstra()
{
	memset(dis, 0x3F, sizeof(dis));
	memset(vis, false, sizeof(vis));
	dis[s] = 0;
	
	for (int i = 0; i < n && !vis[t]; ++i)
	{
		int marker = s, amin = INF;
		for (int j = 0; j < n; ++j) if (!vis[j])
		{
			if (dis[j] < amin) {
				marker = j;
				amin = dis[j];
			}
		}
		vis[marker] = true;
		for (int j = 0; j < n; ++j) if (!vis[j])
			dis[j] = min(dis[j], dis[marker] + path[marker][j]);
	}
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(path, 0x3F, sizeof(path));
		for (int i = 0; i < n; ++i)
			path[i][i] = 0;
		
		while (m--)
		{
			int a, b, x; scanf("%d%d%d", &a, &b, &x);
			path[a][b] = min(path[a][b], x);
			path[b][a] = min(path[b][a], x);
		}
		scanf("%d%d", &s, &t);
		
		dijkstra();
		dis[t] == INF ? printf("-1\n") : printf("%d\n", dis[t]);
	}
}

