//
//  main.cpp
//  2016.12.31.23.17.TheBunnySociety
//
//  Created by Thai Cao Ngoc on 31/12/16.
//  Copyright © 2016 Thai Cao Ngoc. All rights reserved.
//

#include <iostream>
#include "bunnyclass.hpp"


int main()
{
    srand((unsigned int)time(nullptr));
    
    std::ifstream file_read ("namelist.txt");
    std::ofstream file_write ("log.txt");
    
    if (!file_read.is_open()) {
        std::cout << "Could not open the file!" << std::endl;
        return 0;
    }
    
    if (!file_write.is_open()) {
        std::cout << "Could not open the file!" << std::endl;
        return 0;
    }
    
    std::vector<std::string> namelist;
    
    std::string name;
    
    while ( file_read >> name ) {
        namelist.push_back(name);
    }
    
    if (!file_read.eof()) {
        std::cout << "Bad input.... Exiting" << std::endl;
        return 0;
    }
    
    int year = 1;
    
    bunnyClass bunnySociety (namelist);
    
    //std::cout << "Year 0, a bunny society has been creates!" << std::endl << std::endl;
    file_write << "Year 0, a bunny society has been creates!" << std::endl << std::endl;
    
    
    bunnySociety.printBunnies(file_write);
    
    while (bunnySociety.getImmutantNumber() > 0) {
        //std::cout << "Press enter key to continue...";
        //getchar();
        //std::cout << std::endl << std::endl;
        file_write << std::endl << std::endl;;
        
        //std::cout << "Year " << year << "...." << std::endl << std::endl;
        file_write << "Year " << year << "...." << std::endl << std::endl;
        
        bunnySociety.ageOneYear();
        bunnySociety.bunnyBorn(namelist, file_write);
        bunnySociety.eraseDie(file_write);
        bunnySociety.turnVampire(file_write);
        bunnySociety.killHalf(file_write);
        
        bunnySociety.printBunnies(file_write);
        
        ++year;
    }
    
    //std::cout << "All bunnies turn into vampires!" << std::endl << "The bunny society has come to an end!" << std::endl;
    file_write << "All bunnies had turned into vampires!" << std::endl << "The bunny society has come to an end!";
    
    std::cout << "All events have been recorded in file: log.txt" << std::endl;
    
    return 0;
}
