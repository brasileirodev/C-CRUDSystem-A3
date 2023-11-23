#include <stdio.h>
#include <string.h>
#define SIZE 100

//DECLARAÇÃO DE OBJETOS
struct inscricaoDisciplina {
    int matricula;
    int codDisciplina;
    int dataInscricao;
    int codigo;
};

struct aluno {
    int matricula;
};

struct disciplina {
    int codigo;
};

struct tipoCurso {
    int codigo;
};

//DECLARAÇÃO DE VARIAVEIS GLOBAIS
struct inscricaoDisciplina tabelaInscricao[SIZE]; //ARRAY
struct aluno tabelaAluno[SIZE]; //ARRAY
struct disciplina tabelaDisciplina[SIZE]; //ARRAY
struct tipoCurso tabelaCurso[SIZE]; //ARRAY

//MÉTODO NEGRITO - Coloca um texto em negrito. Utilize bold(1) para iniciar e bold(0) para finalizar
void bold(int status) {
	static const char *seq[] = {"\x1b[0m", "\x1b[1m"};
	printf("%s", seq[!!status]);
}

//MÉTODO TELA DO MENU SECUNDÁRIO - Padronização de menu. Recebe um CHAR com o nome do menu selecionado
char menuSecundario(char texto[100]){
    
    int controle;
    
    controle = strlen(texto); //FUNÇÃO QUE CONTA CARACTERE
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
	printf("| Digite uma das operações para prosseguir.                                               |\n");    
	printf("|_________________________________________________________________________________________|\n");

}

//MÉTODO DECISÃO - Tem como objetivo receber um CHAR para imprimir na tela e perguntar ao usuário se ele deseja continuar
int decisao(char texto[200]){
    int decisao;
    printf("%s\n", texto);
    scanf("%d", &decisao);
        
    while (decisao != 1 && decisao != 2) {
        system("clear");
        printf("Dígito inválida, por favor digite (1 - SIM|2 - NÃO): \n"); 
        scanf("%s", &decisao);
    }
    return decisao;
    system("clear");
}

//MÉTODO IMPRIMIR INSCRIÇÃO DISCIPLINA - Método utilizado para imprimir todas as INSCRIÇÕES DE DISCIPLINAS feitas
int imprimir(){
    //char decisao[1];
    for(int i = 0; i < SIZE; i++) {
        if (tabelaInscricao[i].codigo != 0) {
            printf("Código: %d", tabelaInscricao[i].codigo);
            printf("\nMatricula: %d", tabelaInscricao[i].matricula);
            printf("\nCod. Disciplina: %d", tabelaInscricao[i].codDisciplina);
            printf("\nData de inscrição: %d\n", tabelaInscricao[i].dataInscricao);
        } 
    }
}

//MÉTODO DELETAR INSCRIÇÃO DE DISCIPLINA - Método utilizado para deletar registro de INSCRIÇÃO DE DISCIPLINA
int deletarInscricao(){
    
    int delete;
    printf("Digite o código de inscrição de disciplina que você deseja deletar: \n");
    scanf("%d", &delete);
    
    system("clear");
	printf("Código: %d", tabelaInscricao[delete-1].codigo);
    printf("\nMatricula: %d", tabelaInscricao[delete-1].matricula);
    printf("\nCod. Disciplina: %d", tabelaInscricao[delete-1].codDisciplina);
    printf("\nData de inscrição: %d\n\n", tabelaInscricao[delete-1].dataInscricao);
    
    //CONTINUAR
    if (decisao("Você tem certeza que deseja excluir o registro:\n\n1 - SIM\n2 - NÃO\n") == 1) {
        tabelaInscricao[delete-1].codigo = NULL;
        tabelaInscricao[delete-1].matricula = NULL;
        tabelaInscricao[delete-1].codDisciplina = NULL;
        tabelaInscricao[delete-1].dataInscricao = NULL;
	}
}

//MÉTODO ALTERAR INSCRIÇÃO DE DISCIPLINA - Método utilizado para alterar registro de INSCRIÇÃO DE DISCIPLINA
int alterarInscricao(){
    
    int alt;
    printf("Digite o código de inscrição de disciplina que você deseja deletar: \n");
    scanf("%d", &alt);
    
    system("clear");
	printf("Código: %d", tabelaInscricao[alt-1].codigo);
    printf("\nMatricula: %d", tabelaInscricao[alt-1].matricula);
    printf("\nCod. Disciplina: %d", tabelaInscricao[alt-1].codDisciplina);
    printf("\nData de inscrição: %d\n\n", tabelaInscricao[alt-1].dataInscricao);
    
    //CONTINUAR
    if (decisao("\nVocê tem certeza que deseja alterar o registro:\n\n1 - SIM\n2 - NÃO\n") == 1) {
        system("clear");
        printf("Digite a NOVA MATRICULA do aluno: \n");
		scanf("%d", &tabelaInscricao[alt-1].matricula);
		printf("Digite o NOVO CODIGO DA DISCIPLINA do CURSO: \n");
		scanf("%d", &tabelaInscricao[alt-1].codDisciplina);
		printf("Digite a NOVA DATA DE INSCRICAO (DDMMAAAA): \n");
		scanf("%d", &tabelaInscricao[alt-1].dataInscricao);
	}
}

//MÉTODO VALIDA MENU - Tem como objetivo receber dois INT re range do menu
int validaMenu(int maior, int menor){
    int menu;
    scanf("%d", &menu);
    while ( (menu > maior) || (menu < menor) ){
		printf("Digite um menu válido.\n");
	    scanf("%d", &menu);	
	}
	return menu;
}

//MÉTODO DE AUTOINCREMENT - RECEBER UM CHAR PARA ESCOLHER EM QUAL TABELA IRÁ REALIZAR O AUTOINCREMENT
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

//PROGRAMA PRINCIPAL
void main(){

	//DECLARAÇÃO DE VARIAVEIS LOCAIS
	int menu;
	
	//BEGIN
	system("clear");

	do{
	
		system("clear");
		
		printf(" _________________________________________________________________________________________\n");
		printf("|                                                                                         |\n");
		printf("| SISTEMA DE CADASTRO                                                                     |\n");
		printf("|                                                                                         |\n");
		printf("| MENU:                                                                                   |\n");
		printf("|                                                                                         |\n");
		printf("| 1 - CADASTRO ALUNO                                                                      |\n"); 
		printf("| 2 - CADASTRO TIPO DE CURSO                                                              |\n");
		printf("| 3 - CADASTRO DISCIPLINA                                                                 |\n");
		printf("| 4 - INSCRIÇÃO DE DISCIPLINA                                                             |\n");
		printf("| 0 - SAIR                                                                                |\n");
		printf("|                                                                                         |\n");    
		printf("| Digite uma das opção para prosseguir.                                                   |\n");    
		printf("|_________________________________________________________________________________________|\n");
			
		switch(validaMenu(4,0)){
				case 1:
				
					system("clear");
					
					menuSecundario("CADASTRO ALUNO");
					
					menu = validaMenu(5,1);
					
					system("clear");
					break;
						
				case 2:
						
					system("clear");
					
					menuSecundario("CADASTRO DE CURSO");
					
					menu = validaMenu(5,1);
					
					system("clear");
					break;
						
				case 3:
					
					system("clear");
					
					menuSecundario("CADASTRO DE DISCIPLINA");
					
					menu = validaMenu(5,1);
					
					system("clear");
					break;
					
				case 4:
				
					do{
						system("clear");
						
					    menuSecundario("INSCRICAO DE DISCIPLINA");
						
						menu = validaMenu(5,1);
					
						if(menu == 1){
							system("clear");
							for(int i = autoincrement("INSCRICAO DE DISCIPLINA") - 1; i < SIZE; i ++){
							    
								printf("Digite a MATRICULA do aluno: \n");
								scanf("%d", &tabelaInscricao[i].matricula);
				
								printf("Digite o CODIGO DA DISCIPLINA do CURSO: \n");
								scanf("%d", &tabelaInscricao[i].codDisciplina);
				
								printf("Digite a DATA DE INSCRICAO (DDMMAAAA): \n");
								scanf("%d", &tabelaInscricao[i].dataInscricao);
								
								tabelaInscricao[i].codigo = autoincrement("INSCRICAO DE DISCIPLINA");
								system("clear");
			
								//CONTINUAR
								if (decisao("Deseja continuar incluindo matricula?\n\n1 - SIM\n2 - NÃO\n") == 2) {
									break;
								}
								system("clear");
							}
							menu = 6;
						}
						
						if(menu == 2){
							system("clear");
							imprimir();
							
							//CONTINUAR
							if (decisao("\nDeseja retornar ao menu principal?\n\n1 - SIM\n2 - NÃO\n") == 1) {
								menu = 5;
							} else{ menu = 6; }
							system("clear");
						}
							
						if(menu == 3){
						    system("clear");
						    alterarInscricao();
						    system("clear");
						    
						    //CONTINUAR
							if (decisao("\nDeseja retornar ao menu principal?\n\n1 - SIM\n2 - NÃO\n") == 1) {
								menu = 5;
							} else{ menu = 6; }
							system("clear");
						}
							
						if(menu == 4){
						    system("clear");
						    deletarInscricao();
						    system("clear");
						    
						    //CONTINUAR
							if (decisao("\nDeseja retornar ao menu principal?\n\n1 - SIM\n2 - NÃO\n") == 1) {
								menu = 5;
							} else{ menu = 6; }
							system("clear");
						}
						
						system("clear");
						
					}while(menu == 6); //MENU IGUAL A 6 VOLTA PARA O MESMO MENU, PORÉM IGUAL 5 RETORNA PARA O PRINCIPAL
					break;
						
				case 0: 
				
					system("clear");
					menu = 0;
					break;
				
		} //FIM SWITCH MENU PRINCIPAL
		
	}while(menu == 5); //MENU IGUAL A 5 RETORNA PARA O PRINCIPAL E DIFERENTE FECHA O PROGRAMA
	
	//SAIR DO PROGRAMA
	//system("clear");
	//decisao("ALERTA! Você irá sair do programa, deseja realmente sair?");