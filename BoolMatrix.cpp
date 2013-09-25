#include "BoolMatrix.h"

Bool_matrix::Bool_matrix(int in, int im)
{
    n=in; m=im; arr=0;
    arr=new bool[n*m];
    if(arr==0)
    {
        n=0; m=0;
    }
}

Bool_matrix::Bool_matrix(int in, int im, bool *iarr)
{
    n=in; m=im;
    arr=new bool[n*m];
    if(arr==0)
    {
        n=0; m=0;
        return;
    }
    for(int i=0; i<n*m; i++)
        arr[i]=iarr[i];
}

Bool_matrix::Bool_matrix(const Bool_matrix &a)
{
    if(arr==a.arr)
        return;
    n=a.n; m=a.m;
    if(!arr)
        delete [] arr;
    arr=new bool[n*m];
    if(arr)
    {
        for(int i=0; i<n*m; i++)
            arr[i]=a.arr[i];
    }
    else
    {
        n=0; m=0;
    }
}

Bool_matrix::~Bool_matrix()
{
    if(arr)
        delete [] arr;
    n=0; m=0;
}

Bool_matrix Bool_matrix::operator=(Bool_matrix &a)
{
    if(arr==a.arr)
        return (*this);
    n=a.n; m=a.m;
    arr=new bool[n*m];
    if(!arr)
    {
        n=0; m=0;
        return (*this);
    }
    for(int i=0; i<n*m; i++)
        arr[i]=a.arr[i];

    return (*this);
}

Bool_matrix operator+(Bool_matrix &a, Bool_matrix &b)
{
    Bool_matrix tmp(a.get_n(), a.get_m(), new bool[a.get_n()*a.get_m()]);

    if(b.get_n()!=a.get_n() || b.get_m()!=a.get_m())
        return tmp;
    if(tmp.get_adress()==0)
    {
        tmp.set_n(0); tmp.set_n(0);
        return tmp;
    }

    for(int i=0; i<a.get_n()*a.get_m(); i++)
            tmp.get_adress()[i]=(a.get_adress()[i])&(b.get_adress()[i]);

    return tmp;
}

Bool_matrix operator*(Bool_matrix &a, Bool_matrix &b)
{
    Bool_matrix tmp(a.get_n(), a.get_m(), new bool[a.get_n()*a.get_m()]);
    bool temp=false;

    if(b.get_m()!=a.get_n() || b.get_n()!=a.get_m())
        return tmp;
    if(tmp.get_adress()==0)
    {
        tmp.set_n(0); tmp.set_n(0);
        return tmp;
    }

    for(int i=0; i<a.get_n(); i++)
        for(int j=0; j<a.get_m(); j++)
        {
            for(int k=0; k<a.get_m(); k++)
                temp|=(a.get_adress()[i*a.get_m()+k])&&(b.get_adress()[k*a.get_m()+j]);
            tmp.get_adress()[i*a.get_m()+j]=temp;
            temp=false;
        }

    return tmp;
}

Bool_matrix Bool_matrix::operator ++()
{
    for(int i=0; i<n*m; i++)
        arr[i]=!arr[i];
    return (*this);
}

int Bool_matrix::number_ones()
{
    int tmp=0;
    for(int i=0; i<n*m; i++)
        if(arr[i]==true)
            tmp++;
    return tmp;
}
