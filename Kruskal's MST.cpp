#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>

int findParent(int node);
int mst (int nodeNumber);

std::vector<int> parent;
struct edge{
    int from, to, weight;
    edge(int u, int v, int w): from(u), to(v), weight(w){

    }
    bool operator < (const edge& p) const {
        return weight < p.weight;
    }
};

std::vector<edge> graph;

int mst (int nodeNumber){
    std::sort(graph.begin(), graph.end());
    for (int i = 1; i <= nodeNumber; i++){
        parent[i] =i;
    }
    int cost = 0;
    for (int i = 0; i < graph.size(); i++){
        int from = findParent(graph[i].from);
        int to = findParent(graph[i].to);

        if (from != to){
            parent[to] = from;
            cost += graph[i].weight;
        }
    }
    return cost;
}

int findParent(int node){
    if (parent[node] == node){
        return parent[node];
    }
    return parent[node] = findParent(parent[node]);
}

int main()
{
    int nodeCount, edgeCount;
    std::cin >> nodeCount >> edgeCount;
    parent.resize(nodeCount+1);
    for (int i = 0; i< edgeCount; i++){
        int u, v, w;
        std::cin >> u >> v >> w;
        graph.push_back(edge(u, v, w));
    }

    std::cout << mst(nodeCount) << "\n";
    return 0;
}
