#include <iostream>
#include <string.h>
using namespace std;



enum board_status
{
    
    EMPTY, // không có gì
    CHECK_1, // ăn 1
    CHECK_2_AND_MORE, // ăn đôi hoặc hơn
    CHECKED, // đã kiểm tra ( vị trí ăn 2 )
    KNIGHT, // vị trí mã
    OTHER, // vị trí quân khác
};

int board[8][8] = {0};
int kernel[5][5] = {0};

void check_possible_place(int r, int c)
{

    for (int i = 0; i < 5; i++)
    {
        if (r + i - 2  < 0 || r + i - 2 >= 8)
            continue;
        for (int j = 0; j < 5; j++)
        {
            if (c + j - 2 < 0 || c + j - 2 >= 8)
                continue;

            if (kernel[i][j] == 1 && (board[r + (i - 2)][c + (j - 2)] == EMPTY || board[r + (i - 2)][c + (j - 2)] == CHECK_1))
                board[r + (i - 2)][c + (j - 2)]++;
        }
    }
}

int check_knight(int r, int c, int turn)
{
    int res = 0;

    if (turn <= 1)
    {
        for (int i = 0; i < 5; i++)
        {
            if (r + i - 2 < 0 || r + i - 2 >= 8)
                continue;
            for (int j = 0; j < 5; j++)
            {
                if (c + j - 2 < 0 || c + j - 2 >= 8)
                    continue;

                if (kernel[i][j] == 1 && board[r + (i - 2)][c + (j - 2)] == CHECK_2_AND_MORE)
                {
                    res++;
                    board[r + (i - 2)][c + (j - 2)] = CHECKED;
                }
                else if ( kernel[i][j] == 1 && ( board[r + (i - 2)][c + (j - 2)] == EMPTY || board[r + (i - 2)][c + (j - 2)] == CHECK_1 ) )
                    res += check_knight(r + (i - 2), c + (j - 2), turn + 1);
            }
        }
    }

    return res;
}

void solution()
{

    freopen("input.txt","r",stdin);
    int T, N, K_R_point, K_C_point, O_R_point, O_C_point, res = 0, tc = 1;

    cin >> T;
    while (tc <= T)
    {

        // Nhập dữ liệu từng test case
        res = 0;
        cin >> N;

        cin >> K_R_point >> K_C_point;
        board[K_R_point-1][K_C_point-1] = KNIGHT;

        while (N--)
        {
            cin >> O_R_point >> O_C_point;
            board[O_R_point-1][O_C_point-1] = OTHER;
        }


        // kiểm tra các vị trí có thể ăn được 1, 2 trên bàn cờ
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] == OTHER)
                    check_possible_place(i, j);
            }
        }

        // đếm vị trí ăn được 2 hoặc hơn
        res = check_knight(K_R_point-1, K_C_point-1, 0);

        cout<<'#'<<tc<< ' '<< res<<endl;


        tc++;
        memset(board, EMPTY, sizeof(board)*4); // set lại vị trí board, ko hiểu sao vị trí kernel cũng bị reset, phải đặt lại.
        kernel[0][1] = 1;
        kernel[0][3] = 1;
        kernel[1][0] = 1;
        kernel[1][4] = 1;
        kernel[3][0] = 1;
        kernel[3][4] = 1;
        kernel[4][1] = 1;
        kernel[4][3] = 1;
    }

    
}

int main()
{

    memset(board, EMPTY, sizeof(board)*4);

    memset(kernel, 0, sizeof(kernel)*4);
    kernel[0][1] = 1;
    kernel[0][3] = 1;
    kernel[1][0] = 1;
    kernel[1][4] = 1;
    kernel[3][0] = 1;
    kernel[3][4] = 1;
    kernel[4][1] = 1;
    kernel[4][3] = 1;

    solution();
    return 0;
}
