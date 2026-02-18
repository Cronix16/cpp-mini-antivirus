#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>

 int main(int argc, char* argv[]) {
   if(argc<2) {
     std::cerr <<"Error: You must provide a file to scan."<< std::endl;
     std::cerr <<"Try: ./scanner <filename>"<< std::endl;
     return 1;
   }
   std::ifstream file(argv[1]);
   std::cout <<"Bitdefender Mini-Scanner started" << std::endl;
   if(!file.is_open()) {
     std::cerr <<"Error: Could not open file!" << std::endl;
     return 1;
   }
   std::vector<char> memoryArray;
   char currentByte;
   while(file.get(currentByte)) {
     memoryArray.push_back(currentByte);
   }
   file.close();
   std::cout <<"Successfully loaded "<<memoryArray.size()<< std::endl;
   std::cout <<"Scanning file for malicious signature"<< std::endl;
   bool isInfected = false;
   for(int i=0;i<memoryArray.size()-3;i++) {
     if(tolower(memoryArray[i]) == 'e' && tolower( memoryArray[i+1]) == 'v' && tolower(memoryArray[i+2]) == 'i' && tolower(memoryArray[i+3]) == 'l') {
       std::cout <<"MALWARE DETECTED at byte offset "<< i << std::endl;
       std::cout <<"Action: Quarantine recommended.\n"<< std::endl;
       isInfected = true;
       break;
     }
   }
   if(!isInfected) {
   std::cout <<"Scan complete. File is clean."<< std::endl; 
   }
   return 0;
 }
