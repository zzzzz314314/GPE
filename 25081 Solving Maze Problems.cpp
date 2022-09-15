# include <iostream>
char matrix[10][10];
int start_r, start_c;
int end_r, end_c;

bool walk(int i, int j)
{
    // check terminating condition: boundry and wall
    if (i < 0 || i >= 10 || j < 0 || j >= 10 || matrix[i][j] == '#')
        return false;
    // check terminating condition: succeed
    if (matrix[i][j] == 'G')
        return true;
    // mark
    matrix[i][j] = '+';
    // walk
    if (!walk(i+1, j) && !walk(i, j+1) && !walk(i, j-1) && !walk(i-1, j))
    {
        matrix[i][j] = '.';
        return false;
    }
    return true;

}


int main(void)
{


    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            std::cin >> matrix[i][j];
            if (matrix[i][j] == 'S')
            {
                start_r = i;
                start_c = j;
            }
            if (matrix[i][j] == 'G')
            {
                end_r = i;
                end_c = j;
            }
        }
    if (walk(start_r, start_c))
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                std::cout << matrix[i][j];
            }
            std::cout << std::endl;
        }
    else
        std::cout << "No solution";


}
