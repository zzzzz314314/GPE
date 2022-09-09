# include <iostream>
int dp[51];
int main(void)
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= 50; i++)
        dp[i] = dp[i-1] + dp[i-2];

    int in;
    while(std::cin >> in && in != 0)
        std::cout << dp[in] << std::endl;
}
