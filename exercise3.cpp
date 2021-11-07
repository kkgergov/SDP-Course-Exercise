#include <iostream>
#include <vector>
#include "staticQueue.h"
using namespace std;

//number of islands is the number of times we call BFS, biggest island is obviously the largest BFS(we use counter to track number of iterations)
vector<pair<char, int>> solveIslands(vector<string> input)
{
    int n = input.size();
    int m = input[0].length();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    Queue<pair<int, int>> q;

    vector<pair<char, int>> result;

    for (int i = 0; i < n; ++i)
    {

        for (int j = 0; j < m; ++j)
        {
            if (input[i][j] != 'x' && visited[i][j] == false)
            {
                q.enqueue({i, j});
                visited[i][j] = true;

                int cnt = 0;

                while (!q.isEmpty())
                {
                    ++cnt;

                    int curX = q.first().first;
                    int curY = q.first().second;
                    q.dequeue();

                    //cout << "current element is:(" << curX << "," << curY << ")" << endl;

                    int newCoords[2][8] = {{1, 1, 1, -1, -1, -1, 0, 0},
                                           {1, 0, -1, 1, 0, -1, 1, -1}};

                    for (int k = 0; k < 8; ++k)
                    {
                        int newX = curX + newCoords[0][k];
                        int newY = curY + newCoords[1][k];

                        if (newX < n && newX > -1 && newY < m && newY > -1 && visited[newX][newY] == false && input[newX][newY] == input[i][j])
                        {
                            //cout << "       unqueued:(" << newX << "," << newY << ")" << endl;

                            q.enqueue({newX, newY});
                            visited[newX][newY] = true;
                        }
                    }
                }

                result.push_back({input[i][j], cnt});
            }
        }
    }

    return result;
}

int main()
{
    vector<string> input = {"AAAxBBxCCC", "xAxBBxxxxx", "AAxxxxxxDD"};

    vector<pair<char, int>> result = solveIslands(input);

    cout << "Number of islands is: " << result.size() << "\n";

    int idx = 0;
    for (int i = 1; i < result.size(); ++i)
    {
        if (result[idx].second < result[i].second)
        {
            idx = i;
        }
    }

    cout << "Biggest island is " << result[idx].first << " with size " << result[idx].second << "\n";

    system("pause");

    return 0;
}
