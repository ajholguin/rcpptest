/* 
 * To refresh & improve my c++ skills, I'm going to work through some basic examples.
 */

#include <Rcpp.h>
using namespace std;

// [[Rcpp::plugins(cpp11)]]

// for simplicity, just treat this like a "main" function, but print output to R
// [[Rcpp::export]]
int main() {
  Rcpp::Rcout << "hello\n";
  return 0;
}
/*** R
status <- main()
*/
