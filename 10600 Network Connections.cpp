# include <iostream>
# include <sstream>
# include <string>
int arr[1001][1001]; // max?

int main(void)
{
    int case_num;
    std::cin >> case_num;

    for (int c = 0; c < case_num; c++)
    {
        int arr_size;
        std::cin >> arr_size;

        // init arr
        for (int i = 1; i <= arr_size; i++) // index starts from 1, easier
        {
            for (int j = 1; j <= arr_size; j++)
            {
                if (i == j)
                    arr[i][i] = 1;
                else
                    arr[i][j] = 0;
            }
        }

        // read commands
        char command;
        int com1, com2;
        int true_cnt = 0, false_cnt = 0;
        std::string str;

        std::cin.ignore();
        while(std::getline(std::cin, str) && str != "")
        {
            std::stringstream ss(str);
            ss >> command >> com1 >> com2;

            if (command == 'c')
            {
                arr[com1][com2] = 1;
                arr[com2][com1] = 1;

                // update others
                // any computers that connect to com1 can connect to com2
                // any computers that connect to com2 can connect to com1
                for (int any_com = 1; any_com <= arr_size; any_com++)
                {
                    if (arr[any_com][com1] == 1)
                    {
                        arr[any_com][com2] = 1;
                        arr[com2][any_com] = 1;
                    }
                    if (arr[any_com][com2] == 1)
                    {
                        arr[any_com][com1] = 1;
                        arr[com1][any_com] = 1;
                    }
                }

            }
            else
            {
                if (arr[com1][com2])
                    true_cnt += 1;
                else
                    false_cnt += 1;
            }
        }
        std::cout << true_cnt << "," << false_cnt << std::endl;
        if (c != case_num - 1)
            std::cout << std::endl;

    }
}
