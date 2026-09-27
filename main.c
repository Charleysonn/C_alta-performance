#include<stdio.h>

// 'static inline' avisa o GCC para colar o código direto no main, peso ZERO.
static inline void print_idade(unsigned char idade) {
    if (idade >= 100) {
        unsigned char centenas = 0;
        while (idade >= 100) { idade -= 100; centenas++; }
        putchar(centenas + '0');
        
        unsigned char dezenas = 0;
        while (idade >= 10) { idade -= 10; dezenas++; }
        putchar(dezenas + '0');
    } else if (idade >= 10) {
        unsigned char dezenas = 0;
        while (idade >= 10) { idade -= 10; dezenas++; }
        putchar(dezenas + '0');
    }
    putchar(idade + '0');
    putchar('\n');
}

int main(){
    char nome[30],idade;
    fputs("Seja bem vindo!",stdout);
    putchar('\n');
    fputs("Qual o seu nome? ",stdout);
    fgets(nome,sizeof(nome),stdin);
      for (int i = 0; i < 30 && nome[i] != '\0'; i++) {
        if (nome[i] == '\n') {
            nome[i] = '\0';
            break; // Para imediatamente ao encontrar, economizando ciclos de CPU
        }
    }
    fputs("Por gentileza, qual a sua idade? ",stdout);
    scanf("%hhd",&idade);
    fputs("\e[1;1H\e[2J",stdout);
    fputs("Entendi! Você se chama ",stdout);
    fputs(nome,stdout);
    fputs(", e sua idade é ",stdout);
    print_idade(idade); // Executa instantaneamente!
    return 0;
}
