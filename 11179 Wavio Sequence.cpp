# include <iostream>
# include <algorithm>
int main(void)
{
    int num;
    int arr[10000];
    int LIS[10000], RLIS[10000];
    while(std::cin >> num)
    {
        for (int i = 0; i < num; i++)

            std::cin >> arr[i];
        // LIS
        for (int i = 0; i < num; i++)
            LIS[i] = 1;
        for (int i = 0; i < num; i++)
            for (int j = 0; j < i; j++)
                if (arr[i] > arr[j]) // strict
                    LIS[i] = std::max(LIS[i], LIS[j]+1);

        // LIS from the right hand side
        std::reverse(arr, arr+num);
        for (int i = 0; i < num; i++)
            RLIS[i] = 1;
        for (int i = 0; i < num; i++)
            for (int j = 0; j < i; j++)
                if (arr[i] > arr[j]) // strict
                    RLIS[i] = std::max(RLIS[i], RLIS[j]+1);
        std::reverse(RLIS, RLIS + num);

        int max_len = -1;
        for (int center = 0; center < num; center++)
            max_len = std::max(std::min(LIS[center], RLIS[center]), max_len);
        std::cout << max_len*2-1 << std::endl;

    }
}
