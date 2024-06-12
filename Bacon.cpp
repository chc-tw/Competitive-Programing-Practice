#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef vector<pair<string,vector<string> > > MENU;

int main(void){
    map<string, vector<string> > menu;
    map<string, vector<string> >::iterator it;
    // MENU menu;
    int customerN;
    while(cin>>customerN){
        if(customerN==0) break;
        string input;
        getline(cin, input);
        while(customerN--){
            getline(cin, input);
            stringstream ss(input);
            string customer; ss >> customer;
            string order;
            bool flag = true;
            while(ss>>order){
                // for(MENU::iterator mi = menu.begin(); mi != menu.end(); mi++){
                //     if(mi->first == order){
                //         mi->second.push_back(customer);
                //         flag = false;
                //     }
                // }
                // if(flag){
                //     vector<string> newOrder;
                //     newOrder.push_back(customer);
                //     menu.push_back(make_pair(order,newOrder));
                // }
                it = menu.find(order);
                if ( it != menu.end()) {
                    it->second.push_back(customer);
                }
                else {
                    vector<string> newOrder;
                    newOrder.push_back(customer);
                    menu.insert(pair<string, vector<string> >(order, newOrder));
                }
            }
            ss.str("");
            ss.clear();
        }
        for( it = menu.begin(); it != menu.end(); it++){
            cout<<it->first<<" ";
            sort(it->second.begin(), it->second.end());
            for(vector<string>::iterator itt = it->second.begin(); itt != it->second.end(); itt++){
                cout<<*itt<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        menu.clear();
    }
}