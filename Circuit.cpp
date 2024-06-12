#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
int main(void){
    int caseN; cin >> caseN;
    vector<bool> values;
    char value;
    string input;
    while(caseN--){
        cin >> value;
        if(value == 'T')
            values.push_back(true);
        else if(value == 'F')
            values.push_back(false);
    }
    cin.ignore();
    getline(cin, input);
    stringstream ss(input);
    char word;
    stack<bool> character; 
    while(ss>>word){
        if(65<=word && word<=90){
            character.push(values[word-65]);
        }
        else if(word=='*'){
            bool temp1 = character.top();
            character.pop();
            bool temp2 = character.top();
            character.pop();
            character.push(temp1&&temp2);
        }
        else if(word=='+'){
            bool temp1 = character.top();
            character.pop();
            bool temp2 = character.top();
            character.pop();
            character.push(temp1||temp2);
        }
        else if (word=='-'){
            bool temp1 = character.top();
            character.pop();
            character.push(!temp1);
        }
    }
    if(character.top())
        cout<<'T';
    else
        cout<<'F';
}