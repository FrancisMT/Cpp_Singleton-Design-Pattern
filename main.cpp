#include<iostream>

#include"LocalStaticSingleton.h"
#include"SmartPointerSingleton.h"

int main() {
    
    auto LSSingletonInstance = &LSSingeton::GetInstance();
    LSSingletonInstance->IsNum42(42);

    auto SPSingletonInstance = &SPSingleton::GetInstance();
    SPSingletonInstance->IsNum42(42);

    return 0;
}