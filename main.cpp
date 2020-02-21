#include<iostream>

#include"LocalStaticSingleton.h"
#include"SmartPointerSingleton.h"

int main() {

    puts("\n*****************************\n");
    {
        // Getting  a reference.
        auto LSSingletonInstance = &LSSingleton::GetInstance();
        LSSingletonInstance->setX(42);
        std::cout << LSSingletonInstance->getX() << '\n';
        LSSingleton::GetInstance().setX(12);
        std::cout << LSSingletonInstance->getX() << '\n';
    }
    puts("\n*****************************\n");
    {
        // Getting a reference
        auto RPSingletonInstance = &RPSingleton::GetInstance();
        RPSingletonInstance->setX(42);
        std::cout << RPSingletonInstance->getX() << '\n';
        RPSingleton::GetInstance().setX(12);
        std::cout << RPSingletonInstance->getX() << '\n';
        RPSingleton::GetInstance().destroySingleton();
    }
    puts("\n*****************************\n");
    {
        // Getting a reference
        auto UPSingletonInstance = &UPSingleton::GetInstance();
        UPSingletonInstance->setX(42);
        std::cout << UPSingletonInstance->getX() << '\n';
        UPSingleton::GetInstance().setX(12);
        std::cout << UPSingletonInstance->getX() << '\n';
    }
    puts("\n*****************************\n");
    {
        // Getting a copy a shared_ptr
        auto SPSingletonInstance = SPSingleton::GetInstance();
        SPSingletonInstance->setX(42);
        std::cout << SPSingletonInstance->getX() << '\n';
        SPSingleton::GetInstance()->setX(12);
        std::cout << SPSingletonInstance->getX() << '\n';
    }
    puts("\n*****************************\n");

    return 0;
}
