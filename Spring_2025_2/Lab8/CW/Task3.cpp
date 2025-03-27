#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class BigInteger {
private:
    vector<int> digits;
    bool isNegative;

    void fromString(const string& num) {
        isNegative = (num[0] == '-');
        for (int i = num.size() - 1; i >= (isNegative ? 1 : 0); --i)
            digits.push_back(num[i] - '0');
    }

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();
        if (digits.size() == 1 && digits[0] == 0)
            isNegative = false;
    }

    static bool absLessThan(const BigInteger& a, const BigInteger& b) {
        if (a.digits.size() != b.digits.size()) return a.digits.size() < b.digits.size();
        for (int i = a.digits.size() - 1; i >= 0; --i)
            if (a.digits[i] != b.digits[i]) return a.digits[i] < b.digits[i];
        return false;
    }

public:
    BigInteger() : isNegative(false) {}

    BigInteger(string num) {
        fromString(num);
    }

    BigInteger(long long num) {
        fromString(to_string(num));
    }

    BigInteger operator+(const BigInteger& other) const {
        if (isNegative == other.isNegative) {
            BigInteger result;
            result.isNegative = isNegative;
            int carry = 0, sum;
            size_t i;
            for (i = 0; i < max(digits.size(), other.digits.size()) || carry; ++i) {
                sum = carry;
                if (i < digits.size()) sum += digits[i];
                if (i < other.digits.size()) sum += other.digits[i];
                carry = sum / 10;
                result.digits.push_back(sum % 10);
            }
            return result;
        }
        return isNegative ? (other - (-(*this))) : (*this - (-other));
    }

    BigInteger operator-(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            return *this + (-other);
        }
        if (absLessThan(*this, other)) {
            return -(other - *this);
        }
        BigInteger result;
        result.isNegative = isNegative;
        int borrow = 0, diff;
        for (size_t i = 0; i < digits.size(); ++i) {
            diff = digits[i] - borrow - (i < other.digits.size() ? other.digits[i] : 0);
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits.push_back(diff);
        }
        result.removeLeadingZeros();
        return result;
    }

    BigInteger operator*(const BigInteger& other) const {
        BigInteger result;
        result.digits.resize(digits.size() + other.digits.size(), 0);
        result.isNegative = (isNegative != other.isNegative);
        for (size_t i = 0; i < digits.size(); ++i) {
            int carry = 0;
            for (size_t j = 0; j < other.digits.size() || carry; ++j) {
                int sum = result.digits[i + j] + digits[i] * (j < other.digits.size() ? other.digits[j] : 0) + carry;
                carry = sum / 10;
                result.digits[i + j] = sum % 10;
            }
        }
        result.removeLeadingZeros();
        return result;
    }

    BigInteger operator-() const {
        BigInteger result = *this;
        result.isNegative = !isNegative;
        return result;
    }

    bool operator==(const BigInteger& other) const {
        return isNegative == other.isNegative && digits == other.digits;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (isNegative != other.isNegative) return isNegative;
        return isNegative ? absLessThan(other, *this) : absLessThan(*this, other);
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger& other) const {
        return !(other < *this);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& out, const BigInteger& num) {
        if (num.isNegative) out << "-";
        for (int i = num.digits.size() - 1; i >= 0; --i)
            out << num.digits[i];
        return out;
    }

    friend istream& operator>>(istream& in, BigInteger& num) {
        string input;
        in >> input;
        num.fromString(input);
        return in;
    }
};

int main() {
    BigInteger a, b;
    cout << "Enter two large integers:\n";
    cin >> a >> b;

    cout << "a = " << a << "\n";
    cout << "b = " << b << "\n";
    cout << "a + b = " << (a + b) << "\n";
    cout << "a - b = " << (a - b) << "\n";
    cout << "a * b = " << (a * b) << "\n";
    
    cout << "Comparison:\n";
    cout << "a == b: " << (a == b) << "\n";
    cout << "a != b: " << (a != b) << "\n";
    cout << "a < b: " << (a < b) << "\n";
    cout << "a > b: " << (a > b) << "\n";

    return 0;
}
