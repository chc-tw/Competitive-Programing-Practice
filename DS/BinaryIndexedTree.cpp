#include <iostream>
#include <vector>

using namespace std;

int n,q;
vector<int> BIT;
vector<int> number;

int lowbit(int pos){
    return pos&(-pos);
}

void modify(int pos, int value){
    for(;pos<=n;pos+=lowbit(pos)){
        BIT[pos]+=value;
    }
    return;
}

int query(int pos){
    int sum=0;
    for(;pos>0;pos-=lowbit(pos)){
        sum+=BIT[pos];
    }
    return sum;
}

void build(){
    for(int i=1; i<=n; i++){
        modify(i,number[i]);
    }
    return;
}
int main(void){
    cin>>n>>q;
    BIT.resize(n+1,0);
    number.resize(n+1);
    for(int i=0; i<=n; i++){
        cin>>number[i];
    }
    build();
    int op, x, y;
    while(q--){
        cin>>op>>x>>y;
    }
}