#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "fun_12.h"

double* out_res(double a, double b, double y0, int n, double eps, int* k);
void solver(int n, double a, double b, double x0, double y0, double* res);

void mul(double* arr1, double* arr2, double* arr3, double* arr4, double* res, int len);

void solve(double (*f)(double, double), double x0, double y0, double a, double b, double n, double* arr, double* step, double flag);

void true_solve(double* res, double x0, int n, double h);

void steps_x(double* res, double x0, int n, double h);