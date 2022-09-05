# include <iostream>
# include <vector>
# define MAX_n 9

/*

int len[6] = {1, 1, 1, 1, 1, 1};
This len[] stores the longest monotomically increasing subsequence till the i-th number
They len[0]~len[5] are initialized as one, as each represents the i-th number themselves

arr = 2 5 3 1 6 4
len = 1 1 1 1 1 1

now iterate each number thru arr to increase the numbers in len

arr = 2 5 3 1 6 4
len = 1 2 1 1 1 1
      | | (5>2)
----------------------
arr = 2 5 3 1 6 4
len = 1 2 2 1 1 1
      |   | (3>2)

arr = 2 5 3 1 6 4
len = 1 2 2 1 1 1
        | | (3<5)
-----------------------
arr = 2 5 3 1 6 4
len = 1 2 2 1 1 1
      |     | (1<2)

arr = 2 5 3 1 6 4
len = 1 2 2 1 1 1
        |   | (1<5)

arr = 2 5 3 1 6 4
len = 1 2 2 1 1 1
          | | (1<3)
-----------------------
arr = 2 5 3 1 6 4
len = 1 2 2 1 2 1
      |       |(6>2)

arr = 2 5 3 1 6 4
len = 1 2 2 1 3 1
        |     |(6>5)

arr = 2 5 3 1 6 4
len = 1 2 2 1 3 1
          |   |(6>5)

arr = 2 5 3 1 6 4
len = 1 2 2 1 3 1
            | |(6>1)
-----------------------
arr = 2 5 3 1 6 4
len = 1 2 2 1 3 2
      |         |(4>2)

arr = 2 5 3 1 6 4
len = 1 2 2 1 3 2
        |       |(4<5)

arr = 2 5 3 1 6 4
len = 1 2 2 1 3 3
          |     |(4>3)

arr = 2 5 3 1 6 4
len = 1 2 2 1 3 3
            |   |(4>1)

arr = 2 5 3 1 6 4
len = 1 2 2 1 3 3
              | |(4<6)

*/
int LIS[MAX_n];
long long arr[MAX_n];
std::vector <long long> solution_stack; // find one solution
std::vector <std::vector<long long>> return_stack; // record all the solutions

void print_stack(int ind)
{
    if (LIS[ind] == 1){
        // we found the start of the longest increasing sequence
        solution_stack.push_back(arr[ind]);
        // print the reversed stack
        std::vector <long long> temp;
        for (int i = solution_stack.size() - 1; i >= 0; i--)
        {
            //std::cout << solution_stack[i] << " ";
            temp.push_back(solution_stack[i]);
        }
        return_stack.push_back(temp);
        //std::cout << std::endl;
        solution_stack.pop_back();
    }

    for (int prev = 0; prev < ind; prev++)
    {
        // find the previous number of arr[ind] in the longest increasing sequence
        if ((LIS[prev] + 1 == LIS[ind]) && (arr[prev] < arr[ind]))
        {
            solution_stack.push_back(arr[ind]);
            print_stack(prev);
            solution_stack.pop_back();
        }
    }

}


int main(void)
{
    int test_cases;
    int N;

    std::cin >> test_cases;
    for (int t = 0; t < test_cases; t++)
    {
        std::cin >> N;
        for (int i = 0; i < N; i++)
            std::cin >> arr[i];


        // initialize
        for (int i = 0; i < N; i++)
            LIS[i] = 1;


        // iterate arr and update LIS
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j])
                    LIS[i] = std::max(LIS[i], LIS[j] + 1);
            }
        }

        // find the length of the longest
        int longest_len = 0;
        for (int i = 0; i < N; i++)
            longest_len = std::max(longest_len, LIS[i]);


        // backtrack where the LIS comes from
        solution_stack.clear();
        return_stack.clear();
        for (int i = 0; i < N; i++)
            if (LIS[i] == longest_len)
            {
                // std::cout << "ending with ind: " << i << std::endl;
                print_stack(i);
            }
        // print
        std::cout << return_stack.size() << std::endl;
        for (int i = 0; i < return_stack.size(); i++)
        {
            for (int j = 0; j < return_stack[i].size(); j++)
                std::cout << return_stack[i][j] << " ";
            std::cout << std::endl;
        }
    }





}
