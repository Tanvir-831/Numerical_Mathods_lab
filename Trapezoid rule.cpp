
#include <iostream>
#include <math.h>
#define f(x) (x + (1/x))
using namespace std;
void trapezoidalRule (){
double a, b;
int n;
cout << "\n  ----   Integration by trapezoidal Rule   ----\n\n\a";
cout << " equation: (x + (1/x))\n";
cout << "Enter the lower limit of the integral: ";
cin >> a;
cout << "Enter the upper limit of the integral: ";
cin >> b;
cout << "Enter the number of subintervals: ";
cin >> n;
double h = abs(b - a) / n;
double ifx = 0;
ifx = ifx + f(a) + f(b);
for (double i = a+h; i < b;){
ifx = ifx + (2 * f(i));
i = i + h;
}
ifx = ifx * h / 2;
cout << "\nThe integral of the equation using Trapezoidal Rule is " << ifx << endl;
}
int main (){
trapezoidalRule();
}
