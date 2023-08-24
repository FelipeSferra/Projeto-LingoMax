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
void menuLanguages();
void menuExercises();
void menuLessons();

// Protótipos de função

void includeUser();
void deleteUser();
void rearrangeUser();
void exhaustiveUser();
bool searchUser();
void indexUser();

void includeLanguage();
void deleteLanguage();
void rearrangeLanguage();
void exhaustiveLanguage();
bool searchLanguage();
void indexLanguage();

void includeExercise();
void deleteExercise();
void rearrangeExercise();
void exhaustiveExercise();
bool searchExercise();
void indexExercise();

void includeLesson();
void deleteLesson();
void rearrangeLesson();
void exhaustiveLesson();
bool searchLesson();
void indexLesson();

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

void menuUsers()
{
    int op = 999;

    while (op != 0)
    {
        system("cls");
        cout << "\t\tMenu Usuários - LingoMax\n\n";
        cout << "[01] - Incluir Usuário\n";
        cout << "[02] - Excluir Usuário\n";
        cout << "[03] - Reorganizar Tabela\n";
        cout << "[04] - Leitura Exaustiva\n";
        cout << "[00] - Voltar para o menu principal\n";
        cout << "Digite a opção desejada: ";
        cin >> op;

        switch (op)
        {
        case 1:
            includeUser();
            break;
        case 2:
            deleteUser();
            break;
        case 3:
            rearrangeUser();
            break;
        case 4:
            exhaustiveUser();
            break;
        case 0:
            break;
        default:
            cout << "Opção inválida!\n";
            system("pause");
        }
    }
}

void menuLanguages() {}
void menuExercises() {}
void menuLessons() {}