#include <bits/stdc++.h>

using namespace std;

int same_place(int *a, int p, int s, int e)
{
    int temp = 0;
    for (int i = s; i <= e; i++)
    {
        if (a[i] == p)
        {
            temp++;
        }
    }
    return temp;
}

void custom_sort(int *a, int *b, int n)
{
    int flag;
    int temp;
    for (int i = 0; i < n; i++)
    {
        flag = 1;
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] > a[j - 1])
            {
                flag = 0;
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                temp = b[j];
                b[j] = b[j - 1];
                b[j - 1] = temp;
            }
        }

        if (flag)
        {
            return;
        }
    }
}

int starting_index(int *a, int q, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == q)
        {
            return i;
        }
    }
    return n-1;
}
int ending_index(int *a, int starting, int value, int n)
{
    for (int i = starting; i < n; i++)
    {
        if (a[i] != value)
        {
            return i-1;
        }
    }
    return n-1 ;
}
int finding_penalty(int *a, int s, int e, int k)
{
    if (s==e)
    {
        return a[s];
    }
    
    sort(a + s, a + (e+1));
    return a[k - 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    int questions, penalty;
    int starting, ending;
    cin >> n >> k;
    int *question_solve = new int[n];
    int *penalty_time = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> question_solve[i] >> penalty_time[i];
    }
    custom_sort(question_solve, penalty_time, n); //checked
    questions = question_solve[k - 1];            //checked
    starting = starting_index(question_solve, questions, n);
    ending = ending_index(question_solve, starting, questions, n);
    penalty = finding_penalty(penalty_time, starting, ending, k);
    cout << same_place(penalty_time, penalty, starting, ending) << endl;
    delete [] question_solve;
    delete [] penalty_time;
    return 0;
    //7 2 4 10 4 10 4 10 3 20 2 1 2 1 1 10
    //5 4 3 1 3 1 5 3 3 1 3 1
}