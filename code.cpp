// GESTÃO DE CLIENTES
// DEFININDO BIBLIOTECAS 
#include <iostream>
#include <string>
using namespace std;

// DEFINICAO DA ESTRUTURA DO NO
struct Cliente {
    string nome; // variavel que armazena o nome
    string cpf; // variavel que armazena o cpf
    string celular; // variavel que armazena o celular
    Cliente* proximo; // ponteiro que aponta para o proximo elemento da lista
};

// FUNCAO PARA INICIALIZAR A LISTA
Cliente* inicializar() {
    return nullptr;
}

// FUNCAO PARA INSERIR UM NOVO CLIENTE NO FINAL DA LISTA
Cliente* cadastrarCliente(Cliente* lista) {
    // CRIANDO PONTEIRO 
    Cliente* novo = new Cliente;

    // PEDINDO INFORMACOES
    cout << "Digite o nome do cliente: ";
    cin >> novo->nome;
    cout << "Digite o CPF do cliente: ";
    cin >> novo->cpf;
    cout << "Digite o contato de celular do cliente: ";
    cin >> novo->celular;

    novo->proximo = nullptr;

    // DEFININDO CONDICOES
    if (lista == nullptr) {
        return novo;
    } else {
        Cliente* atual = lista;
        while (atual->proximo != nullptr) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
        return lista;
    }
}

// FUNCAO PARA EXCLUIR UM CLIENTE PELO CPF
Cliente* excluirCliente(Cliente* lista, const string& cpf) {
    // CRIANDO PONTEIRO 
    Cliente* anterior = nullptr;
    Cliente* atual = lista;

    // DEFININDO CONDICOES
    while (atual != nullptr && atual->cpf != cpf) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == nullptr) {
        cout << "Cliente com CPF " << cpf << " nao encontrado!\n";
        return lista;
    }
    if (anterior == nullptr) {
        lista = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    delete atual;
    cout << "Cliente excluido com sucesso!\n";
    return lista;
}

// FUNCAO PARA EXIBIR TODOS OS CLIENTES
void exibirClientes(Cliente* lista) {
    // CRIANDO PONTEIRO 
    Cliente* atual = lista;
    
    // DEFININDO CONDICOES
    if (atual == nullptr) {
        cout << "Nenhum cliente cadastrado.\n";
        return;
    }
    while (atual != nullptr) {
        cout << "Nome: " << atual->nome << "\nCPF: " << atual->cpf << "\nCelular: " << atual->celular << "\n\n";
        atual = atual->proximo;
    }
}

// FUNCAO PARA CONSULTAR CLIENTE PELO CPF
void consultarClientePorCPF(Cliente* lista, const string& cpf) {
    // CRIANDO PONTEIRO 
    Cliente* atual = lista;

    // DEFININDO CONDICOES
    while (atual != nullptr) {
        if (atual->cpf == cpf) {
            cout << "Nome: " << atual->nome << "\nCPF: " << atual->cpf << "\nCelular: " << atual->celular << "\n";
            return;
        }
        atual = atual->proximo;
    }
    cout << "Cliente com CPF " << cpf << " nao encontrado.\n";
}

// FUNCAO PARA LIBERAR A MEMORIA DA LISTA
void liberarLista(Cliente* lista) {
    Cliente* atual = lista;
    while (atual != nullptr) {
        Cliente* temp = atual;
        atual = atual->proximo;
        delete temp;
    }
}

// FUNCAO PRINCIPAL
int main() {
    // INICIALIZANDO A LISTA
    Cliente* lista = inicializar();

    // DEFININDO VARIAVEIS
    int opcao;
    string cpf;

    // DEFININDO MENU INTERATIVO 
    do {
        cout << "\n1) Cadastrar cliente\n2) Excluir cliente\n3) Exibir clientes\n4) Consultar clientes pelo CPF\n5) Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        // CHAMANDO AS FUNCOES
        switch (opcao) {
            case 1:
                lista = cadastrarCliente(lista);
                break;
            case 2:
                cout << "Digite o CPF do cliente a ser excluido: ";
                cin >> cpf;
                lista = excluirCliente(lista, cpf);
                break;
            case 3:
                exibirClientes(lista);
                break;
            case 4:
                cout << "Digite o CPF do cliente para consulta: ";
                cin >> cpf;
                consultarClientePorCPF(lista, cpf);
                break;
            case 5:
                cout << "Saindo do programa...\n";
                liberarLista(lista);
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    } while (opcao != 5);

    return 0;
}
