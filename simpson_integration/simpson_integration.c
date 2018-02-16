#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define PI (3.14159265)
#define LOWER_BOUND (0)
#define UPPER_BOUND (PI/3)


/*

* simpson rule finds the area for tan(x)
*****/

float simpson_rule(int number_of_points)
{
	float area = 0.0;
	int i = 0;
	float interval_value = 0.0;
        int number_of_interval = 0;

        /* no of interval is EVEN*/
        number_of_interval =  number_of_points + 1;

       	interval_value = (UPPER_BOUND - LOWER_BOUND)/number_of_interval;

            area = tan(LOWER_BOUND) + tan(UPPER_BOUND);

	for (i = 1; i <= (number_of_points); i++)
	{
		if (i % 2 == 0)
		{
			area += (2*tan(i*interval_value));
		}
		else
		{
			area +=  (4*tan(i*interval_value));
		}
	}


	area = (area * interval_value)/3;

	return area;
}

/*

finds the           area of tan(x) using simpson rule 
 ********************************************************************/

int main()
{
	int number_of_points = 0;
	float area = 0.0;
	float actual_result = 0.0;
        float threshold = 0.00001;

	printf("\nENTER THE NUMBER OF POINTS ====>  ");
	scanf("%d", &number_of_points);

	if (number_of_points % 2 == 0)
	{
		printf("PLEASE ENTER THE ODD VALUE FOR THE NUMBER OF POINTS\n");
		return 0;
	}

        /* Calling the function to find the area under the curve using simpson rule*/
	area = simpson_rule(number_of_points);

	actual_result = -log(cos(UPPER_BOUND)) + log(cos(LOWER_BOUND));

        printf("\n*******************************************************************************************************************");
	printf("\nSIMPSON RULE : AREA UNDER THE CURVE( y = tan(x); 0 <= x <= Pi/3)  ==========>  %.20f\r\n", area);

	printf("\nLog(2) is  integral Value of(y = tan(x); 0 <= x <= Pi/3)   %.20f\r\n", actual_result); 
        printf("***\n");

        number_of_points = 0;

        do {
             
         number_of_points += 1;
      
         area = simpson_rule(number_of_points);

       } while(fabs(actual_result - area) >= threshold);  

       printf("\n***");
       printf("\nintervals %d\r\n", number_of_points + 1);
       printf("\npoints    =====> %d\r\n", number_of_points + 2);
       printf("**\n");

       return 0;
}

