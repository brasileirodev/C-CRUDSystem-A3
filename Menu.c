//@HÉCTOR VALENTE (22/11/2023) - Menu e implementação da usabilidade inscrição de disciplina.
//@LUCAS (23/11/2023) - Menu e implementação da usabilidade cadastro de aluno.
//@HÉCTOR VALENTE (23/11/2023) - Correção caracter especial + função inclusão em método

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000


#define MAX_ALUNOS 100
#define MAX_MATRICULA 20
#define MAX_CPF 11 
#define MAX_NOME 30
#define MAX_EMAIL 50


struct Aluno {
    int matricula;
    char cpf[MAX_CPF];
    char nome[MAX_NOME];
    char sexo;
    char email[MAX_EMAIL];
    int codigoTipoCurso;
};

void imprimirAluno(struct Aluno aluno) {
    printf("Matrícula: %d\n", aluno.matricula);
    printf("CPF: %s\n", aluno.cpf);
    printf("Nome: %s\n", aluno.nome);
    printf("Sexo: %c\n", aluno.sexo);
    printf("Email: %s\n", aluno.email);
    printf("Código do tipo de curso: %d\n", aluno.codigoTipoCurso);
}

void cadastrarAluno(struct Aluno alunos[], int *numAlunos) {
    if (*numAlunos >= MAX_ALUNOS) {
        printf("Limite máximo de alunos atingido!\n");
        return;
    }

    struct Aluno novoAluno;

    printf("Digite a matrícula: ");
    scanf("%d", &novoAluno.matricula);

    while (1) {
        printf("Digite o CPF: ");
        scanf("%s", novoAluno.cpf);

        // Verifica se o CPF tem exatamente 11 dígitos
        if (strlen(novoAluno.cpf) != 11) {
            printf("CPF inválido.\n");
        } else {
            break;
        }
    }

    printf("Digite o nome: ");
    scanf("%s", novoAluno.nome);

    printf("Digite o sexo: ");
    scanf(" %c", &novoAluno.sexo);

    printf("Digite o email: ");
    scanf("%s", novoAluno.email);

    printf("Digite o código do tipo de curso: ");
    scanf("%d", &novoAluno.codigoTipoCurso);

    // Copia o novoAluno para o array de alunos
    alunos[*numAlunos] = novoAluno;

    (*numAlunos)++;

    printf("Aluno cadastrado com sucesso!\n");

    // Imprime os dados do aluno cadastrado
    printf("Dados do aluno cadastrado:\n");
    imprimirAluno(novoAluno);
}


void atualizarAluno(struct Aluno alunos[], int numAlunos) {
    int matricula;

    printf("Digite a matrícula do aluno que deseja atualizar: ");
    scanf("%d", &matricula);

    for (int contador = 0; contador < numAlunos; contador++) {
        if (alunos[contador].matricula == matricula) {
            printf("Digite a nova matrícula: ");
            scanf("%d", &alunos[contador].matricula);

            while (1) {
                printf("Digite o novo CPF: ");
                scanf("%s", alunos[contador].cpf);

                // Verifica se o CPF tem exatamente 11 dígitos
                if (strlen(alunos[contador].cpf) != 11) {
                    printf("CPF inválido.\n");
                } else {
                    break;
                }
            }

            printf("Digite o novo nome: ");
            scanf("%s", alunos[contador].nome);

            printf("Digite o sexo: ");
            scanf(" %c", &alunos[contador].sexo);

            printf("Digite o novo email: ");
            scanf("%s", alunos[contador].email);

            // Verifica se os campos de nome e email não excedem os limites máximos
            if (strlen(alunos[contador].nome) > MAX_NOME || strlen(alunos[contador].email) > MAX_EMAIL) {
                printf("Um ou mais campos excedem o tamanho máximo permitido.\n");
                return;
            }

            printf("Digite o novo código do tipo de curso: ");
            scanf("%d", &alunos[contador].codigoTipoCurso);

            printf("Aluno atualizado com sucesso!\n");

            // Imprime os dados do aluno atualizado
            printf("Dados do aluno atualizado:\n");
            imprimirAluno(alunos[contador]);
            return;
        }
    }

    printf("Aluno com a matrícula %d não encontrado.\n", matricula);
}


void listarAluno(struct Aluno alunos[], int numAlunos) {
    int matricula;

    printf("Digite a matrícula do aluno:");
    scanf("%d", &matricula);

    for (int contador = 0; contador < numAlunos; contador++) {
        if (alunos[contador].matricula == matricula) {
            printf("Dados do aluno:\n");
            imprimirAluno(alunos[contador]);
            return;
        }
    }

    printf("Aluno com a matrícula %d não encontrado.\n", matricula);
}

void excluirAluno(struct Aluno alunos[], int *numAlunos) {
    int matricula;

    printf("Digite a matrícula do aluno que deseja excluir: ");
    scanf("%d", &matricula);

    for (int contador = 0; contador < *numAlunos; contador++) {
        if (alunos[contador].matricula == matricula) {
            for (int contadorY = contador; contadorY < *numAlunos - 1; contadorY++) {
                alunos[contadorY] = alunos[contadorY + 1];
            }
            (*numAlunos)--;
            printf("Aluno com a matrícula %d excluído com sucesso!\n", matricula);
            return;
        }
    }

    printf("Aluno com a matrícula %d não encontrado.\n", matricula);
}


//DECLARACAO DE OBJETOS
struct inscricaoDisciplina {
    int matricula;
    int codDisciplina;
    int dataInscricao;
    int codigo;
};


struct disciplina {
    int codigo;
};

struct tipoCurso {
    int codigo;
};

//DECLARACAO DE VARIAVEIS GLOBAIS
struct inscricaoDisciplina tabelaInscricao[SIZE]; //ARRAY
struct disciplina tabelaDisciplina[SIZE]; //ARRAY
struct tipoCurso tabelaCurso[SIZE]; //ARRAY

//METODO NEGRITO - Coloca um texto em negrito. Utilize bold(1) para iniciar e bold(0) para finalizar
void bold(int status) {
	static const char *seq[] = {"\x1b[0m", "\x1b[1m"};
	printf("%s", seq[!!status]);
}

//METODO TELA DO MENU SECUNDARIO - Padronizacao de menu. Recebe um CHAR com o nome do menu selecionado
void menuSecundario(char texto[100]){

    int controle;

    controle = strlen(texto); //FUNÇAO QUE CONTA CARACTERE
	printf(" _________________________________________________________________________________________\n");
	printf("|                                                                                         |\n");
	printf("| SISTEMA DE CADASTRO                                                                     |\n");
	printf("|                                                                                         |\n");
	printf("| MENU SELECIONADO:                                                                       |\n");
	printf("|                                                                                         |\n");
	bold(1);
	printf("| ");
	printf("%s",texto);
	for(int i=controle ; i <= 87; i++){
	    printf(" ");
	}
	printf("|\n");
	bold(0);
	printf("|                                                                                         |\n");
	printf("|   1 - INCLUIR                                                                           |\n");
	printf("|   2 - LEITURA                                                                           |\n");
	printf("|   3 - ALTERAR                                                                           |\n");
	printf("|   4 - DELETAR                                                                           |\n");
	printf("|   5 - VOLTAR                                                                        	  |\n");
	printf("|                                                                                         |\n"); 
	printf("| Digite uma das operacoes para prosseguir.                                               |\n");    
	printf("|_________________________________________________________________________________________|\n");
}

//METODO VALIDA MENU - Tem como objetivo receber dois INT re range do menu
int validaMenu(int maior, int menor){
    int menu;
    scanf("%d", &menu);
    while ( (menu > maior) || (menu < menor) ){
		printf("Digite um menu valido.\n");
	    scanf("%d", &menu);	
	}
	return menu;
}

//METODO DECISAO - Tem como objetivo receber um CHAR para imprimir na tela e perguntar ao usuario se ele deseja continuar
int decisao(char texto[200]){

    int decisao;

    printf("%s\n", texto);
    scanf("%d", &decisao);

    while (decisao != 1 && decisao != 2) {
        system("clear");
        printf("Digito invalido, por favor digite (1 - SIM|2 - NÃO): \n"); 
        scanf("%s", &decisao);
    }
    return decisao;
    system("clear");
}

//METODO DE AUTOINCREMENT - RECEBER UM CHAR PARA ESCOLHER EM QUAL TABELA IRAO REALIZAR O AUTOINCREMENT
int autoincrement(char texto[50]){

    int increment;
    increment = 1;
    if(texto == "INSCRICAO DE DISCIPLINA"){
       for(int i = 0; i < SIZE; i ++){
           if( (tabelaInscricao[i].codigo >= increment)){
               increment ++;
           } else{
               break;}
       } 
    }
    if(texto == "TIPO DE CURSO"){
       for(int i = 0; i < SIZE; i ++){
           if( (tabelaCurso[i].codigo >= increment)){
               increment ++;
           } else{
               break;}
       } 
    }
    if(texto == "DISCIPLINA"){
       for(int i = 0; i < SIZE; i ++){
           if( (tabelaDisciplina[i].codigo >= increment)){
               increment ++;
           } else{
               break;}
       } 
    }
    return(increment);
}

//METODO VALIDAÇÃO CADASTRO MATRICULA - Metodo tem como objetivo garantir que não existe duplicidade na matricula



//METODO INCLUIR INSCRICAO DE DISCIPLINA - Metodo utilizado para incluir uma nova INSCRICAO DE DISCIPLINA
void cadastroInscricao(){

    for(int i = autoincrement("INSCRICAO DE DISCIPLINA") - 1; i < SIZE; i ++){

	    system("clear");

	    printf("Digite a MATRICULA do aluno: \n");
		scanf("%d", &tabelaInscricao[i].matricula);

		printf("Digite o CODIGO DA DISCIPLINA do CURSO: \n");
		scanf("%d", &tabelaInscricao[i].codDisciplina);

		printf("Digite a DATA DE INSCRICAO (DDMMAAAA): \n\n");
		scanf("%d", &tabelaInscricao[i].dataInscricao);

		tabelaInscricao[i].codigo = autoincrement("INSCRICAO DE DISCIPLINA");
		system("clear");

		//CONTINUAR
		if (decisao("Deseja continuar incluindo matricula?\n\n1 - SIM\n2 - NÃO\n") == 2) {
			break;
			system("clear");
		}
	}
}

//METODO IMPRIMIR INSCRICAO DISCIPLINA - Metodo utilizado para imprimir todas as INSCRICOES DE DISCIPLINAS feitas
void imprimirInscricao(){
    //char decisao[1];
    for(int i = 0; i < SIZE; i++) {
        if (tabelaInscricao[i].codigo != 0) {
            printf("Codigo: %d", tabelaInscricao[i].codigo);
            printf("\nMatricula: %d", tabelaInscricao[i].matricula);
            printf("\nCod. Disciplina: %d", tabelaInscricao[i].codDisciplina);
            printf("\nData de inscricao: %d\n\n", tabelaInscricao[i].dataInscricao);
        } 
    }
}

//METODO DELETAR INSCRICAO DE DISCIPLINA - Metodo utilizado para deletar registro de INSCRICAO DE DISCIPLINA
void deletarInscricao(){

    int delete;
    printf("Digite o Codigo de inscricao de disciplina que voce deseja deletar: \n");
    scanf("%d", &delete);

    system("clear");
	printf("Codigo: %d", tabelaInscricao[delete-1].codigo);
    printf("\nMatricula: %d", tabelaInscricao[delete-1].matricula);
    printf("\nCod. Disciplina: %d", tabelaInscricao[delete-1].codDisciplina);
    printf("\nData de inscricao: %d\n\n", tabelaInscricao[delete-1].dataInscricao);

    //CONTINUAR
    if (decisao("Voce tem certeza que deseja excluir o registro:\n\n1 - SIM\n2 - NÃO\n") == 1) {
        tabelaInscricao[delete-1].codigo = NULL;
        tabelaInscricao[delete-1].matricula = NULL;
        tabelaInscricao[delete-1].codDisciplina = NULL;
        tabelaInscricao[delete-1].dataInscricao = NULL;
	}
}

//METODO ALTERAR INSCRICAO DE DISCIPLINA - Metodo utilizado para alterar registro de INSCRICAO DE DISCIPLINA
void alterarInscricao(){

    int alt;
    printf("Digite o Codigo de inscricao de disciplina que voce deseja deletar: \n");
    scanf("%d", &alt);

    system("clear");
	printf("Codigo: %d", tabelaInscricao[alt-1].codigo);
    printf("\nMatricula: %d", tabelaInscricao[alt-1].matricula);
    printf("\nCod. Disciplina: %d", tabelaInscricao[alt-1].codDisciplina);
    printf("\nData de inscricao: %d\n\n", tabelaInscricao[alt-1].dataInscricao);

    //CONTINUAR
    if (decisao("Voce tem certeza que deseja alterar o registro:\n\n1 - SIM\n2 - NÃO\n") == 1) {
        system("clear");
		printf("Digite o NOVO CODIGO DA DISCIPLINA do CURSO: \n");
		scanf("%d", &tabelaInscricao[alt-1].codDisciplina);
		printf("Digite a NOVA DATA DE INSCRICAO (DDMMAAAA): \n");
		scanf("%d", &tabelaInscricao[alt-1].dataInscricao);
	}
}

//PROGRAMA PRINCIPAL
int main() {

    system("clear");
    struct Aluno alunos[MAX_ALUNOS];
    int numAlunos = 0;
    int menu;

    do {
        printf(" _________________________________________________________________________________________\n");
        printf("|                                                                                         |\n");
        printf("| SISTEMA DE CADASTRO                                                                     |\n");
        printf("|                                                                                         |\n");
        printf("| MENU:                                                                                   |\n");
        printf("|                                                                                         |\n");
        printf("| 1 - CADASTRO ALUNO                                                                      |\n"); 
        printf("| 2 - CADASTRO TIPO DE CURSO                                                              |\n");
        printf("| 3 - CADASTRO DISCIPLINA                                                                 |\n");
        printf("| 4 - INSCRICAO DE DISCIPLINA                                                             |\n");
        printf("| 0 - SAIR                                                                                |\n");
        printf("|                                                                                         |\n");    
        printf("| Digite uma das opcao para prosseguir.                                                   |\n");    
        printf("|_________________________________________________________________________________________|\n");

        menu = validaMenu(4, 0);

        switch(menu) {
	            case 1:
	                while (1) {
	                    system("clear");
	                    menuSecundario("CADASTRO DE ALUNO");
	
	                    int menu = validaMenu(5, 1);
	
	                    if (menu == 1) {
	                        system("clear");
	                        printf("Cadastro de Aluno\n");
	                        cadastrarAluno(alunos, &numAlunos);
	                    } else if (menu == 2) {
	                        system("clear");
	                        printf("Listagem de Aluno\n");
	                        listarAluno(alunos, numAlunos);
	                    } else if (menu == 3) {
	                        system("clear");
	                        printf("Atualizacao de Aluno\n");
	                        atualizarAluno(alunos, numAlunos);
	                    } else if (menu == 4) {
	                        system("clear");
	                        printf("Exclusao de Aluno\n");
	                        excluirAluno(alunos, &numAlunos);
	                    } else if (menu == 5) {
	                        // Voltar ao menu principal
	                        break;
	                    }
		                system("clear");
		            }
		                break;
	
			case 2:

				system("clear");
				menuSecundario("CADASTRO DE CURSO");
				menu = validaMenu(5,1);

				//ESCREVA O SEU MENU AQUI
				
				system("clear");
				break;

			case 3:

				system("clear");
				menuSecundario("CADASTRO DE DISCIPLINA");
				menu = validaMenu(5,1);

				//ESCREVA O SEU MENU AQUI

				system("clear");
				break;

			case 4:

				do{
					system("clear");
				    menuSecundario("INSCRICAO DE DISCIPLINA");
					menu = validaMenu(5,1);

					if(menu == 1){
						system("clear");
						cadastroInscricao();

						//CONTINUAR
						if (decisao("Deseja retornar ao menu principal?\n\n1 - SIM\n2 - NÃO\n") == 1) {
							menu = 5;
						} else{ menu = 6; }
						system("clear");
					}

					if(menu == 2){
						system("clear");
						imprimirInscricao();

						//CONTINUAR
						if (decisao("Deseja retornar ao menu principal?\n\n1 - SIM\n2 - NÃO\n") == 1) {
							menu = 5;
						} else{ menu = 6; }
						system("clear");
					}

					if(menu == 3){
					    system("clear");
					    alterarInscricao();
					    system("clear");

					    //CONTINUAR
						if (decisao("Deseja retornar ao menu principal?\n\n1 - SIM\n2 - NÃO\n") == 1) {
							menu = 5;
						} else{ menu = 6; }
						system("clear");
					}

					if(menu == 4){
					    system("clear");
					    deletarInscricao();
					    system("clear");

					    //CONTINUAR
						if (decisao("Deseja retornar ao menu principal?\n\n1 - SIM\n2 - NÃO\n") == 1) {
							menu = 5;
						} else{ menu = 6; }
						system("clear");
					}

					system("clear");

				}while(menu == 6); //MENU IGUAL A 6 VOLTA PARA O MESMO MENU, POREM IGUAL 5 RETORNA PARA O PRINCIPAL
				break;

			case 0: 

				system("clear");
				menu = 0;
				break;

		}    
    } while(menu != 0);  // Continua enquanto o usuario nÃ£o escolher sair

    return 0;
}
	//SAIR DO PROGRAMA
	//system("clear");
	//decisao("ALERTA! Voce irÃ¡ sair do programa, deseja realmente sair?");
