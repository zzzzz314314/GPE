# include <iostream>
# include <sstream>
// convert int <-> string
//https://home.gamer.com.tw/creationDetail.php?sn=4114818

int arr[20];
int accum[21][201];

int main(void)
{
    int case_num;
    std::cin >> case_num;

    // this one is needed if there is previous input (say "4\n")
    // the "4" will be extracted to case_num while "\n" is left in stream
    // then std::getline() sees "\n1 2 1 2 1", it steps at "\n", which seems not reading.
    // https://stackoverflow.com/questions/21567291/why-does-stdgetline-skip-input-after-a-formatted-extraction
    std::cin.ignore();
    for (int c = 0; c < case_num; c++)
    {
        std::string input;
        std::getline(std::cin, input);
        std::stringstream ss(input); // now use ss >> temp to read out

        int temp;
        int arrlen = 1;
        int sum = 0;

        while(ss >> temp)
        {
            arr[arrlen++] = temp; //start from index 1. this is easier
            sum += temp;
        }
        arrlen -= 1;
        //std::cout << "sum: " << sum << std::endl;
        if (sum % 2)
        {
            std::cout << "NO" << std::endl;
            continue;
        }

        sum /= 2;
        //std::cout << "half sum: " << sum << std::endl;
        //std::cout << "arrlen: " << arrlen << std::endl;


        // start 0-1 knapsack
        // we want to know if packing some of the packages can sum up to "sum"
        // we want to know at if any of accum[i=1, 2, ... arrlen][sum] == sum
        // the difference to original 0-1 knapsack is now value and weight are the same (arr[i])
        // the same thing to original 0-1 knapsack is to pack as more value (summed arr[i]) as possible
        // yet will not exceed the budget (half sum here) => as close as possible to half sum but smaller

        for (int i = 0; i <= arrlen; i++)
            accum[i][0] = 0;
        for (int j = 0; j <= sum; j++)
            accum[0][j] = 0;

        for (int i = 1; i <= arrlen; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i] > j) // cannot afford arr[i] for budget j
                    accum[i][j] = accum[i-1][j];
                else // can afford, try put or not
                    accum[i][j] = std::max(accum[i-1][j], accum[i-1][j-arr[i]]+arr[i]);
            }
        }

        // print accum
        /*
        for (int i = 0; i <= arrlen; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                std::cout << accum[i][j] << " ";
            }
            std::cout << std::endl;
        }
        */

        /*
        bool can = false;
        for (int i = 1; i <= arrlen; i++)
        {
            if (accum[i][sum] == sum)
            {
                std::cout << "YES" << std::endl;
                can = true;
                break;
            }

        }
        if (!can)
            std::cout << "NO" << std::endl;
        */

        // examine only accum[arrlen][sum] is enough
        // think: as close as possible to half sum but smaller
        if (accum[arrlen][sum] == sum)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;


    }
}
