#include <iostream>
#include <vector>
using namespace std;
class Vector {
    public:

    std::vector<double> values;
    Vector() {}
    Vector(const std::vector<double>& v) : values(v) {}
    Vector(int size, double initialValue = 0.0) : values(size, initialValue) {}
    Vector(double singleValue) : values({singleValue}) {}

    double getValue(int index) const {
        return values[index];
    }

    void setValue(int index, double value) {
        values[index] = value;
    }

    int getSize() const {
        return values.size();
    }

    Vector& operator+=(const Vector& other) {
        for (int i = 0; i < getSize(); ++i) {
            values[i] += other.getValue(i);
        }
        return *this;
    }

    Vector& operator-=(const Vector& other) {
        for (int i = 0; i < getSize(); ++i) {
            values[i] -= other.getValue(i);
        }
        return *this;
    }

    Vector operator+(const Vector& other) const {
       
        Vector result(*this);
        result += other;
        return result;
    }

    Vector operator-(const Vector& other) const {
        
        Vector result(*this);
        result -= other;
        return result;
    }

    Vector operator*(const Vector& other) const {
        if (other.getSize() == 1) {
            Vector result(*this);
            for (int i = 0; i < getSize(); ++i) {
                result.setValue(i, result.getValue(i) * other.getValue(0));
            }
            return result;
        } else if (getSize() == other.getSize()) {
            double result = 0.0;
            for (int i = 0; i < getSize(); ++i) {
                result += values[i] * other.getValue(i);
            }
            return Vector(result);
        } else {
            throw std::invalid_argument("Vectors must have the same size or less than one for scalar product");
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec) {
        os << "[ ";
        for (int i = 0; i < vec.getSize(); ++i) {
            os << vec.getValue(i);
            if (i < vec.getSize() - 1) {
                os << ", ";
            }
        }
        os << " ]";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Vector& vec) {
        int size;
        std::cout << "Enter the size of the vector: ";
        is >> size;

        vec.values.resize(size);

        for (int i = 0; i < size; ++i) {
            std::cout << "Enter value for element " << i + 1 << ": ";
            is >> vec.values[i];
        }

        return is;
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            values = other.values;
        }
        return *this;
    }
};

int main() {
    Vector v1, v2;

    std::cout << "Enter values for the first vector:\n";
    std::cin >> v1;

    std::cout << "Enter values for the second vector:\n";
    std::cin >> v2;

    if (v1.getSize()==v2.getSize())
    {
        Vector sum = v1 + v2;
        Vector difference = v1 - v2;
        Vector product = v1 * v2;

        std::cout << "Sum of vectors: " << sum << std::endl;
        std::cout << "Difference of vectors: " << difference << std::endl;
        std::cout << "Scalar product of vectors: " << product << std::endl;
    }
    else {
        Vector product = v1 * v2;
        std::cout << "Scalar product of vectors: " << product << std::endl;
    }


    return 0;
}