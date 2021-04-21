#include <stdio.h>
#include <string.h>
int firstword(char *arr, int i);
int secondword(char *arr, int i);
int thirdword(char *arr, int i);
int main()
{
    char arr[300];
    int j = 0;
    scanf("%s", arr);
    int l = strlen(arr);
    for (int i = 0; i < l; i++)
    {
        int m, n, p, u;
        m = firstword(arr, i);
        n = secondword(arr, i);
        p = thirdword(arr, i);
        if (m != 1 && n != 1 && p != 1)
        {
            char r = arr[i];
            j++;
            printf("%c", r);
            u = firstword(arr, i + 1);
            if (u == 1)
            {
                printf(" ");
            }
        }
    }
    return 0;
}
 
int firstword(char *arr, int n)
{
    if (arr[n] == 'W')
    {
        if (arr[n + 1] == 'U' && arr[n + 2] == 'B')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
int secondword(char *arr, int n)
{
    if (arr[n] == 'U')
    {
        if (arr[n - 1] == 'W' && arr[n + 1] == 'B')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
int thirdword(char *arr, int n)
{
    if (arr[n] == 'B')
    {
        if (arr[n - 1] == 'U' && arr[n - 2] == 'W')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}