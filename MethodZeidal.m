A = [10 2 1 10; 1 10 2 12; 1 1 10 8]
n = 3;
x = zeros(1, n);
x1 = zeros(1, n);
e = 0.001;
for i = 1:1:n
    for k = 1:1:n+1
       if i ~= k
        A(i, k) = A(i, k)/A(i, i);
       end 
    end
    A(i, i) = 0;
end

for k = 1:1:n % первичное преближение
  xt = 0;
  for j = 1:1:n
    xt = xt + A(k, j)*x(1, j); 
  end
  x(1, k) = A(k, n+1) - xt; 
end

l = 1;

while e < norm((x - x1), 1)
    x1 = x;
    for k = 1:1:n % первичное преближение
      xt = 0;
      for j = 1:1:n
        xt = xt + A(k, j)*x(1, j); 
      end
      x(1, k) = A(k, n+1) - xt; 
    end 
    x1
    l = l + 1;
end
x
l