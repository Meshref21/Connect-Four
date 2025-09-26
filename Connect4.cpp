#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

char grid[6][7];

bool is_input_valid(int given)
{
    return given <= 7 and given > 0;
}

char Which_char(int temp)
{
    if (temp % 2 == 0) return 'X';
    return 'O';
}

bool isValid(int i , int j)
{
    return i >= 0  and i < 6 and j >= 0 and j < 7;
}

int dj[] = { 1 , -1 , 0 , 0 , -1 , 1  , 1 , -1};
int di[] = { 0 , 0 , -1 , 1 ,  -1 , -1 , 1 , 1 };

bool Search_all_directions(int i , int j , char current_char)
{
    int counter = 1;
    for (int k = 0 ; k < 8 ; k++)
    {
        int row = i + di[k];
        int column = j + dj[k];

        while (isValid(row , column) and grid[row][column] == current_char)
        {
            counter++;
            row += di[k];
            column += dj[k];
        }
        if (counter >= 4) return true;
        counter = 1;
    }
    return false;
}

void output_handler()
{
    cout << '\n';
    for (int i = 5 ; i >= 0 ; i--)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            cout << '[' << ' ' << grid[i][j] << ' ' << ']';
        }
        cout << '\n';
    }
    cout << "  1  " << "  2  " << "  3  " << "  4  " << "  5  " << "  6  " << "  7  ";
    cout << '\n';
}

int main()
{
    int freq[7];
    memset(freq , -1 , sizeof(freq));
    memset(grid , ' ' , sizeof(grid));

    int temp = 0 ; char X_O;
    bool Wins_flag = false;
    int full_grid_condition = 42;
    while (full_grid_condition--)
    {
        int given; cin >> given;

        if (!is_input_valid(given))
        {
            full_grid_condition++;
            cout << "Out of boundaries! try again" << '\n';
            continue;
        }

        int below_me = freq[--given];
        freq[given]++;

        if ( grid[below_me + 1][given] != ' ' )
        {
            full_grid_condition++;
            cout << "Invalid input try again!" << '\n';
            continue;
        }

        X_O = Which_char(temp++);
        grid[++below_me][given] = X_O;

        output_handler();

        if (Search_all_directions(below_me , given , X_O))
        {
            Wins_flag = true;
            break;
        }
    }
    if (Wins_flag) cout << X_O << " Wins";
    else cout << "Draw!" << '\n';


}
