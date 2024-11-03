#include<iostream>
using namespace std;
int p=0;
class Tiny {
char v;
void assign(int i)
    {
        if(i&~077) 
           throw Bad_range(); 
        v = i;
    }
public:
class Bad_range{ };
Tiny (int a)
{
    assign(a);
}


Tiny operator+(Tiny num)
{
     int b =v+ num.v;
    if(b & ~077 )
       p=b;
    else
       return b;
}

Tiny operator-(Tiny num)
{
     int b =v- num.v;
    if(b & ~077 )
       p=b;
    else
       return b;
}

Tiny operator-(int num)
{
     int b =v- num;
    if(b & ~077 )
       p=b;
    else
       return b;
       
}

operator int() const 
{ 
    return v; 
}

Tiny operator=(int i)
{
    assign(i);
    return *this;
}

Tiny operator=(Tiny i)
{
    assign(i.v);
    return *this;
}

int print()
{
    return v;
}

};

ostream& operator<<(ostream& os,Tiny t){
	os<<t.print()<<endl;
    }


/* Example of Tiny objects mixing with ints in arithmetic expressions */
int main(){
Tiny c1 = 2; // Perform range check
cout<<c1<<endl;
Tiny c2 = 62; // perform range check
cout<<c2<<endl;
Tiny c3 = c2 - c1; // c3 = 60;
cout<<c3<<endl;
Tiny c4 = c3; // no range check required
cout<<c4<<endl;
//c1 = c1 + c2; // range error: c1 can’t be 64
int i = c1 + c2; // i = 64
cout<<i<<endl;
i = c3 - 64; //i = -4
cout<<i<<endl;
//c2 = c3 - 64; // range error: c2 can’t be -4
c3 = c4; // no range check required
cout<<c4<<endl;
}