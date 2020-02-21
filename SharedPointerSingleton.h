#pragma once

#include<iostream>
#include<memory>
#include<mutex>

/** Singleton using a local static weak_ptr.
 * 
 * This is not a perfect singleton implementation since
 * it is not possible to "privatise" the class constructor.
*/
class SPSingleton {

public:

    /**
     * Returns a shared_ptr to the same instance of SPSingleton
    */
    static std::shared_ptr<SPSingleton> GetInstance() {
        
        static std::weak_ptr<SPSingleton> weakSPSingletonInstance;
        auto SPSingletonInstance = weakSPSingletonInstance.lock();

        if(!SPSingletonInstance) {
            std::cout << "Initializing SPSingleton" << '\n';
            SPSingletonInstance = std::make_shared<SPSingleton>();
            weakSPSingletonInstance = SPSingletonInstance;
        }   
        return SPSingletonInstance;
    }

    /**
     * Constructor    
    */
    SPSingleton() : x{9001} {std::cout << "SPSingleton constructor" << '\n';}

    /**
     * Destructor    
    */
    ~SPSingleton() {std::cout << "SPSingleton destructor" << '\n';}

    /**
     * Getter & Setter
    */
    inline void setX(int val){x = val;}
    inline int getX() const {return x;}

private:

    /**
     * Aggregate Constructor    
    */
    SPSingleton(std::initializer_list<int> il) = delete;

    /**
     * Copy Constructor    
    */
    SPSingleton(const SPSingleton& SPSingletonToCopy) = delete;

    /**
     * Move Constructor    
    */
    SPSingleton(SPSingleton&& SPSingletonToMove) = delete;

    /**
     * Copy Assignment Operator
    */
    SPSingleton& operator=(const SPSingleton& SPSingletonToCopy) = delete;

    /**
     * Move Assignment Operator
    */
    SPSingleton& operator=(SPSingleton&& SPSingletonToMove) = delete;

    int x;
};
