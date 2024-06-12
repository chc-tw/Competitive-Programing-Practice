#include <iostream>
#include <vector>

using namespace std;

struct Edge{
    int dst;
    int weight;
};

class DirectedGraph{
private:
    int edgeNum;
    vector< vector<Edge> > adjList;
public:
    DirectedGraph(int n){
        edgeNum = 0;
        adjList.resize(n);
    }

    void addEdge(int src, int dst, int weight){
        Edge e;
        e.dst = dst;
        e.weight = weight;
        adjList[src].push_back(e);
        edgeNum++;
    }

    int getEdgeNum(){
        return edgeNum;
    }

    int getVertexNum(){
        return adjList.size();
    }

    vector<Edge> getAdjList(int src){
        return adjList[src];
    }

    void printGraph() {
        for (int u = 0; u < this->getVertexNum(); u++) {
            cout << u << "-> ";
            for (Edge& e : this->adjList[u]) {
                cout << "(" << e.dst << ", " << e.weight << ") ";
            }
            cout << endl;
        }
    }
};

int main(){
    DirectedGraph g1(4);
    g1.addEdge(0, 1, 5);
    g1.addEdge(0, 2, 3);
    g1.addEdge(1, 2, 2);
    g1.addEdge(1, 3, 6);
    g1.addEdge(2, 3, 7);
    cout << "Directed Graph:" << endl;
    g1.printGraph();

}