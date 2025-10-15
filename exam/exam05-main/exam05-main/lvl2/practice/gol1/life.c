#include "life.h"

void free_board(char **board,int height){
    int row = 0;
    while(row < height){
        free(board[row]);
        row++;
    }
    free(board);
}

void print_board(char **board, int width, int height){
    int row = 0;
    int col = 0;
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
    int col = 0; //col = width
    int row = 0; //row = height
    char **empty_board;

    //allocation for the whole board
    empty_board = (char **)calloc(sizeof(char *), height + 1);

    while(row < height){
        empty_board[row] = (char *)calloc(sizeof(char), width + 1); //allocate per row
        col = 0;
        while(col < width){
            empty_board[row][col] = ' ';
            col++;
        }
        empty_board[row][col] = '\0';
        row++;
    }
    return empty_board;
}

char ** add_living_cells(int width, int height){
    char buf;
    bool pen_stat = false;
    int row = 0; //row = height
    int col = 0; //col = width
    
    char **empty_board = create_board(width, height);
    while(read(0, &buf, 1) > 0){
        if(buf == 'x')
            pen_stat = !pen_stat;
        else if(buf == 'w' && (row - 1 >= 0))
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

char **update_board(char **new_board, int width, int height){
    char **updated_board = create_board(width, height);
    int row = 0; //row = height
    int col = 0; //col = width
    int cell_counter = 0;

    while(row < height){
        col = 0;
        while(col < width){
            int r = row - 1;
            cell_counter = 0;
            while(r <= row + 1){
                int c = col - 1;
                while(c <= col + 1){
                    if(r >= 0 && r < height && c >= 0 && c < width){
                        if(!(r == row && c == col)){
                            if(new_board[r][c] == '0')
                                cell_counter++;
                        }
                    }
                    c++;
                }
                r++;
            }
            if((cell_counter == 2 || cell_counter == 3) && new_board[row][col] == '0')
                updated_board[row][col] = '0';
            else if(cell_counter == 3 && new_board[row][col] == ' ')
                updated_board[row][col] = '0';
            col++;
        }
        row++;
    }
    free_board(new_board, height);
    return updated_board;
}

void gol(int width, int height, int iter){
    char **new_board;

    //will create the empty board and then intitalize the living cells
    new_board = add_living_cells(width, height);

    //apply the living cell check algorithm to the nearest neighbours
    while(iter--)
        new_board = update_board(new_board, width, height);
    print_board(new_board, width, height);
    free_board(new_board, height);
}