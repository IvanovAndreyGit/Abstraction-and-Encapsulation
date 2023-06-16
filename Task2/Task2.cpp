// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <sstream>

class address
{
private:
    std::string city;
    std::string street;
    int house_number = 0;
    int apprt_number = 0;


public:
    address()
    {
    }
    address(std::string v_city, std::string v_street, int v_house_number, int v_apprt_number)
    {
        city = v_city;
        street = v_street;
        house_number = v_house_number;
        apprt_number = v_apprt_number;
    }
    std::string get_output_address(std::string v_city, std::string v_street, int v_house_number, int v_apprt_number)
    {
        std::string full_addr = v_city + ", " + v_street + ", " + to_string(v_house_number) + ", " + to_string(v_apprt_number);
        return full_addr;
    }

    void SetCity(std::string v_city)
    {
        city = v_city;
    }
    void SetStreet(std::string v_street)
    {
        street = v_street;
    }
    void SetHouse(int v_house_number)
    {
        house_number = v_house_number;
    }
    void SetApprt(int v_apprt_number)
    {
        apprt_number = v_apprt_number;
    }

    std::string GetCity()
    {
        return city;
    }
    std::string GetStreet()
    {
        return street;
    }
    int GetHouse()
    {
        return house_number;
    }
    int GetApprt()
    {
        return apprt_number;
    }
    std::string to_string(int i)
    {
        std::string str;
        std::stringstream temp;
        temp << i;
        temp >> str;
        return str;
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");
    int n = 0;
    std::string tempC;
    std::string tempS;
    int tempH;
    int tempA;

    std::ifstream in_file("in.txt");
    std::ofstream out_file("out.txt", std::ios::out);
    in_file >> n;
    out_file << n << std::endl;
    std::cout << n << std::endl;
    std::cout << "--------------" << std::endl;
    address addr;
    address* addrArr = new address[n];
    while (!in_file.eof())
    {
        for (int i = 0; i < n; i++)
        {
            in_file >> tempC;
            in_file >> tempS;
            in_file >> tempH;
            in_file >> tempA;
            addrArr[i].SetCity(tempC);
            addrArr[i].SetStreet(tempS);
            addrArr[i].SetHouse(tempH);
            addrArr[i].SetApprt(tempA);
        }
    }

    bool swapped{};
    do
    {
        swapped = false;
        for (int i = 0; i < n - 1; i++)
        {
            std::string city1 = addrArr[i].GetCity();
            std::string city2 = addrArr[i + 1].GetCity();
            if (city1 > city2)
            {
                address temp = addrArr[i];
                addrArr[i] = addrArr[i + 1];
                addrArr[i + 1] = temp;
                swapped = true;
            }

        }
    } while (swapped);

    for (int i = 0; i < n; i++)
    {
        std::cout << addrArr[i].GetCity() << ", " << addrArr[i].GetStreet() << ", " << addrArr[i].GetHouse() << ", " << addrArr[i].GetApprt() << std::endl;
        std::string result = addr.get_output_address(addrArr[i].GetCity(), addrArr[i].GetStreet(), addrArr[i].GetHouse(), addrArr[i].GetApprt());
        out_file << result << std::endl;
    }

    delete[] addrArr;
    in_file.close();
    return 0;
}
