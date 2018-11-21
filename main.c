
#include <windows.h>

//
//// Alunos: Stephano e Franklin
//
//struct aluno {
//    int codigo, idade;
//    char nome[40], genero;
//    float nota;
//};
//
//void reset() {
//    clrscr();
//    gotoxy(1, 1);
//}
//
//void wait(int x, int y) {
//    gotoxy(x, y);
//    printf("Pressione [Enter] para continuar ...");
//    fflush(stdin);
//    fflush(stdout);
//    getch();
//}
//
//void relatorio() {
//    FILE *infile;
//    struct aluno input;
//    int total = 0;
//
//    infile = fopen("alunos.txt", "r");
//
//    reset();
//
//    if (infile == NULL) {
//        fprintf(stderr, "NÃO FOI POSSÍVEL BUSCAR OS ALUNOS.");
//        exit(1);
//    }
//
//    printf("+--------+--------------------------------------------+");
//    gotoxy(1, 2);
//    printf("| CÓDIGO |                    NOME                    |");
//
//    while (fread(&input, sizeof(struct aluno), 1, infile)) {
//        total++;
//    }
//
//    fclose(infile);
//    infile = fopen("alunos.txt", "r");
//
//    gotoxy(1, 11);
//    printf("+--------+--------------------------------------------+");
//    gotoxy(1, 12);
//    printf("| TOTAL  | %-42i |", total);
//    gotoxy(1, 13);
//    printf("+--------+--------------------------------------------+");
//
//    int row = 3;
//
//    while (fread(&input, sizeof(struct aluno), 1, infile)) {
//        gotoxy(1, row);
//
//        if (row < 10) {
//            row++;
//        }
//
//        printf("+--------+--------------------------------------------+");
//        gotoxy(1, row);
//
//        if (row < 10) {
//            row++;
//        }
//
//        printf("| %-6i | %-42s |", input.codigo, input.nome);
//
//        total++;
//
//        if (row >= 10) {
//            wait(1, 15);
//            gotoxy(1, 4);
//            delline();
//            delline();
//            gotoxy(1, 9);
//            insline();
//            insline();
//
//            printf("+--------+--------------------------------------------+");
//        }
//    }
//
//    fclose(infile);
//    wait(1, 15);
//}
//
//struct aluno criar() {
//    struct aluno input;
//    int row = 2, rowInput;
//
//    reset();
//    printf("+--------------------------------+");
//    gotoxy(1, row++);
//    printf("|            CADASTRO            |");
//    gotoxy(1, row++);
//    rowInput = row;
//    printf("+--------------------------------+");
//    gotoxy(1, row++);
//    printf("| ID     |                       |");
//    gotoxy(1, row++);
//    printf("+------+-------------------------+");
//    gotoxy(1, row++);
//    printf("| NOME   |                       |");
//    gotoxy(1, row++);
//    printf("+------+-------------------------+");
//    gotoxy(1, row++);
//    printf("| IDADE  |                       |");
//    gotoxy(1, row++);
//    printf("+------+-------------------------+");
//    gotoxy(1, row++);
//    printf("| GÊNERO |                       |");
//    gotoxy(1, row++);
//    printf("+--------+-----------------------+");
//    gotoxy(1, row++);
//    printf("| NOTA   |                       |");
//    gotoxy(1, row++);
//    printf("+--------+-----------------------+");
//    gotoxy(12, rowInput);
//    rowInput += 2;
//    scanf("%i", &input.codigo);
//    gotoxy(12, rowInput);
//    rowInput += 2;
//    scanf("%s", input.nome);
//    gotoxy(12, rowInput);
//    rowInput += 2;
//    scanf("%i", &input.idade);
//    gotoxy(12, rowInput);
//    rowInput += 2;
//    scanf(" %c", &input.genero);
//    gotoxy(12, rowInput);
//    rowInput += 2;
//    scanf("%f", &input.nota);
//
//    return input;
//}
//
//void armazenar(struct aluno input) {
//    FILE *outfile;
//
//    outfile = fopen("alunos.txt", "a");
//
//    reset();
//
//    if (outfile == NULL) {
//        fprintf(stderr, "NÃO FOI POSSÍVEL BUSCAR OS ALUNOS.");
//        exit(1);
//    }
//
//    if (fwrite(&input, sizeof(struct aluno), 1, outfile)) {
//        printf("ALUNO SALVO COM SUCESSO!");
//    } else {
//        printf("NÃO FOI POSSÍVEL SALVAR O ALUNO. %s", strerror(errno));
//        exit(1);
//    }
//
//    fclose(outfile);
//    wait(1, 3);
//}
//
//void editar() {
//    FILE *infile;
//    struct aluno input;
//    struct aluno output;
//    char genero;
//    int achou = 0, row = 3, rowInput, count = 0, pesquisa;
//
//    infile = fopen("alunos.txt", "r+");
//
//    reset();
//
//    if (infile == NULL) {
//        fprintf(stderr, "NÃO FOI POSSÍVEL BUSCAR OS ALUNOS.");
//        wait(1, 5);
//        exit(1);
//    }
//
//    printf("PESQUISAR CÓDIGO: ");
//    scanf("%i", &pesquisa);
//
//    while (!feof(infile) && achou == 0) {
//        count++;
//        while (fread(&input, sizeof(struct aluno), 1, infile)) {
//            if (input.codigo == pesquisa) {
//                gotoxy(1, row++);
//                printf("+--------------------------------+");
//                gotoxy(1, row++);
//                printf("| %-30s |", input.nome);
//                gotoxy(1, row++);
//                rowInput = row;
//                printf("+--------------------------------+");
//                gotoxy(1, row++);
//                printf("| ID     |                       |");
//                gotoxy(1, row++);
//                printf("+--------+-----------------------+");
//                gotoxy(1, row++);
//                printf("| NOME   |                       |");
//                gotoxy(1, row++);
//                printf("+--------+-----------------------+");
//                gotoxy(1, row++);
//                printf("| IDADE  |                       |");
//                gotoxy(1, row++);
//                printf("+--------+-----------------------+");
//                gotoxy(1, row++);
//                printf("| GÊNERO |                       |");
//                gotoxy(1, row++);
//                printf("+--------+-----------------------+");
//                gotoxy(1, row++);
//                printf("| NOTA   |                       |");
//                gotoxy(1, row++);
//                printf("+--------+-----------------------+");
//                gotoxy(12, rowInput);
//                rowInput += 2;
//                scanf("%i", &output.codigo);
//                gotoxy(12, rowInput);
//                rowInput += 2;
//                scanf("%s", output.nome);
//                gotoxy(12, rowInput);
//                rowInput += 2;
//                scanf("%i", &output.idade);
//                gotoxy(12, rowInput);
//                rowInput += 2;
//
//                do {
//                    fflush(stdin);
//                    genero = getchar();
//                } while(genero != 'M' && genero != 'F');
//
//                output.genero = genero;
//
//                gotoxy(12, rowInput);
//                rowInput += 2;
//                scanf("%f", &output.nota);
//
//                row += 2;
//                gotoxy(1, row);
//
//                fseek(infile, --count * sizeof(struct aluno), SEEK_SET);
//                if (fwrite(&output, sizeof(struct aluno), 1, infile)) {
//                    printf("ALUNO EDITADO COM SUCESSO!");
//                } else {
//                    printf("NÃO FOI POSSÍVEL SALVAR O ALUNO. %s", strerror(errno));
//                }
//
//                achou = 1;
//            }
//        }
//    }
//
//    if (achou == 0) {
//        gotoxy(1, row++);
//        printf("A BUSCA NÃO RETORNOU NENHUM REGISTRO");
//    }
//
//    fclose(infile);
//    row += 2;
//    wait(1, row);
//}
//
//void dadosEstatisticos() {
//    FILE *infile;
//    struct aluno input;
//    int total = 0, maior = 0, homens = 0, mulheres = 0;
//    float masculino, feminino, media = 0, notas = 0;
//
//    infile = fopen("alunos.txt", "a+");
//
//    reset();
//
//    if (infile == NULL) {
//        fprintf(stderr, "NÃO FOI POSSÍVEL BUSCAR OS ALUNOS.");
//        wait(1, 5);
//        exit(1);
//    }
//
//    while (fread(&input, sizeof(struct aluno), 1, infile)) {
//        if (total == 0 || input.idade > maior) {
//            maior = input.idade;
//        }
//
//        switch(input.genero) {
//            case 'M':
//                homens++;
//                break;
//            case 'F':
//                mulheres++;
//        }
//
//        notas += input.nota;
//
//        total++;
//    }
//
//    masculino = 100 * homens / total;
//    feminino = 100 * mulheres / total;
//    media = total == 0 ? 0 : notas / total;
//
//    int row = 2;
//
//    gotoxy(1, row++);
//    printf("+----------------------------------+");
//    gotoxy(1, row++);
//    printf("|               DADOS              |");
//    gotoxy(1, row++);
//    printf("+-----------------------+----------+");
//    gotoxy(1, row++);
//    printf("| TOTAL DE INSCRITOS    | %-8i |", total);
//    gotoxy(1, row++);
//    printf("+-----------------------+----------+");
//    gotoxy(1, row++);
//    printf("| CANDIDATO MAIS VELHO  | %-8i |", maior);
//    gotoxy(1, row++);
//    printf("+-----------------------+----------+");
//    gotoxy(1, row++);
//    printf("| PERCENTUAL MASCULINO  | %8.2f%%|", masculino);
//    gotoxy(1, row++);
//    printf("+-----------------------+----------+");
//    gotoxy(1, row++);
//    printf("| PERCENTUAL FEMININO   | %8.2f%%|", feminino);
//    gotoxy(1, row++);
//    printf("+-----------------------+----------+");
//    gotoxy(1, row++);
//    printf("| MÉDIA GERAL DAS NOTAS | %8.2f |", media);
//    gotoxy(1, row++);
//    printf("+-----------------------+----------+");
//
//    fclose(infile);
//    wait(1, ++row);
//}
//
//int menu() {
//    int option, row = 2;
//
//    reset();
//    printf("+------------------------+");
//    gotoxy(1, row++);
//    printf("|          MENU          |");
//    gotoxy(1, row++);
//    printf("+------------------------+");
//    gotoxy(1, row++);
//    printf("| 1 | CADASTRO           |");
//    gotoxy(1, row++);
//    printf("+---+--------------------+");
//    gotoxy(1, row++);
//    printf("| 2 | EDIÇÃO             |");
//    gotoxy(1, row++);
//    printf("+---+--------------------+");
//    gotoxy(1, row++);
//    printf("| 3 | RELATÓRIO          |");
//    gotoxy(1, row++);
//    printf("+---+--------------------+");
//    gotoxy(1, row++);
//    printf("| 4 | DADOS ESTATÍSTICOS |");
//    gotoxy(1, row++);
//    printf("+---+--------------------+");
//    gotoxy(1, row++);
//    printf("| 5 | SAIR               |");
//    gotoxy(1, row++);
//    printf("+---+--------------------+");
//
//    row += 2;
//
//    gotoxy(1, row);
//    printf("MENU: ");
//    scanf("%i", &option);
//
//    return option;
//}

struct student {
    int *id;
    char nome[40], *genre;
    float *grade;
};

void GotoXY(short x, short y) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;

    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(handle, coord);
}

void Clear() {
    system("cls");
    GotoXY(1, 1);
}

short Line(short row, char *number, char *text) {
    char *divider = "+--------+----------+";

    GotoXY(1, row++);
    printf("| %-6s | %-8s |", number, text);
    GotoXY(1, row++);
    printf("%s", divider);

    return row;
}

int Menu() {
    short row = 1;
    char *divider = "+-------------------+";

    Clear();

    GotoXY(1, row++);
    printf("%s", divider);
    GotoXY(1, row++);
    printf("| %-17s |", "MENU");
    GotoXY(1, row++);
    printf("%s", divider);
    row = Line(row, "1", "INDEX");
    row = Line(row, "2", "CREATE");
    row = Line(row, "3", "SHOW");
    row = Line(row, "4", "EDIT");
    row = Line(row, "5", "DESTROY");
    row = Line(row, "6", "EXIT");
    row = Line(row, "SELECT", "");

    int input;

    do {
        GotoXY(12, (short) (row - 2));
        scanf("%i", &input);
    } while (input < 1 || input > 6);

    return input;
}

short Form(char *title) {
    short row = 2;

    Clear();

    printf("+--------------------------------+");
    GotoXY(1, row++);
    printf("| %-30s |", title);
    GotoXY(1, row++);
    printf("+--------------------------------+");
    short input = row;
    GotoXY(1, row++);
    printf("| ID     |                       |");
    GotoXY(1, row++);
    printf("+------+-------------------------+");
    GotoXY(1, row++);
    printf("| NAME   |                       |");
    GotoXY(1, row++);
    printf("+------+-------------------------+");
    GotoXY(1, row++);
    printf("| AGE    |                       |");
    GotoXY(1, row++);
    printf("+------+-------------------------+");
    GotoXY(1, row++);
    printf("| GENRE  |                       |");
    GotoXY(1, row++);
    printf("+--------+-----------------------+");
    GotoXY(1, row++);
    printf("| GRADE  |                       |");
    GotoXY(1, row);
    printf("+--------+-----------------------+");

    return input;
}

struct student Create() {
    short row = Form("CREATE");

    struct student student;

    GotoXY(12, row);
    scanf("%i", student.id);
    row += 2;
    GotoXY(12, row);
    scanf("%s", student.nome);
    row += 2;
    GotoXY(12, row);
    scanf("%c", student.genre);
    row += 2;
    GotoXY(12, row);
    scanf("%f", student.grade);

    return student;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    while (1) {
        int option = Menu();

        switch (option) {
            case 1:
                getch();
                break;
            case 2:
                Create();
                getch();
                break;
            default:
                return 0;
        }
    }
}
