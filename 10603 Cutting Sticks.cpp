# include <iostream>
# include <limits>
# define min(a,b) ((a<b)?a:b)

// len_stick = 100
// 3 cuts at 25, 50, 75
// construct arr[5] = {0, 25, 50, 75, 100}
// try to convert to matrix multiplication problem
// say A1 = (0~25), A2 = (25~50), A3 = (50~75), A4 = (75~100)... anyway finally we have to cut to these four pieces.
// 1. check optimal subproblem
// A1A2A3A4 = (A1... Ak)(AK+1... A4)+((arr[4]-arr[k])+(arr[k]-arr[1-1]))
//          = (A1... Ak)(AK+1... A4)+(arr[4]arr[1-1])
// say c[i][j] is the minimum cost of Ai...Aj
// then if c[1][4] is optimal, c[i][k] and c[k+1][4] must be optimal
// 2. recursion
// c[i][j] = min_{i<=k<j}{c[i][k] + c[k+1][j] + arr[j]-arr[i-1]}

int main(void){
    int len_stick;
    int arr[50];
    int c[50][50];

    while(std::cin >> len_stick && len_stick)
    {
        int num_cut;
        std::cin >> num_cut;
        arr[0] = 0;
        for (int i = 1; i <= num_cut; i++)
            std::cin >> arr[i];
        arr[num_cut + 1] = len_stick;

        int whole_problem_size = num_cut + 1; //4
        // init c
        for (int i = 1; i <= whole_problem_size; i++)
            c[i][i] = 0;
        // build c
        for (int d = 2; d <= whole_problem_size; d++)
        {
            for (int i = 1; i <= whole_problem_size - d + 1; i++)
            {
                 int j = i + (d-1);
                 int cutting_cost = arr[j] - arr[i-1];
                 int mmin = std::numeric_limits<int>::max();
                 for (int k = i; k < j; k++)
                    mmin = min(mmin, c[i][k] + c[k+1][j] + cutting_cost);
                c[i][j] = mmin;
            }
        }
        std::cout << "The minimum cutting is " << c[1][whole_problem_size] << std::endl;
    }
}
