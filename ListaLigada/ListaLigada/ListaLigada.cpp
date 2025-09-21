#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;


// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------

int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista j� possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	ultimo = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (posicaoElemento(novo->valor) != NULL) {
		cout << "Esse elemento ja existe\n";
		free(novo);
		return;
	}

	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo;
	}
	else
	{
		ultimo->prox = novo;
		ultimo = novo;
		
	}
}

void excluirElemento()
{
	
	int excluir;
	NO* atual = primeiro;
	NO* anterior = NULL;

	cout << "Digite o numero que deseja excluir: " << endl;
	cin >> excluir;
	
	NO* pos = posicaoElemento(excluir);


	if(pos == NULL){

		cout << "Numero nao existe na lista!" << endl;
		return;
	}

	if (atual->valor == excluir && anterior == NULL)
	{
		primeiro = primeiro->prox;
		free(atual);
		cout << "Numero excluido com sucesso!" << endl;
	}

	else{

		while(atual->valor != excluir && atual != NULL){

			anterior = atual;
			atual = atual ->prox;
		}
			
		if(atual != NULL){

			anterior->prox = atual->prox;
			free(atual);
			cout << "Numero excluido com sucesso" << endl;
		}

		else if(atual-> valor = ultimo && atual->valor == excluir)
		{
			NO* aux = atual;
			atual->prox = anterior->prox;
			free(aux);
		}
	}

}

NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}

void buscarElemento()
{
	int valor = 0;

	cout << "Digite o valor que quer buscar:" << endl;
	cin >> valor;
	NO* pos = posicaoElemento(valor);

	if (pos != NULL) {
		cout << "O elemento foi encontrado na posicao de memoria: " << pos << endl;
	}
	else
	{
		cout << "O elemento digitado nao foi encontrado" << endl;
	}
	
}


