/*
 * MST-Kruskal.cxx
 * Implemented by: dbakti7
 * 18 June 2015
 * Reference:
 * https://en.wikipedia.org/?title=Kruskal%27s_algorithm
 * */
 
#include <cstdio>
#include <algorithm>
using namespace std;

int nodeRank[1010], parent[1010];

// struct of the edges of the graph
struct _edge {
	int first, second, dist;
} edge[1010];
bool cmp(_edge a, _edge b) {
	return a.dist < b.dist;
}

// Functions for Union-Find data structure
void makeNode(int a) {
	nodeRank[a] = 0;
	parent[a] = a;
}
int find(int a) {
	if(a != parent[a])
		parent[a] = find(parent[a]);
	return parent[a];
}
void unionNodes(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if(pa == pb)
		return;
	if(nodeRank[pa] > nodeRank[pb])
		parent[pb] = pa;
	else {
		parent[pa] = pb;
		if(nodeRank[pa] == nodeRank[pb])
			++nodeRank[pb];
	}
}

// Kruskal's algorithm
int MST(int nodes, int edges) {
	// Return the MST cost or distance
	int i, distance = 0;
	for(i=0;i<nodes;++i)
		makeNode(i);
	for(i=0;i<edges;++i) {
		if(find(edge[i].first) != find(edge[i].second)) {
			unionNodes(edge[i].first, edge[i].second);
			distance += edge[i].dist;
			printf("edge %d to edge %d with cost %d\n", 
			edge[i].first, edge[i].second, edge[i].dist);
		}
	}
	return distance;
}

int main() {
	int nodes, edges;
	scanf("%d %d", &nodes, &edges);
	for(int i = 0;i<edges;++i)
		scanf("%d %d %d", &edge[i].first, &edge[i].second, &edge[i].dist);
	sort(edge, edge+edges, cmp);
	printf("MST Distance: %d\n", MST(nodes, edges));
	return 0;
}
