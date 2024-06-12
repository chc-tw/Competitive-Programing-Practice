#include <iostream>

using namespace std;
int main(void){
    int N; cin>>N;
    int Heights[1000001];
    Heights[0] = 0;
    for(int i=1; i<=N; i++)
        cin>>Heights[i];
    int max_=0;
    int min_;
    int heightest = 0;
    int i,j;
    for(i=1; i<=N;i++){
        // cout<<"i:"<<i<<endl;
        min_ = Heights[i+1];
        if(Heights[i]>max_ && Heights[i]>Heights[i+1]){
            for(j=i+2; j<=N; j++){
                // cout<<j<<endl;
                int locate = min(Heights[i], Heights[j]);
                max_ = max(locate - min_, max_);
                min_ = min(min_, locate);
                if(Heights[j]>Heights[i]){
                    i = j-1;
                    break;
                }
                
            }
            if(j>N) break;
        }   
    }
    cout<<max_;
}