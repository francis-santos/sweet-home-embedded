
template <class T>
OperatorFactory<T>* OperatorFactory<T>::instance = 0;

template <class T>
OperatorFactory<T>* OperatorFactory<T>::getInstance() {
  if (instance == 0) {
    instance = new OperatorFactory<T>();
  }
  return instance;
}

template <class T>
OperatorFactory<T>::OperatorFactory()
{
}

template <class T>
OperatorFactory<T>::~OperatorFactory()
{
}

template <class T>
void OperatorFactory<T>::RemoveAllOperators()
{
    map_OperatorMap.clear();
}

template <class T>
bool OperatorFactory<T>::RemoveOperator(std::string sOperator)
{
    return map_OperatorMap.erase(sOperator) != 0;
}

template <class T>
bool OperatorFactory<T>::AddOperator(std::string sOperator, Callback fn)
{
    map_OperatorMap.insert(std::make_pair(sOperator, fn));
}

template <class T>
auto OperatorFactory<T>::GetOperator(std::string sOperator) -> Callback
{
    auto fn = map_OperatorMap.find(sOperator);
    return fn->second;
}