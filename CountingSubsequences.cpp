#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t,n; cin>>t;
    string s;
    while(t--){
        cin.ignore();
        getline(cin,s);
        cin>>n;
        vll prefix(n+1,0);
        for(int i=1;i<=n;i++){
            scanf("%lld", &prefix[i]);
            prefix[i]+=prefix[i-1];
        }
        map<ll,int> m;
        int ans = 0;
        for(int i=0;i<=n;i++){
            m[prefix[i]]++;
            ans += m[prefix[i]-47];
        }
        printf("%d\n",ans);
    }
}