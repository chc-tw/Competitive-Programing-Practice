#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(void){
    string input;
    while(getline(cin, input) && !cin.eof()){
        string hex="";
        string dec="";
        for(int i=0; i<input.size(); i++){
            if(input[i] =='0' && hex.size() == 0){
                hex.push_back('0');
            }
            else if((input[i] == 'x' || input[i] == 'X') && hex.size() ==1){
                hex.push_back(input[i]);
            }
            else if(hex.size() >=2){
                if( (('a'<=input[i] && input[i]<='f') || ('A'<=input[i] && input[i]<='F') || ('0'<=input[i] && input[i]<='9')) && dec.size() < 8){
                    hex.push_back(input[i]);
                    dec.insert(0,1,input[i]);
                }
                else if (dec.size()==0){
                    hex.clear();
                    dec.clear();
                }
                else{
                    cout<<hex<<" ";
                    long long int sum=0;
                    for(int j=0; j<dec.size(); j++){
                        if(dec[j] <= 57){
                            sum += (dec[j] - 48) * pow(16,j);
                        }
                        else if(dec[j] <= 70){
                            sum += (dec[j] - 65  + 10) * pow(16,j);
                        }
                        else if(dec[j] <= 102){
                            sum += (dec[j] - 97 + 10) * pow(16,j);
                        }
                    }
                    cout<<sum<<endl;
                    hex.clear();
                    dec.clear();
                }
                
            }
        }
        if(hex.size()>2){
            cout<<hex<<" ";
            long long int sum=0;
            for(int j=0; j<dec.size(); j++){
                if(dec[j] <= 57){
                    sum += (dec[j] - 48) * pow(16,j);
                }
                else if(dec[j] <= 70){
                    sum += (dec[j] - 65  + 10) * pow(16,j);
                }
                else if(dec[j] <= 102){
                    sum += (dec[j] - 97 + 10) * pow(16,j);
                }
            }
            cout<<sum<<endl;
            hex.clear();
            dec.clear();
        }

    }
}