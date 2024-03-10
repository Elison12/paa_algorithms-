#include <stdio.h>
#include <stdlib.h>

int findRoute(int maze[5][5], int r, int c)
{
    findRouteHelper(maze, 0, 0);
}

int findRouteHelper(int maze[5][5], int i, int j)
{
    if (i > 4 || i < 0 || j > 4 || j < 0)
        return 0;

    if (maze[i][j] == 1 && i == 4 && j == 4)
        return 1;

    if (maze[i][j] == 0)
        return 0;

    int r = findRouteHelper(maze, i, j + 1);

    if (r)
        return 1;

    int d = findRouteHelper(maze, i + 1, j);

    if (d)
        return 1;

    int l = findRouteHelper(maze, i, j - 1);

    if (l)
        return 1;

    return 0;
}

int main() 
{

    int maze[5][5] = {{1, 1, 0, 1, 1}, {0, 1, 0, 1, 0}, {1, 1, 1, 1, 0}, {0, 1, 0, 1, 0}, {1, 0, 1, 1, 1}};

    int k = findRoute(maze, 5, 5);

    printf("%d", k); // k prints whether a route is there or not

    return 0;
}