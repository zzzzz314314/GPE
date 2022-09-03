#include <iostream>

int main()
{
    int N;
    // For this question, the index starts with 1, and is always killed at first
    // Hence we can left shift the whole index by 2 to adapt to the original
    // Joseph problem.
    // f(N, k) = (f(N - 1, k) + k) % N
    // https://www.youtube.com/watch?v=Yeh1_2GyS5s

    int Wellington = 13 - 1 - 1;

    while (std::cin >> N && N){
        // Since the first one is always killed first
        // decrease N by first to ignore the one
        N -= 1;
        // enumerate k from smaller ones
        for (int k = 1; ; k++){
            // start with f(N=1, k) = 0
            int f = 0;
            // then increment to f(N+1, k) by recursion
            for (int n = 1; n <= N; n++){
                f = (f + k) % n;
            }
            if (f == Wellington){
                std::cout << k << std::endl;
                break;
            }
        }
    }
    return 0;
}
