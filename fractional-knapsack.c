#include <stdio.h>


void swap1(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}
void swap2(int *a, int *b)
{
    int temp = *a; 
    *a = *b;
    *b = temp;
}

void sortArr(int p[], int w[], float p_vs_w[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p_vs_w[j] < p_vs_w[j + 1]) 
            {
                swap1(&p_vs_w[j], &p_vs_w[j + 1]);
                swap2(&p[j], &p[j + 1]);
                swap2(&w[j], &w[j + 1]);
            }
        }
    }
}

float findProfit(int p[], int w[], float p_vs_w[], int n, int wt)
{
    float profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (w[i] <= wt)
        {
            wt = wt - w[i];
            profit = profit + p[i];
        }
        else
        {
            profit = profit + ((float)wt / w[i]) * p[i];
            break;
        }
    }

    return profit;
}

int main()
{
    int n = 2;
    int p[10] = {60,100};
    int w[10] = {10, 20};
    int W = 50;
    float profit_vs_wt[10];

    for (int i = 0; i < n; i++)
    {
        profit_vs_wt[i] = (float)p[i] / w[i];
    }

    sortArr(p, w, profit_vs_wt, n);

    printf("%f", findProfit(p, w, profit_vs_wt, n, W));
    return 0;
}
