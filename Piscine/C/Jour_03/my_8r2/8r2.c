#include <stdio.h>
#include <string.h>

#define GRID_SIZE       8

void    solve(int grid[GRID_SIZE][GRID_SIZE], int y);
int     canPlaceQueen(int grid[GRID_SIZE][GRID_SIZE], int x, int y);

void    displayGrid(int grid[GRID_SIZE][GRID_SIZE], int xx)
{
    int x, y;
    char buf[GRID_SIZE + 1];

    for (y = 0; y < GRID_SIZE; y++)
    {
        for (x = 0; x < GRID_SIZE; x++)
        {
            if (grid[x][y] > 0)
                buf[y] = x + '0';
        }
    }
    buf[y - 1] = xx;
    buf[y] = '\0';
    printf("%s\n", buf);
}

int     main(void)
{
    int grid[GRID_SIZE][GRID_SIZE];
    int i;

    memset(grid, 0, sizeof(int) * GRID_SIZE * GRID_SIZE);
    solve(grid, 0);
    return (0);
}

void    solve(int grid[GRID_SIZE][GRID_SIZE], int y)
{
    register int f;
    int x;

    for (x = 0; x < GRID_SIZE; x++)
    {
        f = canPlaceQueen(grid, x, y);
        if (f && y < GRID_SIZE - 1)
        {
            grid[x][y] = 1;
            solve(grid, y + 1);
            grid[x][y] = 0;
        }
        else if (f && y) // We arrived on last row and we have a solution
        {
            displayGrid(grid, x);
            return;
        }
    }
    return;
}

int     canPlaceQueen(int grid[GRID_SIZE][GRID_SIZE], int x, int y)
{
    int xx, yy;

    for (yy = 0; yy < GRID_SIZE; yy++)
        if (grid[x][yy] == 1) return (0);
    // check diagonals now
    xx = x;
    yy = y;
    for (x--, y--; x >= 0 && y >= 0; x--, y--)
        if (grid[x][y])
            return (0);
    for (x = xx + 1, y = yy - 1; x < GRID_SIZE && y >= 0; ++x, --y)
        if (grid[x][y])
            return (0);
    for (x = xx - 1, y = yy + 1; x >= 0 && y < GRID_SIZE; x--, y++)
        if (grid[x][y])
            return (0);
    for (x = xx + 1, y = yy + 1; x < GRID_SIZE && y < GRID_SIZE; x++, y++)
        if (grid[x][y])
            return (0);
    return (1);
}
