%Выводим переменные в глобальную область видимости
global n;
global X_;
global Rmax;
global Rmin;
global x1;

x1 = 0.77;

%12 знаков после запятой
format long e;

%Количество точек рабиения интервала входного
n = 10;
%Гаусс хочет на 1 точку больше
g_n = 11;
%Границы интервала
a = 0.5;
b = 1.0;

%Воспринимать x как символ
syms x
%Задаём свою функцию
f(x) = x^2 - sin(x);
%Считаем от неё 2 производную

%Разбиваем входной интервал на n точек
X = linspace(a, b, n);
%Выделяем память под массив из n значений функции
Y = zeros(1, n);
%Заполняем массив значений функции
for i = 1:n
    Y(i) = f(X(i));
end

xx = linspace(X(1), X(10), n + 1);

yy = lagrange(X, Y, 0.77);

for i = 1:n
    if x1 < X(i+1) && x1 > X(i)
        F2min = fmin('F', X(i), X(i+1))
    end
end

function yy = lagrange(x, y , xx)
    N = length(x); 
    
    for i = 1:N-1
        if xx < x(i+1) && xx > x(i)
            yy = y(i)*(xx - x(i+1))/(x(i)-x(i+1))+y(i+1)*(xx-x(i))/(x(i+1)-x(i));
        end
    end
end


function y = F(x)
    diff(f(x), 2);
end

function om = omega(x)
    N = length(x);
%Строим многочлен, т.к. x - символ, а не число
    for i = 1:N-1
        if xx < x(i+1) && xx > x(i)
            om = (x - x(i))*(x - x(i+1));
        end
    end
end


