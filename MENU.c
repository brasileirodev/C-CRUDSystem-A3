#include <stdio.h>

void bold(int status) {
        static const char *seq[] = {"\x1b[0m", "\x1b[1m"};
        printf("%s", seq[!!status]);
}

int main(){

        int menu;

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
                printf("| 4 - INSCRICAO DE DISCIPLINA                                                             |\n");
                printf("| 0 - SAIR                                                                                |\n");
                printf("|                                                                                         |\n");    
                printf("| Digite uma das opcao para prosseguir.                                                   |\n");    
                printf("|_________________________________________________________________________________________|\n");


                scanf("%d", &menu);
                
                while ( (menu > 4) || (menu < 0) ){
                        printf("Digite um menu válido.\n");
                        scanf("%d", &menu);
                }
                        
                switch(menu){
                                case 1:
                                
                                        system("clear");
                                        menu = 0;
                                
                                        printf(" _________________________________________________________________________________________\n");
                                        printf("|                                                                                         |\n");
                                        printf("| SISTEMA DE CADASTRO                                                                     |\n");
                                        printf("|                                                                                         |\n");
                                        printf("| MENU SELECIONADO:                                                                       |\n");
                                        printf("|                                                                                         |\n");
                                        bold(1);
                                        printf("| CADASTRO ALUNO                                                                          |\n");
                                        bold(0);
                                        printf("|   1 - INCLUIR                                                                           |\n");
                                        printf("|   2 - LEITURA                                                                           |\n");
                                        printf("|   3 - ALTERAR                                                                           |\n");
                                        printf("|   4 - DELETAR                                                                           |\n");
                                        printf("|   5 - VOLTAR                                                                            |\n");
                                        printf("|                                                                                         |\n"); 
                                        printf("| Digite uma das operacoes para prosseguir.                                               |\n");    
                                        printf("|_________________________________________________________________________________________|\n");
                                        
                                        scanf("%d", &menu);
                                        
                                        while ( (menu > 5) || (menu < 1) ){
                                                printf("Digite um menu válido.\n");
                                                scanf("%d", &menu);
                                        }
                                        
                                        system("clear");
                                        break;
                                                
                                case 2:
                                                
                                        system("clear");
                                        menu = 0;
                                
                                        printf(" _________________________________________________________________________________________\n");
                                        printf("|                                                                                         |\n");
                                        printf("| SISTEMA DE CADASTRO                                                                     |\n");
                                        printf("|                                                                                         |\n");
                                        printf("| MENU SELECIONADO:                                                                       |\n");
                                        printf("|                                                                                         |\n");
                                        bold(1);
                                        printf("| CADASTRO TIPO DE CURSO                                                              |\n");
                                        bold(0);
                                        printf("|   1 - INCLUIR                                                                           |\n");
                                        printf("|   2 - LEITURA                                                                           |\n");
                                        printf("|   3 - ALTERAR                                                                           |\n");
                                        printf("|   4 - DELETAR                                                                           |\n");
                                        printf("|   5 - VOLTAR                                                                            |\n");
                                        printf("|                                                                                         |\n"); 
                                        printf("| Digite uma das operacoes para prosseguir.                                               |\n");    
                                        printf("|_________________________________________________________________________________________|\n");
                                        
                                        scanf("%d", &menu);
                                        
                                        while ( (menu > 5) || (menu < 1) ){
                                                printf("Digite um menu válido.\n");
                                                scanf("%d", &menu);
                                        }
                                        
                                        system("clear");
                                        break;
                                                
                                case 3:
                                        
                                        system("clear");
                                        menu = 0;
                                
                                        printf(" _________________________________________________________________________________________\n");
                                        printf("|                                                                                         |\n");
                                        printf("| SISTEMA DE CADASTRO                                                                     |\n");
                                        printf("|                                                                                         |\n");
                                        printf("| MENU SELECIONADO:                                                                       |\n");
                                        printf("|                                                                                         |\n");
                                        bold(1);
                                        printf("| CADASTRO DISCIPLINA                                                                     |\n");
                                        bold(0);
                                        printf("|   1 - INCLUIR                                                                           |\n");
                                        printf("|   2 - LEITURA                                                                           |\n");
                                        printf("|   3 - ALTERAR                                                                           |\n");
                                        printf("|   4 - DELETAR                                                                           |\n");
                                        printf("|   5 - VOLTAR                                                                            |\n");
                                        printf("|                                                                                         |\n"); 
                                        printf("| Digite uma das operacoes para prosseguir.                                               |\n");    
                                        printf("|_________________________________________________________________________________________|\n");
                                        
                                        scanf("%d", &menu);
                                        
                                        while ( (menu > 5) || (menu < 1) ){
                                                printf("Digite um menu válido.\n");
                                                scanf("%d", &menu);
                                        }
                                        
                                        system("clear");
                                        break;
                                        
                                case 4:
                                
                                    system("clear");
                                        menu = 0;
                                
                                        printf(" _________________________________________________________________________________________\n");
                                        printf("|                                                                                         |\n");
                                        printf("| SISTEMA DE CADASTRO                                                                     |\n");
                                        printf("|                                                                                         |\n");
                                        printf("| MENU SELECIONADO:                                                                       |\n");
                                        printf("|                                                                                         |\n");
                                        bold(1);
                                        printf("| INSCRIÇÃO DE DISCIPLINA                                                                 |\n");
                                        bold(0);
                                        printf("|   1 - INCLUIR                                                                           |\n");
                                        printf("|   2 - LEITURA                                                                           |\n");
                                        printf("|   3 - ALTERAR                                                                           |\n");
                                        printf("|   4 - DELETAR                                                                           |\n");
                                        printf("|   5 - VOLTAR                                                                            |\n");
                                        printf("|                                                                                         |\n"); 
                                        printf("| Digite uma das operacoes para prosseguir.                                               |\n");    
                                        printf("|_________________________________________________________________________________________|\n");
                                        
                                        scanf("%d", &menu);
                                        
                                        while ( (menu > 5) || (menu < 1) ){
                                                printf("Digite um menu válido.\n");
                                                scanf("%d", &menu);
                                        }
                                        
                                        system("clear");
                                        break;
                                                
                                case 0: printf("Você saiu do sistema");
                                                system("clear");
                                                break;
                }
                
        }while(menu == 5);

}