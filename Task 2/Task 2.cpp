// Task 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Task1.cpp
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
class Addresses
{
private:
    int number_addr = 0;
    std::string city;
    std::string street;
    int house = 0;
    int room = 0;

public:

    Addresses()
    {

    }

    Addresses(std::string v_city, std::string v_street, int v_house, int v_room)
    {
        city = v_city;
        street = v_street;
        house = v_house;
        room = v_room;
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
        return house;
    }
    int GetRoom()
    {
        return room;
    }
    int GetNumberAddr()
    {
        return number_addr;
    }
    void SetCity(std::string v_city)
    {
        city = v_city;
    }
    void SetStreet(std::string v_street)
    {
        street = v_street;
    }
    void SetHouse(int v_house)
    {
        house = v_house;
    }
    void SetRoom(int v_room)
    {
        room = v_room;
    }
    void SetNumberAddr(int v_number_addr)
    {
        number_addr = v_number_addr;
    }

    std::string get_output_address(std::string city, std::string street, int house, int room)
    {

        std::string res;
        std::string strH;
        std::string strR;
        std::stringstream tempH;
        std::stringstream tempR;
        std::string strC = city;
        std::string strS = street;
        tempH << house;
        tempH >> strH;
        tempR << room;
        tempR >> strR;
        res = strC + ", " + strS + ", " + strH + ", " + strR;

        return res;
    }


};

int main()
{
    setlocale(LC_ALL, "russian");
    std::string c;
    std::string s;
    int h;
    int r;
    int n;
    std::ifstream file_in("in.txt");
    Addresses address;

    if (file_in.is_open())
    {
        file_in >> n;
        address.SetNumberAddr(n);
        Addresses* addr_arr = new Addresses[n];
        while (!(file_in.eof()))
        {
            for (int i = 0; i < n; i++)
            {
                file_in >> c;
                addr_arr[i].SetCity(c);
                file_in >> s;
                addr_arr[i].SetStreet(s);
                file_in >> h;
                addr_arr[i].SetHouse(h);
                file_in >> r;
                addr_arr[i].SetRoom(r);
            }
        }
        std::cout << "---------" << std::endl;
        std::cout << addr_arr[0].GetCity() << std::endl;
        std::cout << addr_arr[1].GetCity() << std::endl;
        std::cout << addr_arr[2].GetCity() << std::endl;
        std::cout << addr_arr[3].GetCity() << std::endl;
        std::cout << addr_arr[4].GetCity() << std::endl;
        std::cout << "+++++++++" << std::endl;
        std::cout << address.GetNumberAddr() << std::endl;
        for (int i = 0; i < address.GetNumberAddr(); i++)
        {
            std::string result2 = addr_arr[i].GetCity();
            std::cout << result2 << std::endl;
        }
        std::cout << "+++++++++" << std::endl;
        std::ofstream file_out2("out2.txt");
        file_out2 << address.GetNumberAddr() << std::endl;
        //std::string City1 = addr_arr[0].GetCity();
        //std::string City2 = addr_arr[0 + 1].GetCity();
        //std::cout << City1[0] << std::endl;
        //std::cout << City2[0] << std::endl;
        std::cout << "xxxxxxxxxxxxx" << std::endl;
        bool swapped{};
        do
        {
            swapped = false;
            for (int i = 0; i < address.GetNumberAddr() - 1; i++)
            {
                std::string city1 = addr_arr[i].GetCity();
                std::string street1 = addr_arr[i].GetStreet();
                int house1 = addr_arr[i].GetHouse();
                int room1 = addr_arr[i].GetRoom();

                std::string city2 = addr_arr[i + 1].GetCity();
                std::string street2 = addr_arr[i + 1].GetStreet();
                int house2 = addr_arr[i + 1].GetHouse();
                int room2 = addr_arr[i + 1].GetRoom();

                std::cout << "11111111" << std::endl;
                std::cout << city1[0] << std::endl;
                std::cout << city2[0] << std::endl;
                std::cout << "11111111" << std::endl;

                if (city1[0] > city2[0])
                {
                    std::string temp_city = addr_arr[i].GetCity();
                    std::string temp_street = addr_arr[i].GetStreet();
                    int temp_house = addr_arr[i].GetHouse();
                    int temp_room = addr_arr[i].GetRoom();

                    addr_arr[i].SetCity(city2);
                    addr_arr[i].SetStreet(street2);
                    addr_arr[i].SetHouse(house2);
                    addr_arr[i].SetRoom(room2);

                    addr_arr[i + 1].SetCity(temp_city);
                    addr_arr[i + 1].SetStreet(temp_street);
                    addr_arr[i + 1].SetHouse(temp_house);
                    addr_arr[i + 1].SetRoom(temp_room);

                    swapped = true;
                }


            }


        } while (swapped);

        std::cout << "------------" << std::endl;
        for (int i = 0; i < address.GetNumberAddr(); i++)
        {
            std::string result3 = addr_arr[i].GetCity();
            std::cout << result3 << std::endl;
        }
        std::cout << "------------" << std::endl;

        file_out2.close();


        std::ofstream file_out("out.txt");
        file_out << address.GetNumberAddr() << std::endl;
        for (int i = 0; i < n; i++)
        {
            std::string result = address.get_output_address(addr_arr[i].GetCity(), addr_arr[i].GetStreet(), addr_arr[i].GetHouse(), addr_arr[i].GetRoom());
            file_out << result << std::endl;
        }
        //file_out.close();





        delete[] addr_arr;
    }
    file_in.close();

    return 0;
}

