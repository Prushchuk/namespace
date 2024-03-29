#include <iostream>
#include <vector>
#include <cmath>

const double pi = 3.14159265358979323846;

namespace Math
{
    double sine(double angle) {
        return sin(angle);
    }

    double cosine(double angle) {
        return cos(angle);
    }

    double tangent(double angle) {
        return tan(angle);
    }

    double cotangent(double angle) {
        return 1.0 / tan(angle);
    }

    double power(double base, double exponent) {
        return pow(base, exponent);
    }
}

namespace MatrixOperations {
    class Matrix {
    private:
        int rows;
        int cols;
        std::vector<std::vector<double>> data;

    public:
        Matrix(int rows, int cols) : rows(rows), cols(cols), data(std::vector<std::vector<double>>(rows, std::vector<double>(cols, 0.0))) {}

        void set(int row, int col, double value) {
            data[row][col] = value;
        }

        double get(int row, int col) const {
            return data[row][col];
        }

        int getRows() const {
            return rows;
        }

        int getCols() const {
            return cols;
        }

        void print() const {
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    std::cout << data[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }

        static Matrix add(const Matrix& m1, const Matrix& m2) {
            if (m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols()) {
                std::cerr << "Matrix dimensions do not match for addition." << std::endl;
                exit(1);
            }

            Matrix result(m1.getRows(), m1.getCols());
            for (int i = 0; i < m1.getRows(); ++i) {
                for (int j = 0; j < m1.getCols(); ++j) {
                    result.set(i, j, m1.get(i, j) + m2.get(i, j));
                }
            }
            return result;
        }

        static Matrix multiply(const Matrix& m1, const Matrix& m2) {
            if (m1.getCols() != m2.getRows()) {
                std::cerr << "Matrix dimensions are not compatible for multiplication." << std::endl;
                exit(1);
            }

            Matrix result(m1.getRows(), m2.getCols());
            for (int i = 0; i < m1.getRows(); ++i) {
                for (int j = 0; j < m2.getCols(); ++j) {
                    double sum = 0.0;
                    for (int k = 0; k < m1.getCols(); ++k) {
                        sum += m1.get(i, k) * m2.get(k, j);
                    }
                    result.set(i, j, sum);
                }
            }
            return result;
        }
    };
}

int main()
{
    std::cout << "sin(PI/4) = " << Math::sine(pi / 4) << std::endl;
    std::cout << "cos(PI/4) = " << Math::cosine(pi / 4) << std::endl;
    std::cout << "tan(PI/4) = " << Math::tangent(pi / 4) << std::endl;
    std::cout << "cot(PI/4) = " << Math::cotangent(pi / 4) << std::endl;
    std::cout << "2^3 = " << Math::power(2, 3) << std::endl;

    MatrixOperations::Matrix matrix1(2, 2);
    matrix1.set(0, 0, 1);
    matrix1.set(0, 1, 2);
    matrix1.set(1, 0, 3);
    matrix1.set(1, 1, 4);

    MatrixOperations::Matrix matrix2(2, 2);
    matrix2.set(0, 0, 5);
    matrix2.set(0, 1, 6);
    matrix2.set(1, 0, 7);
    matrix2.set(1, 1, 8);

    std::cout << "Matrix 1:" << std::endl;
    matrix1.print();
    std::cout << std::endl;

    std::cout << "Matrix 2:" << std::endl;
    matrix2.print();
    std::cout << std::endl;

    MatrixOperations::Matrix sum = MatrixOperations::Matrix::add(matrix1, matrix2);
    std::cout << "Sum of matrices:" << std::endl;
    sum.print();
    std::cout << std::endl;

    MatrixOperations::Matrix product = MatrixOperations::Matrix::multiply(matrix1, matrix2);
    std::cout << "Product of matrices:" << std::endl;
    product.print();
}