//Cannon Ball Program by Andrew Wei, Kulsoom Sabit, Wint Thinzar Phyo
//9/6/20
//This program creates a cannonball class which takes in user input for initial velocity and launch angle and finds the x and y position
//of the ball for every .1 or .5 time interval after the ball is launched until the ball hits the ground (0)
//this file create's the functions for the main function to run

#include "pch.h"
#include <iostream>
#include <math.h> //cos sin and pow
#include "Cannonball.h"

//this class was worked on by Kulsoom Sabit
Cannonball::Cannonball(double start_x) //the member shares the name with the class name with a parameter, meaning its called when the object is created with a parameter
{
	x = start_x; //x is equal to the starting x position in the parameter
	y = 0.0; //y is set to 0 with no variance
}

//this class was worked on by Wint Thinzar Phyo
void Cannonball::set_launch(double velocity, double angle) //member takes two parameters: initial velocity and angle of launch
{
	double const pi = 3.14159265; //pi only needs to be used here so it's defined here
	angle = (angle * (pi / 180)); //since the cos and sin functions use radians, this converts the input of degrees into radians as radians are more complex to enter
	x_velocity = velocity * cos(angle);  //the initial x_velocity = inital_velocity * cos(angle)
	y_velocity = velocity * sin(angle); //the initial y_velocity = initial_velocity * sin(angle)
}

//this class was worked on by Andrew Wei
void Cannonball::shoot(double update_time) //the shoot member takes a time interval as a parameter which increments itself until the ball hits the ground
{
	double initial_x = x; //this allows the x position to update on it's initial position
	double time = update_time; //time variable defined for this member to be able to have time increment with the parameter
	double const gravity = -9.81; //gravity's acceleration is defined here for convenience of use
	do //use a do while loop here to allow the y position to update first so the y condition can only happen when the ball lands
	{
		//the calculation for the x position is initial x + x_velocity * time
		x = initial_x + (x_velocity * time); //the horizontal velocity remains consistent ignoring air resistance and thus doesn't need to update when finding the position of x
		//y position = initial_y_velocity * time + (1/2(gravity * time^2))
		y = (y_velocity * time) + (0.5 * gravity * pow(time, 2.0)); //the y position goes up and down as a result of time ^ 2 giving it a parabolic shape
		if (y > 0) //this makes it so the coordinates won't display a negative y coordinate as the y coordinate shouldn't be negative
		{
			std::cout << "(" << x << ", " << y << ") at " << time << " seconds. " << std::endl;
			//make it so only two decimal points appear to make things more consistent when displaying
		}
		time += update_time; //have the time interval increment
	} while (y > 0); //ends the loop when the ball lands on the ground, or when y <= 0
	std::cout << std::endl;
}
