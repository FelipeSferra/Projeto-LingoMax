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
    int status;
};

struct Languages
{
    int cod;
    char desc[40];
    int status;
};

struct Exercises
{
    int cod;
    char desc[120];
    int difficulty_level;
    int score;
    char answer[30];
    int language;
    int status;
};

struct Lessons
{
    int cod;
    int total_levels;
    int language;
    int status;
};

// Protótipos de função

void menuUsers(Users *, Index *, Languages *, Index *, int &, int &);
void menuLanguages(Languages *, Index *, int &);
void menuExercises(Exercises *, Index *, Languages *, Index *, int &, int);
void menuLessons(Lessons *, Index *, Languages *, Index *, int, int &);

void readUser(Users *, Index *, int &);
void autoIndexUser(Index *, Users *, int);
void printIndexUser(Index *, Users *, int);
void includeUser(Users *, Index *, Languages *, Index *, int &, int &);
void deleteUser(Users *, Index *, Languages *, Index *, int &, int &);
void rearrangeUser(Users *, Index *, int &);
void exhaustiveUser(Index *, Users *, Languages *, Index *, int, int);

void readLanguage(Languages *, Index *, int &);
void autoIndexLanguage(Index *, Languages *, int);
void printIndexLanguage(Index *, Languages *, int);
void includeLanguage(Languages *, Index *, int &);
void deleteLanguage(Languages *, Index *, int &);
void rearrangeLanguage(Languages *, Index *, int &);
void exhaustiveLanguage(Index *, Languages *, int);
void searchLanguageCod(Languages *, Index *, int, int &, char *, int = 0);

void readExercise(Exercises *, Index *, Languages *, Index *, int &, int);
void autoIndexExercise(Index *, Exercises *, int);
void printIndexExercise(Index *, Exercises *, int);
void includeExercise(Exercises *, Index *, Languages *, Index *, int &, int);
void deleteExercise(Exercises *, Index *, Languages *, Index *, int &, int);
void rearrangeExercise(Exercises *, Index *, int &);
void exhaustiveExercise(Index *, Exercises *, Languages *, Index *, int, int);

void readLesson(Lessons *, Index *, Languages *, Index *, int &, int);
void autoIndexLesson(Index *, Lessons *, int);
void printIndexLesson(Index *, Lessons *, int);
void includeLesson(Lessons *, Index *, Languages *, Index *, int &, int);
void deleteLesson(Lessons *, Index *, Languages *, Index *, int &, int);
void rearrangeLesson(Lessons *, Index *, int &);
void exhaustiveLesson(Index *, Lessons *, Languages *, Index *, int, int);

void updateScore(Users *, Exercises *, bool); // Passar resposta do usuário e resposta correta (int,int);

void hr();
bool binarySearch(Index *, int, int &, int);

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
    u[0].status = 0;

    u[1].cod = 45;
    strcpy(u[1].name, "Paulo");
    u[1].language = 2;
    u[1].current_level = 5;
    u[1].total_score = 550;
    u[1].status = 0;

    u[2].cod = 23;
    strcpy(u[2].name, "Ricardo");
    u[2].language = 1;
    u[2].current_level = 15;
    u[2].total_score = 1530;
    u[2].status = 0;

    autoIndexUser(idxUser, u, contUser);

    // Idiomas

    Index idxLanguage[20];
    Languages l[20];
    int contLanguage = 3;

    l[0].cod = 2;
    strcpy(l[0].desc, "Inglês");
    l[0].status = 0;

    l[1].cod = 3;
    strcpy(l[1].desc, "Japonês");
    l[1].status = 0;

    l[2].cod = 1;
    strcpy(l[2].desc, "Espanhol");
    l[2].status = 0;

    autoIndexLanguage(idxLanguage, l, contLanguage);

    // Exercícios

    Index idxExercise[20];
    Exercises e[20];
    int contExercise = 3;

    e[0].cod = 65;
    e[0].difficulty_level = 2;
    e[0].score = 30;
    strcpy(e[0].answer, "teste1");
    strcpy(e[0].desc, "Isso é um exercicio teste1");
    e[0].language = 1;
    e[0].status = 0;

    e[1].cod = 23;
    e[1].difficulty_level = 1;
    e[1].score = 15;
    strcpy(e[1].answer, "teste2");
    strcpy(e[1].desc, "Isso é um exercicio teste2");
    e[1].language = 3;
    e[1].status = 0;

    e[2].cod = 78;
    e[2].difficulty_level = 5;
    e[2].score = 50;
    strcpy(e[2].answer, "teste3");
    strcpy(e[2].desc, "Isso é um exercicio teste3");
    e[2].language = 2;
    e[2].status = 0;

    autoIndexExercise(idxExercise, e, contExercise);

    // Lições

    Index idxLesson[20];
    Lessons ls[20];
    int contLesson = 3;

    ls[0].cod = 1;
    ls[0].total_levels = 3;
    ls[0].language = 2;
    ls[0].status = 0;

    ls[1].cod = 2;
    ls[1].total_levels = 3;
    ls[1].language = 3;
    ls[1].status = 0;

    ls[2].cod = 3;
    ls[2].total_levels = 3;
    ls[2].language = 1;
    ls[2].status = 0;

    autoIndexLesson(idxLesson, ls, contLesson);

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
            menuExercises(e, idxExercise, l, idxLanguage, contExercise, contLanguage);
            break;
        case 4:
            menuLessons(ls, idxLesson, l, idxLanguage, contLanguage, contLesson);
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
        cout << "[05] - Leitura Exaustiva\n";
        cout << "[06] - Reorganizar Lista\n";
        cout << "[00] - Voltar para o menu principal\n";
        cout << "Digite a opção desejada: ";
        cin >> op;

        switch (op)
        {
        case 1:
            readLanguage(l, idx, cont);
            break;
        case 2:
            printIndexLanguage(idx, l, cont);
            break;
        case 3:
            includeLanguage(l, idx, cont);
            break;
        case 4:
            deleteLanguage(l, idx, cont);
            break;
        case 5:
            exhaustiveLanguage(idx, l, cont);
            break;
        case 6:
            rearrangeLanguage(l, idx, cont);
            break;
        case 0:
            break;
        default:
            cout << "\n\nOpção inválida!\n\n";
            getch();
        }
    }
}

void menuExercises(Exercises *e, Index *idx, Languages *l, Index *idxL, int &cont, int contL)
{
    int op = 999;

    while (op != 0)
    {
        system("cls");
        cout << "\t\tMenu Exercícios - LingoMax\n\n";
        cout << "[01] - Leitura de Exercício\n";
        cout << "[02] - Imprimir Índices\n";
        cout << "[03] - Incluir Exercício\n";
        cout << "[04] - Excluir Exercício\n";
        cout << "[05] - Leitura Exaustiva\n";
        cout << "[06] - Reorganizar Lista\n";
        cout << "[00] - Voltar para o menu principal\n";
        cout << "Digite a opção desejada: ";
        cin >> op;

        switch (op)
        {
        case 1:
            readExercise(e, idx, l, idxL, cont, contL);
            break;
        case 2:
            printIndexExercise(idx, e, cont);
            break;
        case 3:
            includeExercise(e, idx, l, idxL, cont, contL);
            break;
        case 4:
            deleteExercise(e, idx, l, idxL, cont, contL);
            break;
        case 5:
            exhaustiveExercise(idx, e, l, idxL, cont, contL);
            break;
        case 6:
            rearrangeExercise(e, idx, cont);
            break;
        case 0:
            break;
        default:
            cout << "\n\nOpção inválida!\n\n";
            getch();
        }
    }
}

void menuLessons(Lessons *ls, Index *idx, Languages *l, Index *idxL, int contL, int &cont)
{
    int op = 999;

    while (op != 0)
    {
        system("cls");
        cout << "\t\tMenu Lições - LingoMax\n\n";
        cout << "[01] - Leitura de Lição\n";
        cout << "[02] - Imprimir Índices\n";
        cout << "[03] - Incluir Lição\n";
        cout << "[04] - Excluir Lição\n";
        cout << "[05] - Leitura Exaustiva\n";
        cout << "[06] - Reorganizar Lista\n";
        cout << "[00] - Voltar para o menu principal\n";
        cout << "Digite a opção desejada: ";
        cin >> op;
        cin.ignore();

        switch (op)
        {
        case 1:
            readLesson(ls, idx, l, idxL, cont, contL);
            break;
        case 2:
            printIndexLesson(idx, ls, cont);
            break;
        case 3:
            includeLesson(ls, idx, l, idxL, cont, contL);
            break;
        case 4:
            deleteLesson(ls, idx, l, idxL, cont, contL);
            break;
        case 5:
            exhaustiveLesson(idx, ls, l, idxL, cont, contL);
            break;
        case 6:
            rearrangeLesson(ls, idx, cont);
            break;
        case 0:
            break;
        default:
            cout << "\n\nOpção inválida!\n\n";
            getch();
        }
    }
}

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
            u[i].status = 0;
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

            if (u[j].status == 1)
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
        if (binarySearch(idx, cont, pos, searchCode))
        {
            char desc[40];
            pos = idx[pos].address;
            if (u[pos].status == 1)
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
            u[cont].status = 0;

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
        if (binarySearch(idx, cont, pos, searchCode))
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

            u[pos].status = 1;

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

        if (u[i].status == 0)
        {
            j++;

            auxU[j].cod = u[i].cod;
            strcpy(auxU[j].name, u[i].name);
            auxU[j].language = u[i].language;
            auxU[j].current_level = u[i].current_level;
            auxU[j].total_score = u[i].total_score;
            auxU[j].status = 0;
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
        if (u[i].status == 0)
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
            l[i].status = 0;
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

void printIndexLanguage(Index *idx, Languages *l, int cont)
{
    system("cls");
    cout << "\n\tImpressão de Índices da tabela de Idiomas\n";

    hr();

    if (cont <= 0)
    {
        cout << "\n\t\tNenhum idioma cadastrado\n\n";
        hr();
    }
    else
    {
        for (int i = 0; i < cont; i++)
        {
            int j = idx[i].address;
            cout << "Código do Índice: " << idx[i].cod << endl;
            cout << "Endereço físico do Idioma: " << idx[i].address << endl;

            if (l[j].status == 1)
                cout << "--| Marcado na lista de exclusão |--" << endl;

            hr();
        }
    }
    cout << endl;

    getch();
}

void includeLanguage(Languages *l, Index *idx, int &cont)
{
    system("cls");
    int pos;

    cout << "\t\tInclusão de idioma\n\n";

    for (int searchCode = 9; searchCode != 0;)
    {
        cout << "\n\nInforme o código do idioma que deseja incluir (digite 0 para sair): ";
        cin >> searchCode;
        cin.ignore();
        if (binarySearch(idx, cont, pos, searchCode))
        {
            pos = idx[pos].address;
            if (l[pos].status == 1)
            {
                cout << "\nIdioma na lista de Exclusão!\n\n";
                cout << "Para usar esse código novamente reorganize a lista.\n\n";
                hr();
                cout << "\nCódigo do idioma: " << l[pos].cod << endl;
                cout << "\tDescrição: " << l[pos].desc << "\n\n";
                hr();
            }
            else
            {
                cout << "\nIdioma já cadastrado - não pode ser cadastrado novamente!\n\n";
                hr();
                cout << "\nCódigo do idioma: " << l[pos].cod << endl;
                cout << "\tDescrição: " << l[pos].desc << "\n\n";
                hr();
            }
        }
        else if (searchCode != 0)
        {
            l[cont].cod = searchCode;
            cout << "\nDescrição: ";
            gets(l[cont].desc);
            l[cont].status = 0;

            cont++;

            autoIndexLanguage(idx, l, cont);

            cout << "\n\nInclusão realizada com sucesso\n\n";
        }
    }
}

void deleteLanguage(Languages *l, Index *idx, int &cont)
{
    system("cls");
    int pos;
    cout << "\t\tExclusão de idioma\n\n";
    for (int searchCode = 9; searchCode != 0;)
    {
        cout << "\n\nInforme o código do idioma que deseja excluir (digite 0 para sair): ";
        cin >> searchCode;
        if (binarySearch(idx, cont, pos, searchCode))
        {
            pos = idx[pos].address;

            cout << "\nDados do idioma que será excluído: \n\n";
            hr();
            cout << "\nDescrição: " << l[pos].desc << endl;
            hr();

            l[pos].status = 1;
            cout << "\n\nIdioma excluído com sucesso\n\n";
        }
        else if (searchCode != 0)
        {
            cout << "\n\nIdioma não cadastrado\n\n";
        }
    }
}

void rearrangeLanguage(Languages *l, Index *idx, int &cont)
{
    int j = -1;
    Languages auxL[20];
    Index auxIdx[20];

    cout << "\n\n\t\tReorganizando Lista...\n\n";

    for (int k = 0; k < cont; k++)
    {
        int i = idx[k].address;

        if (l[i].status == 0)
        {
            j++;

            auxL[j].cod = l[i].cod;
            strcpy(auxL[j].desc, l[i].desc);
            auxL[j].status = 0;
            auxIdx[j].cod = auxL[j].cod;
            auxIdx[j].address = j;
        }
    }
    for (int i = 0; i <= j; i++)
    {
        idx[i] = auxIdx[i];
        l[i] = auxL[i];
    }

    cont = j + 1;
    Sleep(3000);
}

void exhaustiveLanguage(Index *idx, Languages *l, int cont)
{
    system("cls");

    cout << "\t\tLeitura exaustiva dos idiomas\n\n";

    hr();
    for (int k = 0; k < cont; k++)
    {
        int i = idx[k].address;
        if (l[i].status == 0)
        {
            cout << "\nCódigo do Idioma: " << l[i].cod << endl;
            ;
            cout << "\tDescrição: " << l[i].desc << endl;
            hr();
        }
    }
    getch();
}

void searchLanguageCod(Languages *l, Index *idx, int cont, int &cod, char *desc, int status)
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
        cod = status;
    }
    else
    {
        strcpy(desc, "Idioma não cadastrado");
        cod = status;
    }
}

// Exercícios

void readExercise(Exercises *e, Index *idx, Languages *l, Index *idxL, int &cont, int contL)
{
    system("cls");
    int i = 0;
    char desc[40];
    int lCod;
    int op;
    cout << "\t\tLeitura de Exercício\n\n";

    for (int saida = 1; i < 20 && saida != 0; i++)
    {
        op = 2;
        cout << "\n\nCódigo do Exercício: ";
        cin >> e[i].cod;
        cin.ignore();
        if (e[i].cod != 0)
        {
            cout << "\nEnunciado: ";
            gets(e[i].desc);
            cout << "\nNível de dificuldade: ";
            cin >> e[i].difficulty_level;
            cout << "\nPontuação recebida ao acertar: ";
            cin >> e[i].score;
            cin.ignore();
            cout << "\nResposta correta: ";
            gets(e[i].answer);
            while (op != 1)
            {
                cout << "\nDigite o código do Idioma: ";
                cin >> lCod;
                searchLanguageCod(l, idxL, contL, lCod, desc);
                if (lCod != 0)
                {
                    cout << "Este é o idioma escolhido para o exercício " << e[i].cod << "?\n";
                    cout << desc << endl;
                    cout << "\n[1] Sim | [2] Não\n";
                    cin >> op;
                }
                else
                    cout << "\nCódigo do idioma não encontrado!\n";

                if (op == 1)
                {
                    e[i].language = lCod;
                }
                else
                    cout << "\nDigite o código novamente.";
            }
            e[i].status = 0;
        }
        else
            saida = 0;
    }
    cont = i - 1;

    autoIndexExercise(idx, e, cont);
}

void autoIndexExercise(Index *idx, Exercises *e, int cont)
{
    int aux, address_aux, i;

    idx[0].cod = e[0].cod;
    idx[0].address = 0;

    for (int j = 1; j < cont; j++)
    {
        aux = e[j].cod;
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

void printIndexExercise(Index *idx, Exercises *e, int cont)
{
    system("cls");
    cout << "\n\tImpressão de Índices da tabela de Exercícios\n";

    hr();

    if (cont <= 0)
    {
        cout << "\n\t\tNenhum exercício cadastrado\n\n";
        hr();
    }
    else
    {
        for (int i = 0; i < cont; i++)
        {
            int j = idx[i].address;
            cout << "Código do Índice: " << idx[i].cod << endl;
            cout << "Endereço físico do exercício: " << idx[i].address << endl;

            if (e[j].status == 1)
                cout << "--| Marcado na lista de exclusão |--" << endl;

            hr();
        }
    }
    cout << endl;

    getch();
}

void includeExercise(Exercises *e, Index *idx, Languages *l, Index *idxL, int &cont, int contL)
{
    system("cls");
    int pos;
    char desc[40];
    int op;
    int lCod;

    cout << "\t\tInclusão de exercício\n\n";

    for (int searchCode = 9; searchCode != 0;)
    {
        op = 2;
        cout << "\n\nInforme o código do exercício que deseja incluir (digite 0 para sair): ";
        cin >> searchCode;
        cin.ignore();
        if (binarySearch(idx, cont, pos, searchCode))
        {
            pos = idx[pos].address;
            if (e[pos].status == 1)
            {
                searchLanguageCod(l, idxL, contL, e[pos].language, desc);
                cout << "\nExercício na lista de Exclusão!\n\n";
                cout << "Para usar esse código novamente reorganize a lista.\n\n";
                hr();
                cout << "\nCódigo do exercício: " << e[pos].cod << endl;
                cout << "\tEnunciado: " << e[pos].desc << endl;
                cout << "\tNível de dificuldade: " << e[pos].difficulty_level << endl;
                cout << "\tPontuação obtida ao acertar: " << e[pos].score << endl;
                cout << "\tResposta correta: " << e[pos].answer << endl;
                cout << "\tIdioma: " << desc << "\n\n";
                hr();
            }
            else
            {
                searchLanguageCod(l, idxL, contL, e[pos].language, desc);
                cout << "\nExercício já cadastrado - não pode ser cadastrado novamente!\n\n";
                hr();
                cout << "\nCódigo do exercício: " << e[pos].cod << endl;
                cout << "\tEnunciado: " << e[pos].desc << endl;
                cout << "\tNível de dificuldade: " << e[pos].difficulty_level << endl;
                cout << "\tPontuação obtida ao acertar: " << e[pos].score << endl;
                cout << "\tResposta correta: " << e[pos].answer << endl;
                cout << "\tIdioma: " << desc << "\n\n";
                hr();
            }
        }
        else if (searchCode != 0)
        {
            e[cont].cod = searchCode;
            cout << "\nEnunciado: ";
            gets(e[cont].desc);
            cout << "\nNível de dificuldade: ";
            cin >> e[cont].difficulty_level;
            cout << "\nPontuação recebida ao acertar: ";
            cin >> e[cont].score;
            cin.ignore();
            cout << "\nResposta correta: ";
            gets(e[cont].answer);
            while (op != 1)
            {
                cout << "\nDigite o código do Idioma: ";
                cin >> lCod;
                searchLanguageCod(l, idxL, contL, lCod, desc);
                if (lCod != 0)
                {
                    cout << "Este é o idioma escolhido para o exercício " << e[cont].cod << "?\n";
                    cout << desc << endl;
                    cout << "\n[1] Sim | [2] Não\n";
                    cin >> op;
                }
                else
                    cout << "\nCódigo do idioma não encontrado!\n";

                if (op == 1)
                {
                    e[cont].language = lCod;
                }
                else
                    cout << "\nDigite o código novamente.";
            }
            e[cont].status = 0;

            cont++;

            autoIndexExercise(idx, e, cont);

            cout << "\n\nInclusão realizada com sucesso!\n\n";
        }
    }
}

void deleteExercise(Exercises *e, Index *idx, Languages *l, Index *idxL, int &cont, int contL)
{
    system("cls");
    int pos;
    cout << "\t\tExclusão de exercício\n\n";
    for (int searchCode = 9; searchCode != 0;)
    {
        cout << "\n\nInforme o código do exercício que deseja excluir (digite 0 para sair): ";
        cin >> searchCode;
        if (binarySearch(idx, cont, pos, searchCode))
        {
            char desc[40];
            pos = idx[pos].address;
            searchLanguageCod(l, idxL, contL, e[pos].language, desc);

            cout << "\nDados do exercício que será excluído: \n\n";
            hr();
            cout << "\nCódigo do exercício: " << e[pos].cod << endl;
            cout << "\tEnunciado: " << e[pos].desc << endl;
            cout << "\tNível de dificuldade: " << e[pos].difficulty_level << endl;
            cout << "\tPontuação obtida ao acertar: " << e[pos].score << endl;
            cout << "\tDigito da resposta correta: " << e[pos].answer << endl;
            cout << "\tIdioma: " << desc << "\n\n";
            hr();

            e[pos].status = 1;

            cout << "\n\nExercício excluído com sucesso\n\n";
        }
        else if (searchCode != 0)
        {
            cout << "\n\nExercício não cadastrado\n\n";
        }
    }
}

void rearrangeExercise(Exercises *e, Index *idx, int &cont)
{
    int j = -1;
    Exercises auxE[20];
    Index auxIdx[20];

    cout << "\n\n\t\tReorganizando Lista...\n\n";

    for (int k = 0; k < cont; k++)
    {
        int i = idx[k].address;

        if (e[i].status == 0)
        {
            j++;

            auxE[j].cod = e[i].cod;
            strcpy(auxE[j].desc, e[i].desc);
            auxE[j].difficulty_level = e[i].difficulty_level;
            auxE[j].score = e[i].score;
            strcpy(auxE[j].answer, e[i].answer);
            auxE[j].language = e[i].language;
            auxE[j].status = 0;
            auxIdx[j].cod = auxE[j].cod;
            auxIdx[j].address = j;
        }
    }
    for (int i = 0; i <= j; i++)
    {
        idx[i] = auxIdx[i];
        e[i] = auxE[i];
    }

    cont = j + 1;
    Sleep(3000);
}

void exhaustiveExercise(Index *idx, Exercises *e, Languages *l, Index *idxL, int cont, int contL)
{
    system("cls");

    char desc[40];
    cout << "\t\tLeitura exaustiva dos exercícios\n\n";

    hr();
    for (int k = 0; k < cont; k++)
    {
        int i = idx[k].address;
        if (e[i].status == 0)
        {
            searchLanguageCod(l, idxL, contL, e[i].language, desc);
            cout << "\nCódigo do exercício: " << e[i].cod << endl;
            cout << "\tEnunciado: " << e[i].desc << endl;
            cout << "\tNível de dificuldade: " << e[i].difficulty_level << endl;
            cout << "\tPontuação obtida ao acertar: " << e[i].score << endl;
            cout << "\tResposta correta: " << e[i].answer << endl;
            cout << "\tIdioma: " << desc << "\n\n";
            hr();
        }
    }
    getch();
}

// Lições

void readLesson(Lessons *ls, Index *idx, Languages *l, Index *idxL, int &cont, int contL)
{
    system("cls");
    int i = 0;
    int lCod;
    int op;
    char desc[40];
    cout << "\t\tLeitura de Lição\n\n";

    for (int saida = 1; i < 20 && saida != 0; i++)
    {
        op = 2;
        cout << "\n\nCódigo da Lição: ";
        cin >> ls[i].cod;
        if (ls[i].cod != 0)
        {
            cout << "\n\nQuantidade de níveis: ";
            cin >> ls[i].total_levels;
            while (op != 1)
            {
                cout << "\n\nCódigo do idioma: ";
                cin >> lCod;
                searchLanguageCod(l, idxL, contL, lCod, desc);
                if (lCod != 0)
                {
                    cout << "Este é o idioma escolhido para a lição " << ls[i].cod << "?\n";
                    cout << desc << endl;
                    cout << "\n[1] Sim | [2] Não\n";
                    cin >> op;
                }
                else
                    cout << "\nCódigo do idioma não encontrado!\n";

                if (op == 1)
                    ls[i].language = lCod;
                else
                    cout << "\nDigite o código do idioma novamente.";
            }
            ls[i].status = 0;
        }
        else
            saida = 0;
    }
    cont = i - 1;

    autoIndexLesson(idx, ls, cont);
}

void autoIndexLesson(Index *idx, Lessons *ls, int cont)
{
    int aux, address_aux, i;

    idx[0].cod = ls[0].cod;
    idx[0].address = 0;

    for (int j = 1; j < cont; j++)
    {
        aux = ls[j].cod;

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

void printIndexLesson(Index *idx, Lessons *ls, int cont)
{
    system("cls");
    cout << "\t\tImpressão de Índices da tabela de Lições\n\n";

    hr();

    if (cont <= 0)
    {
        cout << "\n\t\tNenhuma lição cadastrada\n\n";
        hr();
    }
    else
    {
        for (int i = 0; i < cont; i++)
        {
            int j = idx[i].address;
            cout << "Código do Índice: " << idx[i].cod << endl;
            cout << "Endereço físico da Lição: " << idx[i].address << endl;

            if (ls[j].status == 1)
                cout << "--| Marcado na lista de exclusão |--" << endl;

            hr();
        }
    }
    cout << endl;

    getch();
}

void includeLesson(Lessons *ls, Index *idx, Languages *l, Index *idxL, int &cont, int contL)
{
    system("cls");
    int pos;
    char desc[40];
    int op;
    int lCod;

    cout << "\t\tInclusão de lição\n\n";

    for (int searchCode = 9; searchCode != 0;)
    {
        op = 2;
        cout << "\n\nInforme o código da lição que deseja incluir (digite 0 para sair): ";
        cin >> searchCode;
        cin.ignore();
        if (binarySearch(idx, cont, pos, searchCode))
        {
            pos = idx[pos].address;
            if (l[pos].status == 1)
            {
                searchLanguageCod(l, idxL, contL, ls[pos].language, desc);
                cout << "\nLição na lista de Exclusão!\n\n";
                cout << "Para usar esse código novamente reorganize a lista.\n\n";
                hr();
                cout << "\nCódigo da lição: " << ls[pos].cod << endl;
                cout << "\tQuantidade de níveis: " << ls[pos].total_levels << endl;
                cout << "\tIdioma: " << desc << "\n\n";
                hr();
            }
            else
            {
                searchLanguageCod(l, idxL, contL, ls[pos].language, desc);
                cout << "\nIdioma já cadastrado - não pode ser cadastrado novamente!\n\n";
                hr();
                cout << "\nCódigo da lição: " << ls[pos].cod << endl;
                cout << "\tQuantidade de níveis: " << ls[pos].total_levels << endl;
                cout << "\tIdioma: " << desc << "\n\n";
                hr();
            }
        }
        else if (searchCode != 0)
        {
            ls[cont].cod = searchCode;
            cout << "\n\nQuantidade de níveis: ";
            cin >> ls[cont].total_levels;
            while (op != 1)
            {
                cout << "\n\nCódigo do idioma: ";
                cin >> lCod;
                searchLanguageCod(l, idxL, contL, lCod, desc);
                if (lCod != 0)
                {
                    cout << "Este é o idioma escolhido para a lição " << ls[cont].cod << "?\n";
                    cout << desc << endl;
                    cout << "\n[1] Sim | [2] Não\n";
                    cin >> op;
                }
                else
                    cout << "\nCódigo do idioma não encontrado!\n";

                if (op == 1)
                    ls[cont].language = lCod;
                else
                    cout << "\nDigite o código do idioma novamente.";
            }
            ls[cont].status = 0;

            cont++;

            autoIndexLesson(idx, ls, cont);

            cout << "\n\nInclusão realizada com sucesso\n\n";
        }
    }
}

void deleteLesson(Lessons *ls, Index *idx, Languages *l, Index *idxL, int &cont, int contL)
{
    system("cls");
    int pos;
    cout << "\t\tExclusão de lição\n\n";
    for (int searchCode = 9; searchCode != 0;)
    {
        cout << "\n\nInforme o código da lição que deseja excluir (digite 0 para sair): ";
        cin >> searchCode;
        if (binarySearch(idx, cont, pos, searchCode))
        {
            char desc[40];
            pos = idx[pos].address;
            searchLanguageCod(l, idxL, contL, ls[pos].language, desc);

            cout << "\nDados da lição que será excluído: \n\n";
            hr();
            cout << "\nCódigo da lição: " << ls[pos].cod << endl;
            cout << "\tQuantidade de níveis: " << ls[pos].total_levels << endl;
            cout << "\tIdioma: " << desc << "\n\n";
            hr();

            ls[pos].status = 1;

            cout << "\n\nLição excluída com sucesso\n\n";
        }
        else if (searchCode != 0)
        {
            cout << "\n\nLição não cadastrada\n\n";
        }
    }
}

void rearrangeLesson(Lessons *ls, Index *idx, int &cont)
{
    int j = -1;
    Lessons auxLs[20];
    Index auxIdx[20];

    cout << "\n\n\t\tReorganizando Lista...\n\n";

    for (int k = 0; k < cont; k++)
    {
        int i = idx[k].address;

        if (ls[i].status == 0)
        {
            j++;

            auxLs[j].cod = ls[i].cod;
            auxLs[j].total_levels = ls[i].total_levels;
            auxLs[j].language = ls[i].language;
            auxLs[j].status = 0;
            auxIdx[j].cod = auxLs[j].cod;
            auxIdx[j].address = j;
        }
    }
    for (int i = 0; i <= j; i++)
    {
        idx[i] = auxIdx[i];
        ls[i] = auxLs[i];
    }

    cont = j + 1;
    Sleep(3000);
}

void exhaustiveLesson(Index *idx, Lessons *ls, Languages *l, Index *idxL, int cont, int contL)
{
    system("cls");

    char desc[40];
    cout << "\t\tLeitura exaustiva das lições\n\n";

    hr();
    for (int k = 0; k < cont; k++)
    {
        int i = idx[k].address;
        if (ls[i].status == 0)
        {
            searchLanguageCod(l, idxL, contL, ls[i].language, desc);
            cout << "\nCódigo da lição: " << ls[i].cod << endl;
            cout << "\tQuantidade de níveis: " << ls[i].total_levels << endl;
            cout << "\tIdioma: " << desc << "\n\n";
            hr();
        }
    }
    getch();
}

void hr()
{
    for (int i = 0; i < 60; i++)
    {
        cout << "-";
    }
    cout << endl;
}

bool binarySearch(Index *idx, int cont, int &pos, int cod)
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