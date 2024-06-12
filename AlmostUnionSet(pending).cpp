#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef vector<ull> vll;

class DisjointSet{
    private:
        
    public:
        vi parent;
        vi query;
        vll sum;
        vi pos;
        int size;
        DisjointSet(int n): size(0){
            parent.resize(n+1);
            query.resize(n+1);
            sum.resize(n+1);
            pos.resize(n+1);
            for(int i=1; i<=n; i++){
                parent[i] = i;
                query[i] = -1;
                sum[i] = i;
                pos[i] = i;
            }
        }
        int find(int x){
            x = pos[x];
            if(parent[x] == x)
                return parent[x];
            parent[x] = find(parent[x]);
            return parent[x];
        }
        void Union(int x, int y){
            int savex = x;
            int savey = y;
            int parent_x = find(x);
            int parent_y = find(y);
            if (query[parent_x] < query[parent_y]){
                parent[pos[parent_y]] = parent_x;
                query[pos[parent_x]] += query[pos[parent_y]];
                sum[pos[parent_x]] += sum[pos[parent_y]];
            }
            else{
                parent[pos[parent_x]] = parent_y;
                query[pos[parent_y]] += query[pos[parent_y]];
                sum[pos[parent_y]] += sum[pos[parent_x]];
            }
        }
        void move(int x,int y){
            int savex = x;
            int savey = y;
            int x_parent = find(x);
            int y_parent = find(y);
            sum[pos[x_parent]]-=savex;
            sum[pos[y_parent]]+=savex;
            query[pos[x_parent]]++;
            query[pos[y_parent]]--;
            parent.push_back(y_parent);
            query.push_back(-1);
            sum.push_back(savex);
            pos[savex] = parent.size()-1;
        }
        bool SameSet(int x, int y){
            return find(x) == find(y);
        }
        ull SetSum(int x){
            return sum[find(x)];
        }
        int SetSize(int x){
            return -query[find(x)];
        }
};

int main(){
    int n,m;
    while((cin >> n>>m) && !cin.eof()){
        DisjointSet ds(n);
        int op,x,y;
        while(m--){
            scanf("%d",&op);
             if(op==1){
                scanf("%d %d",&x,&y);
                ds.Union(x,y);
             }else if(op==2){
                scanf("%d %d",&x,&y);
                ds.move(x,y);
             }else if(op==3){
                scanf("%d",&x);
                printf("%d %llu\n",ds.SetSize(x),ds.SetSum(x));
             }
             for(auto& i:ds.pos)
                cout<<"pos:"<<i<<" ";
            cout<<endl;
            for(auto& i:ds.sum)
                cout<<"sum:"<<i<<" ";
            cout<<endl;
            for(auto& i:ds.query)
                cout<<"query:"<<i<<" ";
            cout<<endl;
            for(auto& i:ds.parent)
                cout<<"parent:"<<i<<" ";
            cout<<endl;
        }

    }
}