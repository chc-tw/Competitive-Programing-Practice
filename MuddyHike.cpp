#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;
#define F first 
#define S second
typedef pair<int, int> pii;

int R,C;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0 ,-1};

bool IsValid(int r, int c){
    return (r>=0 && r<R && c>=0 && c<C);
}

int main(){
    cin >> R >> C;
    vector< vector<int> > grid(R, vector<int> (C));
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> grid[i][j];
        }
    }
    int ans = numeric_limits<int>::max();
    for(int startrow=0; startrow<R; startrow++){
        vector< vector<int> > dist(R, vector<int> (C, numeric_limits<int>::max()));
        vector< vector<bool> > vist(R, vector<bool> (C, false));
        dist[startrow][0] = grid[startrow][0];
        priority_queue<pair<int, pii> , vector<pair<int, pii>>, greater<pair<int, pii>> > pq;
        pq.push({grid[startrow][0],{startrow,0}});
        while(!pq.empty()){
            int cur_r = pq.top().S.F;
            int cur_c = pq.top().S.S;
            int cur_mud = pq.top().F;
            vist[cur_r][cur_c] = true;
            pq.pop();
            if(cur_c == C-1){
                ans = min(ans, cur_mud);
                break;
            }
            for(int i = 0; i <4;i++){
                int new_r = cur_r + dr[i];
                int new_c = cur_c + dc[i];
                
                if(IsValid(new_r, new_c)){
                    if(vist[new_r][new_c]) continue;
                    int new_mud = max(cur_mud, grid[new_r][new_c]);
                    if(new_mud < dist[new_r][new_c]){
                        dist[new_r][new_c] = new_mud;
                        pq.push({new_mud, {new_r, new_c}});
                    }
                }
            }
        }
    }
    cout<<ans;
}
