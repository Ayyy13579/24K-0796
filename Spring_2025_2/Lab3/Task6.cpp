#include <iostream>
using namespace std;


class Matrix {
    private:
    int rows;
    int columns;
    int** elements;
    public:
    Matrix(int rows, int columns) {
        this->rows = rows;
        this->columns = columns;
        elements = new int*[rows];
        for (int i=0; i<rows; i++) {
            elements[i] = new int[columns];
        }
    }
    int getrows(){
        return rows;
    }
    int getcolumns(){
        return columns;
    }
    void setElement(int row, int column, int value){
        elements[row][column] = value;
    }
    void Add(Matrix m) {
        if (rows == m.getrows() && columns == m.getcolumns()) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    elements[i][j] += m.elements[i][j];
                }
            }
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    cout << elements[i][j] << " ";
                }
            }
        }
    }
    void Multiply(Matrix m) {
        if (columns == m.getrows()) {
            Matrix result(rows, m.getcolumns());
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < m.getcolumns(); j++) {
                    result.elements[i][j] = 0;
                    for (int k = 0; k < columns; k++) {
                        result.elements[i][j] += elements[i][k] * m.elements[k][j];
                    }
                }
            }
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < m.getcolumns(); j++) {
                    cout << result.elements[i][j] << " ";
                }
            }
        }
    }
};

int main() {
    
    Matrix m1(3, 3);
    m1.setElement(0, 0, 1);
    m1.setElement(0, 1, 2);
    m1.setElement(0, 2, 3);
    m1.setElement(1, 0, 4);
    m1.setElement(1, 1, 5);
    m1.setElement(1, 2, 6);
    m1.setElement(2, 0, 7);
    m1.setElement(2, 1, 8);
    m1.setElement(2, 2, 9);

    Matrix m2(3, 3);
    m2.setElement(0, 0, 7);
    m2.setElement(0, 1, 8);
    m2.setElement(0, 2, 9);
    m2.setElement(1, 0, 9);
    m2.setElement(1, 1, 10);
    m2.setElement(1, 2, 11);
    m2.setElement(2, 0, 11);
    m2.setElement(2, 1, 12);
    m2.setElement(2, 2, 13);
    m1.Add(m2);
    cout << "\n";
    m1.Multiply(m2);
}