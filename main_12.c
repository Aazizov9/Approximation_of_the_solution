#include "odu_12.h"
#include "d_graph.h"
#pragma warning(disable:4996)


int main() {
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");

    int n;
    double  a, b, y0, eps;

	if (input == NULL)
	{
		printf("Error\n");
		return NULL;
	}
	else {
        fscanf(input, "%lf %lf %lf %d %lf", &a, &b, &y0, &n, &eps);


        int k;
        double* out = out_res(a, b , y0, n, eps, &k );

        double* out_true = (double*) malloc((k + 1) * sizeof(double));
        double* steps_ = (double*) malloc((k + 1) * sizeof(double));

        double xi, h=(b-a)/k;
        int z = k/n;

        true_solve(out_true, a, k, h);
        steps_x(steps_, a, k, h);

        fprintf(output, "%d\n", n);
        for (int i = 0 ; i <= n; i++){

            fprintf(output, "%lf\n", out[z*i]);
        }


        display_graph_1(out, steps_, k);
        display_graph_2(out, out_true, steps_, k);

        free(out);
        free(out_true);
        free(steps_);
        out=NULL;
        out_true=NULL;
        steps_=NULL;
	}

    return 0;
}
