/**
 * @file analytics.h
 * @author your name (you@domain.com)
 * @brief header file
 * @version 0.1
 * @date 2023-08-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <iomanip>
#include<vector>
#include<fstream>
#include<string>
#include <cstdlib>

using namespace std;

struct GradEmploymentData
{
    int demographicsTotal;     // The estimated total of people awarded degrees in this major during 2005
    string educationMajor;     // The name of the major for these graduated students
    float meanSalary;          // The average (mean) recorded salary reported for employed people with this degree
    float medianSalary;        // The median recorded salary reported for employed people with this degree
    int demographicsAsian;     // The estimated number of people identifying as Asian that were awarded degrees in this major
    int demographicsMinority;  // The estimated number of people identifying as minority 
                               // (e.g., Black, African American, Native American) that were awarded degrees in this major
    int demographicsWhite;     // The estimated number of people identifying as White that were awarded degrees in this major
    int demographicsFemales;   // The estimate number of women awarded degrees in this major
    int demographicsMales;     // The estimate number of men awarded degrees in this major
    int educationBachelor;     // The estimated number of bachelor degrees awarded in this for major
    int educationDoctorate;    // The estimated number of doctoral degrees awarded in this for major
    int educationMasters;      // The estimated number of Masters awarded in this for major
};

void loadFile(const string &fileName, vector<GradEmploymentData> &vector);

void displayVector(vector<GradEmploymentData> &vector);

void displayMenu();

void menuChoice(vector<GradEmploymentData> &vec);


void MeanSalaryMost(vector<GradEmploymentData> vec);
void MeanSalaryLeast(vector<GradEmploymentData> vec);
void displayVectorMeanSalary(vector<GradEmploymentData> &vec);


void MedianSalaryMost(vector<GradEmploymentData> vec);
void MedianSalaryLeast(vector<GradEmploymentData> vec);
void displayMedianSalary(vector<GradEmploymentData> &vec);

void highestAsian(vector<GradEmploymentData> vec);
void lowestAsian(vector<GradEmploymentData> vec);
void displayAsianCount(vector<GradEmploymentData> &vec);

void highestMinority(vector<GradEmploymentData> vec);
void lowestMinority(vector<GradEmploymentData> vec);
void displayMinorityCount(vector<GradEmploymentData> &vec);

void highestWhite(vector<GradEmploymentData> vec);
void lowestWhite(vector<GradEmploymentData> vec);
void displayWhiteCount(vector<GradEmploymentData> &vec);

void insertionSort(vector<GradEmploymentData> vec);
void displayMajors(vector<GradEmploymentData> &vec);
int binarySearch(const vector<GradEmploymentData> &vec, string &value);
void displaySpecificMajor(vector<GradEmploymentData> &vec, int pos);