
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct State
{
    int a, b;
    vector<string> steps;
};

int main()
{
    int j1, j2, target;

    cout << "Enter Jug 1 capacity: ";
    cin >> j1;

    cout << "Enter Jug 2 capacity: ";
    cin >> j2;

    cout << "Enter target amount for Jug 1: ";
    cin >> target;

    if (j1 <= 0 || j2 <= 0 || target < 0 || target > j1)
    {
        cout << "Invalid input!";
        return 0;
    }

    queue<State> q;
    set<pair<int, int>> visited;

    q.push({0, 0, {}});
    visited.insert({0, 0});

    bool found = false;

    while (!q.empty())
    {
        State current = q.front();
        q.pop();

        int a = current.a;
        int b = current.b;

        // Goal: Store target amount in Jug 1
        if (a == target)
        {
            cout << "\nSolution Found!\n";

            cout << "Initial State: (0, 0)\n";

            for (int i = 0; i < current.steps.size(); i++)
            {
                cout << "Step " << i + 1 << ": "
                     << current.steps[i] << endl;
            }

            cout << "\nFinal State:\n";
            cout << "Jug 1 = " << a << endl;
            cout << "Jug 2 = " << b << endl;

            found = true;
            break;
        }

        // Calculate possible operations
        int p1 = min(a, j2 - b);
        int p2 = min(b, j1 - a);

        vector<pair<pair<int, int>, string>> next = {

            {{j1, b}, "Fill Jug 1"},

            {{a, j2}, "Fill Jug 2"},

            {{0, b}, "Empty Jug 1"},

            {{a, 0}, "Empty Jug 2"},

            {{a - p1, b + p1}, "Transfer Jug 1 to Jug 2"},

            {{a + p2, b - p2}, "Transfer Jug 2 to Jug 1"}
        };

        for (auto operation : next)
        {
            int x = operation.first.first;
            int y = operation.first.second;

            if (visited.find({x, y}) == visited.end())
            {
                visited.insert({x, y});

                vector<string> newSteps = current.steps;
                newSteps.push_back(operation.second);

                q.push({x, y, newSteps});
            }
        }
    }

    if (!found)
    {
        cout << "\nTarget cannot be achieved in Jug 1.\n";
    }

    return 0;
}

