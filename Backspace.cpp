#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
    string input;
    getline(cin,input);
    vector<char> output;
    for(int i=0;i<input.length();i++){
        if(input[i]=='<'){
            output.pop_back();
        }
        else{
            output.push_back(input[i]);
        }
    }
    for (vector<char>::iterator it=output.begin();it!=output.end();it++){
            cout<<*it;
        }
    cout<<endl;
}