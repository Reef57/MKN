clc
E = eye(n);
n = 3;
A =[1 -2 1 6; 2 -1 3 11; 2 3 -4 -7]
x = zeros(1, n);
%A = [2 -9+4i 4-3i 15-1i; -9-4i 6 -1+2i -22+26i; -4-5i -1-2i -3 -12+10i]
%A = [-11.9163 4.8671-2.9371i -1.7622+3.6084i -10.2378+35.581i;
%    0 -4.9621+0.5005i 4.626-0.6176i 4.8363+9.5965i;
%    0 -7.4783-4.98837i 1.0306+0.1708i 8.3972+8.5532i]

s = A(:, 1).'
e = zeros(n, 1);
e(1, 1) = 1;
v = -1*angle(dot(s,e))-pi
sqrt(dot(s,s));
v1 = sqrt(dot(s, s))
a = -v1
x = 1/sqrt(2*(v1^2)+2*v1*dot(s,e))
w = x*(s'-a*e)
C1 = E - 2*(w*w')
A
A = C1*A

for i = 2:n-1
    s = A(:, i).'
    for k = 1:i-1
        s(k) = 0;
    end
    s
    e = zeros(n, 1);
    e(i, 1) = 1
    v = 1*angle(dot(s,e))-pi
    v1 = sqrt(dot(s, s))
    a = v1 %как понять отрицательна ли 'а'?
    x = 1/(sqrt(2*(v1^2)+2*v1*abs(dot(s,e))))
    w = x*(s'-a*e)
    C1 = E - 2*(w*w')
    A = C1*A
end

x(1, n) = A(n ,n+1)/A(n, n);
for i = n-1:-1:1 
    cx = 0;
    for k = i+1:1:n
       cx = cx + A(i ,k)*x(1, k);
    end
    x(1, i) = (A(i, n+1) - cx)/A(i, i);
end
x