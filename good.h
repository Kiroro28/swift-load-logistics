#ifndef GOODS_H
#define GOODS_H

#include <string>
#include <stdexcept>

class Goods {
private:
    std::string name;
    std::string type;
    double weight;

public:
    Goods(std::string n, std::string t, double w) : name(n), type(t) {
        setWeight(w);
    }

    void setWeight(double w) {
        if (w > 0) {
            weight = w;
        } else {
            throw std::invalid_argument("Cargo weight must be positive.");
        }
    }

    double getWeight() const { return weight; }
    std::string getName() const { return name; }
    std::string getType() const { return type; }
};

#endif
