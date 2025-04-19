#include <stdio.h>
#include <string.h>
#define MAXTAM 100
#define MAXSTR 100

typedef struct {
    char nome[MAXSTR], email[MAXSTR];
    int tel;
} contatos;

int quant = 0;
contatos agenda[MAXTAM];

void salvarContatos() {
    int i;
    FILE *arqContatos = fopen("C:/Faculdade/C/PROJETOS/GITHUB/arquivos/agenda.txt", "w");

    if(arqContatos) {
        for (i = 0; i < quant; i++) {
            fprintf(arqContatos, "\nNome: %s", agenda[i].nome);
            fprintf(arqContatos, "\nEmail: %s", agenda[i].email);
            fprintf(arqContatos, "\nTelefone: %d", agenda[i].tel);
        }
        fclose(arqContatos);
    } else {
        printf("ERRO: nao foi possivel abrir o arquivo clientesPF.txt\n\n");
    }
}

int cadastrarContatos() {
    
    if (quant < MAXTAM) {
        printf("\nNome: ");
        fgets(agenda[quant].nome, MAXSTR, stdin);

        printf("\nEmail: ");
        fgets(agenda[quant].email, MAXSTR, stdin);

        printf("\nTelefone: ");
        scanf("%d", &agenda[quant].tel);
        getchar();

        quant++;
        salvarContatos();
        return 1;
    } else {
        printf("\nERRO: vetor cheio!\n\n");
        return 0;
    }
}

void listarContatos() {
    int i;

    for (i = 0; i < quant; i++) {
        printf("\nNome: %s", agenda[i].nome);
        printf("\nEmail: %s", agenda[i].email);
        printf("\nTelefone: %d\n", agenda[i].tel);
    }
}

int editarContatos() {
    int i, editC=0, posicaoReal=0;

    for (i = 0; i < quant; i++) {
        printf("\n[%d] - Nome: %s", i+1 , agenda[i].nome);
        printf("\n[%d] - Email: %s", i+1 , agenda[i].email);
        printf("\n[%d] - Telefone: %d\n", i+1 , agenda[i].tel);
    }

    printf("\nDigite qual contado vai editar pela posicao: ");
    scanf("%d", &editC);
    getchar();
    
    posicaoReal = editC - 1;

    if (posicaoReal >= 0 && posicaoReal < quant) {
        printf("\n--- EDITAR ---\n");
        printf("\nNome: ");
        fgets(agenda[posicaoReal].nome, MAXSTR, stdin);

        printf("\nEmail: ");
        fgets(agenda[posicaoReal].email, MAXSTR, stdin);

        printf("\nTelefone: ");
        scanf("%d", &agenda[posicaoReal].tel);

        printf("\nContato Editado!\n");
        salvarContatos();
    } else {
        printf("\nERRO: contato invalido.");
    }
    
    return 0;
}

int excluirContato() {
    int i, j, excluirC=0, posicaoReal=0;

    for (i = 0; i < quant; i++) {
        printf("\n[%d] - Nome: %s", i+1 , agenda[i].nome);
        printf("\n[%d] - Email: %s", i+1 , agenda[i].email);
        printf("\n[%d] - Telefone: %d\n", i+1 , agenda[i].tel);
    }

    printf("\nDigite qual contado vai excluir pela posicao: ");
    scanf("%d", &excluirC);
    getchar();
    
    posicaoReal = excluirC - 1;

    if(posicaoReal >= 0 && posicaoReal < quant) {
        printf("\n--- APAGAR CONTATO ---\n");
        
        for (j = posicaoReal; j < quant - 1; j++) {
            agenda[j] = agenda[j + 1];
        }
        quant--;

        printf("\nContato Apagado!\n");
        salvarContatos();
    } else {
        printf("\nERRO: contato invalido.");
    }

    return 0;
}

int main() {
    int op;

    do {
        printf("\n--- MENU ----\n");
        printf("\n1 - Cadastrar contato");
        printf("\n2 - Listar contato");
        printf("\n3 - Editar contato");
        printf("\n4 - Excluir contato");
        printf("\n0 - Sair");
        printf("\nEscolha: ");
        scanf("%d", &op);
        getchar();

        switch (op) {
        case 1:
                cadastrarContatos();
            break;
        case 2:
                listarContatos();
            break;
        case 3:
                editarContatos();
            break;
        case 4:
                excluirContato();
            break;
        case 0:
                printf("\nSaindo...");
            break;
        default:
                printf("\nERRO: opcao invalida!");
            break;
        }

    } while (op != 0);
    


    return 0;
}