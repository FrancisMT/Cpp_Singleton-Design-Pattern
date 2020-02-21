#pragma once

#include<iostream>

/** Singleton using a local static variable.
 * 
 * This is the standard approach when creating a singleton.
*/
class LSSingleton {
public:
    
    inline static LSSingleton& GetInstance() { 

        //Just for demonstration purposes.
        if(static bool bIsSingletonInstanceInitialized{false}; !bIsSingletonInstanceInitialized){
            std::cout << "Initializing LSSingleton" << '\n';
            bIsSingletonInstanceInitialized = !bIsSingletonInstanceInitialized;
        }

        static LSSingleton Instance;

        std::cout << "Getting LSSingleton Instance" << '\n';
        return Instance;
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
    LSSingleton() : x{9001} {std::cout << "LSSingleton constructor" << '\n';};


    /**
     * Destructor    
    */
    ~LSSingleton() {std::cout << "LSSingleton destructor" << '\n';}


    /**
     * Aggregate Constructor    
    */
    LSSingleton(std::initializer_list<int> il) = delete;

    /**
     * Copy Constructor    
    */
    LSSingleton(const LSSingleton& LSSingletonToCopy) = delete;

    /**
     * Move Constructor    
    */
    LSSingleton(LSSingleton&& LSSingletonToMove) = delete;

    /**
     * Copy Assignment Operator
    */
    LSSingleton& operator=(const LSSingleton& LSSingletonToCopy) = delete;

    /**
     * Move Assignment Operator
    */
    LSSingleton& operator=(LSSingleton&& LSSingletonToMove) = delete;

    int x;
};
