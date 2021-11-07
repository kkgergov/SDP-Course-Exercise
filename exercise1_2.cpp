#include <iostream>
#include <vector>
#include <stack>
#include "staticQueue.h"
using namespace std;

//EXERCISE 1
void generateBool(int n)
{
    Queue<string> q;
    q.enqueue("0");
    q.enqueue("1");

    while (!q.isEmpty())
    {
        string elem = q.first();
        q.dequeue();

        if (elem.length() == n)
        {
            cout << elem << endl;
        }
        else
        {
            q.enqueue(elem + "0");
            q.enqueue(elem + "1");
        }
    }
}

//EXERCISE 2
struct Point
{
    int x, y;

    Point()
    {
        x = -1;
        y = -1;
    }

    Point(int k, int p)
    {
        x = k;
        y = p;
    }

    bool operator==(const Point &other)
    {
        return x == other.x && y == other.y;
    }
};

//the algorithm will always be correct, because we are essentialy doing BFS and when we visit new node it will always be the shortest path from source
void shortest_path(Point a, Point b)
{
    vector<vector<bool>> visited(8, vector<bool>(8, false)); //already visited points are ignored to avoid getting stuck in infinite loop
    vector<vector<Point>> previous(8, vector<Point>(8));     //at (x,y) tells us the (x,y) of the previous point, nil value is the point (-1,-1)

    Queue<Point> q;
    q.enqueue(a); //put the starting point in queue
    visited[a.x][a.y] = true;

    while (!q.isEmpty())
    {
        Point elem = q.first();
        q.dequeue();

        if (elem == b) //we have found the goal
        {
            //trace back the path and display the length

            stack<Point> s;

            s.push(elem);

            while (s.top().x != -1 && s.top().y != -1)
            {
                s.push(previous[s.top().x][s.top().y]);
            }
            s.pop();

            cout << "The shortest path is of length: " << s.size() - 1 << endl;

            cout << "And the points are: ";
            while (!s.empty())
            {
                cout << "(" << s.top().x << ", " << s.top().y << ")";
                s.pop();
            }
            cout << endl;
        }
        else
        {

            int x = elem.x;
            int y = elem.y;

            int mov[2][8] = {{2, 2, 1, 1, -1, -1, -2, -2}, {1, -1, 2, -2, 2, -2, 1, -1}};

            for (int i = 0; i < 8; ++i)
            {
                int newX = x + mov[0][i];
                int newY = y + mov[1][i];
                if (newX > -1 && newX < 8 && newY > -1 && newY < 8 && visited[newX][newY] == false) //if the point is in the table and not yet visited
                {
                    //cout << "   equeued:" << newX << newY << "\n";

                    q.enqueue(Point{newX, newY});
                    previous[newX][newY] = elem;
                    visited[newX][newY] = true;
                }
            }

            //cout << "visited:" << elem.x << elem.y << "\n";
        }
    }
}


int main()
{
    //generateBool(5);
    shortest_path(Point{0, 0}, Point{7, 7});
    system("pause");
    return 0;
}