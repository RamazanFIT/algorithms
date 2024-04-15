#include <bits/stdc++.h>


using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    map<string, string> residents;
    map<string, int> namesCount;

    for (int i = 0; i < n; ++i) {
        string name, id;
        cin >> name >> id;
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        transform(id.begin(), id.end(), id.begin(), ::tolower);
        residents[id] = name;
        namesCount[name]++;
    }

    int perfectMatches = 0;
    int satisfactoryMatches = 0;

    for (int i = 0; i < m; ++i) {
        string name, id;
        cin >> name >> id;
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        transform(id.begin(), id.end(), id.begin(), ::tolower);

        if (residents.find(id) != residents.end()) {
            if (residents[id] == name) {
                perfectMatches++;
            } else {
                satisfactoryMatches++;
            }
        } else if (namesCount[name] == 1) {
            satisfactoryMatches++;
        }
    }

    cout << perfectMatches << " " << satisfactoryMatches << endl;

    return 0;
}
