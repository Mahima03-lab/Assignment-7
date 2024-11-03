#include<iostream>
using namespace std;
struct X{
     int i;
     X(int a):i{a}{}
     X operator+(int b)  // `operator+` for adding an int to `X`
     {
        X c = i+b;
        return c;
     }
};
struct Y{
      int i;
      Y operator+(X x) // `operator+` for adding `X` to `Y`
      {
        Y d = x + i; //using 'operator+' for 'X'
        return d;
      }
      operator int() // Conversion operator to `int` from `Y`
      {
        return i;
      }
      Y(X x){
        i=x.i;
      }
};


// Overload `<<` for output of `Y`
ostream& operator<<(ostream& os,Y y)
{
    os<<y.i;
    return os;
}

// `operator*` for multiplying `X` and `Y`
extern X operator*(X x, Y y)
{
    X p = x.i*y.i;
    return p;
}
extern int f(X x)
{
    return x.i;
}
X x = 1;
Y y = x;
int i=2;

int main() {
    cout<<i + 10<<endl; 
    cout<<y+X(10)<<endl;  
    cout<<y + X(10) * y<<endl;
    cout<<x + y + i<<endl;
    cout<< x * x + i<<endl;
    cout<< f(7)<<endl;
    cout<<f(X(y))<<endl;
    cout<< y + y<<endl; 
    cout<<106 + y<<endl;
}