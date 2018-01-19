clc
n = 3;
E = eye(n);
A = [2 -9+4i 4-3i 15-1i; -9-4i 6 -1+2i -22+26i; -4-5i -1-2i -3 -12+10i];

for i = 1:n-1
    s = A(:, i).';
    for k = 1:i-1
        s(k) = 0;
    end
    e = zeros(n, 1);
    e(i, 1) = 1;
    e = e' 
    v = -1*angle(dot(s,e))-pi; %arg(a)
    v1 = sqrt(dot(s, s)) %|a|
    a = v1*exp(v*j) %alpha
    x = 1/(sqrt(2*((v1^2)+v1*abs(dot(s,e)))))
    (s-((10.2882-1.0316j)*e)')*(0.05644)
    w = x*(s-(a*e)).'
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
