#include <bits/stdc++.h>
using namespace std;

int main() {
    string instruccion, arr;
    int casos, n;
    cin >> casos;
    while (casos--) {
        deque<int> listaActual;
        cin >> instruccion >> n >> arr;
        string num = "";
        if (n > 0) {
            for (char c : arr) {
                if (isdigit(c)) {
                    num += c;
                } else if (c == ',' || c == ']') {
                    if (!num.empty()) {
                        listaActual.push_back(stoi(num));
                        num.clear();
                    }
                }
            }
        }

        bool rev = false, ok = true;
        for (char c : instruccion) {
            if (c == 'R') {
                rev = !rev;
            } else {
                if (listaActual.empty()) {
                    cout << "error\n";
                    ok = false;
                    break;
                }
                if (rev) {
                    listaActual.pop_back();
                } else {
                    listaActual.pop_front();
                }
            }
        }

        if (!ok) continue;

        cout << "[";
        if (rev) {
            for (int i = listaActual.size() - 1; i >= 0; --i) {
                cout << listaActual[i];
                if (i != 0) cout << ",";
            }
        } else {
            for (int i = 0; i < listaActual.size(); i++) {
                cout << listaActual[i];
                if (i + 1 != listaActual.size()) cout << ",";
            }
        }
        cout << "]\n";
    }
    return 0;
}
