#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DirectedGraph {
private:
    int numVertices;
    vector<vector<int>> matrix;
public:
    DirectedGraph(int n) {
        numVertices = n;
        matrix.resize(numVertices);
        for(int i = 0; i < numVertices; i++) {
            matrix[i].resize(numVertices, -1);
        }
    }

    void addEdge(int from, int to, int weight) {
        matrix[from][to] = weight;
    }

    void removeEdge(int from, int to) {
        matrix[from][to] = -1;
    }

    bool hasEdge(int from, int to) {
        return matrix[from][to] != -1;
    }

    void printGraph() {
        cout << "Graph:" << endl;
        for(int i = 0; i < numVertices; i++) {
            for(int j = 0; j < numVertices; j++) {
                if(matrix[i][j] != -1) {
                    cout << i << " -> " << j << " (weight: " << matrix[i][j] << ")" << endl;
                }
            }
        }
    }
};

int main() {
    DirectedGraph g(4);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.printGraph();
    return 0;
}