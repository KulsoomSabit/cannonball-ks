//Cannon Ball Program by Andrew Wei, Kulsoom Sabit, Wint Thinzar Phyo
//9/6/20
//This program creates a cannonball class which takes in user input for initial velocity and launch angle and finds the x and y position
//of the ball for every .1 or .5 time interval after the ball is launched until the ball hits the ground (0)
//this file contains the main function that runs the functions in the program
#include "pch.h"
#include <iostream>
#include "Cannonball.h"

int main()
{
	double start_x;
	double launch_speed;
	double initial_angle;

	std::cout << "Enter starting x position(meters): "; //get the starting x position of the cannon
	std::cin >> start_x;

	std::cout << "Enter the initial launch speed(m/s) of the cannon: "; //get the initial velocity of the cannonball
	std::cin >> launch_speed;

	std::cout << "Enter angle(degrees) of launch: "; //get the angle of the cannon being launched
	std::cin >> initial_angle;

	Cannonball cannon1(start_x); //create cannon1 object with inital x position
	cannon1.set_launch(launch_speed, initial_angle); //set the parameters for launch with the initial velocity and angle
	cannon1.shoot(0.5); //shoot the cannon displaying the x and y position for every 0.5 second interval

	return 0; //return 0 to show the function ran smoothly
}