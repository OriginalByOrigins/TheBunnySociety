
//
//  bunnyclass.cpp
//  2016.12.31.23.17.TheBunnySociety
//
//  Created by Thai Cao Ngoc on 31/12/16.
//  Copyright © 2016 Thai Cao Ngoc. All rights reserved.
//

#include "bunnyclass.hpp"


/** Genarate a random number below range
    @param range is the range of random number
 */
int random (int range)
{
    return rand() % range;
}



/** Constructure the first bunny genetarion
    @param inputNameList is a vector contains a list of name
    These first generation do not have mother , so they have random color
 */
bunnyNode::bunnyNode (std::vector<std::string>& inputNameList)
: _age(0)
{
    _name = inputNameList[ random ((int)inputNameList.size()) ];
    
    _sex = random(100) < 50 ? B_MALE : B_FEMALE;
    
    setColor();
    
    _is_Vampire = random(100) < 2 ? true : false;
}




/** Construction later bunny generations
    @param inputNameList is a vector contains a list of name
    @param inputColor is the color of their mother
 */
bunnyNode::bunnyNode (std::vector<std::string>& inputNameList, bunnyColor inputColor)
: _age(0), _color(inputColor)
{
    _name = inputNameList[ random ((int)inputNameList.size()) ];
    
    _sex = random(100) < 50 ? B_MALE : B_FEMALE;
    
    _is_Vampire = random(100) < 2 ? true : false;
}




/** Function get name of a bunny
 */
std::string bunnyNode::getName()
{
    return _name;
}



/*
void bunnyNode::setName (std::string inputName)
{
    _name = inputName;
}
*/



/** Function get age of a bunny
 */
int bunnyNode::getAge()
{
    return _age;
}



/** Function set age for a bunny
    @param inputAge is the new age
    Use this function to every a bunny age 1 year
 */
void bunnyNode::setAge (int inputAge)
{
    _age = inputAge;
}



/** Function get sex of a bunny
 */
bunnySex bunnyNode::getSex()
{
    return _sex;
}



/*
void bunnyNode::setSex (bunnySex inputSex)
{
    _sex = inputSex;
}
*/



/** Function get color of a bunny
 */
bunnyColor bunnyNode::getColor()
{
    return _color;
}



/** Set random color for a bunny
    Use this function to set color for the 1st bunny generation
        when they do not have mother, so their colors are set randomly
 */
void bunnyNode::setColor()
{
    int colorGenerate = random(100);
    
    if (colorGenerate < 25) {
        _color = B_WHITE;
    }
    else if (colorGenerate < 50) {
        _color = B_BROWN;
    }
    else if (colorGenerate < 75) {
        _color = B_BLACK;
    }
    else _color = B_SPOTTED;
}



/** Set color for a bunny based on their mother's color
    @param inputColor is the color of their mother
 */
void bunnyNode::serColor (bunnyColor inputColor)
{
    _color = inputColor;
}



/** Check if a bunny if mutant or immutant
    @return true if the bunny is radioactive_mutant_vampire
    @return false if the bunny is NOT radioactive_mutant_vampire
 */
bool bunnyNode::getVampire()
{
    return _is_Vampire;
}



/** Set the mutant status of a bunny
    Use this function if a bunny is turned by another mutant bunny
 */
void bunnyNode::setVampire (bool inputVampire)
{
    _is_Vampire = inputVampire;
}







/** Constructure initialize 5 bunny of their 1st generation
    @param inputNameList is a vector contains a list of name
 */
bunnyClass::bunnyClass (std::vector<std::string>& inputNameList)
{
    for (int i = 0; i < 5; i++) {
        p_bunnyVec.push_back(new bunnyNode(inputNameList));
    }
}



/** Destructure free allocated memories
    We need this function  because we allocation "new bunnyNode" in bunnyVec
 */
bunnyClass::~bunnyClass()
{
    for (auto p_bunny : p_bunnyVec)
        delete p_bunny;
}



/** Perform sort all bunnies by age
 */
void bunnyClass::ageSort()
{
    int smallest = 0;
    for (int i = 0, size = (int)p_bunnyVec.size(); i < size; ++i) {
        
        smallest = i;
        
        for (int j = i + 1; j < size; ++j) {
            if (p_bunnyVec[ j ]->getAge() < p_bunnyVec[ smallest ]->getAge()) {
                smallest = j;
            }
        }
        
        if (smallest != i) {
            bunnyNode* temp = p_bunnyVec[ i ];
            p_bunnyVec[ i ] = p_bunnyVec[ smallest ];
            p_bunnyVec[ smallest ]= temp;
        }
    }
}





/** print all bunnies in the society
 */
void bunnyClass::printBunnies(std::ofstream& file_write)
{
    ageSort();
    
    for (auto p_bunny : p_bunnyVec) {
        //std::cout << p_bunny->getName() << '\t' << p_bunny->getAge() << '\t';
        file_write << p_bunny->getName() << '\t' << p_bunny->getAge() << '\t';
        
        if (p_bunny->getSex() == B_MALE) {
            //std::cout << "M" << '\t';
            file_write << "M" << '\t';
        }
        else { //std::cout << "F" << '\t';
            file_write << "F" << '\t';
        }
        
        if (p_bunny->getColor() == B_WHITE) {
            //std::cout << "White" << '\t';
            file_write << "White" << '\t';
        }
        else if (p_bunny->getColor() == B_BROWN) {
            //std::cout << "Brown" << '\t';
            file_write << "Brown" << '\t';
        }
        else if (p_bunny->getColor() == B_BLACK) {
            //std::cout << "Black" << '\t';
            file_write << "Black" << '\t';
        }
        else {//std::cout << "Spotted" << '\t';
            file_write << "Spotted" << '\t';
        }
        
        if (p_bunny->getVampire()) {
            //std::cout << "Mutant" << '\t';
            file_write << "Mutant" << '\t';
        }
        else {//std::cout << "Immutant" << '\t';
            file_write << "Immutant" << '\t';
        }
        
        //std::cout << std::endl;
        file_write << std::endl;
    }
    
    //std::cout << std::endl;
    //std::cout << "The society has " << p_bunnyVec.size() << " bunnies" << std::endl;
    file_write << std::endl;
    file_write << "The society has " << p_bunnyVec.size() << " bunnies" << std::endl;
}



/** Get every bunny age 1 year
 Call this method first each turn
 */
void bunnyClass::ageOneYear()
{
    for (auto p_bunny : p_bunnyVec)
        p_bunny->setAge(p_bunny->getAge() + 1);
}




/** Check if there are immutant Male adult
 @return true if ther is at least 1 immutant male adult
 */
bool bunnyClass::is_immutant_male_adult()
{
    for (auto p_bunny : p_bunnyVec) {
        if (p_bunny->getAge() > 1 && p_bunny->getSex() == B_MALE && !p_bunny->getVampire()) {
            return true;
        }
    }
    return false;
    
}



/** Get infomation of all immutant female adult
 Store those infomation into a vector for futher use
 */
void bunnyClass::getFemaleAdult()
{
    if (is_immutant_male_adult()) {
        for (auto p_bunny : p_bunnyVec) {
            if (p_bunny->getAge() > 1 && p_bunny->getSex() == B_FEMALE && !p_bunny->getVampire()) {
                p_femaleAdult.push_back(p_bunny);
            }
        }
    }
}



/** Giving birth to new bunnies
    First, read mother bunnies one by one from p_femaleAdult vector
    For each mother, construc a new baby bunny with the same color as their mother
    Print all birth events
    After all baby bunnies are born, clear the female Aldut vector.
 */
void bunnyClass::bunnyBorn(std::vector<std::string>& inputNameList, std::ofstream& file_write)
{
    getFemaleAdult();
    for ( auto mother : p_femaleAdult) {
        p_bunnyVec.push_back (new bunnyNode (inputNameList, mother->getColor()) );
        
        // Print birth event
        // Print the new baby, mean the last bunny in the vector
        if (p_bunnyVec[ (int)p_bunnyVec.size() - 1 ]->getVampire()) {
            //std::cout << "Radioactive Mutant Vampire Bunny " <<
            //p_bunnyVec[ (int)p_bunnyVec.size() - 1 ]->getName() << " was born!" << std::endl;
            file_write << "Radioactive Mutant Vampire Bunny " <<
                p_bunnyVec[ (int)p_bunnyVec.size() - 1 ]->getName() << " was born!" << std::endl;
        }
        else { //std::cout << "Bunny " <<
            //p_bunnyVec[ (int)p_bunnyVec.size() - 1 ]->getName() << " was born!" << std::endl;
            file_write << "Bunny " <<
            p_bunnyVec[ (int)p_bunnyVec.size() - 1 ]->getName() << " was born!" << std::endl;
        }
    }
    
    p_femaleAdult.clear();
    
    //std::cout << std::endl;
    file_write << std::endl;
}





/** Erase bunnies that dis out of vector
    Immutant bunnies die if age reach 10 ( age > 9 )
    Mutant vampire bunnies die if age reach 50 ( age > 49 )
    Print all die events
    Free allocated memory asoociated to these bunnies
 */
void bunnyClass::eraseDie(std::ofstream& file_write)
{
    for (int i = 0, size = (int)p_bunnyVec.size(); i < size; ++i) {
        if (p_bunnyVec[ i ]->getAge() > 9 && !p_bunnyVec[ i ]->getVampire()) {
            //std::cout << "Bunny " << p_bunnyVec[ i ]->getName() << " died!" << std::endl;
            file_write << "Bunny " << p_bunnyVec[ i ]->getName() << " died!" << std::endl;
            delete p_bunnyVec[ i ];
            p_bunnyVec.erase(p_bunnyVec.begin() + i);
            --i;
        }
        else if (p_bunnyVec[ i ]->getAge() > 49 && !p_bunnyVec[ i ]->getVampire()) {
            //std::cout << "Radioactive Mutant Vampire Bunny " << p_bunnyVec[ i ]->getName() << " died!" << std::endl;
            file_write <<  "Radioactive Mutant Vampire Bunny " << p_bunnyVec[ i ]->getName() << " died!" << std::endl;
            delete p_bunnyVec[ i ];
            p_bunnyVec.erase(p_bunnyVec.begin() + i);
            --i;
        }
    }
    
    //std::cout << std::endl;
    file_write << std::endl;
}





/** Get the number of mutant vampire bunny
 */
int bunnyClass::getMutantNumber()
{
    int mutantNumber = 0;
    
    for (auto p_bunny : p_bunnyVec) {
        if (p_bunny->getVampire()) {
            ++mutantNumber;
        }
    }
    
    return mutantNumber;
}



/** Get the number of immutant bunny
 */
int bunnyClass::getImmutantNumber()
{
    return (int)p_bunnyVec.size() - getMutantNumber();
}


int bunnyClass::getAdultMutantNumber()
{
    int mutantNumber = 0;
    
    for (auto p_bunny : p_bunnyVec) {
        if (p_bunny->getVampire() && p_bunny->getAge() > 0) {
            ++mutantNumber;
        }
    }
    
    return mutantNumber;
}


/** Randomly turn immutant bunnies to mutant based on the number of mutant bunnies
    If the number of vampire is already > the number of immutant, then turn all immutant
    Print all turn events
 */
void bunnyClass::turnVampire(std::ofstream& file_write)
{
    int mutantNumber =getAdultMutantNumber();
    int turnIndex = 0;
    
    // If mutant number < immutant number
    if (mutantNumber < getImmutantNumber()) {
        for (int i = 0; i < mutantNumber; ++i) {
            do {
                turnIndex = random ((int)p_bunnyVec.size());
            } while (p_bunnyVec[ turnIndex ]->getVampire());
            p_bunnyVec[ turnIndex ]->setVampire(true);
            //std::cout << "Bunny " << p_bunnyVec[ turnIndex ]->getName() << " was turned!" << std:: endl;
            file_write << "Bunny " << p_bunnyVec[ turnIndex ]->getName() << " was turned!" << std:: endl;
        }
    }
    // If the mutant number >= immutant number
    else {
        for (auto bunny : p_bunnyVec) {
            if (!bunny->getVampire()) {
                bunny->setVampire(true);
                //std::cout << "Bunny " << bunny->getName() <<" was turned!" << std:: endl;;
                file_write << "Bunny " << bunny->getName() <<" was turned!" << std:: endl;
            }
        }
    }
    
    //std::cout << std::endl;
    file_write << std::endl;
}



/** Kill half of the bunnies if the number > 1000
 */
void bunnyClass::killHalf(std::ofstream& file_write)
{
    int ori_size = (int)p_bunnyVec.size();
    int randomNumber = 0;
    
    if (ori_size > 5000) {
        for (int i = 0, ori_range = ori_size/2; i < ori_range; ++i) {
            randomNumber = random ((int)p_bunnyVec.size());
            delete p_bunnyVec[ randomNumber ];
            p_bunnyVec.erase(p_bunnyVec.begin() + randomNumber);
        }
        
        //std::cout << ori_size/2 << " have died due to food shortage!" << std::endl;
        file_write <<  ori_size/2 << " have died due to food shortage!" << std::endl;
    }
}







