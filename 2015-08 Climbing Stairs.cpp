# include <iostream>
# define N 100
int main(void)
{
    int n;
    long long solutions[N+1];

    std::cin >> n;

    solutions[1] = 1;
    solutions[2] = 2; // 2 or 1+1

    for (int i = 3; i <= n; i++)
        solutions[i] = solutions[i-1] + solutions[i-2];
    std::cout << solutions[n];

}
