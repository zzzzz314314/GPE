# include <iostream>

int main(void)
{
    int m, n, t;

    while(std::cin >> m >> n >> t)
    {
        int min_burger_time = std::min(m, n);
        int max_burger_time = std::max(m, n);

        int max_burger_num = t / min_burger_time; // 5/3=1
        int best_remaining_time = t - min_burger_time * max_burger_num; // as small as possible

        // 1. decrease the # eaten smaller hamburger,
        // 2. try to add # eaten bigger smaller hamburger to fill the remaining time
        // 3. keep the best_remaining time

        // 1. decrease the # eaten smaller hamburger
        for (int i = max_burger_num; i >= 0; i--) // i denotes # eaten small hamburger
        {
            // 2. try to add # eaten bigger smaller hamburger to fill the remaining time
            int cur_remaining_time = t - i * min_burger_time;
            int bigger_burger_num = cur_remaining_time / max_burger_time;
            cur_remaining_time -= bigger_burger_num * max_burger_time;

            // 3. keep the best_remaining time
            if (cur_remaining_time < best_remaining_time)
            {
                best_remaining_time = cur_remaining_time;
                max_burger_num = i + bigger_burger_num;
            }

        }

        std::cout << max_burger_num;
        if (best_remaining_time > 0)
            std::cout << " " << best_remaining_time;
        std::cout << std::endl;

    }
}
