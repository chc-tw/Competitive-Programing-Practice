#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

class DisjointSet{
    private:
        
    public:
        vi parent;
        vi query;
        int size;
        DisjointSet(int n): size(0){
            parent.resize(n);
            query.resize(n);
            for(int i=0; i<n; i++){
                parent[i] = i;
                query[i] = -1;
            }
        }
        int find(int x){
            if(parent[x] == x)
                return parent[x];
            parent[x] = find(parent[x]);
            return parent[x];
        }
        /* Here is iterative version of find 
        int find(int x){
            int root = x;
            while(parent[root] != root) // find the representive root
                root = parent[root];
            while(parent[x] != x){ // here is path compression
                int tmp = parent[x];
                parent[x] = root;
                x = tmp;
            }
            return root;
        }
        */
        void Union(int x, int y){
            x = find(x);
            y = find(y);
            if (query[x] < query[y]){
                parent[y] = x;
                query[x] += query[y];
            }
            else{
                parent[x] = y;
                query[y] += query[x];
            }
        }
        bool SameSet(int x, int y){
            return find(x) == find(y);
        }
        int SetSize(int x){
            return -query[find(x)];
        }
};
int main() {
    int n = 5;
    DisjointSet ds(n);

    // Test find and Union
    ds.Union(0, 1);
    ds.Union(1, 2);
    ds.Union(3, 4);
    

    // Test SameSet
    cout << ds.SameSet(0, 2) << endl; // Output: 1 (true)
    cout << ds.SameSet(0, 3) << endl; // Output: 0 (false)

    // Test SetSize
    cout << ds.SetSize(0) << endl; // Output: 3

    return 0;
}