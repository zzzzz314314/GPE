# include <iostream>
# include <vector>
# include <stack>

std::vector <int> find_left_smaller(int * arr, int N)
{
    std::vector <int> left_smaller(N);
    std::stack <int> s;
    s.push(-1);

    for (int i = 0; i < N; i++)
    {
        while (s.top() != -1 && arr[s.top()] >= arr[i])
            s.pop();
        left_smaller[i] = s.top();
        s.push(i);
    }
    return left_smaller;
}

std::vector <int> find_right_smaller(int * arr, int N)
{
    std::vector <int> right_smaller(N);
    std::stack <int> s;
    s.push(-1);

    for (int i = N - 1; i >= 0; i--)
    {
        while (s.top() != -1 && arr[s.top()] >= arr[i])
            s.pop();
        right_smaller[i] = s.top();
        s.push(i);
    }
    return right_smaller;
}

int max_rectangle_1d(int * arr, int N)
{
    std::vector <int> left_smaller = find_left_smaller(arr, N);
    std::vector <int> right_smaller = find_right_smaller(arr, N);

    int maxx = 0;
    for (int i = 0; i < N; i++)
    {
        int l = left_smaller[i];
        int r = right_smaller[i];
        if (r == -1)
            r = N;
        maxx = std::max(maxx, (r - l - 1) * arr[i]);
    }
    return maxx;
}

int main(void)
{
    int matrix[100][100];
    int M, N;
    bool temp;

    while (std::cin >> M >> N && M && N)
    {
        // read matrix
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
            {
                std::cin >> temp;
                matrix[i][j] = (int)(!temp);
            }

        // turn 2d max rectangle problem into 1d max rectangle problem
        for (int i = 1; i < M; i++)
            for (int j = 0; j < N; j++)
                if (matrix[i][j] == 1 && matrix[i-1][j] != 0)
                    matrix[i][j] += matrix[i-1][j];
        // for each row, run 1d max rectangle problem and take max
        int maxx = 0;
        for (int i = 0; i < M; i++)
            maxx = std::max(maxx, max_rectangle_1d(matrix[i], N));
        std::cout << maxx << std::endl;
    }
}

