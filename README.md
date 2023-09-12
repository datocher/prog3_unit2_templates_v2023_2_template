# Task #2: Templates
**course:** Programación III  
**unit:** 2  
**cmake project:** prog3_unit2_templates_v2023_2
## Instructions
Subir a gradescope los siguientes archivos:
- `P1.h` y `P1.cpp`
- `P2.h` y `P2.cpp`
- `P3.h` y `P3.cpp`
- `P4.h` y `P4.cpp`
- `P5.h` y `P5.cpp`
- `P6.h` y `P6.cpp`
- `P7.h` y `P7.cpp`
- `P8.h` y `P8.cpp`
- `P9.h` y `P9.cpp`
- `P10.h` y `P10.cpp`
- `P11.h` y `P11.cpp`
- `P12.h` y `P12.cpp`

### Question #1 - python input - template de función (1 points)

Crear la función template **`input`** que simula el funcionamiento de la función de python **`input`**.

**Use Case:**
```cpp
    // Por default el template retorna un std::string
auto text = input();
auto entero = input<int>("Ingrese un numero: ");
auto real = input<double>("Ingrese un numero: ");
std::cout << "El texto es: " << text << endl;
std::cout << "El entero es: " << entero << endl;
std::cout << "El real es: " << real << endl;
```

### Question #2 - print - template de función (1 points)

Crear la función template **`print`** que permita imprimir el contenido de un contenedor, incluyendo un delimitador, un objeto del tipo **`std::ostream`** que recibirá el contenido del contenedor.

**Use Case:**
```cpp
    // Vector
std::vector<int> vec = {10, 20, 30, 40, 50, 60};
// Imprimir en consola
print(begin(vec), end(vec), std::cout, "-");
// Grabarlos en un archivo
std::ofstream file("out.txt");
print(begin(vec), end(vec), file, "|");
// Imprimir la mitad de valores
auto last_it = next(begin(vec), vec.size() / 2);
print(begin(vec), last_it, std::cout, "-");

```

### Question #3 - sumarizar - template de función (1 points)

Crear la función template **`sumarizar`** que permita sumar el contenido de un contenedor con valores numéricos, que incluya un parámetro que defina un valor inicial.

**Use Case:**
```cpp
    // Contenedor 
std::list<double> lst = {10.5, 20.4, 30.2, 40.5, 50.9, 60.5};
cout << "Total: " << sumarizar(begin(lst), end(lst), 0) << endl;
// Calcular la mitad de valores inferior
auto last_it = next(begin(lst), size(lst) / 2);
cout << "Sumatoria de la mitad: " << sumarizar(begin(lst), last_it, 0) << endl;
```

### Question #4 - puntero inteligente - template de clase (2 points)
Crear la clase template **`smart_ptr`** que simule un puntero inteligente (la memoria es liberada automáticamente) y la función template **`make_smart_ptr`** que simule el operador **`new`**. Sobrecargar el operador de-referencia `*`, el operador arrow `->`.


**Use Case #1:**
```cpp
    smart_ptr<int> sp1; // puntero inteligente no inicializado
sp1 = make_smart_ptr<int>(10);

cout << *sp1 << endl;   // Imprimiendo el contenido

// puntero inteligente no inicializado
smart_ptr<string> sp2 = make_smart_ptr<string>("Hola");
cout << *sp2 << endl;
```

**Use Case #2:**
```cpp
    class point {
int x;
int y;
public:
point(int x, int y): x{x}, y{y} {}
point() = default;

friend ostream& operator<< (ostream& os, const point& p) {
os << "{" << x <<", " << y << "}" << endl;
return os;
}

int get_x() { return x; }
int get_y() { return y; }
};

smart_ptr<point> sp1; // puntero inteligente no inicializado
sp1 = make_smart_ptr<point>(20, 30);

cout << *sp1 << endl;   // Imprimiendo el contenido

smart_ptr<point> sp2 = make_smart_ptr<point>(10, 40); // puntero inteligente no inicializado
cout << sp2->get_x() << endl;
cout << sp2->get_y() << endl;
```

### Question #5 - suma producto - template de función (1 points)
Crear la función template **`suma_producto`** del tipo variadic que permita tomar de 2 en 2 los parámetros de la función template, calcule el producto y que realice la suma de todos los productos. En caso la cantidad de valores variados sea impar el último valor será considerado en la suma.

**Use Case #1:**
```cpp
    std::cout << suma_producto(1, 10, 3, 5) << endl; // El resultado seria: 25
```
**Use Case #2:**
```cpp
    std::cout << suma_producto(1) << endl; // El resultado seria: 1
```
**Use Case #3:**
```cpp
    std::cout << suma_producto(2, 10.5, 14.0, 1, 11.0) << endl; // El resultado seria: 46
```

**Use Case #4:**
```cpp
    std::cout << suma_producto(-2, 0, 1, 0, 0) << endl; // El resultado seria: 0
```

### Question #6 - Retornar el indice - template de función (2 points)
Crear la función template **`index_of`** que retorne la posición del tipo de dato del parámetro de la funcion, comparado con una lista de tipos, en caso el tipo no se encuentra entonces la funcion retornara -1.

**Use Case #1:**
```cpp
    char var1{};
    std::cout << index_of<int, char>(var1) << endl; // El resultado seria: 1 
```

**Use Case #2:**
```cpp
    string var2;
    std::cout << index_of<int, char, double, float, string>(var2) << endl; // El resultado seria: 4
```

**Use Case #3:**
```cpp
    vector<int> var3;
    std::cout << index_of<int, char, vector<int>, list<double>>(var3) << endl; // El resultado seria: 2 
```

**Use Case #4:**
```cpp
    vector<double> var4;
    std::cout << index_of<int, char, vector<int>, list<double>>(var4) << endl; // El resultado seria: -1 
```


### Question #7 - Operador << - template de función (2 points)

La librería de C++ no permite usar directamente el operador `std::cout` de forma similar que en el caso de variables simples, por ejemplo:
```cpp
    int var = 20
    std::cout << "El valor de var es: " << var << std::endl;    // El valor de var es: 20
```
En cambio en contenedores por ejemplo del tipo `std::array`, `std::vector`, `std::list` o `std::map` no permite por ejemplo:
```cpp
    std::list<int> lst = {10, 20, 30};
    std::cout << "Los valores de lst son: " << lst << std::endl; // NO PERMITIDO
    std::map<char, int> mp = {{'a', 10}, {'b', 20}, {'c', 30}};
    std::cout << "Los valores de mp son: " << mp << std::endl; // NO PERMITIDO
```
Desarrollo el template de sobrecarga del `operador <<` que permita generalizar el uso de `std::cout` para el caso de los siguientes contenedores:
- `std::array`
- `std::vector`
- `std::list`
- `std::map`

**Use Case #1:**
```cpp
    std::array<int, 3> arr = {10, 20, 30};
    std::cout << "Los valores de arr son: " << arr << std::endl; // Los valores de lst son: {10, 20, 30}
```

**Use Case #2:**
```cpp
    std::vector<int> vec = {10, 20, 30};
    std::cout << "Los valores de vec son: " << vec << std::endl; // Los valores de lst son: {10, 20, 30}
```

**Use Case #3:**
```cpp
    std::list<int> lst = {10, 20, 30};
    std::cout << "Los valores de lst son: " << lst << std::endl; // Los valores de lst son: {10, 20, 30}
```

**Use Case #4:**
```cpp
    std::map<char, int> mp = {{'a', 10}, {'b', 20}, {'c', 30}};
    std::cout << "Los valores de mp son: " << mp << std::endl; // Los valores de mp son: {{a: 10}, {b: 20}, {c: 30}}
```

### Question #8 - los mismos tipos - template de clase (2 points)
Generar un template funcion `are_same` que verifique si todos los tipos de una lista de tipos son iguales.

**Use Case #1:**
```cpp
    cout << boolalpha << are_same<int>::value << endl; // true
```

**Use Case #2:**
```cpp
    cout << boolalpha << are_same<int, int , char>::value << endl; // false
```

**Use Case #3:**
```cpp
    cout << boolalpha << are_same<vector<int>, vector<int> , vector<int>>::value << endl; // true
```

**Use Case #4:**
```cpp
    cout << boolalpha << are_same<int, const int, int&, int &&>::value << endl; // false
```

### Question #9 - valores consecutivos en un arreglo estático - template de función (2 points)
Generar un template función `init_array` que inicie un arreglo estático de cualquier tipo y tamaño.

**Use Case #1:**
```cpp
    int arreglo[10];
    init_array(arreglo);    // Valor inicial 0
    for (const auto& i: arreglo)
        std::cout << i << " ";
    std::cout << std::endl;
    // output: 0 1 2 3 4 5 6 7 8 9
```

**Use Case #2:**
```cpp
    int arreglo[15];
    init_array(arreglo, 5); // Se puede configurar el valor inicial (5)
    for (const auto& i: arreglo)
        std::cout << i << " ";
    std::cout << std::endl;
    // output: 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
```

**Use Case #3:**
```cpp
    float arreglo[14];
    init_array(arreglo, 1, 3);  // Se puede configurar el valor inicial (1) y 
                                // el paso (3)
    for (const auto& i: arreglo)
        std::cout << i << " ";
    std::cout << std::endl;
    // output: 1 4 7 10 13 16 19 22 25 28 31 34 37 40
```

**Use Case #4:**
```cpp
    double arreglo[] {0, 0, 0, 4, 5, 6};
    init_array(arreglo, 2, 8, 2);   // Se puede configurar el valor inicial (2)
                                    // valor siguiente al final (8) y 
                                    // el paso (2)
    for (const auto& i: arreglo)
        std::cout << i << " ";
    std::cout << std::endl;
    // output: 2 4 6 4 5 6
```
### Question #10 - Búsqueda binaria - template de clase (2 points)

Desarrollar el template de clase `searcher` que permita ordenar los valores al momento de crear el research o al momento de asignarle un arreglo o contenedor y realice la búsqueda de la posición de un valor en un contenedor del tipo secuencia como:
- `std::array`
- `std::vector`

En caso el valor no sea encontrado, la posición que se devolverá será -1.

**Use Case #1:**
```cpp
    array<int, 4> arr = { 40, 10, 25, 20 };
    searcher<array<int, 4>> s = arr;
    for (const auto& i: arr)
        cout << i << " ";
    cout << endl;                // 10 20 25 40
    auto index = (s << 10);
    cout << index << endl;      // 0
```

**Use Case #2:**
```cpp
    vector<int> vec = {5, 1, 2, 3, 5, 7, 7};
    searcher<vector<int>> s = vec;
    for (const auto& i: vec)
        cout << i << " ";
    cout << endl;                // 1 2 3 5 5 7 7
    cout << (s << 10) << endl;  // -1
```

**Use Case #3:**
```cpp
    vector<double> vec = {5, 1, 2, 3, 5, 4, 7, -1};
    searcher<vector<double>> s = vec;
    for (const auto& i: vec)
        cout << i << " ";
    cout << endl;               // -1 1 2 3 4 5 5 7
    cout << (s << 3) << endl;  // 3
```

**Use Case #4:**
```cpp
    array<float, 8> arr = {-1, 1, 2, 3, 5, 4, 7, 8};
    searcher<array<float, 8>> s = arr;
    for (const auto& i: arr)
        cout << i << " ";
    cout << endl;               // -1 1 2 3 4 5 7 8
    cout << (s << 2) << endl;   // 2
```

### Question #11 - Generar Polinomio - template de clase (2 points)

Desarrollar el template de clase `polynomial` que retorne el valor de un polinomio f(x) para un valor determinado de x. el template de función podría tener dos o más parámetros que permitan generar el polinomio:

```
f(x) = a + bx + cx^2 + dx^3 + ex^4 +...
```

**Use Case #1:** `f(x) = 10 + 7x^2 + 2x^3 + 11x^6`
```
    auto f = polynomial<int, 10, 0, 7, 2, 0, 0, 11>();
    cout << f(5);
```

**Use Case #2:** `f(x) = 21.0 + 3.5x + 5.0x^3`
```
    auto f = polynomial<double, 21.0, 3.5, 0.0, 5.0>();
    cout << f(4.5);
```

**Use Case #3:** `f(x) = 2x^3 + 11x^6`

```
    auto f = polynomial<int, 0, 0, 0, 2, 0, 0, 11>();
    cout << f(4);
```

### Question #12 - cache - template de clase (2 points)

Generar el template de clase `cache` que permita almacenar cualquier tipo de información hasta un limite (`limit`), cada vez que se supere el limite se eliminara el valor insertado más antiguo. 

- Para insertar un valor debera implementarse el metodo `push` 
- Para retirar un elemento debera implementarse el metodo `pop`
- Solo se obtendra el ultimo valor con el metodo `top`
- Para limpiar todo el cache se implementara el metodo `clear`
- Para imprimir todo su contenido se sobrecargara el operador `<<`
- Para verificar si esta vacio se implementara el metodo `empty`

**Use Case #1:**
```
    cache<int, 10> c;  // El primer parametro define el tipo de contenido, 
                       // El segundo parametro define el limite
```

**Use Case #2:**
```
    c = {1, 2, 3, 4, 10}; // sobrecargar el operador = para aceptar 
                          // std::initializer list
                          // si se agrega mas del limite se descarta
                          // los valores
```

**Use Case #3:**
```
    c.push(11);     // Se agrega nuevos valores usando el metodo push
    c.push(15);
```

**Use Case #4:**
```
    std::cout << c.top() << std::endl; // retorna el ultimo valor ingresado
    c.pop(); // retira el ultimo 15
    c.pop(); // retira el ultimo 11
    c.pop(); // retira el ultimo 10
    c.pop(); // retira el ultimo 4
    c.pop(); // retira el ultimo 3
    c.pop(); // retira el ultimo 2
    c.pop(); // retira el ultimo 1
    c.pop(); // Si esta vacio no retira ningun valor
```
**Use Case #5:**
```
    c.clear();
    std::cout << std::boolalpha << c.empty() << std::endl;
```

**Use Case #6:**
```
    cache<std::string, 3> c;
    c.push("apple");
    c.push("banana");
    c.push("orange");
    c.push("lemon");    // Se elimina apple del cache
    c.push("grape");    // Se elimina banana del cache
    
    std::cout << c << std::endl; // grape lemon orange 
```
