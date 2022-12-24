#include "odu_12.h"

void mul(double* arr1, double* arr2, double* arr3, double* arr4, double* res, int len) {

    for (int i = 1; i <= len; i++) {
        res[i] = (-1.0 / 21) * arr1[i] + (2.0 / 3) * arr2[i] + (-8.0 / 3) * arr3[i] + (64.0 / 21) * arr4[i];
    }
}

void solve(double (*f)(double, double), double x0, double y0, double a, double b, double n, double* arr, double* step, double flag) {

    double k1, k2, k3, k4, h = (b - a) / n, y = y0, x;


    int count = 1;
    for (int i = 1; i <= n; i++) {

        x = x0 + i * h;
        k1 = f(x, y);
        k2 = f(x + h / 2, y + h * k1 / 2);
        k3 = f(x + h / 2, y + h * k2 / 2);
        k4 = f(x + h, y + h * k3);

        y = y + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);

        if (flag == 1) {
            step[i] = x;
            arr[i] = y;
        }
        if (step[count] == x) {
            arr[count++] = y;
        }

    }

}
void  solver(int n, double a, double b, double x0, double y0, double* res) {

    double* a2 = (double*)malloc((n + 1) * sizeof(double));
    double* a1 = (double*)malloc((n + 1) * sizeof(double));
    double* a3 = (double*)malloc((n + 1) * sizeof(double));
    double* a4 = (double*)malloc((n + 1) * sizeof(double));
    double* step = (double*) malloc((n + 1) * sizeof(double));


    solve(f, x0, y0, a, b, n, a1, step, 1);
    solve(f, x0, y0, a, b, 2 * n, a2, step, 0);
    solve(f, x0, y0, a, b, 4 * n, a3, step, 0);
    solve(f, x0, y0, a, b, 8 * n, a4, step, 0);

    mul(a1, a2, a3, a4, res, n);
    free(a1);
    free(a2);
    free(a3);
    free(a4);
    free(step);
    a1=NULL;
    a2=NULL;
    a3=NULL;
    a4=NULL;
    step=NULL;
}

double* out_res(double a, double b, double y0, int n, double eps, int* k){

    double loss=0;
    while (1){
        double* out = (double*) malloc((n + 1) * sizeof(double));
        double* res2 = (double*) malloc((2*n + 1) * sizeof(double));
        solver(n, a, b, a, y0, out);
        solver(2*n, a, b, a, y0, res2);
        out[0] = y0;
        res2[0] = y0;

        for(int i=0; i<n+1; i++){
            double temp= res2[2*i]-out[i];
            if(temp<0) temp*=-1;
            loss += temp;
        }

        loss/=n;

        if(loss<=eps) {
            free(res2);
            res2=NULL;
            *k = n;
            return out;
        }
        n=n*2;
        free(out);
        free(res2);
        out=NULL;
        res2=NULL;
    }

}

void true_solve(double* res, double x0,  int n, double h){

    double x;
    for (int i = 0; i <= n; i++) {
        x = x0 + i * h;
        res[i]=Y(x);
        }
}


void steps_x(double* res, double x0,  int n, double h) {

    for (int i = 0; i <= n; i++) {
        res[i] = x0 + i * h;
        }
}