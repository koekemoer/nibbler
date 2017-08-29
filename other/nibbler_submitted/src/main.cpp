/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <dmather@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 15:34:25 by dmather           #+#    #+#             */
/*   Updated: 2017/06/25 18:16:15 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Nibbler.hpp"

Game *core = new Game;

char	*con(const char * first, const char * second)
{
    int l1 = 0, l2 = 0;
    const char * f = first, * l = second;

    while (*f++) ++l1;
    while (*l++) ++l2;
    char *result = new char[l1 + l2];
    for (int i = 0; i < l1; i++) result[i] = first[i];
    for (int i = l1; i < l1 + l2; i++) result[i] = second[i - l1];
    result[l1+l2] = '\0';
    return result;
}

void	display_callback()
{
	int 	f;
	char	*name;
	char	*title;

	f = 0;
	name = const_cast<char *> (std::to_string(core->getScore()).c_str());
	title = con("Highscore Garry -> 111 >>> Your Score -> ", name);
	glutSetWindowTitle(title);
	if (core->lib == 1)
		core->change_lib(1);
	else if (core->lib == 2)
		core->change_lib(2);
	else if (core->lib == 3)
		core->change_lib(3);
	glClear(GL_COLOR_BUFFER_BIT);
	for (int x = 0; x < core->getGridX(); x++)
	{
		for (int y = 0; y < core->getGridY(); y++)
			core->drawBlock(x, y, core->getGridX(), core->getGridY());
	}
	core->boostCheck();
	core->moveSnake();
	for (int i = 0; i < core->getSnakeLen(); i++)
	{
		core->overlap();
		if (core->getPosXatN(i) == core->getFoodX() && core->getPosYatN(i) == core->getFoodY())
			f = 1;
		if (core->getPosXatN(0) == core->getPosXatN(i + 1) && core->getPosYatN(0) == core->getPosYatN(i + 1))
			core->setGameOver(true);
		core->lib_draw_snake(i, core->getPosXatN(i), core->getPosYatN(i));
	}
	core->postMoveCheck(f);
	core->drawFood();
	core->lib_draw_food(core->getFoodX(), core->getFoodY());
	glutSwapBuffers();
	if (core->getGameOver())
	{
		std::cout << "GAME OVER!" << std::endl << "You scored: " << core->getScore() << " points!" << std::endl;
		glutWMCloseFunc(close);
		delete core;
		exit(0);
	}
	return ;
}

void	keyboard_callback(int key, int, int)
{
	switch (key)
	{
		case GLUT_KEY_UP:
			core->setPDirection(core->getSDirection());
			if (core->getSDirection() == UP)
				core->activate_boost();
			if (core->getSDirection() != DOWN)
				core->setSDirection(UP);
			break;
		case GLUT_KEY_DOWN:
			core->setPDirection(core->getSDirection());
			if (core->getSDirection() == DOWN)
				core->activate_boost();
			if (core->getSDirection() != UP)
				core->setSDirection(DOWN);
			break;
		case GLUT_KEY_LEFT:
			core->setPDirection(core->getSDirection());
			if (core->getSDirection() == LEFT)
				core->activate_boost();
			if (core->getSDirection() != RIGHT)
				core->setSDirection(LEFT);
			break;
		case GLUT_KEY_RIGHT:
			core->setPDirection(core->getSDirection());
			if (core->getSDirection() == RIGHT)
				core->activate_boost();
			if (core->getSDirection() != LEFT)
				core->setSDirection(RIGHT);
			break;
		case 27:
			core->setGameOver(true);
			break;
		case 62:
			core->setFPS(core->getFPS() + 1);
			break;
		case 60:
			core->setFPS(core->getFPS() - 1);
			if (core->getFPS() < 1)
				core->setFPS(1);
			break;
		case 49:
			core->lib = 1;
			core->change_lib(1);
			break;
		case 50:
			core->lib = 2;
			core->change_lib(2);
			break;
		case 51:
			core->lib = 3;
			core->change_lib(3);
			break;
		case 32:
			core->activate_boost();
			break;
	}
	return ;
}

void	timer_callback(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / core->getFPS(), timer_callback, 0);
}

void	reshape_callback(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COLOUMNS, 0.0, ROWS, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void	close(void)
{
    return ;
}

int	main(int argc, char **argv)
{
	bool	first;

	first = true;
	if (argc == 1)
	while(1)
	{
		if (first)
		{
			first = false;
			glutInit(&argc, argv);
			glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
			glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
			glutCreateWindow("Garry => 98");
			glutDisplayFunc(display_callback);
			glutReshapeFunc(reshape_callback);
			glutTimerFunc(0, timer_callback, 0);
			glutSpecialFunc(keyboard_callback);
			glClearColor(0.0, 0.0, 0.0, 1.0);
		}
		glutCheckLoop();
	}
	else
		std::cout << "No parameters required" << std::endl;
	return (0);
}