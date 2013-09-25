#ifndef BOOLMATRIX_H_INCLUDED
#define BOOLMATRIX_H_INCLUDED

class Bool_matrix
{
public:
    void cout_matrix();
    int number_ones();

    int get_element(int in, int im){return arr[in*m+im];}
    bool *get_adress(){return arr;}
    int get_n(){return n;}
    int get_m(){return m;}

    void set_element(int in, int im, char data){arr[in*n+im]=data;}
    void set_arr(bool *iarr){arr=iarr;}
    void set_n(int in){n=in;}
    void set_m(int im){m=im;}

    Bool_matrix():n(0),m(0),arr(0) {}
    Bool_matrix(int in, int im);
    Bool_matrix(int in, int im, bool *iarr);
    Bool_matrix(const Bool_matrix &a);

    friend Bool_matrix operator+(Bool_matrix &a, Bool_matrix &b);
    friend Bool_matrix operator*(Bool_matrix &a, Bool_matrix &b);
    Bool_matrix operator=(Bool_matrix &a);
    Bool_matrix operator ++();

    ~Bool_matrix();
private:
    int n, m;
    bool *arr;
};

#endif // BOOLMATRIX_H_INCLUDED
