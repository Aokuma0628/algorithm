#include <stdio.h>

typedef struct Edge {
	struct Edge *next;
	int v;
} edge;

void DFS(edge* adj[], int u, int t, int flag[], int k, int cur[])
{
	int i;
	if (u == t) {
		for (i = 0; i < k; i++) printf("%d ", cur[i]);
		return;
	}
	flag[u] = 1;
	
	int w;
	edge *p;
	for (p = adj[u]; p != NULL; p = p->next) {
		w = p->v;
		if (flag[w] != 0) continue;
		cur[k] = w;
		DFS(adj, w, t, flag, k + 1, cur);
	}
	flag[u] = 0;
}

int main()
{
	int i, N, M, X, Y, u, w;
	edge *adj[200001] = {}, e[400001], *p;
	scanf("%d %d %d", &N, &X, &Y);
	for (i = 0; i < N - 1; i++) {
		scanf("%d %d", &u, &w);
		e[i*2].v = w;
		e[i*2+1].v = u;
		e[i*2].next = adj[u];
		e[i*2+1].next = adj[w];
		adj[u] = &(e[i*2]);
		adj[w] = &(e[i*2+1]);
	}
	
	int flag[200001] = {}, cur[200001];
	cur[0] = X;
	DFS(adj, X, Y, flag, 1, cur);
	fflush(stdout);
	return 0;
}