/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_two.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <dmather@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 11:54:48 by dmather           #+#    #+#             */
/*   Updated: 2017/06/25 18:15:44 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_TWO_H
# define GL_TWO_H

# include <OpenGL/gl.h>
# include <GLUT/glut.h>
# include <stddef.h>
# include <cstdlib>
# include <ctime>
# include <iostream>

extern "C"  int     lib_draw_food(int FoodX, int FoodY);
extern "C"  void    drawBlock(int x, int y, int gridX, int gridY);
extern "C"  void	lib_draw_snake(int i, int PosXatN, int PosYatN);

#endif