%������� ���������� � ���������� ������� ���������
global n;
global X_;
global Rmax;
global Rmin;
global x1;

x1 = 0.77;

%12 ������ ����� �������
format long e;

%���������� ����� �������� ��������� ��������
n = 10;
%����� ����� �� 1 ����� ������
g_n = 11;
%������� ���������
a = 0.5;
b = 1.0;

%������������ x ��� ������
syms x
%����� ���� �������
f(x) = x^2 - sin(x);
%������� �� �� 2 �����������

%��������� ������� �������� �� n �����
X = linspace(a, b, n);
%�������� ������ ��� ������ �� n �������� �������
Y = zeros(1, n);
%��������� ������ �������� �������
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
%������ ���������, �.�. x - ������, � �� �����
    for i = 1:N-1
        if xx < x(i+1) && xx > x(i)
            om = (x - x(i))*(x - x(i+1));
        end
    end
end


