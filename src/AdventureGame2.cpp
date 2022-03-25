#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

struct Start
{
    int row, col;
};

struct Map
{
    int Maxheight, Maxwidth;

    void Loadmap(Start &player, Start treasure, Start enemy)
    {
        char Map[Maxheight][Maxwidth];
        for (int i = 0; i < Maxheight; i++)
        {
            for (int j = 0; j < Maxwidth; j++)
            {
                if (player.row == i && player.col == j)
                {
                    std::cout << "P";
                }
                else if (treasure.row == i && treasure.col == j)
                {
                    std::cout << "X";
                }
                else if (enemy.row == i && enemy.col == j)
                {
                    std::cout << "E";
                }
                else
                {
                    std::cout << char(176);
                }

                if (player.row >= Maxheight)
                {
                    player.row = 0;
                }
                else if (player.row < 0)
                {
                    player.row = Maxheight - 1;
                }
                if (player.col >= Maxwidth)
                {
                    player.col = 0;
                }
                else if (player.col < 0)
                {
                    player.col = Maxwidth - 1;
                }
            }

            std::cout << std::endl;
        }
    }
};

struct Playerinput
{
    std::string YourString;

    char GetInput()
    {
        std::cout << "Move your player using w, a, s, d " << '\n';
        std::cin >> YourString;

        std::cout << std::endl;

        return YourString[0];
    }
};

int main()
{
    system("cls");

    srand((unsigned)time(0));

    std::cout << "Where would you like your adventure to take you? " << std::endl;

    // int enemyHP = 100;

    Map map;
    map.Maxheight = 10;
    map.Maxwidth = 20;

    Start player;
    player.row = rand() % map.Maxwidth;
    player.col = rand() % map.Maxheight;

    Start enemy;
    enemy.row = rand() % map.Maxwidth;
    enemy.col = rand() % map.Maxheight;

    Start treasure;
    treasure.row = rand() % map.Maxwidth;
    treasure.col = rand() % map.Maxheight;

    Playerinput playermovement;
    char input;

    while (input != 'q')
    {

        double distancetotreasure = sqrt((pow(player.row - treasure.row, 2) +
                                          pow(player.col - treasure.col, 2) * 1.0));

        map.Loadmap(player, treasure, enemy);

        input = playermovement.GetInput();
        if (input == 'w')
        {
            player.row -= 1;
            std::cout << "Distance from treasure " << distancetotreasure << " tiles away." << std::endl;
        }
        if (input == 'a')
        {
            player.col -= 1;
            std::cout << "Distance from treasure " << distancetotreasure << " tiles away." << std::endl;
        }
        if (input == 's')
        {
            player.row += 1;
            std::cout << "Distance from treasure " << distancetotreasure << " tiles away." << std::endl;
        }
        if (input == 'd')
        {
            player.col += 1;
            std::cout << "Distance from treasure " << distancetotreasure << " tiles away." << std::endl;
        }

        if (distancetotreasure <= 4 && distancetotreasure >= 3)
        {
            std::cout << "You're getting close, i smell something, actually no it could just be you" << std::endl;
        }
        if (distancetotreasure <= 3)
        {
            std::cout << "No wait, its definitely something, i hope its money" << std::endl;
        }
        if (player.row == enemy.row && player.col == enemy.col)
        {
            std::cout << "wtf enemies?????"
                      << '\n'
                      << "Press z to heavy attack, x to light attack, c to flee (we dont do that here)" << std::endl;
            switch (input)
            {
            case 'z':
            {
                std::cout << "Are you Saitama because you just one punched him" << std::endl;
                break;
            }
            case 'x':
            {
                std::cout << "Why do u want to tickle him, that did nothing" << std::endl;
                break;
            }
            case 'c':
            {
                std::cout << "This had to be an option, go back and fight or forever be called a coward" << std::endl;

                break;
            }
            default:
            {
                std::cout << "Invalid input" << std::endl;
            }
            }
        }
        if (player.row == treasure.row && player.col == treasure.col)
        {
            std::cout << "Congrats! You've found the hidden treasure!";
            return 'q';
        }
    }
}

// insert random enemy using random generator in the array,
// while or if loop when player hits the enemy tile