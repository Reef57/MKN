A = [15.21 0 1.11 9.01; 1.32 14.82 -0.61 8.52; 0.75 -1.26 -15.44 8.33]
n = 3;
b1 = zeros(n, 1)
e = 0.001;
l = 0;
x = zeros(1, n);

for i = 1:1:n
    for k = 1:1:n+1
       if i ~= k
        A(i, k) = (A(i, k)/A(i, i));
        if k ~= n+1
           A(i, k) = A(i, k)*-1; 
        end
       end 
    end
    A(i, i) = 0;
end
A

b = A(:, n+1)
while sum(abs(b)) > e
   max = abs(b(1));
   k = 1;
   for i = 1:n
      if abs(b(i)) > max 
          max = abs(b(i));
          k = i;
      end
   end
   
   x(k) = x(k) + b(k);
   b1(k) = 0;
   for i = 1:n
      if i ~= k
        b1(i) = b(i) + A(i, k)*b(k);
      end
   end
   
   b = b1
   l = l + 1;
end
l
x