# include <iostream>
# include <limits>
# define N 18

int main(void)
{
    int n;
    int arr[N];
    int case_cnt = 1;

    while(std::cin >> n)
    {
        for (int i = 0; i < n; i++)
            std::cin >> arr[i];

        int record_max = 0 ; // as question requires
        // since a negative num times previous accumulated min
        // can become very large. Hence, keep track of min and max
        int now_max = arr[0];
        int now_min = arr[0];

        for (int i = 1; i < n; i++)
        {
            now_max = std::max(now_max, std::max(now_max * arr[i], now_min * arr[i]));
            now_min = std::min(now_min, std::min(now_min * arr[i], now_max * arr[i]));
            record_max = std::max(record_max, now_max);
        }

        std::cout << "Case #" << case_cnt << ": The maximum product is " << record_max << "." << std::endl;
        std::cout << "\n";

        case_cnt += 1;
    }
}
