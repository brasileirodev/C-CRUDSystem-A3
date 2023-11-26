//@H�CTOR VALENTE (22/11/2023) - Menu e implementação da usabilidade inscrição de disciplina.
//@LUCAS (23/11/2023) - Menu e implementação da usabilidade cadastro de aluno.
//@H�CTOR VALENTE (23/11/2023) - Correção caracter especial + função inclusão em método.
//@H�CTOR VALENTE (25/11/2023) - Fun��o validar matricula + nova fun��o alterar/deletar.
//Pedro Soares (26/11/2023) - Correção de caracter especial.

#include <stdio.h/>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000


#define MAX_ALUNOS 100
#define MAX_MATRICULA 20
#define MAX_CPF 11 
#define MAX_NOME 30
#define MAX_EMAIL 50
#define MAX_TIPO_CURSOS 100

//DECLARACAO DE OBJETOS
struct inscricaoDisciplina {
    int matricula;
    int codDisciplina;
    int dataInscricao;
    int codigo;
};

struct disciplina {
    int codigo;
    char nome[SIZE];
    char nomeProfessor [SIZE];
    int codigoTipoCurso;
};

struct tipoCurso {
    int codigo;
};

struct Aluno {
    int matricula;
    char cpf[MAX_CPF];
    char nome[MAX_NOME];
    char sexo;
    char email[MAX_EMAIL];
    int codigoTipoCurso;
};

//DECLARACAO DE VARIAVEIS GLOBAIS
struct inscricaoDisciplina tabelaInscricao[SIZE]; //ARRAY
struct disciplina tabelaDisciplina[SIZE]; //ARRAY
struct tipoCurso tabelaCurso[SIZE]; //ARRAY
//struct alunos tabelaAluno[SIZE]; Lucas o seu ARRAY GLOBAL AQUI

//------------------------------------------------------------FUNCOES ALUNO (LUCAS)------------------------------------------------------------
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


//----------------------------------------------------FUNCOES INSCRICOES & MENU (HECTOR)-----------------------------------------------------
//FUNCAO NEGRITO - Coloca um texto em negrito. Utilize bold(1) para iniciar e bold(0) para finalizar
void bold(int status) {
	static const char *seq[] = {"\x1b[0m", "\x1b[1m"};
	printf("%s", seq[!!status]);
}

//FUNCAO TELA DO MENU SECUNDARIO - Padronizacao de menu. Recebe um CHAR com o nome do menu selecionado
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

//FUNCAO VALIDA MENU - Tem como objetivo receber dois INT re range do menu
int validaMenu(int maior, int menor){
    int menu;
    scanf("%d", &menu);
    while ( (menu > maior) || (menu < menor) ){
		printf("Digite um menu valido.\n");
	    scanf("%d", &menu);	
	}
	return menu;
}

//FUNCAO DECISAO - Tem como objetivo receber um CHAR para imprimir na tela e perguntar ao usuario se ele deseja continuar
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

//FUNCAO DE AUTOINCREMENT - RECEBER UM CHAR PARA ESCOLHER EM QUAL TABELA IRAO REALIZAR O AUTOINCREMENT
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

//FUNCAO VALIDACAO CADASTRO MATRICULA - Metodo tem como objetivo garantir o usuario escolheu uma matricula j� existente
/*int validaMatricula(int matricula){
    for(int i = 0; i < SIZE; i++){
        if(alunos[i].matricula == matricula){
            matricula = NULL;
            break;
        }
    }
    return(matricula);
}*/

//FUNCAO INCLUIR INSCRICAO DE DISCIPLINA - Metodo utilizado para incluir uma nova INSCRICAO DE DISCIPLINA
void cadastroInscricao(){

    int vMatricula; //VARIAVEL DE MEMORIA LOCAL
    int vCodDisciplina; //VARIAVEL DE MEMORIA LOCAL

    for(int i = autoincrement("INSCRICAO DE DISCIPLINA") - 1; i < SIZE; i ++){

        //ERRO_MAT_S:
	    system("clear");

	    printf("Digite a MATRICULA do aluno: \n");
	    /*scanf("%d", &vMatricula);
        if(validaMatricula(vMatricula) == NULL){
            system("clear");
            if(decisao("MATRICULA j� existente, deseja digitar outra MATRICULA?\n\n1 - SIM\n2 - N�O\n") == 1){
                goto ERRO_MAT_S;
            } else{ 
                goto ERRO_MAT_N;
            }
        }else{
            tabelaInscricao[i].matricula = vMatricula;
        }*/
		scanf("%d", &tabelaInscricao[i].matricula);

		printf("Digite o CODIGO DA DISCIPLINA do CURSO: \n");
		scanf("%d", &tabelaInscricao[i].codDisciplina);

		printf("Digite a DATA DE INSCRICAO (DDMMAAAA): \n");
		scanf("%d", &tabelaInscricao[i].dataInscricao);

		//tabelaInscricao[i].codigo = autoincrement("INSCRICAO DE DISCIPLINA");
		system("clear");

        //ERRO_MAT_N:
		//CONTINUAR
		if (decisao("Deseja incluir outra inscricao?\n\n1 - SIM\n2 - N�O\n") == 2) {
			system("clear");
			break;
		}
	}
}

//FUNCAO IMPRIMIR INSCRICAO DISCIPLINA - Metodo utilizado para imprimir todas as INSCRICOES DE DISCIPLINAS feitas
void imprimirInscricao(){

    for(int i = 0; i < SIZE; i++) {
        if (tabelaInscricao[i].matricula != 0) {
            //printf("Codigo: %d", tabelaInscricao[i].codigo);
            printf("Matricula: %d", tabelaInscricao[i].matricula);
            printf("\nCod. Disciplina: %d", tabelaInscricao[i].codDisciplina);
            printf("\nData de inscricao: %d\n\n", tabelaInscricao[i].dataInscricao);
        } 
    }
}

//FUNCAO ALTERAR INSCRICAO DE DISCIPLINA - Funcao utilizada para alterar registro de INSCRICAO DE DISCIPLINA
void altInscricao(){
    
    int vMatricula, vCodigo, cont = 1;// VARIAVEL LOCAL
    
    printf("Digite a matricula que voc� deseja alterar uma inscricao: \n");
    scanf("%d", &vMatricula);
    
    inicio_loop:
    system("clear");
    for (int i = 0; i < SIZE ; i ++){ //FOR PARA LISTAR TODAS AS INCRICOES DE UMA MATRICULA SELECIONADA
        tabelaInscricao[i].codigo = 0;
        if(tabelaInscricao[i].matricula == vMatricula){
                tabelaInscricao[i].codigo = cont;
                cont ++;
                printf("Codigo: %d", tabelaInscricao[i].codigo);
                printf("\nMatricula: %d", tabelaInscricao[i].matricula);
                printf("\nCod. Disciplina: %d", tabelaInscricao[i].codDisciplina);
                printf("\nData de inscricao: %d\n\n", tabelaInscricao[i].dataInscricao);
        }
    }
    printf("Digite o codigo de inscricao que voc� deseja alterar: \n");
    scanf("%d", &vCodigo);
    system("clear");
    for (int i = 0; i < SIZE ; i ++){ //FOR PARA MOSTRAR A INSCRICAO SELECIONADA
        if(tabelaInscricao[i].codigo == vCodigo){
            printf("Matricula: %d", tabelaInscricao[i].matricula);
            printf("\nCod. Disciplina: %d", tabelaInscricao[i].codDisciplina);
            printf("\nData de inscricao: %d\n\n", tabelaInscricao[i].dataInscricao);
            
            if (decisao("Voce tem certeza que deseja alterar o registro:\n\n1 - SIM\n2 - N�O\n") == 1){ //CERTEZA QUE DESEJA EXCLUIR?
                system("clear");
	         printf("Digite um o NOVO CODIGO DA DISCIPLINA do CURSO: \n"); //NOVOS DADOS
	         scanf("%d", &tabelaInscricao[i].codDisciplina);
	         printf("Digite uma NOVA DATA DE INSCRICAO (DDMMAAAA): \n"); //NOVOS DADOS
	         scanf("%d", &tabelaInscricao[i].dataInscricao);
	         break;
            }
        }else{
            if(i == 999){ //ELSE PARA INFORMAR QUE O CODIGO N�O FOI LOCALIZADO
                system("clear");
                printf("ALERTA: CODIGO NAO LOCALIZADO.\n\n");
                if (decisao("Deseja tentar alterar novamente:\n\n1 - SIM\n2 - N�O\n") == 1){//DESEJA TENTAR NOVAMENTE?
                    goto inicio_loop;
                }else{
                    goto fim_loop;
                }
            }
        }
    }
    fim_loop:
}

//FUNCAO DELETAR INSCRICAO DE DISCIPLINA - Funcao utilizada para deletar registro de INSCRICAO DE DISCIPLINA
void delInscricao(){

    int vMatricula, vCodigo, cont = 1;// VARIAVEL LOCAL
    
    printf("Digite a matricula que voc� deseja deletar uma inscricao: \n");
    scanf("%d", &vMatricula);
    
    inicio_loop:
    system("clear");
    for (int i = 0; i < SIZE ; i ++){ //FOR PARA LISTAR TODAS AS INCRICOES DE UMA MATRICULA SELECIONADA
        tabelaInscricao[i].codigo = 0;
        if(tabelaInscricao[i].matricula == vMatricula){
                tabelaInscricao[i].codigo = cont;
                cont ++;
                printf("Codigo: %d", tabelaInscricao[i].codigo);
                printf("\nMatricula: %d", tabelaInscricao[i].matricula);
                printf("\nCod. Disciplina: %d", tabelaInscricao[i].codDisciplina);
                printf("\nData de inscricao: %d\n\n", tabelaInscricao[i].dataInscricao);
        }
    }
    printf("Digite o codigo de inscricao que voc� deseja deletar: \n");
    scanf("%d", &vCodigo);
    system("clear");
    for (int i = 0; i < SIZE ; i ++){ //FOR PARA MOSTRAR A INSCRICAO SELECIONADA
        if(tabelaInscricao[i].codigo == vCodigo){
            printf("Matricula: %d", tabelaInscricao[i].matricula);
            printf("\nCod. Disciplina: %d", tabelaInscricao[i].codDisciplina);
            printf("\nData de inscricao: %d\n\n", tabelaInscricao[i].dataInscricao);
            
            if (decisao("Voce tem certeza que deseja deletar o registro:\n\n1 - SIM\n2 - N�O\n") == 1){ //CERTEZA QUE DESEJA EXCLUIR?
                system("clear");
                tabelaInscricao[i].codigo = NULL;
                tabelaInscricao[i].matricula = NULL;
                tabelaInscricao[i].codDisciplina = NULL;
                tabelaInscricao[i].dataInscricao = NULL;
	            break;
            }
        }else{
            if(i == 999){ //ELSE PARA INFORMAR QUE O CODIGO N�O FOI LOCALIZADO
                system("clear");
                printf("ALERTA: CODIGO NAO LOCALIZADO.\n\n");
                if (decisao("Deseja tentar deletar novamente:\n\n1 - SIM\n2 - N�O\n") == 1){//DESEJA TENTAR NOVAMENTE?
                    goto inicio_loop;
                }else{
                    goto fim_loop;
                }
            }
        }
    }
    fim_loop:
}

//--------------------------------------------------FUNCOES DISCIPLINA (PEDRO)-------------------------------------------------------------

// FUNCAO DE PRINT;
void imprimirDisciplinas(struct disciplina disciplinas[], int quantidadeDisciplinas) {
    
    printf("Disciplinas Cadastradas: \n");
        
    //LOOP UTILIZADO PARA FAZER O PRINT DE TODAS AS DISCIPLINAS CADASTRADAS;
    for (int cont = 0; cont < quantidadeDisciplinas; cont++) {    
        
        printf("\nCodigo da Disciplina: %03d", disciplinas[cont].codigo);
        printf("\nNome da Disciplina: %s", disciplinas[cont].nome);
        printf("\nNome do Professor: %s", disciplinas[cont].nomeProfessor);
        printf("\nCodigo Tipo Curso: %d", disciplinas[cont].codigoTipoCurso);
        printf("\n");
    }
}   
    

// FUNCAO NOME DISCIPLINA;
    
void scanNomeDisciplina(char nome[]) {
    printf("Informe o nome da disciplina:\n");
    fgets(nome, SIZE, stdin);
    nome[strcspn(nome, "\n")] = 0;
}

// FUNCAO NOME PROFESSOR;

void scanNomeProfessor(char nomeProfessor[]) {
    printf("Informe o nome do Professor:\n");
    fgets(nomeProfessor, SIZE, stdin);
    nomeProfessor[strcspn(nomeProfessor, "\n")] = 0;
    
}

// FUNCAO ALTERAR DISCIPLINAS;
void alterarDisciplina(struct disciplina disciplinas[], int quantidadeDisciplinas) {
    // SOLICITANDO CODIGO A SER ALTERADO
    int altDisciplina = 0;
    system("clear");
    printf("Digite o codigo da disciplina que você deseja alterar: \n");
    scanf("%d", &altDisciplina);

    // PRINT DAS INFORMAÇÕES DA DISCIPLINA DE CODIGO ESCOLHIDO
    system("clear");
    printf("Codigo: %03d", disciplinas[altDisciplina - 1].codigo);
    printf("\nNome da Disciplina: %s", disciplinas[altDisciplina - 1].nome);
    printf("\nNome do Professor: %s", disciplinas[altDisciplina - 1].nomeProfessor);
    printf("\nCodigo tipo curso: %d", disciplinas[altDisciplina - 1].codigoTipoCurso);

    //VERIFICADOR DE CODIGO
    if (altDisciplina > 0 && altDisciplina <= quantidadeDisciplinas) {
       
        // VERIFICADOR
        int codVerificador = 1;
        printf("\n\nVoce realmente deseja fazer a alteracao \n\n1 - SIM\n2 - NAO\n");
        scanf("%d", &codVerificador);
        getchar();
        // ALTERANDO OS VALORES DAS DISCIPLINAS(SEM ALTERAR O CODIGO)
        if (codVerificador == 1) {
            
            system("clear");
            printf("Digite o novo nome da disciplina: \n");
            fgets(disciplinas[altDisciplina - 1].nome, sizeof(disciplinas[altDisciplina - 1].nome), stdin);
            disciplinas[altDisciplina - 1].nome[strcspn(disciplinas[altDisciplina - 1].nome, "\n")] = 0;
    
            system("clear");
            printf("Digite o novo nome do professor: \n");
            fgets(disciplinas[altDisciplina - 1].nomeProfessor, sizeof(disciplinas[altDisciplina - 1].nomeProfessor), stdin);
            disciplinas[altDisciplina - 1].nomeProfessor[strcspn(disciplinas[altDisciplina - 1].nomeProfessor, "\n")] = 0;
            
            system("clear");
            printf("Disciplina alterada\n");
            
        } else {
            system("clear");
            printf("\nOperacao Cancelada\n");
        }
            
    }else {
    system("clear");
    printf("\nCodigo de disciplina nao existente\n");
    }
}

// FUNÇÃO DELETAR DISCIPLINAS
int deletarDisciplina(struct disciplina disciplinas[], int quantidadeDisciplinas) {
   
   
    // SOLICITANDO CÓDIGO A SER EXCLUIDO
    int delDisciplina = 0;
    system("clear");
    printf("Digite o codigo da disciplina que voce deseja excluir:\n");
    scanf("%d", &delDisciplina);
    
    
     // PRINT DAS INFORMAÇÕES DA DISCIPLINA DE CÓDIGO ESCOLHIDO
    system("clear");
    printf("Codigo: %03d", disciplinas[delDisciplina - 1].codigo);
    printf("\nNome da Disciplina: %s", disciplinas[delDisciplina - 1].nome);
    printf("\nNome do Professor: %s", disciplinas[delDisciplina - 1].nomeProfessor);
    printf("\nCodigo tipo curso: %d", disciplinas[delDisciplina - 1].codigoTipoCurso);

    // VERIFICADOR DE CODIGO (EM TESTE)
    if (delDisciplina > 0 && delDisciplina <= quantidadeDisciplinas) {
        
        // VERIFICADOR
        int codVerificador = 0;
        printf("\n\nVoce realmente deseja excluir?\n1 - SIM\n2 - NAO\n");
        scanf("%d", &codVerificador);
        getchar();
            
        //EXCLUINDO 
        if (codVerificador == 1) {
            
            disciplinas[delDisciplina - 1].codigo = NULL;
            disciplinas[delDisciplina - 1].nome[0] = '\0';
            disciplinas[delDisciplina - 1].nomeProfessor[0] = '\0';
            disciplinas[delDisciplina - 1].codigoTipoCurso = NULL;
            system("clear");
            printf("Disciplina excluida\n");
            return quantidadeDisciplinas; // Retorna a nova quantidade de disciplinas
        } else {
            
            system("clear");
            printf("\nOperacao Cancelada\n");
        }
    } else {
        system("clear");
        printf("\nCodigo de disciplina nao existente\n");
    }
    return quantidadeDisciplinas; // Retorna a quantidade original de disciplinas
}

//DECLARAÇÃO DE VARIÁVEIS DO TIPO CURSO
typedef struct {
    int codigoTipoCurso ;
    char nome[50];  
    char turno[50]; 
}TipoCurso;

TipoCurso tiposCursos[MAX_TIPO_CURSOS];
int numTiposCursos = 0;


//FUNÇÕES DO TIPOCURSO
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void createTipoCurso() {
    if (numTiposCursos < MAX_TIPO_CURSOS) {
        TipoCurso novoTipoCurso;

        printf("\nDigite o nome do curso a ser adicionado: ");
        fgets(novoTipoCurso.nome, sizeof(novoTipoCurso.nome), stdin);
        novoTipoCurso.nome[strcspn(novoTipoCurso.nome, "\n")] = '\0'; 

        printf("\nDigite o turno do curso a ser adicionado (manha/noite): ");
        fgets(novoTipoCurso.turno, sizeof(novoTipoCurso.turno), stdin);
        novoTipoCurso.turno[strcspn(novoTipoCurso.turno, "\n")] = '\0'; 

        novoTipoCurso.codigoTipoCurso = numTiposCursos + 1;
        tiposCursos[numTiposCursos] = novoTipoCurso;
        numTiposCursos++;

        printf("\nCurso criado com sucesso! Retornando ao menu.\n");
    } else {
        printf("\nErro: Limite máximo de cursos atingido.\n");
    }
}

void readTipoCurso(int codigoTipoCurso) {
    int encontrado = 0;
    for (int i = 0; i < numTiposCursos; i++) {
        if (tiposCursos[i].codigoTipoCurso == codigoTipoCurso) {
            printf("\nCodigo: %d\n", tiposCursos[i].codigoTipoCurso);
            printf("Curso: %s\n", tiposCursos[i].nome);
            printf("Turno: %s\n", tiposCursos[i].turno);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nErro: Curso nao encontrado.\n");
    }
}


void updateTipoCurso(int codigoTipoCurso) {
    int encontrado = 0;
    for (int i = 0; i < numTiposCursos; i++) {
        if (tiposCursos[i].codigoTipoCurso == codigoTipoCurso) {
            printf("\nDigite o novo nome do curso: ");
            fgets(tiposCursos[i].nome, sizeof(tiposCursos[i].nome), stdin);
            tiposCursos[i].nome[strcspn(tiposCursos[i].nome, "\n")] = '\0';

            printf("\nDigite o novo turno do curso (manha/noite): ");
            fgets(tiposCursos[i].turno, sizeof(tiposCursos[i].turno), stdin);
            tiposCursos[i].turno[strcspn(tiposCursos[i].turno, "\n")] = '\0';

            encontrado = 1;
            printf("\nCurso atualizado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\nErro: Curso nao encontrado.\n");
    }
}


void deleteTipoCurso(int codigoTipoCurso) {
    int encontrado = 0;
    for (int i = 0; i < numTiposCursos; i++) {
        if (tiposCursos[i].codigoTipoCurso == codigoTipoCurso) {
            for (int j = i; j < numTiposCursos - 1; j++) {
                tiposCursos[j] = tiposCursos[j + 1];
            }
            numTiposCursos--;
            encontrado = 1;
            printf("\nCurso removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\nErro: Curso nao encontrado.\n");
    }
}//FIM DAS FUNÇÕES DO TIPOCURSO



//PROGRAMA PRINCIPAL
//-----------------------------------------------------------INICIO MAIN--------------------------------------------------------------------
int main() {

    system("clear");
    struct Aluno alunos[MAX_ALUNOS];
    int numAlunos = 0;
    int menu;

    // ---------------VARIÝVEIS DICIPLINA(PEDRO)----------------------
    // DEFININDO ARRAY DISCIPLINAS UTILIZANDO O "SIZE" PARA DEFINIR UM MÝXIMO DE DISCIPLINAS;
    struct disciplina disciplinas[SIZE];
    // VARIÝVEL PARA CONTABILIZAR QUANTIDADE DE DISCIPLINAS;
    int quantidadeDisciplinas = 0;
    // DEFINIR VARIAVEL "STRUCT" PARA NOVA DISCIPLINA;
    struct disciplina novaDisciplina;
    // variavel do alt
    int altDisc = 0;
    int codver = 1;
    //---------------------------------------------------------------


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
                            system("clear");
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
            do{
				system("clear");
				menuSecundario("CADASTRO DE DISCIPLINA");
				menu = validaMenu(5,1);

				if(menu == 1){
							system("clear");
						
                             
                                //---------------------------- LOOP PARA SOLICITAÇÃO DE INCLUSÕES --------------------------
                                
                                // VARIAVEL PARA CONTROLAR LOOP WHILE;
                                
                                int loop = 1;
                               
                                while  (loop == 1) {
                                
                                
                                    //---------------- VERIFICADOR DE SIZE (QUANTIDADE MAXIMA DE DISCIPLINAS) ---------------
                                   
                                    if (quantidadeDisciplinas < SIZE){
                                        
                                    
                                    // CONTADOR DE CÓDIGO DE DISCIPLINA (AUTO INCREMENT);
                                        novaDisciplina.codigo = quantidadeDisciplinas + 1;
                                    
                                    // VALOR ESTRANGEIRO, CÓDIGO TIPO CURSO MARTELADO;
                                        novaDisciplina.codigoTipoCurso = 1;
                            
                                   
                                    //------------------------ SOLICITAÇÕES DAS DISCIPLINAS------------------------------- 
                                        getchar();
                                        system("clear");
                                        scanNomeDisciplina(novaDisciplina.nome);
                            
                                        system("clear");
                                        scanNomeProfessor(novaDisciplina.nomeProfessor);
                            
                                    //------------------------------------------------------------------------------------
                                        
                                        
                                        // INCLUSOR DE DISCIPLINAS NO ARRAY;
                                       
                                        disciplinas[quantidadeDisciplinas] = novaDisciplina;
                                        quantidadeDisciplinas++;
			
			                system("clear");
								//CONTINUAR
								if (decisao("Deseja incluir outra disciplinas?\n\n1 - SIM\n2 - NAO\n") == 2) {
									break;
								}
								system("clear");
                                    } else {
                                    system("clear"); 
                                    printf ("Nao e possivel adicionar mais disciplinas");
                                    
                                     break;
                                     }
								
							}
							menu = 6;
						}
						//PRINT DOS REGISTROS
						if(menu == 2){
							system("clear");
							imprimirDisciplinas(disciplinas, quantidadeDisciplinas);
							
							//CONTINUAR
							if (decisao("\nDeseja retornar ao menu principal?\n\n1 - SIM\n2 - NAO\n") == 1) {
								menu = 5;
							} else{ menu = 6; }
							system("clear");
						}
						// ALTERAR REGISTROS	
						if(menu == 3){
						    system("clear");
						    alterarDisciplina(disciplinas, quantidadeDisciplinas);
						    
						    //CONTINUAR
							if (decisao("\nDeseja retornar ao menu principal?\n\n1 - SIM\n2 - NAO\n") == 1) {
								menu = 5;
							} else{ menu = 6; }
							system("clear");
						}
						// DELETAR REGISTROS	
						if(menu == 4){
						    
						    system("clear");
						    deletarDisciplina(disciplinas, quantidadeDisciplinas);
						    
						    //CONTINUAR
							if (decisao("\nDeseja retornar ao menu principal?\n\n1 - SIM\n2 - NAO\n") == 1) {
								menu = 5;
							} else{ menu = 6; }
							system("clear");
						    
						}
						
                        system("clear");
						
					}while(menu == 6); //MENU IGUAL A 6 VOLTA PARA O MESMO MENU, PORÉM IGUAL 5 RETORNA PARA O PRINCIPAL
					break;
					
					system("clear");
					break;

				system("clear");
				break;

			case 4:

				do{
					system("clear");
				    menuSecundario("INSCRICAO DE DISCIPLINA");
					menu = validaMenu(5,1);

					if(menu == 1){ //INCLUIR------------------------
						system("clear");
						cadastroInscricao();

						//CONTINUAR
						if (decisao("Deseja retornar ao menu principal?\n\n1 - SIM\n2 - NAO\n") == 1) {
							menu = 5;
						} else{ menu = 6; }
						system("clear");
					}

					if(menu == 2){//IMPRIMIR-----------------------
						system("clear");
						imprimirInscricao();

						//CONTINUAR
						if (decisao("Deseja retornar ao menu principal?\n\n1 - SIM\n2 - NAO\n") == 1) {
							menu = 5;
						} else{ menu = 6; }
						system("clear");
					}

					if(menu == 3){//ALTERAR------------------------
					    system("clear");
					    altInscricao();
					    //alterarInscricao();
					    system("clear");

					    //CONTINUAR
						if (decisao("Deseja retornar ao menu principal?\n\n1 - SIM\n2 - NAO\n") == 1) {
							menu = 5;
						} else{ menu = 6; }
						system("clear");

					}

					if(menu == 4){//EXCLUIR------------------------
					    system("clear");
					    delInscricao();
                        //deletarInscricao();
					    system("clear");

					    //CONTINUAR
						if (decisao("Deseja retornar ao menu principal?\n\n1 - SIM\n2 - NAO\n") == 1) {
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