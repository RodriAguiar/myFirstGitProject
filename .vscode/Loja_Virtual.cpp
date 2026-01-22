#include <iostream>

using namespace std;



class Produto {
protected:
    string nome;
    double preco;

public:
    Produto(string n, double p) : nome(n) {
        setPreco(p);
    }

    void setPreco(double valor) {
        if (valor < 0) {
            this->preco = 0;
            cout << "Aviso: Preço negativo para '" << nome << "' definido como 0." << endl;
        } else {
            this->preco = valor;
        }
    }

    virtual void exibirDetalhes() {
        cout << "Produto: " << nome << " | Preço: " << preco << "€";
    }
};

class Livro : public Produto {
private:
    string autor;

public:
    Livro(string n, double p, string a) : Produto(n, p), autor(a) {}

    void exibirDetalhes() override {
        Produto::exibirDetalhes(); 
        cout << " | Autor: " << autor << endl;
    }
};

class Smartphone : public Produto {
private:
    string marca;

public:
    Smartphone(string n, double p, string m) : Produto(n, p), marca(m) {}

    void exibirDetalhes() override {
        Produto::exibirDetalhes();
        cout << " | Marca: " << marca << endl;
    }
};

int main() {

    Livro livro1("O Pé Grandinho ", 25.50, "Joaquim das Couves");
    Smartphone celular1("iPhone 15", -1000, "Apple"); // Teste de preço negativo

    livro1.setPreco(-50);

    cout << "\n--- Lista Produtos ---\n";
  
    livro1.exibirDetalhes();
    celular1.exibirDetalhes();

    return 0;
}
