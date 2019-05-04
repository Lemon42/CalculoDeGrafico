#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

//Mudar Cor
enum DOS_COLORS {
        BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
        LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
        LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE };

void textcolor (DOS_COLORS iColor)
{
        HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
        BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
        bufferInfo.wAttributes &= 0x00F0;
        SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

// Funções
void introducao()
{	
	textcolor(YELLOW);

	cout << "\n ******************************\n";
	cout << " ** C\240lculo da Lei da Fun\207\706o **\n";
	cout << " ******************************\n\n";
	
	textcolor(WHITE);
	cout << " <vers\706o 1.6.4> Ultra Version";
}

void getDados(double *pontoX1, double *pontoY1, double *pontoX2, double *pontoY2)
{
	cout << "- Digite os Dados do Ponto 1\n\n";
	cout << "	X: ";
	cin >> *pontoX1;
	cout << "	Y: ";
	cin >> *pontoY1;
	
	cout << "\n- Digite os Dados do Ponto 2\n\n";
	cout << "	X: ";
	cin >> *pontoX2;
	cout << "	Y: ";
	cin >> *pontoY2;
}

bool continua(double pontoX1, double pontoY1, double pontoX2, double pontoY2)
{
	
	if(pontoX1 == 0 && pontoY1 == 0 && pontoX2 == 0 && pontoY2 == 0)
	{
		return false;
	} else {
		return true;
	}
}

void funcCalc(double pontoX1, double pontoY1, double pontoX2, double pontoY2)
{	
	double x1, y1, x2, y2, a, b, rX, rY, rXA, yI;
	
	x1 = pontoX1 * (-1);
	y1 = pontoY1 * (-1);
	x2 = pontoX2;
	y2 = pontoY2;
	rX =  (x1) + (x2);
	rY = (y1) + (y2);
	a = rY / rX;
	yI = rX * (-1);
	rXA = (x1) * (a); 
	b = (rXA) + (pontoY1);
	
	textcolor(GREEN);
	cout << "\n\nCalculando . . .";
	
	cout << "\n\n	Ponto 1( "<< pontoX1 << ", "<< pontoY1 <<") Ponto 2( "<< pontoX2 << ", "<< pontoY2 <<")\n\n";
	
	textcolor(LIGHT_GREEN);
	cout << "|" << pontoY1 << " = " << pontoX1 << "a + b";
	cout << "	--> |" << pontoX1 << "a + b = " << pontoY1 << " .(-1)\n";
	
	cout << "|" << pontoY2 << " = " << pontoX2 << "a + b";
	cout << "	--> |" << pontoX2 << "a + b = " << pontoY2 << "\n\n";
	
	cout << "| " << x1 << "a - b = " << y1 << endl;
	cout << "| " << x2 << "a + b = " << y2;
	
	cout << "\n\n" << rX << "a = " << rY;
	cout << "\na = " << rY << "/" << rX;
	textcolor(LIGHT_RED);
	cout << "\nA = " << a;
	textcolor(LIGHT_GREEN);
	
	cout << "\n\n" << pontoY1 << " = " << x1 << "."<< a << " + b";
	cout << "\n" << pontoY1 << " = " << rXA << " + b";
	cout << "\nb = " << rXA << " + " << pontoY1;
	textcolor(LIGHT_RED);
	cout << "\nB = " << b;
	
	textcolor(RED);
	cout << "\n\nRESULTADO: ";
	
	textcolor(LIGHT_RED);
	if (a == 0)
	{	
		cout << "Y = " << b;
	} else if (b == 0)
	{
		cout << "Y = " << a << "X ";
	} else if (b<0)
	{
		cout << "Y = " << a << "X " << b;
	}
	else {

		cout << "Y = " << a << "X + " << b;
	}
	
	textcolor(WHITE);
	cout << "\n[" << pontoX1 << "," << pontoX2 << "]";
}

int main()
{	
	// Variaveis
	double pontoX1, pontoY1, pontoX2, pontoY2;
	bool flag = true;

	introducao();
	
	while(flag == true)
	{	
		textcolor(YELLOW);
		cout << "\n\n<---------------------->\n\n";	
		textcolor(WHITE);	
		getDados(&pontoX1, &pontoY1, &pontoX2, &pontoY2);
		flag = continua(pontoX1, pontoY1, pontoX2, pontoY2);
		
		if(flag == true)
		{
			funcCalc(pontoX1, pontoY1, pontoX2, pontoY2);
		}
	}	
}
