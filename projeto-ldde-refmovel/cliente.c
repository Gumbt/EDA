#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "cliente.h"

#define FRACASSO 0
#define SUCESSO 1

int main()
{
    LDDE *ptr = NULL;
	FILE *arq;	
    if( cria(&ptr, sizeof(info)) == SUCESSO ) {
    	carregaLista(ptr);
		menu(ptr,arq);
        destroi(&ptr);

        return 0;
    }

    printf("Erro de memoria ao alocar a lista\n");

    return 1;
}

void menu(LDDE *p,FILE *arq)
{	
    unsigned int opc, pos;
    info *reg, x;
	int contp=0,linha=0,contnewline=0,j,comecouPalavra = 0;
	char plvra[30];
	char *caracter; 
    reg = &x;

    do {
        system("cls");
		exibeLista(p, reg);	   
        printf("\n MENU:");
        puts("\n 1 Insere no inicio \n 2 Insere no final \n 3 Insere na posicao");
        puts("\n 4 Busca no inicio \n 5 Busca no final \n 6 Busca na posicao");
        puts("\n 7 Remove do inicio \n 8 Remove do final \n 9 Remove da posicao");
        puts("\n 10 reinicia a lista  \n 11 tamanho \n 12 Exibir total de palavras\n 10 Salvar em txt\n 0 sair");
        printf("\n :>");
        scanf("%ui", &opc);

        flush(stdin);
        switch (opc) {
            case 1:      	
                printf("\ninforme numero da coluna e palavra: ");
                scanf("%i %s",&reg->loca, reg->palavra);

                if( insereNoInicio(p,reg) == FRACASSO )
                    puts("erro na insercao");
                else
                    puts("sucesso na insercao");

                break;
            case 2:
                printf("\ninforme numero da coluna e palavra: ");
                scanf("%i %s", &reg->loca, reg->palavra);
                if( insereNoFim(p, reg) == FRACASSO )
                    puts("erro na insercao");
                else
                    puts("sucesso na insercao");
                break;
            case 3:
                printf("informe a posicao para insercao: ");
                scanf("%i", &pos);
                printf("\ninforme numero da coluna e palavra: ");
                flush(stdin);
                scanf("%i %s", &reg->loca, reg->palavra);

                if( insereNaPosLog(p, reg, pos) == FRACASSO )
                    puts("erro na insercao:pos invalida ou lista vazia");
                else
                    puts("sucesso na insercao");
                break;
            case 4:
                if( buscaNoInicio(p,reg) == FRACASSO )
                    puts("lista vazia");
                else
                    printf("\n buscou:: palavra: %s numero da coluna = %i", reg->palavra, reg->loca);
                break;
            case 5:
                if( buscaNoFim(p,reg) == FRACASSO )
                    puts("lista vazia");
                else
                    printf("\n buscou:: palavra: %s numero da coluna = %i", reg->palavra, reg->loca);
                break;
            case 6:
                printf("informe a posicao para a busca: ");
                scanf("%i", &pos);
                if( buscaNaPosLog(p, reg, pos) == FRACASSO )
                    puts("erro na busca: pos invalida ou lista vazia");
                else
                    printf("\n buscou:: palavra: %s numero da coluna = %i", reg->palavra, reg->loca);
                break;
            case 7:
                if( removeDoInicio(p, reg) == FRACASSO )
                    puts("lista vazia");
                else
                    printf("removido: :: palavra: %s numero da coluna = %i", reg->palavra, reg->loca);
                break;
            case 8:
                if( removeDoFim(p, reg) == FRACASSO )
                    puts("lista vazia");
                else
                    printf("removido:: palavra: %s numero da coluna = %i", reg->palavra, reg->loca);
                break;
            case 9:
                printf("informe a posicao da remocao: ");
                scanf("%i", &pos);
                if( removeDaPosLog(p, reg, pos) == FRACASSO)
                    puts("erro na remocao: pos invalida ou lista vazia");
                else
                    printf("removido::: palavra: %s loca = %i", reg->palavra, reg->loca);
                break;
            case 10:
                reinicia(p);
                printf("lista reiniciada");
                break;
            case 11:
                printf("tamanho: %i", tamanho(p));
                break;
			case 12:
				contp=0;
				arq = fopen("saida.txt", "r");
            	while (!feof(arq)) {
					fread(caracter, 1, 1, arq);
					if  ((*caracter!=' ') && (*caracter!='\n') && (!comecouPalavra)) {
						comecouPalavra = 1;
						}
					if  (((*caracter==' ') || (*caracter == '\n')) && (comecouPalavra)) {
						comecouPalavra = 0;
						contp++;
					}
   
   				}           
  				 printf("\n O n�mero de palavras do arquivo �: %d", contp);
                contp=0;
                break;
                case 13: //exibir quantidade de repetiçoes de uma palavra
                printf("Digite a palavra que busca: ");
                scanf("%s", &plvra);
                for(int i=1;i<=tamanho(p);i++){
                    buscaNaPosLog(p,reg,i);
                    if(strcmp(reg->palavra,plvra)==0){
                        contp++;
                    }
                }
                printf("Quantidade de repeticoes da palavra %s: %i",plvra,contp);
                contp=0;
                break;
            case 14: //exibir na posição(linha/coluna)
                printf("Digite a posicaoo(linha/coluna)");

                break;
            case 15: //inserçao na posicao(linha/coluna)
                break;
            case 16: //remoçao na posição(linha/coluna)
                break;
            case 17:// exibir na forma de texto tudo

                break;
            case 18: //substituir palavra na posicao (linha/coluna)
                break;
            case 19: //substituir todas as ocorrencias da palavra
                break;

            case 20: //salvar nova versão no arquivo
            
	            arq = fopen("saida.txt", "a");	            
	            for(j=1; j<=tamanho(p); j++){
	            		buscaNaPosLog(p,reg,j);
            			if(strcmp(reg->palavra, "newline")){
            				fprintf(arq,"%s ",reg->palavra);
            			} else {
            				fprintf(arq,"\n");
            			}
            	}
            	printf("Dados salvos no arquivo\n");
            	fclose(arq);

                break;
            case 0:
                puts("fim");
                break;
                default:
                puts("informe uma opcao correta");
                break;
                
        }
        flush(stdin);
        //getchar();
    } while(opc != 0);
}


void flush(FILE *in)
{
    int c;

    do {
        c = fgetc(in);
    } while(c!='\n' && c != EOF);
}
void exibeLista(LDDE *ptr, info *reg)
{ 	
    int i=1;

    printf("\nLista:\n");
    while( buscaNaPosLog(ptr, reg, i) == SUCESSO ) {
        printf("%i) %s, numedo da coluna: %i \n", i, reg->palavra, reg->loca); 
        i++;
    }
}
void carregaLista(LDDE *ptr)
{	info vet[] = { {300,"Pedro"}, {200,"Paulo"}, {100,"Judas"}, {400,"Manuel"},
    {250,"Lucas"}, {270,"Andre"}, {390,"Thiago"}, {-1,"\0"} };
    int i=0;	

    system("cls");
    do { // carregando a lista
        if( insereNoFim(ptr, &vet[i]) == SUCESSO ) {
            i++;
        }
        else { 	
            puts(">>> Fracasso na craga da lista");	
            exit(0);	
        }
    } while( vet[i].loca > 0 );

    puts("Carga realizada com sucesso");	
    puts("tecle para continuar...");	 
    getchar();
}
