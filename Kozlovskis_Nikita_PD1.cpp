#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <chrono> //shet4ik

int main () {
 try { 
  std::ifstream file("ints_10M.txt");
  if (!file) {
			throw std::runtime_error("Can't open file");
		}
  std::string line;
  std::chrono::time_point<std::chrono::steady_clock> begin_time = std::chrono::steady_clock::now(); 
  int ans = 0;
  int lowest_value;
  bool nachalo=false;
   
  while(!file.eof()){
    int read_int;
	  file >> read_int;
    int counter = 1; 
    if(!nachalo) lowest_value=read_int;


    if (lowest_value>read_int) lowest_value=read_int;
    if(ans<read_int-lowest_value) ans=read_int-lowest_value; 
    nachalo=true;
  }

   std::cout << "answer is: "<< ans << std::endl;
   std::chrono::time_point<std::chrono::steady_clock> end_time = std::chrono::steady_clock::now();
   std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - begin_time).count() << "ms" << std::endl;
  return 0;
 }
  catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		exit(1);
	}
}