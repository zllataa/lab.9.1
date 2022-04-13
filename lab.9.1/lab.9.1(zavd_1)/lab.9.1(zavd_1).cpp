#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці
using namespace std;

enum Specialyty { CS, INFORM, MATHandECONOM, PHISYCSandINFORM, WORKTRAINING }; 
                 // КОМПЮТЕРНІ НАУКИ, ІНФОРМАТИКА, МАТЕМАТИКА І ЕКОНОМІКА, ФІЗИКА І ІНФОРМАТИКА, ТРУДОВЕ НАВЧАННЯ

string specialytyStr[] = { "КОМПЮТЕРНІ НАУКИ", "ІНФОРМАТИКА", "МАТЕМАТИКА І ЕКОНОМІКА", "ФІЗИКА І ІНФОРМАТИКА", "ТРУДОВЕ НАВЧАННЯ" };

struct Student
{
    string lastName;
    int course;
    Specialyty specialyty;
    int markPHISICS;
    int markMATH;
    union 
    {
        int markPROGRAMMING;
        int markNUMERICALMETHODS;
        int markPEDAGOGICS;
    };
};

void Create(Student *s, const int N);
void Print(Student *s, const int N);
double LineSearch(Student *s, const int N);
double LineSearch1(Student* s, const int N);

int main()
{
    SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
    int N;
    cout << "Введіть к-сть студентів: "; cin >> N;
    Student* s = new Student[N];
    Create(s, N);
    Print(s, N);
    cout << endl;
    double percent = LineSearch(s, N);
    cout << endl;
    cout << " Процент студентів, які вчаться без трійок (на “відмінно” і “добре”): " << percent << "%" << endl;
    cout << endl;
    LineSearch1(s, N);
    return 0;
}

void Create(Student* s, const int N)
{
    int specialyty;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();
        cout << " Прізвище: "; getline(cin, s[i].lastName);
        cout << " Курс: "; cin >> s[i].course;
        cout << " Спеціальність(0 - КОМПЮТЕРНІ НАУКИ, 1 - ІНФОРМАТИКА, 2 - МАТЕМАТИКА І ЕКОНОМІКА, 3 - ФІЗИКА І ІНФОРМАТИКА, 4 - ТРУДОВЕ НАВЧАННЯ): ";
        cin >> specialyty;
        s[i].specialyty = (Specialyty)specialyty;
        cout << " Оцінка з фізики: "; cin >> s[i].markPHISICS;
        cout << " Оцінка з математики: "; cin >> s[i].markMATH;
        switch (s[i].specialyty)
        {
        case CS:
            cout << " Оцінка з програмування: "; cin >> s[i].markPROGRAMMING;
            break;
        case INFORM:
            cout << " Оцінка з чисельних методів: "; cin >> s[i].markNUMERICALMETHODS;
            break;
        case MATHandECONOM:
            cout << " Оцінка з педагогіки: "; cin >> s[i].markPEDAGOGICS;
            break;
        case PHISYCSandINFORM:
            cout << " Оцінка з педагогіки: "; cin >> s[i].markPEDAGOGICS;
            break;
        case WORKTRAINING:
            cout << " Оцінка з педагогіки: "; cin >> s[i].markPEDAGOGICS;
            break;
        }
        cout << endl;
    }
}
void Print(Student* s, const int N)
{
    cout << "                                                                                                                                                    " << endl;
    cout << "                                                                                                                                                    " << endl;
    cout << "                                                        Рівень В) – дев’ять клітинок:                                                               " << endl;
    cout << "                              (1) – порядковий номер студента у групі, (2) – прізвище, (3) – курс,(4) – спеціальність,                              " << endl;
    cout << "                    оцінки з (5) – фізики, (6) – математики (клітинки цих оцінок заповнені для студентів всіх спеціальностей),                      " << endl;
    cout << "                                      оцінки з (7) – програмування, (8) – чисельних методів, (9) – педагогіки                                       " << endl;
    cout << "                              (заповнена лише одна з клітинок цих оцінок – залежно від спеціальності такого студента).                              " << endl;
    cout << "                                                                                                                                                    " << endl;
    cout << "  ================================================================================================================================================  " << endl;
    cout << " |   |                  |      |                                 |                                       Оцінка                                   | " << endl;
    cout << " | № |     Прізвище     | Курс |          Спеціальність          |--------------------------------------------------------------------------------| " << endl;
    cout << " |   |                  |      |                                 | з фізики | з математики | з програмування | з чисельних методів | з педагогіки | " << endl;
    cout << "  ================================================================================================================================================  " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << " | " << right << i + 1 << " ";
        cout << "| " << setw(16) << left << s[i].lastName << " "
            << "| " << setw(4) << right << s[i].course << " "
            << "| " << setw(31) << left << specialytyStr[s[i].specialyty] << " ";
        cout << "| " << setw(8) << right << s[i].markPHISICS << " "
            << "| " << setw(12) << right << s[i].markMATH << " ";
        switch (s[i].specialyty)
        {
        case CS:
            cout << "| " << setw(15) << right << s[i].markPROGRAMMING << " |                     |              |" << endl;
            break;
        case INFORM:
            cout << "|                 | " << setw(19) << right << s[i].markNUMERICALMETHODS << " |              |" << endl;
            break;
        case MATHandECONOM:
            cout << "|                 |                     |" << setw(13) << right << s[i].markPEDAGOGICS << " |" << endl;
            break;
        case PHISYCSandINFORM:
            cout << "|                 |                     |" << setw(13) << right << s[i].markPEDAGOGICS << " |" << endl;
            break;
        case WORKTRAINING:
            cout << "|                 |                     |" << setw(13) << right << s[i].markPEDAGOGICS << " |" << endl;
            break;
        }
    }
    cout << "  ================================================================================================================================================  " << endl;
    cout << endl;
}

double LineSearch(Student* s, const int N)
{
    cout << " Прізвища студентів, які вчаться без трійок (на “відмінно” і “добре”):" << endl;
    int k = 0; // к-сть студентів які вчаться без трійок (на “відмінно” і “добре”)
    for (int i = 0; i < N; i++)
    {
        if (
            (s[i].markPHISICS > 3)
            &&
            (s[i].markMATH > 3)
            &&
            (s[i].markPROGRAMMING > 3)
            &&
            (s[i].markNUMERICALMETHODS > 3)
            &&
            (s[i].markPEDAGOGICS > 3)
            )
        {
            k++;
            cout << "   " << right << s[i].lastName << endl;
        }
    }
    return 100.0 * k / N;
}

double LineSearch1(Student* s, const int N)
{
    cout << " Прізвища студентів, які отримали з фізики оцінки “5” або “4”:" << endl;
    for (int i = 0; i < N; i++)
    {
        if ((s[i].markPHISICS == 4) || (s[i].markPHISICS == 5))
        {
            cout << "   " << right << s[i].lastName << endl;
        }
    }
    return 0;
}