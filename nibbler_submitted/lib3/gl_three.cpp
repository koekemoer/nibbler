/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_three.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <dmather@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 10:01:35 by dmather           #+#    #+#             */
/*   Updated: 2017/06/25 18:21:11 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_three.hpp"

int    lib_draw_food(int FoodX, int FoodY)
{
	static int	c = 0;

	if (c == 0)
	{
		glColor3f(1.0, 0.0, 0.0);
		glRectf(FoodX, FoodY, FoodX + 1, FoodY + 1);
		c++;
	}
	else if (c == 1)
	{
		glColor3f(0.0, 1.0, 0.0);
		glRectf(FoodX, FoodY, FoodX + 1, FoodY + 1);
		c++;
	}
	else if (c == 2)
	{
		glColor3f(0.0, 0.0, 1.0);
		glRectf(FoodX, FoodY, FoodX + 1, FoodY + 1);
		c++;
	}
	else if (c == 3)
	{
		glColor3f(1.0, 1.0, 0.0);
		glRectf(FoodX, FoodY, FoodX + 1, FoodY + 1);
		c++;
	}
	else if (c == 4)
	{
		glColor3f(0.0, 1.0, 1.0);
		glRectf(FoodX, FoodY, FoodX + 1, FoodY + 1);
		c++;
	}
	else if (c == 5)
	{
		glColor3f(0.0, 0.0, 0.0);
		glRectf(FoodX, FoodY, FoodX + 1, FoodY + 1);
		c = 0;
	}
    return (1);
}

void    drawBlock(int x, int y, int gridX, int gridY)
{
	static int	c = 0;
	static int	d = 0;
	static int	e = 0;

	//Draw the blue border (outer)
	if (x == 0 || y == 0 || x == (gridX - 1) || y == (gridY - 1))
	{
		glLineWidth(20.0);
		if (c == 0)
		{
			glColor3f(1.0, 0.0, 0.0);
			c++;
		}
		else if (c == 1)
		{
			glColor3f(0.0, 1.0, 0.0);
			c++;
		}
		else if (c == 2)
		{
			glColor3f(0.0, 0.0, 1.0);
			c++;
		}
		else if (c == 3)
		{
			glColor3f(1.0, 1.0, 0.0);
			c++;
		}
		else if (c == 4)
		{
			glColor3f(0.0, 1.0, 1.0);
			c++;
		}
		else if (c == 5)
		{
			glColor3f(0.0, 0.0, 0.0);
			c = 0;
		}
	}
	//Draw the border shadow (inner)
	else if (x == 1 || y == 1 || x == (gridX - 2) || y == (gridY - 2))
	{
		glLineWidth(5.0);
		if (d == 0)
		{
			glColor3f(0.1, 0.0, 0.0);
			d++;
		}
		else if (d == 1)
		{
			glColor3f(0.0, 0.1, 0.0);
			d++;
		}
		else if (d == 2)
		{
			glColor3f(0.0, 0.0, 0.1);
			d++;
		}
		else if (d == 3)
		{
			glColor3f(0.1, 0.1, 0.0);
			d++;
		}
		else if (d == 4)
		{
			glColor3f(0.0, 0.1, 0.1);
			d++;
		}
		else if (d == 5)
		{
			glColor3f(0.1, 0.1, 0.1);
			d = 0;
		}
		glRectf(x, y, x + 1, y + 1);
		return ;
	}
	//Draw inside
	else
	{
		glLineWidth(10.0);
		if (e == 0)
		{
			glColor3f(0.2, 0.2, 0.2);
			glColor3f(0.2, 0.1, 0.1);
			e++;
		}
		else if (e == 1)
		{
			glColor3f(0.2, 0.2, 0.2);
			glColor3f(0.1, 0.2, 0.1);
			e++;
		}
		else if (e == 2)
		{
			glColor3f(0.2, 0.2, 0.2);
			glColor3f(0.1, 0.1, 0.2);
			e++;
		}
		else if (e == 3)
		{
			glColor3f(0.2, 0.2, 0.2);
			glColor3f(0.2, 0.2, 0.1);
			e++;
		}
		else if (e == 4)
		{
			glColor3f(0.2, 0.2, 0.2);
			glColor3f(0.1, 0.2, 0.2);
			e++;
		}
		else if (e == 5)
		{
			glColor3f(0.2, 0.2, 0.2);
			glColor3f(0.2, 0.2, 0.2);
			e = 0;
		}
	}
	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x + 1, y); //Horizontal vertex
	glVertex2f(x + 1, y + 1); //Diagonal vertex
	glVertex2f(x, y + 1); //Vertical vertex
	glEnd();
}

void	lib_draw_snake(int i, int PosXatN, int PosYatN)
{
	if (i == 0)
		glColor3f(1.0, 1.0, 1.0);
	else
		glColor3f(0.0, 0.0, 0.0);
	glRectd(PosXatN, PosYatN, PosXatN + 1, PosYatN + 1);
}