#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

struct Start
{
    int x, y;
};

struct Map
{
    int Maxheight, Maxwidth;

    void Loadmap(Start &player1, Start treasure, Start key)
    {
        for (int i = 0; i < Maxheight; i++)
        {
            for (int j = 0; j < Maxwidth; j++)
            {
                if (player1.x == i && player1.y == j)
                {
                    std::cout << "P";
                }
                else if (treasure.x == i && treasure.y == j)
                {
                    std::cout << "-";
                }
                else if (key.x == i && key.y == j)
                {
                    std::cout << "?";
                }
                else if (player1.x == key.x && player1.y == key.y)
                {
                    std::cout << "-";
                }
                else
                {
                    std::cout << "-";
                }

                if (player1.x >= Maxheight)
                {
                    player1.x = 0;
                }
                else if (player1.x < 0)
                {
                    player1.x = Maxheight - 1;
                    // std::cout << "hey";
                }
                if (player1.y >= Maxwidth)
                {
                    player1.y = 0;
                }
                else if (player1.y < 0)
                {
                    player1.y = Maxwidth - 1;
                }
            }

            std::cout << std::endl;
        }
    }
};

struct Playerinput
{
    char Yourchar;

    char GetInput()
    {
        // std::cout << "Welcome adventurer! Can you help find our treasure?" << "\n" << "Enter your name ";
        std::cout << "Choose where to go " << '\n'
                  << "Type: w for north, d for east, s for south, a for west " << '\n';
        std::cin >> Yourchar;

        std::cout << std::endl;

        return Yourchar;
    }
};

int main()
{
    system("cls");
    srand((unsigned)time(0));

    int size = 10;

    Map map;
    map.Maxheight = rand() % size; // rand()10+10 to display array between 10 and 19
    map.Maxwidth = rand() % size;

    Start player1;
    player1.x = rand() % map.Maxheight;
    player1.y = rand() % map.Maxwidth;

    Start treasure;
    treasure.x = rand() % map.Maxheight;
    treasure.y = rand() % map.Maxwidth;

    Start key;
    key.x = rand() % map.Maxheight;
    key.y = rand() % map.Maxwidth;

    Playerinput playermovement;
    char input;

    while (input != 'q')
    {
        float distancetotreasure;

        map.Loadmap(player1, treasure, key);

        input = playermovement.GetInput();

        switch (input)
        {
        case 'w':
        {
            // std::cout << player1.x;
            player1.x -= 1;
            float distancetotreasure = sqrt((pow((player1.x - treasure.x), 2) +
                                             pow((player1.y - treasure.y), 2)));
            std::cout << distancetotreasure << " step to treasure" << '\n';
        }
        break;
        case 'd':
        {
            player1.y += 1;
            float distancetotreasure = sqrt((pow((player1.x - treasure.x), 2) +
                                             pow((player1.y - treasure.y), 2)));
            std::cout << distancetotreasure << " step to treasure" << '\n';
        }
        break;
        case 's':
        {
            player1.x += 1;
            float distancetotreasure = sqrt((pow((player1.x - treasure.x), 2) +
                                             pow((player1.y - treasure.y), 2)));
            std::cout << distancetotreasure << " step to treasure" << '\n';
        }
        break;
        case 'a':
        {
            player1.y -= 1;
            float distancetotreasure = sqrt((pow((player1.x - treasure.x), 2) +
                                             pow((player1.y - treasure.y), 2)));
            std::cout << distancetotreasure << " step to treasure" << '\n';
        }
        break;
        case 'q':
        {
            std::cout << "You quit the game ";
        }
        break;
        default:
        {
            std::cout << "Invalid input" << std::endl;
        }
        }

        if (player1.x == key.x && player1.y == key.y)
        {
            std::cout << "You've found a Key!" << '\n';
            key.x = 50;
            key.y = 50;
        }

        if (player1.x == treasure.x && player1.y == treasure.y)
        {
            std::cout << "Congrats! You've found the treasure!";
            return 'q';
        }
    }
}

/*int main() {

    system("cls");
    string map[10][10] = {{"A1","A2","A3"},  // 2nests 3 elements
                                    {"B1","B2","B3"}};






     for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            std::cout << map[i][j] << std:: endl;
        }
    }//














    int usersPin, pin, errorCounter = 0;
    const int MAX_ERRORS = 3;
    std::cout << "uhh.. where.. am I? ";
    std::cout << "Set your Pin: ";
    std::cin >> usersPin;
    do
    {
        std::cout << "Please Enter Your PIN: ";
        std::cin >> pin;
        errorCounter += 1;
        int T = MAX_ERRORS - errorCounter;
        std::cout << "You have " << T << " tries remaining" << "\n";
    } while (errorCounter < MAX_ERRORS && pin != usersPin);




    if(pin == usersPin){
        std::cout << "Welcome to the system" << "\n";
        int n;
        char c;
        std::cout << " Press B to show balance" <<"\n Press D to deposit" <<"\n Press W to withdraw" <<"\n";
        std::cin >> c;
        switch(c)
    {
        case 'B':{
            std::cout << "You're Broke" <<std::endl;
        }
        break;
        case 'D':{
            std::cout << "How much cash would you like to deposit" <<std::endl;
            std::cin >> n;
            std::cout << n << " pounds was deposited to your acc";
        }
        break;
        case 'W':{
            std::cout << "How much cash would you like to withdraw" <<std::endl;
            std::cin >> n;
            std::cout << n << " pounds was withdrawn from your acc";
        }
    default:{
        std::cout << "Invalid input" <<std::endl;
    }
    }
    }
    else{
        std::cout << "Your account has been blocked";
    }



    return 0;
}*/