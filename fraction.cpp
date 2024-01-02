#include <iostream>
class Fraction {

public:
    int numerator;
    int denominator;

    Fraction() : numerator(0), denominator(1) {}
    Fraction(int num, int den) : numerator(num), denominator(den) {
        simplify();
    }

    int getNumerator() const { 
        return numerator; 
        }

    int getDenominator() const 
    { 
        return denominator; 
    }
    void setNumerator(int num) {
        numerator = num;
        simplify(); 
    }
    void setDenominator(int den) {
        denominator = den; 
        simplify(); 
    }

    Fraction& operator+=(const Fraction& other) {
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    Fraction operator+(const Fraction& other) const {
        Fraction result = *this;
        result += other;
        return result;
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
        out << fraction.numerator << '/' << fraction.denominator;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Fraction& fraction) {
        char slash;
        in >> fraction.numerator >> slash >> fraction.denominator;
        fraction.simplify();
        return in;
    }

    double toDouble() const {
        return static_cast<double>(numerator) / denominator;
    }

    int gcd(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return std::abs(a);
    }

    void simplify() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        int commonDivisor = gcd(std::abs(numerator), denominator);
        numerator /= commonDivisor;
        denominator /= commonDivisor;
    }
};

int main() {

    std::cout << "Enter a fraction(numerator/denominator): ";
    Fraction input;
    std::cin >> input;
    std::cout << "You entered: " << input << std::endl;

    return 0;
}