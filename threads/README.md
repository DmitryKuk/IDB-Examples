# Многопоточность
#### Пример работы с потоками, `std::async`, `std::mutex` и проч., реальный пример использования `std::reference_wrapper`.
---

### Как запустить?
Команда для сборки: `b2`.
Исполняемые файлы будут находиться где-то в каталоге `bin`.

*Примечание:* Эти примеры лучше запускать вручную, т.к. `b2` буферизует вывод -- кое-что не будет наглядно видно.

Необходима система сборки: [Boost.Build](http://www.boost.org/build/).

### Что почитать?
- Управление потоками, управление текущим потоком:
	+ [std::thread](http://www.cplusplus.com/reference/thread/thread/)
	+ [std::this_thread](http://www.cplusplus.com/reference/thread/this_thread/)
- Асинхронный запуск функций, функторов, лямбда-функций и проч.:
	+ [Header: future](http://www.cplusplus.com/reference/future/)
	+ [std::async(...)](http://www.cplusplus.com/reference/future/async/)
	+ [std::future](http://www.cplusplus.com/reference/future/async/)
- Безопасное взаимодействие между потоками:
	+ Блокировки:
		* [Header: mutex](http://www.cplusplus.com/reference/mutex/)
		* [std::mutex](http://www.cplusplus.com/reference/mutex/mutex/)
	+ *Необычные* блокировки:
		* [Spinlock (из Boost.Atomic)](http://www.boost.org/doc/libs/1_62_0/doc/html/atomic/usage_examples.html#boost_atomic.usage_examples.example_spinlock)
		* См. файлы `spinlock.hpp` и `spinlock_impl.hpp` с *правильной* реализацией спинлока
	+ Вспомогательные ништяки для блокировок:
		* [std::lock_guard](http://www.cplusplus.com/reference/mutex/lock_guard/)
		* [std::unique_lock](http://www.cplusplus.com/reference/mutex/unique_lock/)
		* [std::lock(...)](http://www.cplusplus.com/reference/mutex/lock/)
	+ Атомарные операции:
		* [Header: atomic](http://www.cplusplus.com/reference/atomic/)
		* [std::atomic](http://www.cplusplus.com/reference/atomic/atomic/)
- Вспомогательные ништяки:
	+ [Header: chrono](http://www.cplusplus.com/reference/chrono/)
	+ [std::ref](http://www.cplusplus.com/reference/functional/ref/)

---
Дмитрий Куковинец <d1021976@gmail.com>, 11.10.2016, 19:54
