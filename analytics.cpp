/**
 * @file analytics.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "analytics.h"

using namespace std;

/**
 * @brief loads the file and loads it into a vector
 * 
 * @param fileName 
 * @param vector 
 */
void loadFile(const string &fileName, vector<GradEmploymentData> &vector) {
    ifstream fileData(fileName);
    if (!fileData) {
        cout << "Error opening file.\n";
        // Terminate the program
        exit(1); // include <cstdlib>
    }
    

    string line;
    getline(fileData, line);

    while(fileData.peek() != EOF) {
        char comma;
        GradEmploymentData dataLine;
        fileData>>dataLine.demographicsTotal>>comma;
        if(fileData.peek() == '"') {
            fileData>>comma;
            getline(fileData, dataLine.educationMajor, '"');
            fileData>>comma;
        } else {
            getline(fileData, dataLine.educationMajor, ',');
        }
        fileData>>dataLine.meanSalary>>comma;
        fileData>>dataLine.medianSalary>>comma;
        fileData>>dataLine.demographicsAsian>>comma;
        fileData>>dataLine.demographicsMinority>>comma;
        fileData>>dataLine.demographicsWhite>>comma;
        fileData>>dataLine.demographicsFemales>>comma;
        fileData>>dataLine.demographicsMales>>comma;
        fileData>>dataLine.educationBachelor>>comma;
        fileData>>dataLine.educationDoctorate>>comma;
        fileData>>dataLine.educationMasters;

        vector.push_back(dataLine);
    }

    fileData.close();

}

void displayVector(vector<GradEmploymentData> &vector) {
    for(long unsigned int i = 0; i < vector.size()-1; i++) {
        cout << setw(7) << left << vector[i].demographicsTotal<<" "<<vector[i].educationMajor<< " " << vector[i].meanSalary << " " << vector[i].medianSalary << " " << vector[i].demographicsAsian << " " << vector[i].demographicsMinority << " " << vector[i].demographicsWhite << " " << vector[i].demographicsFemales << " " << vector[i].demographicsMales << " " << vector[i].educationBachelor << " " << vector[i].educationDoctorate << " " << vector[i].educationMasters << endl;
    }
}

/**
 * @brief function to display all menu options
 * 
 */
void displayMenu() {
    cout << "2015 National Survey of Recent College Graduate" << endl;
    cout << "1. Top 10 Majors with the Highest Mean Salary" << endl;
    cout << "2. Top 10 Majors with the Lowest Mean Salary" << endl;
    cout << "3. Top 10 Majors with the Highest Median Salary" << endl;
    cout << "4. Top 10 Majors with the Lowest Median Salary" << endl;
    cout << "5. What are the Top 5 Majors with the Highest Number of Asians" << endl;
    cout << "6. What are the Top 5 Majors with the Lowest Number of Asians" << endl;
    cout << "7. What are the Top 5 Majors with the Highest Number of Minorities" << endl;
    cout << "8. What are the Top 5 Majors with the Lowest Number of Minorities" << endl;
    cout << "9. What are the Top 5 Majors with the Highest Number of Whites" << endl;
    cout << "10. What are the Top 5 Majors with the Lowest Number of Whites" << endl;
    cout << "11. Display Information for a Specific Major" << endl;
    cout << "12. Exit" << endl;
}
/**
 * @brief lets the user input what they want from the menu.
 * 
 */
void menuChoice(vector<GradEmploymentData> &vec){
    while(1) {
    int userChoice=0;
    cout << "Select a menu: ";
    cin >> userChoice;

    switch(userChoice) {
        case 1: MeanSalaryMost(vec);
            break;
        case 2: MeanSalaryLeast(vec);
            break;
        case 3: MedianSalaryMost(vec);
            break;
        case 4: MedianSalaryLeast(vec);
            break;
        case 5: highestAsian(vec);
            break;
        case 6: lowestAsian(vec);
            break;
        case 7: highestMinority(vec);
            break;
        case 8: lowestMinority(vec);
            break;
        case 9: highestWhite(vec);
            break;
        case 10: lowestWhite(vec);
            break;
        case 11: insertionSort(vec);
            break;
        case 12: exit(1);
            break;
        default: cout << "You did not choose a option from 1 to 12"<<endl;
        cin.ignore();
        menuChoice(vec);
            break;

    }
    
    cout<< endl;
    cout<< endl;
    cin.ignore();
    cout<< "press enter to continue..." << endl;
    cin.ignore();
    displayMenu();
    }
}

/**
 * @brief Functions for sorting by Mean Salary for Most and least and displaying that afterwards
 * 
 * @param vector 
 */
void MeanSalaryMost(vector<GradEmploymentData> vec)
{

    for (long unsigned int startScan = 0; startScan < vec.size()-1; ++startScan)
    {
        GradEmploymentData minValue;
        int minIndex = startScan;
        minValue = vec[startScan];
        for (long unsigned int index = startScan + 1; index < vec.size(); ++index)
        {
            if (minValue.meanSalary < vec[index].meanSalary)
            {
                minValue = vec[index];
                minIndex = index;
            }
        }
    vec[minIndex] = vec[startScan];
    vec[startScan] = minValue;
    }
    displayVectorMeanSalary(vec);
}
void MeanSalaryLeast(vector<GradEmploymentData> vec)
{

    for (long unsigned int startScan = 0; startScan < vec.size()-1; ++startScan)
    {
        GradEmploymentData minValue;
        int minIndex = startScan;
        minValue = vec[startScan];
        for (long unsigned int index = startScan + 1; index < vec.size(); ++index)
        {
            if (minValue.meanSalary > vec[index].meanSalary)
            {
                minValue = vec[index];
                minIndex = index;
            }
        }
    vec[minIndex] = vec[startScan];
    vec[startScan] = minValue;
    }
    displayVectorMeanSalary(vec);
}
void displayVectorMeanSalary(vector<GradEmploymentData> &vec) {
    cout << setw(35) << left << "Education Major" << setw(10) << "Mean Salary" << endl;
    cout << "------------------------------------------------" << endl;
    for(long unsigned int i = 0; i <= 10; i++) {
        cout << setw(35) << left <<vec[i].educationMajor<< "$" << setw(10) << right << vec[i].meanSalary << endl;
    }

}

/**
 * @brief sorts the vector based on high or low median and displays it
 * 
 * @param vec 
 */
void MedianSalaryMost(vector<GradEmploymentData> vec)
{

    for (long unsigned int startScan = 0; startScan < vec.size()-1; ++startScan)
    {
        GradEmploymentData minValue;
        int minIndex = startScan;
        minValue = vec[startScan];
        for (long unsigned int index = startScan + 1; index < vec.size(); ++index)
        {
            if (minValue.medianSalary < vec[index].medianSalary)
            {
                minValue = vec[index];
                minIndex = index;
            }
        }
    vec[minIndex] = vec[startScan];
    vec[startScan] = minValue;
    }
    displayMedianSalary(vec);
}
void MedianSalaryLeast(vector<GradEmploymentData> vec)
{

    for (long unsigned int startScan = 0; startScan < vec.size()-1; ++startScan)
    {
        GradEmploymentData minValue;
        int minIndex = startScan;
        minValue = vec[startScan];
        for (long unsigned int index = startScan + 1; index < vec.size(); ++index)
        {
            if (minValue.medianSalary > vec[index].medianSalary)
            {
                minValue = vec[index];
                minIndex = index;
            }
        }
    vec[minIndex] = vec[startScan];
    vec[startScan] = minValue;
    }
    displayMedianSalary(vec);
}
void displayMedianSalary(vector<GradEmploymentData> &vec) {
    cout << setw(35) << left << "Education Major" << setw(10) << "Median Salary" << endl;
    cout << "------------------------------------------------" << endl;
    for(long unsigned int i = 0; i <= 10; i++) {
        cout << setw(35) << left <<vec[i].educationMajor<< "$" << setw(10) << right << vec[i].medianSalary << endl;
    }

}

/**
 * @brief used to sort the number of Asians in a major from highest or lowest and displays it
 * 
 * @param vec 
 */
void highestAsian(vector<GradEmploymentData> vec)
{

    for (long unsigned int startScan = 0; startScan < vec.size()-1; ++startScan)
    {
        GradEmploymentData minValue;
        int minIndex = startScan;
        minValue = vec[startScan];
        for (long unsigned int index = startScan + 1; index < vec.size(); ++index)
        {
            if (minValue.demographicsAsian < vec[index].demographicsAsian)
            {
                minValue = vec[index];
                minIndex = index;
            }
        }
    vec[minIndex] = vec[startScan];
    vec[startScan] = minValue;
    }
    displayAsianCount(vec);
}
void lowestAsian(vector<GradEmploymentData> vec)
{

    for (long unsigned int startScan = 0; startScan < vec.size()-1; ++startScan)
    {
        GradEmploymentData minValue;
        int minIndex = startScan;
        minValue = vec[startScan];
        for (long unsigned int index = startScan + 1; index < vec.size(); ++index)
        {
            if (minValue.demographicsAsian > vec[index].demographicsAsian)
            {
                minValue = vec[index];
                minIndex = index;
            }
        }
    vec[minIndex] = vec[startScan];
    vec[startScan] = minValue;
    }
    displayAsianCount(vec);
}
void displayAsianCount(vector<GradEmploymentData> &vec) {
    cout << setw(35) << left << "Education Major"  << "Asian Demographic" << endl;
    cout << "-------------------------------------------------------" << endl;
    for(long unsigned int i = 0; i <= 5; i++) {
        cout << setw(40) << left <<vec[i].educationMajor<< " " << setw(10) << right << vec[i].demographicsAsian << endl;
    }

}

/**
 * @brief used to sort the number of Minorities in a major from highest or lowest and displays it
 * 
 * @param vec 
 */
void highestMinority(vector<GradEmploymentData> vec)
{

    for (long unsigned int startScan = 0; startScan < vec.size()-1; ++startScan)
    {
        GradEmploymentData minValue;
        int minIndex = startScan;
        minValue = vec[startScan];
        for (long unsigned int index = startScan + 1; index < vec.size(); ++index)
        {
            if (minValue.demographicsMinority < vec[index].demographicsMinority)
            {
                minValue = vec[index];
                minIndex = index;
            }
        }
    vec[minIndex] = vec[startScan];
    vec[startScan] = minValue;
    }
    displayMinorityCount(vec);
}
void lowestMinority(vector<GradEmploymentData> vec)
{

    for (long unsigned int startScan = 0; startScan < vec.size()-1; ++startScan)
    {
        GradEmploymentData minValue;
        int minIndex = startScan;
        minValue = vec[startScan];
        for (long unsigned int index = startScan + 1; index < vec.size(); ++index)
        {
            if (minValue.demographicsMinority > vec[index].demographicsMinority)
            {
                minValue = vec[index];
                minIndex = index;
            }
        }
    vec[minIndex] = vec[startScan];
    vec[startScan] = minValue;
    }
    displayMinorityCount(vec);
}
void displayMinorityCount(vector<GradEmploymentData> &vec) {
    cout << setw(35) << left << "Education Major"  << "Minorities Demographic" << endl;
    cout << "-------------------------------------------------------" << endl;
    for(long unsigned int i = 0; i <= 5; i++) {
        cout << setw(40) << left <<vec[i].educationMajor<< " " << setw(10) << right << vec[i].demographicsMinority << endl;
    }

}

/**
 * @brief used to sort the number of Whites in a major from highest or lowest and displays it
 * 
 * @param vec 
 */
void highestWhite(vector<GradEmploymentData> vec)
{

    for (long unsigned int startScan = 0; startScan < vec.size()-1; ++startScan)
    {
        GradEmploymentData minValue;
        int minIndex = startScan;
        minValue = vec[startScan];
        for (long unsigned int index = startScan + 1; index < vec.size(); ++index)
        {
            if (minValue.demographicsWhite< vec[index].demographicsWhite)
            {
                minValue = vec[index];
                minIndex = index;
            }
        }
    vec[minIndex] = vec[startScan];
    vec[startScan] = minValue;
    }
    displayWhiteCount(vec);
}
void lowestWhite(vector<GradEmploymentData> vec)
{

    for (long unsigned int startScan = 0; startScan < vec.size()-1; ++startScan)
    {
        GradEmploymentData minValue;
        int minIndex = startScan;
        minValue = vec[startScan];
        for (long unsigned int index = startScan + 1; index < vec.size(); ++index)
        {
            if (minValue.demographicsWhite > vec[index].demographicsWhite)
            {
                minValue = vec[index];
                minIndex = index;
            }
        }
    vec[minIndex] = vec[startScan];
    vec[startScan] = minValue;
    }
    displayWhiteCount(vec);
}
void displayWhiteCount(vector<GradEmploymentData> &vec) {
    cout << setw(35) << left << "Education Major"  << "White Demographic" << endl;
    cout << "----------------------------------------------------" << endl;
    for(long unsigned int i = 0; i <= 5; i++) {
        cout << setw(40) << left <<vec[i].educationMajor<< " " << setw(10) << right << vec[i].demographicsWhite << endl;
    }

}

/**
 * @brief sorts all majors alphabetically
 * 
 * @param vec 
 */
void insertionSort(vector<GradEmploymentData> vec)
{
    for (long unsigned int startScan = 1; startScan < vec.size(); ++startScan)
    {
        GradEmploymentData key = vec[startScan];
        int index = startScan - 1;
        while (index >= 0 && vec[index].educationMajor > key.educationMajor)
        {
            vec[index+1] = vec[index];
            --index;
        }
        vec[index+1] = key;
    }
    displayMajors(vec);
}

/**
 * @brief displays all majors
 * 
 * @param vec 
 */
void displayMajors(vector<GradEmploymentData> &vec) {
    cout << setw(35) << left << "Education Major"  << endl;
    cout << "-------------------------------------------" << endl;
    for(long unsigned int i = 0; i <= vec.size()-1; i++) {
        cout << setw(40) << left <<vec[i].educationMajor<< endl;
    }
    string userInput;
    cin.ignore();
    cout << "Please type a major you want more info on: ";
    getline(cin,userInput);
    userInput[0] = toupper(userInput[0]);
    int position = binarySearch(vec, userInput);
    displaySpecificMajor(vec, position);
    cin.ignore();
    cout << "\n\n";
    displayMenu();
    menuChoice(vec);
}

/**
 * @brief searches for user inputted major from vector
 * 
 * @param vec 
 * @param value 
 * @return int 
 */
int binarySearch(const vector<GradEmploymentData> &vec, string &value)
{
int first = 0, // First array element
last = vec.size() - 1, // Last array element
middle, // Midpoint of search
position = -1; // Position of search value
bool found = false; // Flag
while (!found && first <= last)
{
middle = (first + last) / 2; // Calculate midpoint
if (vec[middle].educationMajor == value) // If value is found at mid
{
found = true;
position = middle;
}
else if (vec[middle].educationMajor > value) // If value is in lower half
{
last = middle - 1;
}
else
{
first = middle + 1; // If value is in upper half
}
}
return position;
}

/**
 * @brief Displays all information on a specific major
 * 
 * @param vec 
 * @param pos 
 */
void displaySpecificMajor(vector<GradEmploymentData> &vec, int pos) {
    cout << vec[pos].educationMajor << endl;
    cout << setw(20) << left << "Demographic Total" << setw(20)<< right << vec[pos].demographicsTotal << endl;
    cout << setw(20) << left << "Mean Salary" << setw(20)<< right << vec[pos].meanSalary << endl;
    cout << setw(20) << left << "Median Salary" << setw(20)<< right << vec[pos].medianSalary << endl;
    cout << setw(20) << left << "Asian Demographic" << setw(20)<< right << vec[pos].demographicsAsian << endl;
    cout << setw(20) << left << "Minority Demographic" << setw(20)<< right << vec[pos].demographicsMinority << endl;
    cout << setw(20) << left << "White Demographic" << setw(20)<< right << vec[pos].demographicsWhite << endl;
    cout << setw(20) << left << "Female Demographic" << setw(20)<< right << vec[pos].demographicsFemales << endl;
    cout << setw(20) << left << "Male Demographic" << setw(20)<< right << vec[pos].demographicsMales << endl;
    cout << setw(20) << left << "Bachelors" << setw(20)<< right << vec[pos].educationBachelor << endl;
    cout << setw(20) << left << "Docorates" << setw(20)<< right << vec[pos].educationDoctorate << endl;
    cout << setw(20) << left << "Masters" << setw(20)<< right << vec[pos].educationMasters << endl;
}