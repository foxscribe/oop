template <typename T>
void Sort2(T & first, T & second)
{

}

template <>
void Sort2<const char*>(const char* & first, const char* & second);
