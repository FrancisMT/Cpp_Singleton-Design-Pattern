#pragma once

#include<iostream>
#include<mutex>

/** Singleton using a private static pointer and a mutex.
 * 
 * A mutex is used to ensure that the singleton will be
 * thread safe initialized.
*/
class RPSingleton {

public:
    inline static RPSingleton& GetInstance() {
     
        if(!IsInstanceValid()) {
            std::cout << "Initializing RPSingleton" << '\n';
            
            std::lock_guard<std::mutex> InitLock(InitMutex);
            Instance = new RPSingleton();
        }

        std::cout << "Getting RPSingleton Instance" << '\n';
        return *Instance;
    }

    /**
    * Although memory will only be allocated once (no memory leaks in theory),
    * having an auxiliary method that calls delete for the class pointer
    * is the only way to guarantee this singleton's class destructor is called.
    */
    void destroySingleton() {
        delete Instance;
    }

    /**
     * Getter & Setter
    */
    inline void setX(int val){x = val;}
    inline int getX() const {return x;}

private:
    /** 
     * Constructor
    */
    RPSingleton() : x{9001} {std::cout << "RPSingleton constructor" << '\n';};

    /**
     * Destructor    
    */
    ~RPSingleton() {std::cout << "RPSingleton destructor" << '\n';}

    /**
     * Aggregate Constructor    
    */
    RPSingleton(std::initializer_list<int> il) = delete;

    /**
     * Copy Constructor    
    */
    RPSingleton(const RPSingleton& PPSingletonToCopy) = delete;

    /**
     * Move Constructor    
    */
    RPSingleton(RPSingleton&& PPSingletonToMove) = delete;

    /**
     * Copy Assignment Operator
    */
    RPSingleton& operator=(const RPSingleton& PPSingletonToCopy) = delete;

    /**
     * Move Assignment Operator
    */
    RPSingleton& operator=(RPSingleton&& PPSingletonToMove) = delete;

    inline static bool IsInstanceValid() {
        return (Instance != nullptr);
    }

    static RPSingleton* Instance;
    static std::mutex InitMutex;
    
    int x;
};
RPSingleton* RPSingleton::Instance{};
std::mutex RPSingleton::InitMutex{};
