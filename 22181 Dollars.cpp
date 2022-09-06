# include <stdio.h>
// dollar change is similar to unbounded 0-1 knapsack
// one kind of dollar is unlimited provided
// classic 0-1 knapsack:
// c[i, j] = max(c[i-1][j], c[i-1][j-w[i]]+v[i])
//               no i          include i, track from no i case
//                                        since i is yes or no
// unbounded 0-1 knapsack:
// c[i, j] = max(c[i-1][j], c[i][j-w[i]]+v[i])
//               no i          include i, track from previous having i case
//                                        since i could have been taken
// Also, for this question, weight=value
int c[11+1][30000+1];

int main(void)
{
    int v[12] = {0, 10000, 5000, 2000, 1000, 500, 200, 100,
                 50, 20, 10, 5}; // index starts from 1

    // init
    for (int i = 0; i <= 11; i++)
        // this is classic/unbounded knapsack
        // c[i][0] = 0;
        // this is coin change
        c[i][0] = 1; // not using any coin, we can sum to 0, this is one coin change way
    for (int j = 0; j <= 30000; j++)
        c[0][j] = 0; // we have no coin at all, hence 0 coin change way for any numbers

    for (int i = 1; i <= 11; i++)
    {
        for (int j = 1; j <= 30000; j++)
        {
            if (v[i] > j)
                c[i][j] = c[i-1][j];
            else
                // this is classic 0-1 knapsack (take OR not take)
                // c[i][j] = max(c[i-1][j], c[i-1][j-v[i]] + v[i]);
                // this is unbounded 0-1 knapsack (take OR not take)
                // c[i][j] = max(c[i-1][j], c[i][j-v[i]] + v[i]);
                // this is dollar change (take + not take)
                c[i][j] = c[i-1][j] + c[i][j-v[i]];
        }
    }

    int input1, input2;
    while(scanf("%d.%d", &input1, &input2) != EOF && !(input1 == 0 && input2 == 0))
    {
        // NOTE THE PRINT FORMAT
        printf("%3d.%02d%17d\n", input1, input2, c[11][input1*100+input2] );
    }

}
