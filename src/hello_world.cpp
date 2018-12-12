/* 
 * To refresh & improve my c++ skills, I'm going to work through some basic examples.
 */

#include <Rcpp.h>
#include <string>
using namespace std;

// [[Rcpp::plugins(cpp11)]]

// for simplicity, just treat this like a "main" function, but print output to R
// [[Rcpp::export]]
int main() {
  
  // use R function readline to get input from the R console
  Rcpp::Environment base = Rcpp::Environment("package:base");
  Rcpp::Function readline = base["readline"];
  
  // get the value
  Rcpp::StringVector rname = "??";
  Rcpp::Rcout << "Enter your name\n";
  rname = readline();
  
  // back to standard c++ and print
  std::string name = Rcpp::as<std::string>(rname);
  Rcpp::Rcout << "Hello " << name << "\n";
  
  return 0;
}
/*** R
status <- main()
*/
