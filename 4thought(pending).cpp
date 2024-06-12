#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(void) {
    char op[4] = {'+', '-', '*','/'};
    vector<char> opq;
    vector<char>::iterator it1;
    vector<int> numq;
    vector<int>::iterator it2;
    map<int,string> targets;
    map<int,string>::iterator it;
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4;k++){
                numq.push_back(4);
                if(op[i]=='+' || op[i]=='-'){
                    opq.push_back(op[i]);
                    numq.push_back(4);
                }
                else{
                    numq.push_back(4);
                    if(op[i]=='*'){
                        int num1 = numq.back();
                        numq.erase(numq.begin()+numq.size()-1);
                        int num2 = numq.back();
                        numq.erase(numq.begin()+numq.size()-1);
                        numq.push_back(num1*num2);
                    }
                    else if (op[i]=='/'){
                        int num1 = numq.back();
                        numq.erase(numq.begin()+numq.size()-1);
                        int num2 = numq.back();
                        numq.erase(numq.begin()+numq.size()-1);
                        numq.push_back(num2/num1);
                    }
                }

                if(op[j]=='+' || op[j]=='-'){
                    opq.push_back(op[j]);
                    numq.push_back(4);
                }
                else{
                    numq.push_back(4);
                    if(op[j]=='*'){
                        int num1 = numq.back();
                        numq.erase(numq.begin()+numq.size()-1);
                        int num2 = numq.back();
                        numq.erase(numq.begin()+numq.size()-1);
                        numq.push_back(num1*num2);
                    }
                    else if (op[j]=='/'){
                        int num1 = numq.back();
                        numq.erase(numq.begin()+numq.size()-1);
                        int num2 = numq.back();
                        numq.erase(numq.begin()+numq.size()-1);
                        numq.push_back(num2/num1);
                    }
                }

                if(op[k]=='+' || op[k]=='-'){
                    opq.push_back(op[k]);
                    numq.push_back(4);
                }
                else{
                    numq.push_back(4);
                    if(op[k]=='*'){
                        int num1 = numq.back();
                        numq.erase(numq.begin()+numq.size()-1);
                        int num2 = numq.back();
                        numq.erase(numq.begin()+numq.size()-1);
                        numq.push_back(num1*num2);
                    }
                    else if (op[k]=='/'){
                        int num1 = numq.back();
                        numq.erase(numq.begin()+numq.size()-1);
                        int num2 = numq.back();
                        numq.erase(numq.begin()+numq.size()-1);
                        numq.push_back(num2/num1);
                    }
                }
                // cout<<"opq";
                // for(it1 = opq.begin(); it1 != opq.end();it1++) cout<<" "<<*it1;
                // cout<<endl;
                // cout<<"numq";
                // for(it2 = numq.begin(); it2 != numq.end();it2++) cout<<" "<<*it2;
                // cout<<endl;
                // cout<<"Enter while\n";
                while(opq.size()!=0){
                    if(opq.front()=='+'){
                        int num1 = numq.front();
                        numq.erase(numq.begin());
                        int num2 = numq.front();
                        numq.erase(numq.begin());
                        numq.insert(numq.begin(),num1+num2);
                    }
                    else{
                        int num1 = numq.front();
                        numq.erase(numq.begin());
                        int num2 = numq.front();
                        numq.erase(numq.begin());
                        numq.insert(numq.begin(),num1-num2);
                    }
                    opq.erase(opq.begin());
                }
                int ans = numq.front();
                it = targets.find(ans);
                string ops="";
                if (it == targets.end()){
                    ops.append("4 ");
                    ops.push_back(op[i]);
                    ops.append(" 4 ");
                    ops.push_back(op[j]);
                    ops.append(" 4 ");
                    ops.push_back(op[k]);
                    ops.append(" 4");
                    targets.insert(pair<int,string>(ans,ops));
                }
                opq.clear();
                numq.clear();
            }
        }
    }
    int caseN;
    cin>>caseN;
    while(caseN--){
        int target; cin>>target;
        it = targets.find(target);
        if (it != targets.end()){
            cout<<it->second<<" = "<<it->first<<endl;
        }
        else{
            cout<<"no solution\n";
        }
    }
}