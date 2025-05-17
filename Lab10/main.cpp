/*#include <iostream>
#include <exception>
using namespace std;

class divzero: public exception
{
    virtual const char* what() const throw()
    {
        return "div0 not allowed";
    }
} ;

int main () {
    divzero exceptiamea;
    int a, b;
    cin>>a>>b;
    try
    {
        if (b == 0) {
            throw exceptiamea;
        }
        cout<<a/b;
    }
    catch (exception& e)
    {
        cout << e.what() << '\n';
    }
    return 0;
}
//template, retinem ce vrem noi si sa tratam operatii de adaugare;
//constructori, toti, normal, cu param, copy, move, dstructor, operator adunare, scadere, inmultire, cu un indexare, metode de manipulare elem
*/
#include <iostream>
#include <exception>
#include <cstdio>
using namespace std;

class div0: public exception
{
    virtual const char* what() const throw()
    {
        return "Impartirea la 0 nu este posibila";
    }
} eroare1;

class index: public exception {
    virtual const char* what() const throw() {
        return "Spatiu insuficient";
    }
} eroare2;

class nuexista: public exception {
    virtual const char* what() const throw() {
        return "Elementul nu exista";
    }
} eroare3;

class marime: public exception {
    virtual const char* what() const throw() {
        return "Nu se poate cauta intr-un vector mic un vector mai mare decat el";
    }
} eroare4;

template <typename T>
class vect {
    T* v;
    int size;
    int capacity;
    public:
        vect(): size(0), capacity(1) {
            v = new T[capacity];
            printf("ctor default called \n");
        }
        vect(int valoare) {
            capacity = valoare;
            size = 0;
            v = new T[capacity];
            //printf("size = %d, capacity = %d \n", size, capacity);
            //printf("capacity ctr called \n");
        }
        vect(const vect &other) { // constructor de copiere
            T* save = new T[other.capacity];
            for (int i = 0; i < other.size; i++) {
                save[i] = other.v[i];
            }
            capacity = other.capacity;
            size = other.size;
            v = new T[capacity];
            for (int i = 0; i < size; i++) {
                v[i] = other.v[i];
            }
            //printf("copy ctr called \n");
        }
        vect(vect &&other) { // constructor de mutare
            capacity = other.capacity;
            size = other.size;
            v = new T[capacity];
            for (int i = 0; i < size; i++) {
                v[i] = other.v[i];
            }
            printf("move ctr called \n");
        }
        ~vect() {
            delete[] v;
        }

        vect& operator=(vect &other) {

            if (this != &other)
            {
                delete[] v;
                size = other.size;
                capacity = other.capacity;
                v = new T[capacity];
                for (int i = 0; i < size; ++i)
                {
                    v[i] = other.v[i];
                }
            }
            return *this;

        }

        friend vect& operator+(vect &v1, vect &v2) {
            vect save(v1.capacity);
            save.size = v1.size;
            for (int i = 0; i < v1.size; i++) {
                save.v[i] = v1.v[i];
            }
            delete[] v1.v;
            v1.v = new T[v1.capacity+v2.capacity];

            for (int i = 0; i < v1.size; i++) {
                v1.v[i] = save.v[i];
            }
            for (int i = 0; i < v2.size; i++) {
                if (!v1.isnumber(v2.v[i])) {
                    v1.Set(v2.v[i]);
                }
            }
            return v1;
        }

        friend vect& operator-(vect &v1, vect &v2) {
            for (int i = 0; i < v2.size; i++) {
                if (v1.isnumber(v2.v[i])) {
                    v1.Delete(v2.v[i]);/*
                    for(int i = 0; i<v1.size; i++){
                        cout<<v1.v[i]<<" ";
                    }
                    cout<<endl;*/
                }
            }
            return v1;
        }

        friend vect& operator*( vect& other, const T& n) {
            //printf("multiplication called \n");

            //printf("multiplication called \n");
            //printf("Result : size = %d, capacity = %d \n", result.size, result.capacity);
            //printf("Other : size = %d, capacity = %d \n", other.size, other.capacity);
            for (int i = 0; i < other.size; i++) {
                other[i] = other[i] * n;
                //printf("Elem %d : %d\n", i, other[i]);
            }
            return other;
        }

        friend vect operator/(const vect& other, const T& n) {
            //printf("division called with n = %d\n", n); // Mesaj de debug
            if (n == 0) {
                throw eroare1; // Aruncă excepția
            }
            vect result(other.capacity);
            result.size = other.size;
            for (int i = 0; i < other.size; i++) {
                result.v[i] = other.v[i] / n;
            }
            return result;
        }

        T& operator[](int index) {
            //printf("index = %d -> %d\n", index, v[index]); // Mesaj de debug
            try {
                if (index > size || index < 0) {
                    throw eroare2;
                }
            }catch (exception& e) {
                cout << e.what() << '\n';
                exit(0);
            }
            return v[index];
        }

        bool isnumber(T n) {    //daca numarul n se afla in vector
            for (int i = 0; i < size; i++) {
                if (v[i] == n) {
                    //printf("Numarul %d se afla in vector\n", n); // Mesaj de debug
                    return true;
                }
            }
            return false;
        }

        void Set(T n) {
            if (size < capacity) {
                v[size] = n;
                //printf("Adăugat: %d\n", n); // Mesaj de debug
                size++;
            } else {
                T* save = new T[capacity * 2];
                for (int i = 0; i < size; i++) {
                    save[i] = v[i];
                }
                delete[] v;
                v = save;
                capacity *= 2;
                v[size] = n;
                //printf("Adăugat: %d\n", n); // Mesaj de debug
                size++;
            }
        }

        void Delete(T n) {
            try {
                bool exist = false;
                for (int i = 0; i < size && !exist; i++) {
                    if (v[i] == n) {
                        for (int j = i; j < size-1; j++) {
                            v[j] = v[j + 1];
                        }
                        size--;
                        exist = true;
                        //printf("Sters: %d\n", n); // Mesaj de debug
                    }
                }
                if (!exist) {
                    throw eroare3;
                }
            }catch (exception& e) {
                cout << e.what() << '\n';
            }

        }

        bool exist_vect(vect &other) {
            if (other.size > size) {
                throw eroare4;
            } else {
                int i = 0;
                while (i < other.size) {
                    if (v[i] == other[i]) {
                        int j=i;
                        while (j < other.size && j!=-1) {
                            if (v[j] != other[j]) {
                                j=-1;
                            }else {
                                j++;
                            }
                        }
                        if (j!=-1) {
                            return true;
                        }
                    }
                    i++;
                }
                return false;
            }
        }
        class Iterator {
            T* ptr;
        public:
            Iterator(T* p): ptr(p){}
            Iterator& operator++() {
                ++ptr;
                return *this;
            }
            bool operator!=(const Iterator &other) const{
                return ptr != other.ptr;
            }
            T& operator*() const {
                return *ptr;
            }
        };
        Iterator begin() {
            return Iterator(v);
        }
        Iterator end() {
            return Iterator(v + size);
        }
};

int main() {
    vect<int> n(4);
    n.Set(2);
    n.Set(4);
    n.Set(7);
    vect<int> m = n ; //printf("Am ajuns aici \n");
    m = m*2;
    printf("Vect m = n * 2 \n");
    for (const auto& i: m) {
        printf("%d ", i);
    }
    cout<<endl;
    printf("Vectorul n original \n");
    for(const auto& i : n) {
        printf("%d ", i);
    }
    cout<<endl;
    vect<int> p = m / 2 ;//printf("Am ajuns aici \n");
    printf("Vect p = m / 2 \n");
    for (const auto& i: p) {
        printf("%d ", i);
    }
    cout<<endl;
    vect<int> q = n; //printf("Am ajuns aici \n");
    q=q + m;
    printf("Vect q = n + m \n");
    for (const auto& i: q) {
        printf("%d ", i);
    }
    cout<<endl;
    vect<int> r = q;
    r = r - m;
    printf("Vect r = n - m \n");
    for (const auto& i: r) {
        printf("%d ", i);
    }
    cout<<endl;
    cout<<n.exist_vect(r)<<endl;
    cout<<n.exist_vect(p)<<endl;
    cout<<n.exist_vect(q)<<endl; // o sa dea eroare4
    return 0;
}