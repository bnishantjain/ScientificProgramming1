#include<stdio.h>

#define MAX_ROWS 3
#define MAX_COLS 3
#define HILBERT_MATRIX_ROWS 4
#define HILBERT_MATRIX_COLS 4
/*
This is function for collatz conjecture
 ********************************************************************/
u_int collatz_conjecture(u_int num)
{
	u_int result = 0;

	if (num % 2 == 0)
	{
		result = num/2;
	}
	else
	{
		result = (3*num)+1;
	}

	return result;
}


/*
   funcction count_digits
 */

u_int count_digits(u_int num)
{
	u_int count = 0;

        if (num == 0)
        {
           return count;
        }

	while(num != 0)
	{
		num /= 10;
		count++;
	}

	return count;
}


/* function for print_in order
*/

void print_in_order(u_int num, int *str_position, u_int is_third_num)
{
	u_int ndigits = 0;

	ndigits = count_digits(num);

	if (*str_position + 1 + ndigits  > MAX_DISPLAY_STRING_LEN)
	{
                /*exceeds  40 character in single line*/
		printf("\n");
		*str_position = 0;
	}

	if (is_third_num == 1 && num == 1)
	{
		printf("%u\n",num);
	}
	else
	{
		printf("%u, ", num);
	}

	*str_position = *str_position + 2 + ndigits;

	return;
}

/*
main function
*/

int main(int argc, char *argv[])
{

	u_int num = 0;
	int ndigits = 0;
	int str_position = 0;


	if (argc != 2)
	{
		printf("Please Provide the Proper Input\n");
		return 0;
	}

	num = atoi(argv[1]);
 
	while (num > 0)
	{
		if (num == FIRST_NUM)
		{
			print_in_order(FIRST_NUM, &str_position, 0);
			print_in_order(SECOND_NUM, &str_position, 0);
			print_in_order(THIRD_NUM, &str_position, 1);

			break;
		}

		print_in_order(num, &str_position, 0);

		num = collatz_conjecture(num);
	}
   
	return 0;
}
