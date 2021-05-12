#include <iostream>
using namespace std;

int min(int a, int b)
{
    return (a < b ? a : b);
}
int max(int a, int b)
{
    return (a > b ? a : b);
}

int main()
{
    long int n;
    cin >> n;
    int ctr[5] = {0};
    int i, input, re = 0;
    for (i = 0; i < n; i++)
    {
        cin >> input;
        ctr[input]++;
    }
    int entering, leaving, moving;
    moving = min(ctr[1], ctr[2]);
    re += moving;
    ctr[1] -= moving;
    ctr[2] -= moving;
    ctr[3] += moving;
    if (ctr[1] > 0 && ctr[2] == 0)
    {
        moving = ctr[1] / 3;
        re += moving * 2;
        ctr[1] -= moving * 3;
        ctr[3] += moving;
        if (ctr[1] == 1)
        {
            if (ctr[3] >= 1)
            {
                re++;
            }
            else
            {
                if (ctr[4] >= 2)
                {
                    re += 2;
                }
                else
                {
                    re = -1;
                }
            }
        }
        if (ctr[1] == 2)
        {
            if (ctr[4] >= 1)
            {
                re += 2;
            }
            else
            {
                if (ctr[3] >= 2)
                {
                    re += 2;
                }
                else
                {
                    re = -1;
                }
            }
        }
    }
    if (ctr[1] == 0 && ctr[2] > 0)
    {
        moving = ctr[2] / 3;
        re += moving * 2;
        ctr[2] -= moving * 3;
        ctr[3] += moving * 2;
        if (ctr[2] == 1)
        {
            if (ctr[4] >= 1)
            {
                re++;
            }
            else
            {
                if (ctr[3] >= 2)
                {
                    re += 2;
                }
                else
                {
                    re = -1;
                }
            }
        }
        if (ctr[2] == 2)
        {
            re += 2; //merge
        }
    }
    cout << re;
    return 0;
}