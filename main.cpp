#include "LinkedHashMap.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, len;
    bool forEachByTime;
    cin >> n >> len >> forEachByTime;
    
    LinkedHashMap* map = new LinkedHashMap(len, forEachByTime);
    
    for(int i = 0; i < n; i++) {
        string op;
        cin >> op;
        
        if(op == "insert") {
            int key;
            string value;
            cin >> key >> value;
            map->insert(key, value);
        } else if(op == "remove") {
            int key;
            string value;
            cin >> key >> value;
            map->remove(key, value);
        } else if(op == "ask") {
            int key;
            cin >> key;
            vector<string> result = map->ask(key);
            cout << result.size();
            for(size_t j = 0; j < result.size(); j++) {
                cout << " " << result[j];
            }
            cout << endl;
        } else if(op == "forEach") {
            vector<Data> result = map->forEach();
            cout << result.size();
            for(size_t j = 0; j < result.size(); j++) {
                cout << " " << result[j].key << " " << result[j].value;
            }
            cout << endl;
        }
    }
    
    delete map;
    return 0;
}
