# include <iostream>
# include <sstream>
# include <string>
# include <vector>

// a classic 0-1 knapsack problem. Similar to 10621 Luggage
// pay attention to the backtracking!

int arr[30];
// for dp
int dp[31][10000];
int arr_len = 0;
int sum = 0;
// for backtrack, storing solutions
std::vector<std::vector<int>> solutions;
std::vector<int> solution;

void backtrack(int i, int j)
{

    // termination
    if (i == 0 || j <= 0)
    {
        solutions.push_back(solution);
        return;
    }

    // cannot pack item i with capacity j
    if (arr[i] > j)
        backtrack(i-1, j);

    // can pack item i with capacity, try pack or not to get max
    else
    {
        // backtrack from dp[i][j] = dp[arr_len][sum]
        // how do we know if the item arr[i] is taken?
        // we check the value of dp[i-1][j] and dp[i-1][j-w[i]]+v[i]
        // if dp[i-1][j] is larger, we do not take arr[i]
        // if dp[i-1][j-w[i]]+v[i] is larger, we take arr[i]
        // if the both have same value, both are possible solutions.
        if (dp[i-1][j] == (dp[i-1][j-arr[i]]+arr[i]))
        {
            // both paths are possible (we have solutions for including arr[i] and not including arr[i])
            // including arr[i]
            solution.push_back(arr[i]);
            backtrack(i-1, j-arr[i]);
            solution.pop_back();

            // not including arr[i]
            backtrack(i-1, j);
        }
        if (dp[i-1][j] > dp[i-1][j-arr[i]]+arr[i])
        {
            // not including arr[i]
            backtrack(i-1, j);
        }
        if (dp[i-1][j] < dp[i-1][j-arr[i]]+arr[i])
        {
            // including arr[i]
            solution.push_back(arr[i]);
            backtrack(i-1, j-arr[i]);
            solution.pop_back();
        }
    }
}

int main(void)
{
    // for reading array
    std::string s;
    int temp;

    while(getline(std::cin, s) && s[0] != '.')
    {
        // read array
        s = s.substr(1, s.length()-2);
        std::stringstream ss(s);
        int arr_len = 0;
        int sum = 0;
        while(ss >> temp)
        {
            arr[++arr_len] = temp; // the array starts from index=1 to index=arr_len
            sum += temp;
        }
        // {1, 3, 5, 7, 12}
        // arr_len = 5
        // arr = [0, 1, 3, 5, 7, 12]

        // quick check
        if (sum % 2)
        {
            std::cout << "No such subset" << std::endl;
            continue;
        }

        // to classic 0-1 knapsack problem
        sum /= 2;

        // init
        for (int i = 0; i <= arr_len; i++)
            dp[i][0] = 0;
        for (int i = 0; i <= sum; i++)
            dp[0][i] = 0;
        // start
        for (int i = 1; i <= arr_len; i++)
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i] > j)
                    // for sum=j, we cannot afford arr[i]
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-arr[i]] + arr[i]);
            }
        if (dp[arr_len][sum] == sum)
        {
            backtrack(arr_len, sum);
            std::cout << solutions.size() << " subsets." << std::endl;
            // print the solutions
            for (int i = 0; i < solutions.size(); i++)
            {
                for (int j = solutions[i].size()-1; j >= 0; j--)
                {
                    if (j == solutions[i].size()-1)
                        std::cout << "{" << solutions[i][j] << " ";
                    else if (j == 0)
                        std::cout << solutions[i][j] << "}" << std::endl;
                    else
                        std::cout << solutions[i][j] << " ";

                }
            }
        }
        else
            std::cout << "No such subset" << std::endl;
    }
}
