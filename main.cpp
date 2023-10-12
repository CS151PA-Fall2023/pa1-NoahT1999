/**
 * @file main.cpp
 * @author Noah Turner
 * @brief Write a data analytics program using the National Survey of Recent College Graduates.
 * @version 0.1
 * @date 2023-08-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include "analytics.h"

using namespace std;

int main() {

    vector<GradEmploymentData> GradData;
    loadFile("graduates2015.csv", GradData);

    displayMenu();
    menuChoice(GradData);

    return 0;
}