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

struct Languages
{
    int cod;
    char desc[40];
};

struct Lessons
{
    int cod_lesson, cod_language, total_levels;
};

struct Exercises
{
    int cod_exerc, difficulty_level, score, answer;
    char desc[60];
};

struct Users
{
    int cod, language, current_level, total_score;
    char name[30];
};

int main()
{
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
