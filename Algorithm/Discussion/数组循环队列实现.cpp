
template<typename T>
LoopQueue<T>::LoopQueue(int c = 10)
: capacity(c), begin(0), end(0), queue(nullptr)
{
    queue = new T[capacity];
};
 
template<typename T>
LoopQueue<T>::~LoopQueue()
{
    delete[]queue;
}
 
template <typename T>
bool LoopQueue<T>::isEmpty()
{
    if (begin == end)
        return true;
    return false;
};
 
template<typename T>
int LoopQueue<T>::size()
{
    return (end-begin+capacity)%capacity; //计算队列长度
};
 
template<typename T>
bool LoopQueue<T>::push(T t)
{
    if (end + 1 % capacity == begin) //判断队列是否已满
    {
        return false;
    }
    queue[end] = t;
    end = (end + 1) % capacity;
    return true;
};
 
template <typename T>
bool LoopQueue<T>::pop()
{
    if (end == begin) //判断队列是否为空
    {
        return false;
    }
    begin = (begin + 1) % capacity;
    return true;
};
 
template <typename T>
T LoopQueue<T>::front()
{
    if (end == begin)
    {
        return false;
    }
    return queue[begin];
};