
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
int one() {
  return 1;
}

// [[Rcpp::export]]
int signC(double x) {
  if (x > 0) {
    return 1;
  } else if (x == 0) {
    return 0;
  } else {
    return -1;
  }
}
