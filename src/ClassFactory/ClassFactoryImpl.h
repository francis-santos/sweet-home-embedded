

template <class ClassType>
ClassFactory<ClassType>* ClassFactory<ClassType>::instance = 0;

template <class ClassType>
ClassFactory<ClassType>* ClassFactory<ClassType>::getInstance() {
  if (instance == 0) {
    instance = new ClassFactory<ClassType>();
  }
  return instance;
}

template <class ClassType>
void ClassFactory<ClassType>::RemoveAllClasses()
{
    map_ClassMap.clear();
}

template <class ClassType>
bool ClassFactory<ClassType>::RemoveClass(std::string sClass)
{
    return map_ClassMap.erase(sClass) != 0;
}

template <class ClassType>
bool ClassFactory<ClassType>::AddClass(std::string sClass, ClassType klass)
{
    map_ClassMap.insert(std::make_pair(sClass, klass));
}

template <class ClassType>
auto ClassFactory<ClassType>::GetClass(std::string sClass) -> ClassType
{
    auto fn = map_ClassMap.find(sClass);
    return fn->second;
}