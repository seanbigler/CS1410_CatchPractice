//
// Created by w01164264 on 10/31/2017.
//

#include "Distance.h"
/**
 * Default constructor
 * Set initial values to 0
 */
Distance::Distance(): feet(0), inches(0) {}

/**
 * Getter function for feet
 * @return value of feet
 */
int Distance::getFeet() const
{
    return feet;
}
/**
 * Setter function for feet variable
 * @param feet
 */
void Distance::setFeet(int feet)
{
    Distance::feet = feet;
}
/**
 * Getter function for inches variable
 * @return value of inches
 */
float Distance::getInches() const
{
    return inches;
}
/**
 * Setter for inches variable
 * @param inches
 */
void Distance::setInches(float inches)
{
    Distance::inches = inches;
}

Distance::Distance(int f, float i)
{
    feet = f;
    inches = i;
}

Distance Distance::operator+(Distance &second)
{
    Distance sum;
    // <obj>.attribute + <obj>.getter
    int tfeet;
    float tinches;
    tfeet = feet + second.feet;
    tinches = inches + second.inches;

    if(tinches >= 12.0)
    {
        tinches -= 12.0;
        tfeet += 1;
    }
    sum.setFeet(tfeet);
    sum.setInches(tinches);

    return sum;
}

Distance Distance::operator+(const int temp)
{
    feet += temp;    // Adding feet

    return Distance(feet, inches);
}


Distance operator+(const int f, Distance d1)
{
    int sum;
    sum = f + d1.getFeet();
    return Distance(sum, d1.getInches());
}
