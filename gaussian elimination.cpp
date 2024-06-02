#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,n;

    cout << "\n Solve equations with Gaussian Elimination Method\n\n";

    cout<<"\nEnter the no. of equations: ";
    cin>>n;


    float mat[n][n+1];


    float res[n];

    cout<<"\nEnter the elements of the augmented matrix: \n";
    for(i=0; i<n; i++)
    {
        for(j=0; j<n+1; j++)
        {
            cin>>mat[i][j];
        }
    }

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(abs(mat[i][i]) < abs(mat[j][i]))
            {
                for(k=0; k<n+1; k++)
                {
                    /* swapping mat[i][k] and mat[j][k] */
                    mat[i][k]=mat[i][k]+mat[j][k];
                    mat[j][k]=mat[i][k]-mat[j][k];
                    mat[i][k]=mat[i][k]-mat[j][k];

                }
            }
        }
    }

    /* performing Gaussian elimination */
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            float f=mat[j][i]/mat[i][i];
            for(k=0; k<n+1; k++)
            {
                mat[j][k]=mat[j][k]-f*mat[i][k];
            }
        }
    }
for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cout<< setw(7) << setprecision(2) << mat[i][j] << ' ';
        }
        cout<< '\n';
    }

    /* Backward substitution for discovering values of unknowns */
    for(i=n-1; i>=0; i--)
    {
        res[i]=mat[i][n];

        for(j=i+1; j<n; j++)
        {
            if(i!=j)
            {
                res[i]=res[i]-mat[i][j]*res[j];
            }
        }
        res[i]=res[i]/mat[i][i];
    }

    cout<<"\nThe values of unknowns for the above equations:\n";
    for(i=0; i<n; i++)
    {
        cout<<res[i]<<"\n";
    }
    /*
        3 -1 7
    2 3 1
    */

    return 0;
}
