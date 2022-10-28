#ifndef CROSS_PLATFORM_COMPLEX_LIB
#define CROSS_PLATFORM_COMPLEX_LIB

#include <complex.h>

#ifdef _MSC_VER
// MSVC compiler：
#define CMPLX       _DCOMPLEX_
#define CMPLXF      _FCOMPLEX_
#define CMPLXL      _LCOMPLEX_

// Complex Add (a complex with a complex)
static inline _Dcomplex caddcc(_Dcomplex a, _Dcomplex b)
{
    return CMPLX(creal(a) + creal(b),
        cimag(a) + cimag(b));
}

static inline _Fcomplex caddccf(_Fcomplex a, _Fcomplex b)
{
    return CMPLXF(crealf(a) + crealf(b),
        cimagf(a) + cimagf(b));
}

static inline _Lcomplex caddccl(_Lcomplex a, _Lcomplex b)
{
    return CMPLXL(creall(a) + creall(b),
        cimagl(a) + cimagl(b));
}

// Complex Add (a complex with a real floating-point number)
static inline _Dcomplex caddcr(_Dcomplex a, double b)
{
    return CMPLX(creal(a) + b, cimag(a));
}

static inline _Fcomplex caddcrf(_Fcomplex a, float b)
{
    return CMPLXF(crealf(a) + b, cimagf(a));
}

static inline _Lcomplex caddcrl(_Lcomplex a, long double b)
{
    return CMPLXL(creall(a) + b, cimagl(a));
}

// Complex Subtraction (a complex with a complex)
static inline _Dcomplex csubcc(_Dcomplex a, _Dcomplex b)
{
    return CMPLX(creal(a) - creal(b),
        cimag(a) - cimag(b));
}

static inline _Fcomplex csubccf(_Fcomplex a, _Fcomplex b)
{
    return CMPLXF(crealf(a) - crealf(b),
        cimagf(a) - cimagf(b));
}

static inline _Lcomplex csubccl(_Lcomplex a, _Lcomplex b)
{
    return CMPLXL(creall(a) - creall(b),
        cimagl(a) - cimagl(b));
}

// Complex Subtraction (a complex with a real floating-point number)
static inline _Dcomplex csubcr(_Dcomplex a, double b)
{
    return CMPLX(creal(a) - b, cimag(a));
}

static inline _Fcomplex csubcrf(_Fcomplex a, float b)
{
    return CMPLXF(crealf(a) - b, cimagf(a));
}

static inline _Lcomplex csubcrl(_Lcomplex a, long double b)
{
    return CMPLXL(creall(a) - b, cimagl(a));
}

// Complex Multiplication (a complex with a complex)
static inline _Dcomplex cmulcc(_Dcomplex a, _Dcomplex b)
{
    return _Cmulcc(a, b);
}

static inline _Fcomplex cmulccf(_Fcomplex a, _Fcomplex b)
{
    return _FCmulcc(a, b);
}

static inline _Lcomplex cmulccl(_Lcomplex a, _Lcomplex b)
{
    return _LCmulcc(a, b);
}

// Complex Multiplication (a complex with a real floating-point number)
static inline _Dcomplex cmulcr(_Dcomplex a, double b)
{
    return _Cmulcr(a, b);
}

static inline _Fcomplex cmulcrf(_Fcomplex a, float b)
{
    return _FCmulcr(a, b);
}

static inline _Lcomplex cmulcrl(_Lcomplex a, long double b)
{
    return _LCmulcr(a, b);
}

// Complex Division (a complex with a complex)
static inline _Dcomplex cdivcc(_Dcomplex a, _Dcomplex b)
{
    const double denominator = creal(b) * creal(b) + cimag(b) * cimag(b);

    double real = creal(a) * creal(b) + cimag(a) * cimag(b);
    real /= denominator;

    double imag = cimag(a) * creal(b) - creal(a) * cimag(b);
    imag /= denominator;

    return CMPLX(real, imag);
}

static inline _Fcomplex cdivccf(_Fcomplex a, _Fcomplex b)
{
    const float denominator = crealf(b) * crealf(b) + cimagf(b) * cimagf(b);

    float real = crealf(a) * crealf(b) + cimagf(a) * cimagf(b);
    real /= denominator;

    float imag = cimagf(a) * crealf(b) - crealf(a) * cimagf(b);
    imag /= denominator;

    return CMPLXF(real, imag);
}

static inline _Lcomplex cdivccl(_Lcomplex a, _Lcomplex b)
{
    const long double denominator = creall(b) * creall(b) + cimagl(b) * cimagl(b);

    long double real = creall(a) * creall(b) + cimagl(a) * cimagl(b);
    real /= denominator;

    long double imag = cimagl(a) * creall(b) - creall(a) * cimagl(b);
    imag /= denominator;

    return CMPLXL(real, imag);
}

// Complex Division (a complex with a real floating-point number)
static inline _Dcomplex cdivcr(_Dcomplex a, double b)
{
    return _Cmulcr(a, 1.0 / b);
}

static inline _Fcomplex cdivcrf(_Fcomplex a, float b)
{
    return _FCmulcr(a, 1.0f / b);
}

static inline _Lcomplex cdivcrl(_Lcomplex a, long double b)
{
    return _LCmulcr(a, 1.0L / b);
}

#else
// Other C compilers that support C11 <complex.h>
typedef double complex          _Dcomplex;
typedef float complex           _Fcomplex;
typedef long double complex     _Lcomplex;

// Complex Add (a complex with a complex)
static inline _Dcomplex caddcc(_Dcomplex a, _Dcomplex b)
{
    return a + b;
}

static inline _Fcomplex caddccf(_Fcomplex a, _Fcomplex b)
{
    return a + b;
}

static inline _Lcomplex caddccl(_Lcomplex a, _Lcomplex b)
{
    return a + b;
}

// Complex Add (a complex with a real floating-point number)
static inline _Dcomplex caddcr(_Dcomplex a, double b)
{
    return a + b;
}

static inline _Fcomplex caddcrf(_Fcomplex a, float b)
{
    return a + b;
}

static inline _Lcomplex caddcrl(_Lcomplex a, long double b)
{
    return a + b;
}

// Complex Subtraction (a complex with a complex)
static inline _Dcomplex csubcc(_Dcomplex a, _Dcomplex b)
{
    return a - b;
}

static inline _Fcomplex csubccf(_Fcomplex a, _Fcomplex b)
{
    return a - b;
}

static inline _Lcomplex csubccl(_Lcomplex a, _Lcomplex b)
{
    return a - b;
}

// Complex Subtraction (a complex with a real floating-point number)
static inline _Dcomplex csubcr(_Dcomplex a, double b)
{
    return a - b;
}

static inline _Fcomplex csubcrf(_Fcomplex a, float b)
{
    return a - b;
}

static inline _Lcomplex csubcrl(_Lcomplex a, long double b)
{
    return a - b;
}

// Complex Multiplication (a complex with a complex)
static inline _Dcomplex cmulcc(_Dcomplex a, _Dcomplex b)
{
    return a * b;
}

static inline _Fcomplex cmulccf(_Fcomplex a, _Fcomplex b)
{
    return a * b;
}

static inline _Lcomplex cmulccl(_Lcomplex a, _Lcomplex b)
{
    return a * b;
}

// Complex Multiplication (a complex with a real floating-point number)
static inline _Dcomplex cmulcr(_Dcomplex a, double b)
{
    return a * b;
}

static inline _Fcomplex cmulcrf(_Fcomplex a, float b)
{
    return a * b;
}

static inline _Lcomplex cmulcrl(_Lcomplex a, long double b)
{
    return a * b;
}

// Complex Division (a complex with a complex)
static inline _Dcomplex cdivcc(_Dcomplex a, _Dcomplex b)
{
    return a / b;
}

static inline _Fcomplex cdivccf(_Fcomplex a, _Fcomplex b)
{
    return a / b;
}

static inline _Lcomplex cdivccl(_Lcomplex a, _Lcomplex b)
{
    return a / b;
}

// Complex Division (a complex with a real floating-point number)
static inline _Dcomplex cdivcr(_Dcomplex a, double b)
{
    return a / b;
}

static inline _Fcomplex cdivcrf(_Fcomplex a, float b)
{
    return a / b;
}

static inline _Lcomplex cdivcrl(_Lcomplex a, long double b)
{
    return a / b;
}

#endif // _MSC_VER

#endif
