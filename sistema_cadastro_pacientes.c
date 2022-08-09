#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<conio.h>

typedef struct{
	char covid[50], nome[50], cpf[20], comorbidades[500], sexo[10], email[25], rua[20], bairro[15], cidade[15], estado[2];
    int telefone, cep, idade, ano, codi, urg;
    struct Paciente *prox;
}paciente;

typedef struct{
    int qnt;
    struct Paciente *head;
}listas;

typedef struct{
    struct Paciente *No;
    struct Arvore *Esq;
    struct Arvore *Dir;
}arvore;

int pacientes = 0;

void adicionar(arvore **Arv, paciente *tmp);

listas* inicializarLista(){
    listas *tmp = (listas*)malloc(sizeof(listas));
    tmp->qnt = 0;
    tmp->head = NULL;
    return tmp;
}
void cadastrar_paciente(listas *tmp, arvore *Arv){
      int op_cadastro_paciente = 0;
    printf("\t\t**********************************************************\n\n");
    printf("\t\t----------------REGISTRO DE PACIENTE----------------------\n\n");
    printf("\t\t**********************************************************\n\n");
	do{

        system("cls");
        paciente *aux = (paciente *)malloc(sizeof(paciente));
        printf("\tInforme os dados do paciente\n");
        printf("\tNome: ");
        fflush(stdin);
        gets(aux->nome);
        fflush(stdin);
        char* fgets(char *string, int length, FILE * stream);

        //printf("\n\tInforme o CPF do paciente\n");
        printf("\tCPF: ");
        scanf("%s", aux->cpf);

        //printf("\n\tInforme o telefone do paciente:\n");
        printf("\tTelefone: ");
        scanf("%d", &aux->telefone);

        printf("\n\tPreencha a seguir, o endereço do paciente.\n");
        printf("\tRua:");
        fflush(stdin);
        gets(aux->rua);
        fflush(stdin);

        //printf("\n\tInforme o bairro:\n");
        printf("\tBairro:");
        fflush(stdin);
        gets(aux->bairro);
        fflush(stdin);

        //printf("\n\tInforme a Cidade:\n");
        printf("\tCidade:");
        fflush(stdin);
        gets(aux->cidade);
        fflush(stdin);

        //printf("\n\tInforme seu estado:\n");
        printf("\tEstado:");
        fflush(stdin);
        gets(aux->estado);
        fflush(stdin);

        //printf("\n\tInforme o Cep:\n");
        printf("\tCep:");
        scanf("%d", &aux->cep);
        fflush(stdin);

        printf("\n\tData do diagnóstico:\n");
        printf("\tData: ");
        scanf("%s", &aux->covid);
        fflush(stdin);

        printf("\n\tInforme a data de nascimento do paciente\n");
        printf("\tAno: ");
        scanf("%d", &aux->ano);
        fflush(stdin);
        aux->idade= 2021-aux->ano ;
        printf("\tIdade: %d",aux->idade);
        printf("\n");

        printf("\n\tInforme o sexo do paciente\n");
        printf("\tSexo [M]-[F]: ");
        fflush(stdin);
        scanf("%s", aux->sexo);
        fflush(stdin);

        printf("\n\tInforme o Email do paciente\n");
        printf("\tEmail: ");
        scanf("%s", aux->email);
        fflush(stdin);
        printf("\n ");

        printf("\tInforme a Comorbidades: ");
        printf("\n\t Se houver comorbidades, digite 1 se não houver comorbidades, digite 2: ");
    	int op_como;

        scanf("%d",&op_como);

        switch(op_como){
            case 1:
    			printf("\n\tDigite a comorbidade: ");
		        fflush(stdin);
		        scanf("%s", aux->comorbidades);
		        char* fgets(char *string, int length, FILE * stream);
        		break;
            case 2:
        		printf("\n\tSem Comorbidade\n");
                break;
            default:
                printf("\n\n\n\n");
                printf("Opcao invalida\n");
                break;
                //printf("\n\n\n\n");
        }
        fflush(stdin);

        printf("\n\tInforme a urgência do paciente:\n\tDigite '1' para paciente do grupo de risco ou digite '2' para paciente fora do grupo de risco.\n");
        printf("\tUrgencia: ");
        scanf("%d", &aux->urg);
        printf("\n");

        printf("\n\tDigite um código para identificação do paciente\n");
        printf("\tCódigo: ");
        scanf("%d", &aux->codi);
        printf("\n\n");

        FILE *paci;
        paci = fopen("Dados_Pacientes.txt", "a+");
        fprintf(paci,"Código do paciente: %d \n Data do Diagnóstico: %s \n Nome: %s \n CPF: %s \n Sexo: %s \n Idade: %d \n Telefone: %d \n Código: %d \n Rua: %s \n Bairro: %s \n Cidade: %s\n Estado: %s \n Cep: %d \n\n",aux->codi,aux->covid, aux->nome, aux->cpf, aux->sexo, aux->idade, aux->telefone, aux->codi, aux->rua, aux->bairro, aux->cidade,aux->estado, aux->cep);
        fprintf(paci,"----------------------------------------------------------------\n");
		  fclose(paci);

          FILE *sint;
          sint = fopen("pacientes_grupo_de_risco.txt", "a+");
          fprintf(sint,"Data do Diagnóstico: %s \nNome: %s\nIdade: %d\nComorbidades: %s\nEmail: %s\n",aux->covid, aux->nome, aux->idade, aux->comorbidades, aux->email);
          fprintf(sint,"----------------------------------------------------------------\n");
        fclose(sint);

        adicionar(&Arv, aux);

        aux->prox = tmp->head;
        tmp->head = aux;
        tmp->qnt++;

        printf("1- Novo cadastro\n\n2- Voltar ao Menu\n");
        printf("Opção: ");
        scanf("%d", &op_cadastro_paciente);
    }while(op_cadastro_paciente != 2);
}
void listar_pacientes(listas *tmp){
    int op = 0;
    printf("\t----------------------PACIENTES----------------------\n");

    paciente *aux;
    printf("\n\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    for(aux = tmp->head; aux != NULL; aux = aux->prox){
        printf("Nome: %s\nCPF: %s\nSexo: %s\nIdade: %d\nTelefone: %d\nComorbidades: %s \nCódigo: %d \nRua: %s\nBairro: %s\nCidade: %s\nEstado: %s\nCep: %d\n",
               aux->nome, aux->cpf, aux->sexo, aux->idade, aux->telefone, aux->comorbidades, aux->codi, aux->rua, aux->bairro, aux->cidade, aux->estado, aux->cep);

		printf("---------------------------------------------------------------------------------------------------------\n\n\n");
    }

    printf("---------------------------------------------------------------------------------------------------------\n\n\n");
    printf("\t\t\tExistem %d pacientes cadastrados\n", tmp->qnt);
    free(aux);
    printf("\n\n");

    printf("1- Voltar ao menu\n\n2- Encerrar o programa ");
    scanf("%d", &op);
    if(op == 2){
        exit(0);
    }
}
void listar_urgencia(listas *tmp){
    int op = 0;
    printf("\t----------------------PACIENTES----------------------\n");

    paciente *aux;
    printf("\n\n");
    printf("---------------------------------------------------------------------------------------------------------\n");

    for(aux = tmp->head; aux != NULL; aux = aux->prox){
    	if ((aux->urg ==2)) {
			printf("---------------Sem-Urgencias-!!!-----------------------------\n");
		} else {
        	printf("Data do Diagnóstico: %s\n Nome: %s\nCPF: %s\nSexo: %s\nIdade: %d\nTelefone: %d\nComorbidades: %s \nCódigo: %d \nRua: %s\nBairro: %s\nCidade: %s\nEstado: %s\nCep: %d\n\n",
                aux->covid, aux->nome, aux->cpf, aux->sexo, aux->idade, aux->telefone, aux->comorbidades, aux->codi, aux->rua, aux->bairro, aux->cidade, aux->estado, aux->cep);
		}
    }

    printf("---------------------------------------------------------------------------------------------------------\n\n\n");
    printf("\t\t\tExistem %d pacientes cadastrados\n", tmp->qnt);
    free(aux);
    printf("\n\n");
    printf("1- Voltar ao menu\n\n2- Encerrar o programa ");
    scanf("%d", &op);
    if(op == 2){
        exit(0);
    }
}

void adicionar(arvore **Arv, paciente *pac){
    arvore *temp = NULL;

    if (*Arv == NULL){
        temp = (arvore*)malloc(sizeof(arvore));
        temp->Esq = NULL;
        temp->Dir = NULL;
        temp->No = pac;
        *Arv = temp;
    }
    else {
        if (pac->urg < ((*Arv)->No->urg)){
            adicionar(&((*Arv)->Esq), pac);
        }
        else{
            adicionar(&((*Arv)->Dir), pac);
        }
    }
}

void Mostrar(arvore *Arv){
    if(Arv != NULL){
        Mostrar(Arv->Esq);
        printf("Nome: %s\nCPF: %s\nSexo: %s\nIdade: %d\nTelefone: %d\nComorbidades: %s\nUrgencia: %d\nC?digo: %d\n",
        Arv->No->nome, Arv->No->cpf, Arv->No->sexo, Arv->No->idade, Arv->No->telefone, Arv->No->comorbidades, Arv->No->urg, Arv->No->codi);
        Mostrar(Arv->Dir);
    }
}

/*void alterar_paciente(listas* lista_escolhida){
     char nome_substituto[50];
     char cpf_substituto[50];
     char rua_s[50];
     char bairro_s[50];
     char cidade_s[50];
     char estado_s[50];
     char sexo_s[20];
     char comorbidades_s[500];
	 char email_s[25];

     int codigo, idade_substituto,ano_s, telefone_substituto;
     paciente* atual = lista_escolhida->head;
     system("cls");

     printf("\tCódigo do paciente a ser alterado: ");
     scanf("%d", &codigo);

     while(atual != NULL && atual->codi != codigo){
        atual = atual->prox;
     }

     if(atual!=NULL){
        printf("\n\tNovo nome: ");
        fflush(stdin);
        gets(nome_substituto);
        strcpy(atual->nome,nome_substituto);

        printf("\n\tNova data de nascimento: ");
        scanf("%d", &ano_s);
        fflush(stdin);
        atual->idade= 2021-ano_s ;
        printf("\tIdade: %d",atual->idade);
        printf("\n");

        printf("\n\tNovo CPF: ");
        scanf("%s", cpf_substituto);
        strcpy(atual->cpf,cpf_substituto);

        printf("\n\tNovo telefone: ");
        scanf("%d", &telefone_substituto);
        atual->telefone = telefone_substituto;

        fflush(stdin);
        printf("\n\tInforme a Rua:");
        fflush(stdin);
        gets(rua_s);
        strcpy(atual->rua,rua_s);

        fflush(stdin);
        printf("\n\tInforme o Bairro:");
        fflush(stdin);
        gets(bairro_s);
        strcpy(atual->bairro,bairro_s);

        fflush(stdin);
        printf("\n\tInforme a cidade:");
        fflush(stdin);
        gets(cidade_s);
        strcpy(atual->cidade,cidade_s);

        fflush(stdin);
        printf("\n\tInforme o Estado:");
        fflush(stdin);
        gets(estado_s);
        strcpy(atual->estado,estado_s);

        fflush(stdin);
        printf("\n\tInforme o sexo [m]ou[f]:");
        fflush(stdin);
        scanf("%c",&sexo_s);
        strcpy(atual->sexo,sexo_s);

        fflush(stdin);
        printf("\n\tInforme o Email:");
        fflush(stdin);
        scanf("%s",&email_s);
        strcpy(atual->email,email_s);

        printf("\n\tDados modificados com exito.\n\tVoltando ao menu...");

     }else{
        printf("\n\tNão foi positivável encontra o paciente solicitado \n\tVoltando ao menu...");
     }
}
*/
listas* excluir_paciente(listas* lista_escolhida){

    paciente *anterior = NULL;
    paciente *atual = lista_escolhida->head;
    int codigo;
    system("cls");
    printf("\n\nC?digo do paciente a ser exclu?do: ");
    scanf("%d", &codigo);
    while(atual != NULL && atual->codi != codigo){
       anterior = atual;
       atual = atual->prox;
    }
    if(atual == NULL){
       printf("\n  Paciente não encontrado.");
       return lista_escolhida;
    }
    if(anterior == NULL){
       printf("\n  Paciente excluído com sucesso.");
       lista_escolhida->head = atual->prox;
       return lista_escolhida;
    }else{
       printf("\n  Paciente excluído com sucesso.");
       anterior->prox = atual->prox;
       return lista_escolhida;
    }
    lista_escolhida->qnt--;
    free(atual);
    return lista_escolhida;
}
void entrando(){
    int carregando;
    for(carregando=0;carregando<=3;carregando++){
        printf("\n\n\n\t\t\tCarregando.");
        system("cls");
        printf("\n\n\n\t\t\tCarregando..");
        system("cls");
        printf("\n\n\n\t\t\tCarregando....");
        system("cls");
    }
}

void menu(){

    int op_menu;
    listas *lista_paciente = inicializarLista();
    arvore *Arv = NULL;

    do{
    	printf("\t\t****************************************************************\n\n");
        printf("\t\t*             #REGISTRO DE PACIENTES DA COVID19#                 *\n\n");
        printf("\t\t****************************************************************\n\n");
        printf("\n\n");
        printf("\tCadastrar Pacientes Da COVID(19)\n");
        printf("\t[1] - Incluir paciente\n");
        //printf("\t[2] - Alterar dados do paciente\n");
        printf("\t[2] - Ordem de Cadastro do Paciente\n");
        printf("\t[3] - Por urgencia de Paciente\n");
        printf("\t[4] - Excluir cadastro de paciente\n");
        printf("\t[5] - Encerrar programa\n");
        printf("\n\tOpcao: ");
        scanf("%d", &op_menu);
        switch(op_menu){
            case 1:
                system("cls");
                cadastrar_paciente(lista_paciente, Arv);
                break;
            /*case 2:
                system("cls");
                alterar_paciente(lista_paciente);
                break;*/
            case 2:
                system("cls");
                listar_pacientes(lista_paciente);
                break;
            case 3:
                system("cls");
                printf("-- Pacientes por ordem de urgencia --");
                listar_urgencia(lista_paciente);
                system("pause>null");
                break;
            case 4:
                system("cls");
                printf("\tQual paciente deseja excluir?\n");
                lista_paciente = excluir_paciente(lista_paciente);
                break;
            case 5:
                exit(5);
                break;
            default:
                printf("\n\n\n\n");
                printf("Opcao invalida\n");
                printf("\n\n\n\n");
        }
        system("cls");
    }while(op_menu != 0);
}

int main(){

     while(1)
    {
        char string[5];
        char enter[2];

        printf ("\n Digite a senha : ");
        string[0] = getch();
        printf ("*");
        string[1] = getch();
        printf ("*");
        string[2] = getch();
        printf ("*");
        string[3] = getch();
        printf ("*");

        enter[0] = getch();
        if(enter[0] == 13)
        {
            if((string[0] == 'U') && (string[1] == 'n') && (string[2] == 'i') && (string[3] == 'p'))
            {
                system("color F1");
                system("cls");
                printf ("\n\n\t\tAcesso permitido!\n\n\t\tParabens!\n\t\tTecle Enter para Acessar o Sistema!\n\n\n\n\n\n\n");
                getchar();
                system("cls");
            }
            else
            {
                system("color F1");
                system("cls");
                printf ("\n\n\t\tAcesso negado!\n\n\t\tVoce nao tem permissao para acesso! Tecle Enter Para Tentar Novamente!\n\n\n\n\n\n\n\n\n\n\n");
                system("pause>null");
                system("cls");

                return main();
            }

    system("color F1");
    setlocale(LC_ALL,"Portuguese");
    entrando();
    menu();
    system("pause>null");
}}}
