#include <iostream> // консоль - cout

class Calculator
{
private:
    double num1, num2;

public:
    Calculator()
    {
        set_num1(1);
        set_num2(1);
    }
    double add() { return num1 + num2; }
    double multiply() { return num1 * num2; }
    double subtract_1_2() { return num1 - num2; }
    double subtract_2_1() { return num2 - num1; }
    double divide_1_2() { return num1 / num2; }
    double divide_2_1() { return num2 / num1; }
    bool set_num1(double num1)
    {
        if (num1 == 0) return false;
        this->num1 = num1;
        return true;
    }
    bool set_num2(double num2)
    {
        if (num2 == 0) return false;
        Calculator::num2 = num2;
        return true;
    }
};

double userInput(const std::string&);

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");   // задаём русский текст
    system("chcp 1251");            // настраиваем кодировку консоли
    std::system("cls");

    std::cout << "Задача 1. Калькулятор двух чисел\n";
    std::cout << "--------------------------------\n";
    
    Calculator calc;    // создаю объект, запускаю конструктор
    bool isGood = true; // флаг состояния сеттера
    
    while (1) // Программа спрашивает пользователя бесконечно, пока он сам не закроет консоль
    {
        std::cout << std::endl;
        do
        {
            isGood = calc.set_num1(userInput("Введите num1: "));
            if (!isGood) std::cout << "Неверный ввод!" << std::endl;
        } while (!isGood);
        do
        {
            isGood = calc.set_num2(userInput("Введите num2: "));
            if (!isGood) std::cout << "Неверный ввод!" << std::endl;
        } while (!isGood);

        std::cout << "----------------" << std::endl
            << "num1 + num2 = " << calc.add() << std::endl
            << "num1 - num2 = " << calc.subtract_1_2() << std::endl
            << "num2 - num1 = " << calc.subtract_2_1() << std::endl
            << "num1 * num2 = " << calc.multiply() << std::endl
            << "num1 / num2 = " << calc.divide_1_2() << std::endl
            << "num2 / num1 = " << calc.divide_2_1() << std::endl;
    }

    return 0;
}


// будет запрашивать у пользователя ввод данных
// пока не будут введены верные данные.
// В случае успеха, вернет double.
// При ошибке ввода, сбросит и очистит cin
// и снова попросит ввести данные
double userInput(const std::string& userText)
{
    double uData = 0;
    bool err = true;

    do
    {
        std::cout << userText; std::cin >> uData;
        
        if (err = std::cin.fail()) std::cin.clear(); // ошибка ввода
        int ch; // поиск и очистка лишних введенных символов
        while ((ch = std::cin.get()) != '\n' && ch != EOF);
    } while (err);

    return uData;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
