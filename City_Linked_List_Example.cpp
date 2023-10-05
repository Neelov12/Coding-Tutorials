#include <iostream>
#include <limits>

struct City {
    std::string name;
    int pop;
    double income;
    City* next;

    City(const std::string& cityName, int citypop, double householdIncome)
        : name(cityName), pop(citypop), income(householdIncome), next(nullptr) {}
};

class CityList {
private:
    City* head;
    City* tail;

public:
    CityList() : head(nullptr), tail(nullptr) {}

    void addCityAtTail(const std::string& name, int pop, double income) {
        City* newCity = new City(name, pop, income);

        if (head == nullptr) {
            head = newCity;
            tail = newCity;
        } else {
            tail->next = newCity;
            tail = newCity;
        }
    }

    void addCityAtHead(const std::string& name, int pop, double income) {
        City* newCity = new City(name, pop, income);

        if (head == nullptr) {
            head = newCity;
            tail = newCity;
        } else {
            newCity->next = head;
            head = newCity;
        }
    }

    void displayCityWithLargestpop() {
        if (head == nullptr) {
            std::cout << "No city records" << std::endl;
            return;
        }

        City* largestCity = head;
        City* current = head->next;

        while (current != nullptr) {
            if (current->pop > largestCity->pop) {
                largestCity = current;
            }
            current = current->next;
        }

        std::cout << "City with largest pop:" << std::endl;
        std::cout << "Name: " << largestCity->name << std::endl;
        std::cout << "pop: " << largestCity->pop << std::endl;
        std::cout << "Median Household Income: " << largestCity->income << std::endl;
    }

    void displayAllCityRecords() {
        if (head == nullptr) {
            std::cout << "No city records" << std::endl;
            return;
        }

        City* current = head;

        std::cout << "All city records:" << std::endl;
        while (current != nullptr) {
            std::cout << "Name: " << current->name << std::endl;
            std::cout << "pop: " << current->pop << std::endl;
            std::cout << "Median Household Income: " << current->income << std::endl;
            std::cout << std::endl;
            current = current->next;
        }
    }

    ~CityList() {
        City* current = head;
        while (current != nullptr) {
            City* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    CityList cities;
    int choice;

    do {
        std::cout << "1. Add city record at the tail" << std::endl;
        std::cout << "2. Add city record at the head" << std::endl;
        std::cout << "3. Display the city with largest population" << std::endl;
        std::cout << "4. Display all the city records" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name;
                int population;
                double medianIncome;

                std::cout << "Enter city name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);

                std::cout << "Enter city population: ";
                std::cin >> population;

                std::cout << "Enter median household income: ";
                std::cin >> medianIncome;

                cities.addCityAtTail(name, population, medianIncome);
                break;
            }
            case 2: {
                std::string name;
                int population;
                double medianIncome;

                std::cout << "Enter city name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);

                std::cout << "Enter city population: ";
                std::cin >> population;

                std::cout << "Enter median household income: ";
                std::cin >> medianIncome;

                cities.addCityAtHead(name, population, medianIncome);
                break;
            }
            case 3:
                cities.displayCityWithLargestpop();
                break;
            case 4:
                cities.displayAllCityRecords();
                break;
            case 5:
                std::cout << "Exiting the program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (choice != 5);

    return 0;
}
           

