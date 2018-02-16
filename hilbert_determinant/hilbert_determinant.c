#include<stdio.h>

#define MAX_ROWS 3
#define MAX_COLS 3
#define HILBERT_MATRIX_ROWS 4
#define HILBERT_MATRIX_COLS 4


/*
determinant for 3x3 matrix

*/

float determinant_3x3_matrix(float matrix[MAX_ROWS][MAX_COLS])
{

	return matrix[0][0]*matrix[1][1]*matrix[2][2] + 
		matrix[0][1]*matrix[1][2]*matrix[2][0] +  
		matrix[0][2]*matrix[1][0]*matrix[2][1] - 
		matrix[0][0]*matrix[1][2]*matrix[2][1] - 
		matrix[0][1]*matrix[1][0]*matrix[2][2] - 
		matrix[0][2]*matrix[1][1]*matrix[2][0]; 
}


/*
cramer rule construction

*/

void cramer_rule_data_construction(
		float hilbert_matrix[HILBERT_MATRIX_ROWS][HILBERT_MATRIX_COLS],
		float temp_matrix[MAX_ROWS][MAX_COLS], int ignore_col)
{
	int row = 0, col = 0, i= 0, j =0;

	for (row = 1; row < HILBERT_MATRIX_ROWS; row++)
	{
		for (col = 0; col < HILBERT_MATRIX_COLS; col++)
		{
			if (ignore_col == col)
			{
				continue;
			}

			temp_matrix[i][j] = hilbert_matrix[row][col];
			j++;
		}

		i++;
		j = 0;
	}

	return;
}


/***********************************************************************

* cramer rule for determinant

 ************************************************************************/

float cramers_rule_for_determinant(float hilbert_matrix[HILBERT_MATRIX_ROWS][HILBERT_MATRIX_COLS])
{

	float detA = 0, detB = 0, detC= 0, detD = 0;
	float temp_matrix[MAX_ROWS][MAX_COLS];
	float determinant = 0.0;
	int row = 0, col = 0, i= 0, j =0;

        cramer_rule_data_construction(hilbert_matrix, temp_matrix, 0);

	/*Compute Determinant of minors of Matrix*/
	detA = determinant_3x3_matrix(temp_matrix);

        cramer_rule_data_construction(hilbert_matrix, temp_matrix, 1);

	detB = determinant_3x3_matrix(temp_matrix);

        cramer_rule_data_construction(hilbert_matrix, temp_matrix, 2);

	detC = determinant_3x3_matrix(temp_matrix);

        cramer_rule_data_construction(hilbert_matrix, temp_matrix, 3);

	detD = determinant_3x3_matrix(temp_matrix);




	determinant = hilbert_matrix[0][0]*detA -
		hilbert_matrix[0][1]*detB +
		hilbert_matrix[0][2]*detC -
		hilbert_matrix[0][3]*detD;

	return determinant;
}


/*
* find collatz conjecture
*/

int main()
{
	int row = 0,col = 0;
	float determinant = 0;
	float hilbert_matrix[HILBERT_MATRIX_ROWS][HILBERT_MATRIX_COLS];


	for (row = 0; row < HILBERT_MATRIX_ROWS; row++)
	{
		for (col = 0; col < HILBERT_MATRIX_COLS; col++)
		{
			hilbert_matrix[row][col] = (float)1/(row+1+col);
		}
	}

	determinant = cramers_rule_for_determinant(hilbert_matrix);

	printf("\n**"); 
	printf("\nThe Hilbert Matrix  is\r\n");
	printf("******\n");

	for (row = 0; row < HILBERT_MATRIX_ROWS; row++)
	{
		for (col = 0; col < HILBERT_MATRIX_COLS; col++)
		{
			printf("%f\t",hilbert_matrix[row][col]);
		}
		printf("\n");
	}

	printf("\n*************");
	printf("\nThe Determinant of Hilbert Matrix is ===> %.10f\r\n", determinant);
	printf("*******\n");

	return 0;
}

