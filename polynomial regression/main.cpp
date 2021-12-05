#include <iostream>
#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int i, j, z, n, k, m;
long double** tab_X;
long double** tab_y;
long double** tab_XT;
long double** tab_XTX;
long double** a;
long double** tab_XTX_XT;
long double** tab_odw;
long double** A;
long double** YY;

void menu()
{
    cout << "\n PODAJ LICZBE PUNKTOW\n ";
    cin >> n;
    cout << "\n PODAJ POTEGE\n ";
    cin >> k;
    m = k + 1;
    tab_X = new long double*[n];
    for(i = 0; i < n; ++i)
        tab_X[i] = new long double[k+1];

    tab_y = new long double*[n];
    for(i = 0; i < n; ++i)
        tab_y[i] = new long double[1];

    tab_XT = new long double*[k+1];
    for(i = 0; i < k+1; ++i)
        tab_XT[i] = new long double[n];

    tab_XTX = new long double*[k+1];
    for(i = 0; i < k+1; ++i)
        tab_XTX[i] = new long double[k+1];

    a = new long double*[1000];
    for(i = 0; i < 1000; ++i)
        a[i] = new long double[2000];

    tab_XTX_XT = new long double*[k+1];
    for(i = 0; i < k+1; ++i)
        tab_XTX_XT[i] = new long double[n];

    tab_odw = new long double*[k+1];
    for(i = 0; i < k+1; ++i)
        tab_odw[i] = new long double[k+1];

    A = new long double*[k+1];
    for(i = 0; i < k+1; ++i)
        A[i] = new long double[1];

    YY = new long double*[n];
    for(i = 0; i < n; ++i)
        YY[i] = new long double[1];
}
void losuj_xy()
{
    srand((unsigned int)time((time_t *)NULL));
    for(i = 0; i < n; i++)
    {
        tab_X[i][0] = 1;
        tab_X[i][1] = ( std::rand() % 1920);
        tab_y[i][0] = ( std::rand() % 555)+300;
        for(j = 2; j <= k; j++)
        {
            tab_X[i][j] = pow(tab_X[i][1], j);
        }
    }
}
void wypisz_tablice(long double **matrix, int rows, int cols)
{
    for(i = 0; i < rows; ++i)
    {
        for(j = 0; j < cols; ++j)
        {
            cout << matrix[i][j];
            cout << " , " ;
        }
        cout << "\n\n" ;
    }
}
void transponowanie_X()
{
    for(i = 0; i < k+1; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            tab_XT[i][j] = tab_X[j][i];
        }
    }
}
void mnozenie_macierzy(long double **matrix1, long double **matrix2, long double **matrix3, int rows1, int cols1, int rows2, int cols2)
{
    for (i = 0; i < rows1; i++)
    {
        for( j = 0; j < cols2; j++)
        {
            matrix3[i][j] = 0;
            for (z = 0; z < cols1; z++)
            {
                matrix3[i][j] += matrix1[i][z] * matrix2[z][j];
            }
        }
    }
}
void odwracanie_XTX()
{
    for(i=0; i<m; i++)
    {
        for(j=0; j<m; j++)
        {
            a[i][j]=tab_XTX[i][j];
        }
    }
    long double d;
    for(i = 0; i < m; i++)
        for(j = 0; j <2*m; j++)
            if(j==(i+m))
                a[i][j]=1;

    for(i=m; i>0; i--)
    {
        if(a[i-1][1]<a[i][1])
            for(j=0; j<m*2; j++)
            {
                d=a[i][j];
                a[i][j]=a[i-1][j];
                a[i-1][j]=d;
            }
    }
    for(i=0; i<m; i++)
    {
        for(j=0; j<m*2; j++)
            if(j!=i)
            {
                d=a[j][i]/a[i][i];
                for(z=0; z<=m*2; z++)
                {
                    a[j][z]-=a[i][z]*d;
                }
            }
    }
    for(i=0; i<m; i++)
    {
        d=a[i][i];
        for(j=0; j<m*2; j++)
            a[i][j]=a[i][j]/d;
    }
    for(i=0; i<m; i++)
    {
        for(j=m; j<m*2; j++)
            tab_odw[i][j-m]=a[i][j];
    }
}
void wypisz_wzor()
{
    cout << "\n---------------------------------\n  WZOR FUNKCJI \n---------------------------------\n\n";
    for(i = 0; i < k+1; i++)
    {
        if(A[i][0] <= 0)
        {
            cout << A[i][0] <<"x^"<< i;
        }
        else
        {
            cout << "+" << A[i][0] <<"x^"<< i;
        }
    }
    cout << "\n\n";
}
void rysuj()
{
    int sx, sy, kx, ky;
    double x, y, xp, yp;
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth,screenHeight,"REGRESJA NIELINIOWA");
    x = 0;
    sx = 0;
    sy = 0;
    xp = -1;
    kx = screenWidth;
    ky = screenHeight;

    for(i = 0; i < n; i++)
    {
        circle(tab_X[i][1], ky-tab_y[i][0], 5);
    }
    for(x = -1; x < kx; x++)
    {
        y = 0;
        for(i = 0; i < k+1; i++)
        {
            y += A[i][0] * pow(x, i);
        }
        line(xp, ky-yp, x,ky-y);
        xp = x;
        yp = y;
    }
    getch();
    closegraph();
}
int main()
{
    menu();
    losuj_xy();
    transponowanie_X();
    mnozenie_macierzy((long double **)tab_XT, (long double **)tab_X, (long double **)tab_XTX, k+1, n, n, k+1);
    odwracanie_XTX();
    mnozenie_macierzy((long double **)tab_odw, (long double **)tab_XT, (long double **)tab_XTX_XT, k+1, k+1, k+1, n);
    mnozenie_macierzy((long double **)tab_XTX_XT, (long double **)tab_y, (long double **)A, k+1, n, n, 1);
    mnozenie_macierzy((long double **)tab_X, (long double **)A, (long double **)YY, n, k+1, k+1, 1);
    //wypisz_tablice((long double **)tab_y, n, 1);
    wypisz_tablice((long double **)tab_X, n, k+1);
    //wypisz_tablice((long double **)tab_XT, k+1, n);
    //multiply_XTX();
    //wypisz_tablice((long double **)tab_XTX, k+1, k+1);
    //multiply_odXTX_XT();
    //wypisz_tablice((long double **)tab_XTX_XT, k+1, n);
    //multiply_XTXXT_Y();
    //wypisz_tablice((long double **)tab_odw, k+1, k+1);
    cout << "\n---------------------------------------------------------------\n  WSPOLCZYNNIKI FUNKCJI (ZACZYNAJAC OD X^0, X^1...) \n---------------------------------------------------------------\n\n";
    wypisz_tablice((long double **)A, k+1, 1);
    cout << "\n---------------------------------------------------------------\n";
    wypisz_tablice((long double **)YY, n, 1);
    cout << "\n---------------------------------------------------------------\n";
    cout << "\n---------------------------------------------------------------\n";
    wypisz_tablice((long double **)tab_y, n, 1);
    cout << "\n---------------------------------------------------------------\n";
    wypisz_wzor();
    rysuj();
}
