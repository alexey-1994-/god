#include <iostream>
using namespace std;
#include "BoolMatrix.h"

void show(Bool_matrix &a)
{
    for(int i=0; i<a.get_n(); i++)
    {
        for(int j=0; j<a.get_m(); j++)
            cout<<a.get_adress()[i*a.get_m()+j];
        cout<<endl;
    }
}

Bool_matrix delta(Bool_matrix a, Bool_matrix b)
{
    Bool_matrix temp;

    ++a; ++b;

    return a*b;
}

int main()
{
    const int n=3, m=3;
    bool a_tmp[n*m]={1,1,1, 1,1,1, 1,1,1};
    bool b_tmp[n*m]={1,1,1, 0,0,0, 1,1,1};

    Bool_matrix *a=new Bool_matrix[12];

    for(int i=0; i<6; i++)
    {
        Bool_matrix temp_1(n,m,a_tmp);
        a[2*i]=temp_1;
        Bool_matrix temp_2(n,m,b_tmp);
        a[2*i+1]=temp_2;
    }

    for(int i=0; i<9; i++)
        a[i]=delta(a[i+1],a[i+2]);

    for(int i=0; i<12; i++)
    {
        show(a[i]);
        cout<<endl;
    }

    delete [] a;
    return 0;
}
