#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

class adress_book
{
private:
    std::string town;
    std::string street;
    int num_house;
    int num_flat;
public:
    adress_book(std::string town, std::string street, int num_house, int num_flat)
    {
        this->town = town;
        this->street = street;
        this->num_house = num_house;
        this->num_flat = num_flat;
    }
    adress_book() {};

    std::string out_adres()
    {
        std::string numHouse, numFlat;
        numHouse = std::to_string(num_house);
        numFlat = std::to_string(num_flat);
        std::string adres_out =  town + ", " + street + ", " + numHouse + ", " + numFlat;
        return adres_out;
    }
};

adress_book* arr_adres(int number)
{
    adress_book* arr = new adress_book[number];
    return arr;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
        
    std::ifstream file("in.txt");
    if (file.is_open())
    {
        int number, house, flat;
        std::string size_ar1, field1, field2, field3, field4;
        file >> size_ar1;
        number = std::stoi(size_ar1);
        adress_book* arr_adresses = arr_adres(number);
        for (int i = 0; i < number; ++i)
        {
            file >> field1;
            file >> field2;
            file >> field3;
            file >> field4;
            house = std::stoi(field3);
            flat = std::stoi(field4);
            adress_book adress(field1, field2, house, flat);
            arr_adresses[i] = adress;
        }
        file.close();
        std::ofstream fout("out.txt");
        fout << number;
        fout << std::endl;
        for (int i = number - 1; i >= 0; --i)
        {
            adress_book adress = arr_adresses[i];
            fout << adress.out_adres();
            fout << std::endl;
        }
        fout.close();
        delete[] arr_adresses;
    }
    else
    {
        std::cout << "Ошибка! Фаил начальных условий не найден! Код ошибки: -1" << std::endl;
        return 0;
    }
    return 0;
}