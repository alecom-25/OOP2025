//
// Created by Alexia on 05.05.2025.
//

#ifndef MAPA_H
#define MAPA_H

#endif //MAPA_H

template <typename K, typename V>
class Map {

    struct Data {
        K key;
        V value;
    }*data;
    int size; // cate elemente am
    int count; // dimensiunea maxima
    public:
        Map(): size(0), count(1) {
            data = new Data[count];
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
            if (size == count) {
                Data* newData = new Data[count + 1];
                for (int i = 0; i < count; i++) {
                    newData[i] = data[i];
                }
                delete[] data;
                data = newData;
            }
            data[size] = { cheie };
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
            delete[] data;
            size = 0; count = 1;
            data = new Data[count];
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
            int marime=0;
            for (int i = 0; i < size; i++) {
                V temp;
                if (Get(map[i].key, temp)) {
                    marime++;
                }
            }
            if (marime == map.size) {
                return true;
            }
            return false;
        }

        struct Item {
            K key;
            V value;
            int index;
        };

        struct Iterator {
            Data* valori;
            int index;

            Iterator(Data* d, int i) : valori(d), index(i) {}

            auto operator*() {
                return Item{valori->key, valori->value, index};
            }

            Iterator& operator++() {
                ++valori;
                ++index;
                return *this;
            }

            bool operator!=(const Iterator& it) const {
                return index != it.index;
            }
        };
    Iterator begin() {
        return Iterator(this->data, 0);
    }
    Iterator end() {
        return Iterator(this->data, size);
    }
};
