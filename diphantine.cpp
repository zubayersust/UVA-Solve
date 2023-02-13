#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b, int& x, int& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;

        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g)
{
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g)
        return false;

    x0 *= c / g;
    y0 *= c / g;

    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;

    return true;
}

void find_all_solution(int a, int b, int c, int gcd, int &x, int &y)
{
    int cnt = 0;
    while(true)
    {
        if(cnt == 10)
            break;

        int x_next = x + ((cnt + 1) * (b / gcd));
        int y_next = y - ((cnt + 1) * (a / gcd));

        if(x_next >= 0 && y_next >= 0)
            printf("ANS :: %d %d\n", x_next, y_next);

        cnt++;
    }
}

int main()
{
    int x, y, g;
    find_any_solution(202, 203, 606, x, y, g);
    //printf("%d %d %d\n", x, y, g);

    find_all_solution(202, 203, 606, g, x, y);

    printf("\n\n");

    find_any_solution(202, 203, 406, x, y, g);
    //printf("%d %d %d\n", x, y, g);

    find_all_solution(202, 203, 406, g, x, y);

    printf("\n\n");

    find_any_solution(202, 203, 206, x, y, g);
    //printf("%d %d %d\n", x, y, g);

    find_all_solution(202, 203, 206, g, x, y);

    printf("\n\n");

    find_any_solution(202, 203, 6, x, y, g);
    //printf("%d %d %d\n", x, y, g);

    find_all_solution(202, 203, 6, g, x, y);

    return 0;
}
