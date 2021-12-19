typedef int Rank; // 秩
#define DEFAULT_CAPACITY 3 // 默认大小
template<typename T>
class Vector {
protected:
    Rank _size; // 规模
    int _capacity; // 容量
    T *_elem; // 数据区

    void copyFrom(T const *A, Rank lo, Rank hi); // 复制数组lo， hi
    void expand(); // 空间不足时扩容
    void shrink(); // 装填因子过小时压缩
    bool bubble(Rank lo, Rank hi); // 扫描交换
    void bubbleSort(Rank lo, Rank hi); // 冒泡排序
    Rank max(Rank lo, Rank hi); // 选取区域最大元素
    void selectionSort(Rank lo, Rank hi); // 选择排序
    void merge(Rank lo, Rank hi); // 归并算法
    void mergeSort(Rank lo, Rank hi); // 归并排序
    void partition(Rank lo, Rank hi); // 轴点构造算法
    void quickSort(Rank lo, Rank hi); // 快速排序
    void heapSort(Rank lo, Rank hi); // 堆排序
public:
// 构造函数
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) {// 容量、规模、初始化元素
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _size++) {
            _elem[_size] = v;
        }
    }
    Vector(T const *A, Rank lo, Rank hi) { // 复制数组区域元素
        copyFrom(A, lo, hi);
    }
    Vector(T const *A, Rank n) { // 复制数组整个元素
        copyFrom(A, 0, n);
    }
    Vector(Vector<T> const &V, Rank lo, Rank hi) { // 复制Vector元素
        copyFrom(V._elem, lo, hi);
    }
    Vector(Vector<T> const &V) { // Vector整体复制
        copyFrom(V._elem, 0, V._size);
    }

    ~Vector() {delete []_elem;} // 析构函数
// 只读
    Rank size() const {return _size;} // 规模
    bool empty() const {return !_size}; // 判空
    int disordered() const; // 是否已排序
    Rank find(T const &e) const {return find(e, 0, _size);} // 无序Vector查找元素
    Rank find(T const &e, Rank lo, Rank hi) const; // 无序Vector区域查找元素
    Rank search(T const &e) const {return (0 >= _size) ? -1 : search(e, 0, _size);}
    Rank search(T const &e, Rank lo, Rank hi) const; // 有序Vector查找元素
//修改
    T &operator[](Rank r) const; // 重载【】
    Vector<T> & operator=(Vector<T> const&); // 重载=
    T remove(Rank r); // 移除元素
    int remove(Rank lo, Rank hi); // 删除区域元素
    Rank insert(Rank r, T const &e); // 在r处插入元素
    Rank insert(T const &e) {return insert(_size, e);} // 在末尾插入元素
    void sort(Rank lo, Rank hi); // 区域排序
    void sort() {sort(0, _size);} // 整体排序
    void unsort(Rank lo, Rank hi); // 区域打乱顺序
    void unsort() {unsort(0, _size);} // 整体打乱
    int deduplicate(); // 无序去重
    int uniquify(); // 有序去重
    void traverse(void (*)(T &)); // 遍历，传入特定的访问函数
    template<typename VST>
    void traverse(VST&); // 遍历，传入特定的函数对象
};

template<typename T>
void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi) {
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0;
    while (lo < hi)
    {
        _elem[_size++] = A[lo++];
    }
}

