#pragma once


/*required funtions with precision (epsilon)*/
double exponent(double x, double epsilon);
double quickExponent(double x, double epsilon);

double sin(double x, double epsilon);
double cos(double x, double epsilon);
double tg(double x, double epsilon);
double ctg(double x, double epsilon);

double ln(double x, double epsilon);

/* functions with built-in precision (epsilon = 2.22045e-16(machine limit))*/
double myExponent(double x);
double myQuickExponent(double x);
double mySin(double x);
double myCos(double x);
double myTg(double x);
double myCtg(double x);
double myLn(double x);

/*solution from Lab01*/
double quickPower(double x, int n);

/*without epsilon, precision depends on quantity of iterations (N)*/
double exponent(double x, int n);