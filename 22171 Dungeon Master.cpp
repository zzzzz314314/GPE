# include <iostream>
# include <deque>
# include <cstring>

char maze[1000][1000][1000];
int move_l[6] = {1, -1, 0, 0, 0, 0};
int move_r[6] = {0,  0, 1, -1, 0, 0};
int move_c[6] = {0,  0, 0, 0, 1, -1};

struct Point
{
    int l;
    int r;
    int c;
    int steps;
};

int BFS(Point start, Point endd, int L, int R, int C)
{
    int visited[L][R][C];
    memset(visited, 0, sizeof(visited));
    std::deque <Point> q;
    q.push_back(start);

    while(q.size())
    {
        Point now = q.front();
        // termination check
        if (now.l == endd.l && now.r == endd.r && now.c == endd.c)
            return now.steps;

        q.pop_front();
        visited[now.l][now.r][now.c] = 1;
        for (int i = 0; i < 6; i++)
        {
            int next_l = now.l + move_l[i];
            int next_r = now.r + move_r[i];
            int next_c = now.c + move_c[i];
            // boundary check
            if (next_l < 0 || next_r < 0 || next_c < 0 || next_l >= L || next_r >= R || next_c >= C)
                continue;
            // wall check
            if (maze[next_l][next_r][next_c] == '#')
                continue;
            // has visited check
            if (visited[next_l][next_r][next_c])
                continue;

            q.push_back({next_l, next_r, next_c, now.steps+1}); //NOTE THIS

        }
    }
    return -1;
}

int main(void)
{

    int L, R, C;

    Point start, endd;
    int start_l, start_r, start_c, end_l, end_r, end_c;


    while(std::cin >> L >> R >> C && L && R && C)
    {
        int steps = 0;

        for (int i  = 0; i < L; i++)
            for (int j = 0; j < R; j++)
                for (int k = 0; k < C; k++)
                {
                    std::cin >> maze[i][j][k];
                    if (maze[i][j][k] == 'S')
                        start = {i, j, k, 0};
                    else if (maze[i][j][k] == 'E')
                        endd = {i, j, k, 0};
                }

        int time = BFS(start, endd, L, R, C);
        if (time == -1)
            std::cout << "Trapped!" << std::endl;
        else
            std::cout << "Escaped in " << time << " minute(s)." << std::endl;

    }
}
