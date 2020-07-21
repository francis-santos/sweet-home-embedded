#ifndef OPERATOR_FACTORY_H
#define OPERATOR_FACTORY_H

#include <functional>
#include <map>
#include <string>

template <class T>
class OperatorFactory
{
    public:
        static OperatorFactory* getInstance();
        typedef std::function<void(T, int)> Callback;
        bool AddOperator(std::string sOperator, Callback fn);
        bool RemoveOperator(std::string sOperator);
        void RemoveAllOperators();
        auto GetOperator(std::string sOperator) -> Callback;
    private:
        static OperatorFactory* instance;
        OperatorFactory();
        virtual ~OperatorFactory();
        std::map<std::string, Callback> map_OperatorMap;
};

#include "./OperatorFactoryImpl.h"

#endif // OPERATOR_FACTORY_H