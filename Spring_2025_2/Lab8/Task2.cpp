#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class PolynomialUtils;

class Polynomial {
private:
    vector<int> coefficients;

public:
    Polynomial() {}

    Polynomial(const vector<int>& coeffs) : coefficients(coeffs) {}

    Polynomial operator+(const Polynomial& other) const {
        vector<int> result(max(coefficients.size(), other.coefficients.size()), 0);
        for (size_t i = 0; i < coefficients.size(); ++i) result[i] += coefficients[i];
        for (size_t i = 0; i < other.coefficients.size(); ++i) result[i] += other.coefficients[i];
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        vector<int> result(max(coefficients.size(), other.coefficients.size()), 0);
        for (size_t i = 0; i < coefficients.size(); ++i) result[i] += coefficients[i];
        for (size_t i = 0; i < other.coefficients.size(); ++i) result[i] -= other.coefficients[i];
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        vector<int> result(coefficients.size() + other.coefficients.size() - 1, 0);
        for (size_t i = 0; i < coefficients.size(); ++i) {
            for (size_t j = 0; j < other.coefficients.size(); ++j) {
                result[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(result);
    }

    friend ostream& operator<<(ostream& os, const Polynomial& p) {
        bool first = true;
        for (int i = p.coefficients.size() - 1; i >= 0; --i) {
            if (p.coefficients[i] != 0) {
                if (!first) os << " ";
                if (p.coefficients[i] > 0 && !first) os << "+ ";
                if (p.coefficients[i] < 0) os << "- ";
                os << (abs(p.coefficients[i]) != 1 || i == 0 ? abs(p.coefficients[i]) : "") << (i > 0 ? "x" : "")
                   << (i > 1 ? "^" + to_string(i) : "");
                first = false;
            }
        }
        if (first) os << "0";
        return os;
    }

    friend class PolynomialUtils;
};

class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x) {
        int result = 0;
        int power = 1;
        for (int coeff : p.coefficients) {
            result += coeff * power;
            power *= x;
        }
        return result;
    }

    static Polynomial derivative(const Polynomial& p) {
        if (p.coefficients.size() < 2) return Polynomial();
        vector<int> deriv(p.coefficients.size() - 1, 0);
        for (size_t i = 1; i < p.coefficients.size(); ++i) {
            deriv[i - 1] = p.coefficients[i] * static_cast<int>(i);
        }
        return Polynomial(deriv);
    }
};

int main() {
    Polynomial p1({1, -2, 3});
    Polynomial p2({0, 4, -1});

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;

    cout << "p1: " << p1 << "\n";
    cout << "p2: " << p2 << "\n";
    cout << "Sum: " << sum << "\n";
    cout << "Difference: " << diff << "\n";
    cout << "Product: " << prod << "\n";

    cout << "p1 evaluated at x=2: " << PolynomialUtils::evaluate(p1, 2) << "\n";
    cout << "Derivative of p1: " << PolynomialUtils::derivative(p1) << "\n";

    return 0;
}
