#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

string getPassword(int length)
{
    string password = "";
    string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    srand(time(0));
    for (int i = 0; i < length; i++)
    {
        password += characters[rand() % characters.length()];
    }
    return password;
}

string getName()
{
    string name;
    cout << "Enter your name: ";
    cin >> name;
    return name;
}

void create_user_file(const std::string &filename, const std::string &name, const std::string &password, double height)
{
    std::ofstream user_file(filename + ".txt", std::ios::app);
    if (user_file.is_open())
    {
        user_file << "Name: " << name << std::endl;
        user_file << "Password: " << password << std::endl;
        user_file << "Height: " << height << " cm" << std::endl;
        user_file.close();
        std::cout << "User file updated successfully: " << filename << ".txt" << std::endl;
    }
    else
    {
        std::cout << "Unable to update user file for: " << filename << std::endl;
    }
}

int main()
{
    string filename;
    cout << "Enter the name of the text file to open (without extension): ";
    cin >> filename;

    ifstream existingFile(filename + ".txt");

    if (!existingFile.is_open())
    {
        cout << "File not found. Creating a new file." << endl;
    }
    else
    {
        cout << "File found. Appending to existing file." << endl;
        existingFile.close();
    }

    double height;
    string name = getName(); // Ask for user's name
    cout << "Your name is: " << name << endl;

    cout << "Enter your height: ";
    cin >> height;
    cout << "Your height is: " << height << " cm" << endl;

    int length;
    cout << "Enter the length of the password: ";
    cin >> length;

    string password = getPassword(length);
    cout << "Your password is: " << password << endl;

    create_user_file(filename, name, password, height);

    return 0;
}
