#include <iostream>
#include <string>

class Medicine {
private:
    std::string name;
    std::string genericName;
    double unitPrice;
    double discountPercent;
    int numberOfItems;
    static double initialPrice;

public:
    Medicine() : name(""), genericName(""), unitPrice(0), discountPercent(5), numberOfItems(0) {}

    Medicine(std::string name, std::string genericName, double unitPrice)
        : name(name), genericName(genericName), unitPrice(unitPrice), discountPercent(5), numberOfItems(0) {
        initialPrice = unitPrice;
    }

    double updatedPrice(int percent) {
        discountPercent = percent;
        return unitPrice * (1 - discountPercent / 100);
    }

    double getSellingPrice(int nos) {
        double sellingPrice = unitPrice - unitPrice * (discountPercent / 100);
        return sellingPrice * nos;
    }

    double readjustedPrice() {
        double remainingPrice = initialPrice - initialPrice * (discountPercent / 100);
        unitPrice = remainingPrice / numberOfItems;
        return unitPrice;
    }

    void resetPrice() {
        unitPrice = initialPrice;
        discountPercent = 5;
    }

    static double getTotalPriceSold(Medicine* medicines, int count) {
        double total = 0;
        for (int i = 0; i < count; i++) {
            total += medicines[i].getSellingPrice(medicines[i].numberOfItems);
        }
        return total;
    }

    ~Medicine() {
        std::cout << "Medicine Name: " << name << std::endl;
        std::cout << "Generic Name: " << genericName << std::endl;
        std::cout << "Unit Price: " << unitPrice << std::endl;
        std::cout << "Discount Percent: " << discountPercent << "%" << std::endl;
        std::cout << "Number of Items: " << numberOfItems << std::endl;
        std::cout << "-------------------------" << std::endl;
    }
};

double Medicine::initialPrice = 0;

int main() {
    Medicine medicine1("Med1", "Generic1", 10.0);
    Medicine medicine2("Med2", "Generic2", 15.0);
    Medicine medicine3("Med3", "Generic3", 20.0);

    medicine1.numberOfItems = 10;
    medicine2.numberOfItems = 7;
    medicine3.numberOfItems = 5;

    double totalPrice = Medicine::getTotalPriceSold(new Medicine[3]{medicine1, medicine2, medicine3}, 3);
    std::cout << "Total Price of Sold Medicines: " << totalPrice << std::endl;

    medicine1.updatedPrice(1);
    medicine2.updatedPrice(2);
    medicine3.updatedPrice(3);

    std::cout << "Unit Price after Applying Discounts:" << std::endl;
    std::cout << "Medicine1: " << medicine1.updatedPrice(1) << std::endl;
    std::cout << "Medicine2: " << medicine2.updatedPrice(2) << std::endl;
    std::cout << "Medicine3: " << medicine3.updatedPrice(3) << std::endl;

    medicine1.readjustedPrice();
    medicine2.readjustedPrice();
    medicine3.readjustedPrice();

    std::cout << "Unit Price after Readjustment:" << std::endl;
    std::cout << "Medicine1: " << medicine1.readjustedPrice() << std::endl;
    std::cout << "Medicine2: " << medicine2.readjustedPrice() << std::endl;
    std::cout << "Medicine3: " << medicine3.readjustedPrice() << std::endl;

    medicine1.resetPrice();
    medicine2.resetPrice();
    medicine3.resetPrice();

    std::cout << "Unit Price after Reset:" << std::endl;
    std::cout << "Medicine1: " << medicine1.updatedPrice(5) << std::endl;
    std::cout << "Medicine2: " << medicine2.updatedPrice(5) << std::endl;
    std::cout << "Medicine3: " << medicine3.updatedPrice(5) << std::endl;

    return 0;
}
