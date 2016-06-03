#include <stdio.h>
#include <stdlib.h>

#define STRING_LENGTH 64

typedef char String[STRING_LENGTH];
typedef int bool;
enum{false, true};

double *input_matrix(int *rows, int *columns, String matrixName)
{
	printf("Enter the number of rows for %s: ", matrixName);
	scanf("%d", rows);

	printf("Enter the number of columns for %s: ", matrixName);
	scanf("%d", columns);

	double *matrix;
	int rowIndex, colIndex;

	matrix = (double *) malloc((*rows * *columns) * sizeof(double));

	for(rowIndex = 0; rowIndex < *rows; rowIndex++)
	{
		for(colIndex = 0; colIndex < *columns; colIndex++)
		{
			
			printf("Enter the value for row %d, column %d in %s: ", rowIndex + 1, colIndex + 1, matrixName);
			scanf("%lf", matrix + (rowIndex * *columns) + colIndex);
			//printf("Rows * Columns = %d ... RI + CI = %d\n", *rows * *columns, (rowIndex * *columns) + colIndex);
		}
	}

	return matrix;
}

void output_matrix(double *matrix, int rows, int columns)
{
	int rowIndex, colIndex;

	for(rowIndex = 0; rowIndex < rows; rowIndex++)
	{
		for(colIndex = 0; colIndex < columns; colIndex++)
		{
			printf("%.2f ", *(matrix + (rowIndex * columns) + colIndex));
		}

		printf("\n");
	}
}

bool matrix_multiply(double *matrix1, int rows1, int columns1, double *matrix2, int rows2, int columns2, double *matrixProduct)
{
	int index, row1Index, col2Index;
	int matrix1Index, matrix2Index;
	double matrix1Val, matrix2Val, finalMatrixVal;

	if(columns1 == rows2)
	{
		for(row1Index = 0; row1Index < rows1; row1Index++)
		{
			for(col2Index = 0; col2Index < columns2; col2Index++)
			{
				finalMatrixVal = 0;

				for(index = 0; index < columns1; index++)
				{
					matrix1Index = row1Index * columns1;
					matrix1Index += index;
					matrix1Val = *(matrix1 + matrix1Index);

					matrix2Index = index * columns2;
					matrix2Index += col2Index;
					matrix2Val = *(matrix2 + matrix2Index);

					finalMatrixVal += matrix1Val * matrix2Val;
					//printf("matrix1Val = %lf ... matrix2Val = %lf\n", matrix1Val, matrix2Val);
					//printf("row1Index = %d ... col2Index = %d ... index = %d\n", row1Index, col2Index, index);
				}

				*(matrixProduct + (row1Index * columns2) + col2Index) = finalMatrixVal;
			}
		}

		return true;
	}

	else
	{
		return false;
	}
}

/*---------------------------------------------------------------------------*/
int main(void) 
{

    double *m1,*m2,*m3;
    int m1_rows,m1_columns,m2_rows,m2_columns;

    if (((m1 = input_matrix(&m1_rows,&m1_columns,"Matrix 1")) != NULL) &&
((m2 = input_matrix(&m2_rows,&m2_columns,"Matrix 2")) != NULL) &&
((m3 = malloc(m1_rows*m2_columns*sizeof(double))) != NULL)) 
    {
        printf("Matrix 1\n");
        output_matrix(m1,m1_rows,m1_columns);
        printf("Matrix 2\n");
        output_matrix(m2,m2_rows,m2_columns);
        if (matrix_multiply(m1,m1_rows,m1_columns,m2,m2_rows,m2_columns,m3)) 
        {
            printf("Product\n");
            output_matrix(m3,m1_rows,m2_columns);
            free(m1);
            free(m2);
            free(m3);
            return(0);
        } 

        else 
        {
            printf("Error in dimensions\n");
            free(m1);
            free(m2);
            free(m3);
            return(-1);
        }
    } 

    else 
    {
        free(m1);
        free(m2);
        free(m3);
        printf("Error allocating memory\n");
        return(-2);
    }
}