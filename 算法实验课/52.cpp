#include <bits/stdc++.h>
using namespace std;
 
int num_x[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int num_y[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
 
bool isvalid(int r, int c, int row, int col)
{
    return (row >= 0 && row < r && col >= 0 && col < c);
}
 
int count(int r, int c, int sx, int sy, int dx, int dy)
{
    queue<pair<pair<int, int>, int> > q;
    set<pair<int, int> > st;
    q.push(make_pair(make_pair(sx, sy), 0));
    while (!q.empty()) {
        pair<pair<int, int>, int> p = q.front();
        st.insert(make_pair(sx, sy));
        if (p.first.first == dx && p.first.second == dy) {
            return p.second;
        }
        q.pop();
        for (int i = 0; i < 8; i++) {
            int row = p.first.first + num_x[i];
            int col = p.first.second + num_y[i];
            if (isvalid(r, c, row, col) && st.find(make_pair(row, col)) == st.end()) {
                st.insert(make_pair(row, col));
                int temp = p.second + 1;
                q.push(make_pair(make_pair(row, col), temp));
            }
        }
    }
    return -1;
}
 
int main()
{
    int r, c;
    cout << "Row: ";
    cin >> r;
    cout << "Col: ";
    cin >> c;
    int sx, sy, dx, dy;
    cout << "Staring position : ";
    cin >> sx >> sy;
    cout << "Destination position : ";
    cin >> dx >> dy;
    cout << "Steps :";
    cout << count(r, c, sx - 1, sy - 1, dx - 1, dy - 1) << endl;
    return 0;
}

