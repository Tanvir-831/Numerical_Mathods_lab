#include<math.h>
#define EPS 0.000001
#define MAXIT 20
#define F(x) (x)*(x) - 3*x + 2
#define FD(x) 2*(x) - 3

int main()
{
    int count;
    float x0, xn, fx, fdx;

    printf("\n");
    printf("Input initial value of x:");
    scanf("%f", &x0);
    printf("\n    SOLUTION BY NEWTON-RAPHSON METHOD\n\n");
    count = 1;
    begin:
        fx = F(x0);
        fdx = FD(x0);
        xn = x0 - fx / fdx;

        if(fabs((xn - x0)/ xn) < EPS)
        {
            printf("Root = %f\n", xn);
            printf("Function value = %f\n", F(xn));
            printf("Number of iterations = %d\n\n", count);

        }
    else
    {
        x0 = xn;
        count = count + 1;
        if(count < MAXIT)
        {
            goto begin;
        }
        else
        {
            printf("\n SOLUTION DOES NOT CONVERGE\n");
            printf("IN %d ITERATIONS \n", MAXIT);
        }
    }
    return 0;
}
