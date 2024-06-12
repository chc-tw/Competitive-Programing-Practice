#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

class DisjointSet{
public:
    vi query;
    vi parent;
    int size;
    DisjointSet(int size_): size(size_){
        query.resize(size_);
        parent.resize(size_);
        for(int i=0; i<size_; i++){
            parent[i] = i;
            query[i] = -1;
        }
    }
    int find(int x){
        if(parent[x] == x)
            return parent[x];
        else{
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }

    void Union(int x, int y){
        x = find(x);
        y = find(y);
        if(x==0){
            parent[y] = x;
            query[x] += query[y];
        }
        else if(y==0){
            parent[x] = y;
            query[y] += query[x];
        }
        else if(query[x] <= query[y]){
            parent[y] = x;
            query[x] += query[y];
        }
        else if(query[x] > query[y]){
            parent[x] = y;
            query[y] += query[x];
        }
    }
};

int main() {
    int N,M; cin>>N>>M;
    DisjointSet ds(N);
    while(M--){
        int x,y; cin>>x>>y;
        ds.Union(x-1,y-1);
    }
    bool flag = true;
    for(int i=0; i<N; i++){
        if(ds.find(i)!=0){
            flag = false;
            cout<<i+1<<endl;
        }
    }
    if(flag)
        cout<<"Connected"<<endl;
    // for(auto& i:ds.parent){
    //     cout<<i+1<<" ";
    // }
    return 0;
}