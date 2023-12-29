#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> freq;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        bool possible = true;
        for(auto it : freq) {
            if(it.second > 2) {
                possible = false;
                break;
            }
        }

        if(!possible) {
            cout << -1 << endl;
            continue;
        }

        vector<int> b(n, 0);
        int current = 1;
        for(auto it : freq) {
            if(it.second == 2) {
                for(int i = 0; i < n; i++) {
                    if(a[i] == it.first) {
                        b[i] = current;
                        current = 3 - current + 1;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(b[i] == 0) {
                b[i] = current;
                current = 3 - current + 1;
            }
        }

        for(int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
