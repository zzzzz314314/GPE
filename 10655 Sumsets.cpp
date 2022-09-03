# include <iostream>
# include <vector>
# include <algorithm>
# include <climits> // for INT_MAX

int find_d(std::vector<int> v){
    for (int d = v.size() - 1; d >= 0 ; d--){
        for (int a = 0; a < v.size(); a++){
            for (int b = a + 1; b < v.size(); b++){
                for (int c = b + 1; c < v.size(); c++){
                    if (v[a] + v[b] + v[c] == v[d] &&
                        a != d && b != d && c != d){
                            return v[d];
                        }
                }
            }
        }
    }
    return INT_MAX;
}

int main(void)
{
    int N, d;
    while (std::cin >> N && N){
        std::vector<int> v(N);
        for (int i = 0; i < N; i++){
            std::cin >> v[i];
        }
        // sort so d can be examined from the end of v
        // pay attention to the syntex
        sort(v.begin(), v.end());
        d = find_d(v);
        if (d == INT_MAX){
            std::cout << "no solution\n";
        }
        else{
            std::cout << d << "\n";
        }

    }
    return 0;
}
