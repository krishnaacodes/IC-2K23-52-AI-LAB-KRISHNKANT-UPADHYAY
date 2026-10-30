
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// Check whether the state is safe
bool isValid(int m, int c)
{
    if (m < 0 || c < 0 || m > 3 || c > 3)
        return false;

    // Check left bank
    if (m > 0 && c > m)
        return false;

    // Check right bank
    int rm = 3 - m;
    int rc = 3 - c;

    if (rm > 0 && rc > rm)
        return false;

    return true;
}

int main()
{
    // State = (Missionaries, Cannibals, Boat)
    vector<int> start = {3, 3, 0};
    vector<int> goal = {0, 0, 1};

    // Possible boat movements
    vector<pair<int, int>> moves = {
        {1, 0}, {2, 0}, {0, 1}, {0, 2}, {1, 1}
    };

    queue<vector<int>> q;
    set<vector<int>> visited;

    map<vector<int>, vector<int>> parent;
    map<vector<int>, string> action;

    q.push(start);
    visited.insert(start);

    while (!q.empty())
    {
        vector<int> state = q.front();
        q.pop();

        int m = state[0];
        int c = state[1];
        int boat = state[2];

        if (state == goal)
            break;

        for (auto move : moves)
        {
            int dm = move.first;
            int dc = move.second;

            vector<int> next;
            string direction;

            if (boat == 0)
            {
                next = {m - dm, c - dc, 1};
                direction = "Left to Right";
            }
            else
            {
                next = {m + dm, c + dc, 0};
                direction = "Right to Left";
            }

            int nm = next[0];
            int nc = next[1];

            if (isValid(nm, nc) && visited.find(next) == visited.end())
            {
                visited.insert(next);

                parent[next] = state;

                action[next] =
                    to_string(dm) + " Missionary, " +
                    to_string(dc) + " Cannibal: " + direction;

                q.push(next);
            }
        }
    }

    if (visited.find(goal) == visited.end())
    {
        cout << "No solution found.";
        return 0;
    }

    // Reconstruct solution path
    vector<vector<int>> path;

    vector<int> current = goal;

    while (current != start)
    {
        path.push_back(current);
        current = parent[current];
    }

    path.push_back(start);

    reverse(path.begin(), path.end());

    // Print solution
    cout << "\nSolution Found!\n\n";

    for (int i = 0; i < path.size(); i++)
    {
        vector<int> s = path[i];

        int m = s[0];
        int c = s[1];
        int boat = s[2];

        cout << "Step: " << i << endl;

        if (i > 0)
            cout << "Movement: " << action[s] << endl;

        cout << "Left Bank: M = " << m
             << " C = " << c << endl;

        cout << "Right Bank: M = " << 3 - m
             << " C = " << 3 - c << endl;

        cout << "Boat: "
             << (boat == 0 ? "Left" : "Right")
             << endl;

        cout << "----------------------\n";
    }

    return 0;
}
