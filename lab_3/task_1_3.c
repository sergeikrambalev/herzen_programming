#include <math.h>
#include <stdio.h>

typedef struct {
  double re;
  double im;
} Complex;

Complex cx_create(double re, double im) {
  Complex c;
  c.re = re;
  c.im = im;
  return c;
}

void cx_print(const char *name, Complex c) {
  if (c.im > 0) {
    printf("%s = %.6f + %.6fi\n", name, c.re, c.im);
  } else {
    printf("%s = %.6f - %.6fi\n", name, c.re, c.im);
  }
}

Complex cx_add(Complex a, Complex b) {
  Complex result;
  result.re = a.re + b.re;
  result.im = a.im + b.im;
  return result;
}

Complex cx_mul(Complex a, Complex b) {
  Complex result;
  result.re = a.re * b.re - a.im * b.im;
  result.im = a.re * b.im + a.im * b.re;
  return result;
}

Complex cx_div(Complex c, double scalar) {
  Complex result;
  result.re = c.re / scalar;
  result.im = c.im / scalar;
  return result;
}

Complex cx_pow(Complex c, int n) {
  Complex result = cx_create(1, 0);
  Complex base = c;
  if (n == 0)
    return result;
  for (int i = 0; i < n; i++) {
    result = cx_mul(result, base);
  }
  return result;
}

Complex cx_exp(Complex c, int max_terms) {
  Complex sum = cx_create(1, 0);
  Complex term = cx_create(1, 0);

  for (int n = 1; n <= max_terms; n++) {
    term = cx_mul(term, c);
    term = cx_div(term, n);
    sum = cx_add(sum, term);
  }

  return sum;
}

int main() {
  Complex c1 = cx_create(1, 0);
  cx_print("c1", c1);
  Complex c1_exp = cx_exp(c1, 30);
  cx_print("exp(c1)", c1_exp);

  Complex c2 = cx_create(0, 1);
  cx_print("c2", c2);
  Complex c2_exp = cx_exp(c2, 30);
  cx_print("exp(c2)", c2_exp);

  Complex c3 = cx_create(1, 1);
  cx_print("c3", c3);
  Complex c3_exp = cx_exp(c3, 30);
  cx_print("exp(c3)", c3_exp);
}
