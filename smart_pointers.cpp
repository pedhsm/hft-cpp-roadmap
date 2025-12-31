#include <iostream>
#include <vector>

struct Order{
    int id;
    double Price;
};
class OrderBook{
    private:
    std::vector<Order> p;

    public:
    explicit OrderBook(size_t capacity_limit){
        p.reserve(1000);

        std::cout<< "[MEMORIA] reservada para"<< capacity_limit << "ordens.\n";
    }

    void add_order(int id, double Price){
    if (p.size() < p.capacity()){
            p.emplace_back(Order{id,Price});
    } 
    else {
        std::cerr << "[ALERTA] Book cheio!";
    }
}
};

int main() {
    std::cout << "--- Inicializando Sistema ---\n";
    OrderBook book(100); 
    
    book.add_order(101, 99.50);
    book.add_order(102, 99.55);
    book.add_order(103, 99.60);

    return 0;
}