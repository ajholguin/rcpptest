/* 
 * To refresh & improve my C++ skills, I'm going to work through some basic examples.
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
  Rcpp::StringVector sv_name = "??";
  Rcpp::Rcout << "Enter your name\n";
  sv_name = readline();
  
  // back to standard C++ and print
  std::string name = Rcpp::as<std::string>(sv_name);
  Rcpp::Rcout << "Hello " << name << "\n";
  
  return 0;
}
/*** R
status <- main()
*/
