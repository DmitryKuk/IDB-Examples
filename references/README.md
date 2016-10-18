# Ссылки
#### Пример работы со ссылками, собственного класса с конструкторами копирования и перемещения (и соотв. операторами присваивания), использования `std::move`, `std::forward`, `std::reference_wrapper`, `std:ref`.
---

### Как запустить?
Команда для запуска: `b2`.
*Примечание:* См. файл jamroot.jam. Можно закомментировать некоторые строки, и отключить лишние тесты, если мешают.

Необходима система сборки: [Boost.Build](http://www.boost.org/build/).

### Что почитать?
- [Value caterory (cppreference.com)](http://en.cppreference.com/w/cpp/language/value_category)
- [What are rvalues, lvalues, xvalues, glvalues, and prvalues? (stackoverflow.com)](http://stackoverflow.com/questions/3601602/what-are-rvalues-lvalues-xvalues-glvalues-and-prvalues)
- [std::move (cppreference.com)](http://en.cppreference.com/w/cpp/utility/move)
- [std::forward (cppreference.com)](http://en.cppreference.com/w/cpp/utility/forward)
- [What is use of the ref-qualifier `const &&`? (stackoverflow.com)](http://stackoverflow.com/questions/24824432/what-is-use-of-the-ref-qualifier-const)
- [Ref-qualified member functions (habrahabr.ru)](https://habrahabr.ru/post/216783/)
- [std::ref](http://www.cplusplus.com/reference/functional/ref/), [std::cref](http://www.cplusplus.com/reference/functional/cref/), [std::reference_wrapper](http://www.cplusplus.com/reference/functional/reference_wrapper/)

---
Дмитрий Куковинец <d1021976@gmail.com>, 11.10.2016, 19:54
