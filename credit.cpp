#include <iostream>
using namespace std;

bool CorrectCard(const char* NumberCard);
void CheckInput(char NumberCard[], const int SIZE_CARD);
void ShowCardNumber(const char NumberCard[], const int SIZE_CARD);

int main()
{
	const int SIZE_CARD = 16;
	char NumberCard[SIZE_CARD + 1]{};

    CheckInput(NumberCard, SIZE_CARD);
    ShowCardNumber(NumberCard, SIZE_CARD);
    cin.clear();

    if (CorrectCard(NumberCard))
        cout << "\nAll is well with your card";
    else
        cout << "\nYou have problems with the card";

	return 0;
}

bool CorrectCard(const char* NumberCard)
{
    int Sum = 0;
    int Size = strlen(NumberCard);
    int Parity = (Size - 1) % 2;
    char ZeroSymb[2] = "\0";

    for (int i = Size; i > 0; i--)
    {
        ZeroSymb[0] = NumberCard[i - 1];
        int Digit = atoi(ZeroSymb);

        if (Parity == i % 2)
            Digit = Digit * 2;

        Sum += Digit / 10;
        Sum += Digit % 10;
    }

    return 0 == Sum % 10;
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

void ShowCardNumber(const char NumberCard[], const int SIZE_CARD)
{
    cout << "Your card number\n";
    for (size_t i = 0; i < SIZE_CARD; i++)
    {
        cout << NumberCard[i];

        if (i == 3 || i == 7 || i == 11)
            cout << " ";
    }
}
