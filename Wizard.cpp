#include <string>
#include <iostream>

using namespace std;

void bigNdouble(int (&bign)[110]){
    int i;
    for(i=0; i<110; i++){
        if(bign[i]!=0){
            bign[i] *= 2;
        }
    }
    for(i=0; i<110; i++){
        if(bign[i] >= 10){
            bign[i] -= 10;
            bign[i+1]++;
        }
    }
}

int main(int argc, char **argv){
    string N,k;
    int bign[110] ={0};
    bign[0]=1;
    cin >> N >> k ;
    if(k.length()>=4){
        cout << "Your wish is granted!";
        return 0;
    }
    else if(k.length()==3){
        int K = stoi(k);
        if(K>=336){
            cout << "Your wish is granted!";
            return 0;
        }
            
    }
    int K = stoi(k);
    int Len;
    while(K--){
        bigNdouble(bign);
    }
    for(int i=109; i>=0; i--){
        if(bign[i]!=0){
            Len = i;
            break;
        }
    }
    Len++;
    // cout<<"Len = "<<Len<<endl;
    // cout<<"N.len = "<<N.length()<<endl;
    if(Len > N.length()){
        cout << "Your wish is granted!";
    }
    else if(Len == N.length()){
        for(int i=0; i < N.length(); i++){
            // cout<<"i:"<<i<<" "<<bign[Len - i - 1]<<" "<<(int)(N[i]-'0')<<endl;
            if(bign[Len - i - 1] > N[i]-'0'){
                // cout<<bign[Len - i - 1]<<" "<<(int)(N[i]-'0')<<endl;
                cout<<"Your wish is granted!";
                
                return 0;
            }
            else if(bign[Len - i - 1] < N[i]-'0'){
                cout<<"You will become a flying monkey!";
                return 0;
            }
        }
        cout<<"Your wish is granted!";
    }
    else{
        cout<<"You will become a flying monkey!";
    }

}