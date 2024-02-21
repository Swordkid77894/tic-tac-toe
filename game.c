#include <stdio.h>
#include <string.h>

#define value(x,y) c[x][y] == 0 ? ' ':c[x][y]

char arr[3][3] = {0};
char num_buf[127];
char flag_buf;
int  win = 0;

void change_flag(int *flag_p){
    *flag_p = *flag_p == 'X'? 'O':'X';
}

int check_vertical(char c[3][3], int i, int j){
    int k;
    for (k = 0; k<3; k++){
        if (c[k][j] != c[i][j]){
            return 1;
        }
    }
    return 0;
}

int check_diagonal(char c[3][3], int i, int j){
    int k;
    if (i == j){
        for(k = 0; k<3; k++){
            if (c[k][k] != c[i][j]){
                return 1;
            }
        }
    }
    else if (i == 3-1-j){
        for(k = 0; k<3; k++){
            if (c[k][3-1-k] != c[i][j]){
                return 1;
            }
        }
    }
    else{
        return 1;
    }
    
    return 0;
}

int check_horizontal(char c[3][3], int i, int j){
    int k;
    for (k = 0; k<3; k++){
        if (c[i][k] != c[i][j]){
            return 1;
        }
    }

    return 0;
}

int find_winner(char c[3][3], int i, int j){
    if (check_diagonal(c, i, j) == 0 || check_horizontal(c, i, j) == 0||check_vertical(c, i, j) == 0){
        return  0;
    }

    return 1;
}

int check_result(int rc, int row, int col) {
    if (rc !=2){
        printf("Invalid format input. Try again:");

        return  1; 
    }

    if (((row > 2) || (row < 0)) || ((col > 2) || (col < 0))){
        printf("Oh! There was an error in the coordinates! Enter the "
                 "coordinates of another cell:");
        return  1; 
    }

    if (arr [row][col] != 0){
        printf("Oh! This cell is already occupied! Enter the coordinates of another cell:");
        return  1; 
    }
    return 0;
}

void print_field(char c[3][3]){
    printf("+-----+-----+-----+\n");
    printf("|  %c  |  %c  |  %c  |\n",value(0,0),value(0,1),value(0,2));
    printf("+-----+-----+-----+\n");
    printf("|  %c  |  %c  |  %c  |\n",value(1,0),value(1,1),value(1,2));
    printf("+-----+-----+-----+\n");
    printf("|  %c  |  %c  |  %c  |\n",value(2,0),value(2,1),value(2,2));
    printf("+-----+-----+-----+\n");
}


int main(){
    int turn;
    int row;
    int flag; 
    int col;
    int rc = 0;

        printf("Who will start first? Enter the X or O symbol to start "
        "the game:");
       
        do{
            fgets(num_buf, sizeof(num_buf), stdin);
            if(strlen(num_buf)!=2){
               printf("Invalid format input. Try again::");
               continue; 
            }
            flag = num_buf[0];
            if(flag != 'X' && flag != 'O'){
                printf("An invalid character was entered!\n");
            }    
        }while(flag != 'X'&& flag != 'O');

    for (turn = 0; turn < 9; turn++){
        printf("Which cell to put it in? %c?:", flag);

        do{
            fgets(num_buf, sizeof(num_buf), stdin);
            rc = sscanf(num_buf,"%d, %d",&row, &col);
            
        }while(check_result(rc, row, col)!=0);

        arr[row][col]=flag;
        print_field(arr);

        if (find_winner (arr, row, col) == 0){
            printf("Congratulations! %c wins!\n",flag);

            return 0;
        }
        change_flag(&flag);
    }

    if (turn == 9){
    printf("Oh no! There are no more cells on the field. Start new game.");
    }

    
    return 0;
}