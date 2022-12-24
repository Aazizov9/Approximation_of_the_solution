#include "fun_12.h"
//0 1 2 1000 0.0000001
//double f(double x, double y) {
//    return -40*(y-1)*(y-1)*sin(100*x);
//}
//double Y(double x) {
//    return  (2*cos(100*x)-12)/(2*cos(100*x)-7);
//}
//0 1 0.3 1000 0.0000001

double f(double x, double y) {
    return y/8-sin(48*x)/y;
}
double Y(double x) {
    return sqrt((1781.85*exp(x/4)+8*(sin(48*x)+192*cos(48*x)))/36865);
}

