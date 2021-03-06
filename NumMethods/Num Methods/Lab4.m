%�������� ����������� 12 ������ ����� �������
format long e

%����� �������
f = @(x) x.^3 - cos(2 .* x);

%������ ���������� t "����������". ���� ���� ����� �������� 'a = t-5', ��
%������ �� ����� �������� ���������� ���� �������� t, � ��� � �������
%������
syms t

%������� F - ����� ������� 4 ����������� �� ����� �������
F(t) = diff(abs(t^3 - cos(2 * t)), 4);

%F1 - ������
F1(t) = diff(abs(t^3 - cos(2 * t)));

%F2 - ������
F2(t) = diff(abs(t^3 - cos(2 * t)), 2);

%���������� ������ �������� ���������
Istar = integral(f, 0.1, 0.6);
%������� �� �����
fprintf("I* = %s\n", Istar);

% for j = 4
%     n = 2^j;
%     
%     ��������� ��� ������� �� n �����
%     x = linspace(0.1, 0.6, n);
%     ���������� � ������ y �������� ������� � ���� ������
%     y = f(x);
%     ���������� �������� 4-� ����������� � ���� �� ������
%     Y = F(x);
%     
%     ������� �� ����� ���������� �����
%     fprintf("n = %d\n", n);
%     
%     ������� �������� ������� �������� � ������� �� �����
%     I = Simpson(x, y);
%     fprintf("I = %s\n", I);
%     
%     ������� ���������� ������
%     DeltaI = abs(Istar - I);
%     fprintf("Delta I = %s\n", DeltaI);
%     
%     ������� ������������� ������
%     deltai = DeltaI / abs(Istar) * 100;
%     fprintf("delta i = %s\n", deltai);
%     
%     ������� ������������� ������
%     R = double((max(Y) * 0.5^5) / (180 * n^4));
%     fprintf("R = %s\n", R);
% end

%��������� ������� �������� �� 10� �����
x = linspace(0.1, 0.6, 10000);
y = f(x);
Y = F(x);
%���������� � ������ �������� ������ �����������
Y1 = F1(x);
%���������� �������� ������ �����������
Y2 = F2(x);

%������� �������� ������� ����� ���������������
I1 = left(x, y);
DeltaI1 = abs(Istar - I1);
deltaI1 = DeltaI1 / abs(Istar);
R1 = double(max(Y1) / 2 * 0.5 * (x(2) - x(1)));

%����� ������ ���������������
I2 = right(x, y);
DeltaI2 = abs(Istar - I2);
deltaI2 = DeltaI2 / abs(Istar);

%����� ����������� ���������������
I3 = center(x, y);
DeltaI3 = abs(Istar - I3);
deltaI3 = DeltaI3 / abs(Istar);
R3 = double((max(Y2) * 0.5^3) / 24 );

%����� ��������
I4 = trap(x, y);
I44 = trapz(x, y);
DeltaI4 = abs(Istar - I4);
deltaI4 = DeltaI4 / abs(Istar);
R4 = double((max(Y2) * 0.5^3) / (12 * 100000000))

%����� ��������
I5 = Simpson(x, y);
DeltaI5 = abs(Istar - I5);
deltaI5 = DeltaI5 / abs(Istar);
R = double((max(Y) * 0.5^5) / (180 * n^4));

function I = Simpson(x, y)
%   n - ���������� ��� �����, ������� ������ �� ����
    n = fix(length(x) / 2);

%   ��������� �������� ��������� - �������� ������� � ����� ����� �����
    I = y(1);
%   ���������� �������� ������� � �������� ������ * 4
    for i = 2 : n
        I = I + y(2 * i - 1) * 4;
    end
    
%   ���������� �������� ������� � ������ ������ * 2
    for i = 2 : n - 1
        I = I + y(2 * i) * 2;
    end
    
%   ���������� �������� ������� � ��������� �����
    I = I + y(2 * n);
    
%   ���������� ��������� �������� �� ��� �����, ��������� �� 3
    I = I * (x(2) - x(1)) / 3;
end

function I = left(x, y)
%   ���������� ����� �������
    n = length(x);
%   ������� ��� �����
    h = x(2) - x(1);
    
%   ��������� �������� ��������� = 0
    I = 0;
    
%   �������� h �� �������� ������� �� ���� ����� ������
    for i = 1 : n - 1
        I = I + h * y(i);
    end
end

function I = right(x, y)
    n = length(x);
    h = x(2) - x(1);
    
    I = 0;
    
%   �������� h �� �������� ������� �� ���� ������ ������
    for i = 2 : n
        I = I + h * y(i);
    end
end

function I = center(x, y)
    n = length(x);
%   ������� ��� ����� * 2
    h = x(3) - x(1);
    
    I = 0;
    
%   �������� h �� �������� ������� �� ���� ������� ������
    for i = 2 : n / 2
        I = I + y(2 * i - 2) * h;
    end
end

function I = trap(x, y)
    n = length(x);
    h = x(2) - x(1);
    
    I = 0;

%   ��� ������ ���� ����� ������� ������� �������� � ���������� x_i, x_i+1
%   � �������� f(x_i), f(x_i+1)
    for i = 1 : n - 1
        I = I + (y(i) + y(i + 1)) * h / 2;
    end
end