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
    int D_E_L_E_T_E;
};

struct Lessons
{
    int cod_lesson;
    int cod_language;
    int total_levels;
    int D_E_L_E_T_E;
};

struct Exercises
{
    int cod_exerc;
    int difficulty_level;
    int score;
    int answer;
    char desc[60];
    int D_E_L_E_T_E;
};

struct Users
{
    int cod;
    char name[30];
    int language;
    int current_level;
    int total_score;
    int D_E_L_E_T_E;
};

// Protótipos de função

void menuUsers(Users *, Index *, int &);
void menuLanguages(/* Languages *, int & */);
void menuExercises(/* Exercises *, int & */);
void menuLessons(/* Lessons *, int & */);

void readUser(Users *, Index *, int &);
void autoIndex(Index *, Users *, int);
void printIndex(Index *, int);
void includeUser();
void deleteUser();
void rearrangeUser();
void exhaustiveUser();
bool searchUser();

void readLanguage();
void indexLanguage();
void includeLanguage();
void deleteLanguage();
void rearrangeLanguage();
void exhaustiveLanguage();
bool searchLanguage();

void readExercise();
void indexExercise();
void includeExercise();
void deleteExercise();
void rearrangeExercise();
void exhaustiveExercise();
bool searchExercise();

void readLesson();
void indexLesson();
void includeLesson();
void deleteLesson();
void rearrangeLesson();
void exhaustiveLesson();
bool searchLesson();

void updateScore(Users *, Exercises *, int, int); // Passar resposta do usuário e resposta correta (int,int);

void hr();

// Programa principal

int main()
{
    // Muda linguagem do terminal para PT-BR
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();

    SetConsoleOutputCP(CPAGE_UTF8);

    // Variáveis

    Index idxUser[20];
    Users u[20];
    int contUser;

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
            menuUsers(u, idxUser, contUser);
            break;
        case 2:
            //  menuLanguages();
            break;
        case 3:
            //  menuExercises();
            break;
        case 4:
            // menuLessons();
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

// Menus

void menuUsers(Users *u, Index *idx, int &cont)
{
    int op = 999;

    while (op != 0)
    {
        system("cls");
        cout << "\t\tMenu Usuários - LingoMax\n\n";
        cout << "[01] - Leitura de Usuário\n";
        cout << "[02] - Imprimir Índices\n";
        cout << "[03] - Incluir Usuário\n";
        cout << "[04] - Excluir Usuário\n";
        cout << "[05] - Reorganizar Tabela\n";
        cout << "[06] - Leitura Exaustiva\n";
        cout << "[07] - Buscar Usuário\n";
        cout << "[00] - Voltar para o menu principal\n";
        cout << "Digite a opção desejada: ";
        cin >> op;

        switch (op)
        {
        case 1:
            readUser(u, idx, cont);
            break;
        case 2:
            printIndex(idx, cont);
            break;
        case 3:
            // includeUser();
            break;
        case 4:
            // deleteUser();
            break;
        case 5:
            // rearrangeUser();
            break;
        case 6:
            // exhaustiveUser();
            break;
        case 7:
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

// Funções

void readUser(Users *u, Index *idx, int &cont)
{
    int i = 0;

    cout << "\n\tLeitura de Usuário\n\n";

    for (int saida = 1; i < 20 && saida != 0; i++)
    {
        cout << "\n\nCódigo do Usuário: ";
        cin >> u[i].cod;
        cin.ignore();
        if (u[i].cod != 0)
        {
            cout << "\nNome: ";
            gets(u[i].name);
            u[i].language = 0;
            u[i].current_level = 0;
            u[i].total_score = 0;
            u[i].D_E_L_E_T_E = 0;
        }
        else
            saida = 0;
    }
    cont = i - 1;

    autoIndex(idx, u, cont);

    system("pause");
}

void autoIndex(Index *idx, Users *u, int cont)
{
    int aux, address_aux, i;

    idx[0].cod = u[0].cod;
    idx[0].address = 0;

    for (int j = 1; j < cont; j++)
    {
        aux = u[j].cod;
        address_aux = j;
        i = j - 1;

        for (; i >= 0 && idx[i].cod > aux; i--)
        {
            idx[i + 1].cod = idx[i].cod;
            idx[i + 1].address = idx[i].address;
        }

        idx[i + 1].cod = aux;
        idx[i + 1].address = address_aux;
    }
}

void printIndex(Index *idx, int cont)
{
    cout << "\n\tImpressão de Índices da tabela Usuários\n";

    hr();

    for (int i = 0; i < cont; i++)
    {
        cout << "Código do Índice: " << idx[i].cod << endl;
        cout << "Endereço físico do Usuário: " << idx[i].address << endl;
        hr();
    }

    cout << endl;
    
    system("pause");
}

void hr()
{
    for (int i = 0; i < 60; i++)
    {
        cout << "-";
    }
    cout << endl;
}