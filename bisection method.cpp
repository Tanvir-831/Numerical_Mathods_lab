#include <iostream>
using namespace std;
#define EP 0.0001

double solution(double x) {
   return x*x - 4*x - 10;
}

void bisection(double a, double b) {
   if (solution(a) * solution(b) >= 0) {
      cout << "You have not assumed right a and b\n";
      return;
   }
   int n = 0;
   double c = a;
   while ((b-a) >= EP) {

      c = (a+b)/2;

      if (solution(c) == 0.0)
         break;

      else if (solution(c)*solution(a) < 0)
         b = c;
      else
         a = c;
         n++;
   }
   cout << "The value of root is : " << c << endl;
   cout << "Number of Iterations: " << n << endl;
}

int main() {
     double a, b;
    cout << "   Solution by Bisection Method\n\n";
    cout << " Equation: x*x - 4*x - 10\n";
    cout << " Enter initial guess:\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

   bisection(a, b);
   return 0;
}
