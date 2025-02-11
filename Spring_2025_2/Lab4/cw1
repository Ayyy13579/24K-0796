#include <iostream>
using namespace std;

class Matrix {
    private:
    int x;
    int y;
    double** data;
    public:
    Matrix() : x(0), y(0), data(nullptr) {}

    Matrix(int rows, int cols) : x(rows), y(cols) {
        data = new double*[x];
        for (int i=0; i < x; i++) {
            data[i] = new double[y]();
        }
    }

    Matrix(const Matrix &obj1) : x(obj.x), y(obj.y) {
        data = new double*[x];
        for (int i=0; i< x; i++) {
            data = new double[y];
            for (int j=0; j < y; j++) {
                data[i][j] = obj1.data[i][j];
            }
        }
    }

    Matrix(Matrix&& m1) : x(m1.x), y(m1.y), data(m1.data) {
        m1.x = 0;
        m1.y = 0;
        m1.data = nullptr;
    }

    ~Matrix() {
        for (int i=0; i < x; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    int getRows() {
        return x;
    }
    int getColumns() {
        return y;
    }
    int at(int r, int c) {
        return data[r][c];
    }
    void fill(double value) {
        for (int i =0; i < x; i++) {
            for (int j=0; j<y; j++) {
                data[x][y] = value;
            }
        }
    }
    void transpose() {
        Matrix transposed(y,x);
        for (int i =0; i < x; i++) {
            for (int j=0; j<y; j++) {
                transposed[i][j] = data[i][j];
            }
        }
    }
}; 
