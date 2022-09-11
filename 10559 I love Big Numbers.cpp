# include <iostream>
# include <cmath>
# include <cstring> // for memset
int ans[1001];
int product[3000];

int find_digit_for_factorial(int n)
{
    // https://www.geeksforgeeks.org/count-digits-factorial-set-1/
    // factorial exists only for n>=0
    if (n < 0)
        return 0;

    // base case
    if (n <= 1)
        return 1;

    // else iterate through n and calculate the
    // value
    double digits = 0;
    for (int i=2; i<=n; i++)
        digits += log10(i);

    return floor(digits) + 1;

}

int main(void)
{
    // std::cout << find_digit_for_factorial(1000);
    // 2568 digits => product[3000] is enough
    std::memset(ans, 0, sizeof(ans));
    std::memset(product, 0, sizeof(product));
    ans[0] = 1; ans[1] = 1;
    product[0] = 1;

    int digits_in_product = 1;
    for (int i = 2; i <= 1000; i++)
    {
        for (int j = 0; j < digits_in_product; j++)
        {
            product[j] *= i;
            /*
            10000000..
            2
            -----------
            20000000..
            */
        }

        // in one digit, the number might >= 10
        // deal with carry
        for (int j = 0; j < digits_in_product; j++)
        {
            product[j + 1] += product[j] / 10;
            // check out whether new digits has appeared
            /*
            digits_in_product = 1
            60000000...
            4
            --------
            24000000...
            */
            if (product[digits_in_product] > 0)
                digits_in_product += 1;
            product[j] %= 10;
            ans[i] += product[j];

        }
    }
    int inp;
    while(std::cin >> inp)
        std::cout << ans[inp] << std::endl;


}
