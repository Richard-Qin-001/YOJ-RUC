#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// ____qcodep____
#include <vector>

class Matrix
{
private:
    int row, col;
    vector<vector<double> > table;
public:
    Matrix(int r, int c) : row(r), col(c) {
        table.assign(row, vector<double>(col, 0));
    }
    friend istream& operator>>(istream&is, Matrix&matrix){
        int row = matrix.row, col = matrix.col;
        for(int i = 0; i < row; ++i)for(int j = 0; j < col; ++j)is>>matrix.table[i][j];
        return is;
    }
    friend ostream& operator<<(ostream&os, const Matrix&matrix) {
        int row = matrix.row, col = matrix.col;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j)os << setw(6) << matrix.table[i][j];
            os << endl;
        }
        return os;
    }
    Matrix operator+(const Matrix&other) const {
        if(this->row != other.row || this->col != other.col){
            cout << "invalid operation!" << endl;
            return Matrix(0, 0);
        }
        Matrix result(row, col);
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                result.table[i][j] = this->table[i][j] + other.table[i][j];
            }
        }
        return result;
    }
    Matrix operator-(const Matrix &other) const{
        if (this->row != other.row || this->col != other.col){
            cout << "invalid operation!" << endl;
            return Matrix(0, 0);
        }
        Matrix result(row, col);
        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j){
                result.table[i][j] = this->table[i][j] - other.table[i][j];
            }
        }
        return result;
    }
    Matrix operator*(const Matrix &other) const{
        if(this->col != other.row){
            cout << "invalid operation!" << endl;
            return Matrix(0, 0);
        }
        Matrix result(this->row, other.col);
        for(int i = 0; i < this->row; ++i){
            for(int j = 0; j < other.col; ++j){
                for(int k = 0; k < this->col; ++k){
                    result.table[i][j] += this->table[i][k] * other.table[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    int r,c;

    cin>>r>>c;
    if(r<1 || c<1){
    cout<<"Input error."<<endl;
    exit(1);
    }
    Matrix A(r,c);
    cin >> A;
    
    cin>>r>>c;
    if(r<1 || c<1){
    cout<<"Input error."<<endl;
    exit(1);
    }
    Matrix B(r,c);
    cin >> B;
    
    cout<<"A + B:"<<endl;
    cout << A + B <<endl;

    cout<<"A - B:"<<endl;
    cout << A - B <<endl;
    
    cout<<"A * B:"<<endl;
    cout << A * B <<endl;

    return 0;
}