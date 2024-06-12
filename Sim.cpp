#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
    int caseN; cin>>caseN;
    string input;
    getline(cin,input);
    while(caseN--){
        int index = 0;
        bool flag = true;
        getline(cin,input);
        string output = "";
        for(int i=0;i<input.length();i++){
            if(input[i] == '['){
                index = 0;
                flag = false;
            }
            else if(input[i] == ']'){
                index = output.size();
                flag = true;
            }
            else if(input[i] == '<'){
                if(index!=0){
                    output.erase(output.begin()+index-1);
                    index--;
                }
            }
            else{
                output.insert(output.begin()+index,input[i]);
                index++;
            }
        }
        cout<<output<<endl;
    }

}