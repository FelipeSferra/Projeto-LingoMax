/*
    Projeto LingoMax - Algoritmos e estruturas de dados

    Nome: Felipe Sferra de Oliveira
    RA: 2211600147
    Curso: 2º BCC - T1
*/

#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

// Structs

struct Index
{
    int cod;
    int address;
};

struct Languages
{
    int cod;
    char desc[40];
};

struct Lessons
{
    int cod_lesson;
    int cod_language;
    int total_levels;
};

struct Exercises
{
    int cod_exerc;
    int difficulty_level;
    int score;
    int answer;
    char desc[60];
};

struct Users
{
    int cod, language;
    int current_level;
    int total_score;
    char name[30];
};

// Menus

void menuUsers();
void menuExercises();
void menuLessons();
void menuLanguages();

// Protótipos de função

// Programa principal

int main()
{
    // Muda linguagem do terminal para PT-BR
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();

    SetConsoleOutputCP(CPAGE_UTF8);

    int op = 999;

    while (op != 0)
    {
        system("cls");
        cout << "\t\tMenu Principal - LingoMax\n\n";
        cout << "[01] - Menu Usuários\n";
        cout << "[02] - Menu Idiomas\n";
        cout << "[03] - Menu Exercícios\n";
        cout << "[04] - Menu Lições\n";
        cout << "[00] - Sair\n";
        cout << "Digite a opção desejada: ";
        cin >> op;

        switch (op)
        {
        case 1:
            menuUsers();
            break;
        case 2:
            menuLanguages();
            break;
        case 3:
            menuExercises();
            break;
        case 4:
            menuLessons();
            break;
        case 0:
            system("cls");
            cout << "\n\n\t\tObrigado por usar o programa!\n\n";
            break;
        default:
            cout << "Opção inválida!\n";
            system("pause");
        }
    }

    SetConsoleOutputCP(CPAGE_DEFAULT);
}