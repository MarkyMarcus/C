#include <stdio.h>
#include <stdint.h>
#include <strings.h>

/**
 * Write a program to print the given pattern
 *
 *  1  2  3  4  5
 *  16 17 18 19 6
 *  15 24 25 20 7
 *  14 23 22 21 8
 *  13 12 11 10 9
 *
 */
int
main(
    void)
{
    #define WIDTH 5
    uint32_t vals[WIDTH][WIDTH];

    bzero(&vals, sizeof(vals));

    uint32_t col = 0;
    uint32_t row = 0;
    uint32_t col_limits[2] = {0, WIDTH - 1};
    uint32_t row_limits[2] = {0, WIDTH - 1};

    for (uint32_t i = 1; i <= WIDTH * WIDTH; ++i)
    {
        vals[row][col] = i;

        if (row == row_limits[0] && col < col_limits[1])
        {
            //printf("move right\n");
            col++;

            if (col == col_limits[1] && row == row_limits[0])
            {
                //printf("upper right\n");
                row_limits[0]++;
            }
        }
        else if (col == col_limits[1] && row < row_limits[1])
        {
            //printf("move down\n");
            row++;

            if (col == col_limits[1] && row == row_limits[1])
            {
                //printf("bottom right\n");
                col_limits[1]--;
            }
        }
        else if (row == row_limits[1] && col > col_limits[0])
        {
            //printf("move left\n");
            col--;

            if (col == col_limits[0] && row == row_limits[1])
            {
                //printf("bottom left\n");
                row_limits[1]--;
            }
        }
        else if (col == col_limits[0] && row > row_limits[0])
        {
            //printf("move up\n");
            row--;

            if (col == col_limits[0] && row == row_limits[0])
            {
                //printf("upper left\n");
                col_limits[0]++;
            }
        }

    }

    for (uint32_t i = 0; i < WIDTH; ++i)
    {
        for (uint32_t j = 0; j < WIDTH; ++j)
        {
            printf("%3d", vals[i][j]);
        }
        printf("\n");
    }

    // Return success
    return 0;
}
