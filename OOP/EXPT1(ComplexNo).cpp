#include<iostream>
using namespace std;
class Complex
{
    public :
    float real,img;
    Complex()
    {}
    Complex operator +(Complex);
    Complex operator *(Complex);
    friend ostream & operator <<(ostream&,Complex&);
    friend istream & operator >>(istream&,Complex&);
};

Complex Complex::operator +(Complex obj)
{
    Complex temp;
    temp.real=real+obj.real;
    temp.img=img+obj.img;
    return temp;
}

Complex Complex::operator *(Complex obj)
{
    Complex temp;
    temp.real=real*obj.real-img*obj.img;
    temp.img=real*obj.img+img*obj.real;
    return temp;
}

//definition of istream
istream& operator >>(istream& is,Complex& obj)
{
    is>>obj.real;
    is>>obj.img;
    return is;
}
//definition of ostream
ostream& operator <<(ostream& os,Complex& obj)
{
    os<<obj.real;
    os<<"+"<<obj.img<<"i";
    return os;
}
int main()
{
    Complex a,b,c,d,e;
    cout<<endl<<"enter 1st no"<<endl;
    cout<<"enter real and img. no = "<<endl;
    cin>>a;
    cout<<endl<<"enter 2nd no"<<endl;
    cout<<"enter real and img. no = "<<endl;
    cin>>b;
    cout<<endl<<"arithmatic operations are"<<endl;
    c=a+b;
    cout<<"addition is= "<<c<<endl;
    d=a*b;
    cout<<"multiplication is ="<<d<<endl<<endl;
    return 0;
}