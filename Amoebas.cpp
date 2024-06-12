#include <iostream>
#include <vector>

using namespace std;
typedef pair<char, int> pci;
typedef vector <vector <pci>> vc;
int m,n;
struct result{
    int i,j;
    int count;
};
bool IsValid(int i, int j,int di, int dj){
    return i+di >= 0 && i+di < m && j+dj >= 0 && j+dj < n;
}
result checkCount(vc grid, int i, int j){
    int Num = 0;
    int di[] = {1,1,1,0,0,-1,-1,-1};
    int dj[] = {-1,0,1,-1,1,-1,0,1};
    result temp;
    temp.count = -1;
    temp.i = -1;
    temp.j = -1;
    for(int k=0; k<8;k++){
        // cout<<grid[i+di[k]][j+dj[k]].second<<" ";
        if(IsValid(i,j,di[k],dj[k])){
            if(grid[i+di[k]][j+dj[k]].second != -1){
                temp.count = grid[i+di[k]][j+dj[k]].second;
                
            }
            if(grid[i+di[k]][j+dj[k]].first == '#' && grid[i+di[k]][j+dj[k]].second == -1){
                temp.i = i+di[k];
                temp.j = j+dj[k];
            }
        }
    }
    return temp;
}
int main(){
    cin>>m>>n;
    vc grid(m, vector <pci> (n));
    vector<vector<bool>> vist(m, vector<bool> (n, false));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            char temp;
            cin>>temp;
            grid[i][j] = make_pair(temp,-1);
        }
    }
    int count = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j].first == '.' || vist[i][j])
                continue;
            int x = i,y=j;
            while(x != -1 && y != -1){
                // printf("i;%d, j=%d\n",x,y);
                vist[x][y] = true;
                result temp = checkCount(grid,x,y);
                if(temp.count == -1){
                grid[x][y].second = count;
                count++;
                }
                else{
                    grid[x][y].second = temp.count;
                }
                x = temp.i;
                y = temp.j;
            }
        }
    }
    // for(auto& i:grid){
    //     for(auto& j:i){
    //         cout<<j.second<<"\t ";
    //     }
    //     cout<<endl;
    // }
    cout<<count;
}