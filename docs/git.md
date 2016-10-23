# IDB-Examples
#### Рекомендации по использованию git и github
---

## Что такое Git и Github?

**Git** -- распределённая система контроля версий. Может работать без github -- на вашем локальном компьютере или сервере.

**[Github](https://github.com/)** -- хостинг (хранилище) проектов. Github использует git, но есть и альтернативы: [BitBucket](https://bitbucket.org/) (git и mercurial), [Gitlab](https://gitlab.com) (git).

Хорошая справка по git: [v1 (на русском)](https://git-scm.com/book/ru/v1), [v2 (на английском)](https://git-scm.com/book/en/v2).


## Репозиторий
В системе git существуе понятие "репозиторий" ([педивикия](https://ru.wikipedia.org/wiki/Репозиторий)):

> **Репозиторий**, хранилище — место, где хранятся и поддерживаются какие-либо данные. Чаще всего данные в репозитории хранятся в виде файлов, доступных для дальнейшего распространения по сети.

Итак, git -- система контроля версий, которая управляет вашим репозиторием, а github -- это хостинг, на котором ваш репозиторий лежит. Все действия со своим репозиторием вы могли бы делать без github, git умеет всё необходимое, но github предоставляет удобный интерфейс + бесплатный хостинг.


### Что есть смысл хранить в репозитории:

- Исходный код.
- Какие-то файлы с документацией (github позволяет очень удобно работать с Markdown -- попробуйте).
- Сопутствующие ресурсы, необходимые вашему приложению (например, набор иконок).
- Инструкции для системы сборки (они всегда вместе с исходниками).


### Что не стоит хранить в репозитории:

- Коллекцию песен/фильмов/картинок и т.п.
	+ Git -- система контроля версий, а не файловое хранилище. Она хорошо себя проявляет при работе с набором небольших текстовых файлов (для которых важна история изменений).
	+ Github -- хостинг проектов с открытым (за деньги -- и закрытым) исходным кодом. Вам в любом случае не дадут широкий канал для нормальной работы с тяжёлыми файлами.
	+ С гигабайтами тех же картинок или архивов прекрасно справится и простой DropBox.
- Архивы (пусть и с исходными текстами):
	+ Git и так отслеживает изменения каждого из ваших файлов.
	+ Git не умеет копаться в архивах, поэтому при каждом изменении файла в архиве он загружается в репозиторий полностью.
	+ Github позволяет более-менее удобно просматривать содержимое вашего проекта, даже редактировать текстовые файлы через веб-интерфейс, но если вы выкладываете архив, то (естественно) другие пользователи будут вынуждены вручную его скачивать и разархивировать, чтобы покопаться в исходниках.
- Результаты сборки ваших программ, включая объектные файлы, библиотеки и исполняемые файлы:
	+ Все те же причины, что и с архивами.
	+ Конечные пользователи должны получать вашу программу в готовом виде (например, установщик, `.deb`)/`.rpm`-файл и т.п.) `->` github -- это вообще не для них, и они попали в ваш репозиторий случайно.
	+ Пользователи-разработчики (которым интересны ваши исходники) и так запустят у себя систему сборки, если посчитают нужным. Если вы дадите им результаты своей сборки (хотя бы частично), у них будут проблемы (другая ОС, другая платформа, другой компилятор, другая версия того же компилятора и т.д.).
		* *Хозяйке на заметку:* В случае использования Boost.Build некоторых проблем можно избежать, т.к. результаты сборки с разными параметрами разнесены по каталогам. Но никаких гарантий!
- Пароли:
	+ Например, вы взяли в аренду небольшой сервер и "захардкодили" логин-пароль от него в исходный код своей программы. И выложили всё на гитхаб. Вам крупно повезло -- теперь придётся менять пароль, логин, а возможно, и ip сервера.
	+ Удалить в очередном коммите эти данные можно.
	+ Можно даже удалить репозиторий и перезалить всё заново, уже без паролей.
	+ Но все репозитории гитхаба зеркалируются (какими-то предприимчивыми людьми) куда-то (и раздаются потом как торренты).
	+ Будьте бдительны. История знает именно такие случаи с известными проектами.


## Ветки

Самое интересное в git -- ветки. Ещё интереснее -- вы можете ими управлять на своё усмотрение, делать историю разработки сложной и запутанной (если захотите) или наоборот, упрощать восстановление проекта после ошибок товарищей, упрощать тестирование различных конфигурация и вариантов вашего кода и т.д.

По умолчанию в вашем репозитории есть только ветка `master`.


### Для чего стоит использовать ветки

- Для запиливания новой фичи:
	+ У вас основной код в `master`, вы хотите запилить новую фичу, но точно не знаете, сможете ли сделать всё идеально одним коммитом.
	+ Создаёте новую ветку.
	+ Делаете коммиты в неё.
	+ Когда всё готово, сливаете её обратно в `master`.
	+ Да, можно не только в `master` -- ответвляться можно от любой ветки, и сливать -- тоже в любую.
- Для тестирования:
	+ У вас код работает, у вашего товарища -- нет (конечно, ошибку внесли вы сами, и сами исправляете).
	+ Создаёте ветку.
	+ Тестируете, исправляете, настраиваете и т.д.
	+ Когда код из этой ветки работает везде -- сливаете обратно.
- Для обозначения релизов:
	+ **Примечание:** это не совсем ветки. Это называется тэги (команда: `git tag`). Хотя можно и старыми добрыми ветками.
- Для хранения документации или сайта проекта:
	+ Github умеет запускать ваш сайт, если вы храните его в определённой ветке своего проекта. См. справку по гитхабу.
	+ Github умеет показывать справку по вашему проекту, тоже из определённой ветки, тоже см. справку.

**Резюмируя:** в различных ветках стоит хранить либо совсем параллельные сущности (документацию, сайт проекта), либо новые (текущие, активно разрабатываемые) версии своего проекта. Позже новые версии должны быть слиты в `master`, чтобы не путать пользователей и команду.


### Для чего не стоит использовать ветки

- Для постоянного хранения новых (или просто сильно изменённых) версий проекта.
	+ Есть тэги.
	+ Можно создать форк (ответвление) проекта.
- Для хранения разных подпроектов одного проекта.
	+ Особенно, когда все они будут необходимы одновременно, при сборке.
	+ Стоит создать отдельные репозитории.
- Для хранения "резервный копий" вашего проекта.
	+ Тем более, в виде архивов. :)
	+ Для этого есть другие инструменты.
	+ Если роском-что-то-там заблокировал гитхаб, все такие бекапы полетели вместе с репозиторием.


## Организуем репозитории правильно

Требуется:
- По репозиторию на команду.
	+ Не разные ветки в одной репе, а разные репы.
	+ В каждой репе свой движ (я не против, если кому-то интересно поучаствовать в нескольких командах, и он справляется с этим, но репы всё равно надо разделять).
	+ Все команды, кроме GUI, должны представить динамическую библиотечку (+ набор заголовочных файлов) в качестве результата своей работы.
	+ GUI-команда должна представить исполняемый файл (к которому подключены те библиотеки).
- Тимлид команды отвечает за репозиторий своей команды.
	+ Обязанности:
		* Всегда *примерно* представлять, кто и что делает в каждой из веток.
		* Быть в курсе, какая ветка хотя бы собирается (а лучше -- работает), чтобы другой команде можно было дать рабочую версию + показать мне.
		* Иметь на локальной машине (а лучше -- ещё и флешке/диске) последнюю значимую резервную копию проекта. *Да, и гитхаб блокируют, и без интернета иногда показать надо.*
	+ Ребята, не вешайте все вопросы на Главного Тимлида (Данилин).

---
Дмитрий Куковинец <d1021976@gmail.com>, 19.10.2016, 19:30