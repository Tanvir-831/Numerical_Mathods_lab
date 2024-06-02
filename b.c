
#include<stdio.h>
#include<math.h>
#define ERROR 0.000001
double F(double x)
{
	double y;
	y=(x)*(x)-4*(x)-10;
	return(y);
}

main()
{
	int s, count;
	double a, b, root;
	printf("\n");
	printf("SOLUTION BY BISECTION METHOD \n");
	printf("\n");
	printf("Input starting values: ");
	scanf("%lf%lf",&a,&b);

	/*calling the subroutine bim() */
	bim(&a, &b, &root, &s, &count);

	if(s == 0)
	{
		printf("\n");
		printf("Starting points do not bracket any root \n");
		printf("Check whether they bracket EVEN roots");
		printf("\n");
	}
	else
	{
		printf("\nRoot = %lf \n", root);
		printf("F(root)  = %lf\n", F(root));
		printf("\n");
		printf("Iterations = %d\n", count);
		printf("\n");
	}
}

/*End of main program */

/* ------------------------------------------------------------------------------------------------------ */
/* Defining the subroutine bim() */

bim(double  *a, double *b, double * root, int *s, int *count)
{
	double x1, x2, x0, f0, f1, f2;
	x1 = *a;
	x2 = *b;
	f1 = F(x1);
	f2 = F(x2);

/*Test if initial values bracket a SINGLE root */
	if(f1 * f2 > 0)
	{
		*s = 0;
		return ;		/*Program terminated*/
	}
	else
	{
		*count = 0;

		begin:
		x0 = (x1 + x2)/2.0;
		f0 = F(x0);
		if(f0 == 0)
		{
			*s = 1;
			*root = x0;
			return ;
		}
		if(f1 * f0 < 0)
		{
			x2 = x0;
			f2 = f0;
		}
		else
		{
			x1 = x0;
			f1 = f0;
		}

	/*Testfor accuracy  and repeat the process,if necessary */

		if(fabs(x2 - x1) < ERROR)
		{
			*s = 1;
			*root = (x1 + x2) / 2.0;
			return ; 	/*Iteration ends */
		}
		else
		{
			*count = *count + 1;
			goto begin;
		}
	}
}
