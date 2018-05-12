#include<iostream>
#include<memory>
#include<mutex>

std::once_flag testflag; 

/** Thread-safe singleton using:
 * 
 * Smart Pointers;
 * std::call_once: 
 *      ->  Wraps a callable object and ensures it is called only once
 *          (even if multiple threads try to call it all a the same time).
 *      ->  The wrapper is using an object of type "std::once_flag" to
 *          keep track wheter the code was already called.
*/
class SPSingleton {

public:

    inline void IsNum42(const int Number) {
        (Number == 42)  ?
        std::cout << "Yes" << std::endl : 
        std::cout << "No" << std::endl  ;
    }

    inline static SPSingleton& GetInstance() {

        // Guaratees that the singleton will be thread safe initialized.
        std::call_once(SPSingleton::InitFlag, [](){
            std::cout << "Initializing Singleton" << std::endl;
            Instance.reset(new SPSingleton);
        });

        std::cout << "Getting Singleton Instance" << std::endl;
        return *(Instance.get());        
    }
    
     /** 
     * std::unique_ptr and std::share_ptr are only
     * usable with classes that don't provide public destructors.
    */
    ~SPSingleton() = default;    // Same as ~SPSingleton(){};

    /**
     * Make sure the copy constructor and the assignment operator
     * are not implemented. 
     * We don't want accidental copies of the singleton.
     * 
     * Side note: 
     * deleted functions should be public 
     * as it results in better error messages 
     * due to the compilers behavior to check accessibility
     * before deleted status.
    */
    SPSingleton(SPSingleton const&) = delete;
    SPSingleton& operator=(SPSingleton const&) = delete;

private:
    /** 
     * We don't want another singleton to be constructed.
    */
    SPSingleton() = default;     // Same as SPSingleton(){};

    static std::unique_ptr<SPSingleton> Instance;
    static std::once_flag InitFlag; 
};

std::unique_ptr<SPSingleton> SPSingleton::Instance{};
std::once_flag SPSingleton::InitFlag{}; 