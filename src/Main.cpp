#include <iostream>
#include"cryptography/cryptography.h"
#include "data_structures/_data_structure.h"
#include "tests/_test.h"
#include "string/_string.h"
#include <map>
#include <vector>
#include<string>
#include <thread>
#include <chrono>

int main() {
    
    std::string random_password = rndm_alphanum((size_t)1024);
    std::cout << "To guess: " << random_password << std::endl;
    
    auto start = std::chrono::high_resolution_clock::now();
    report rreport = simple_brute("A",1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "The password is: "<<rreport.key<<" Comparisions done: " << rreport.comparisions <<
        " and is success?: " << rreport.solved <<" and it took time of this: "
        << duration.count() << " milliseconds." << std::endl;
    
    auto imstart = std::chrono::high_resolution_clock::now();
    report newreport = improved_brute(random_password, random_password.length());
    auto imend = std::chrono::high_resolution_clock::now();
    auto imduration = std::chrono::duration_cast<std::chrono::milliseconds>(imend - imstart);
    std::cout << "\nComparisions done: " << newreport.comparisions <<
        " and is success?: " << newreport.solved << " and it took time of this: "
        << imduration.count() << " milliseconds." << std::endl;
    
    auto logical_start = std::chrono::high_resolution_clock::now();
    report logical_report = logical_brute(random_password);
    auto logical_end = std::chrono::high_resolution_clock::now();
    auto logical_duration = std::chrono::duration_cast<std::chrono::milliseconds>(logical_end - logical_start);
    std::cout << "The password is: " << logical_report.key << "\nComparisions done: " << logical_report.comparisions <<
        " and is success?: " << logical_report.solved << " and it took time of this: "
        << logical_duration.count() << " milliseconds." << std::endl;
    
    std::cin.get();

    return 0;
}