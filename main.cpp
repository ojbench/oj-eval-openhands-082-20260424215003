#include "src.hpp"
#include <iostream>
using namespace std;

int main(){
    int n,len,method;
    cin>>n>>len>>method;
    LinkedHashMap map(len,method==0);
    for(int i=0;i<n;i++){
        string op;
        cin>>op;
        if(op=="insert"){
            int key;
            string value;
            cin>>key>>value;
            map.insert(key,value);
        }
        else if(op=="remove"){
            int key;
            string value;
            cin>>key>>value;
            map.remove(key,value);
        }
        else if(op=="ask"){
            int key;
            cin>>key;
            vector<string> ret=map.ask(key);
            cout<<ret.size();
            for(size_t j=0;j<ret.size();j++){
                cout<<" "<<ret[j];
            }
            cout<<endl;
        }
        else if(op=="forEach"){
            vector<Data> ret=map.forEach();
            cout<<ret.size();
            for(size_t j=0;j<ret.size();j++){
                cout<<" "<<ret[j].key<<" "<<ret[j].value;
            }
            cout<<endl;
        }
    }
    return 0;
}
