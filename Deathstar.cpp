#include <iostream>
#include <bitset>

using namespace std;
int main(void){
    int N; cin>>N;
    bitset <30> output[1000];
    bitset<30> M[1000][1000];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            int temp;
            cin>>temp;
            M[i][j] = temp;
        }
            
    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++)
            for(int k=0; k<30;k++){
                if(M[i][j][k]){
                    output[i][k] = true;
                    output[j][k] = true;
                }
            }
            
    for(int i=0; i<N; i++)
        cout << output[i].to_ulong() <<" ";
}