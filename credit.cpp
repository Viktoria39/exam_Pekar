#include <iostream>
using namespace std;

void CheckInput(char NumberCard[], const int SIZE_CARD);

int main()
{
	const int SIZE_CARD = 16;
	char NumberCard[SIZE_CARD + 1]{};

    CheckInput(NumberCard, SIZE_CARD);

	return 0;
}

void CheckInput(char NumberCard[], const int SIZE_CARD)
{
    bool exit = true;

    do
    {
        cout << "Enter number card 16 characters\n";
        cin.getline(NumberCard, SIZE_CARD + 1);

        NumberCard[SIZE_CARD] = '\0';

        for (size_t i = 0; i < SIZE_CARD; i++)
        {
            if (NumberCard[i] >= 0 && !(NumberCard[i] > ':') && !(NumberCard[i] < '/'))
            {
                if (i == SIZE_CARD - 1)
                    exit = false;
            }
            else
            {
                cout << "Incorrect input. Please try again\n";
                cin.clear();
                while (cin.get() != '\n');
                break;
            }
        }
    } while (exit);
}
