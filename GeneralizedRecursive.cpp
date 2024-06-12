#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<int> BigInt;

vi a;
vi b;
BigInt dic[100][100];
int c;
int d;

BigInt BigIntAdd(const BigInt& a, const BigInt& b) {
    BigInt result(max(a.size(), b.size()) + 1, 0);
    int carry = 0;
    for (size_t i = 0; i < result.size(); i++) {
        int aValue = i < a.size() ? a[i] : 0;
        int bValue = i < b.size() ? b[i] : 0;
        int sum = aValue + bValue + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    return result;
}

BigInt RF(int x, int y){
    BigInt ans(1, 0);
    if(x <= 0 || y <= 0) {
        ans[0] = d;
        return ans;
    }
    else {
        if(dic[x][y].size() != 0) return dic[x][y];
        else{
            for(int i=0; i<a.size(); i++){
                ans = BigIntAdd(ans, RF(x-a[i], y-b[i]));
            }
            ans[0] += c;
            dic[x][y] = ans;
        }
    }
    return ans;
}

void printBigInt(const BigInt& bigint) {
    for (auto it = bigint.rbegin(); it != bigint.rend(); ++it) {
        cout << *it;
    }
}

int main(){
    int caseN; cin>>caseN;
    int ai,bi,x,y;
    stringstream ss;
    string s;
    cin.ignore();
    while(caseN--){
        for(int i=0; i<100; i++)
            for(int j=0; j<100; j++)
                dic[i][j].clear();
        getline(cin,s);
        ss.str("");
        ss.clear();
        ss<<s;
        while(ss>>ai>>bi){
            a.push_back(ai);
            b.push_back(bi);
        }
        a.erase(a.end()-1);
        b.erase(b.end()-1);
        c = ai;
        d = bi;
        getline(cin,s);
        ss.str("");
        ss.clear();
        ss<<s;
        int count = 0;
        while(ss>>x>>y){
            printBigInt(RF(x,y));
            cout<<endl;
        }
        cout<<endl;
        a.erase(a.begin(),a.end());
        b.erase(b.begin(),b.end());
    }
}
