# include <iostream>
# include <cmath>
// Dijkstra and Floyd should both work (both needs a bit adaptation)
// we use Floyd here since it is easy to code
int main(void)
{
    int arr[101][101];
    int N; // num of city (vertex)
    int R; // num of road (edge)
    int from, to, d, tourists;
    int case_cnt = 1;

    while(std::cin >> N >> R && N && R)
    {
        // init
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                // Floyd
                // arr[i][j] = std::numeric_limits<int>.max();

                // assume no any capacity
                arr[i][j] = 0;
            }
        }

        // read
        for (int k = 0; k < R; k++)
        {
            std::cin >> from >> to >> d;
            arr[from][to] = d;
        }

        std::cin >> from >> to >> tourists;

        // Floyd relexation
        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++)
                    // Floyd
                    // arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j])
                    arr[i][j] = std::max(arr[i][j], std::min(arr[i][k], arr[k][j]));

        // consider the tourist guide
        int ans = std::ceil(float(tourists) / float((arr[from][to] - 1)));
        std::cout << "Scenario #" << case_cnt << std::endl;
        std::cout << "Minimum Number of Trips = " << ans << std::endl;
        std::cout << std::endl;

        case_cnt += 1;



    }
}
