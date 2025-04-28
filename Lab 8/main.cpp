#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<fstream>

using namespace std;

ifstream file("../file.txt");

class Compare {
public:
    bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) {
        if(p1.second == p2.second) {
            return p1.first > p2.first;
        }
        return p1.second < p2.second;
    }
};

int main() {
    string str, aux = "";
    vector<string> v;
    getline(file, str);
    //cout << str << endl;
    //impartim fraza in cuvinte
    for(int i = 0; i < str.length(); i++) {
        if (str[i]==' '|| str[i]=='.'||str[i]=='?'||str[i]=='!'||str[i]==',') {
            if (!aux.empty()) {
                v.push_back(aux);
                //cout << "aux=" << aux << endl;
                aux = "";
            }
        }
        else {
            if (str[i]>='A'&&str[i]<='Z') {
                str[i] = str[i]+32;
            }
            if (str[i]>='a'&&str[i]<='z') {
                aux+=str[i];
            }
        }
    }

    map<string, int> mp;
    vector<string>::iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        mp[*it]++;
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
    for (pair<string, int> p : mp) {
        pq.push(p);
    }

    while (!pq.empty()) {
        pair<string, int> p = pq.top();
        pq.pop();
        cout << p.first << " " << p.second << endl;
    }

    file.close();
    return 0;
}