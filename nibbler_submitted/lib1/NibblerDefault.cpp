/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NibblerDefault.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <dmather@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 16:59:46 by tmaske            #+#    #+#             */
/*   Updated: 2017/06/25 18:15:44 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NibblerDefault.hpp"

int    lib_draw_food(int FoodX, int FoodY)
{
	glColor3f(0.7, 0.0, 0.8);
	glRectf(FoodX, FoodY, FoodX + 1, FoodY + 1);
    return (1);
}

void    drawBlock(int x, int y, int gridX, int gridY)
{
	//Draw the blue border (outer)
	if (x == 0 || y == 0 || x == (gridX - 1) || y == (gridY - 1))
	{
		glLineWidth(20.0);
		glColor3f(0.1, 0.3, 0.7);
	}
	//Draw the black border (inner)
	else if (x == 1 || y == 1 || x == (gridX - 2) || y == (gridY - 2))
	{
		glLineWidth(5.0);
		glColor3f(0.0, 0.0, 0.2);
		glRectf(x, y, x + 1, y + 1);
		return ;
	}
	//Draw inside
	else
	{
		glLineWidth(10.0);
		glColor3f(0.2, 0.2, 0.2);
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
		glColor3f(0.0, 0.8, 0.1);
	else
		glColor3f(0.0, 0.4, 0.0);
	glRectd(PosXatN, PosYatN, PosXatN + 1, PosYatN + 1);
}