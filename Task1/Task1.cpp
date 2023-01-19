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

        std::ofstream file_out("out.txt");
        file_out << address.GetNumberAddr() << std::endl;
        for (int i = n - 1; i >= 0; i--)
        {
            std::string result = address.get_output_address(addr_arr[i].GetCity(), addr_arr[i].GetStreet(), addr_arr[i].GetHouse(), addr_arr[i].GetRoom());
            file_out << result << std::endl;
        }
        file_out.close();

        delete[] addr_arr;
    }
    file_in.close();

    return 0;
}

