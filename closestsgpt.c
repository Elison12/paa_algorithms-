#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 1e9

typedef struct
{
    double x;
    double y;
} Point;



#include <stdio.h>

void swap(void* a, void* b, size_t size) {
    char* p = a, *q = b, tmp;
    for (size_t i = 0; i < size; ++i) {
        tmp = p[i];
        p[i] = q[i];
        q[i] = tmp;
    }
}

void myqsort(void* base, size_t nmemb, size_t size,
           int (*compar)(const void*, const void*)) {
    if (nmemb <= 1) {
        return;
    }
    char* p = (char*)base;
    char* lo = p;
    char* hi = p + (nmemb-1)*size;
    char* pivot = p + (nmemb/2)*size;
    while (lo <= hi) {
        while (compar(lo, pivot) < 0) {
            lo += size;
        }
        while (compar(hi, pivot) > 0) {
            hi -= size;
        }
        if (lo <= hi) {
            swap(lo, hi, size);
            lo += size;
            hi -= size;
        }
    }
    myqsort(base, (hi - (char*)base)/size + 1, size, compar);
    myqsort(lo, (char*)base + nmemb*size - lo, size, compar);
}


int compare_x(const void *a, const void *b)
{
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compare_y(const void *a, const void *b)
{
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->y - p2->y);
}

double distance(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double brute_force(Point P[], int n)
{
    double min_dist = INF;
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
    myqsort(strip, size, sizeof(Point), compare_y);
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
    myqsort(Px, n, sizeof(Point), compare_x);
    myqsort(Py, n, sizeof(Point), compare_y);
    return closest_util(Px, Py, n);
}

int main()
{
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    Point P[n];
    printf("Enter the coordinates of the points (x y):\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf %lf", &P[i].x, &P[i].y);
    }
    double dist = closest(P, n);
    printf("The closest pair of points have a distance of %.2lf\n", dist);
    return 0;
}