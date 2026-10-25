#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

int MaxIndex(int* a, const int n)
{
    int imax = 0;
    for (int i = 1; i < n; i++)
        if (a[i] > a[imax])
            imax = i;
    return imax;
}

int FindZero(int* a, const int n, const int start)
{
    for (int i = start; i < n; i++)
        if (a[i] == 0)
            return i;
    return -1;
}

int Product(int* a, const int left, const int right)
{
    int p = 1;
    for (int i = left + 1; i < right; i++)
        p *= a[i];
    return p;
}

int Gather(int* a, int* t, const int n, const int start, int k)
{
    for (int i = start; i < n; i += 2)
        t[k++] = a[i];
    return k;
}

void CopyArray(int* from, int* to, const int n)
{
    for (int i = 0; i < n; i++)
        to[i] = from[i];
}

void Rearrange(int* a, const int n)
{
    int* t = new int[n];
    int k = Gather(a, t, n, 0, 0);
    Gather(a, t, n, 1, k);
    CopyArray(t, a, n);
    delete[] t;
}

int main()
{
    srand((unsigned)time(NULL));
    int n;
    cout << "n = ";
    cin >> n;
    if (n <= 0)
    {
        cout << "n must be positive" << endl;
        return 1;
    }

    int* a = new int[n];
    Create(a, n, -5, 5);
    Print(a, n);

    int imax = MaxIndex(a, n);
    cout << "max = " << a[imax] << ", index = " << imax << endl;

    int z1 = FindZero(a, n, 0);
    int z2 = -1;
    if (z1 != -1)
        z2 = FindZero(a, n, z1 + 1);

    if (z2 == -1)
        cout << "fewer than two zeros" << endl;
    else if (z2 == z1 + 1)
        cout << "no elements between zeros" << endl;
    else
        cout << "product = " << Product(a, z1, z2) << endl;

    Rearrange(a, n);
    Print(a, n);

    delete[] a;
    return 0;
}