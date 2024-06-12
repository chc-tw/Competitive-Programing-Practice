#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector< pii> vpi;
typedef pair<int ,pii> piii;
typedef priority_queue<piii, deque<piii>, greater<piii>> pqpi;

class DisjointSet{
    public:
        vi query;
        vi parent;
        int size =0;
        int edges=0;

        DisjointSet(int size_): size(size_){
            query.resize(size_);
            parent.resize(size_);
            for(int i=0; i<size_; i++){
                parent[i] = i;
                query[i] = -1;
            }
        }
        int Find(int x){
            if(parent[x] == x)
                return x;
            parent[x] = Find(parent[x]);
            return parent[x];
        }
        void Union(int x,int y){
            x = Find(x);
            y = Find(y);
            if(query[x] < query[y]){
                parent[y] = x;
                query[x] += query[y];
            }
            else{
                parent[x] = y;
                query[y] += query[x];
            }
        }
        int SetSize(int x){
            return -query[Find(x)];
        }
        bool SameSet(int x,int y){
            return Find(x)==Find(y);
        }
};

int main(void){
    int n; cin>>n;
    vvi grid(n,vector<int>(n));
    for(int i=0; i<n;i++)
        for(int j=0; j<n; j++)
            cin>>grid[i][j];
    pqpi edges;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            edges.push({grid[i][j],make_pair(i,j)});
    int weight,x,y;
    vpi connect;
    DisjointSet us(n);
    while(!edges.empty()){
        weight = edges.top().first;
        tie(x,y) = edges.top().second;
        edges.pop();
        if(!us.SameSet(x,y)){
            us.Union(x,y);
            connect.push_back(make_pair(x,y));
        }
        if(connect.size()==n-1)
            break;
    }
    for(auto& i:connect){
        cout<<i.first+1<<" "<<i.second+1<<endl;
    }
    return 0;
}