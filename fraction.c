#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "fraction.h"

Fraction* Fraction_Create()
{
    Fraction *f = malloc(sizeof(Fraction));

    if(f != NULL)
    {
        f->num = 0;
        f->den = 1;
        f->value = 0;
    }

    return f;
}

void Fraction_Free(Fraction *f)
{
    if(f != NULL)
        free(f);
}

void Fraction_SetNum(Fraction *f, float value)
{
    if((int)value != value)
    {
        Fraction f1;
        DecimalToFraction(value, &f1);
        *f = Fraction_Div(&f1, &FRACT(f->den));
    }
    else
    {
        f->num = (int)value;
        f->value = (float)f->num / (float)f->den;
    }
}

int Fraction_GetNum(Fraction *f)
{
    return f->num;
}

void Fraction_SetDen(Fraction *f, float value)
{
    if((int)value != value)
    {
        Fraction f1;
        DecimalToFraction(value, &f1);
        *f = Fraction_Div(&FRACT(f->num), &f1);
    }
    else
    {
        f->den = (int)value;
        f->value = (float)f->num / (float)f->den;
    }
}

int Fraction_GetDen(Fraction *f)
{
    return f->den;
}

void Fraction_SetValue(Fraction* f, float value)
{
    DecimalToFraction(value, f);
}

float Fraction_GetValue(Fraction *f)
{
    return f->value;
}

Fraction Fraction_Sum(Fraction *f1, Fraction *f2)
{
    Fraction result;

    result.num = (f1->num * f2->den) + (f2->num * f1->den);
    result.den = (f1->den * f2->den);
    result.value = (float)result.num / (float)result.den;

    Fraction_Reduce(&result);

    return result;
}

void Fraction_SumIn(Fraction *f1, Fraction *f2, Fraction *result)
{
    result->num = (f1->num * f2->den) + (f2->num * f1->den);
    result->den = (f1->den * f2->den);
    result->value = (float)result->num / (float)result->den;

    Fraction_Reduce(result);
}

Fraction Fraction_Sub(Fraction *f1, Fraction *f2)
{
    Fraction result;

    result.num = (f1->num * f2->den) - (f2->num * f1->den);
    result.den = (f1->den * f2->den);
    result.value = (float)result.num / (float)result.den;

    Fraction_Reduce(&result);

    return result;
}

void Fraction_SubIn(Fraction *f1, Fraction *f2, Fraction *result)
{
    result->num = (f1->num * f2->den) - (f2->num * f1->den);
    result->den = (f1->den * f2->den);
    result->value = (float)result->num / (float)result->den;

    Fraction_Reduce(result);
}

Fraction Fraction_Mul(Fraction *f1, Fraction *f2)
{
    Fraction result;

    result.num = f1->num * f2->num;
    result.den = f1->den * f2->den;
    result.value = (float)result.num / (float)result.den;

    Fraction_Reduce(&result);

    return result;
}

void Fraction_MulIn(Fraction *f1, Fraction *f2, Fraction *result)
{
    result->num = f1->num * f2->num;
    result->den = f1->den * f2->den;
    result->value = (float)result->num / (float)result->den;

    Fraction_Reduce(result);
}

Fraction Fraction_Div(Fraction *f1, Fraction *f2)
{
    Fraction result;

    result.num = f1->num * f2->den;
    result.den = f1->den * f2->num;
    result.value = (float)result.num / (float)result.den;

    Fraction_Reduce(&result);

    return result;
}

void Fraction_DivIn(Fraction *f1, Fraction *f2, Fraction *result)
{
    result->num = f1->num * f2->den;
    result->den = f1->den * f2->num;
    result->value = (float)result->num / (float)result->den;

    Fraction_Reduce(result);
}

Fraction Fraction_Pow(Fraction *f, int p)
{
    Fraction result;
    result.num = pow(f->num, p);
    result.den = pow(f->den, p);
    result.value = (float)result.num / (float)result.den;

    Fraction_Reduce(&result);

    return result;
}

void Fraction_PowIn(Fraction *f, int p, Fraction *result)
{
    result->num = pow(f->num, p);
    result->den = pow(f->den, p);
    result->value = (float)result->num / (float)result->den;

    Fraction_Reduce(result);
}

Fraction Fraction_Sqrt(Fraction *f)
{
    Fraction result, f1, f2;

    DecimalToFraction(sqrt(f->num), &f1);
    DecimalToFraction(sqrt(f->den), &f2);

    Fraction_DivIn(&f1, &f2, &result);

    return result;
}

void Fraction_SqrtIn(Fraction *f, Fraction *result)
{
    Fraction f1, f2;

    DecimalToFraction(sqrt(f->num), &f2);
    DecimalToFraction(sqrt(f->den), &f2);

    Fraction_DivIn(&f1, &f2, result);
}

void Fraction_Reduce(Fraction *f)
{
    if(f->num == 0)
    {
        f->den = 1;
    }
    else
    {
        int d = PGCD(f->num, f->den);

        if(d != 0)
        {
            f->num /= d;
            f->den /= d;
        }
    }
}

void DecimalToFraction(float decimal, Fraction *fraction)
{
    if(decimal == 0)
    {
        fraction->num = 0;
        fraction->den = 1;
        fraction->value = 0;
        return;
    }
    long int d = 1;

    while(decimal - (int)decimal != 0)
    {
        decimal *= 10;
        d *= 10;
    }

    fraction->num = decimal;
    fraction->den = d;

    Fraction_Reduce(fraction);
}

int Fraction_IsInteger(Fraction *f)
{
    return fmod(Fraction_GetValue(f), 1.0) == 0;
}

void Fraction_ToggleSign(Fraction *fraction)
{
    fraction->num *= -1;
    fraction->value *= -1;
}

int PGCD(int a,int b)
{
    if(b == 0)
        return a;
    return PGCD(b, a % b);

}
