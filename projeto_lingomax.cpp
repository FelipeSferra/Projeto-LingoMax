/*
    Projeto LingoMax - Algoritmos e estruturas de dados

    Nome: Felipe Sferra de Oliveira
    RA: 2211600147
    Curso: 2º BCC - T1
*/

#include <iostream>
#include <string.h>
#include <windows.h>
#include <conio.h>

using namespace std;

// Structs

struct Index
{
    int cod;
    int address;
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

struct Languages
{
    int cod;
    char desc[40];
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

struct Lessons
{
    int cod_lesson;
    int cod_language;
    int total_levels;
    int D_E_L_E_T_E;
};

// Protótipos de função

void menuUsers(Users *, Index *, Languages *, Index *, int &, int &);
void menuLanguages(Languages *, Index *, int &);
void menuExercises(/* Exercises *, int & */);
void menuLessons(/* Lessons *, int & */);

void readUser(Users *, Index *, int &);
void autoIndexUser(Index *, Users *, int);
void printIndexUser(Index *, Users *, int);
void includeUser(Users *, Index *, Languages *, Index *, int &, int &);
void deleteUser(Users *, Index *, Languages *, Index *, int &, int &);
void rearrangeUser(Users *, Index *, int &);
void exhaustiveUser(Index *, Users *, Languages *, Index *, int, int);
bool searchUser(Index *, int, int &, int);

void readLanguage(Languages *, Index *, int &);
void autoIndexLanguage(Index *, Languages *, int);
void printIndexLanguage(Index *, int);
void includeLanguage(Languages *, Index *, int &);
void deleteLanguage();
void rearrangeLanguage();
void exhaustiveLanguage();
bool searchLanguage(Index *, int, int &, int);
void searchLanguageCod(Languages *, Index *, int, int, char *);

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

    // Usuários

    Index idxUser[20];
    Users u[20];
    int contUser = 3;

    u[0].cod = 12;
    strcpy(u[0].name, "Luan");
    u[0].language = 3;
    u[0].current_level = 10;
    u[0].total_score = 1025;
    u[0].D_E_L_E_T_E = 0;

    u[1].cod = 45;
    strcpy(u[1].name, "Paulo");
    u[1].language = 2;
    u[1].current_level = 5;
    u[1].total_score = 550;
    u[1].D_E_L_E_T_E = 0;

    u[2].cod = 23;
    strcpy(u[2].name, "Ricardo");
    u[2].language = 1;
    u[2].current_level = 15;
    u[2].total_score = 1530;
    u[2].D_E_L_E_T_E = 0;

    autoIndexUser(idxUser, u, contUser);

    // Idiomas

    Index idxLanguage[20];
    Languages l[20];
    int contLanguage = 3;

    l[0].cod = 2;
    strcpy(l[0].desc, "Inglês");
    l[0].D_E_L_E_T_E = 0;

    l[1].cod = 3;
    strcpy(l[1].desc, "Japonês");
    l[1].D_E_L_E_T_E = 0;

    l[2].cod = 1;
    strcpy(l[2].desc, "Espanhol");
    l[2].D_E_L_E_T_E = 0;

    autoIndexLanguage(idxLanguage, l, contLanguage);

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
            menuUsers(u, idxUser, l, idxLanguage, contLanguage, contUser);
            break;
        case 2:
            menuLanguages(l, idxLanguage, contLanguage);
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
            cout << "\n\nOpção inválida!\n\n";
            getch();
        }
    }

    SetConsoleOutputCP(CPAGE_DEFAULT);
}

// Menus

void menuUsers(Users *u, Index *idx, Languages *l, Index *idxL, int &contL, int &cont)
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
        cout << "[05] - Leitura Exaustiva\n";
        cout << "[06] - Reorganizar Lista\n";
        cout << "[00] - Voltar para o menu principal\n";
        cout << "Digite a opção desejada: ";
        cin >> op;
        cin.ignore();

        switch (op)
        {
        case 1:
            readUser(u, idx, cont);
            break;
        case 2:
            printIndexUser(idx, u, cont);
            break;
        case 3:
            includeUser(u, idx, l, idxL, contL, cont);
            break;
        case 4:
            deleteUser(u, idx, l, idxL, contL, cont);
            break;
        case 5:
            exhaustiveUser(idx, u, l, idxL, contL, cont);
            break;
        case 6:
            rearrangeUser(u, idx, cont);
            break;
        case 0:
            break;
        default:
            cout << "\n\nOpção inválida!\n\n";
            getch();
        }
    }
}

void menuLanguages(Languages *l, Index *idx, int &cont)
{
    int op = 999;

    while (op != 0)
    {
        system("cls");
        cout << "\t\tMenu Idiomas - LingoMax\n\n";
        cout << "[01] - Leitura de Idioma\n";
        cout << "[02] - Imprimir Índices\n";
        cout << "[03] - Incluir Idioma\n";
        cout << "[04] - Excluir Idioma\n";
        cout << "[05] - Reorganizar Tabela\n";
        cout << "[06] - Leitura Exaustiva\n";
        cout << "[00] - Voltar para o menu principal\n";
        cout << "Digite a opção desejada: ";
        cin >> op;

        switch (op)
        {
        case 1:
            readLanguage(l, idx, cont);
            break;
        case 2:
            printIndexLanguage(idx, cont);
            break;
        case 3:
            includeLanguage(l, idx, cont);
            break;
        case 4:
            // deleteLanguage();
            break;
        case 5:
            // rearrangeLanguage();
            break;
        case 6:
            // exhaustiveLanguage();
            break;
        case 0:
            break;
        default:
            cout << "\n\nOpção inválida!\n\n";
            getch();
        }
    }
}

void menuExercises() {}
void menuLessons() {}

// Funções

// Usuários

void readUser(Users *u, Index *idx, int &cont)
{
    system("cls");
    int i = 0;

    cout << "\t\tLeitura de Usuário\n\n";

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

    autoIndexUser(idx, u, cont);
}

void autoIndexUser(Index *idx, Users *u, int cont)
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

void printIndexUser(Index *idx, Users *u, int cont)
{
    system("cls");
    cout << "\t\tImpressão de Índices da tabela de Usuários\n\n";

    hr();

    if (cont <= 0)
    {
        cout << "\n\t\tNenhum usuário cadastrado\n\n";
        hr();
    }
    else
    {
        for (int i = 0; i < cont; i++)
        {
            int j = idx[i].address;
            cout << "Código do Índice: " << idx[i].cod << endl;
            cout << "Endereço físico do Usuário: " << idx[i].address << endl;

            if (u[j].D_E_L_E_T_E == 1)
                cout << "--| Marcado na lista de exclusão |--" << endl;

            hr();
        }
    }
    cout << endl;

    getch();
}

void includeUser(Users *u, Index *idx, Languages *l, Index *idxL, int &contL, int &cont)
{
    system("cls");
    int pos;

    cout << "\t\tInclusão de usuário\n\n";
    for (int searchCode = 9; searchCode != 0;)
    {
        cout << "\n\nInforme o código do usuário que deseja incluir (digite 0 para sair): ";
        cin >> searchCode;
        cin.ignore();
        if (searchUser(idx, cont, pos, searchCode))
        {
            char desc[40];
            pos = idx[pos].address;
            if (u[pos].D_E_L_E_T_E == 1)
            {
                searchLanguageCod(l, idxL, contL, u[pos].language, desc);

                cout << "\nUsuário na lista de Exclusão!\n\n";
                cout << "Para usar esse código novamente reorganize a lista.\n\n";
                hr();
                cout << "\nCódigo do usuário: " << u[pos].cod << endl;
                cout << "\tNome: " << u[pos].name << endl;
                cout << "\tIdioma: " << desc << endl;
                cout << "\tNível atual: " << u[pos].current_level << endl;
                cout << "\tPontuação: " << u[pos].total_score << "\n\n";
                hr();
            }
            else
            {
                searchLanguageCod(l, idxL, contL, u[pos].language, desc);

                cout << "\nUsuário já cadastrado - não pode ser cadastrado novamente!\n\n";
                hr();
                cout << "\nCódigo do usuário: " << u[pos].cod << endl;
                cout << "\tNome: " << u[pos].name << endl;
                cout << "\tIdioma: " << desc << endl;
                cout << "\tNível atual: " << u[pos].current_level << endl;
                cout << "\tPontuação: " << u[pos].total_score << "\n\n";
                hr();
            }
        }
        else if (searchCode != 0)
        {
            u[cont].cod = searchCode;
            cout << "\nNome: ";
            gets(u[cont].name);
            u[cont].language = 0;
            u[cont].current_level = 0;
            u[cont].total_score = 0;
            u[cont].D_E_L_E_T_E = 0;

            cont++;

            autoIndexUser(idx, u, cont);

            cout << "\n\nInclusão realizada com sucesso\n\n";
        }
    }
}

void deleteUser(Users *u, Index *idx, Languages *l, Index *idxL, int &contL, int &cont)
{
    system("cls");
    int pos;
    cout << "\t\tExclusão de usuário\n\n";
    for (int searchCode = 9; searchCode != 0;)
    {
        cout << "\n\nInforme o código do usuário que deseja excluir (digite 0 para sair): ";
        cin >> searchCode;
        cin.ignore();
        if (searchUser(idx, cont, pos, searchCode))
        {
            char desc[40];
            pos = idx[pos].address;
            searchLanguageCod(l, idxL, contL, u[pos].language, desc);

            cout << "\nDados do usuário que será excluído: \n\n";
            hr();
            cout << "\nNome: " << u[pos].name << endl;
            cout << "\tIdioma: " << desc << endl;
            cout << "\tNível atual: " << u[pos].current_level << endl;
            cout << "\tPontuação: " << u[pos].total_score << "\n\n";
            hr();

            u[pos].D_E_L_E_T_E = 1;

            cout << "\n\nUsuário excluído com sucesso\n\n";
        }
        else if (searchCode != 0)
        {
            cout << "\n\nUsuário não cadastrado\n\n";
        }
    }
}

void rearrangeUser(Users *u, Index *idx, int &cont)
{
    int j = -1;
    Users auxU[20];
    Index auxIdx[20];

    cout << "\n\n\t\tReorganizando Lista...\n\n";
    
    for (int k = 0; k < cont; k++)
    {
        int i = idx[k].address;

        if (u[i].D_E_L_E_T_E == 0)
        {
            j++;

            auxU[j].cod = u[i].cod;
            strcpy(auxU[j].name, u[i].name);
            auxU[j].language = u[i].language;
            auxU[j].current_level = u[i].current_level;
            auxU[j].total_score = u[i].total_score;
            auxU[j].D_E_L_E_T_E = 0;
            auxIdx[j].cod = auxU[j].cod;
            auxIdx[j].address = j;
        }
    }
    for (int i = 0; i <= j; i++)
    {
        idx[i] = auxIdx[i];
        u[i] = auxU[i];
    }

    cont = j + 1;
    Sleep(3000);
}

void exhaustiveUser(Index *idx, Users *u, Languages *l, Index *idxL, int contL, int cont)
{
    system("cls");

    char desc[40];
    cout << "\t\tLeitura exaustiva dos usuários\n\n";

    hr();
    for (int k = 0; k < cont; k++)
    {
        int i = idx[k].address;
        if (u[i].D_E_L_E_T_E == 0)
        {
            searchLanguageCod(l, idxL, contL, u[i].language, desc);
            cout << "\nCódigo do usuário: " << u[i].cod << endl;
            cout << "\tNome: " << u[i].name << endl;
            cout << "\tIdioma: " << desc << endl;
            cout << "\tNível atual: " << u[i].current_level << endl;
            cout << "\tPontuação: " << u[i].total_score << "\n\n";
            hr();
        }
    }
    getch();
}

bool searchUser(Index *idx, int cont, int &pos, int cod)
{
    int i = 0;
    int f = cont;
    int m = (i + f) / 2;

    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2)
    {
        if (cod > idx[m].cod)
        {
            i = m + 1;
        }
        else
        {
            f = m - 1;
        }
    }
    if (cod == idx[m].cod)
    {
        pos = m;
        return true;
    }

    return false;
}

// Idiomas

void readLanguage(Languages *l, Index *idx, int &cont)
{
    system("cls");
    int i = 0;

    cout << "\n\tLeitura de Idioma\n\n";

    for (int saida = 1; i < 20 && saida != 0; i++)
    {
        cout << "\n\nCódigo do Idioma: ";
        cin >> l[i].cod;
        cin.ignore();
        if (l[i].cod != 0)
        {
            cout << "\nDescrição: ";
            gets(l[i].desc);
            l[i].D_E_L_E_T_E = 0;
        }
        else
            saida = 0;
    }
    cont = i - 1;

    autoIndexLanguage(idx, l, cont);

    cout << "\n\n";

    getch();
}

void autoIndexLanguage(Index *idx, Languages *l, int cont)
{
    int aux, address_aux, i;

    idx[0].cod = l[0].cod;
    idx[0].address = 0;

    for (int j = 1; j < cont; j++)
    {
        aux = l[j].cod;
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

void printIndexLanguage(Index *idx, int cont)
{
    system("cls");
    cout << "\n\tImpressão de Índices da tabela de Idiomas\n";

    hr();

    for (int i = 0; i < cont; i++)
    {
        cout << "Código do Índice: " << idx[i].cod << endl;
        cout << "Endereço físico do Idioma: " << idx[i].address << endl;
        hr();
    }

    cout << endl;

    getch();
}

void includeLanguage(Languages *l, Index *idx, int &cont)
{
    system("cls");
    int pos;
    for (int searchCode = 9; searchCode != 0;)
    {
        cout << "\n\nInforme o código do idioma que deseja incluir (digite 0 para sair): ";
        cin >> searchCode;
        cin.ignore();
        if (searchLanguage(idx, cont, pos, searchCode))
        {
            pos = idx[pos].address;

            cout << "\nIdioma já cadastrado - não pode ser cadastrado novamente!\n\n";
            hr();
            cout << "\nCódigo do idioma: " << l[pos].cod << endl;
            cout << "\tDescrição: " << l[pos].desc << "\n\n";
            hr();
        }
        else if (searchCode != 0)
        {
            l[cont].cod = searchCode;
            cout << "\nDescrição: ";
            gets(l[cont].desc);

            cont++;

            autoIndexLanguage(idx, l, cont);

            cout << "\n\nInclusão realizada com sucesso\n\n";
        }
    }
    getch();
}

bool searchLanguage(Index *idx, int cont, int &pos, int cod)
{
    int i = 0;
    int f = cont;
    int m = (i + f) / 2;

    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2)
    {
        if (cod > idx[m].cod)
        {
            i = m + 1;
        }
        else
        {
            f = m - 1;
        }
    }
    if (cod == idx[m].cod)
    {
        pos = m;
        return true;
    }

    return false;
}

void searchLanguageCod(Languages *l, Index *idx, int cont, int cod, char *desc)
{
    int i = 0;
    int f = cont;
    int m = (i + f) / 2;

    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2)
    {
        if (cod > idx[m].cod)
        {
            i = m + 1;
        }
        else
        {
            f = m - 1;
        }
    }
    if (cod == idx[m].cod)
    {
        i = idx[m].address;
        strcpy(desc, l[i].desc);
    }
    else if (cod == 0)
    {
        strcpy(desc, "Ainda não iniciou os estudos");
    }
    else
    {
        strcpy(desc, "Idioma não cadastrado");
    }
}

void hr()
{
    for (int i = 0; i < 60; i++)
    {
        cout << "-";
    }
    cout << endl;
}