#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>


int i, filial, CARGO, diaEntrada, mesEntrada, anoEntrada, diaSaida, mesSaida, anoSaida, diaDoAnoSaida, diaDoAnoEntrada, numeroQuarto,TipodeUsuario, multa, acessoglobal=0, ReservasConcluidas=0, opc1;
char NOME[50], CPF[12], SENHA[15];
float precoS1=650.00, precoC1=850.00, precoM1=1150.00, precoP1=1750.00, encarecer=0.30;
float precoS2=450.00, precoC2=550.00, precoM2=750.00;
typedef struct
{
    char nome[50], cpf[12], senha[15];
    int codcad, cargo;
} cadastroCliente;

typedef struct
{
    int numeroQuarto, diaDoAnoEntrada,diaDoAnoSaida, AnoEntrada, AnoSaida, CodRes, pg, fillial;
    char nomeR[50], cpfR[12],  USUARIO[50];
    float precoreserva;
} ReservaA;
typedef struct
{
    int numeroQuarto, diaDoAnoEntrada,diaDoAnoSaida, AnoEntrada, AnoSaida, fillial;
    float precoreserva;
} Pago;

typedef struct
{
    int cargo;
    char nome[50], senha[15];
} funcionarios;

void LoginFuncionario(funcionarios Funcionario[], int *nFuncionarios);
void definidorfuncionarios(funcionarios Funcionarios[], int *nFuncionarios);
void ConcluirReserva(ReservaA reserva[], Pago reservac[], int *nReservas, int *nReserC);
void ExibirReservasCliente(ReservaA reserva[], cadastroCliente cadastroCli[], int *nReservas);
void Logincliente(cadastroCliente cadastroCli[], funcionarios Funcionario[],int *numClientes, int *nFuncionarios);
int recebedordecheckin(ReservaA reserva[], int*nReservas);
void exibirClientes(cadastroCliente clientes[], int *numClientes);
void cadastrarCliente(cadastroCliente clientes[], int *numClientes);
void FazerReservasFuncionario(ReservaA reserva[], cadastroCliente cadastroCli[],  int *nReservas, int *numClientes);
void FazerReservasCliente(ReservaA reserva[], cadastroCliente cadastroCli[],  int *nReservas, int *numClientes);
void ExibirReservas(ReservaA reserva[], cadastroCliente cadastroCli[], int *nReservas);
void VerificarDisponibilidade(ReservaA reserva[], cadastroCliente cadastroCli[], int *nReservas);
void CancelarReserva(ReservaA reserva[], int *nReservas);
void LeitorFaturamento(ReservaA reserva[],Pago reserc[], int *nReservas, int *nReserc);
void definirCorConsole();
int CompararDataAtual (int Dia, int Mes, int Ano);
int ValidarDatas(int dia, int mes, int ano);
int dataParaDiaDoAno(int dia, int mes, int ano);
int VerificarSobreposicao(ReservaA reserva[], int *nReservas, int numeroQuarto, int diaDoAnoEntrada, int diaDoAnoSaida, int anoEntrada, int anoSaida);
void mensagemMenuFun();
void descricaoQrt();

int main()
{
    system("color B0");
    setlocale(LC_ALL, "Portuguese");
    funcionarios Funcionarios[5];
    cadastroCliente client[1000];
    ReservaA reservas[1000];
    Pago reservasC[1000];
    int numReservas = 0, nClientes =0, numFuncionarios =0, numReservasC=0;
    int  opc1 = 0, opc = 0, num;


    definidorfuncionarios(Funcionarios, &numFuncionarios);
    //=====================================================
    //=======================login=========================
    definidorfuncionarios(Funcionarios, &numFuncionarios);

    do
    {
        system("cls");
        printf("\n=============================================\n");
        printf("---Bem vindo a rede Hotel Algoritmo Suites---");
        printf("\n=============================================\n");
        printf("Escolha uma opção\n");
        printf("[1] Login de Cliente.\n");
        printf("[2] Login de Colaborador.\n");
        printf("[3] Cadastre-se.\n");
        printf("[4] Conheça nossos Quartos.\n");
        printf("[5] Fechar programa.\n");
        scanf("%d", &TipodeUsuario);
        fflush(stdin);
        if(TipodeUsuario==2)
            opc1=1;
        else if(TipodeUsuario==1)
            opc1=1;
        else if(TipodeUsuario==3)
            opc1=3;
        else if(TipodeUsuario==4)
            opc1=4;
        else if(TipodeUsuario==5)
            opc1=5;

        switch(opc1)
        {
        case 1:

            if(TipodeUsuario==1)
                Logincliente(client, Funcionarios, &nClientes, &numFuncionarios);
            if(TipodeUsuario==2)
            {
                LoginFuncionario(Funcionarios, &numFuncionarios);

            }
            do
            {
                system("cls");
                printf("\n|------------------Bem vindo a rede Hotel Algoritmo Suites-------------------|\n");
                printf("\n|1.Escolha 1 para a filial (1) - Master......................................|");
                printf("\n|2.Escolha 2 para a filial (2) - Confort.....................................|\n");
                printf("\n|3.Escolha 3 para Voltar.....................................................|\n");
                scanf("%d", &filial);
                system("cls");

                switch (filial)
                {
                case 1:
                    do
                    {
                        system("cls");
                        if(CARGO==1)
                            mensagemMenuFun();
                        if(CARGO==0)
                            mensagemMenuCli();

                        scanf("%d", &opc);
                        system("cls");

                        switch (opc)
                        {
                        case 1:
                            if(CARGO==1)
                            {
                                VerificarDisponibilidade(reservas, client, &numReservas);
                                FazerReservasFuncionario(reservas, client, &numReservas, &nClientes);

                            }
                            if(CARGO==0)
                            {
                                VerificarDisponibilidade(reservas, client, &numReservas);
                                FazerReservasCliente(reservas, client, &numReservas, &nClientes);
                            }
                            break;
                        case 2:
                            //=====================================================
                            //=====================clientes========================
                            if(CARGO==1)
                                cadastrarCliente(client, &nClientes);
                            if(CARGO==0)
                            {
                                ExibirReservasCliente(reservas, client, &numReservas);
                                system("pause");
                            }
                            break;
                        case 3:
                            //=====================================================
                            //====================relatorio========================
                            if(CARGO==1)
                            {
                                ExibirReservas(reservas, client, &numReservas);

                            }
                            if(CARGO==0)
                                VerificarDisponibilidade(reservas, client, &numReservas);
                            system("pause");
                            break;
                        case 4:
                            if(CARGO==1)
                                ConcluirReserva(reservas,reservasC, &numReservas, &numReservasC);
                            if(CARGO==0)
                                printf("opcao invalida");

                            break;
                        case 5:
                            if(CARGO==1)
                            {
                                ExibirReservas(reservas, client, &numReservas);
                                CancelarReserva(reservas, &numReservas);
                            }
                            if(CARGO==0)
                                printf("opcao invalida");
                            break;
                        case 6:
                            if(CARGO==1)
                            {
                                exibirClientes(client, &nClientes);
                                system("pause");
                            }
                            if(CARGO==0)
                                printf("opcao invalida");
                            break;
                        case 7:
                            if(CARGO==1)
                                LeitorFaturamento(reservas,reservasC, &numReservas, &numReservasC);
                            if(CARGO==0)
                                printf("opcao invalida");
                            break;
                        case 8:
                            formaPagamento(nClientes, client, reservas);
                            confirmarPagamento(reservas, &numReservas );
                            break;
                        case 9:
                            if(CARGO==1)
                                Alteradordepreco();
                            if(CARGO==0)
                                printf("opcao invalida");
                            break;
                        case 10:
                            definirCorConsole();
                            break;
                        default:
                            printf("opcao invalida");
                            break;
                        case 13:
                            break;
                        }
                    }
                    while (opc != 13);
                    break;
                case 2:
                    do
                    {
                        system("cls");
                        if(CARGO==1)
                            mensagemMenuFun();
                        if(CARGO==0)
                            mensagemMenuCli();

                        scanf("%d", &opc);
                        system("cls");

                        switch (opc)
                        {
                        case 1:
                            if(CARGO==1)
                            {
                                VerificarDisponibilidade(reservas, client, &numReservas);
                                FazerReservasFuncionario(reservas, client, &numReservas, &nClientes);

                            }
                            if(CARGO==0)
                            {
                                VerificarDisponibilidade(reservas, client, &numReservas);
                                FazerReservasCliente(reservas, client, &numReservas, &nClientes);
                            }
                            break;
                        case 2:
                            //=====================================================
                            //=====================clientes========================
                            if(CARGO==1)
                                cadastrarCliente(client, &nClientes);
                            if(CARGO==0)
                            {
                                ExibirReservasCliente(reservas, client, &numReservas);
                                system("pause");
                            }
                            break;
                        case 3:
                            //=====================================================
                            //====================relatorio========================
                            if(CARGO==1)
                            {
                                ExibirReservas(reservas, client, &numReservas);

                            }
                            if(CARGO==0)
                                VerificarDisponibilidade(reservas, client, &numReservas);
                            system("pause");
                            break;
                        case 4:
                            if(CARGO==1)
                                ConcluirReserva(reservas,reservasC, &numReservas, &numReservasC);
                            if(CARGO==0)
                                printf("opcao invalida");

                            break;
                        case 5:
                            if(CARGO==1)
                            {
                                ExibirReservas(reservas, client, &numReservas);
                                CancelarReserva(reservas, &numReservas);
                            }
                            if(CARGO==0)
                                printf("opcao invalida");
                            break;
                        case 6:
                            if(CARGO==1)
                            {
                                exibirClientes(client, &nClientes);
                                system("pause");
                            }
                            if(CARGO==0)
                                printf("opcao invalida");
                            break;
                        case 7:
                            if(CARGO==1)
                                LeitorFaturamento(reservas,reservasC, &numReservas, &numReservasC);
                            if(CARGO==0)
                                printf("opcao invalida");
                            break;
                        case 8:
                            formaPagamento(nClientes, client, reservas);
                            confirmarPagamento(reservas, &numReservas );
                            break;
                        case 9:
                            if(CARGO==1)
                                Alteradordepreco();
                            if(CARGO==0)
                                printf("opcao invalida");
                            break;
                        case 10:
                            definirCorConsole();
                            break;
                        default:
                            printf("opcao invalida");
                            break;
                        case 13:
                            break;
                        }
                    }
                    while (opc != 13);
                    break;

                case 3:
                    break;
                default:
                    printf("\nopcao invalida\n");
                    system("pause");
                    system("cls");
                    break;
                }
            }
            while(filial != 3);
            break;
        case 2:
            LoginFuncionario(Funcionarios, &numFuncionarios);
            break;
        case 3:
            cadastrarCliente(client, &nClientes);
            break;
        case 4:
            system("cls");
            printf("[1]FILIAL – MASTER\n");
            printf("[2]FILIAL – COMFORT\n");
            scanf("%d", &num);

            if(num == 1)
            {
                descricaoQrtF1();
            }
            else if(num == 2)
            {
                descricaoQrtF2();
            }
            else
            {
                printf("Escolha invalida!\n\n");
                system("pause");
            }

            break;
        case 5:
            break;
        default:
            system("cls");
            printf("\nOpção Invalida!\n");
            break;
        }
    }
    while(opc1!=5);
    //=====================================================
    //=====================Quartos=========================

    return 0;
}

void Logincliente(cadastroCliente cadastroCli[], funcionarios Funcionario[],int *numClientes, int *nFuncionarios)
{
    system("cls");
    int procurarcliente, acesso=0;
    char nome1[50];
    char senhaA[15];
    printf("\nLogin de Cliente!\n");
    do
    {
        if(*numClientes!=0)
        {
            printf("\nUsuario: ");
            scanf("%s", &nome1);
            fflush(stdin);
            printf("Senha: ");
            scanf("%s", &senhaA);
            fflush(stdin);
            for(i=0; i<*numClientes; i++)
            {
                if(strcmp(nome1,cadastroCli[i].nome)==0&&strcmp(senhaA,cadastroCli[i].senha)==0)
                {
                    procurarcliente=i;
                    acesso=1;

                }
            }
            if(acesso==0)
            {
                printf("\nUsuario ou senha invalido, por favor tente novamente!\n");
            }
        }
        else if(*numClientes==0)
        {
            printf("\nAinda não há Clientes!\n");
            cadastrarCliente(cadastroCli, numClientes);

        }
    }
    while(acesso!=1);

    CARGO=cadastroCli[procurarcliente].cargo;
    strcpy(NOME,cadastroCli[procurarcliente].nome);
    strcpy(SENHA,cadastroCli[procurarcliente].senha);
    strcpy(CPF,cadastroCli[procurarcliente].cpf);
}

void LoginFuncionario(funcionarios Funcionario[], int *nFuncionarios)
{
    int procurarfun = 0, procurarcliente = -1;
    char nome1[50], senhaA[15];
    printf("\nLogin de Colaborador!\n");
    int i;

    do
    {
        printf("\nUsuario: ");
        scanf("%s", nome1);

        printf("Senha: ");
        int j = 0;
        char c;
        while (1)
        {
            c = _getch();

            if (c == '\r')
                break;

            senhaA[j] = c;
            j++;
            putchar('*');
        }

        senhaA[j] = '\0';
        printf("\n");

        for (i = 0; i < *nFuncionarios; i++)
        {
            if (strcmp(nome1, Funcionario[i].nome) == 0 && strcmp(senhaA, Funcionario[i].senha) == 0)
            {
                procurarfun = 1;
                procurarcliente = i;
                acessoglobal = 1;
                break;
            }
        }

        if (procurarcliente == -1)
        {
            printf("Nome de usuário ou senha inválidos. Por favor, tente novamente.\n");
        }
    }
    while (procurarfun != 1);

    CARGO = Funcionario[procurarcliente].cargo;
    strcpy(NOME, Funcionario[procurarcliente].nome);
    strcpy(SENHA, Funcionario[procurarcliente].senha);
}

//============================================================================================
//========================================Clientes===========================================
void cadastrarCliente(cadastroCliente client[], int *nClientes)
{
    system("cls");
    printf("\nCadastro!! ");

    cadastroCliente novoCliente;
    printf("\nDigite o nome do cliente: ");
    scanf(" %[^\n]", novoCliente.nome);

    printf("\nDigite o CPF do cliente(apenas numeros): ");
    scanf(" %s", novoCliente.cpf);

    printf("\nDigite a Senha do Cliente: ");
    scanf(" %s", novoCliente.senha);

    novoCliente.cargo=0;

    novoCliente.codcad=*nClientes+1;

    client[*nClientes] = novoCliente;
    (*nClientes)++;
    printf("\n\nCliente %s, cadastrado com sucesso!!!\n\n", novoCliente.nome);
    system("pause");

    return;
}
//============================================================================================
//=======================================relatorio============================================
void exibirClientes(cadastroCliente client[], int *numClientes)
{
    if(*numClientes!=0)
        printf("=======Clientes cadastrados:===========\n");
    i=0;
    while(i < *numClientes)
    {
        printf("Nome: %s\n", client[i].nome);
        printf("CPF: %s\n", client[i].cpf);
        printf("Codigo do Cliente: %d\n", client[i].codcad);
        printf("===================================\n");
        i++;
    }
    if(*numClientes==0)
    {
        printf("\nNao há Cadastros!\n");
    }
}
//============================================================================================
//==================================mensagem menu=============================================
void mensagemMenuFun()
{
    printf(" \n______________________________________________________ ");
    if(filial==1)
        printf("\n|-------Bem-vindo ao Algoritmo Suites Master-----------|");
    if(filial==2)
        printf("\n|-------Bem-vindo ao Algoritmo Suites Confort----------|");
    printf("\n ______________________________________________________ ");
    printf("\n|--------------------Menu Colaborador------------------|");
    printf("\n Olá, %s", NOME);
    printf("\n|______________________________________________________|\n");
    printf("\n1|Escolha 1 para fazer uma reserva.....................|");
    printf("\n2|Escolha 2 para Cadastro de clientes..................|");
    printf("\n3|Escolha 3 para visualizar as reservas................|");
    printf("\n4|Escolha 4 para Concluir uma reserva..................|");
    printf("\n5|Escolha 5 para cancelar reserva......................|");
    printf("\n6|Escolha 6 para ver clientes..........................|");
    printf("\n7|Escolha 7 para ver relatorio de faturamento..........|");
    printf("\n8|Escolha 8 para realizar pagamento....................|");
    printf("\n9|Escolha 9 para alterar preço de estadia..............|\n");
    printf("\n10|Escolha 10 para alterar tema do sistema.............|");
    printf("\n\n13|Escolha 13 voltar.................................|\n\n");
}

void mensagemMenuCli()
{
    printf(" \n______________________________________________________ ");
    if(filial==1)
        printf("\n|-------Bem-vindo ao Algoritmo Suites Master-----------|");
    if(filial==2)
        printf("\n|-------Bem-vindo ao Algoritmo Suites Confort----------|");
    printf("\n ______________________________________________________ ");
    printf("\n|-------------------------Menu-------------------------|");
    printf("\n Olá, %s\tPortador do cpf %s", NOME, CPF);
    printf("\n|______________________________________________________|\n");
    printf("\n1|Escolha 1 para fazer uma reserva.....................|");
    printf("\n2|Escolha 2 para visualizar as minhas reservas.........|");
    printf("\n3|Escolha 3 para visualizar estadias ja reservadas.....|\n");
    printf("\n10|Escolha 10 para alterar tema do sistema.............|");
    printf("\n\n13|Escolha 13 para voltar............................|\n\n");
}

void descricaoQrtF1()
{
    system("cls");
    printf("\n_________________________________________________________________________________________\n");
    printf("=============================REDE DE HOTEL ALGORITMO SUÍTES==============================\n");

    printf("\n\t\t\t\tFILIAL 1 – MASTER\n\n");


    printf("\n======================================STANDARD===========================================\n");
    printf("Esta categoria possui apartamentos de 30m², todos com sacada e decoração moderna. \
           \nEstão em andares mais baixos, com vista para o jardim. Piso vinílico, frigobar, tv \
           \npor assinatura, banheiro completo com amenities de banho e secador de cabelo. \
           \nOpção: cama Queen Size ou duas camas de solteiro. Café da manhã e wifi são cortesia.");
    printf("\n\n__________________________________________________________________Preço da diária: R$%2.f\n,", precoS1);
    printf("=========================================================================================\n\n");

    printf("======================================COMFORT=============================================\n");
    printf("Esta categoria possui apartamentos de 40m², todos com decoração moderna. \
           \nEstão em andares intermediários, com vista para a cidade. Piso vinílico, frigobar, \
           \ntábua de passar e ferro, tv por assinatura, banheiro completo com amenities de banho, \
           \nsecador de cabelo e roupão. Cama Queen Size. Café da manhã e wifi são cortesia. ");
    printf("\n\n__________________________________________________________________Preço da diária: R$%2.f\n", precoC1);
    printf("=========================================================================================\n\n");

    printf("\n======================================MASTER==============================================\n");
    printf("Esta categoria possui apartamentos de 50m², todos com decoração moderna. Estão em andares \
           \nintermediários, com vista para a cidade. Piso vinílico, frigobar, tábua de passar e ferro, \
           \ntv por assinatura e plataforma de streaming. Banheiro completo com amenities L’Occitane \
           \nde banho, secador de cabelo, roupão e chinelo de quarto. Cama Queen Size. \
           \nCafé da manhã e wifi são cortesia.");
    printf("\n\n__________________________________________________________________Preço da diária: R$%2.f\n", precoM1);
    printf("=========================================================================================\n\n");

    printf("\n===================================PRESIDENCIAL===========================================\n");
    printf("Esta categoria possui apartamentos suntuosos, elegantes e confortáveis de 90m². \
           \nEstão em andares altos com vista panorâmica da cidade. Piso vinílico, frigobar, \
           \ntv por assinatura e plataforma de streaming, máquina de café Nespresso. \
           \nBanheiro completo com hidromassagem, amenities de banho L’Occitane, secador de cabelo, \
           \nroupão e chinelo de quarto. Cama King Size. Café da manhã e wifi são cortesia.");
    printf("\n\n__________________________________________________________________Preço da diária: R$%2.f\n", precoP1);
    printf("=========================================================================================\n\n");

    system("pause");
    return;
}

void descricaoQrtF2()
{
    system("cls");
    printf("\n_________________________________________________________________________________________\n");
    printf("=============================REDE DE HOTEL ALGORITMO SUÍTES==============================\n");

    printf("\n\t\t\t\tFILIAL 1 – MASTER\n\n");


    printf("\n======================================STANDARD===========================================\n");
    printf("Esta categoria possui apartamentos de 20m² com decoração moderna. Estão em andares \
           \nmais baixos, com vista para o jardim. Piso vinílico, frigobar, tv por assinatura, \
           \nbanheiro completo com amenities de banho e secador de cabelo. Opção: cama de casal ou \
           \nduas camas de solteiro. Café da manhã e wifi são cortesia.");
    printf("\n\n__________________________________________________________________Preço da diária: R$%2.f\n",precoS2);
    printf("=========================================================================================\n\n");

    printf("======================================COMFORT=============================================\n");
    printf("Esta categoria possui apartamentos de 25m², todos com decoração moderna. \
           \nEstão em andares intermediários, com vista para a cidade. Piso vinílico, frigobar, \
           \ntv por assinatura, banheiro completo com amenities de banho. Cama Queen Size. \
           \nCafé da manhã e wifi são cortesia. ");
    printf("\n\n__________________________________________________________________Preço da diária: R$%2.f\n",precoC2);
    printf("=========================================================================================\n\n");

    printf("\n======================================MASTER=============================================\n");
    printf("Esta categoria possui apartamentos de 30m², todos com decoração moderna e sacada. \
           \nEstão em andares altos, com vista para a cidade. Piso vinílico, frigobar, \
           \ntv por assinatura e máquina de café Nespresso. Banheiro completo com amenities, \
           \nsecador de cabelo e roupão. Cama King Size. Café da manhã e wifi são cortesia. ");
    printf("\n\n__________________________________________________________________Preço da diária: R$%2.f\n", precoM2);
    printf("=========================================================================================\n\n");

    system("pause");
    return;

}
void diaDoAnoParaData(int diaDoAno, int ano, int *dia, int *mes)
{
    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))
    {
        diasNoMes[2] = 29;
    }

    int i;
    for (i = 1; i <= 12; i++)
    {
        if (diaDoAno <= diasNoMes[i])
        {
            break;
        }
        diaDoAno -= diasNoMes[i];
    }

    *dia = diaDoAno;
    *mes = i;
}
int ValidarDatas(int dia, int mes, int ano)
{
    if (mes >= 1 && mes <= 12)
    {
        if ((mes <= 7 && mes % 2 != 0) || (mes > 7 && mes % 2 == 0))
        {
            if (dia >= 1 && dia <= 31)
            {
                return 1;
            }
        }
        else if (mes == 2)
        {
            if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
            {
                if (dia >= 1 && dia <= 29)
                {
                    return 1;
                }
            }
            else
            {
                if (dia >= 1 && dia <= 28)
                {
                    return 1;
                }
            }
        }
        else
        {
            if (dia >= 1 && dia <= 30)
            {
                return 1;
            }
        }
    }
    return 0;
}
int CompararDataAtual(int Dia, int Mes, int Ano)
{
    time_t current_time;
    struct tm* timeinfo;
    time(&current_time);
    timeinfo = localtime(&current_time);

    if (Ano < timeinfo->tm_year + 1900)
    {
        return -1;
    }
    else if (Ano > timeinfo->tm_year + 1900)
    {
        return 0;
    }
    else
    {
        if (Mes < timeinfo->tm_mon + 1)
        {
            return -1;
        }
        else if (Mes > timeinfo->tm_mon + 1)
        {
            return 0;
        }
        else
        {
            if (Dia < timeinfo->tm_mday)
            {
                return -1;
            }
            else if (Dia > timeinfo->tm_mday)
            {
                return 0;
            }
            else
            {
                return 0;
            }
        }
    }
}
int dataParaDiaDoAno(int dia, int mes, int ano)
{
    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))
    {
        diasNoMes[2] = 29;
    }

    int diaDoAno = dia;
    for (int i = 1; i < mes; i++)
    {
        diaDoAno += diasNoMes[i];
    }

    return diaDoAno;
}
int VerificarSobreposicao(ReservaA reserva[], int *nReservas, int numeroQuarto, int diaDoAnoEntrada, int diaDoAnoSaida, int anoEntrada, int anoSaida)
{
    for (int i = 0; i < *nReservas; i++)
    {

        if ((reserva[i].numeroQuarto == numeroQuarto && reserva[i].fillial == filial)&&
                (anoEntrada==reserva[i].AnoEntrada && anoSaida==reserva[i].AnoSaida)&&
                (diaDoAnoSaida >= reserva[i].diaDoAnoEntrada&& anoEntrada==reserva[i].AnoEntrada)&&
                (diaDoAnoEntrada <= reserva[i].diaDoAnoSaida&& anoSaida==reserva[i].AnoSaida))
        {
            return 1;
        }
        else
        {
            return 0;
        }
        if ((reserva[i].numeroQuarto == numeroQuarto && reserva[i].fillial == filial)&&
            (anoEntrada==reserva[i].AnoEntrada && anoSaida==reserva[i].AnoSaida)&&
            (diaDoAnoSaida >= reserva[i].diaDoAnoEntrada&& anoEntrada==reserva[i].AnoEntrada)&&
            (diaDoAnoEntrada <= reserva[i].diaDoAnoSaida&& anoSaida==reserva[i].AnoSaida)&&
            (reserva[i].AnoEntrada!=reserva[i].AnoSaida)&& ((diaDoAnoSaida >= reserva[i].diaDoAnoEntrada || diaDoAnoEntrada <= reserva[i].diaDoAnoSaida) ||
                        (diaDoAnoSaida <= 366 && diaDoAnoEntrada >= 1))&&
            ((diaDoAnoSaida >= reserva[i].diaDoAnoEntrada || diaDoAnoEntrada <= reserva[i].diaDoAnoSaida) ||
                        (diaDoAnoSaida <= 366 && diaDoAnoEntrada >= 1)))
            {
                        return 1;
            }
            else{
                    return 0;
            }

    }

    for (int i = 0; i < *nReservas; i++)
    {
        if (reserva[i].numeroQuarto == numeroQuarto && reserva[i].fillial == filial)
        {

            if (diaDoAnoEntrada < diaDoAnoSaida)
            {
                if (diaDoAnoSaida >= reserva[i].diaDoAnoEntrada && diaDoAnoEntrada <= reserva[i].diaDoAnoSaida)
                {
                    return 1; // Sobreposição encontrada caso 1, caso 0 sem sobreposicao
                }
            }
            else if (reserva[i].AnoEntrada==anoEntrada)
            {
                if ((diaDoAnoSaida >= reserva[i].diaDoAnoEntrada || diaDoAnoEntrada <= reserva[i].diaDoAnoSaida) ||
                        (diaDoAnoSaida <= 366 && diaDoAnoEntrada >= 1))
                {
                    return 1;
                }

            }
        }

    }
    return 0;
}


int PrecificarQuartoF1(int nnQuarto, float preco)
{
    if(nnQuarto>=1 && nnQuarto<=3)
    {
        preco=precoS1;
    }
    if(nnQuarto>=4 && nnQuarto<=6)
    {
        preco=precoC1;
    }
    if(nnQuarto>=7 && nnQuarto<=9)
    {
        preco=precoM1;
    }
    if(nnQuarto>=10 && nnQuarto<=12)
    {
        preco=precoP1;
    }
    return preco;
}
void Alteradordepreco()
{
    int Estadia;
    float novopreco, novoencarecimento;
    do
    {
        printf("\nQual Estadia, voce deseja alterar o preço?\n");
        printf("[1]Standard\n");
        printf("[2]Comfort\n");
        printf("[3]Master\n");
        if(filial==1)
            printf("[4]Presidencial\n");
        printf("[5] Encarecimento de temporada\n");
        printf("[6] Voltar\n");
        scanf("%d", &Estadia);
        switch(Estadia)
        {
        case 1:
            if(filial==1)
            {
                printf("\nPor favor insira o novo preço da Estadia Standard");
                scanf("%f", &novopreco);
                precoS1=novopreco;
            }
            if(filial==2)
            {
                printf("\nPor favor insira o novo preço da Estadia Standard");
                scanf("%f", &novopreco);
                precoS2=novopreco;

            }
            break;
        case 2:
            if(filial==1)
            {
                printf("\nPor favor insira o novo preço da Estadia Comfort");
                scanf("%f", &novopreco);
                precoC1=novopreco;

            }
            if(filial==2)
            {
                printf("\nPor favor insira o novo preço da Estadia Comfort");
                scanf("%f", &novopreco);
                precoC2=novopreco;

            }
            break;
        case 3:
            if(filial==1)
            {
                printf("\nPor favor insira o novo preço da Estadia Master");
                scanf("%f", &novopreco);
                precoM1=novopreco;

            }
            if(filial==2)
            {
                printf("\nPor favor insira o novo preço da Estadia Master");
                scanf("%f", &novopreco);
                precoM2=novopreco;

            }
            break;
        case 4:
            if(filial==1)
            {
                printf("\nPor favor insira o novo preço da Estadia Presidencial");
                scanf("%f", &novopreco);
                precoP1=novopreco;

            }
            if(filial==2)
                printf("\nOpção Invalida!\n");
            break;
        case 5:
            printf("\nPor favor inisira a porcentagem de encarecimento:\n");
            scanf("%f", &novoencarecimento);
           novoencarecimento=novoencarecimento/100;
            encarecer=novoencarecimento;
            break;
             case 6:
            break;
        default:
            printf("\nOpção Invalida!\n");
        }
    }
    while(Estadia!=6);
    return;
}

int PrecificarQuartoF2(int nnQuarto, float preco)
{
    if(nnQuarto>=1 && nnQuarto<=3)
    {
        preco=precoS2;
    }
    if(nnQuarto>=4 && nnQuarto<=6)
    {
        preco=precoC2;
    }
    if(nnQuarto>=7 && nnQuarto<=9)
    {
        preco=precoM2;
    }

    return preco;
}



void FazerReservasFuncionario(ReservaA reserva[], cadastroCliente cadastroCli[],  int *nReservas, int *numClientes)
{
    int p=1, opcreserva, quebraL=1, codcli, codirese, gapDia;
    float precoR;
    do
    {
        recebedordecheckin(reserva, nReservas);
        if(filial==1)
            precoR=PrecificarQuartoF1(numeroQuarto, precoR);
        if(filial==2)
            precoR=PrecificarQuartoF2(numeroQuarto, precoR);
        if(anoEntrada<anoSaida)
        {
            gapDia=(float)(diaDoAnoSaida+365-diaDoAnoEntrada);
            precoR*= gapDia;
        }

        else if(anoEntrada==anoSaida)
        {
            if(diaDoAnoEntrada < diaDoAnoSaida)
            {
                gapDia=(float)(diaDoAnoSaida-diaDoAnoEntrada);
                precoR*= gapDia;
                    if(diaDoAnoEntrada>335)
                    precoR*=encarecer;
            }
            if(diaDoAnoEntrada == diaDoAnoSaida)
            {
                gapDia=(float)(diaDoAnoSaida+1-diaDoAnoEntrada);
                precoR*= gapDia;
                if(diaDoAnoEntrada>335)
                    precoR*=encarecer;
            }
        }

        reserva[*nReservas].precoreserva=precoR;
        printf("\nData de entrada no dia %d/%d/%d registrada com sucesso!\n", diaEntrada, mesEntrada,anoEntrada);
        printf("\nData de saida no dia %d/%d/%d registrada com sucesso!\n", diaSaida, mesSaida,anoSaida);
        printf("\nCom o preço de R$%2.f\n", precoR);
        reserva[*nReservas].fillial=filial;
        do
        {
            printf("\nVoce deseja:\n");
            printf("\n 1 - Escolher um cliente?");
            printf("\n 2 - Cadastrar novo cliente?\n");
            scanf("%d", &opcreserva);

            codirese=*nReservas+1501;
            reserva[*nReservas].CodRes = codirese;
            switch(opcreserva)
            {
            case 1:
                system("cls");
                exibirClientes(cadastroCli, numClientes);
                if(*numClientes==0)
                {
                    cadastrarCliente(cadastroCli, numClientes);
                    system("cls");
                    exibirClientes(cadastroCli, numClientes);
                }
                printf("\nPor favor insira o codigo do cliente:\n");
                scanf("%d", &codcli);
                int clienteachado= -1;
                for(i=0; i<*numClientes; i++)
                {
                    if(cadastroCli[i].codcad==codcli)
                    {
                        clienteachado=i;
                    }
                }
                strcpy(reserva[*nReservas].cpfR, cadastroCli[clienteachado].cpf);
                strcpy(reserva[*nReservas].nomeR, cadastroCli[clienteachado].nome);
                if(clienteachado == -1)
                {
                    printf("\ncliente nao encontrado\n");
                }
                reserva[*nReservas].fillial=filial;
                strcpy(reserva[*nReservas].USUARIO, NOME);
                reserva[*nReservas].diaDoAnoEntrada = diaDoAnoEntrada;
                reserva[*nReservas].diaDoAnoSaida = diaDoAnoSaida;
                reserva[*nReservas].numeroQuarto = numeroQuarto;
                reserva[*nReservas].AnoSaida = anoSaida;
                reserva[*nReservas].AnoEntrada = anoEntrada;
                reserva[*nReservas].pg=0;
                printf("\nO codigo da reserva é: %d\n",  reserva[*nReservas].CodRes);
                quebraL = 3;
                (*nReservas)++;

                break;
            case 2:
                system("cls");
                cadastrarCliente(cadastroCli, numClientes);
                break;
            default:
                break;
            }
        }
        while(quebraL!=3);

        p = 2;
    }
    while (p != 2);
    system("pause");
    system("cls");
}
void FazerReservasCliente(ReservaA reserva[], cadastroCliente cadastroCli[],  int *nReservas, int *numClientes)
{
    int p=1, opcreserva, quebraL=1, codcli, codirese, apoiodiaDoAnoSaida,apoiodiaDoAnoEntra;
    float precoR, gapDia;
    do
    {
        recebedordecheckin(reserva, nReservas);
        if(filial==1);
        precoR=PrecificarQuartoF1(numeroQuarto, precoR);
        if(filial==2);
        precoR=PrecificarQuartoF2(numeroQuarto, precoR);

        if(anoEntrada<anoSaida)
        {
            gapDia=(float)(diaDoAnoSaida+365-diaDoAnoEntrada);
            precoR*= gapDia;
        }

        else if(anoEntrada==anoSaida)
        {
            if(diaDoAnoEntrada < diaDoAnoSaida)
            {
                gapDia=(float)(diaDoAnoSaida-diaDoAnoEntrada);
                precoR*= gapDia;
                if(diaDoAnoEntrada>335)
                    precoR*=encarecer;
            }
            if(diaDoAnoEntrada == diaDoAnoSaida)
            {
                gapDia=(float)(diaDoAnoSaida+1-diaDoAnoEntrada);
                precoR*= gapDia;
                if(diaDoAnoEntrada>335)
                    precoR*=encarecer;
            }
        }


        reserva[*nReservas].precoreserva = precoR;
        printf("\nData de entrada no dia %d/%d/%d registrada com sucesso!\n", diaEntrada, mesEntrada,anoEntrada);
        printf("\nData de saida no dia %d/%d/%d registrada com sucesso!\n", diaSaida, mesSaida,anoSaida);
        printf("\nCom o preço de R$%2.f\n", precoR);
        reserva[*nReservas].fillial=filial;
        strcpy(reserva[*nReservas].USUARIO, NOME);
        strcpy(reserva[*nReservas].cpfR, CPF);
        strcpy(reserva[*nReservas].nomeR, NOME);
        reserva[*nReservas].diaDoAnoEntrada = diaDoAnoEntrada;
        reserva[*nReservas].diaDoAnoSaida = diaDoAnoSaida;
        reserva[*nReservas].numeroQuarto = numeroQuarto;
        reserva[*nReservas].AnoSaida = anoSaida;
        reserva[*nReservas].AnoEntrada = anoEntrada;
        reserva[*nReservas].pg=0;
        codirese=*nReservas+1501;
        reserva[*nReservas].CodRes = codirese;
        printf("\nO codigo da reserva é: %d\n",  reserva[*nReservas].CodRes);
        (*nReservas)++;
        p=2;
    }
    while (p != 2);
    system("pause");
    system("cls");
}
void ExibirReservas(ReservaA reserva[], cadastroCliente cadastroCli[], int *nReservas)
{
    int MesE, DiaE, anoE, MesS, DiaS, anoS;
    if(*nReservas!=0)
    {
        printf("\n=================== Lista de Reservas ==================\n");
        printf("\n========================================================\n");
    }
    i=0;
    while(i<*nReservas)
    {
        if(reserva[i].CodRes>1)
        {
            diaDoAnoParaData(reserva[i].diaDoAnoEntrada, reserva[i].AnoEntrada, &DiaE, &MesE);
            diaDoAnoParaData(reserva[i].diaDoAnoSaida, reserva[i].AnoSaida, &DiaS, &MesS);
            printf("Código da Reserva: %d\n", reserva[i].CodRes);
            printf("Número do Quarto: %d\n", reserva[i].numeroQuarto);
            printf("Data de Entrada: %02d/%02d/%d - Data de Saída: %02d/%02d/%d\n",DiaE, MesE, reserva[i].AnoEntrada,DiaS,MesS, reserva[i].AnoSaida);
            printf("Nome do Cliente: %s\n", reserva[i].nomeR);
            printf("CPF do Cliente: %s\n", reserva[i].cpfR);
            printf("Preço da Reserva: R$%.2f\n", reserva[i].precoreserva);
            printf("feito por: %s\n", reserva[i].USUARIO);
            if(reserva[i].fillial==1)
                printf("Essa Reserva foi feita na filial Master\n");
            if(reserva[i].fillial==2)
                printf("Essa Reserva foi feita na filial Confort\n");
            if(reserva[i].pg==1)
                printf("Essa Reserva já foi paga\n");
            if(reserva[i].pg==0)
                printf("Essa Reserva nao paga\n");
            printf("\n========================================================\n");
            if(reserva[i].CodRes<1)
                printf("\nNão há reservas!\n");
        }
        i++;
    }


    if(*nReservas==0)
        printf("\nNão há reservas!\n");
}

void VerificarDisponibilidade(ReservaA reserva[], cadastroCliente cadastroCli[], int *nReservas)
{
    int MesE, DiaE, anoE, MesS, DiaS, anoS;
    if(*nReservas!=0)
    {
        printf("\n=================== Lista de Reservas ==================\n");
        printf("========================================================\n");
    }
    i=0;
    while(i<*nReservas)
    {
        if(reserva[i].CodRes>1500&&strcmp(reserva[i].nomeR,NOME)!=0)
        {
            diaDoAnoParaData(reserva[i].diaDoAnoEntrada, reserva[i].AnoEntrada, &DiaE, &MesE);
            diaDoAnoParaData(reserva[i].diaDoAnoSaida, reserva[i].AnoSaida, &DiaS, &MesS);
            printf("Número do Quarto: %2.d\t Filial: %d\n", reserva[i].numeroQuarto, reserva[i].fillial);
            printf("Data de Entrada: %02.d/%02.d/%d - Data de Saída: %02.d/%02.d/%d\n",DiaE, MesE, reserva[i].AnoEntrada,DiaS,MesS, reserva[i].AnoSaida);
            printf("\n========================================================\n");
            if(reserva[i].CodRes<1)
                printf("\nNão há reservas!\n");
        }
        if(strcmp(reserva[i].nomeR,NOME)==0)
        {
            diaDoAnoParaData(reserva[i].diaDoAnoEntrada, reserva[i].AnoEntrada, &DiaE, &MesE);
            diaDoAnoParaData(reserva[i].diaDoAnoSaida, reserva[i].AnoSaida, &DiaS, &MesS);
            printf("Código da Reserva: %d\n", reserva[i].CodRes);
            printf("Número do Quarto: %d\n", reserva[i].numeroQuarto);
            printf("Data de Entrada: %02d/%02d/%d - Data de Saída: %02d/%02d/%d\n",DiaE, MesE, reserva[i].AnoEntrada,DiaS,MesS, reserva[i].AnoSaida);
            printf("Nome do Cliente: %s\n", reserva[i].nomeR);
            printf("CPF do Cliente: %s\n", reserva[i].cpfR);
            printf("Preço da Reserva: R$%.2f\n", reserva[i].precoreserva);
            printf("feito por: %s\n", reserva[i].USUARIO);
            if(reserva[i].fillial==1)
                printf("Essa Reserva foi feita na filial Master\n");
            if(reserva[i].fillial==2)
                printf("Essa Reserva foi feita na filial Confort\n");
            if(reserva[i].pg==1)
                printf("Essa Reserva já foi paga\n");
            if(reserva[i].pg==0)
                printf("Essa Reserva nao foi paga\n");
            printf("\n========================================================\n");
            if(reserva[i].CodRes<1500)
                printf("\nNão há reservas!\n");
            printf("As outras Datas estão Disponiveis!\n");
        }
        i++;
    }


    if(*nReservas==0)
        printf("\nNão há reservas!\n");

}
void ExibirReservasCliente(ReservaA reserva[], cadastroCliente cadastroCli[], int *nReservas)
{
    int MesE, DiaE, anoE, MesS, DiaS, anoS, acho=0;
    if(*nReservas!=0)
    {
        printf("\n=================== Lista de Reservas ==================\n");
    }

    for(i=0; i<*nReservas; i++)
    {
        if(reserva[i].CodRes>1500&& strcmp(reserva[i].nomeR,NOME)==0)
        {
            {
                diaDoAnoParaData(reserva[i].diaDoAnoEntrada, reserva[i].AnoEntrada, &DiaE, &MesE);
                diaDoAnoParaData(reserva[i].diaDoAnoSaida, reserva[i].AnoSaida, &DiaS, &MesS);
                printf("Código da Reserva: %d\n", reserva[i].CodRes);
                printf("Número do Quarto: %d\n", reserva[i].numeroQuarto);
                printf("Data de Entrada: %02d/%02d/%d - Data de Saída: %02d/%02d/%d\n",DiaE, MesE, reserva[i].AnoEntrada,DiaS,MesS, reserva[i].AnoSaida);
                printf("Nome do Cliente: %s\n", reserva[i].nomeR);
                printf("CPF do Cliente: %s\n", reserva[i].cpfR);
                printf("Preço da Reserva: R$%.2f\n", reserva[i].precoreserva);
                printf("feito por: %s\n", reserva[i].USUARIO);
                if(reserva[i].fillial==1)
                    printf("Essa Reserva foi feita na filial Master\n");
                if(reserva[i].fillial==2)
                    printf("Essa Reserva foi feita na filial Confort\n");
                if(reserva[i].pg==1)
                    printf("Essa Reserva já foi paga\n");
                if(reserva[i].pg==0)
                    printf("Essa Reserva nao foi paga\n");
                printf("\n========================================================\n");
                if(reserva[i].CodRes<1)
                    printf("\nNão há reservas!\n");
                acho=1;
            }

        }
    }

    if(acho==0)
        printf("\nVoce ainda nao tem Reservas!\n");
    if(*nReservas==0)
        printf("\nNão há reservas!\n");

}
void MoverReservas(ReservaA reserva[], int *nReservas)
{
    int procura0 = 0;

    for (int i = 0; i < *nReservas; i++)
    {
        if (reserva[i].CodRes != 0)
        {
            reserva[procura0] = reserva[i];
            procura0++;
        }
    }


    for (int i = procura0; i < *nReservas; i++)
    {
        memset(&reserva[i], 0, sizeof(ReservaA));
    }


    *nReservas = procura0;
}
void CancelarReserva(ReservaA reserva[], int *nReservas)
{
    int acho = 0, caso;
    if (*nReservas == 0)
    {
        printf("\nNao há reservas para cancelar.\n");
        return;
    }


    int codigoreserv;
    printf("Digite o número da reserva que deseja cancelar (0 para cancelar nenhuma): ");
    scanf("%d", &codigoreserv);

    if (codigoreserv == 0)
    {
        printf("Cancelamento de reserva cancelado.\n");
        return;
    }

    for (i = 0; i < *nReservas; i++)
    {
        if (reserva[i].CodRes == codigoreserv)
        {

            memset(&reserva[i], 0, sizeof(ReservaA));
            acho = 1;
            break;
        }
    }

    if (acho==1)
    {
        MoverReservas(reserva, nReservas);
        printf("\n[1]Por favor insira 1 caso seja necessario aplicar multa!\n[1](cancelamento de reserva sendo feito depois de 20 dias de antecedencia)[1]\n");
        printf("[0]Insira 0 caso nao seja necessario aplica multa[0]\n");
        scanf("%d",&caso);
    }
    if(caso==1)
    {
        for (i = 0; i < *nReservas; i++)
        {
            if (reserva[i].CodRes == codigoreserv)
            {

                multa+=reserva[i].CodRes*0.20;
                acho = 1;
                break;
            }
        }

        printf("Reserva cancelada com sucesso.\n");
        system("pause");
    }
    if(acho==0)
    {
        printf("Reserva nao encontrada.\n");
        system("pause");
    }
}
void ConcluirReserva(ReservaA reserva[], Pago reservc[], int *nReservas, int *nReserC)
{
    int acho = 0, caso;
    if (*nReservas == 0)
    {
        printf("\nNão há reservas para concluir.\n");
        return;
    }

    int codigoreserv;
    printf("Digite o número da reserva que deseja concluir (digite 0 para cancelar): ");
    scanf("%d", &codigoreserv);

    if (codigoreserv == 0)
    {
        printf("Conclusão da reserva cancelada.\n");
        return;
    }

    for (int i = 0; i < *nReservas; i++)
    {
        if (reserva[i].CodRes == codigoreserv)
        {
            if(reserva[i].pg==1)
            {
                reservc[*nReserC].AnoEntrada = reserva[i].AnoEntrada;
                reservc[*nReserC].AnoSaida = reserva[i].AnoSaida;
                reservc[*nReserC].diaDoAnoEntrada = reserva[i].diaDoAnoEntrada;
                reservc[*nReserC].diaDoAnoSaida = reserva[i].diaDoAnoSaida;
                reservc[*nReserC].numeroQuarto = reserva[i].numeroQuarto;
                reservc[*nReserC].precoreserva = reserva[i].precoreserva;
                reservc[*nReserC].fillial = reserva[i].fillial;
                (*nReserC)++;
                memset(&reserva[i], 0, sizeof(ReservaA));
                acho = 1;
                break;
            }
            else
            {
                printf("\nOperação Cancelada : Reserva ainda não paga!\n");
                system("pause");
            }
        }
    }

    if (acho == 1)
    {
        MoverReservas(reserva, nReservas);
        printf("Reserva concluída com sucesso.\n");
        system("pause");
    }
    if (acho==0)
    {
        printf("Reserva não encontrada.\n");
        system("pause");
    }
}
void LeitorFaturamento(ReservaA reserva[],Pago reserc[], int *nReservas, int *nReserc)
{
    float soma = 0, somanaopg = 0, somapg = 0, somaS = 0, somaC = 0, somaM = 0, somaP = 0, somaf=0, soma1S=0, soma1C=0, soma1M=0, soma1P=0, soma2=0, soma2pg=0, soma2S=0, soma2C=0, soma2M=0;
    float nsoma1S=0,nsoma1C=0,nsoma1M=0,nsoma1P=0,nsoma2S=0,nsoma2C=0,nsoma2M=0,nsomaS = 0,nsomaC = 0,nsomaM = 0,nsomaP = 0;
    int contreservapg = 0, contreservanaopg = 0, contS = 0, contC = 0, contM = 0, contP = 0, contreserva=0;
    i = 0;

    while (i < *nReservas)
    {
        if (reserva[i].CodRes > 1500)
        {
            soma += reserva[i].precoreserva;
            contreserva++;
            if (reserva[i].pg == 1)
            {
                somapg += reserva[i].precoreserva;
                contreservapg++;

                if (reserva[i].numeroQuarto >= 1 && reserva[i].numeroQuarto <= 3)
                {
                    somaS += reserva[i].precoreserva;
                    if(reserva[i].fillial==1)
                        soma1S+= reserva[i].precoreserva;
                    if(reserva[i].fillial == 2)
                        soma2S += reserva[i].precoreserva;
                    contS++;
                }
                else if (reserva[i].numeroQuarto >= 4 && reserva[i].numeroQuarto <= 6)
                {
                    somaC += reserva[i].precoreserva;
                    if(reserva[i].fillial==1)
                        soma1C+=reserva[i].precoreserva;
                    if(reserva[i].fillial == 2)
                        soma2C += reserva[i].precoreserva;
                    contC++;
                }
                else if (reserva[i].numeroQuarto >= 7 && reserva[i].numeroQuarto <= 9)
                {
                    somaM += reserva[i].precoreserva;
                    if(reserva[i].fillial==1)
                        soma1M+=reserva[i].precoreserva;
                    if(reserva[i].fillial == 2)
                        soma2M += reserva[i].precoreserva;
                    contM++;
                }
                else if (reserva[i].numeroQuarto >= 10 && reserva[i].numeroQuarto <= 12)
                {
                    somaP += reserva[i].precoreserva;
                    if(reserva[i].fillial==1)
                        soma1P+=reserva[i].precoreserva;
                    contP++;
                }
            }
            else if (reserva[i].pg == 0)
            {
                somanaopg += reserva[i].precoreserva;
                contreservanaopg++;
                if (reserva[i].numeroQuarto >= 1 && reserva[i].numeroQuarto <= 3)
                {
                    nsomaS += reserva[i].precoreserva;
                    if(reserva[i].fillial==1)
                        nsoma1S+= reserva[i].precoreserva;
                    if(reserva[i].fillial == 2)
                        nsoma2S += reserva[i].precoreserva;
                    contS++;
                }
                else if (reserva[i].numeroQuarto >= 4 && reserva[i].numeroQuarto <= 6)
                {
                    nsomaC += reserva[i].precoreserva;
                    if(reserva[i].fillial==1)
                        nsoma1C+=reserva[i].precoreserva;
                    if(reserva[i].fillial == 2)
                        nsoma2C += reserva[i].precoreserva;
                    contC++;
                }
                else if (reserva[i].numeroQuarto >= 7 && reserva[i].numeroQuarto <= 9)
                {
                    nsomaM += reserva[i].precoreserva;
                    if(reserva[i].fillial==1)
                        nsoma1M+=reserva[i].precoreserva;
                    if(reserva[i].fillial == 2)
                        nsoma2M += reserva[i].precoreserva;
                    contM++;
                }
                else if (reserva[i].numeroQuarto >= 10 && reserva[i].numeroQuarto <= 12)
                {
                    nsomaP += reserva[i].precoreserva;
                    if(reserva[i].fillial==1)
                        nsoma1P+=reserva[i].precoreserva;
                    contP++;
                }
            }
        }

        i++;
    }
    i = 0;

    while (i < *nReserc)
    {

        somapg += reserc[i].precoreserva;
        contreservapg++;

        if (reserc[i].numeroQuarto >= 1 && reserc[i].numeroQuarto <= 3)
        {
            somaS += reserc[i].precoreserva;
            if(reserc[i].fillial==1)
                soma1S+=reserc[i].precoreserva;
            if(reserc[i].fillial == 2)
                soma2S += reserc[i].precoreserva;
            contS++;
        }
        else if (reserc[i].numeroQuarto >= 4 && reserc[i].numeroQuarto <= 6)
        {
            somaC += reserc[i].precoreserva;
            if(reserc[i].fillial==1)
                soma1C+=reserc[i].precoreserva;
            if(reserc[i].fillial == 2)
                soma2C += reserc[i].precoreserva;
            contC++;
        }
        else if (reserc[i].numeroQuarto >= 7 && reserc[i].numeroQuarto <= 9)
        {
            somaM += reserc[i].precoreserva;
            if(reserc[i].fillial==1)
                soma1M+=reserc[i].precoreserva;
            if(reserc[i].fillial == 2)
                soma2M += reserc[i].precoreserva;
            contM++;
        }
        else if (reserc[i].numeroQuarto >= 10 && reserc[i].numeroQuarto <= 12)
        {
            somaP += reserc[i].precoreserva;
            if(reserc[i].fillial==1)
                soma1P+=reserc[i].precoreserva;
            contP++;
        }
        i++;
    }

    printf("\n===========================\n");
    printf("\nFaturamento Geral");
    printf("\nR$%.2f", soma);
    printf("\nForam %d reservas\n", contreserva);
    printf("\n===========================\n");


    printf("\nFaturamento á Receber");
    printf("\nR$%.2f", somanaopg);
    printf("\nForam %d reservas\n", contreservanaopg);
    printf("\n===========================\n");


    printf("\nFaturamento Recebido");
    printf("\nR$%.2f", somapg);
    printf("\nForam %d reservas\n", contreservapg);
    printf("\n===========================\n");


    printf("\nFaturamento Standard");
    printf("\nJá pago");
    printf("\nR$%.2f\tFilial 1:R$%.2f \tFilial 2:R$%.2f", somaS, soma1S,soma2S);
    printf("\nAinda nao pago");
    printf("\nR$%.2f\tFilial 1:R$%.2f \tFilial 2:R$%.2f", nsomaS, nsoma1S,nsoma2S);
    printf("\nForam %d reservas\n", contS);
    printf("\n===========================\n");


    printf("\nFaturamento Confort");
    printf("\nJá pago");
    printf("\nR$%.2f\tFilial 1:R$%.2f \tFilial 2:R$%.2f", somaC, soma1C,soma2C);
    printf("\nAinda nao pago");
    printf("\nR$%.2f\tFilial 1:R$%.2f \tFilial 2:R$%.2f", nsomaC, nsoma1C,nsoma2C);
    printf("\nForam %d reservas\n", contC);
    printf("\n===========================\n");


    printf("\nFaturamento Master");
    printf("\nJá pago");
    printf("\nR$%.2f\tFilial 1:R$%.2f \tFilial 2:R$%.2f", somaM, soma1M,soma2M);
    printf("\nAinda nao pago");
    printf("\nR$%.2f\tFilial 1:R$%.2f \tFilial 2:R$%.2f", nsomaM, nsoma1M,nsoma2M);
    printf("\nForam %d reservas\n", contM);
    printf("\n===========================\n");


    printf("\nFaturamento Presidencial");
    printf("\nJá pago");
    printf("\nR$%.2f\tFilial 1:R$%.2f", somaP, soma1P);
    printf("\nAinda nao pago");
    printf("\nR$%.2f\tFilial 1:R$%.2f", nsomaP, nsoma1P);
    printf("\nForam %d reservas\n", contP);
    printf("\n===========================\n");
    system("pause");
}

void definirCorConsole()
{
    char Paleta[10], textoC[3],planoDeFundoC[3];
    int planoDeFundo, texto;

    printf("Cores disponiveis!\n");
    printf("0-Preto!\n");
    printf("1-Azul!\n");
    printf("2-Verde!\n");
    printf("3-Verde-Agua!\n");
    printf("4-Vermelho!\n");
    printf("5-Roxo!\n");
    printf("6-Amarelo!\n");
    printf("7-Branco!\n");
    printf("8-Cinza!\n");
    printf("9-Azul Claro!\n");
    printf("10-Verde Claro!\n");
    printf("11-Verde-agua Claro!\n");
    printf("12-Vermelho Claro!\n");
    printf("13-Rosa!\n");
    printf("14-Amarelo Claro!\n");
    printf("15-Branco Brilhante!\n");


    printf("\nEscolha a cor do plano de fundo (0-15): ");
    scanf("%d", &planoDeFundo);
    fflush(stdin);
    if(planoDeFundo==0)
        strcpy(planoDeFundoC,"0");
    if(planoDeFundo==1)
        strcpy(planoDeFundoC,"1");
    if(planoDeFundo==2)
        strcpy(planoDeFundoC,"2");
    if(planoDeFundo==3)
        strcpy(planoDeFundoC,"3");
    if(planoDeFundo==4)
        strcpy(planoDeFundoC,"4");
    if(planoDeFundo==5)
        strcpy(planoDeFundoC,"5");
    if(planoDeFundo==6)
        strcpy(planoDeFundoC,"6");
    if(planoDeFundo==7)
        strcpy(planoDeFundoC,"7");
    if(planoDeFundo==8)
        strcpy(planoDeFundoC,"8");
    if(planoDeFundo==9)
        strcpy(planoDeFundoC,"9");
    if(planoDeFundo==10)
        strcpy(planoDeFundoC,"A");
    if(planoDeFundo==11)
        strcpy(planoDeFundoC,"B");
    if(planoDeFundo==12)
        strcpy(planoDeFundoC,"C");
    if(planoDeFundo==13)
        strcpy(planoDeFundoC,"D");
    if(planoDeFundo==14)
        strcpy(planoDeFundoC,"E");
    if(planoDeFundo==15)
        strcpy(planoDeFundoC,"F");




    printf("Escolha a cor do texto (0-15): ");
    scanf("%d", &texto);
    fflush(stdin);
    if(texto==0)
        strcpy(textoC,"0");
    if(texto==1)
        strcpy(textoC,"1");
    if(texto==2)
        strcpy(textoC,"2");
    if(texto==3)
        strcpy(textoC,"3");
    if(texto==4)
        strcpy(textoC,"4");
    if(texto==5)
        strcpy(textoC,"5");
    if(texto==6)
        strcpy(textoC,"6");
    if(texto==7)
        strcpy(textoC,"7");
    if(texto==8)
        strcpy(textoC,"8");
    if(texto==9)
        strcpy(textoC,"9");
    if(texto==10)
        strcpy(textoC,"A");
    if(texto==11)
        strcpy(textoC,"B");
    if(texto==12)
        strcpy(textoC,"C");
    if(texto==13)
        strcpy(textoC,"D");
    if(texto==14)
        strcpy(textoC,"E");
    if(texto==15)
        strcpy(textoC,"F");

    if (planoDeFundo >= 0 && planoDeFundo <= 15 && texto >= 0 && texto <= 15)
    {
        sprintf(Paleta, "color %s%s", textoC, planoDeFundoC);
        system(Paleta);
    }
    else
    {
        printf("Cores fora do intervalo válido (0-15).\n");
    }
}

void definidorfuncionarios(funcionarios Funcionarios[], int *nFuncionarios)
{
    strcpy(Funcionarios[0].nome,"Dorcas");
    strcpy(Funcionarios[0].senha,"0000");
    Funcionarios[0].cargo=1;
    (*nFuncionarios)++;
    strcpy(Funcionarios[1].nome,"Murilo");
    strcpy(Funcionarios[1].senha,"123");
    Funcionarios[1].cargo=1;
    (*nFuncionarios)++;

    strcpy(Funcionarios[2].nome,"Adrian");
    strcpy(Funcionarios[2].senha,"123");
    Funcionarios[2].cargo=1;
    (*nFuncionarios)++;

    strcpy(Funcionarios[3].nome,"Joao");
    strcpy(Funcionarios[3].senha,"123");
    Funcionarios[3].cargo=1;
    (*nFuncionarios)++;

    strcpy(Funcionarios[4].nome,"Giovana");
    strcpy(Funcionarios[4].senha,"123");
    Funcionarios[4].cargo=1;
    (*nFuncionarios)++;
}

int validadorquarto(int numQuarto)
{

    if(filial==1)
    {
        if(numQuarto < 1 || numQuarto > 12)
            return 0;
        else
        {
            return 1;
        }
    }
    else if(filial==2)
    {
        if(numQuarto < 1 || numQuarto > 9)
            return 0;
        else
        {
            return 1;
        }
    }

}

int recebedordecheckin(ReservaA reserva[], int*nReservas)
{
    int VerOut=0, VerSob, valin, compin, valout, compout, valquarto;
    do
    {
        do
        {
            printf("\n---------------Fazer uma Reserva---------------\n");
            printf("\n===============STANDARD==============\n");
            printf("[1]Quarto\t");
            printf("[2]Quarto\t");
            printf("[3]Quarto");
            printf("\n===============COMFORT===============\n");
            printf("[4]Quarto\t");
            printf("[5]Quarto\t");
            printf("[6]Quarto");
            printf("\n===============MASTER================\n");
            printf("[7]Quarto\t");
            printf("[8]Quarto\t");
            printf("[9]Quarto");
            if(filial==1)
            {
                printf("\n=============PRESIDENCIAL============\n");
                printf("[10]Quarto\t");
                printf("[11]Quarto\t");
                printf("[12]Quarto");
            }
            printf("\nDigite o numero do quarto:\n");

            scanf("%d", &numeroQuarto);
            fflush(stdin);
            valquarto=validadorquarto(numeroQuarto);

        }
        while(valquarto!=1);
        do
        {
            printf("\nDigite a data de Check-in desta forma DD/MM/AAAA:");
            scanf("%d/%d/%d", &diaEntrada, &mesEntrada, &anoEntrada);
            fflush(stdin);
            valin = ValidarDatas( diaEntrada,  mesEntrada,  anoEntrada) ;
            compin = CompararDataAtual ( diaEntrada,  mesEntrada, anoEntrada);
            if (valin == 0)
            {
                printf("\n\t|xxxxx|-Data de Check-in Inválida-|xxxxx|\n");
                printf("\nPor Favor Insira Novamente:\n");
            }
            if (compin == -1)
            {
                printf("\n\t|xxxxx|-Data de Check-in já passou-|xxxxx|\n");
                printf("\nPor Favor Insira Novamente:\n");
            }
        }
        while (valin  != 1 || compin != 0);
        do
        {
            printf("Digite a data de Check-out desta forma DD/MM/AAAA:");
            scanf("%d/%d/%d", &diaSaida, &mesSaida, &anoSaida);
            fflush(stdin);
            valout = ValidarDatas(diaSaida, mesSaida, anoSaida);
            compout =  CompararDataAtual ( diaSaida,  mesSaida, anoSaida);
            if (valout == 0)
            {
                printf("\n\t|xxxxx|-Data de Check-out Inválida-|xxxxx|\n");
                printf("\nPor Favor Insira Novamente:\n");
            }
            if (compout == 1)
            {
                printf("\n\t|xxxxx|-Data de Check-out já passou-|xxxxx|\n");
                printf("\nPor Favor Insira Novamente:\n");
            }

            diaDoAnoEntrada = dataParaDiaDoAno(diaEntrada, mesEntrada, anoEntrada);
            diaDoAnoSaida = dataParaDiaDoAno(diaSaida, mesSaida, anoSaida);
            VerOut = VerificarCheckout(diaDoAnoEntrada, diaDoAnoSaida, anoEntrada, anoSaida);
            if (VerOut != 1)
            {
                printf("\n\t|xxxxx|-Data de Check-out Inválida (data de check-out menor que à data de check-in)-|xxxxx|\n");
                printf("\nPor Favor Insira Novamente:\n");
            }

        }
        while (valout != 1 || compout !=0 || VerOut != 1);
        VerSob = VerificarSobreposicao(reserva, nReservas, numeroQuarto, diaDoAnoEntrada, diaDoAnoSaida, anoEntrada, anoSaida);

        if (VerSob == 1)
        {
            printf("\n\t|xxxxx|-Conflito de datas com outra reserva-|xxxxx|\n");
            printf("\nPor Favor Insira Novamente:\n");
        }
    }
    while (VerSob != 0);
}

int VerificarCheckout(int diaDoAnoEntrada, int diaDoAnoSaida, int anoEntrada, int anoSaida)
{
    int VerOut = 0;

    if (anoEntrada < anoSaida)
    {
        VerOut = 1;
    }
    else if (anoEntrada == anoSaida)
    {
        if (diaDoAnoEntrada <= diaDoAnoSaida)
        {
            VerOut = 1;
        }
    }

    return VerOut;
}

int boleto(nClientes, client, reservas);
void cliente(nClientes, client);
int formaPagamento(int nClientes, cadastroCliente client[], ReservaA reserva[])
{

    int opcao;

    printf("\n|================================\n");
    printf("|======Formas de Pagamentos======\n");
    printf("|[1]Cartao\n"); //credito // debito
    printf("|[2]Dinheiro\n");
    printf("|[3]Boleto\n");
    printf("|[4]pix\n");
    printf("|[0]Cancelar\n");
    printf("|================================\n");
    printf("Digite a forma de pagamento: ");
    scanf("%d", &opcao);
    //system("cls");
    switch (opcao)
    {
    case 1:
        printf("\n________________________________________________________________________________________________________\n");
        printf("\t\t\t\t\tPagamento em Cartão.");
        printf("\n________________________________________________________________________________________________________\n");
        cartao(nClientes, client, reserva);
        printf("\n________________________________________________________________________________________________________\n");

        break;
    case 2:
        printf("\n________________________________________________________________________________________________________\n");
        printf("\t\tPagamento em Dinheiro.");
        printf("Seu pagamento será cobrado no Check-out!\n");
        printf("\n________________________________________________________________________________________________________\n");
        system("pause");
        break;
    case 3:
        printf("\n________________________________________________________________________________________________________\n");
        printf("\t\t\t\t\tPagamento em Boleto.");
        printf("\n========================================================================================================\n");
        boleto(nClientes, client, reserva);
        break;
    case 4:
        printf("\n________________________________________________________________________________________________________\n");
        printf("\t\t\t\t\tPagamento em Pix.");
        printf("\n________________________________________________________________________________________________________\n");
        printf("Chave pix: \n\t12 345 678 0001 00");
        printf("\n________________________________________________________________________________________________________\n");

        break;
    case 0:
        printf("Pagamento cancelado.\n");
        break;
    default:
        printf("Opção inválida.\n");
        break;
    }
    return 0;
}

void valorReserva(nClientes,reservas);
void cartao(nClientes, client, reserva);

int boleto(int nClientes, cadastroCliente client[], ReservaA reserva[])
{

    int numDoc;
    numDoc++;
    time_t agora = time(NULL);
    char hoje[20];
    strftime(hoje, sizeof(hoje), "%d/%m/%Y", localtime(&agora));

    printf("\n________________________________________________________________________________________________________\n");
    printf("Nome do Beneficiario: \t\t\t\t\t\t\t| CNPJ:");
    printf("\n\tHotel suite confort \t\t\t\t\t\t| 12.345.678/0001-00");
    printf("\n________________________________________________________________________|_______________________________\n");
    printf("Data do Documento\t\t|N Do Documento: \t\t|Valor:");
    printf("\n\tData: %s \t|", hoje);
    numeroDoc(numDoc);
    printf("\t|");
    valorReserva(nClientes,reserva);
    printf("\n________________________________|_______________________________|_______________________________________\n");
    cod();
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("Local de Pagamento:\t\t\t\t\t| Vencimento:\n");
    printf("\tEm qualquer banco ate o vencimento\t\t|");
    printf("\tvencimento");
    printf("\n________________________________________________________|_______________________________________________\n");
    printf("Instrucoes:\n\n");
    printf("1) NAO ACEITAR PAGAMENTO EM CHEQUE\n\n");
    printf("2) NAO ACEITAR MAIS DE UM PAGAMENTO COM O MESMO BOLETO\n\n");
    printf("3) EM CASO DE VENCIMENTO NO FIM DE SEMANA OU FERIADO, ACEITAR O PAGAMENTO ATE O PRIMEIRO DIAS UTIL APOS \nO VENCIMENTOS\n");
    printf("\n\n________________________________________________________________________________________________________\n");
    printf("Beneficiario:\n\n");
    enderecoMatriz();
    printf("\n________________________________________________________________________________________________________\n");
    printf("Pagador:\n");
    cliente(nClientes, client);
    printf("\n________________________________________________________________________________________________________\n\n");
    codBarra();
    return 0;
}

void numeroDoc(int *numDoc)
{
    printf("\t001230045600789.%d", numDoc);
    return;
}

void cod()
{
    int cont = 0;
    int numeros[48];

    printf("\n--------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < 47; i++)
    {
        numeros[i] = rand() % 10;
    }
    printf("\n\n");
    for (int i = 0; i < 47; i++)
    {
        if (cont <= 0)
        {
            printf("\t\t\t\t\t| 123-4 | ");
        }
        printf("%d", numeros[i]);
        if(cont == 5)
        {
            printf(".");
        }
        if(cont == 10)
        {
            printf(" ");
        }
        if(cont == 15)
        {
            printf(".");
        }
        if(cont == 21)
        {
            printf(" ");
        }
        if(cont == 26)
        {
            printf(".");
        }
        if(cont == 32)
        {
            printf(" ");
        }
        if(cont == 33)
        {
            printf(" ");
        }
        cont++;
    }
    printf("\n");

    return;
}

void codBarra()
{
    int cont = 0;
    for (int j = 0; j < 2; j++)
    {
        if(cont <= 0)
        {
            printf("\t\t\t\t\t\t|");
        }
        if(cont == 1)
        {
            printf("\t\t\t\t\t\t|");
        }
        cont++;
        for (int i = 0; i < 8; i++)
        {
            printf("|||||| ");
        }
        printf("\n");
    }
    printf("\n--------------------------------------------------------------------------------------------------------\n");
}

void valorReserva(int nclientes, ReservaA reserva[])
{

    printf("\tR$ %.2f", reserva[nclientes - 1].precoreserva);
}

void enderecoMatriz()
{
    printf("\tSuites Algaritmos:\n");
    printf("\tEndereco: Araraquara-SP");
    return;
}

void cliente(int nClientes, cadastroCliente client[])
{

    printf("\t%s\n", client[nClientes - 1].nome);
    int opcao;
    printf("\t\t\t\t\tCodigo de Barra");
    return;
}

void cartao(int nClientes, cadastroCliente client[], ReservaA reserva[])
{

    int opcao, dia, mes, ano;


    printf("%s\n", client[nClientes - 1].nome);
    printf("CPF: %s\n", client[nClientes - 1].cpf);

    int numero_cartao1, numero_cartao2, numero_cartao3, numero_cartao4;
    int codigo_seguranca;

    printf("\nNº cartao: 0000 0000 0000 0000\n");
    scanf("%d %d %d %d", &numero_cartao1, &numero_cartao2, &numero_cartao3, &numero_cartao4);

    printf("\nData de validade: dd/mm/yyyy\n");
    scanf("%d%d%d",&dia, &mes, &ano);

    fflush(stdin);

    printf("\nCód de segurança: 000\n");
    scanf("%d",&codigo_seguranca);
    return;
}


void confirmarPagamento(ReservaA reserva[], int *nReservas)
{
    int opcao,codigorese,reservaachada;
    printf("\nDigite o codigo de reserva:\n");
    scanf("%d", &codigorese);
    if(*nReservas>0)
    {

        for(i=0; i<*nReservas; i++)
        {
            if(codigorese==reserva[i].CodRes)
                reservaachada=i;
        }

    }
    if(*nReservas==0)
        printf("\nNão há reservas!");
    do
    {
        printf("\n\nConfirmar pagamento [1][sim]  [2][cancelar]\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Pagamento confirmado!\n");
            break;
        case 2:
            printf("Pagamento cancelado!\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    }
    while(opcao < 0 || opcao > 2);



    if(opcao == 1)
    {
        reserva[reservaachada].pg = 1;
    }
    printf("\n%d", reserva[reservaachada].pg);
    system("pause");
    return;
}

