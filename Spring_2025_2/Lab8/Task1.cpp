#include <iostream>
using namespace std;

class Fraction {
    private:
    int numerator;
    int denominator;
    public:
    Fraction(int num, int den) : numerator(num), denominator(den) {}
    
    int GCD() {
    while (denominator != 0) {
        int temp = denominator;
        denominator = numerator % denominator;
        numerator = temp;
        }
    return numerator;
    }
    void reduceFraction() {
    int divisor = GCD();
    numerator /= divisor;
    denominator /= divisor;
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
        }
    }
    Fraction operator+(const Fraction other) {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }
    Fraction operator-(const Fraction other) {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }
    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }
    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
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
        return in;
    }
};

int main() {
    Fraction f1(1,2), f2(3, 4);

    cout << "Fraction 1: " << f1 << endl;
    cout << "Fraction 2: " << f2 << endl;

    return 0;
}
