#include <Rcpp.h>
#include <math.h>
using namespace Rcpp;

// [[Rcpp::plugins(cpp11)]]

// [[Rcpp::export]]
int one() {
  return 1;
}

// [[Rcpp::export]]
int signC(double x) {
  if (std::isnan(x)) {
    return NA_INTEGER;
  } else if (x > 0) {
    return 1;
  } else if (x == 0) {
    return 0;
  } else {
    return -1;
  }
}
/*** R
sign(-2); signC(-2)
sign(0); signC(0)
sign(2); signC(2)
sign(NA_real_); signC(NA_real_)
*/

// [[Rcpp::export]]
double sumC(NumericVector x, bool narm = true) {
  int n = x.size();
  double total = 0;
  for (int i = 0; i < n; ++i) {
    if (narm & NumericVector::is_na(x[i])) {
      continue;
    } if (!narm & NumericVector::is_na(x[i])) {
      return NA_REAL;
    } else {
      total += x[i];
    }
  }
  return total;
}
/*** R
x <- 1:4
sum(x); sumC(x)
x <- c(1, NA, 3, 4)
sum(x, na.rm = FALSE); sumC(x, narm = FALSE)
sum(x, na.rm = TRUE); sumC(x, narm = TRUE)
*/

// [[Rcpp::export]]
NumericVector pdistC(double x, NumericVector ys) {
  int n = ys.size();
  NumericVector out(n);
  
  for (int i = 0; i < n; ++i) {
    out[i] = sqrt(pow(ys[i] - x, 2.0));
  }
  return out;
}

// [[Rcpp::export]]
NumericVector rowSumsC(NumericMatrix x) {
  int nrow = x.nrow(), ncol = x.ncol();
  NumericVector out(nrow);

  for (int i = 0; i < nrow; i++) {
    double total = 0;
    for (int j = 0; j < ncol; j++) {
      total += x(i, j);
    }
    out[i] = total;
  }
  return out;
}

/*** R
library(microbenchmark)
x <- matrix(sample(100), 10)
microbenchmark(
  rowSums(x),
  rowSumsC(x)
)
*/

// [[Rcpp::export]]
bool allC(LogicalVector x) {
  for (int i = 0; i < x.size(); i++) {
    if (!x[i]) return false;
  }
  return true;
}

/*** R
x <- c(TRUE, FALSE); allC(x)
y <- c(TRUE, TRUE); allC(y)
*/

// [[Rcpp::export]]
NumericVector cumprodC(NumericVector x) {
  int n = x.size();
  NumericVector out(n);
  out[0] = x[0];
  for (int i = 1; i < n; i++) {
    out[i] = out[i - 1] * x[i];
  }
  return out;
}
/*** R
cumprod(1:5)
cumprodC(1:5)
*/

// [[Rcpp::export]]
NumericVector diffC(NumericVector x, int lag = 1) {
  int n = x.size();
  NumericVector out(n - lag);
  for (int i = 0; i < out.size(); i++) {
    out[i] = x[i + lag] - x[i];
  }
  return out;
}
/*** R
x <- c(2, 4, 1, 4, 3)
diff(x); diffC(x)
diff(x, lag = 2); diffC(x, lag = 2)
*/

// [[Rcpp::export]]
NumericVector rangeC(NumericVector x) {
  int n = x.size();
  NumericVector out(2);
  out[0] = x[0];
  out[1] = x[0];
  for (int i = 0; i < n; i++) {
    if (x[i] < out[0]) out[0] = x[i];
    if (x[i] > out[1]) out[1] = x[i];
  }
  return out;
}
/*** R
range(x); rangeC(x)
*/
