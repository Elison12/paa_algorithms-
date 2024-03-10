#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int is_solvable(int n, int m, char maze[MAX][MAX])
{
    int visited[MAX][MAX] = {0};

    int start_x = 0, start_y = 0;
    int queue_x[MAX * MAX], queue_y[MAX * MAX];
    int front = 0, rear = 0;
    queue_x[rear] = start_x;
    queue_y[rear] = start_y;
    visited[start_x][start_y] = 1;
    rear++;

    while (front < rear)
    {
        int x = queue_x[front];
        int y = queue_y[front];
        front++;
        if (x == n - 1 && y == m - 1)
        {
            return 1;
        }
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && maze[nx][ny] == '.')
            {
                visited[nx][ny] = 1;
                queue_x[rear] = nx;
                queue_y[rear] = ny;
                rear++;
            }
        }
    }

    return 0;
}

int main()
{
    int n, m;
    char maze[MAX][MAX];

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", maze[i]);
    }

    if (is_solvable(n, m, maze))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}
