#ifndef CLASS_FACTORY_H
#define CLASS_FACTORY_H

#include <map>
#include <string>

template <class ClassType>
class ClassFactory
{
    public:
        static ClassFactory* getInstance();
        bool AddClass(std::string sClass, ClassType klass);
        bool RemoveClass(std::string sClass);
        void RemoveAllClasses();
        auto GetClass(std::string sClass) -> ClassType;
    private:
        static ClassFactory* instance;
        std::map<std::string , ClassType> map_ClassMap;
};

#include "ClassFactoryImpl.h"

#endif // CLASS_FACTORY_H

