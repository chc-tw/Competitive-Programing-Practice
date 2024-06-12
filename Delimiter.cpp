#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(void){
    int small = 0;
    int medium = 0;
    int large = 0;
    int Length; cin>>Length;
    int count = 0;
    string input;
    cin.ignore();
    getline(cin, input);
    stack<char> output;
    while(count<Length){
        if(input[count]=='('){
            output.push('(');
        }
        else if (input[count]=='['){
            output.push('[');
        }
        else if (input[count]=='{'){
            output.push('{');
        }
        else if (input[count]==')'){
            if(output.empty()){
                cout<< input[count]<<" "<< count;
                break;
            }
            else if(output.top()!='('){
                cout<< input[count]<<" "<< count;
                break;
            }
            else{
                output.pop();
            }
        }
        else if (input[count]==']'){
            if(output.empty()){
                cout<< input[count]<<" "<< count;
                break;
            }
            else if(output.top()!='['){
                cout<< input[count]<<" "<< count;
                break;
            }
            else{
                output.pop();
            }
        }
        else if (input[count]=='}'){
            if(output.empty()){
                cout<< input[count]<<" "<< count;
                break;
            }
            else if(output.top()!='{'){
                cout<< input[count]<<" "<< count;
                break;
            }
            else{
                output.pop();
            }
        }
        count++;
    }
    if(count==Length){
        cout<<"ok so far";
    }
}