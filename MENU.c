#include <stdio.h>


void bold(int status) {
        static const char *seq[] = {"\x1b[0m", "\x1b[1m"};
        printf("%s", seq[!!status]);
}


void main(){


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
                printf("| 4 - INSCRIÇÃO DE DISCIPLINA                                                             |\n");
                printf("| 5 - SAIR                                                                                |\n");
                printf("|                                                                                         |\n");    
                printf("| Digite uma das opção para prosseguir.                                                   |\n");    
                printf("|_________________________________________________________________________________________|\n");


                scanf("%d", &menu);
                
                while ( (menu > 5) || (menu < 1) ){
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
                            printf("| 1 - CADASTRO ALUNO                                                                      |\n");
                                        bold(0);
                                        printf("|   2 - INCLUIR                                                                           |\n");
                                        printf("|   3 - LEITURA                                                                           |\n");
                                        printf("|   4 - ALTERAR                                                                           |\n");
                                        printf("|   5 - DELETAR                                                                           |\n");
                                        printf("| 6 - VOLTAR                                                                                  |\n");
                                        printf("|                                                                                         |\n"); 
                                        printf("| Digite uma das operações para prosseguir.                                               |\n");    
                                        printf("|_________________________________________________________________________________________|\n");
                                        
                                        scanf("%d", &menu);
                                        
                                        while ( (menu > 6) || (menu < 2) ){
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
                                        printf("| 1 - CADASTRO TIPO DE CURSO                                                              |\n");
                                        bold(0);
                                        printf("|   2 - INCLUIR                                                                           |\n");
                                        printf("|   3 - LEITURA                                                                           |\n");
                                        printf("|   4 - ALTERAR                                                                           |\n");
                                        printf("|   5 - DELETAR                                                                           |\n");
                                        printf("| 6 - VOLTAR                                                                                  |\n");
                                        printf("|                                                                                         |\n"); 
                                        printf("| Digite uma das operações para prosseguir.                                               |\n");    
                                        printf("|_________________________________________________________________________________________|\n");
                                        
                                        scanf("%d", &menu);
                                        
                                        while ( (menu > 6) || (menu < 2) ){
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
                                        printf("| 1 - CADASTRO DISCIPLINA                                                                 |\n");
                                        bold(0);
                                        printf("|   2 - INCLUIR                                                                           |\n");
                                        printf("|   3 - LEITURA                                                                           |\n");
                                        printf("|   4 - ALTERAR                                                                           |\n");
                                        printf("|   5 - DELETAR                                                                           |\n");
                                        printf("| 6 - VOLTAR                                                                                  |\n");
                                        printf("|                                                                                         |\n"); 
                                        printf("| Digite uma das operações para prosseguir.                                               |\n");    
                                        printf("|_________________________________________________________________________________________|\n");
                                        
                                        scanf("%d", &menu);
                                        
                                        while ( (menu > 6) || (menu < 2) ){
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
                                        printf("| 1 - INSCRIÇÃO DE DISCIPLINA                                                             |\n");
                                        bold(0);
                                        printf("|   2 - INCLUIR                                                                           |\n");
                                        printf("|   3 - LEITURA                                                                           |\n");
                                        printf("|   4 - ALTERAR                                                                           |\n");
                                        printf("|   5 - DELETAR                                                                           |\n");
                                        printf("| 6 - VOLTAR                                                                                  |\n");
                                        printf("|                                                                                         |\n"); 
                                        printf("| Digite uma das operações para prosseguir.                                               |\n");    
                                        printf("|_________________________________________________________________________________________|\n");
                                        
                                        scanf("%d", &menu);
                                        
                                        while ( (menu > 6) || (menu < 2) ){
                                                printf("Digite um menu válido.\n");
                                                scanf("%d", &menu);
                                        }
                                        
                                        system("clear");
                                        break;
                                                
                                case 5: printf("Você saiu do sistema");
                                                system("clear");
                                                break;
                }
                
        }while(menu == 6);


}