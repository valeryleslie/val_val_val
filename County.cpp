/* *~*~*
Implementation file for the County class
Written by: Valery Leslie Tanada
IDE: Xcode
*~**/
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "County.h"

using namespace std;

//**************************************************
// Constructor
//**************************************************
County::County()
{
    county = "";
    code = "";
    population = -1;
    cases = -1;
    deaths = -1;
}

//**************************************************
// Overloaded Constructor
//**************************************************
County::County(string cn, string cd, int p, int cs, int d)
{
    county = cn;
    code = cd;
    population = p;
    cases = cs;
    deaths = d;
}

//***********************************************************
// setCounty sets the value of the member variable county.
//**********************************************************

void County::setCounty(string ct)
{
    if (ct == " ")
    {
        cout << "Invalid County\n";
        exit(EXIT_FAILURE);
    }
    else
        county = ct;
}

//***********************************************************
// setCode sets the value of the member variable code.
//**********************************************************

void County::setCode(string cd)
{
    if (cd == " ")
    {
        cout << "Invalid Code\n";
        exit(EXIT_FAILURE);
    }
    else
        code = cd;
}

//***********************************************************
// setPopulation sets the value of the member variable
// population.
//**********************************************************

void County::setPopulation(int p)
{
    if (p < 0)
    {
        cout << "Invalid Population\n";
        exit(EXIT_FAILURE);
    }
    else
        population = p;
}

//***********************************************************
// setCases sets the value of the member variable cases.
//**********************************************************

void County::setCases(int c)
{
    if (c < 0)
    {
        cout << "Invalid Number of Cases\n";
        exit(EXIT_FAILURE);
    }
    else
        cases = c;
}


//***********************************************************
// setDeaths sets the value of the member variable deaths.
//**********************************************************

void County::setDeaths(int d)
{
    if (d < 0)
    {
        cout << "Invalid Number of Deaths\n";
        exit(EXIT_FAILURE);
    }
    else
        deaths = d;
}


//***********************************************************
// Displays the values of the County object member variables
// on one line (horizontal display)
//***********************************************************
void County::hDisplay() const
{
    cout << left;
    cout << setw(7) << county;
    cout << setw(11) << population;
    cout << setw(8) << code;
    cout << setw(6) << cases;
    cout << deaths << endl;
}

//***********************************************************
// Displays the values of the County object member variables
// as a vertical display
//***********************************************************
void County::vDisplay() const
{
    cout << "County Code: " << code << endl;
    cout << "Population: " << population << endl;
    cout << "Cases: " << cases << endl;
    cout << "Deaths: " << deaths << endl;
    cout << endl;
}

//************************************************************
// Overloaded > operator. Returns true if the current object *
// is set to a value greater than that of right.             *
//************************************************************

bool County::operator > (const County &right)
{
    bool status;

    if (code > right.code)
        status = true;
    else
        status = false;

    return status;
}

//************************************************************
// Overloaded < operator. Returns true if the current object *
// is set to a value less than that of right.                *
//************************************************************

bool County::operator < (const County &right)
{
    bool status;

    if (code < right.code)
        status = true;
    else
        status = false;

    return status;
}

//*************************************************************
// Overloaded == operator. Returns true if the current object *
// is set to a value equal to that of right.                  *
//*************************************************************

bool County::operator == (const County &right)
{
    bool status;

    if (code == right.code)
        status = true;
    else
        status = false;

    return status;
}

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display FeetInches objects.                  *
//********************************************************

ostream &operator << (ostream &strm, const County &obj)
{
    obj.hDisplay();
    return strm;
}

