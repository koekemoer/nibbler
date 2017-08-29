/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <dmather@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 18:35:02 by tmaske            #+#    #+#             */
/*   Updated: 2017/06/25 18:05:25 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game()
{
	this->_lenX = WINDOW_WIDTH;
	this->_lenY = WINDOW_HEIGHT;
	this->_gridX = COLOUMNS;
	this->_gridY = ROWS;
	this->_fps = DEFAULT_FPS;
	this->_snakeLen = DEFAULT_SNAKE_LEN;
	this->_food = true;
	this->_gameOver = false;
	this->_boost = 0;
	this->_score = 0;
	this->_speed_increase = 3;
	this->_sDirection = RIGHT;
	this->_pDirection = RIGHT;
	this->lib = 1; 
	init_snake();
	drawFood();
}

Game::Game(Game const & src)
{
	*this = src;
}

Game::~Game() {}

Game & 				Game::operator=(Game const & src)
{
	this->_lenX = src.getLenX();
	this->_lenY = src.getLenY();
	this->_gridX = src.getGridX();
	this->_gridY = src.getGridY();
	this->_fps = src.getFPS();
	this->_snakeLen = src.getSnakeLen();
	this->_posX[0] = src.getPosX();
	this->_posY[0] = src.getPosY();
	this->_foodX = src.getFoodX();
	this->_foodY = src.getFoodY();
	this->_food = src.getFood();
	this->_boost = src.getBoost();
	this->_gameOver = src.getGameOver();
	this->_score = src.getScore();
	this->_speed_increase = src.getSpeedIncrease();
	this->_sDirection = src._sDirection;
	this->_pDirection = src._pDirection;
	return *this;
}

int 				Game::getLenX() const
{
	return this->_lenX;
}

int 				Game::getLenY() const
{
	return this->_lenY;
}

int 				Game::getGridX() const
{
	return this->_gridX;
}

int 				Game::getGridY() const
{
	return this->_gridY;
}

int 				Game::getFPS() const
{
	return this->_fps;
}

int 				Game::getSnakeLen() const
{
	return this->_snakeLen;
}

int					Game::getPosX() const
{
	return this->_posX[0];
}

int					Game::getPosY() const
{
	return this->_posY[0];
}

int 				Game::getPosXatN(int n) const
{
	return this->_posX[n];
}

int 				Game::getPosYatN(int n) const
{
	return this->_posY[n];
}

int 				Game::getFoodX() const
{
	return this->_foodX;
}

int 				Game::getFoodY() const
{
	return this->_foodY;
}

bool 				Game::getFood() const
{
	return this->_food;
}

bool 				Game::getGameOver() const
{
	return this->_gameOver;
}

int 				Game::getBoost() const
{
	return this->_boost;
}

int 				Game::getScore() const
{
	return this->_score;
}

int 				Game::getSpeedIncrease() const
{
	return this->_speed_increase;
}

short 				Game::getSDirection() const
{
	return this->_sDirection;
}

short 				Game::getPDirection() const
{
	return this->_pDirection;
}

void 				Game::setLenX(int n)
{
	this->_lenX = n;
}

void				Game::setLenY(int n)
{
	this->_lenY = n;
}

void				Game::setGridX(int n)
{
	this->_gridX = n;
}

void				Game::setGridY(int n)
{
	this->_gridY = n;
}

void				Game::setFPS(int n)
{
	this->_fps = n;
}

void				Game::setPosX(int v)
{
	this->_posX[0] = v;
}

void				Game::setPosY(int v)
{
	this->_posY[0] = v;
}

void				Game::setPosXatN(int n, int i)
{
	this->_posY[n] = i;
}

void				Game::setPosYatN(int n, int i)
{
	this->_posX[n] = i;
}

void				Game::setFoodX(int n)
{
	this->_foodX = n;
}

void				Game::setFoodY(int n)
{
	this->_foodY = n;
}

void				Game::setFood(bool b)
{
	this->_foodY = b;
}

void				Game::setGameOver(bool b)
{
	this->_gameOver = b;
}

void				Game::setBoost(int n)
{
	this->_boost = n;
}

void				Game::setScore(int n)
{
	this->_score = n;
}

void				Game::setSpeedIncrease(int n)
{
	this->_speed_increase = n;
}

void				Game::setSDirection(short d)
{
	this->_sDirection = d;
}

void				Game::setPDirection(short d)
{
	this->_pDirection = d;
}

void				Game::init_snake()
{
	this->_posX[0] = 5;
	this->_posX[1] = 4;
	this->_posX[2] = 3;
	this->_posX[3] = 2;
	this->_posY[0] = this->_gridY / 2;
	this->_posY[1] = this->_gridY / 2;
	this->_posY[2] = this->_gridY / 2;
	this->_posY[3] = this->_gridY / 2;
}

void				Game::increase_speed()
{
	if (this->_score % this->_speed_increase == 0)
		this->_fps++;
}

void				Game::drawFood()
{
	if (this->_food)
	{
		int maxX_val;
		int maxY_val;
		int min_val;
		int d;
		int xi;
		int yi;

		srand(time(0));
		d = 1;
		maxX_val = this->_gridX - 3;
		maxY_val = this->_gridY - 3;
		min_val = 2;
		while (d)
		{
			xi = min_val + rand() % (maxX_val - min_val);
			yi = min_val + rand() % (maxY_val - min_val);
			for (int i = 0; i < this->_snakeLen; i++)
			{
				if (this->_posX[i] != xi && this->_posY[i] != yi)
					d = 0;
				else if (this->_posX[i] == xi && this->_posY[i] == yi)
				{
					d = 1;
					// std::cout << "hit" << std::endl;
					break;
				}
			}
			if (d == 0)
			{
				this->_foodX = xi;
				this->_foodY = yi;
			}
		}
	}
	this->_food = false;
}

void				Game::activate_boost()
{
	if (this->_boost == 0)
	{
		this->_fps += 20;
		this->_boost++;
	}
}

void				Game::deactivate_boost()
{
	if (this->_boost >= 15)
	{
		this->_fps -= 20;
		if (this->_fps < 1)
			this->_fps = 1;
		this->_boost = 0;
	}
}

void				Game::overlap()
{
	if (this->_posX[0] == this->_posX[2] && this->_posY[0] == this->_posY[2])
	{
		if ((this->_pDirection == UP && this->_sDirection == RIGHT) || (this->_pDirection == LEFT && this->_sDirection == DOWN))
		{
			this->_posY[0]++;
			this->_posX[0]--;
		}
		else if ((this->_pDirection == UP && this->_sDirection == LEFT) || (this->_pDirection == RIGHT && this->_sDirection == DOWN))
		{
			this->_posY[0]++;
			this->_posX[0]++;
		}
		else if ((this->_pDirection == DOWN && this->_sDirection == RIGHT) || (this->_pDirection == LEFT && this->_sDirection == UP))
		{
			this->_posY[0]--;
			this->_posX[0]--;
		}
		else if ((this->_pDirection == DOWN && this->_sDirection == LEFT) || (this->_pDirection == RIGHT && this->_sDirection == UP))
		{
			this->_posY[0]--;
			this->_posX[0]++;
		}
	}
}

void					Game::boostCheck()
{
	if (this->_boost >= 1)
		this->_boost++;
	if (this->_boost == 15)
		deactivate_boost();
}

void					Game::moveSnake()
{
	for (int i = this->_snakeLen - 1; i > 0; i--)
	{
		this->_posX[i] = this->_posX[i - 1];
		this->_posY[i] = this->_posY[i - 1];
	}
	if (this->_sDirection == UP)
		this->_posY[0]++;
	else if (this->_sDirection == DOWN)
		this->_posY[0]--;
	else if (this->_sDirection == RIGHT)
		this->_posX[0]++;
	else if (this->_sDirection == LEFT)
		this->_posX[0]--;
}

void					Game::postMoveCheck(int f)
{
	if (this->_posX[0] == 0 || this->_posX[0] == this->_gridX - 1 || this->_posY[0] == 0 || this->_posY[0] == this->_gridY - 1)
		this->_gameOver = true;
	if ((this->_posX[0] == this->_foodX && this->_posY[0] == this->_foodY) || f == 1)
	{
		this->_score++;
		increase_speed();
		this->_snakeLen++;
		if (this->_snakeLen > MAX)
			this->_snakeLen = MAX;
		this->_food = true;
	}
}

void	Game::change_lib(int number)
{
	void*	gl_library = NULL;
	if (number == 1)
		gl_library = dlopen("libft_1.so", RTLD_NOW | RTLD_GLOBAL);
	else if (number == 2)
		gl_library = dlopen("libft_2.so", RTLD_NOW | RTLD_GLOBAL);
	else if (number == 3)
		gl_library = dlopen("libft_3.so", RTLD_NOW | RTLD_GLOBAL);

	if (gl_library == NULL)
	{
		std::cout << "Error with Library " << number << ": " << dlerror() << std::endl;
	}
	else
	{
		this->lib_draw_food = reinterpret_cast<print_t>(dlsym(gl_library, "lib_draw_food"));
		if (lib_draw_food == NULL)
			std::cout << "Error: " << dlerror() << std::endl;
		this->drawBlock = reinterpret_cast<drawBlock_t>(dlsym(gl_library, "drawBlock"));
		if (drawBlock == NULL)
			std::cout << "Error: " << dlerror() << std::endl;
		this->lib_draw_snake = reinterpret_cast<lib_draw_snake_t>(dlsym(gl_library, "lib_draw_snake"));
		if (lib_draw_snake == NULL)
			std::cout << "Error: " << dlerror() << std::endl;
	}
	return ;
}