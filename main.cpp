//
//  main.cpp
//  Created by Abdalla Atalla on 11/7/19.
//  Copyright © 2019 Abdalla Atalla. All rights reserved.
//

#include <iostream>
#include <list>
#include <cmath>

using namespace std;

float formatNumber(double d)
{
    return std::ceil(d * 100.00) / 100.00;
}

void showMaxMin(list<double> l)
{
    double maxNumber = l.front();
    double minNumber = l.front();

    list<double>::iterator it;
    for (it = l.begin(); it != l.end(); ++it)
    {
        if (*it > maxNumber)
        {
            maxNumber = *it;
        }

        if (*it < minNumber)
        {
            minNumber = *it;
        }
    }
    cout << "Maximum number is: " << maxNumber << endl;
    cout << "Minimum number is: " << minNumber << endl;
    cout << "Average is: " << formatNumber((maxNumber + minNumber) / 2) << endl;
    cout << endl;
}

int main()
{

    list<double> myList;

    double number = -1;
    string existYN;

    do
    {
        cout << "Please enter your number to the list: ";

        if (cin >> number)
        {
            myList.push_back(formatNumber(number));
        }
        else
        {
            cout << "Invalid input! Please enter a valid number!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Are you done? (Y/N) ";
        cin >> existYN;

    } while (existYN != "Y" and existYN != "y");

    showMaxMin(myList);

    myList.clear();
    return 0;
}
