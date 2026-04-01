#include <array>
#include <compare>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

struct State {
    char m {};
    char b {};
    char g {};
    int  h {};

    auto operator<=>(const State&) const = default;
};

struct Node {
    State state;
    std::vector<std::string> path;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    State start {};
    std::cin >> start.m >> start.b >> start.g >> start.h;

    std::queue<Node> q;
    std::set<State> visited;

    q.push({start, {}});
    visited.insert(start);

    constexpr std::array<char, 3> locations {'A', 'B', 'C'};

    while (!q.empty()) {
        Node curr = std::move(q.front());
        q.pop();

        const State s = curr.state;

        if (s.m == s.g && s.b == s.g && s.h == 1) {
            for (const std::string& step : curr.path) {
                std::cout << step << '\n';
            }
            std::cout << "Monkey reach the banana\n";
            return 0;
        }

        auto try_enqueue = [&](const State& next_state, std::string action) {
            if (visited.contains(next_state)) {
                return;
            }
            visited.insert(next_state);
            auto next_path = curr.path;
            next_path.push_back(std::move(action));
            q.push({next_state, std::move(next_path)});
        };

        if (s.h == 1) {
            try_enqueue({s.m, s.b, s.g, 0}, "Monkey climb down from the box");
        }

        if (s.h == 0) {
            for (char loc : locations) {
                if (loc != s.m) {
                    try_enqueue({loc, s.b, s.g, 0}, std::string("Monkey go to ") + loc);
                }
            }
        }

        if (s.m == s.b && s.h == 0) {
            for (char loc : locations) {
                if (loc != s.m) {
                    try_enqueue({loc, loc, s.g, 0}, std::string("Monkey push the box to ") + loc);
                }
            }
            try_enqueue({s.m, s.b, s.g, 1}, "Monkey climb onto the box");
        }
    }

    return 0;
}