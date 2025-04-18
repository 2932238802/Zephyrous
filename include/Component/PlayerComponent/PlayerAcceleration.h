
#pragma once

struct PlayerAcceleration
{
	float a_x;		// 
	float a_y;

	PlayerAcceleration(float a_x_out , float a_y_out)
	{
		a_x = a_x_out;
		a_y = a_y_out;
	}
};