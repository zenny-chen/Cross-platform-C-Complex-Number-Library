#if __ANDROID__
#include <jni.h>
#include <syslog.h>
#endif

#include <stdio.h>
#include "cross_complex.h"

int main(void)
{
    _Dcomplex dcomp = CMPLX(1.5, -2.5);
    _Fcomplex fcomp = CMPLXF(-0.5f, 1.25f);
    _Lcomplex lcomp = CMPLXL(100.25L, 300.75L);

    dcomp = cadd(dcomp, CMPLX(1.5, 0.5));
    fcomp = caddf(fcomp, CMPLXF(1.5f, 0.75f));
    lcomp = caddl(lcomp, CMPLXL(1.75L, 10.25L));

    dcomp = csub(dcomp, CMPLX(1.5, 0.5));
    fcomp = csubf(fcomp, CMPLXF(1.5f, 0.75f));
    lcomp = csubl(lcomp, CMPLXL(1.75L, 10.25L));

    dcomp = cmulcc(dcomp, CMPLX(0.2, 10.0));
    fcomp = cmulccf(fcomp, CMPLXF(1.5f, 20.0f));
    lcomp = cmulccl(lcomp, CMPLXL(0.8L, 0.4L));

    dcomp = cmulcr(dcomp, 10.0);
    fcomp = cmulcrf(fcomp, 10.0f);
    lcomp = cmulcrl(lcomp, 10.0L);

    dcomp = cdivcc(dcomp, CMPLX(0.2, 10.0));
    fcomp = cdivccf(fcomp, CMPLXF(1.5f, 20.0f));
    lcomp = cdivccl(lcomp, CMPLXL(0.8L, 0.4L));

    dcomp = cdivcr(dcomp, 10.0);
    fcomp = cdivcrf(fcomp, 10.0f);
    lcomp = cdivcrl(lcomp, 10.0L);

    // The followings are contained in the <complex.h> header...

    // conjugate 
    dcomp = conj(dcomp);
    fcomp = conjf(fcomp);
    lcomp = conjl(lcomp);

    // absolute value
    const double d = cabs(dcomp);
    const float f = cabsf(fcomp);
    const long double ld = cabsl(lcomp);

#if __ANDROID__
    syslog(LOG_INFO, "dcomp = (%f + %fi), d = %f\n", creal(dcomp), cimag(dcomp), d);
    syslog(LOG_INFO, "fcomp = (%f + %fi), f = %f\n", crealf(fcomp), cimagf(fcomp), f);
    syslog(LOG_INFO, "lcomp = (%Lf + %Lfi), ld = %Lf\n", creall(lcomp), cimagl(lcomp), ld);
#else
    printf("dcomp = (%f + %fi), d = %f\n", creal(dcomp), cimag(dcomp), d);
    printf("fcomp = (%f + %fi), f = %f\n", crealf(fcomp), cimagf(fcomp), f);
    printf("lcomp = (%Lf + %Lfi), ld = %Lf\n", creall(lcomp), cimagl(lcomp), ld);
#endif
}
