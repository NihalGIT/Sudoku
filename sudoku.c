#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

//sudoku problem
int matrix[9][9] = {
    {6,5,0,8,7,3,0,9,0},
    {0,0,3,2,5,0,0,0,8},
    {9,8,0,1,0,4,3,5,7},
    {1,2,5,0,0,0,0,0,0},
    {4,3,9,0,0,0,0,0,2},
    {8,6,7,9,1,2,5,0,3},
    {5,7,8,3,0,1,4,2,6},
    {2,1,6,7,4,8,9,3,5},
    {3,9,4,6,2,5,7,8,1}

};
int matrix_util[9][9] = {
    {6,5,0,8,7,3,0,9,0},
    {0,0,3,2,5,0,0,0,8},
    {9,8,0,1,0,4,3,5,7},
    {1,2,5,0,0,0,0,0,0},
    {4,3,9,0,0,0,0,0,2},
    {8,6,7,9,1,2,5,0,3},
    {5,7,8,3,0,1,4,2,6},
    {2,1,6,7,4,8,9,3,5},
    {3,9,4,6,2,5,7,8,1}

};
char chek_usr_rep[9][9] = {
    {'6','5','0','8','7','3','0','9','0'},
    {'0','0','3','2','5','0','0','0','8'},
    {'9','8','0','1','0','4','3','5','7'},
    {'1','2','5','0','0','0','0','0','0'},
    {'4','3','9','0','0','0','0','0','2'},
    {'8','6','7','9','1','2','5','0','3'},
    {'5','7','8','3','0','1','4','2','6'},
    {'2','1','6','7','4','8','9','3','5'},
    {'3','9','4','6','2','5','7','8','1'}
};
void sudoku() ;
void print_sudoku() ;
int solve_sudoku();
int is_safe() ;
int main()
{
    printf("veuillez resoudre le sudoku: \n\n");
 print_sudoku();
 sudoku();
printf("\nvotre bilan :\n(les valeurs justes sont remplacer par v les valeurs fausses sont remplacer par f)\n\n");
int i, j;

 for(i=0; i<SIZE; i++)
 {
 if(i%3==0)
 {
  for(j=0; j<SIZE*2+1; j++)
  putchar('-');
  putchar('\n');
 }
 for(j=0; j<SIZE; j++)
 {
     if (j%3==0){
     putchar('|');
     printf ("%c" , chek_usr_rep[i][j]);
     }
     else {
         putchar(' ');
         printf("%c" , chek_usr_rep[i][j]);
     }
 }
 printf("|\n");
 }
 for(i=0;i<SIZE*2+1;i++)
 putchar('-');
 putchar('\n');
 }

void sudoku()
{

   printf("\n");
    if (solve_sudoku())

        {
            printf("\nvoici la correction:\n\n");
            print_sudoku();
        }
    else
        printf("No solution\n");
}
void print_sudoku()
{
 int i, j;
 for(i=0; i<SIZE; i++)
 {
 if(i%3==0)
 {
  for(j=0; j<SIZE*2+1; j++)
  putchar('-');
  putchar('\n');
 }
 for(j=0; j<SIZE; j++)
 {
     if (j%3==0){
     putchar('|');
     printf ("%d" , matrix[i][j]);
     }
     else {
         putchar(' ');
         printf("%d" , matrix[i][j]);
     }
 }
 printf("|\n");
 }
 for(i=0;i<SIZE*2+1;i++)
 putchar('-');
 putchar('\n');
}
int number_unassigned(int *row, int *col)
{
     int i , j ;
     int num_unassign = 0;
    for(i=0;i<SIZE;i++)
     {
        for(j=0;j<SIZE;j++)
        {
            //cell is unassigned
            if(matrix[i][j] == 0)
            {
                *row = i;
                *col = j;
                //there is one or more unassigned cells
                num_unassign = 1;
                return num_unassign;
            }
        }
    }
    return num_unassign;
}
 int is_safe(int n, int r, int c)
{
    int i,j;
     //checking in row
    for(i=0;i<SIZE;i++)
    {
        //there is a cell with same value
        if(matrix[r][i] == n)
            return 0;
    }
    //checking column
    for(i=0;i<SIZE;i++)
     {
         //there is a cell with the value equal to i
        if(matrix[i][c] == n)
            return 0;
    }
    //checking sub matrix
    int row_start = (r/3)*3;
    int col_start = (c/3)*3;
    for(i=row_start;i<row_start+3;i++)
    {
    	 for(j=col_start;j<col_start+3;j++)
    	   {
            if(matrix[i][j]==n)
                return 0;
        }
    }
    return 1;
}
int solve_sudoku()
{
printf("\n\n");
    int row;
    int col;
    int i, j ;
    for (i=0 ; i<9 ; i++){
    	for (j=0;j<9;j++){
    		if (matrix_util[i][j]==0){
    			printf("veuillez saisir la valeur de la ligne  %d et  colonne %d        " ,i+1,j+1);
    			scanf ("%d", &matrix_util[i][j]);
			}
		}
	}
	 
    if(number_unassigned(&row, &col) == 0 )
        return 1;
    int n;
     //number between 1 to 9
    for(i=1;i<=SIZE;i++)
    {
        //if we can assign i to the cell or not
        //the cell is matrix[row][col]
        if(is_safe(i, row, col))
 {
          matrix[row][col] = i;
           if (matrix_util[row][col]!=matrix[row][col] ){
                       printf("vous avez une faute dans la ligne    %d  et la colonne     %d\n " , row+1 ,col+1);
                       chek_usr_rep[row][col]='f';
						}
            else {
                chek_usr_rep[row][col]='v';
            }
            //backtracking
          if(solve_sudoku())
                return 1;
            //if we can't proceed with this solution
            //reassign the cell
           matrix[row][col]=0;
       }
    }
    return 0;
}

