#include <stdio.h>


void printBoard(char board[][3]){
    printf("___________ \n");
    printf("\n");
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("___________ \n");
}

int checkWin(char board[][3], int row, int column){
   
    if(board[row][0] == board[row][1] && board[row][0] == board[row][2]){
        return 1;
    }

    if(board[0][column] == board[1][column] && board[0][column] == board[2][column]){
        return 1;
    }

   if(board[row][column] != '-' &&
      board[row][column] == board[1][1] &&
      board[row][column] == board[2][2]){
        return 1;
    }

    if(board[row][column] != '-' &&
      board[row][column] == board[1][1] &&
      board[row][column] == board[2][0]){
        return 1;
    }

    return 0;
}

int main(){
    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };

    int chance = 1;
    while(chance < 10){
        char XorO = (chance % 2 != 0) ? 'X' : 'O';
        int row, column;
        printf("%c plays , which row : ", XorO);
        scanf("%d", &row);
        printf("%c plays , which column : ", XorO);
        scanf("%d", &column);

        if(board[row-1][column-1] != '-'){
            printf("space already occupied!\n");
        }
        else{
            board[row - 1][column - 1] = XorO;
            int result = checkWin(board, row-1, column-1);
            if(result == 1){
                printf("%c wins!\n", XorO);
                printBoard(board);
                return 0;
            }
            chance++;
            printBoard(board);
        }
        
    };

    printf("Match Draw!");
    return 0;
}