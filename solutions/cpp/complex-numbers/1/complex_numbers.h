#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H

namespace complex_numbers
{
    struct Complex
    {
    private:
        double m_real;
        double m_imag;

    public:
        Complex(double real, double imag);

        double real() const;
        double imag() const;

        double abs() const;

        Complex conj() const;

        Complex exp() const;

        Complex operator+(Complex const &other) const;
        Complex operator-(Complex const &other) const;
        Complex operator*(Complex const &other) const;
        Complex operator/(Complex const &other) const;
    };

} // namespace complex_numbers

#endif // COMPLEX_NUMBERS_H
