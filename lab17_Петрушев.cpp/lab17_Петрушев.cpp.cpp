// lab17_Петрушев.cpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <Windows.h>

// Базовий клас Component
class Component {
protected:
    std::string brand;
    double price;

public:
    Component(const std::string& brand, double price) : brand(brand), price(price) {}

    std::string getBrand() const { return brand; }
    double getPrice() const { return price; }
};

// Клас Processor наслідується від Component
class Processor : public Component {
private:
    double clockSpeed;
    int cacheSize;

public:
    Processor(const std::string& brand, double clockSpeed, int cacheSize, double price)
        : Component(brand, price), clockSpeed(clockSpeed), cacheSize(cacheSize) {}

    double getClockSpeed() const { return clockSpeed; }
    int getCacheSize() const { return cacheSize; }
};

// Клас Motherboard наслідується від Component
class Motherboard : public Component {
private:
    Processor processor;
    int ramSize;

public:
    Motherboard(const std::string& brand, const Processor& processor, int ramSize, double price)
        : Component(brand, price), processor(processor), ramSize(ramSize) {}

    Processor getProcessor() const { return processor; }
    int getRamSize() const { return ramSize; }
};

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Processor cpu("Intel", 3.5, 8, 250.0);
    Motherboard mb("ASUS", cpu, 16, 150.0);

    std::cout << "Інформація про процесор:" << std::endl;
    std::cout << "Бренд: " << cpu.getBrand() << std::endl;
    std::cout << "Частота: " << cpu.getClockSpeed() << " GHz" << std::endl;
    std::cout << "Розмір кешу: " << cpu.getCacheSize() << " MB" << std::endl;
    std::cout << "Ціна: $" << cpu.getPrice() << std::endl;

    std::cout << "\nІнформація про материнську плату:" << std::endl;
    std::cout << "Бренд: " << mb.getBrand() << std::endl;
    std::cout << "Бренд процесора: " << mb.getProcessor().getBrand() << std::endl;
    std::cout << "Розмір оперативної пам'яті: " << mb.getRamSize() << " GB" << std::endl;
    std::cout << "Ціна: $" << mb.getPrice() << std::endl;

    return 0;
}
