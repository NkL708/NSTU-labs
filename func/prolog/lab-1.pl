:- encoding(utf8).

% model, power of engine, color, price
car('Lexus', 50, 'Красный', 100).
car('Toyta', 200, 'Чёрный', 150).
car('BWM', 1000, 'Чёрный', 400).
car('Audi', 600, 'Зелёный', 320).
car('Lada', 123, 'Белый', 321).
car('Lada', 400, 'Жёлтый', 210).
car('Toyta', 100, 'Серый', 150).

print_car_info(Model, Engine_power, Color, Price) :-
    car(Model, Engine_power, Color, Price),
    write('Модель машины: '), writeln(Model),
    write('Мощность двигателя: '), writeln(Engine_power),
    write('Цвет: '), writeln(Color),
    write('Цена: '), writeln(Price), nl.

print_cars_info :-
    car(Model, Engine_power, Color, Price),
    print_car_info(Model, Engine_power, Color, Price).
    
print_cars_info.

find_cars_by_color(Color) :-
    car(Model, Engine_power, Color, Price),
    print_car_info(Model, Engine_power, Color, Price),
    fail.
find_cars_by_color(_).

find_cars_by_power(Engine_power_from) :-
    car(Model, Engine_power, Color, Price),
    Engine_power > Engine_power_from,
    print_car_info(Model, Engine_power, Color, Price),
    fail.
find_cars_by_power(_).

menu_case(0) :- !.
menu_case(1) :- 
    print_cars_info().
menu_case(2) :-
    writeln('Введите цвет машины '), 
    read(Color),
    find_cars_by_color(Color).
menu_case(3) :- 
    writeln('Введите минимальную мощность машины '), 
    read(Engine_power_from),
    find_cars_by_power(Engine_power_from).

menu :-
    repeat,
    writeln('Меню программы:'),
    writeln('1. Вывести информацию обо всех машинах'),
    writeln('2. Найти машины по цвету'),
    writeln('3. Найти машины с мощностью больше заданной'),
    writeln('0. Выход из программы'),
    read(Menu_point), 
    menu_case(Menu_point),
    Menu_point = 0.
