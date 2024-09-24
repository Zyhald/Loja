#include <iostream>
using namespace std;

struct Produto {

   string nome;
   float preco;
   int quantidade;

};

void adicionarProduto(Produto produtos[], int& quantidadeAtual){

    cout << "Qual o nome do produto?" << endl;
    cin >> produtos[quantidadeAtual].nome;
    cout << "Qual o preco do produto?" << endl;
    cin >> produtos[quantidadeAtual].preco;
    cout << "Quanto produto há?" << endl;
    cin >> produtos[quantidadeAtual].quantidade;
    quantidadeAtual++;

}

void exibirProdutos(const Produto produtos[], int quantidadeAtual){
    for (int i = 0; i < quantidadeAtual; i++) {
        cout << "Produto " << i + 1 << ": " << endl;
        cout << "Nome: " << produtos[i].nome << endl;
        cout << "Preco: " << produtos[i].preco << endl;
        cout << "Quantidade: " << produtos[i].quantidade << endl;
        cout << "-------------------------" << endl;
    }

}

float calcularValorTotal(const Produto produtos[], int quantidadeAtual){
    float ValorTotal = 0;
    for(int i = 0; i < quantidadeAtual; i++)
    {
        ValorTotal += produtos[i].preco * produtos[i].quantidade; 
    }
    return ValorTotal;
}


int main(){
    const int maximoProdutos = 100;
    Produto produtos[maximoProdutos];
    int quantidadeAtual = 0;
    int opcao;

    do {
        
        cout << "---------------------------------" << endl;
        cout << "           Bem vindo!" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Adicionar Produto" << endl;
        cout << "2. Exibir Produtos" << endl;
        cout << "3. Calcular Valor Total do Stock" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao valida: " << endl;
        cin >> opcao;


        switch(opcao)
        {
            case 1: 
                if (quantidadeAtual < maximoProdutos) {
                    adicionarProduto(produtos, quantidadeAtual);
                } else {
                    cout << "Limite de produtos atingido!" << endl;
                }
                break;
        
            case 2: 
                exibirProdutos(produtos, quantidadeAtual);
                break;
        
            case 3:
                cout << "Valor total do stock: " << calcularValorTotal(produtos, quantidadeAtual) << endl;
                break;
        
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }
    } while (opcao != 0);

    return 0;

}
