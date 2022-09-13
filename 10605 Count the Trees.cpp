# include <iostream>
# include <string>
# include <cstring>
// Catalen number
// https://www.codeleading.com/article/74213429968/
int product[1000];
int main(void){
// ans(k) = (k+2)*(k+3)* ... *(2k)
// k = n
// ans(n) = (n+2)*(n+3)* ... *(2n)
// k = n+1
// ans(n+1) = (n+3)*(n+4) ... (2n+2)
//          = ans(n) / (n+2) * (2n+1) * (2n+2)
// to build a table first might not be easy...
// it might involve big number division
    int n;

    while(std::cin >> n && n)
    {
        if (n == 1)
        {
            std::cout << "1" << std::endl;
            continue;
        }

        int n_plus_2 = n + 2; // multiplication from n+2
        memset(product, 0, sizeof(product));
        int digits = std::to_string(n_plus_2).length();
        // index 210 (digits=3)
        // num   123
        for (int i = 0; i < digits; i++)
        {
            // product[digits - i - 1] = n % 10;
            product[i] = n_plus_2 % 10;
            n_plus_2 /= 10;
        }

        // (n+2) * (n+3) * ... * (2n)
        for(int i = n + 3 ; i <= 2 * n; i++)
        {
            for (int j = 0; j < digits; j++)
            {
                product[j] *= i;
            }
            // carry
            for (int j = 0; j < digits; j++)
            {
                product[j+1] += product[j] / 10;
                product[j] %= 10;
                if (j+1 >= digits && product[j+1] > 0)
                    digits += 1;
            }
        }
        for (int i = digits - 1; i >= 0; i--)
            std::cout << product[i];
        std::cout << std::endl;
    }
}
