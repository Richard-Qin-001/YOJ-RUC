#include <bits/stdc++.h>
using namespace std;

class State
{
public:
    char m;
    char b;
    char g;
    int h;

    bool operator< (const State& other) const {
        if (this->m != other.m) {
            return this->m < other.m;
        }
        if (this->b != other.b)
        {
            return this->b < other.b;
        }
        if (this->g != other.g)
        {
            return this->g < other.g;
        }
        return this->h < other.h;
    }
};

class Node {
public:
    State state;
    vector<string> path;
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char m;
    char b;
    char g;
    int h;
    cin >> m >> b >> g >> h;

    queue<Node> q;
    set<State> visited;

    State start {m, b, g, h};
    q.push({start, {}});
    visited.insert(start);

    char locations[] = {'A', 'B', 'C'};

    while (!q.empty())
    {
        Node curr = q.front();
        q.pop();

        State s = curr.state;

        if (s.m == s.g && s.b == s.g && s.h == 1) {
            for (const string& step : curr.path) {
                cout << step << endl;
            }
            cout << "Monkey reach the banana" << endl;
            return 0;
        }

        if (s.h == 1) {
            State next_s {s.m, s.b, s.g, 0};
            if (visited.find(next_s) == visited.end()) {
                visited.insert(next_s);
                vector<string> next_path = curr.path;
                next_path.push_back("Monkey climb down from the box");
                q.push({next_s, next_path});
            }
        }

        if (s.h == 0) {
            for (char loc : locations){
                if (loc != s.m) {
                    State next_s {loc, s.b, s.g, 0};
                    if (visited.find(next_s) == visited.end()) {
                        visited.insert(next_s);
                        vector<string> next_path = curr.path;
                        next_path.push_back(string("Monkey go to ") + loc);
                        q.push({next_s, next_path});
                    }
                }
            }
        }

        if (s.m == s.b && s.h == 0)
        {
            for (char loc : locations)
            {
                if (loc != s.m)
                {
                    State next_s {loc, loc, s.g, 0};
                    if (visited.find(next_s) == visited.end())
                    {
                        visited.insert(next_s);
                        vector<string> next_path = curr.path;
                        next_path.push_back(string("Monkey push the box to ") + loc);
                        q.push({next_s, next_path});
                    }
                }
            }
        }

        if (s.m == s.b && s.h == 0)
        {
            State next_s = {s.m, s.b, s.g, 1};
            if (visited.find(next_s) == visited.end())
            {
                visited.insert(next_s);
                vector<string> next_path = curr.path;
                next_path.push_back("Monkey climb onto the box");
                q.push({next_s, next_path});
            }
        }
    }

    return 0;
    
}