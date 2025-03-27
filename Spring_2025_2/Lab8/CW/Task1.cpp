#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    int GCD(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduceFraction() {
        int divisor = GCD(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        reduceFraction();
    }

    Fraction operator+(const Fraction& other) const {
        Fraction result(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
        result.reduceFraction();
        return result;
    }

    Fraction operator-(const Fraction& other) const {
        Fraction result(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
        result.reduceFraction();
        return result;
    }

    Fraction operator*(const Fraction& other) const {
        Fraction result(numerator * other.numerator, denominator * other.denominator);
        result.reduceFraction();
        return result;
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw invalid_argument("Cannot divide by zero.");
        }
        Fraction result(numerator * other.denominator, denominator * other.numerator);
        result.reduceFraction();
        return result;
    }

    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    bool operator<=(const Fraction& other) const {
        return !(other < *this);
    }

    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& out, const Fraction& f) {
        out << f.numerator << "/" << f.denominator;
        return out;
    }

    friend istream& operator>>(istream& in, Fraction& f) {
        char slash;
        in >> f.numerator >> slash >> f.denominator;
        if (f.denominator == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        f.reduceFraction();
        return in;
    }
};

int main() {
    Fraction f1(1, 2), f2(3, 4);

    cout << "Fraction 1: " << f1 << endl;
    cout << "Fraction 2: " << f2 << endl;
    cout << "Sum: " << (f1 + f1) << endl;

    return 0;
}
