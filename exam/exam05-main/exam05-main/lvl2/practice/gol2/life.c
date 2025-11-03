#include "life.h"

void free_board(int height, char** board){
    int row = 0;
    while(row < height)
        free(board[row++]);
    free(board);
}

void print_board(int width, int height, char **board){
    int col = 0;
    int row = 0;
    while(row < height){
        col = 0;
        while(col < width){
            putchar(board[row][col++]);
        }
        putchar('\n');
        row++;
    }
}

char **create_board(int width, int height){
    int col = 0;
    int row = 0 ;
    char **board;

    board = (char **)calloc(sizeof(char *), height + 1);
    while(row < height){
        board[row] =  (char *)calloc(sizeof(char), width + 1);
        col = 0;
        while(col < width)
            board[row][col++] = ' ';
        board[row][col] = '\0';
        row++;
    }
    return board;
}

char **start_life(int width, int height){
    char buf;
    int col = 0; //col = widht
    int row = 0; // row = height
    bool pen_stat = false;
    
    char **empty_board = create_board(width, height);

    while(read(0, &buf, 1) > 0){
        if(buf == 'x')
            pen_stat = !pen_stat;
        if(buf == 'w' && (row - 1 >= 0))
            row--;
        else if(buf == 'a' && (col - 1 >= 0))
            col--;
        else if(buf == 's' && (row + 1 < height))
            row++;
        else if(buf == 'd' && (col + 1 < width))
            col++;

        if(pen_stat == true)
            empty_board[row][col] = '0';
    }

    return empty_board;
}

char **update_board(int width, int height, char **prev_board){
    char **new_board = create_board(width, height);

    int col = 0;
    int row = 0;
    int cell_counter;

    while(row < height){
        col = 0;
        while(col < width){
            int r = row - 1;
            cell_counter = 0;
            while(r <= row + 1){
                int c = col - 1;
                while(c <= col + 1){
                    if(r >= 0 && r < height && c >= 0 && c < width)
                    {
                        if(!(r == row && c == col)){
                        if(prev_board[r][c] == '0')
                            cell_counter++;
                    }
                }
                    c++;
                }
                r++;
                if((cell_counter == 2 || cell_counter == 3) && prev_board[row][col] == '0')
                    new_board[row][col] = '0';
                else if(cell_counter == 3 && prev_board[row][col] == ' ')
                    new_board[row][col] = '0';
            }
            col++;
        }
        row++;
    }
    free_board(height, prev_board);
    return new_board;
}

void gol(int width, int height, int iter){
    char **new_board;

    new_board = start_life(width, height);
    while(iter--)
        new_board = update_board(width, height, new_board);
    
    print_board(width, height, new_board);
    free_board(height, new_board);
}