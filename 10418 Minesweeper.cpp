# include <iostream>

int matrix[101][101]; // to facilitate adding

void add_neighbor_one(int mine_r, int mine_c, int row, int col)
{
    for (int i = mine_r - 1; i <= mine_r + 1; i++)
        for (int j = mine_c - 1; j <= mine_c + 1; j++)
        {
            // eight neighbors, not including mine position
            if (i == mine_r && j == mine_c)
                continue;
            // boundry check
            if (i < 0 || i >= row || j < 0 || j >= col)
                continue;
            // avoid affecting other mines
            if (matrix[i][j] == -1)
                continue;
            matrix[i][j] += 1;
        }
}

int main(void)
{

    int row, col;
    char temp;
    int case_cnt = 1;

    while(std::cin >> row >> col && row && col)
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                std::cin >> temp;
                if (temp == '*')
                    matrix[i][j] = -1;
                else
                    matrix[i][j] = 0;
            }
        // predict
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (matrix[i][j] == -1)
                    add_neighbor_one(i, j, row, col);
        // print
        std::cout << "Field #" << case_cnt << ":" << std::endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == -1)
                    std::cout << "*";
                else
                    std::cout << matrix[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        case_cnt += 1;



    }
}
