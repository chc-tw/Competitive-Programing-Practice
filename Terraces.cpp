#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
typedef vector< vector<int>> vvi;

int x,y;
int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};

bool IsValid(int new_x,int new_y){
    return new_x>=0 && new_x< y && new_y>=0 && new_y<x;
}

int CheckFlat(vvi grid,vvi &vist, int i, int j){
    // cout<<"init\n";
    stack<pair<int,int>> q;
    q.push(make_pair(i,j));
    int count = 1;
    bool flat = true;
    vist[i][j] = 1;
    while(!q.empty()){
        i = q.top().first;
        j = q.top().second;
        // printf("i:%d, j:%d\n",i,j);
        q.pop();
        for(int k=0; k<4; k++){
            if(IsValid(i+di[k],j+dj[k])){
                if(grid[i][j] == grid[i+di[k]][j+dj[k]] && !vist[i+di[k]][j+dj[k]]){
                    count++;
                    vist[i+di[k]][j+dj[k]] = 1;
                    q.push(make_pair(i+di[k],j+dj[k]));
                }
                if(grid[i][j] > grid[i+di[k]][j+dj[k]]){
                    flat = false;
                }
            }
        }
    }
    return flat ? count : -count;
}

int main(void){
    cin >> x >> y;
    vvi grid(y,vector<int>(x));
    vvi vist(y,vector<int>(x,0));
    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            scanf("%d",&grid[i][j]);
        }
    }
    int ans = 0;
    int temp;
    stack<pair<int,int>> q;
    for(int k=0; k<y; k++){
        for(int w=0; w<x; w++){
            if(vist[k][w])
                 continue;
            // cout<<"init\n";
            q.push(make_pair(k,w));
            int count = 1;
            bool flat = true;
            vist[k][w] = 1;
            int i,j;
            while(!q.empty()){
                i = q.top().first;
                j = q.top().second;
                // printf("i:%d, j:%d\n",i,j);
                q.pop();
                for(int k=0; k<4; k++){
                    if(IsValid(i+di[k],j+dj[k])){
                        if(grid[i][j] == grid[i+di[k]][j+dj[k]] && !vist[i+di[k]][j+dj[k]]){
                            count++;
                            vist[i+di[k]][j+dj[k]] = 1;
                            q.push(make_pair(i+di[k],j+dj[k]));
                        }
                        if(grid[i][j] > grid[i+di[k]][j+dj[k]]){
                            flat = false;
                        }
                    }
                }
            }
            ans += flat ? count : 0;
        }
    }
    cout<<ans;
}