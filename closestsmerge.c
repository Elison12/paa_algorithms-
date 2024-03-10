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

void merge(Point arr[], int l, int m, int r, int dim)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    Point L[n1];
    Point R[n2];
    for (int i = 0; i < n1; ++i)
    {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; ++i)
    {
        R[i] = arr[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (dim == 0)
        {
            if (L[i].x <= R[j].x)
            {
                arr[k++] = L[i++];
            }
            else
            {
                arr[k++] = R[j++];
            }
        }
        else
        {
            if (L[i].y <= R[j].y)
            {
                arr[k++] = L[i++];
            }
            else
            {
                arr[k++] = R[j++];
            }
        }
    }
    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

void merge_sort(Point arr[], int l, int r, int dim)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        merge_sort(arr, l, m, dim);
        merge_sort(arr, m + 1, r, dim);
        merge(arr, l, m, r, dim);
    }
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
    merge_sort(Px, 0, n - 1, 0);
    merge_sort(Py, 0, n - 1, 1);
    return closest_util(Px, Py, n);
}


int main(){
    int n;

    while(scanf("%d", &n) && n > 0){
        Point conj[10000];
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &conj[i].x, &conj[i].y);
        }
        

        double min_dist = closest(conj, n);

        if(min_dist < 10000)
            printf("%.4lf\n", min_dist);
        else
            printf("INFINITY\n");

    }
    return 0;
}