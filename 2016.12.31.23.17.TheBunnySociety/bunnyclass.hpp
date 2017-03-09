//
//  bunnyclass.hpp
//  2016.12.31.23.17.TheBunnySociety
//
//  Created by Thai Cao Ngoc on 31/12/16.
//  Copyright © 2016 Thai Cao Ngoc. All rights reserved.
//

#ifndef bunnyclass_hpp
#define bunnyclass_hpp

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>

enum bunnySex { B_MALE, B_FEMALE};
enum bunnyColor { B_WHITE, B_BROWN, B_BLACK, B_SPOTTED };


/** bunnyNode class store infomation of each individual bunny
 */
class bunnyNode
{
public:
    bunnyNode (std::vector<std::string>& inputNameList);
    bunnyNode (std::vector<std::string>& inputNameList, bunnyColor inputColor);
    std::string getName();
    int getAge();
    void setAge (int inputAge);
    bunnySex getSex();
    bunnyColor getColor();
    void setColor ();
    void serColor (bunnyColor inputColor);
    bool getVampire();
    void setVampire (bool inputVampire);
    
    
private:
    std::string _name;
    int _age;
    bunnySex _sex;
    bunnyColor _color;
    bool _is_Vampire;
};



/** bunnyClass class store all bunnies
    I create a vector to hold all pointers to every individual bunny
 */
class bunnyClass
{
public:
    bunnyClass (std::vector<std::string>& inputNameList);
    ~bunnyClass();
    void printBunnies(std::ofstream& file_write);
    
    void ageOneYear();
    
    bool is_immutant_male_adult();
    void getFemaleAdult();
    void bunnyBorn(std::vector<std::string>& inputNameList, std::ofstream& file_write);
    
    void eraseDie(std::ofstream& file_write);
    
    int getMutantNumber();
    int getImmutantNumber();
    int getAdultMutantNumber();
    void turnVampire (std::ofstream& file_write);
    
    void killHalf(std::ofstream& file_write);
    
    
private:
    std::vector<bunnyNode*> p_bunnyVec;
    std::vector<bunnyNode*> p_femaleAdult;
    
    void ageSort();
};



#endif /* bunnyclass_hpp */
