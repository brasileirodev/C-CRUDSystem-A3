//@HECTOR VALENTE (22/11/2023) - Menu e implementação da usabilidade inscrição de disciplina.
//@LUCAS (23/11/2023) - Menu e implementação da usabilidade cadastro de aluno.
//@HECTOR VALENTE (23/11/2023) - Correção caracter especial + função inclusão em método.
//@HECTOR VALENTE (25/11/2023) - Funo validar matricula + nova funo alterar/deletar.
//Pedro Soares (26/11/2023) - Correção de caracter especial.
//Nathan Muñoz (26/11/23) - Implementação dos métodos TipoCurso
//Pedro Soares (27/11/2023) - Revisão e melhoria de funções
//HECTOR VAENTE (27/11/2023) - IMPLEMENTACAO VALIDACAO DE CADASTROS EXISTENTES TABELA INSCRICAO DE DISCIPLINA
//Pedro Soares (27/11/2023) - Revisão e melhoria de funções + aula
//Lucas (28/11/2023) - matricula automatica e imprimir todas as matriculas
//Pedro (28/11/2023) - Finalização da Disciplina com a variavel codigoTipoCurso, melhoria do delete, melhoria do incluirTipoCurso(), revisão dos códigos.
//HECTOR (28/11/2023) - IMPLEMENTACAO DA VALIDACAO MATRICULA, DISCIPLINA E AMARRACAO TIPOCURSO E DISCIPLINA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000

//DECLARACAO DE OBJETOS
struct Aluno {
    int matricula;
    int cpf;
    char nome[SIZE];
    char sexo[SIZE];
    char email[SIZE];
    int codigotipoCurso;
};

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
    int codigoTipoCurso;
    char nome[SIZE];  
    char turno[SIZE]; 
}tipoCurso;


//DECLARACAO DE VARIAVEIS GLOBAIS

int numTabelaTipoCurso = 0;
struct tipoCurso tabelaTipoCurso[SIZE];
struct inscricaoDisciplina tabelaInscricao[SIZE]; //ARRAY

//----------------------VARIAVEIS GLOBAIS DISCIPLINA (PEDRO)---------------------------------------------------------------------------                                 
struct disciplina tabelaDisciplina[SIZE]; // DEFININDO ARRAY DISCIPLINAS UTILIZANDO O "SIZE" PARA DEFINIR UM MAXIMO DE DISCIPLINAS;
int totalDisciplinas = 0; // VARIAVEL PARA CONTABILIZAR QUANTIDADE DE DISCIPLINA
//-------------------------------------------------------------------------------------------------------------------------------------------
struct Aluno tabelaAluno[SIZE];
//------------------------------------------------------------FUNCOES ALUNO (LUCAS)------------------------------------------------------------

int ultimaMatricula() {
    int controlematricula = -1;
    for (int i = 0; i < SIZE; i++) {
        if (tabelaAluno[i].matricula != 0) {
            controlematricula = i;
        }
    }
    return (controlematricula + 1);
}

void cadastroAluno() {
    int i = ultimaMatricula();
    tabelaAluno[i].matricula = ultimaMatricula() + 1;

    system("clear");
    printf("Digite o CPF:\n");
    scanf("%d", &tabelaAluno[i].cpf);
    while (getchar() != '\n');  // Limpa o buffer

    system("clear");
    printf("Digite o nome do aluno: \n");
    fgets(tabelaAluno[i].nome, SIZE, stdin);
    tabelaAluno[i].nome[strcspn(tabelaAluno[i].nome, "\n")] = '\0';  // Remove o \n

    system("clear");
    printf("Digite o sexo do aluno: \n");
    fgets(tabelaAluno[i].sexo, SIZE, stdin);
    tabelaAluno[i].sexo[strcspn(tabelaAluno[i].sexo, "\n")] = '\0';  // Remove o \n

    system("clear");
    printf("Digite o e-mail do aluno: \n");
    fgets(tabelaAluno[i].email, SIZE, stdin);
    tabelaAluno[i].email[strcspn(tabelaAluno[i].email, "\n")] = '\0';  // Remove o \n

    system("clear");
    printf("Digite o codigo do tipo de curso: \n");
    scanf("%d", &tabelaAluno[i].codigotipoCurso);
    while (getchar() != '\n');  // Limpa o buffer

    if (decisao("Deseja incluir outra inscricao?\n\n1 - SIM\n2 - NAO\n") == 2) {
        system("clear");
    }
}

void imprimirAluno() {
    
    system("clear");
    for (int i = 0; i < SIZE; i++) {
        if (tabelaAluno[i].matricula != 0) {
            printf("\nMatricula: %d", tabelaAluno[i].matricula);
            printf("\nCPF: %d", tabelaAluno[i].cpf);
            printf("\nNome: %s", tabelaAluno[i].nome);
            printf("\nSexo: %s", tabelaAluno[i].sexo);
            printf("\nE-mail: %s", tabelaAluno[i].email);
            printf("\nCodigo do Curso: %d", tabelaAluno[i].codigotipoCurso);
            printf("\n");
        }
    }
}

void altAluno() {
    int matricula;

    do {
        printf("Digite a matricula que voce deseja alterar: \n");
        scanf("%d", &matricula);

        for (int i = 0; i < SIZE; i++) {
            if (tabelaAluno[i].matricula == matricula) {
                system("clear");
                printf("\nMatricula: %d", tabelaAluno[i].matricula);
                printf("\nCPF: %d", tabelaAluno[i].cpf);
                printf("Nome: %s", tabelaAluno[i].nome);
                printf("Sexo: %s", tabelaAluno[i].sexo);
                printf("E-mail: %s", tabelaAluno[i].email);
                printf("Codigo do Curso: %d", tabelaAluno[i].codigotipoCurso);

                if (decisao("\n\nVoce tem certeza que deseja alterar o registro:\n\n1 - SIM\n2 - NAO\n") == 1) {
                    system("clear");
                    printf("Digite uma nova matricula: \n");
                    scanf("%d", &tabelaAluno[i].matricula);
                    printf("Digite o nome do aluno: \n");
                    fgets(tabelaAluno[i].nome, SIZE, stdin);
                    getchar();
                    printf("Registro alterado com sucesso!\n");
                } else {
                    printf("Registro NAO foi alterado.\n");
                }

                return;  // Encerra a função após a alteração ou decisão de não alterar
            }
        }

        // Se o loop terminou e a matrícula não foi encontrada
        system("clear");
        printf("ALERTA: MATRICULA NAO LOCALIZADA.\n\n");

    } while (decisao("Deseja tentar alterar novamente:\n\n1 - SIM\n2 - NAO\n") == 1);

    printf("Retornando ao menu.\n");
}


void delAluno() {
    struct Aluno vazio;
    int matricula;

    do {
        printf("Digite a matricula que voce deseja deletar: \n");
        scanf("%d", &matricula);

        for (int i = 0; i < SIZE; i++) {
            if (tabelaAluno[i].matricula == matricula) {
                system("clear");
                printf("\nMatricula: %d", tabelaAluno[i].matricula);
                printf("CPF: %d", tabelaAluno[i].cpf);
                printf("\nNome: %s", tabelaAluno[i].nome);
                printf("\nSexo: %s", tabelaAluno[i].sexo);
                printf("\nE-mail: %s", tabelaAluno[i].email);
                printf("\nCodigo do Curso: %d", tabelaAluno[i].codigotipoCurso);

                if (decisao("\n\nVoce tem certeza que deseja deletar a matricula:\n\n1 - SIM\n2 - NAO\n") == 1) {
                    system("clear");
                    tabelaAluno[i] = vazio;
                    printf("Matricula deletada com sucesso!\n");
                } else {
                    printf("Matricula NAO foi deletada.\n");
                }

                return;  // Encerra a função após a exclusão ou decisão de não excluir
            }
        }

        // Se o loop terminou e a matrícula não foi encontrada
        system("clear");
        printf("ALERTA: MATRICULA NAO LOCALIZADA.\n\n");

    } while (decisao("Deseja tentar deletar novamente:\n\n1 - SIM\n2 - NAO\n") == 1);

    printf("Retornando ao menu.\n");
}


//----------------------------------------------------FUNCOES INSCRICOES & MENU (HECTOR)-----------------------------------------------------
//FUNCAO NEGRITO - Coloca um texto em negrito. Utilize bold(1) para iniciar e bold(0) para finalizar
void bold(int status) {
	static const char *seq[] = {"\x1b[0m", "\x1b[1m"};
	printf("%s", seq[!!status]);
}

//FUNCAO DECISAO - Tem como objetivo receber um CHAR para imprimir na tela e perguntar ao usuario se ele deseja continuar
int decisao(char texto[200]){

    int decisao;

    printf("%s\n", texto);
    scanf("%d", &decisao);

    while (decisao != 1 && decisao != 2) {
        system("clear");
        printf("Digito invalido, por favor digite (1 - SIM|2 - NAO): \n"); 
        scanf("%s", &decisao);
    }
    return decisao;
    system("clear");
}

char convData(int intData) {
    int vDia;
    vDia = intData / 10000;
    int dia = (vDia / 100) % 100; // Obtm os primeiros dois dgitos (DD)
    int mes = (intData / 10000) % 100; // Obtm os prximos dois dgitos (MM)
    int ano = intData % 10000; // Obtm os ltimos quatro dgitos (AAAA)
    
    return printf("%02d/%02d/%04d", dia, mes, ano); // Exibe a data no formato desejado
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

//ULTIMO REGISTRO INSCRICAO DE DISCIPLINA - Funcao tem como objetivo retornar a posicao da ultima matricula registrada
int ultimoRegistro(){
    int controle;
    for(int i = 0; i < SIZE; i ++){
        if(tabelaInscricao[i].matricula != NULL){
            controle = i;
        }
    }
    return(controle + 1);
}

//FUNCAO VALIDACAO CADASTRO MATRICULA - Funcao tem como objetivo garantir o usuario escolheu uma matricula j� existente
int validaMatricula(int matricula){
    for(int i = 0; i < SIZE; i++){
        if(tabelaAluno[i].matricula == matricula){
            matricula = -1;
            break;
        }
    }
    return(matricula);
}

//FUNCAO VALIDACAO CADASTRO TIPOCURSO/DISCIPLINA - Funcao tem como objetivo garantir o usuario escolheu uma disciplina existente dentro do curso registrado em sua matricula
int validaDisciplina(int matricula, int disciplina){
    //char resposta[SIZE];
    for(int i = 0; i < SIZE; i++){
        if(tabelaDisciplina[i].codigo == disciplina){
            for(int j = 0; j < SIZE; j++){
                if( (tabelaAluno[j].matricula == matricula) && (tabelaAluno[j].codigotipoCurso == tabelaDisciplina[i].codigoTipoCurso) ){
                    return(1);
                    break;
                }
                if (j == 999){
                    return(2);
                    break;
                }
            }
        } 
        if(i == 999){
            return(3);
            break;
        }
    }
}

//FUNCAO INCLUIR INSCRICAO DE DISCIPLINA - Metodo utilizado para incluir uma nova INSCRICAO DE DISCIPLINA
void cadastroInscricao(){

    int vCadastro; //VARIAVEL DE MEMORIA LOCAL
    
    for(int i = ultimoRegistro(); i < SIZE; i ++){
        
        vCadastro = NULL; //VARIAVEL DE MEMORIA LOCAL
	    system("clear");
	    printf("Digite a MATRICULA do aluno: \n");
	    scanf("%d", &vCadastro);
        
        //FUNCAO VALIDA MATRICULA ---------------------------------------------------------------------------------------------------
        if(validaMatricula(vCadastro) != -1){
            system("clear");
            if(decisao("MATRICULA n�o existe. Deseja reiniciar o cadastro?\n\n1 - SIM\n2 - NAO\n") == 1){
                goto ERRO_INS_S;
            }else{ 
                goto ERRO_INS_N;
            }
        }else{
        //GRAVA MATRICULA -----------------------------------------------------------------------------------------------------------
            tabelaInscricao[i].matricula = vCadastro;
        }
        
        vCadastro = NULL; //LIMPA VARIAVEL LOCAL
		printf("Digite o CODIGO DA DISCIPLINA do CURSO: \n");
		scanf("%d", &vCadastro);
		
		//FUNCAO VALIDA DISCIPLINA --------------------------------------------------------------------------------------------------
		if(validaDisciplina(tabelaInscricao[i].matricula, vCadastro) == 1){// TUDO OK
        //GRAVA DISCIPLINA ----------------------------------------------------------------------------------------------------------    
            tabelaInscricao[i].codDisciplina = vCadastro;
        }else{
            system("clear");
            tabelaInscricao[i].matricula = NULL;
            if(validaDisciplina(tabelaInscricao[i].matricula, vCadastro) == 3){ //DISCIPLINA NAO CADASTRADA
                if(decisao("DISCIPLINA n�o existe. Deseja reiniciar o cadastro?\n\n1 - SIM\n2 - NAO\n") == 1){
                    goto ERRO_INS_S;
                }else{ 
                    goto ERRO_INS_N;
                }
            }else{ //DISCIPLINA FORA DA GRADE
                system("clear");
                tabelaInscricao[i].matricula = NULL; 
                if(decisao("DISCIPLINA fora da grade do CURSO do aluno. Deseja reiniciar o cadastro?\n\n1 - SIM\n2 - NAO\n") == 1){
                    goto ERRO_INS_S;
                }else{ 
                    goto ERRO_INS_N;
                }
            }

        }
        
        //GRAVA DATA -----------------------------------------------------------------------------------------------------------------
		printf("Digite a DATA DE INSCRICAO (DDMMAAAA): \n"); //GRAVA DATA
		scanf("%d", &tabelaInscricao[i].dataInscricao);
		
		//CONTROLE DE DUPLICIDADE DE INSCRICAO ---------------------------------------------------------------------------------------
		/*for(int j = ultimoRegistro() - 1; j >= 0; j--){
		    if( (tabelaInscricao[i].matricula == tabelaInscricao[j].matricula) && (tabelaInscricao[i].codDisciplina == tabelaInscricao[j].codDisciplina) && (tabelaInscricao[i].dataInscricao = tabelaInscricao[j].dataInscricao)){
		        system("clear");
		        tabelaInscricao[i].matricula = NULL;
		        tabelaInscricao[i].codDisciplina = NULL;
		        tabelaInscricao[i].dataInscricao = NULL;
		        if(decisao("REGISTRO duplicado. Deseja digitar outra INSCRICAO?\n\n1 - SIM\n2 - NAO\n") == 1){
                    goto ERRO_INS_S;
                } else{ 
                    goto ERRO_INS_N;
                }
		    }
		}*/

		system("clear");

		//CONTINUAR
		if (decisao("Deseja incluir outra inscricao?\n\n1 - SIM\n2 - NAO\n") == 2) {
			ERRO_INS_N:
			system("clear");
			break;
		}
		ERRO_INS_S:
	}
}

//FUNCAO IMPRIMIR INSCRICAO DISCIPLINA - Metodo utilizado para imprimir todas as INSCRICOES DE DISCIPLINAS feitas
void imprimirInscricao(){

    for(int i = 0; i < SIZE; i++) {
        if (tabelaInscricao[i].matricula != 0) {
            //printf("Codigo: %d", tabelaInscricao[i].codigo);
            printf("Matricula: %d", tabelaInscricao[i].matricula);
            printf("\nCod. Disciplina: %d", tabelaInscricao[i].codDisciplina);
            printf("\nData de inscricao: ");
            convData(tabelaInscricao[i].dataInscricao);
            printf("\n\n");
        } 
    }
}

//FUNCAO ALTERAR INSCRICAO DE DISCIPLINA - Funcao utilizada para alterar registro de INSCRICAO DE DISCIPLINA
void altInscricao(){
    
    int vMatricula, vDisciplina, vCodigo, cont;// VARIAVEL LOCAL
    
    printf("Digite a matricula que voce deseja alterar uma inscricao: \n");
    scanf("%d", &vMatricula);
    
    inicio_loop:
    cont = 1;
    system("clear");
    for (int i = 0; i < SIZE ; i ++){ //FOR PARA LISTAR TODAS AS INCRICOES DE UMA MATRICULA SELECIONADA
        tabelaInscricao[i].codigo = 0;
        if(tabelaInscricao[i].matricula == vMatricula){
                tabelaInscricao[i].codigo = cont;
                cont ++;
                printf("Codigo: %d", tabelaInscricao[i].codigo);
                printf("\nMatricula: %d", tabelaInscricao[i].matricula);
                printf("\nCod. Disciplina: %d", tabelaInscricao[i].codDisciplina);
                printf("\nData de inscricao: ");
                convData(tabelaInscricao[i].dataInscricao);
                printf("\n\n");
        }
    }
    printf("Digite o codigo de inscricao que voce deseja alterar: \n");
    scanf("%d", &vCodigo);
    system("clear");
    for (int i = 0; i < SIZE ; i ++){ //FOR PARA MOSTRAR A INSCRICAO SELECIONADA
        if(tabelaInscricao[i].codigo == vCodigo){
            printf("Matricula: %d", tabelaInscricao[i].matricula);
            printf("\nCod. Disciplina: %d", tabelaInscricao[i].codDisciplina);
            printf("\nData de inscricao: ");
            convData(tabelaInscricao[i].dataInscricao);
            printf("\n\n");

            if (decisao("Voce tem certeza que deseja alterar o registro:\n\n1 - SIM\n2 - NAO\n") == 1){ //CERTEZA QUE DESEJA EALTERAR?
                system("clear");
	         printf("Digite um o NOVO CODIGO DA DISCIPLINA do CURSO: \n"); //NOVOS DADOS
	         //scanf("%d", &tabelaInscricao[i].codDisciplina);
	         scanf("%d", &vDisciplina);
	         
	         //VALIDAR DISCIPLINA
	         if(validaDisciplina(tabelaInscricao[i].matricula, vDisciplina) == 1){ //TUDO OK
	            tabelaInscricao[i].codDisciplina = vDisciplina; //GRAVA DISCIPLINA
	         }else{
	            system("clear");
                if(validaDisciplina(tabelaInscricao[i].matricula, vDisciplina) == 3){ //DISCIPLINA NAO CADASTRADA
                    if(decisao("DISCIPLINA n�o existe. Deseja reiniciar o cadastro?\n\n1 - SIM\n2 - NAO\n") == 1){
                        goto inicio_loop;
                    }else{ 
                        goto fim_loop;
                    }
	            }else{ //DISCIPLINA FORA DA GRADE
                    if(decisao("DISCIPLINA fora da grade do CURSO do aluno. Deseja reiniciar o cadastro?\n\n1 - SIM\n2 - NAO\n") == 1){
                        goto inicio_loop;
                    }else{ 
                        goto fim_loop;
                    }
	            }
	         }
	         
	         printf("Digite uma NOVA DATA DE INSCRICAO (DDMMAAAA): \n"); //NOVOS DADOS
	         scanf("%d", &tabelaInscricao[i].dataInscricao);
	         break;
            }
        }else{
            if(i == 999){ //ELSE PARA INFORMAR QUE O CODIGO NAO FOI LOCALIZADO
                system("clear");
                printf("ALERTA: CODIGO NAO LOCALIZADO.\n\n");
                if (decisao("Deseja tentar alterar novamente:\n\n1 - SIM\n2 - NAO\n") == 1){//DESEJA TENTAR NOVAMENTE?
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
    
    printf("Digite a matricula que voce deseja deletar uma inscricao: \n");
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
                printf("\nData de inscricao: ");
                convData(tabelaInscricao[i].dataInscricao);
                printf("\n\n");
        }
    }
    printf("Digite o codigo de inscricao que voce deseja deletar: \n");
    scanf("%d", &vCodigo);
    system("clear");
    for (int i = 0; i < SIZE ; i ++){ //FOR PARA MOSTRAR A INSCRICAO SELECIONADA
        if(tabelaInscricao[i].codigo == vCodigo){
            printf("Matricula: %d", tabelaInscricao[i].matricula);
            printf("\nCod. Disciplina: %d", tabelaInscricao[i].codDisciplina);
            printf("\nData de inscricao: ");
            convData(tabelaInscricao[i].dataInscricao);
            printf("\n\n");
            
            if (decisao("Voce tem certeza que deseja deletar o registro:\n\n1 - SIM\n2 - NAO\n") == 1){ //CERTEZA QUE DESEJA EXCLUIR?
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
                if (decisao("Deseja tentar deletar novamente:\n\n1 - SIM\n2 - NAO\n") == 1){//DESEJA TENTAR NOVAMENTE?
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

// FUNCAO DE PRINT;------------------------------------------------------------------------
void imprimirDisciplinas() {
    

    if (totalDisciplinas == 0) { //verifica se existem disciplinas cadastradas
       
      system("clear");
       printf("Nao ha disciplinas cadastradas.\n\n");
    
       
    } else { 

    printf("Disciplinas Cadastradas: \n");
        
    //LOOP UTILIZADO PARA FAZER O PRINT DE TODAS AS DISCIPLINAS CADASTRADAS;
    for (int cont = 0; cont < totalDisciplinas; cont++) {    
        if (tabelaDisciplina[cont].codigo != 0) {
            printf("\nCodigo da Disciplina: %03d", tabelaDisciplina[cont].codigo);
            printf("\nNome da Disciplina: %s", tabelaDisciplina[cont].nome);
            printf("\nNome do Professor: %s", tabelaDisciplina[cont].nomeProfessor);
            printf("\nCodigo do Curso: %03d\n\n", tabelaDisciplina[cont].codigoTipoCurso);
        }
    }
    }
}   

// FUNÇÃO CRIAR DISCIPLINAS--------------------------------------------------------------

void incluirDisciplina() {
    char resposta; //validador de nova inclusão de curso
    int verificadorTipoCurso = 0;
    
    do { //repetidor
       
        if (totalDisciplinas < SIZE) { // VERIFICA SE O NUMERO DE DISCIPLINAS JA ATINGIU O MAXIMO
            
            
            if (numTabelaTipoCurso <= 0) { // VERIFICA SE EXISTEM CURSOS 
                
                system("clear");
                printf("Nao existem cursos cadastrados, cadastre um curso primeiro");
                
            } else {
                
                system("clear");
                printf("Cursos existentes:\n");
                
                for (int cont = 0; cont < numTabelaTipoCurso; cont++) {   // MOSTRADOR DE CURSOS 
                    
                printf("\nCodigo do curso: %03d", tabelaTipoCurso[cont].codigoTipoCurso);
                printf("\nNome do curso: %s", tabelaTipoCurso[cont].nome);
                printf("\nTurno do curso: %s\n", tabelaTipoCurso[cont].turno);
                
                    
                }// FIM DO FOR MOSTRADOR DOS CURSOS CADASTRADOS
                
                
                printf("\nDigite o codigo do curso ao qual voce deseja atribuir a disciplina: \n");
                getchar();
                scanf("%d", &verificadorTipoCurso);
                
                
                if ((verificadorTipoCurso > 0) && (verificadorTipoCurso <= numTabelaTipoCurso)) { // VERIFICA SE O CÓDIGO ESCOLHIDO EXISTE 

                // PRINT DAS INFORMAÇÕES DA DISCIPLINA DE CODIGO ESCOLHIDO
                
                system("clear");
                struct disciplina novaDisciplina; // VARIAVEL LOCAL PARA INCLUIR DISCIPLINAS NO ARRAY 
            

                getchar(); //limpador de buffer 
                printf("Digite o nome da disciplina a ser adicionada: \n");
                fgets(novaDisciplina.nome, sizeof(novaDisciplina.nome), stdin);
                novaDisciplina.nome[strcspn(novaDisciplina.nome, "\n")] = '\0'; //limpador de buffer

                system("clear");
                printf("Digite o nome do professor desta disciplina: \n");
                fgets(novaDisciplina.nomeProfessor, sizeof(novaDisciplina.nomeProfessor), stdin);
                novaDisciplina.nomeProfessor[strcspn(novaDisciplina.nomeProfessor, "\n")] = '\0'; //limpador de buffer

                novaDisciplina.codigo = totalDisciplinas + 1; //numTabelaTipoCurso = contador de cursos criados na tabela //novoTipoCurso define codigo do curso = tabela +1
                novaDisciplina.codigoTipoCurso = verificadorTipoCurso; // INCLUI O CODIGO DO TIPO CURSO ESCOLHIDO NA VARIAVEL CODIGO TIPO CURSO DO ARRAY DISCIPLINA
               
                tabelaDisciplina[totalDisciplinas] = novaDisciplina; // inclui as informações salvas na variavel local dentro do array utilizando o contador numTabelaTipoCurso 
                
                totalDisciplinas++; //adiciona +1 ao contador de cursos na tabela 

                system("clear");
                printf("Disciplina com sucesso!\n");

                // Pergunta se deseja incluir outro tipo de curso
                system("clear");
                printf("Deseja incluir outra disciplina ?\n\n1 - SIM\n2 - NAO\n");
                scanf(" %c", &resposta);

            } // FIM DO SELECIONADOR DE CURSOS
            system("clear");
            printf("dasda");
            
            } // FIM DO VERIFICADOR DA EXISTENCIA DE CURSOS CADASTRADOS
        
        } else { // FIM DO VERIFICADOR DE SIZE
            system("clear");
            printf("Erro: Limite maximo de disciplinas atingido.\n");
            resposta = '2';  // Forçar saída do loop se atingir o limite
        
        } // FIM DO ELSE VERIFICADOR DE SIZE
    
    } while (resposta == '1'); //FIM DO LOOP DO
    
    
    printf("Retornando ao menu.\n");

} //FIM DA FUNÇÃO

// FUNCAO ALTERAR DISCIPLINAS;----------------------------------------------------------------------
void alterarDisciplina() {
    // SOLICITANDO CODIGO A SER ALTERADO
    int altDisciplina = 0;
    
    if (totalDisciplinas == 0) { //verifica se existem disciplinas cadastradas
       system("clear");
       printf("Nao ha disciplinas cadastradas.\n\n");
    
       
    } else { 
    
    system("clear");
    printf("Digite o codigo da disciplina que você deseja alterar: \n");
    scanf("%d", &altDisciplina);

    //VERIFICADOR DE CÓDIGO
    if (altDisciplina > 0 && altDisciplina <= totalDisciplinas) {

    // PRINT DAS INFORMAÇÕES DA DISCIPLINA DE CODIGO ESCOLHIDO
    system("clear");
    printf("Codigo: %03d", tabelaDisciplina[altDisciplina - 1].codigo);
    printf("\nNome da Disciplina: %s", tabelaDisciplina[altDisciplina - 1].nome);
    printf("\nNome do Professor: %s", tabelaDisciplina[altDisciplina - 1].nomeProfessor);
    printf("\nCodigo tipo curso: %d", tabelaDisciplina[altDisciplina - 1].codigoTipoCurso);

   
   
       
        // VERIFICADOR
        int codVerificador = 1;
        printf("\n\nVoce realmente deseja fazer a alteracao \n\n1 - SIM\n2 - NAO\n");
        scanf("%d", &codVerificador);
        getchar();
        // ALTERANDO OS VALORES DAS DISCIPLINAS(SEM ALTERAR O CODIGO)
        if (codVerificador == 1) {
            
            system("clear");
            printf("Digite o novo nome da disciplina: \n");
            fgets(tabelaDisciplina[altDisciplina - 1].nome, sizeof(tabelaDisciplina[altDisciplina - 1].nome), stdin);
           tabelaDisciplina[altDisciplina - 1].nome[strcspn(tabelaDisciplina[altDisciplina - 1].nome, "\n")] = 0;
    
            system("clear");
            printf("Digite o novo nome do professor: \n");
            fgets(tabelaDisciplina[altDisciplina - 1].nomeProfessor, sizeof(tabelaDisciplina[altDisciplina - 1].nomeProfessor), stdin);
            tabelaDisciplina[altDisciplina - 1].nomeProfessor[strcspn(tabelaDisciplina[altDisciplina - 1].nomeProfessor, "\n")] = 0;
            
            system("clear");
            printf("Disciplina alterada\n");
            
        } else {
            system("clear");
            printf("Operacao Cancelada\n");
        }
            
    }else {
    system("clear");
    printf("Codigo de disciplina nao existente\n");
    }
    }
}

// FUNÇÃO DELETAR DISCIPLINAS---------------------------------------------------------------------------------
int deletarDisciplina() {
    int delDisciplina = 0;
    struct disciplina vazio;
    
    // SOLICITANDO CÓDIGO A SER EXCLUIDO
   
    if (totalDisciplinas == 0) { //verifica se existem disciplinas cadastradas
       system("clear");
       printf("Nao ha disciplinas cadastradas.\n\n");
    
       
    } else {

    system("clear");
    printf("Digite o codigo da disciplina que voce deseja excluir:\n");
    scanf("%d", &delDisciplina);
    getchar();
    
     // PRINT DAS INFORMAÇÕES DA DISCIPLINA DE CÓDIGO ESCOLHIDO
    system("clear");
    printf("Codigo: %03d", tabelaDisciplina[delDisciplina - 1].codigo);
    printf("\nNome da Disciplina: %s", tabelaDisciplina[delDisciplina - 1].nome);
    printf("\nNome do Professor: %s", tabelaDisciplina[delDisciplina - 1].nomeProfessor);
    printf("\nCodigo tipo curso: %d", tabelaDisciplina[delDisciplina - 1].codigoTipoCurso);

    // VERIFICADOR DE CODIGO (EM TESTE)
    if (delDisciplina > 0 && delDisciplina <= totalDisciplinas) {
        
        // VERIFICADOR
        int codVerificador = 0;
        printf("\n\nVoce realmente deseja excluir?\n1 - SIM\n2 - NAO\n");
        scanf("%d", &codVerificador);
        getchar();
            
        //EXCLUINDO 
        if (codVerificador == 1) {
            
            tabelaDisciplina[delDisciplina - 1] = vazio;
           
            system("clear");
            printf("Disciplina excluida\n");
            return totalDisciplinas; // Retorna a nova quantidade de disciplinas
        } else {
            
            system("clear");
            printf("\nOperacao Cancelada\n");
        }
    } else {
        system("clear");
        printf("\nCodigo de disciplina nao existente\n");
    }
    return totalDisciplinas; // Retorna a quantidade original de disciplinas
    }
}


//---------------------------------------------------FIM FUNÇÕES DISCIPLINA (PEDRO)----------------------------------------




void createTipoCurso() {
    char resposta; //validador de nova inclusão de curso
    int verificador; //validador do turno
    
    do { //repetidor
       
        if (numTabelaTipoCurso < SIZE) { //verifica se o numero de cursos atingiu o máximo estipulado
            
            system("clear");
            struct tipoCurso novoTipoCurso; //variavel local que inclui o curso criado no array 

            getchar(); //limpador de buffer 
            printf("Digite o nome do curso a ser adicionado: \n");
            fgets(novoTipoCurso.nome, sizeof(novoTipoCurso.nome), stdin);
            novoTipoCurso.nome[strcspn(novoTipoCurso.nome, "\n")] = '\0'; //limpador de buffer

            system("clear");// limpador da tela antes do loop para apagar a mensagem anterior mas manter a do default
           

            do { //loop para evitar valores errados
              
                printf("Digite o turno do curso a ser adicionado \n1 - Diurno\n2 - Noturno): \n");
                scanf("%d", &verificador);

                switch (verificador) { //switch case para definir turno apenas usando numeros (evitar inclusão de valor sem sentido dentro da aba turno)
                    
                    case 1:
                        strcpy(novoTipoCurso.turno, "Diurno"); //strcpy (string copy) utilizado para atribuir um valor a uma string, tentei com "=" mas não deu certo...
                        break;
        
                    case 2:
                        strcpy(novoTipoCurso.turno, "Noturno");
                        break;
        
                    default:
                        system("clear");
                        printf("Erro: Valor de turno inválido.\n\n");
                }       
            } while (verificador != 1 && verificador != 2); // enquanto o valor não for nem 1 e nem 2, ele fica repetindo 
            
            
            novoTipoCurso.codigoTipoCurso = numTabelaTipoCurso + 1; //numTabelaTipoCurso = contador de cursos criados na tabela //novoTipoCurso define codigo do curso = tabela +1
            tabelaTipoCurso[numTabelaTipoCurso] = novoTipoCurso; // atribui valores da variavel local temporária ao array    
            numTabelaTipoCurso++; //adiciona +1 ao contador de cursos na tabela 

            system("clear");
            printf("Curso criado com sucesso!\n");

            // Pergunta se deseja incluir outro tipo de curso
            system("clear");
            printf("Deseja incluir outro curso ?\n\n1 - SIM\n2 - NAO\n");
            scanf(" %c", &resposta);

        } else {
            system("clear");
            printf("Erro: Limite maximo de cursos atingido.\n");
            resposta = '2';  // Forçar saída do loop se atingir o limite
        }

    } while (resposta == '1');
    
    printf("Retornando ao menu.\n");
}

void readTipoCurso() {
    
    system("clear");
    
    if (numTabelaTipoCurso == 0){ //Verifica se há cursos a serem exibidos
        system("clear");
        printf("Nao ha cursos cadastrados.\n");
    }else {
        
    for (int i = 0; i < numTabelaTipoCurso; i++) { //laço de repetição que exibe os cursos cadastrados 
            if (tabelaTipoCurso[i].codigoTipoCurso != 0) {
            printf("Codigo: %03d\n", tabelaTipoCurso[i].codigoTipoCurso); // i = posição no array
            printf("Curso: %s\n", tabelaTipoCurso[i].nome);
            printf("Turno: %s\n\n", tabelaTipoCurso[i].turno);
            }
        
        }
    }
}

void updateTipoCurso() {
    // SOLICITANDO CODIGO DO CURSO  A SER ALTERADO
    struct tipoCurso novoTipoCurso; //variavel local temporaria para armazenar um array 
    int verificador; // verificador do "DO-WHILE"
   
    int altTipoCurso = 0; //variavel de codigoTipoCurso a ser trocado
    system("clear");
    
    if (numTabelaTipoCurso == 0) { //verifica se existem cursos cadastrados
       system("clear");
       printf("Nao ha curso cadastrados.\n");
    
       
    } else {
    
    printf("Digite o codigo do curso que você deseja alterar: \n");
    scanf("%d", &altTipoCurso); //atribui o codigo do curso selecionado à variavel altTipoCurso
    
        
    //Verificador de código 
     if (altTipoCurso > 0 && altTipoCurso <= numTabelaTipoCurso) { // verifica se o código inserido é menor ou igual a quantidade de curso no array

    // PRINT DAS INFORMAÇÕES DO CURSO DE CODIGO ESCOLHIDO
     system("clear");
     printf("Codigo: %03d\n", tabelaTipoCurso[altTipoCurso -1].codigoTipoCurso); //acha o curso pelo código inserido, e diminui 1 pra localizar as informações no array
     printf("Curso: %s\n", tabelaTipoCurso[altTipoCurso -1].nome);
     printf("Turno: %s\n", tabelaTipoCurso[altTipoCurso -1].turno);
          
    
       
        // VERIFICADOR
        int codVerificador = 1;
        printf("\n\nVoce realmente deseja fazer a alteracao \n\n1 - SIM\n2 - NAO\n");
        scanf("%d", &codVerificador);
        getchar();
        // ALTERANDO OS VALORES DOS CURSOS (SEM ALTERAR O CODIGO)
        if (codVerificador == 1) { //condição para que o usuário prossiga com a alteração
            
            system("clear");
            printf("Digite o nome do curso a ser alterado: \n");
            fgets(tabelaTipoCurso[altTipoCurso - 1].nome, sizeof(tabelaTipoCurso[altTipoCurso - 1].nome), stdin); //localiza o curso no array pelo código inserido -1, e salva novas informações em cima do mesmo
            tabelaTipoCurso[altTipoCurso - 1].nome[strcspn(tabelaTipoCurso[altTipoCurso - 1].nome, "\n")] = 0; //limpador de buffer

            system("clear");
             
             do { //loop para evitar valores errados
              
                printf("Digite o turno do curso a ser adicionado \n1 - Diurno\n2 - Noturno): \n");
                scanf("%d", &verificador);

                switch (verificador) { //switch case para definir turno apenas usando numeros (evitar inclusão de valor sem sentido dentro da aba turno)
                    
                    case 1:
                        strcpy(novoTipoCurso.turno, "Diurno"); //strcpy (string copy) utilizado para atribuir um valor a uma string, tentei com "=" mas não deu certo...
                        break;
        
                    case 2:
                        strcpy(novoTipoCurso.turno, "Noturno");
                        break;
        
                    default:
                        system("clear");
                        printf("Erro: Valor de turno inválido.\n\n");
                }       
            } while (verificador != 1 && verificador != 2); // enquanto o valor não for nem 1 e nem 2, ele fica repetindo  
            
            system("clear");
            printf("Curso alterado\n");
            
        } else { //caso o usuário não deseje prosseguir com a alteração, a mensagem é exibida:
            system("clear");
            printf("Operacao Cancelada\n");
        }
            
    }else {
    system("clear");
    printf("Codigo do curso nao existente\n"); //mensagem exibida caso o código inserido não exista no array (resposta do if/else verificador)
    } 
    }    
    }
    




void deleteTipoCurso() {
    struct tipoCurso vazio; // variavel tipo curso chamado vazio para usar no delete
    
    // SOLICITANDO CÓDIGO A SER EXCLUIDO
    int delTipoCurso = 0;
    system("clear");
    printf("Digite o codigo do curso que voce deseja excluir:\n");
    scanf("%d", &delTipoCurso);
    getchar();
    
     // PRINT DAS INFORMAÇÕES DO TIPO DE CURSO DE CÓDIGO ESCOLHIDO
     system("clear");
     printf("Codigo: %03d\n", tabelaTipoCurso[delTipoCurso -1].codigoTipoCurso); //acha o curso pelo código inserido, e diminui 1 pra localizar as informações no array
     printf("Curso: %s\n", tabelaTipoCurso[delTipoCurso -1].nome);
     printf("Turno: %s\n", tabelaTipoCurso[delTipoCurso -1].turno);

    // VERIFICADOR DE CODIGO (EM TESTE)
    if (delTipoCurso > 0 && delTipoCurso <= numTabelaTipoCurso) {
        
        // VERIFICADOR
        int codVerificador = 0;
        printf("\n\nVoce realmente deseja excluir?\n1 - SIM\n2 - NAO\n");
        scanf("%d", &codVerificador);
        getchar();
            
        //EXCLUINDO 
        if (codVerificador == 1) {
            
            tabelaTipoCurso[delTipoCurso - 1] = vazio; // joga as informações deletadas dentro da variavel delete
           
            system("clear");
            printf("Curso excluido\n");
            
        } else {
            
            system("clear");
            printf("\nOperacao Cancelada\n");
        }
    } else {
        system("clear");
        printf("\nCodigo do curso nao existente\n");
    }
    
}
    
    
//FIM DAS FUNÇÕES DO tIPOCURSO



//PROGRAMA PRINCIPAL
//-----------------------------------------------------------INICIO MAIN--------------------------------------------------------------------
int main() {

    system("clear");
    //struct Aluno alunos[MAX_ALUNOS];
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
        printf("| Digite uma das opcoes para prosseguir.                                                  |\n");    
        printf("|_________________________________________________________________________________________|\n");

        menu = validaMenu(4, 0);

        switch(menu) {
	            case 1:
	                while (1) {
	                    system("clear");
	                    menuSecundario("CADASTRO DE ALUNO");
	
	                    int menu = validaMenu(5, 1);
	
	                    if (menu == 1) {
				cadastroAluno();
                		break;
			    } else if (menu == 2) {
	                        imprimirAluno();
				break;
	                    } else if (menu == 3) {
				altAluno();
				break;
			    } else if (menu == 4) {
				delAluno();
				break;
			    } else if (menu == 5) {
	                        // Voltar ao menu principal
                            system("clear");
	                        break;
	                    }
		                system("clear");
		            }
		                break;
	
			case 2:
                   
            do {  
                               
				system("clear");
				menuSecundario("CADASTRO DE CURSO");
				menu = validaMenu(5,1);

				if(menu == 1){ //INCLUIR------------------------
						system("clear");
						createTipoCurso();
						
						

						//CONTINUAR
						system("clear");
						if (decisao("\nDeseja retornar ao menu principal?\n\n1 - SIM\n2 - NAO\n") == 1) {
							menu = 5;
						} else{ menu = 6; }
						system("clear");
					}

				if(menu == 2){//IMPRIMIR-----------------------
				        readTipoCurso();

						//CONTINUAR
						if (decisao("\nDeseja retornar ao menu principal?\n\n1 - SIM\n2 - NAO\n") == 1) {
							menu = 5;
						} else{ menu = 6; }
						system("clear");
					}

					if(menu == 3){//ALTERAR------------------------
					    system("clear");
					    
					    updateTipoCurso();
					    

					    //CONTINUAR
						if (decisao("\nDeseja retornar ao menu principal?\n\n1 - SIM\n2 - NAO\n") == 1) {
							menu = 5;
						} else{ menu = 6; }
						system("clear");

					}

					if(menu == 4){//EXCLUIR------------------------
					   
					   system("clear");
                       deleteTipoCurso();
                        //deletarInscricao();
					   

					    //CONTINUAR
						if (decisao("\nDeseja retornar ao menu principal?\n\n1 - SIM\n2 - NAO\n") == 1) {
							menu = 5;
						} else{ menu = 6; }
						system("clear");
					}

					system("clear");

				}while(menu == 6); //MENU IGUAL A 6 VOLTA PARA O MESMO MENU, POREM IGUAL 5 RETORNA PARA O PRINCIPAL
				break;
				
				system("clear");
                break;

			case 3:
            do{
				system("clear");
				menuSecundario("CADASTRO DE DISCIPLINA");
				menu = validaMenu(5,1);

				if(menu == 1){
							system("clear");
                            incluirDisciplina();
						
						    //CONTINUAR
							system("clear");
							if (decisao("Deseja retornar ao menu principal?\n\n1 - SIM\n2 - NAO\n") == 1) {
								menu = 5;
							} else{ menu = 6; }
							system("clear");
                                             
						}
						//PRINT DOS REGISTROS
						if(menu == 2){
							system("clear");
							imprimirDisciplinas();
							
							//CONTINUAR
							if (decisao("\nDeseja retornar ao menu principal?\n\n1 - SIM\n2 - NAO\n") == 1) {
								menu = 5;
							} else{ menu = 6; }
							system("clear");
						}
						// ALTERAR REGISTROS	
						if(menu == 3){
						    system("clear");
						    alterarDisciplina();
						    
						    //CONTINUAR
							if (decisao("\nDeseja retornar ao menu principal?\n\n1 - SIM\n2 - NAO\n") == 1) {
								menu = 5;
							} else{ menu = 6; }
							system("clear");
						}
						// DELETAR REGISTROS	
						if(menu == 4){
						    
						    system("clear");
						    deletarDisciplina();
						    
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