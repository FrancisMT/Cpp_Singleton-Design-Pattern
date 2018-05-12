#include<iostream>
#include<mutex>

/** Creating a singleton with local statics and a mutex.
 * 
 * A mutex is used to ensure that the singleton will be
 * thread safe initialized.
*/
class LSSingeton {

public:

    inline void IsNum42(const int Number) {
        (Number == 42)  ?
        std::cout << "Yes" << std::endl : 
        std::cout << "No" << std::endl  ;
    }

    inline static LSSingeton& GetInstance() {
     
        if(!IsInstanceValid()) {
            std::cout << "Initializing Singleton" << std::endl;
            
            std::lock_guard<std::mutex> InitLock(InitMutex);
            Instance = new LSSingeton();
        }

        std::cout << "Getting Singleton Instance" << std::endl;
        return *Instance;
    }

    inline static bool IsInstanceValid() {
        return (Instance != nullptr);
    }

    inline static void ResetInstance() {
        delete Instance;    // Works even if the pointer is null.
        Instance = nullptr; // So that "GetInstance()"" still works.
   }

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
    LSSingeton(LSSingeton const&) = delete;
    LSSingeton operator=(LSSingeton const&) = delete;

private:

    /** 
     * We don't want another singleton to be constructed.
    */
    LSSingeton() = default;     // Same as LSSingleton(){};
    
    /** 
     * We don't want our singleton to be accidentally destroyed.
     * 
     * It will get torn down and be deallocated when the program terminates.
    */
    ~LSSingeton() = default;    // Same as ~LSSingleton(){};
    
    static LSSingeton* Instance;
    static std::mutex InitMutex;
    
};
LSSingeton* LSSingeton::Instance = nullptr;
std::mutex LSSingeton::InitMutex{};