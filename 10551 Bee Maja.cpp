# include <iostream>
# define MAX 100001
typedef struct _coord
{
    int x;
    int y;
}coord;

coord * construct_maja()
{

    static coord maja[MAX+1]; // index 0 ~ MAX
    maja[1].x = 0; // (0,0)
    maja[1].y = 0;
    maja[2].x = 0; // (0,1)
    maja[2].y = 1;
    int length = 1;
    int i = 3;

    while (i <= MAX)
    {
        // left-up
        for (int cur_len = 0; cur_len < length; cur_len++)
        {
            if (i > MAX) return maja;
            maja[i].x = maja[i-1].x - 1;
            maja[i].y = maja[i-1].y;
            i += 1;
        }
        // up
        for (int cur_len = 0; cur_len < length; cur_len++)
        {
            if (i > MAX) return maja;
            maja[i].x = maja[i-1].x;
            maja[i].y = maja[i-1].y - 1;
            i += 1;
        }
        // right-up
        for (int cur_len = 0; cur_len < length; cur_len++)
        {
            if (i > MAX) return maja;
            maja[i].x = maja[i-1].x + 1;
            maja[i].y = maja[i-1].y - 1;
            i += 1;
        }
        // right-down
        for (int cur_len = 0; cur_len < length; cur_len++)
        {
            if (i > MAX) return maja;
            maja[i].x = maja[i-1].x + 1;
            maja[i].y = maja[i-1].y;
            i += 1;
        }
        // down
        for (int cur_len = 0; cur_len < length; cur_len++)
        {
            if (i > MAX) return maja;
            maja[i].x = maja[i-1].x;
            maja[i].y = maja[i-1].y + 1;
            i += 1;
        }
        // down 1 step
        if (i > MAX) return maja;
        maja[i].x = maja[i-1].x;
        maja[i].y = maja[i-1].y + 1;
        i += 1;
        // left-down
        for (int cur_len = 0; cur_len < length; cur_len++)
        {
            if (i > MAX) return maja;
            maja[i].x = maja[i-1].x - 1;
            maja[i].y = maja[i-1].y + 1;
            i += 1;
        }
        length += 1;
    }
}

int main(void)
{
    coord * maja = construct_maja();


    int num;
    while(std::cin >> num)
        std::cout << maja[num].x << " " << maja[num].y << std::endl;

}
