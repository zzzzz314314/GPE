# include <iostream>
# include <string>
# define N 1000

int a[N + 1][N + 1];
int b[N + 1][N + 1];

void LCS(std::string s1, std::string s2, int s1_len, int s2_len)
{
    for (int i = 1; i <= s1_len; i++)
    {
        for (int j = 1; j <= s2_len; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                a[i][j] = a[i-1][j-1] + 1;
                b[i][j] = 1;
            }

            else
            {
                if (a[i-1][j] >= a[i][j-1])
                {
                    a[i][j] = a[i-1][j];
                    b[i][j] = 2;
                }

                else
                {
                    a[i][j] = a[i][j-1];
                    b[i][j] = 3;
                }

            }
        }
    }
}

void print_LCS(int i, int j, std::string s1)
{
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 1)
    {
        print_LCS(i-1, j-1, s1);
        std::cout << s1[i-1];
    }
    else if (b[i][j] == 2)
        print_LCS(i-1, j, s1);
    else
        print_LCS(i, j-1, s1);
}

int main(void){
    std::string s1, s2;
    while(std::cin >> s1)
    {
        std::cin >> s2;
        int s1_len = s1.length();
        int s2_len = s2.length();
        //init array
        for (int i = 0; i <= s1_len; i++)
            a[i][0] = 0;
        for (int j = 0; j <= s2_len; j++)
            a[0][j] = 0;
        LCS(s1, s2, s1_len, s2_len);
        std::cout << a[s1_len][s2_len] << std::endl;
        print_LCS(s1_len, s2_len, s1);
        std::cout << std::endl;
    }
}
