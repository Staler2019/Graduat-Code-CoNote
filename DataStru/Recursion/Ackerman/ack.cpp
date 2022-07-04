#include <bits/stdc++.h>
using namespace std;

vector<string> ack_st;
int op = 0;

string int2str(int a) {
    stringstream ss;
    ss << a;
    return ss.str();
}

string add_up(int m, int n) {
    return "ack(" + int2str(m) + ", " + int2str(n) + ") ";
}
string add_phrase(int m, string n) {
    return "ack(" + int2str(m) + ", " + n + ") ";
}
void error() {
    cout << "function error!" << endl;
    exit(0);
}

void print_st(vector<string> st) {
    cout << "***print_st***";
    for (string str : st) cout << "\n" << str;
    cout << endl;
}

int ack(int m, int n) {
    if (m < 0 || n < 0) error();

    print_st(ack_st);
    ack_st.pop_back();
    op++;

    if (m == 0)
        return n + 1;
    else if (n == 0) {
        ack_st.push_back(add_up(m - 1, 1));
        return ack(m - 1, 1);
    } else {
        ack_st.push_back(add_phrase(m - 1, add_up(m, n - 1)));
        ack_st.push_back(add_up(m, n - 1));
        return ack(m - 1, ack(m, n - 1));
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m, n;
    cin >> m >> n;
    ack_st.push_back(add_up(m, n));
    cout << ack(2, 2) << endl;
    cout << "op = " << op << endl;
}