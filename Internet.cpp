#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int N,M; cin>>N>>M;
    set<int> all;
    for(int i=2; i<=N; i++)
        all.insert(all.end(),i);
    set<int> connected = {1};
    vector<set<int> > joins;
    joins.push_back(connected);
    int p1,p2;
    while(M--){
        cin>>p1>>p2;
        int flag = -1;
        for(int i=0; i<joins.size(); i++){
            all.erase(p1);
            all.erase(p2);
            if(joins[i].count(p1) || joins[i].count(p2)){
                joins[i].insert(p1);
                joins[i].insert(p2);
                if(flag == -1)
                    flag = i;
                else{
                    // cout<<"in\n";
                    // cout<<"flag: "<<flag<<" i: "<<i<<endl;
                    set_union(joins[flag].begin(), joins[flag].end(), joins[i].begin(), joins[i].end(), inserter(joins[flag], joins[flag].begin()));
                    joins.erase(joins.begin()+i);
                }
            }
        }
        if(flag == -1){
            set<int> temp;
            temp.insert(p1);
            temp.insert(p2);
            joins.push_back(temp);
        }
        // for(auto i:joins){
        //         cout<<"times:"<<M<<" ";
        //         for(auto j:i)
        //             cout<<j<<" ";
        //         cout<<endl;
        //     }
    }
    if(joins[0].size() == N) cout<<"Connected";
    else{
        // for(auto i:joins){
        //     for(auto j:i)
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        joins[0] = all;
        for(int i=1; i<joins.size(); i++){
            set_union(joins[0].begin(), joins[0].end(),joins[i].begin(),joins[i].end(), inserter(joins[0], joins[0].begin()));
        }
        for(auto i:joins[0])
            cout<<i<<endl;

    }
}
