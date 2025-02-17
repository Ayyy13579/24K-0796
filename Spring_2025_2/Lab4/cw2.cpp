#include <iostream>
#include <cmath>
using namespace std;

class Polynomial {
private:
    double* coefficients;
    int degree;

public:
    Polynomial() : degree(0) {
        coefficients = new double[1]{0};
    }

    Polynomial(int deg, const double* coeffs) : degree(deg) {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = coeffs[i];
        }
    }

    Polynomial(const Polynomial& other) : degree(other.degree) {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = other.coefficients[i];
        }
    }

    Polynomial(Polynomial&& other) noexcept : degree(other.degree), coefficients(other.coefficients) {
        other.coefficients = nullptr;
        other.degree = 0;
    }

    ~Polynomial() {
        delete[] coefficients;
    }

    int getDegree() const {
        return degree;
    }

    double evaluate(double x) const {
        double result = 0;
        for (int i = 0; i <= degree; ++i) {
            result += coefficients[i] * pow(x, i);
        }
        return result;
    }

    Polynomial add(const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        double* newCoeffs = new double[maxDegree + 1]{0};

        for (int i = 0; i <= degree; ++i) {
            newCoeffs[i] += coefficients[i];
        }

        for (int i = 0; i <= other.degree; ++i) {
            newCoeffs[i] += other.coefficients[i];
        }

        return Polynomial(maxDegree, newCoeffs);
    }

    Polynomial multiply(const Polynomial& other) const {
        int newDegree = degree + other.degree;
        double* newCoeffs = new double[newDegree + 1]{0};

        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                newCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(newDegree, newCoeffs);
    }

    void display() const {
        for (int i = degree; i >= 0; --i) {
            cout << coefficients[i] << "x^" << i;
            if (i > 0) cout << " + ";
        }
        cout << endl;
    }
};

int main() {
    double coeffs1[] = {1, 2, 3}; // 3x^2 + 2x + 1
    Polynomial p1(2, coeffs1);

    double coeffs2[] = {4, 0, 5}; // 5x^2 + 4
    Polynomial p2(2, coeffs2);

    cout << "Polynomial 1: ";
    p1.display();

    cout << "Polynomial 2: ";
    p2.display();

    Polynomial sum = p1.add(p2);
    cout << "Sum: ";
    sum.display();

    Polynomial product = p1.multiply(p2);
    cout << "Product: ";
    product.display();

    double x = 2;
    cout << "p1(" << x << ") = " << p1.evaluate(x) << endl;

    return 0;
}
