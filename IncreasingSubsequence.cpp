#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

vi LIS(vi seq){
    vi dp;
    vi idx(seq.size(),-1);
    vi pre(seq.size(),-1);
    for(int i=0;i<seq.size();i++){
        auto p = lower_bound(dp.begin(),dp.end(),seq[i]);
        int j = p-dp.begin();
        if(p==dp.end() || *p>seq[i]){
            if(p==dp.end())
                dp.push_back(seq[i]);
            else
                *p = seq[i];
            if(j>0)
                pre[i] = idx[j-1];
            idx[j] = i;
        }
    }
    vi ans(dp.size());
    int i = idx[dp.size()-1];
    for(int j=dp.size()-1; i>=0; j--){
        ans[j] = seq[i];
        i = pre[i];
    }
    return ans;
}

int main(void){
    int n; cin>>n;
    vi seq;
    vi ans;
    while(n!=0){
        seq.resize(n);
        for(int i=0;i<n;i++)
            cin>>seq[i];
        ans = LIS(seq);
        cout<<ans.size();
        for(auto i:ans)
            cout<<" "<<i;
        cout<<'\n';
        cin>>n;
    }
}