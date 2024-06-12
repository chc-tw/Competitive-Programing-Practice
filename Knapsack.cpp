#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<long long> vi;

int main(){
    int ca,n;
    vi va, weight;
    vi dp;
    vi chosen_item;
    while((cin>>ca>>n) && !cin.eof()){
        va.clear();
        dp.clear();
        weight.clear();
        dp.resize(ca+1,0);
        va.resize(n);
        weight.resize(n);
        vector< vector<bool>> used(n,vector<bool>(ca+1,false));
        for(int i=0; i<n; i++)
            cin>>va[i],cin>>weight[i];
        for(int i=0; i<n; i++)
            for(int j=ca; j>=weight[i]; j--){
                if(dp[j-weight[i]]+va[i]>dp[j]){
                    dp[j] = dp[j-weight[i]]+va[i];
                    used[i][j] = true;
                }
            }
        chosen_item.clear();
        for(int i=n-1,j=ca; i>=0; i--)
            if(used[i][j]){
                chosen_item.push_back(i);
                j -= weight[i];
            }
        sort(chosen_item.begin(),chosen_item.end());
        cout << chosen_item.size() << '\n';
        for(auto i:chosen_item)
            cout << i << ' ';
        cout<<'\n';
    }
}