#include <iostream>
#include <conio.h>


const int width = 25;
const int height = 20;
int x = width / 2;
int y = height / 2;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;



void move_figure()

{
  switch (dir)
   {
    case UP:
      if (y != 0)
      {
        y --;
      }
      break;
    case DOWN:
      if (y != 19)
      {
        y ++;
      }

      break;
    case LEFT:
      if (x != 1)
      {
        x --;
      }
      break;
    case RIGHT:
      if (x != 23)
      {
        x ++;
      }
      break;
  }
}


void get_key_state()
{
  switch(getch())
  {
    case 'a':
      dir = LEFT;
      break;
    case 'w':
      dir = UP;
      break;
    case 's':
      dir = DOWN;
      break;
    case 'd':
      dir = RIGHT;
      break;
  }
}

void draw_the_map()
{
  system("clear");
  for (int i = 0; i < width; i++)
  {
    std::cout << "#";
  }
  std::cout << std::endl;
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (j == 0 || j == width - 1)
      {
        std::cout << "|";
      }
      else if (j == x && i == y)
      {
        std::cout << "@";
      }
      else
      {
        std::cout << " ";
      }
    }
    std::cout << std::endl;
  }
  for (int i = 0; i < width; i++)
  {
    std::cout << "#";
  }
}


int main()
{
  while (true)
  {
    get_key_state();
    move_figure();
    draw_the_map();

  }
}
