template <typename T>
void Sort2(T & first, T & second)
{
    if (second < first)
    {
        T buffer = first;
        first = second;
        second = buffer;
    }
}

template <>
void Sort2<const char*>(const char* & first, const char* & second);
