#include <stdio.h>
#include <tuple>
using namespace std;

template <typename K, typename V>
class Map {

    struct Data {
        K key;
        V value;
    }*data;
    int size;
    public:
        Map(): size(0) {
            data = new Data[100];
        }

        ~Map() {
            delete[] data;
        }

        V& operator[](const K& cheie) {
            for (int i = 0; i < size; i++) {
                if (data[i].key == cheie) {
                    return data[i].value;
                }
            }
            data[size].key = cheie;
            return data[size++].value;
        }

        void Set(const K& cheie, const V& valoare) {
            (*this)[cheie] = valoare;
        }

        bool Get(const K& cheie, V& valoare ) {
            for (int i = 0; i < size; i++) {
                if (data[i].key == cheie) {
                    valoare = data[i].value;
                    return true;
                }
            }
            return false;
        }

        int Count() {
            return size;
        }

        void Clear() {
            size = 0;
        }

        bool Delete(const K& cheie) {
            for (int i = 0; i < size; i++) {
                if (data[i].key == cheie) {
                    for (int j = i; j < size - 1; j++) {
                        data[j] = data[j + 1];
                    }
                    size--;
                    return true;
                }
            }
            return false;
        }

        bool Includes(const Map<K,V>& map) {
            if (map.size != size) {
                return false;
            }
            for (int i = 0; i < size; i++) {
                V temp;
                if (!Get(map[i].key, temp)) {
                    return false;
                }
            }
            return true;
        }

        struct Iterator {
            Map<K,V>& map;
            int index;

            Iterator(Map<K,V>& m, int i) : map(m), index(i) {}

            auto operator*() {
                return tuple<K, V, int>(map.data[index].key, map.data[index].value, index);
            }

            Iterator& operator++() {
                ++index;
                return *this;
            }

            bool operator!=(const Iterator& it) const {
                return index != it.index;
            }
        };
    Iterator begin() {
        return Iterator(*this, 0);
    }
    Iterator end() {
        return Iterator(*this, size);
    }
};

int main()
{
    Map<int, const char *> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}
