// MyString.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <math.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
//#include <cstdlib>
#include <ctype.h>
#include <vector>
#include <map>

using namespace std;

class SimpleStrings
{
private:
    string _stringX80 = "";
    string _rowRand;
    string _userRow;

public:
    SimpleStrings() {};
    SimpleStrings(const string& UserRow, const string& StringX80, const string& RowRand, const int& Size) : 
        _stringX80(StringX80.length() <= 80 ? StringX80 : ""),
        _userRow(UserRow),
        _rowRand(RowRand.length() <=Size ? RowRand : "") {};

    void SetStringX80() {
        string temp;
        do {
            cout << "Введите строку (макс размер 80 символов)\n";
            getline(cin, temp);
            _stringX80 = temp.length() <= 80 ? temp : "";
            if (_stringX80 == "") {
                cout << "Введен неправильный формат строки, попробуйте снова\n";
            }
        } while (_stringX80 == "");
    }

    void SetUserString() {
        string temp;
        do {
            cout << "Введите строку\n";
            getline(cin, temp);
            _userRow = temp;
            if (_userRow == "") {
                cout << "Введен неправильный формат строки, попробуйте снова\n";
            }
        } while (_userRow == "");
    }

    void SetUserSizeString() {
        string temp;
        int size;
        do {
            cout << "Введите размер строки\n";
            cin >> size;
            cout << "Введите строку\n";
            getline(cin, temp);
            _rowRand = temp.length() <= size ? temp : "";
            if (_rowRand == "") {
                cout << "Введен неправильный формат строки, попробуйте снова\n";
            }
        } while (_rowRand == "");
    }

    string GetStringX80() {
        return _stringX80;
    }

    string GetRowRand() {
        return _rowRand;
    }

    string GetUserRow() {
        return _userRow;
    }

    ~SimpleStrings() {};
};


class MyStringLibrary
{
private:
    vector<SimpleStrings> _strings;

public:
    
    MyStringLibrary(const SimpleStrings& String)
    {
        _strings.push_back(String);
    }

    void StringsNumber() {
        cout << "Количество созданных объектов строк - ";
        cout << _strings.size();
    }
};

class Room
{
private:
    string _roomName;
    double _roomSize;
    bool _glueTheCeiling;

public:
    Room() {};
    Room(const double& Length, const double& Width, const string& RoomName, const bool& GlueTheCeiling) {
        _roomSize = Length * Width;
        _roomName = RoomName;
        _glueTheCeiling = GlueTheCeiling;
    }

    string GetName() {
        return _roomName;
    }

    void SetName(const string& RoomName) {
        _roomName = RoomName;
    }

    double GetSize() {
        return _roomSize;
    }

    void SetSize(const double& Length, const double& Width) {
        _roomSize = Length * Width;
    }

    bool GetGlueTheCeiling() {
        return _glueTheCeiling;
    }

    void SetGlueTheCeiling(const bool& GlueTheCeiling) {
        _glueTheCeiling = GlueTheCeiling;
    }
};

class Wallpaper
{
private:
    string _wallpaperName;
    double _wallpaperSize;
    double _wallpaperPrice;

public:
    Wallpaper() {};
    Wallpaper(
        const string& WallpaperName, 
        const double& Length, 
        const double& Width, 
        const double& WallpaperPrice
    ) {
        _wallpaperName = WallpaperName;
        _wallpaperSize = Length * Width;
        _wallpaperPrice = WallpaperPrice;
    }
    string GetName() {
        return _wallpaperName;
    }
    void SetName(const string& WallpaperName) {
        _wallpaperName = WallpaperName;
    }

    double GetSize() {
        return _wallpaperSize;
    }
    void SetSize(const double& Length, const double& Width) {
        _wallpaperSize = Length * Width;
    }

    double GetPrice() {
        return _wallpaperPrice;
    }

    void SetPrice(const double& WallpaperPrice) {
        _wallpaperPrice = WallpaperPrice;
    }
};

class Flat
{
private:
    vector<Room> _rooms;
    Wallpaper wallpaper;
public:
    Flat() {};
    Flat(const Room& Room, const Wallpaper& Wallpaper) {
        _rooms.push_back(Room);
        wallpaper = Wallpaper;
    }

    void SetFlatRooms(const Room& Room) {
        _rooms.push_back(Room);
    }
    void SetWallpaper(const Wallpaper& Wallpaper) {
        wallpaper = Wallpaper;
    }

    void NeededWallpaperForTheFlat() {
        int wallpaperNumberNeeded=0;
        double flatDecorPrice=0;
        for (int i = 0; i < _rooms.size(); i++)
        {
            if (_rooms[i].GetSize() / wallpaper.GetSize() != 0) {
                wallpaperNumberNeeded += _rooms[i].GetSize() / wallpaper.GetSize() + 1;
            }
            else {
                wallpaperNumberNeeded += _rooms[i].GetSize() / wallpaper.GetSize();
            }
            if (_rooms[i].GetGlueTheCeiling()) {
                wallpaperNumberNeeded += wallpaperNumberNeeded;
            }
        }

        flatDecorPrice = wallpaperNumberNeeded * wallpaper.GetPrice();

        cout << "Кол. Обоев:\n" << wallpaperNumberNeeded << "\nЦена:" << flatDecorPrice;
    }
};


int main()
{
    setlocale(LC_ALL, "RUS");
    Room room1;
    Flat flat1;
    Wallpaper wallpaper1;
    room1.SetName("Гостиная");
    room1.SetSize(10, 20);
    room1.SetGlueTheCeiling(true);

    wallpaper1.SetSize(2, 1);
    wallpaper1.SetPrice(100);

    flat1.SetFlatRooms(room1);
    flat1.SetWallpaper(wallpaper1);
    flat1.NeededWallpaperForTheFlat();
}
