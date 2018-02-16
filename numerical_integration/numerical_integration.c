#include<stdio.h>
#include<common_include.h>
#include<math.h>

#define TRAPEZOIDAL_RULE 1
#define SIMPSON_RULE 2
#define GAUSS_QUADRATURE 3


int main()
{
  int  number_of_interval = 0;
  int method_of_integration = 0;
  float area = 0.0;
  int i = 0;

  printf("\numercial Integration\r\n\n");

  printf("  1 ---> Trapezoidal Rule\n");
 
  printf("  2 ---> Simpson's Rule\n");

  printf("  3 ---> Gauss Quadrature\n\n");

  printf("Press 1 or 2 or 3 ===>  ");

  scanf("%d", &method_of_integration);

  if (method_of_integration < 1 || method_of_integration > 3)
  {
     printf("I am sorry!!! Please Enter the valid integration type\n");
     return 0;
  }

  switch(method_of_integration)
  {
    case TRAPEZOIDAL_RULE:
         printf("\n number of Intervals  ");

         scanf("%d", &number_of_interval);
         area = trapezodial_rule(number_of_interval);       
         printf("\ntrapezodial Rule for interval[ %d ] is %.10f\n", number_of_interval, area);
    break;

    case SIMPSON_RULE:
         printf("\nEnter the Number of Intervals  ");

         scanf("%d", &number_of_interval);

         if (numner_of_interval % 2 != 0)
         {
            printf("Please Enter the Even number of intervals\r\n");
            return 0;
         }

         area = simpson_rule(number_of_interval);
         printf("\nusing Simpson Rule for interval[ %d ] is %.10f\n", number_of_interval, area);
    break;

    case GAUSS_QUADRATURE:
         area = gauss_quadrature();
         printf("\nusing Gauss Quadrature for the interval[ %d ] is %.10f\n", 2, area);
    break;

    default:
    
    break;
  }

  printf("\n***\n");

  for (i = 1; i <= 6; i++)
  {
      if (i == 2 || i == 5)
      {
         continue;
      }

      number_of_interval = pow(2,i);

      printf("\n**");
      printf("\nArea Sin(x)  %d \r\n\n", number_of_interval);
      printf("Trapezodial    %.10f\r\n",trapezodial_rule(number_of_interval));
      printf("SimpsonRule        %.10f\r\n",simpson_rule(number_of_interval));
      printf("GaussQuadrature    %.10f\r\n", gauss_quadrature()); 
      printf("***\n");
      printf("\n");     
  }

  return 0;
}

