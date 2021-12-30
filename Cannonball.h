//Cannon Ball Program by Andrew Wei, Kulsoom Sabit, Wint Thinzar Phyo
//9/6/20
//This program creates a cannonball class which takes in user input for initial velocity and launch angle and finds the x and y position
//of the ball for every .1 or .5 time interval after the ball is launched until the ball hits the ground (0)
//this file is the header file creating the class and declaring the members
//SOLUTION
#ifndef CANNONBALL_H
#define CANNONBALL_H
// A Cannonball class and program.

#include <iostream>
#include <cmath> //cos sin and pow

/**
   This class simulates a cannonball fired at an angle.
*/
class Cannonball
{
public:
   /**
      Constructs a Cannonball that is on the ground, at rest.
      @param a variable for the initial x position
   */
	Cannonball(double start_x); //this will initialze the x and y positions

   /**
      Updates the position and velocity of this cannonball
      after a given time interval.
      @param a variable for the time interval
   */
	void set_launch(double velocity, double angle); //this member will calculate the x and y velocity

   /**
      @param a variable for the initial velocity of the ball
      @param a variable for the angle (in degrees) at which the cannonball was launched
   */
	void shoot(double update_time);//this member will calculate the x and y positions as they change with the provided time interval until y = 0; hits the ground

private:
	double x_velocity; //the x_velocity is double because the velocity uses cosine in it's calculations, which often returns a decimal value
	double y_velocity; //the y_velocity is also double as it uses sin in it's calculations; both x and y velocity need decimal values for highest accuracy
	double x; //the x position requires gravity and the x_velocity to calculate, which means it needs to be double
	double y; //the y position also uses gravity and the y_velocity; if these are not decimals the calculations are very inaccurate
};

#endif
