#include <iostream>
#include <string>
#include <vector>

class OrdemDeCompra{
    private:
    std::string name;
    int quantidade;
    double precoUnitario;

    public:
    OrdemDeCompra(std::string n ,int q ,double p){
        name = n;
        quantidade = q;
        precoUnitario = p;
    }

    double getValorTotal(){
        double total = quantidade * precoUnitario;
        return total;
    }

    void novoPreco(double novoPreco){
        if (novoPreco > 0 ){
            precoUnitario = novoPreco;
        }
    }

    void imprimirResumo(){
        std::cout << name << ":"<< quantidade << " acoes a "<< precoUnitario;

    }
};

int main(){
    OrdemDeCompra minhaOrdem("PETR4",100,30.4);
    minhaOrdem.imprimirResumo();
}

