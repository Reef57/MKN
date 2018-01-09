A = [2 -9+4i 4-3i 15-1i; -9-4i 6 -1+2i -22+26i; -4-5i -1-2i -3 -12+10i]
n = 3;
s = A(:, 1).'
e = zeros(1, n);
e(1, 1) = 1;

v = angle(dot(s,e))-pi
v1 = sqrt(dot(s, s))
a = v1*(exp(v))
x = 1/sqrt(2*(a^2+a*abs(dot(s, e))))