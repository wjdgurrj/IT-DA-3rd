#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <stack>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int arr[1001][1001];
//int visit[1001][1001];

int x, y;
int n, m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs()
{
    queue<pair<int, int>> q;

    q.push(make_pair(x, y));
    arr[x][y] = 2;  

    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (arr[nx][ny] == 1) //갈수있는곳이면
            {
                q.push({nx, ny});
                arr[nx][ny] = arr[a][b] + 1; //갈수있는 곳에 +1
            }
        }
    }
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2) { //2인 곳 저장
                x = i;
                y = j;
            }

        }

    bfs();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int ans = arr[i][j];

            if(ans)
                cout << ans-2;
            else
            {
                cout << 0;
            }
            
        }
        cout << endl;
    }
    return 0;
}