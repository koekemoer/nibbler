/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <dmather@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:15:07 by tmaske            #+#    #+#             */
/*   Updated: 2017/06/25 18:17:58 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

# include <cstdlib>
# include <ctime>
# include <iostream>
# include <vector>
#include <dlfcn.h>

# define WINDOW_HEIGHT 500
# define WINDOW_WIDTH 500
# define COLOUMNS 50
# define ROWS 50
# define DEFAULT_FPS 10
# define DEFAULT_SNAKE_LEN 4
# define UP 1
# define DOWN -1
# define RIGHT 2
# define LEFT -2
# define MAX 200

typedef int(*print_t)(int FoodX, int FoodY);
typedef void(*drawBlock_t)(int x, int y, int gridX, int gridY);
typedef void(*lib_draw_snake_t)(int i, int PosXatN, int PosYatN);

class Game
{
public:
	Game();
	~Game();
	Game(Game const & src);
	Game &				operator=(Game const & rhs);

	print_t				lib_draw_food;
	drawBlock_t			drawBlock;
	lib_draw_snake_t	lib_draw_snake;

	int 				getLenX() const;
	int 				getLenY() const;
	int 				getGridX() const;
	int 				getGridY() const;
	int 				getFPS() const;
	int					getSnakeLen() const;
	int					getPosX() const;
	int					getPosY() const;
	int					getPosXatN(int n) const;
	int					getPosYatN(int n) const;
	int 				getFoodX() const;
	int 				getFoodY() const;
	bool 				getFood() const;
	bool 				getGameOver() const;
	int					getBoost() const;
	int 				getScore() const;
	int 				getSpeedIncrease() const;
	short				getSDirection() const;
	short				getPDirection() const;
	void				setLenX(int n);
	void				setLenY(int n);
	void				setGridX(int n);
	void				setGridY(int n);
	void				setFPS(int n);
	void				setSnakeLen(int n);
	void				setPosX(int v);
	void				setPosY(int v);
	void				setPosXatN(int n, int i);
	void				setPosYatN(int n, int i);
	void				setFoodX(int n);
	void				setFoodY(int n);
	void				setFood(bool b);
	void				setGameOver(bool b);
	void				setBoost(int n);
	void				setScore(int n);
	void				setSpeedIncrease(int n);
	void				setSDirection(short d);
	void				setPDirection(short d);
	void				init_snake();
	void				increase_speed();
	void				drawFood();
	void				activate_boost();
	void				deactivate_boost();
	void				overlap();
	void				boostCheck();
	void				moveSnake();
	void				postMoveCheck(int f);
	void				change_lib(int number);
	int					lib;

protected:
	int					_lenX;
	int					_lenY;
	int					_gridX;
	int					_gridY;
	int					_fps;
	int					_snakeLen;
	int					_posX[204];
	int					_posY[204];
	int					_foodX;
	int					_foodY;

private:
	bool				_food;
	bool				_gameOver;
	int					_boost;
	int					_score;
	int					_speed_increase;
	short				_sDirection;
	short				_pDirection;
};

#endif