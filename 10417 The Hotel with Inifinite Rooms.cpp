# include <iostream>

int main(void){
    int S;
    long long D;

    while(std::cin >> S >> D)
    {
        int stayed_days = 0;
        for (long long i = 1; i < D; i++)
        {
            stayed_days += 1;
            if (stayed_days == S)
            {
                stayed_days = 0;
                S += 1;
            }

        }
        std::cout << S << std::endl;
    }
}
