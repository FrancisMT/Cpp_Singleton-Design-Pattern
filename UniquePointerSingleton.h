#pragma once

#include<iostream>
#include<mutex>
#include<memory>

/** Singleton using a private static unique_ptr and a mutex.
 * 
 * A mutex is used to ensure that the singleton will be
 * thread safe initialized.
*/
class UPSingleton {

public:
    inline static UPSingleton& GetInstance() {

        if(!IsInstanceValid()) {
            std::cout << "Initializing UPSingleton" << '\n';
            
            std::lock_guard<std::mutex> InitLock(InitMutex);
            Instance.reset(new UPSingleton);
        };

        std::cout << "Getting UPSingleton Instance" << '\n';
        return *Instance;        
    }
    
    /** 
     * smart pointers are only usable with classes
     * that provide public destructors.
    */
    ~UPSingleton() {std::cout << "UPSingleton destructor" << '\n';};

    /**
     * Getter & Setter
    */
    inline void setX(int val){x = val;}
    inline int getX() const {return x;}

private:
    /** 
     * Constructor
    */
    UPSingleton() : x{9001} {std::cout << "UPSingleton constructor" << '\n';};

    /**
     * Aggregate Constructor    
    */
    UPSingleton(std::initializer_list<int> il) = delete;

    /**
     * Copy Constructor    
    */
    UPSingleton(const UPSingleton& UPSingletonToCopy) = delete;

    /**
     * Move Constructor    
    */
    UPSingleton(UPSingleton&& UPSingletonToMove) = delete;

    /**
     * Copy Assignment Operator
    */
    UPSingleton& operator=(const UPSingleton& UPSingletonToCopy) = delete;

    /**
     * Move Assignment Operator
    */
    UPSingleton& operator=(UPSingleton&& UPSingletonToMove) = delete;


    inline static bool IsInstanceValid() {
        return (Instance != nullptr);
    }

    static std::unique_ptr<UPSingleton> Instance;
    static std::mutex InitMutex;

    int x;
};
std::unique_ptr<UPSingleton> UPSingleton::Instance{};
std::mutex UPSingleton::InitMutex{};
