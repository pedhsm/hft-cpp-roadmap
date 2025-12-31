#include <iostream> 
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// estrutura do csv criado
struct MarketData{
    std::string Ticker;
    double Price;
    int Size;
    long long Time;
};

int main(){
    std::vector <MarketData> Data;
    Data.reserve(1000000);

    std::ifstream file ("market_data.csv");

    if (!file.is_open()){
        std::cerr <<"Erro ao abrir o arquivo/Arquivo nao encontrado.\n";
    }

    std::string line;
    // pegamos a primeira linha
    std::getline(file,line);

    // enquanto houver linha manterermos o loop, pega linha -> passa os valores pras variaveis temp -> cria a estrutura -> joga no vetor
    while (std::getline(file,line)){
        std::stringstream ss(line);
        std::string token;
        
        //variaveis temp com a estrutura do struct
        std::string t_ticker;
        double t_price;
        long long t_time;
        int t_size;
        
        std::getline(ss, t_ticker, ',');
        std::getline(ss,token, ',');
        t_price = std::stod(token); // string to double

        std::getline(ss,token, ',');
        t_size = std::stoi(token); //string to integer 

        std::getline(ss,token,',');
        t_time = std::stoll(token); // string to long long 

        Data.emplace_back(MarketData{std::move(t_ticker),t_price,t_size,t_time});
    }

    file.close();
    std::cout << "O arquivo foi lido.Carregados: " << Data.size() << "trades.\n";
}