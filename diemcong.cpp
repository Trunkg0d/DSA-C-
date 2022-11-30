#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef vector<int> vi;

vi edge[8];

void input()
{
    edge[0].push_back(1);
    edge[0].push_back(3);
    edge[0].push_back(5);
    edge[1].push_back(0);
    edge[1].push_back(2);
    edge[1].push_back(6);
    edge[2].push_back(1);
    edge[2].push_back(3);
    edge[2].push_back(7);
    edge[3].push_back(0);
    edge[3].push_back(4);
    edge[3].push_back(5);
    edge[4].push_back(3);
    edge[4].push_back(5);
    edge[4].push_back(7);
    edge[5].push_back(0);
    edge[5].push_back(4);
    edge[5].push_back(6);
    edge[6].push_back(1);
    edge[6].push_back(5);
    edge[6].push_back(7);
    edge[7].push_back(2);
    edge[7].push_back(4);
    edge[7].push_back(6);
}

void findPath(vi path)
{
    int last = path[path.size() - 1];
    if (last == 7)
    {
        for (int i = 0; i < path.size(); ++i)
            cout << path[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < edge[last].size(); ++i)
    {
        vi tmp = path;
        int check = 0;
        for (int j = 0; j < path.size(); ++j)
            if (edge[last][i] == path[j])
                check = 1;
        if (check == 0)
        {
            tmp.push_back(edge[last][i]);
            findPath(tmp);
        }
    }
}

int main()
{
    vi tmp;
    tmp.push_back(0);
    freopen("output.txt", "w", stdout);
    input();
    findPath(tmp);
    return 0;
}