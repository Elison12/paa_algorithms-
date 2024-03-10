#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
} Point;

double distance(Point a, Point b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double brute_force(Point P[], int n)
{
    double min_dist = INFINITY;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            double dist = distance(P[i], P[j]);
            if (dist < min_dist)
            {
                min_dist = dist;
            }
        }
    }
    return min_dist;
}

double strip_closest(Point strip[], int size, double d)
{
    double min_dist = d;
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min_dist; ++j)
        {
            double dist = distance(strip[i], strip[j]);
            if (dist < min_dist)
            {
                min_dist = dist;
            }
        }
    }
    return min_dist;
}

double closest_util(Point Px[], Point Py[], int n)
{
    if (n <= 3)
    {
        return brute_force(Px, n);
    }
    int mid = n / 2;
    Point mid_point = Px[mid];
    Point Pyl[mid + 1];
    Point Pyr[n - mid - 1];
    int li = 0, ri = 0;
    for (int i = 0; i < n; ++i)
    {
        if (Py[i].x <= mid_point.x)
        {
            Pyl[li++] = Py[i];
        }
        else
        {
            Pyr[ri++] = Py[i];
        }
    }
    double dl = closest_util(Px, Pyl, mid);
    double dr = closest_util(Px + mid, Pyr, n - mid);
    double d = fmin(dl, dr);
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (fabs(Py[i].x - mid_point.x) < d)
        {
            strip[j++] = Py[i];
        }
    }
    return fmin(d, strip_closest(strip, j, d));
}

double closest(Point P[], int n)
{
    Point Px[n];
    Point Py[n];
    for (int i = 0; i < n; ++i)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }
    qsort(Px, n, sizeof(Point), (const void *a, const void *b))
    {
        Point *pa = (Point *)a;
        Point *pb = (Point *)b;
        if (pa->x < pb->x)
        {
            return -1;
        }
        else if (pa->x > pb->x)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    qsort(Py, n, sizeof(Point), (const void *a, const void *b))
    {
        Point *pa = (Point *)a;
        Point *pb = (Point *)b;
        if (pa->y < pb->y)
        {
            return -1;
        }
        else if (pa->y > pb->y)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return closest_util(Px, Py, n);
}

int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    double min_dist = closest(P, n);
    printf("The smallest distance is %lf", min_dist);
    return 0;
}
