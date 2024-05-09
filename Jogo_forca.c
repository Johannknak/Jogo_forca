#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i, acertou, j=1, venceu=0, enforcou=0, erros=0, num_acertos=0;
    char chute, palavrasecreta[20];
    char *possiveispalavras[]={"LINDO", "CAPITAO", "JOHANN", "SERIO", "AXIOMA", "AZULEJO","CATARRO","CRESPO","INDIGNO","INTRIGANTE","MARFIM","ORQUIDEA","VAPORIZAR", "XILOFONE","ALBATROZ","ALPACA","BACALHAU","DROMEDARIO","ESCARAVELHO","GRALHA","ORNITORRINCO","PELICANO","GUAXINIM","TEXUGO","ADVOGADO","DOUTOR","QUIROPRATA","PIZZAIOLO","ENGENHEIRO","AMPULHETA","CANDELABRO","DESFIBRILADOR","FANTOCHE","NAVALHA","ZIPER","BERGAMOTA","GROSELHA","KIWI","ALGARISMO","ALQUIMICA","ASTERISCO","ATLAS","BENEFICENTE","BUROCRACIA","BUMERANGUE","BERIMBAU","CACTO","CAMUFLAGEM","CICATRIZ","CEREBRO","CONSCIENTE","COMPANHIA","CLEPTOMANIACO","DESTRUIDO","EMPECILHO","ENXERIDO","ESFIRRA","ESCOMBRO","ESPINAFRE","EXCENTRICO","EXCEPCIONAL","GLORIOSO","GRAMPEADOR","INTERRUPTOR","LANTEJOULA","MAGNETICO","RADIOATIVO","MADRASTA","MARGARINA","MANTEIGA","MICROFONE","LOSANGO","MILIONARIO","PEDAGIO","PERNOITE","PRODIGIO","QUINTUPLO","RECICLAR","REIVINDICAR","RITMO","IMPROVISAR","PSICANALISE","PSICOLOGIA","SENSATEZ","SOBREVIVENTE","UNIVERSIDADE","VENTILADOR"};
    int num_palavras = 87;
    srand(time(0));
    int x = rand() % num_palavras;
    strcpy(palavrasecreta, possiveispalavras[x]);
    int letras = strlen(palavrasecreta);
    char mostruario[2*letras+1];
    for(int l=0;l<letras;l++){
        mostruario[l*2]='_';
        mostruario[1+2*l]=' ';
    }
    mostruario[2*letras]='\0';
    printf("Bem vindo ao jogo da forca! Digite enter para comecar");
    getchar();
    printf("Digite apenas letras maiusculas!\n\n"
           "                             +---+                         \n"
           "                             |   |                         \n"
           "                                 |                         \n"
           "                                 |                         \n"
           "                                 |                         \n"
           "                                 |                         \n"
           "                          ===========                      \n"
           "%s\n\n", mostruario);
    do
    {
        acertou = 0;
        printf("Tentativa numero %d: ", j);
        scanf(" %c", &chute);
        for(i=0; i<strlen(palavrasecreta); i++)
        {
            if(chute==palavrasecreta[i])
            {
                printf("Parabens! A letra %c esta na posicao %d\n", chute, i+1);
                acertou = 1;
                num_acertos++;
                //Função para remover a letra (chute) na posição (i)
                palavrasecreta[i]=' ';
                mostruario[i*2]=chute;
            }
        }
        if(acertou==0)
        {
            printf("Errou!\n");
            erros++;
        }
        j++;
        printf(
                "                             +---+                         \n"
                "                             |   |                         \n"
                "                             %c   |                        \n"
                "                            %c%c%c  |                      \n"
                "                            %c %c  |                       \n"
                "                                 |                         \n"
                "                          ===========                      \n"
                "%s\n\n",(erros >= 1 ? '0' : ' '), (erros >= 3 ? '/' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 4 ? '\\' : ' '), (erros >= 5 ? '/' : ' '), (erros >= 6 ? '\\' : ' '), mostruario);
        if(erros == 6)
        {
            enforcou = 1;
            printf("\n\nVOCE MORREU!\n\nPALAVRA SECRETA ERA: %s\n", possiveispalavras[x]);
        }
        if(num_acertos == strlen(palavrasecreta))
        {
            venceu = 1;
            printf("\n\nMUITO BEM, VOCE NAO FOI ENFORCADO!!\n\n");
        }
    }
    while(!venceu && !enforcou);
    return 0;
}


