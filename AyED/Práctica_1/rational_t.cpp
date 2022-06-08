/**
 * AUTOR: Samuel Pérez López
 * FECHA: 25/02/2022
 * EMAIL: alu0101481524@ull.edu.es - samperezlopez@gmail.com
 * VERSION: 1.0
 * ASIGNATURA: Algoritmos y Estructuras de Datos
 * PRÁCTICA Nº: 1
 * COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
 *              "C++ Programming Style Guidelines"
 * COMPILACIÓN: g++ -g rational_t.cpp main_rational_t.cpp -o main_rational_t
**/

#include "rational_t.hpp"


/**
 * @brief Convert the number to decimal.
 * @param[in] none
 */
double Rational::Value() const { 
  return double(GetNumerator()) / GetDenominator();
}

/**
 * @brief Simplifies the rational number.
 * @param[in] none
 */
void Rational::Simplify() {
  int denominator = gcd(numerator_, denominator_);
  numerator_ /= denominator;
  denominator_ /= denominator;
}

/**
 * @brief Check if the two numbers are equal.
 * @param[in] rational: The second rational number to check with the first one.
 * @param[in] presicion: kEpsilon constant.
 */
bool Rational::IsEqual(const Rational& rational, const double precision) const {
  if ((fabs(Value() - rational.Value())) < precision) {
    return true;
  } else {
    return false;
  }
}

/**
 * @brief Check if the first number is greater than the second one.
 * @param[in] rational: The second rational number to check with the first one.
 * @param[in] presicion: kEpsilon constant.
 */
bool Rational::IsGreater(const Rational& rational, const double precision) const {
  if ((Value() - rational.Value()) > precision) {
    return true;
  } else {
    return false;
  }
}

/**
 * @brief Check if the first number is less than the second one.
 * @param[in] rational: The second rational number to check with the first one.
 * @param[in] presicion: kEpsilon constant.
 */
bool Rational::IsLess(const Rational& rational, const double precision) const {
  if ((Value() - rational.Value()) < -precision) {
    return true;
  } else {
    return false;
  }
}

/**
 * @brief Assert that the number is rational.
 * @param[in] none
 */
bool Rational::is_integer(void) {
  if (GetNumerator() % GetDenominator() == 0) {
    return true;
  } else {
    return false;
  }
}

/**
 * @brief Adds two rational numbers.
 * @param[in] rational: The second rational number to add with the first one.
 */
Rational Rational::Add(const Rational& rational) {
  if (GetDenominator() == rational.GetDenominator()) {
    Rational result(GetNumerator() + rational.GetNumerator(), GetDenominator());
    result.Simplify();
    return result;
  }
  else {
    double den_result = GetDenominator() * rational.GetDenominator();
    double sum_numerator = GetNumerator() * rational.GetDenominator() + rational.GetNumerator() * GetDenominator();
    Rational result(sum_numerator, den_result);
    result.Simplify();
    return result;
  }
}

/**
 * @brief Substracts two rational numbers.
 * @param[in] rational: The second rational number to substract with the first one.
 */
Rational Rational::Substract(const Rational& rational) {
  if (GetDenominator() == rational.GetDenominator()) {
    Rational result(GetNumerator() - rational.GetNumerator(), GetDenominator());
    result.Simplify();
    return result;
  } else {
    double den_result = GetDenominator() * rational.GetDenominator();
    double sum_numerator = GetNumerator() * rational.GetDenominator() - rational.GetNumerator() * GetDenominator();
    Rational result(sum_numerator, den_result);
    result.Simplify();
    return result;
  }
}

/**
 * @brief Multiplies two rational numbers.
 * @param[in] rational: The second rational number to multiply with the first one.
 */
Rational Rational::Multiply(const Rational& rational) {
  double num_result = GetNumerator() * rational.GetNumerator();
  double den_result = GetDenominator() * rational.GetDenominator();
  Rational result(num_result, den_result);
  result.Simplify();
  return result;
}

/**
 * @brief Divides two rational numbers.
 * @param[in] rational: The second rational number to divide with the first one.
 */
Rational Rational::Divide(const Rational& rational) {
  double num_result = GetNumerator() * rational.GetDenominator();
  double den_result = GetDenominator() * rational.GetNumerator();
  Rational result(num_result, den_result);
  result.Simplify();
  return result;
}

// E/S

/**
 * @brief Prints the rational number.
 * @param[in] os: The output.
 */
void Rational::Write(std::ostream& os) const {
  os << GetNumerator() << "/" << GetDenominator() << "=" << Value() << std::endl;
}

/**
 * @brief Collect information for the numerator and denominator.
 * @param[in] is: The input.
 */
void Rational::Read(std::istream& is) {
  std::cout << "Numerador? ";
  is >> numerator_;
  std::cout << "Denominador? ";
  is >> denominator_;
  assert(denominator_ != 0);
}

/**
 * @brief This is de Euclide's algorithm.
 * @param[in] number1: The first number.
 * @param[in] number1: The second number.
 */
int gcd(long long number_1, long long number_2) {
  if (number_2 == 0) {
    return number_1;
  }
  return gcd(number_2, number_1 % number_2);
}