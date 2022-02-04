/* *~*~*
Specification file for the County class
 Holds the data for Counties COVID-19 Data
Written by: Valery Leslie Tanada
IDE: Xcode
*~**/

#ifndef County_h
#define County_h

#include<string>

using std::string;
using std::ostream;

class County;

ostream &operator << (ostream &, const County &);

class County
{
private:
    string county;
    string code;
    int population;
    int cases;
    int deaths;
public:
    // constructors
    County();
    County(string, string, int, int, int);
    
    // setters
    void setCounty (string);
    void setCode (string);
    void setPopulation(int);
    void setCases(int);
    void setDeaths(int);
        
    // getters
    string getCounty() const {return county;}
    string getCode() const {return code;}
    int getPopulation() const {return population;}
    int getCases() const {return cases;}
    int getDeaths() const {return deaths;}
    
    // display or print functions
    void hDisplay()const;
    void vDisplay()const;
    
    //overloaded operators
    bool operator < (const County &right);
    bool operator > (const County &right);
    bool operator == (const County &right);
    
    //friends operators
    friend ostream &operator << (ostream &, const County &);
};

#endif /* County_h */
