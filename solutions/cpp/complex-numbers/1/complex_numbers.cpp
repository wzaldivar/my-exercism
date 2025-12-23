#include "complex_numbers.h"

#include <cmath>

namespace complex_numbers
{
    Complex::Complex(double real, double imag) : m_real(real), m_imag(imag) {}

    double Complex::imag() const { return m_imag; }

    double Complex::real() const { return m_real; }

    double Complex::abs() const
    {
        return std::sqrt(std::pow(this->m_real, 2) + std::pow(this->m_imag, 2));
    }

    Complex Complex::conj() const
    {
        return {this->m_real, -this->m_imag};
    }

    Complex Complex::exp() const
    {
        return Complex(std::pow(M_E, this->m_real), 0) * Complex(std::cos(this->m_imag), std::sin(this->m_imag));
    }

    Complex Complex::operator+(Complex const &other) const
    {
        return {this->m_real + other.m_real, this->m_imag + other.m_imag};
    }

    Complex Complex::operator-(Complex const &other) const
    {
        return {this->m_real - other.m_real, this->m_imag - other.m_imag};
    }

    Complex Complex::operator*(Complex const &other) const
    {
        return {this->m_real * other.m_real - this->m_imag * other.m_imag, this->m_imag * other.m_real + this->m_real * other.m_imag};
    }

    Complex Complex::operator/(Complex const &other) const
    {
        double sqr_sum = std::pow(other.m_real, 2) + std::pow(other.m_imag, 2);
        return {(this->m_real * other.m_real + this->m_imag * other.m_imag) / sqr_sum, (this->m_imag * other.m_real - this->m_real * other.m_imag) / sqr_sum};
    }
} // namespace complex_numbers
