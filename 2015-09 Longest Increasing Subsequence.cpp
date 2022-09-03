# include <iostream>
# include <vector>
# define N 65535

int main(void)
{

    int n;
    int arr[N];
    int LIS[N];
    //std::vector <std::vector> LIS_record;

    while(std::cin >> n)
    {
        // read array
        for (int i = 0; i < n; i++)
            std::cin >> arr[i];

        // init LIS
        for (int i = 0; i < n; i++)
        {
            LIS[i] = 1;
            //LIS_record[i].push_back(arr[i]);
        }


        // examine LIS[i] one by one
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j])
                {
                    LIS[i] = std::max(LIS[j] + 1, LIS[i]);
                    // copy LIS_record[j] to LIS_record[i]
                    // LIS_record[i].clear();
                    //for (int i = 0; i < LIS[j]; i++)
                        //LIS_record[i] = LIS_record[j]
                    //LIS_record[LIS[j]] = arr[i]
                }
            }
        }

        // find the largest value in LIS
        int ret = 0;
        //max_i = -1;
        for (int i = 0; i < n; i++)
            ret = std::max(ret, LIS[i]);
        std::cout << ret << std::endl;

    }
}
